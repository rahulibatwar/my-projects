#include <stdio.h>

// void ki jagah int likha hai, kyunki yeh number return karega
int checkEligibility(int age) {
    if (age >= 18) {
        return 1; // 1 ka matlab hai: Eligible hai!
    } else {
        return 0; // 0 ka matlab hai: Eligible nahi hai!
    }
}

int main() {
    int userAge;

    printf("--- Welcome to Return Type Voter Checker ---\n");
    printf("(Program band karne ke liye '0' enter karein)\n");

    while (1) {
        printf("\nAge enter kijiye: ");
        scanf("%d", &userAge); 

        if (userAge == 0) {
            break; 
        }

        // Yahan function chalega aur apna jawab 'result' variable mein daal dega
        int result = checkEligibility(userAge);

        // Ab main() function khud decision le raha hai result dekh kar
        if (result == 1) {
            printf("Aap vote de sakte hain! \n");
        } else {
            printf("Maaf kijiye, aap abhi vote nahi de sakte. \n");
        }
    }

    printf("\nProgram safely closed. Thank you!\n");
    return 0;
}