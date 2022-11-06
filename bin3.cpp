#include <iostream>
using namespace std;

int bin3(int n , int k){

    int k;

    if(k > n/2) // 조건문에 들어갈 값  
        k = n - k; // 전체 행

    int B[k]; //배열 인덱스, 메모리가 낭비되지 않도록

    for(int i = 0; i <= n; i++){
        for(int j = min(i, k); j>= 0; j--){ //for문 전체 쓰기
            if(j == 0 || j == i)
                B[j] = 1; // 배열 인덱스 
            else   
                B[j] = B[j] + B[j-1]; // B[j] = _ + _ 
                
        }
    }

    return B[k]; // 리턴 값 적기
}