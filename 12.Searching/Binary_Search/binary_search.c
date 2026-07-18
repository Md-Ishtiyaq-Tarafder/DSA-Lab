#include <stdio.h>

int binarySearch(int*arr,int n,int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; 

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            low = mid + 1; 
        }
        else {
            high = mid - 1; 
        }
    }
    return -1;
}

int main() {
    int n;
    int key;

    printf("Enter number of elements in array: ");
    scanf("%d",&n);

    printf("Enter target key element: ");
    scanf("%d",&key);

    int arr[n];

    printf("Enter Array elements:\n");
    for(int i=0; i<n ;i++){
        scanf("%d",&arr[i]);
    }
    
    for (int i = 0; i < n - 1; i++) {
        if (arr[i+1] < arr[i]) {
            printf("Unsorted Array.\nBinary Search can't be performed.");
            return 0;
        }
    }
    
    int i = binarySearch(arr,n,key);
    if (i == -1)
        printf("Key Not Found");
    else
        printf("Key Found at Index: %d", i);

    return 0;
}
