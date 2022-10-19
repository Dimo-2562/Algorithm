#include <iostream>

using namespace std;

#define INF 999999

int** path;

void floyd2(int n, int** graph, int** shortest, int** path){
    int i, j, k;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++)
            path[i][j] = 0;
    }

    //D = W;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++)
            shortest[i][j] = graph[i][j];
    }

    for(k = 1; k <= n; k++){
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                if(shortest[i][k] + shortest[k][j] < shortest[i][j]){
                    path[i][j] = k;
                    shortest[i][j] = shortest[i][k] + shortest[k][j];
                }
            }
        }
    }
}

void findPath(int q, int r){
    if(path[q][r] != 0){
        findPath(q, path[q][r]);
        cout<< " v" << path[q][r];
        findPath(path[q][r], r);
    }
}

int main(void){

    int example[6][6] = { {0, 0, 0, 0, 0, 0}
    , {0, 0, 1, INF, 1, 5}
    , {0, 9, 0, 3, 2, INF}
    , {0, INF, INF, 0, 4, INF}
    , {0, INF, INF, 2, 0, 3}
    , {0, 3, INF, INF, INF, 0}};

    int n = 5;

    int** ex = new int*[n+1];
    int** shortest = new int* [n+1];
    path = new int* [n+1]; 
    for(int i = 0; i < n+1; i++){
        ex[i] = new int[n+1];
        shortest[i] = new int[n+1];
        path[i] = new int[n+1];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ex[i][j] = example[i][j];
        }
    }

    floyd2(n, ex, shortest, path);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << shortest[i][j] << " ";
        }
        cout<<"\n";
    }

    findPath(5, 3);
    
    
        
    return 0;
}