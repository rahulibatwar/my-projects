#include <stdio.h>

int main() {
    char name[50];
    printf("What is your name? ");
    scanf("%s", name);
    printf("Hello , %s! welcome to Git!\n", name);
    return 0;
}