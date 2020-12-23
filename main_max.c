#include <string.h>
#include <stdlib.h>

int five_max (int *arr, int A);

int main(){
    int A = 10;
    int arr[] = {1, 2, 3, 10, 5, 6, 7, 8, 11, 12};
    int* res = (int*)malloc(sizeof(int)*5);
    for(int i = 0; i < 5; i++){
        *(res + i) = five_max(&arr, A);
    }
    return 0;
}

int five_max (int *arr, int A){
    int max = *arr;
    for(int i =1; i < A; i++){
        if(*(arr + i) > max){
            max = *(arr + i);
        }
    }
    for(int i =0; i < A; i++){
        if(*(arr + i) == max){
            *(arr + i) =0;
        }
    }
    return max;
}




