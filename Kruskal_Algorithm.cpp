#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

struct node{
    int parent;
    int depth;
};

typedef node universe;
typedef int set_pointer;

universe U[5+1];


void kruskal(int, int, vector<tuple<int, int, int>>, vector<tuple<int, int, int>> &); 

void makeset(int);
set_pointer find(int);
void merge(set_pointer, set_pointer);
bool equal(set_pointer, set_pointer);
void initial(int);

static bool compare(tuple<int, int, int> &a, tuple<int, int ,int> &b){
    if(get<2>(a) == get<2>(b)){
        if(get<0>(a) == get<0>(b))
            return get<1>(a) < get<1>(b);
        else
            return get<0>(a) < get<0>(b);
    }
    else
        return get<2>(a) < get<2>(b);
}

int main(void){
    int n = 5;
    int m = 7;

    vector<tuple<int, int, int>> E, F;
    tuple <int, int, int> e;

    /**
     * @brief 교재의 입력 데이터(Figure 4.7)
     */
    /*
    e = make_tuple(1, 2, 1);
    E.push_back(e);

    e = make_tuple(2, 3, 3);
    E.push_back(e);

    e = make_tuple(3, 4, 4);
    E.push_back(e);

    e = make_tuple(4, 5, 5);
    E.push_back(e);

    e = make_tuple(2, 4, 6);
    E.push_back(e);

    e = make_tuple(3, 5, 2);
    E.push_back(e);

    e = make_tuple(1, 3, 3);
    E.push_back(e);
    */

    /**
     * @brief 임의의 자작 데이터
     */
    e = make_tuple(1, 2, 6);
    E.push_back(e);

    e = make_tuple(1, 3, 2);
    E.push_back(e);

    e = make_tuple(1, 4, 4);
    E.push_back(e);

    e = make_tuple(1, 5, 4);
    E.push_back(e);

    e = make_tuple(2, 3, 1);
    E.push_back(e);

    e = make_tuple(3, 4, 3);
    E.push_back(e);

    e = make_tuple(4, 5, 5);
    E.push_back(e);
    
    kruskal(n, m, E, F);

    for(int i = 0; i < F.size(); i++){
       cout<<"v"<<get<0>(F[i])<<"-v"<<get<1>(F[i])<<"\tweight: "<<get<2>(F[i])<<"\n";
    }

    return 0;
}

void kruskal(int n, int m, vector<tuple<int, int, int>> E, vector<tuple<int, int, int>> &F){
    int i, j;
    set_pointer p, q;
    tuple<int, int, int> e;

    sort(E.begin(), E.end(), compare);

    initial(n);

    int k = 0;

    while(F.size() < n-1){
        e = E.at(k++);

        i = get<0>(e);
        j = get<1>(e);

        p = find(i);
        q = find(j);

        if(!equal(p,q)){
            merge(p,q);
         
            F.push_back(e);
        }
    }
}

void makeset(int i){
    U[i].parent = i;
    U[i].depth = 0;
}

set_pointer find(int i){
    int j;
    j = i;
    while(U[j].parent != j)
        j = U[j].parent;

    return j;
}

void merge(set_pointer p, set_pointer q){
    if(U[p].depth == U[q].depth){
        U[p].depth += 1;
        U[q].parent = p;
    }
    else if(U[p].depth < U[q].depth)
        U[p].parent = q;
    else
        U[q].parent = p;
}

bool equal(set_pointer p, set_pointer q){
    if(p == q)
        return true;
    else
        return false;
}

void initial(int n){
    int i;
    for(i = 1; i <= n; i++)
        makeset(i);
}


