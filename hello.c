#include <stdio.h>
#include <string.h>
int main(){
    int  a[5] = {10,20,30,40,50};
    int i, kay;
    printf("Enter the key to search: ");
    scanf("%d", &kay);
    for(int i=0; i<5; i=i+1){
        {
            if(a[i] == kay){
                printf("Key found at index: %d\n", i);
                break;
            }
        }
    }
    return 0;
}