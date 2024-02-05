#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student1.h"

typedef struct student2{
    char *name; 
    char *student_number;
    int year;
} student2;

void printName(student1 student) {
    printf("%s\n", student.name);
}

void set_default_name(student1 *p_s) {
    strcpy(p_s->name, "Default Name");
    p_s->year = 0;
}

void set_default_name_wrong(student1 s) {
    strcpy(s.name, "Default Name Wrong"); // doesnt work because s is a local variable in set_default_name_wrong
    s.year = 1; // also doesnt work because s is a local variable in set_default_name_wrong
}

void create_block1(student1 **p_p_s, int n_students) {
    *p_p_s = malloc(n_students * sizeof(student1));
}

void set_name(student1 *p_s, char *name) {
    if(strlen(name) > 199) {
        strncpy(p_s->name, name, 199);
        p_s->name[199] = '\0';
    }
    strcpy(p_s->name, name);

}

void destroy_block1(student1 **p_p_s) {
    free(*p_p_s);
    *p_p_s = NULL;
}



void create_block2(student2 **p_p_s, int num_students) {
    *p_p_s = malloc(num_students * sizeof(student2));
    for(int i = 0; i < num_students; i++) {
        (*p_p_s)[i].name = 0;
        (*p_p_s)[i].student_number = 0;
    }
}

void set_name2(student2 *p_s, char *name) {
    p_s->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(p_s->name, name);
}

void destroy_block2(student2 *p_s, int block_sz) {
    for(int i = 0; i < block_sz; i++) {
        free(p_s[i].name);
        free(p_s[i].student_number);
    }
    free(p_s);
}

void set_names(student1 s1, student2 s2) {
    strcpy(s1.name, "John"); 
    strcpy(s2.name, "John");
}

int main() {
    // student1 s;
    // set_default_name(&s);
    // printf("%s, %d\n", s.name, s.year);
    // set_default_name_wrong(s);
    // printf("%s, %d\n", s.name, s.year);

    // int n_students = 10;
    // student1 *p_s;
    // create_block1(&p_s, n_students);
    // for(int i = 0; i < n_students; i++) {
    //     set_default_name(&p_s[i]);
    //     printName(p_s[i]);
    // }
    // set_name(&(p_s[0]), "name");
    // printName(p_s[0]);
    // destroy_block1(&p_s);

    student1 *p_s;
    create_block1(&p_s, 10);
    strcpy(p_s->name, "John");
    strcpy(p_s->student_number, "1234567890");
    p_s->year = 1;
    printName(*p_s);
}


