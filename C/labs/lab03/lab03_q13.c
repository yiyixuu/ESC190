#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_file_contents(const char *filename) {
    char line[200];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s\n", line);
    }

    fclose(fp);
}

double avg_nums(char filename[]) {
    double sum = 0;
    int count = 0;
    char line[200];
    FILE *fp = fopen(filename, "r");

    while (fgets(line, sizeof(line), fp) != NULL) {
        sum += atoi(line);
        count++;
    }

    fclose(fp);
    return sum/count;
}

int main() {
    char filename[] = "nums.txt";
    print_file_contents(filename);
    printf("Average: %lf\n", avg_nums(filename));
}