#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error: malloc failed\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("After Malloc: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int *tmp = realloc(arr, (n + 2) * sizeof(int));
    if (tmp == NULL) {
        printf("Error: realloc failed\n");
        free(arr);
        return 1;
    }
    arr = tmp;

    printf("Enter 2 more elements: ");
    for (int i = n; i < n + 2; i++) {
        scanf("%d", &arr[i]);
    }

    printf("After malloc + realloc: ");
    for (int i = 0; i < n + 2; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int *clean_copy = calloc(n + 2, sizeof(int));
    if (clean_copy == NULL) {
        printf("Error: calloc failed\n");
        free(arr);
        return 1;
    }

    printf("After calloc (zeroed): ");
    for (int i = 0; i < n + 2; i++) {
        printf("%d ", clean_copy[i]);
    }
    printf("\n");

    free(arr);
    free(clean_copy);
    return 0;
}
