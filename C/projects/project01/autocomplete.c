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

int compare_weights(const void *a, const void *b) {
    const term *term_a = (const term *)a;
    const term *term_b = (const term *)b;
    if(term_a->weight < term_b->weight) {
        return 1;
    } else if(term_a->weight > term_b->weight) {
        return -1;
    } else {
        return 0;
    }
}

void read_in_terms(term **terms, int *pnterms, char *filename) {
    FILE *file = fopen(filename, "r");

    fscanf(file, "%d", pnterms);

    *terms = (term *) malloc(*pnterms * sizeof(term));

    for(int i = 0; i < *pnterms; i++) {
        fscanf(file, "%lf %[^\n]", &((*terms)[i].weight), (*terms)[i].term);
    }

    fclose(file);

    qsort(*terms, *pnterms, sizeof(term), compare_terms);
}

int lowest_match(term *terms, int nterms, char *substr) {
    int left = 0;
    int right = nterms - 1;
    while(left<=right) {
        int mid = (left + right) /2;
        if(strncmp(terms[mid].term, substr, strlen(substr)) >= 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int highest_match(term *terms, int nterms, char *substr) {
    int left = 0;
    int right = nterms - 1;
    while(left<=right) {
        int mid = (left + right) /2;
        if(strncmp(terms[mid].term, substr, strlen(substr)) > 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return right;
}

void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr) {
    int left = lowest_match(terms, nterms, substr);
    int right = highest_match(terms, nterms, substr);

    *n_answer = right - left + 1;

    *answer = (term *) malloc(*n_answer * sizeof(term));

    for(int i = 0; i < *n_answer; i++) {
        (*answer)[i] = terms[left + i];
    }

    qsort(*answer, *n_answer, sizeof(term), compare_weights);
}