#include <stdio.h>
int hasDuplicates(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int size;
    printf("Enter the no of elements : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter %d elements :\n",size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    if (hasDuplicates(arr, n))
        printf("Array contains duplicates.\n");
    else
        printf("Array does not contain duplicates.\n");
    return 0;
}
