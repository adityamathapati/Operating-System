#include <stdio.h>
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter %d elements: ",size);
    for(int i=0;i<size;i++) {
        scanf("%d", &arr[i]);
    }
    int smallest = arr[0];
    int pos = 0;
    for(int i=1; i<size; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
            pos = i;
        }
    }
    printf("Smallest number = %d\n", smallest);
    printf("Position of smallest number : %d\n",pos+1);
    return 0;
}
