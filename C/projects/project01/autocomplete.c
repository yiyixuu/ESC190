#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct term{
    char term[200]; 
    double weight;
} term;

int compare_terms(const void *a, const void *b) {
    const term *term_a = (const term *)a;
    const term *term_b = (const term *)b;
    return strcmp(term_a->term, term_b->term);
}

void read_in_terms(term **terms, int *pnterms, char *filename) {
    
    FILE *file = fopen(filename, "r");

    if(file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char num_terms[200];
    fgets(num_terms, sizeof(num_terms), file);
    *pnterms = atoi(num_terms);

    *terms = (term *) malloc(*pnterms * sizeof(term));

    for(int i = 0; i < *pnterms; i++) {
        fscanf(file, "%lf %[^\n]", &((*terms)[i].weight), (*terms)[i].term);
    }

    fclose(file);

    qsort(*terms, *pnterms, sizeof(term), compare_terms);
}

int main() {
    term *terms;
    int nterms;
    read_in_terms(&terms, &nterms, "cities.txt");
    return 0;
}