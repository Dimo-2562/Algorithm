#include <iostream>
using namespace std;

#define INF 999

struct node{
    int key;
    node* left;
    node* right;
};

typedef node* node_pointer;

void optimalSearchTree(int n, const float p[], float& minAvg, int** R){
    int i, j, k, diagonal;
    float A[n+2][n+1];

    float sum = 0;
    for(i = 0; i <= n+1; i++)
        for(j = 0; j <= n; j++)
            A[i][j] = 0;

    for(i = 1; i <= n; i++){
        A[i][i-1] = 0;
        A[i][i] = p[i];
        R[i][i] = i;
        R[i][i-1] = 0;
    }
    A[n+1][n] = 0;
    R[n+1][n] = 0;

    for(diagonal = 1; diagonal <= n-1; diagonal++)
        for(i = 1; i <= n-diagonal; i++){
            j = i + diagonal;
            float minval = INF;
            for(k = i; k <= j; k++){
                if(minval > A[i][k-1] + A[k+1][j]){
                    minval = A[i][k-1] + A[k+1][j];
                    R[i][j] = k;
                }
            }

            sum = p[i];
            for(k = i+1; k <= j; k++)
                sum += p[k];
            A[i][j] = minval + sum;
        }
    
    minAvg = A[1][n];

    //
    for(i = 1; i < n+2; i++){
        for(j = 0; j < n+1; j++){
            cout<<A[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

int main(void){
    int n = 4;
    
    //교재의 입력 데이터(Figure 3.9)
    float bookProbability[5] = {0, 0.375, 0.375, 0.125, 0.125};

    //임의의 자작 데이터
    float myProbability[5] = {0, 0.1, 0.4, 0.3, 0.2};

    float minAvg;

    int** R = new int* [n+2];
    for(int i = 0; i < n+2; i++){
        R[i] = new int[n+1];
    }

    for(int i = 0; i < n+2; i++)
        for(int j = 0; j < n+1; j++)
            R[i][j] = 0;

    optimalSearchTree(n, myProbability, minAvg, R);

    cout<<"\n"<<minAvg<<"\n\n";

    for(int i = 1; i <= n+1; i++){
        for(int j = 0; j <= n; j++)
            cout<<R[i][j]<<"\t";
        cout<<"\n";
    }


    return 0;
}