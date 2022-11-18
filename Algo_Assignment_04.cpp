#include <iostream>
#include <vector>
using namespace std;

#define INF 999

void dijkstra (int n, int** W, vector<pair<int, int>> graph){
    int i, vnear;
    pair<int, int> e;
    int touch[n+1];
    int length[n+1];

    for(i = 2; i <= n; i++){
        touch[i] = 1;
        length[i] = W[1][i];
    }

    for(int k = 0; k < n-1; k ++){
        int min = INF;
        for(i = 2; i <= n; i++){ //Check each vertex for having shortest path.
            if(length[i] <= min && length[i] >= 0){
                min = length[i];
                vnear = i;
            }
        }
        
        e = make_pair(touch[vnear], vnear);
        graph.push_back(e);

        for(i = 2; i <= n; i++){
            if(length[vnear] + W[vnear][i] < length[i]){
                length[i] = length[vnear] + W[vnear][i];
                touch[i] = vnear;
            }
        }
        length[vnear] = -1;
    }

    cout<<"edge list\n\n";
    for(int i = 0; i <graph.size(); i++){
        cout<<graph[i].first<<" "<<graph[i].second<<"\n";
    }
}


int main(void){

    int n = 5;

    //교재의 입력 데이터(Figure 4.8)
    int bookData[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 7, 4, 6, 1},
        {0, INF, 0, INF, INF, INF},
        {0, INF, 2, 0, 5, INF},
        {0, INF, 3, INF, 0, INF},
        {0, INF, INF, INF, 1, 0}
    };

    //임의의 자작 데이터
    int myData[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 3, 8, 1, 5},
        {0, INF, 0, 2, INF, 1},
        {0, INF, INF, 0, INF, INF},
        {0, INF, 6, INF, 0, 4},
        {0, INF, INF, INF, INF, 0}
    };

    vector<pair<int, int>> graph;

    int** W = new int* [n+1];
    for(int i= 0; i <n+1; i++){
        W[i] = new int[n+1];
    }

    for(int i = 0; i <n+1; i++){
        for(int j = 0 ; j < n+1; j++)
            W[i][j] = myData[i][j];
    }

    dijkstra(n, W, graph);

    return 0;
}