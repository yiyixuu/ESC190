#include "seamcarving.h"
#include "c_img.c"
#include <stdio.h>
#include <float.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

void calc_energy(struct rgb_img *im, struct rgb_img **grad) {
    *grad = (struct rgb_img *)malloc(sizeof(struct rgb_img));
    (*grad)->width = im->width;
    (*grad)->height = im->height;
    (*grad)->raster = (uint8_t *)malloc(3 * im->width * im->height * sizeof(uint8_t));

    for (int i = 0; i < im->height; i++) { // y
        for (int j = 0; j < im->width; j++) { // x
            int R_x, G_x, B_x, R_y, G_y, B_y;
            R_x = abs(get_pixel(im, i, j + 1 > im->width - 1 ? 0 : j + 1, 0) - get_pixel(im, i, j - 1 < 0 ? im->width - 1 : j - 1, 0));
            G_x = abs(get_pixel(im, i, j + 1 > im->width - 1 ? 0 : j + 1, 1) - get_pixel(im, i, j - 1 < 0 ? im->width - 1 : j - 1, 1));
            B_x = abs(get_pixel(im, i, j + 1 > im->width - 1 ? 0 : j + 1, 2) - get_pixel(im, i, j - 1 < 0 ? im->width - 1 : j - 1, 2));

            R_y = abs(get_pixel(im, i + 1 > im->height - 1 ? 0 : i + 1, j, 0) - get_pixel(im, i - 1 < 0 ? im->height - 1 : i - 1, j, 0));
            G_y = abs(get_pixel(im, i + 1 > im->height - 1 ? 0 : i + 1, j, 1) - get_pixel(im, i - 1 < 0 ? im->height - 1 : i - 1, j, 1));
            B_y = abs(get_pixel(im, i + 1 > im->height - 1 ? 0 : i + 1, j, 2) - get_pixel(im, i - 1 < 0 ? im->height - 1 : i - 1, j, 2));

            // printf("R_x = %d, G_x = %d, B_x = %d, R_y = %d, G_y = %d, B_y = %d\n", R_x, G_x, B_x, R_y, G_y, B_y);

            int delta_x_squared = R_x * R_x + G_x * G_x + B_x * B_x;
            int delta_y_squared = R_y * R_y + G_y * G_y + B_y * B_y;

            double energy = sqrt(delta_x_squared + delta_y_squared);

            u_int8_t dual_gradient_energy = (u_int8_t)(energy / 10);

            set_pixel(*grad, i, j, dual_gradient_energy, dual_gradient_energy, dual_gradient_energy);
        }
    }
}

void dynamic_seam(struct rgb_img *grad, double **best_arr) {
    *best_arr = (double *)malloc(grad->width * grad->height * sizeof(double));

    for (int i = 0; i < grad->height; i++) { // y
        for (int j = 0; j < grad->width; j++) { // x
            if (i == 0) {
                (*best_arr)[i * grad->width + j] = get_pixel(grad, i, j, 0);
            }
            else {
                double min_val = DBL_MAX;
                for (int dj = -1; dj <= 1; dj++) {
                    int new_j = j + dj;
                    if (0 <= new_j && new_j < grad->width)
                    {
                        min_val = min(min_val, (*best_arr)[(i - 1) * grad->width + new_j]);
                    }
                }
                // printf("min_val for (%d, %d) of %d = %f\n", i, j, get_pixel(grad, i, j, 0), min_val);
                (*best_arr)[i * grad->width + j] = get_pixel(grad, i, j, 0) + min_val;
            }
        }
    }
}

void recover_path(double *best, int height, int width, int **path) {
    *path = (int *)malloc((height) * sizeof(int));

    for(int i = 0; i < height; i++) {
        if(i == 0) {
            double min_val = DBL_MAX;
            int min_j = 0;
            for(int j = 0; j < width; j++) {
                if(best[i * width + j] < min_val) {
                    min_val = best[i * width + j];
                    min_j = j;
                }
            }
            (*path)[i] = min_j;
        }
        else {
            int prev_j = (*path)[i - 1];
            double min_val = DBL_MAX;
            int min_j = 0;
            for(int dj = -1; dj <= 1; dj++) {
                int new_j = prev_j + dj;
                if(0 <= new_j && new_j < width) {
                    if(best[i * width + new_j] < min_val) {
                        min_val = best[i * width + new_j];
                        min_j = new_j;
                    }
                }
            }
            (*path)[i] = min_j;
        }
    }
}

void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path) {
    create_img(dest, src->height, src->width - 1);
    for(int i = 0; i < src->height; i++) {
        int k = 0;
        for(int j = 0; j < src->width; j++) {
            if(j != path[i]) {
                set_pixel(*dest, i, k, get_pixel(src, i, j, 0), get_pixel(src, i, j, 1), get_pixel(src, i, j, 2));
                k++;
            }
        }
    }

}

int main() {
    struct rgb_img *im;
    struct rgb_img *cur_im;
    struct rgb_img *grad;
    double *best;
    int *path;

    // read_in_img(&im, "HJoceanSmall.bin");
    // read_in_img(&im, "3x4.bin");
    read_in_img(&im, "6x5.bin");

    for(int i = 0; i < im->height; i++) {
        for(int j = 0; j < im->width; j++) {
            for(int k = 0; k < 3; k++) {
                printf("%d ", get_pixel(im, i, j, k));
            }
        }
        printf("\n");
    }

    calc_energy(im, &grad);

    printf("grad\n");
    print_grad(grad);

    printf("best\n");
    // for(int i = 0; i < 5; i++){
    //     printf("i = %d\n", i);
    //     calc_energy(im,  &grad);
    dynamic_seam(grad, &best);
    for (int i = 0; i < grad->height; i++)
    {
        for (int j = 0; j < grad->width; j++)
        {
            printf("%f ", best[i * grad->width + j]);
        }
        printf("\n");
    }

    recover_path(best, grad->height, grad->width, &path);
    for (int i = 0; i < grad->height; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
    remove_seam(im, &cur_im, path);

    for(int i = 0; i < cur_im->height; i++) {
        for(int j = 0; j < cur_im->width; j++) {
            for(int k = 0; k < 3; k++) {
                printf("%d ", get_pixel(cur_im, i, j, k));
            }
        }
        printf("\n");
    }



    //     char filename[200];
    //     sprintf(filename, "img%d.bin", i);
    //     write_img(cur_im, filename);

    //     destroy_image(im);
    //     destroy_image(grad);
    //     free(best);
    //     free(path);
    //     im = cur_im;
    // }
    // destroy_image(im);
}