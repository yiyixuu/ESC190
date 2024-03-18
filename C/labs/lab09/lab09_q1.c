#include "c_img.c"

void change_brightness(struct rgb_img *im, struct rgb_img **dest, int factor) {
    create_img(dest, im->height, im->width);

    for(int i = 0; i < im->height; i++) {
        for(int j = 0; j < im->width; j++) {
            int r = get_pixel(im, i, j, 0);
            int g = get_pixel(im, i, j, 1);
            int b = get_pixel(im, i, j, 2);

            r *= factor;
            g *= factor;
            b *= factor;

            if(r > 255) {
                r = 255;
            }
            if(g > 255) {
                g = 255;
            }
            if(b > 255) {
                b = 255;
            }

            set_pixel(*dest, i, j, (uint8_t)r, (uint8_t)g, (uint8_t)b);
        }
    }
}

int main() {
    struct rgb_img *im;
    struct rgb_img *cur_im;
    read_in_img(&im, "cannon.bin");

    

    for(int i = 0; i < 5; i++) {
        change_brightness(im, &cur_im, i);

        char filename[200];
        sprintf(filename, "img%d.bin", i);
        write_img(cur_im, filename);

        destroy_image(cur_im);
    }

    destroy_image(im);
}