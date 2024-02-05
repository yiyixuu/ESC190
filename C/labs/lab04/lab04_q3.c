#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student1 {
    char name[3];
    int age;
} student1;

void change_name(student1 *p_s, char new_name[]) {
    strcpy(p_s->name, new_name);
}

int main() {
    student1 student = {"ab", 20};
    printf("%s\n", student.name);
    change_name(&student, "bc");
    printf("%s\n", student.name);
}