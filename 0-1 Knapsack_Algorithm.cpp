#include <iostream>
using namespace std;

int weightAll = 0;
int profitAll = 0;
int maxProfit = 0;

int numBest;
string bestSet[100];
string include[100];

/**
 * @brief 교재의 입력 데이터(Example 5.6)
 */
/*
int n = 4;
int W = 16;
int w[5] = {0, 2, 5, 10, 5};
int p[5] = {0, 40, 30, 50, 10};
*/

/**
 * @brief 자작 데이터
 */

int n = 4;
int W = 18;
int w[5] = {0, 3, 4, 12, 5};
int p[5] = {0, 60, 40, 96, 25};


bool promising(int i){
    int j, k;
    int totalWeight;
    float bound;

    if(weightAll >= W)
        return false;
    else{
        j = i+1;
        bound = profitAll;
        totalWeight = weightAll;
        while( (j<=n) && (totalWeight + w[j] <= W)){
            totalWeight += w[j];
            bound += p[j];
            j++;
        }
        k = j;
        if(k <= n)
            bound = bound + (W-totalWeight) * p[k]/w[k];

        //cout<<"bound: "<<bound<<"\n";

        return bound > maxProfit;
    }
}


void knapsack(int i, int profit, int weight){
    //cout<<"i: "<<i<<" ";
    //cout<<"profit: "<<profit<<" "<<"weight: "<<weight<<" ";

    weightAll = weight;
    profitAll = profit;

    if(weight <= W && profit > maxProfit){
        maxProfit = profit;
        numBest = i;
        for(int j = 1; j <= i; j++){
            bestSet[j] = include[j];
        }
    }

    //cout<<"maxProfit: "<<maxProfit<<" ";

    if(promising(i)){
        include[i+1] = "YES";
        knapsack(i+1, profit+p[i+1], weight+w[i+1]);
        include[i+1] = "NO";
        knapsack(i+1, profit, weight);
    }
}


int main(void){

    knapsack(0, 0, 0);

    for(int i = 1; i <= numBest; i++){
        cout<<bestSet[i]<<"\n";
    }


    return 0;
}