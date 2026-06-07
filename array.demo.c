#include <stdio.h>

// Humne vahi return type wala function yahan phir se banaya
int checkEligibility(int age) {
    if (age >= 18) {
        return 1; // Eligible
    } else {
        return 0; // Not Eligible
    }
}

int main() {
    // 5 alag-alag logon ki ages ka array
    int ages[5] = {20, 15, 32, 12, 26};

    printf("--- Array Voter Eligibility Report ---\n\n");

    // Loop automatic array ke har element par chalega
    for (int i = 0; i < 5; i++) {
        
        // ages[i] ka matlab hai: pehle ages[0], phir ages[1], phir ages[2]...
        int result = checkEligibility(ages[i]);

        printf("Person %d (Age: %d) -> ", i + 1, ages[i]);
        
        if (result == 1) {
            printf("Aap vote de sakte hain! ✅\n");
        } else {
            printf("Maaf kijiye, aap abhi vote nahi de sakte. ❌\n");
        }
    }

    printf("\nReport complete! Sabhi elements check ho gaye.\n");
    return 0;
}