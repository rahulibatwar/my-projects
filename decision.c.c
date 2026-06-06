#include <stdio.h>

int main() {
    int age;

    // Yeh loop exactly 3 baar chalega (i = 1, i = 2, i = 3)
    for (int i = 1; i <= 3; i++) {
        printf("\n--- Person Number %d ---\n", i);
        
        printf("Apni umar (Age) enter kijiye: ");
        scanf("%d", &age); 

        if (age >= 18) {
            printf("Aap ek adult hain aur vote de sakte hain! \n");
        } 
        else if (age >= 13) {
            printf("Aap ek teenager hain. \n");
        } 
        else {
            printf("Aap abhi bacche hain. \n");
        }
    }

    printf("\nSabhi logon ka data check ho gaya! Program Khatam.\n");
    return 0;
}