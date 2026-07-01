#include <stdio.h>

// Hamara return-type function bilkul pehle jaisa hi hai
int checkEligibility(int age) {
    if (age >= 18) {
        return 1; // Eligible
    } else {
        return 0; // Not Eligible
    }
}

int main() {
    // Ek khali array banaya jo 5 integers store kar sakta hai
    int ages[5]; 

    printf("--- Dynamic Array Voter Input ---\n");
    printf("Kripya 5 logon ki age ek-ek karke enter kijiye:\n\n");

    // LOOP 1: Array ke andar data bharne (Input lene) ke liye
    for (int i = 0; i < 5; i++) {
        printf("Person %d ki age daliye: ", i + 1);
        scanf("%d", &ages[i]); // Jo bhi input aayega, wo ages[i] par save hoga
    }

    printf("\n--- Generating Final Eligibility Report ---\n\n");

    // LOOP 2: Array se data nikal kar process karne ke liye
    for (int i = 0; i < 5; i++) {
        int result = checkEligibility(ages[i]);

        printf("Person %d (Age: %d) -> ", i + 1, ages[i]);
        
        if (result == 1) {
            printf("Aap vote de sakte hain! ✅\n");
        } else {
            printf("Maaf kijiye, aap abhi vote nahi de sakte. ❌\n");
        }
    }

    printf("\nAll done! Program complete.\n");
    return 0;
}