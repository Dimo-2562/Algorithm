#include <iostream>
using namespace std;

#define INF 999

int** point;

int minmult(int n, const int matrix[], int** point){
    int i, j, k, diagonal;

    int multipleCount[n+1][n+1];
    for(i = 0; i <= n; i++)
        for(j = 0; j <= n; j++)
            multipleCount[i][j] = INF;

    for(i = 1; i <= n; i++)
        multipleCount[i][i] = 0;

    for(diagonal = 1; diagonal <= n-1; diagonal++)
        for(i = 1; i <= n-diagonal; i++){
            j = i + diagonal;
            for(k = i; k <= j-1; k++){
                if(multipleCount[i][j] > multipleCount[i][k] + multipleCount[k+1][j] + matrix[i-1]*matrix[k]*matrix[j]){
                    multipleCount[i][j] = multipleCount[i][k] + multipleCount[k+1][j] + matrix[i-1]*matrix[k]*matrix[j];
                    point[i][j] = k;
                }
            }
        }

    //multipleCount 배열의 전체 원소를 확인하는 코드
    for(i = 1; i <= n; i++){
        for(j = 1; j <=n; j++){
            if(multipleCount[i][j] == INF)
                cout<<"    ";
            else
                cout<<multipleCount[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
        
    return multipleCount[1][n];

}

void order(int i, int j){
    int k;

    if(i == j)
        cout<<"A"<<i;
    else{
        k = point[i][j];
        cout<< "(";
        order(i, k);
        order(k+1, j);
        cout<<")";
    }
}


int main(void){
    int n, i, j;

    /**
     * @brief 교재의 입력 데이터(Example 3.5)
     */
    int bookMatrix [7] = {5, 2, 3, 4, 6, 7, 8};

    /**
     * @brief 임의의 자작 데이터
     */
    int myMatrix [7] = {4, 9, 2, 3, 6, 8, 5};

    n = 6;

    //배열의 동적 생성
    point = new int* [n+1];
    for(int i = 0; i < n+1; i++){
        point[i] = new int[n+1];
    }
    int* matrix = new int [n+1];

    //배열에 입력 데이터 초기화
    for(int i = 0; i < 7; i++){
        matrix[i] = myMatrix[i];
        for(int j = 0; j < 7; j++)
            point[i][j] = 0;
    }

    int result = minmult(n, matrix, point);

    cout<<"min num: "<<result<<"\n\n";

    //point 배열의 전체 원소를 확인하는 코드
    for(i = 1; i <= n-1; i++){
        for(j = 1; j <= n; j++){
            if(point[i][j] == 0)
                cout<<"  ";
            else
                cout<<point[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    order(1, 6);

   return 0;
}