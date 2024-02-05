#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double my_atof(char *line) {
    int start = 0;
    while(line[start]!= '=') {
        start++;
    }
    int i = start + 2;
    int sign = 1;
    if(line[i] == '-') {
        sign = -1;
        i++;
    }


    double result = 0.0;
    while(line[i] >= '0' && line[i] <= '9' && line[i] != '.') {
        result = result * 10 + (line[i] - '0');
        i++;
    }
    i++;
    double scale = 1;
    while(line[i] >= '0' && line[i] <= '9') {
        scale/=10;
        result = result + (line[i]-'0')*scale;
        i++;
    }

    return result * sign;
}

int count_digits(char *line) {
    int start = 0;
    while(line[start]!= '.') {
        start++;
    }
    int i = start+1;

    int digits = 0;
    while(line[i] >= '0' && line[i] <= '9') {
        digits++;
        i++;
    }
    return digits;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char filename[] = "constants.txt";

    char line[200];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    double sum = 0.0;
    int decimal_digits = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        sum += my_atof(line);
        decimal_digits = max(decimal_digits, count_digits(line));
    }

    printf("%.*f\n", decimal_digits, sum);

    fclose(fp);
}