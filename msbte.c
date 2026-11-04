#include <stdio.h>
int main() {
    int arr [50], n, i, pos, element;

    printf(" Enter the number of elements: ");
    scanf("%d", &n);

    printf("enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("enter element to insert: ");
    scanf("%d", &element);
    printf("enter position (1 to %d): ", n + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("invalid position! \n");
    } else { 
        for (i = n - 1; i >= pos - 1; i--) {
            arr[i + 1] = arr[i];
        }
        arr[pos - 1] = element;
        n++; 

        printf("array after insertion: \n");
        for (i = 0; i <n; i++) { 
            printf("%d" , arr[i]);
        }
        printf("\n");
    }
    return 0;
}

