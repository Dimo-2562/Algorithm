#include <iostream>
using namespace std;
void quicksort(int low, int high);

void quicksort2(int low, int high);
int S[11] = {0, 3,8,48,73,11,31,20,29,65,15};

int main()
{
   for(int i = 1 ; i <= 10 ; i++)
   {
      cout << S[i] << " ";
   }
   cout << "\n";
   cout << "after\n";

   quicksort2(1,10);

   for(int i = 1 ; i <= 10 ; i++)
   {
      cout << S[i] << " ";
   }
   cout << "\n";
}

void partition2(int low, int high, int& pivotpoint)
{
   int i,j;
   int pivotItem;
   
   pivotItem = S[high];
   j = low;
   for(i = low; i <= high -1 ; i++)
   {
      if(S[i] < pivotItem)
      {
         
         swap(S[i],S[j]);

         j++;
      }
   }
   
   pivotpoint = j;
   swap(S[high],S[pivotpoint]);
}


void quicksort2(int low, int high)
{
   int pivotpoint;
   
   if(high > low)
   {
      partition2(low,high,pivotpoint);
      quicksort2(low,pivotpoint-1);
      quicksort2(pivotpoint+1,high);
   }
}