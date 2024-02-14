#include <stdio.h>
#include <stdlib.h>

// Q5
void change_int(int *p_a) {
    *p_a = 45;
}

// Q10
void change_int2(int **p_p_a) {
    **p_p_a = 46;
}

// Q11
void change_int_ptr(int **p_p_a) {
    *p_p_a = malloc(sizeof(int));
}

// Q16
void change_arr(int *p_arr) {
    p_arr[2] = 8;
}

// Q21
typedef struct student {
    char name[1000];
    int age;
} student;

// Q27
void change_name(student *p_s) {
    strcpy(p_s->name, "Jenny"); 
}

// Q28
void change_age(student *p_s) {
    p_s->age = 20;
}

// self Q2
// define a function that takes in a string and changes a specified character to 'X'
void change_char(char *str, int index) {
    str[index] = 'X';
}

int main() {
    // Q1
    int a = 42;

    // Q2
    int *p_a = &a;

    // Q3
    *p_a = 43;

    // Q4
    int b = 44; 
    p_a = &b;

    // Q6
    change_int(&a);
    printf("%d\n", a); // prints 45

    // Q7
    change_int(p_a);

    // Q8
    int **p_p_a;
    
    // Q9
    p_p_a = &p_a;

    // Q12
    change_int2(&p_a); 
    change_int2(p_p_a);

    // Q13
    change_int_ptr(&p_a);

    // Q14
    change_int_ptr(p_p_a);

    // Q15
    int arr[] = {5, 6, 7};

    // Q17
    change_arr(arr);

    // Q18
    int *p_block = malloc(3 * sizeof(int));
    change_arr(p_block);

    // Q19
    change_int(p_block);

    // Q20
    change_int_ptr(&p_block);

    // Q21
    student s = {"Jenny", 20};

    // Q22
    strcpy(s.name, "Jennifer");

    // Q23
    s.age = 21;

    // Q24
    student *p_s = &s;

    // Q25
    strcpy(p_s->name, "Jenny");

    // Q26
    p_s->age = 20;

    // Q29
    change_name(p_s);

    // Q30
    change_age(&s);

    // Q31
    student arr_s[5];

    // Q32
    change_name(&(arr_s[2]));
    change_age(&(arr_s[2]));

    // self Q1
    // Define a character array message and initialize it to "Hello".
    char message[] = "Hello";

    // self Q2
    change_char(message, 1);
}