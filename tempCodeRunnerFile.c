#include<stdio.h>

int main() {
    int size, numKeys, i;

    // Get the size of the Hash Table from the user
    printf("Enter the size of the Hash Table: ");
    scanf("%d", &size);

    // Get the number of keys from the user
    printf("Enter the number of keys: ");
    scanf("%d", &numKeys);

    int keys[numKeys];

    // Get the keys from the user
    printf("Enter %d keys:\n", numKeys);
    for (i = 0; i < numKeys; i++) {
        scanf("%d", &keys[i]);
    }

    int indexes[numKeys];
    int M = size;

    for (i = 0; i < numKeys; i++) {
        indexes[i] = (keys[i] % M);
    }

    printf("\nThe indexes of the values in the Hash Table: ");
    for (i = 0; i < numKeys; i++) {
        printf("%d ", indexes[i]);
    }

    return 0;
}
