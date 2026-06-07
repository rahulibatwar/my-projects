#include <stdio.h>

// 1. Yeh hamara khud ka banaya hua function hai
void checkEligibility(int age) {
    if (age >= 18) {
        printf("Aap ek adult hain aur vote de sakte hain!\n");
    } 
    else if (age >= 13) {
        printf("Aap ek teenager hain.\n");
    } 
    else {
        printf("Aap abhi bache hain.\n");
    }
}

// 2. Main function ab bohot saaf aur chota dikhega
int main() {
    int userAge;

    printf("--- Welcome to Modular Voter Checker ---\n");
    printf("(Program band karne ke liye '0' enter karein)\n");

    while (1) {
        printf("\nAge enter kijiye: ");
        scanf("%d", &userAge); 

        if (userAge == 0) {
            break; 
        }

        // 3. Yahan humne function ko "Call" kiya aur use userAge bhej di
        checkEligibility(userAge);
    }

    printf("\nProgram safely closed. Thank you!\n");
    return 0;
}