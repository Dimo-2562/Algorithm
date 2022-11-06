#include <iostream>
using namespace std;

void pascal(int size){
    printf("1\n");
    for(int row = 1; row < size; row++){
        printf("1 ");
        double arr[size];
        arr[0] = 1;
        double n = row;
        double k = 1;
        for(int i = 1 ; i < row; i++){

            arr[i] = arr[i - 1] * (n--/ k) ;
            printf("%f ", arr[i]);
            k++;
        }
        printf("1\n");
    }
}

int main(void){

    pascal(6);
}