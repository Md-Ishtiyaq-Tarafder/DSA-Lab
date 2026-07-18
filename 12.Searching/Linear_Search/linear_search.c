#include <stdio.h>

int linearSearch(int*arr,int n,int key) {
    for (int i = 0; i<n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    int key;

    printf("Enter number of elements in array: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter target key element: ");
    scanf("%d",&key);

    printf("Enter Array elements:\n");
    for(int i=0; i<n ;i++){
        scanf("%d",&arr[i]);
    }
    
    int i = linearSearch(arr,n,key);
    if (i == -1)
        printf("Key Not Found");
    else
        printf("Key Found at Index: %d", i);

    return 0;
}
