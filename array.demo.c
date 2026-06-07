#include <stdio.h>

int main() {
    // 5 logon ki age ka ek array banaya
    int ages[5] = {20, 15, 32, 12, 26};

    printf("--- Array Print Demo ---\n");

    // Loop 0 se shuru hoga aur 4 tak chalega (i < 5)
    for (int i = 0; i < 5; i++) {
        printf("Position %d (Index %d) par age hai: %d\n", i + 1, i, ages[i]);
    }

    return 0;
}