#include <iostream>
#include <cmath>
using namespace std;
int count;
void merge(int *array, int l, int m, int r) 
{
   int i, j, k, nl, nr;
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      count++;
      k++;
   }
   while(i<nl) {       
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int l, int r) 
{
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
int main()
{
    for(int input_size=1;input_size<101;input_size++)
    {
        int a[30+input_size*9];
        int size=sizeof(a)/sizeof(a[0]);
        for(int index=0;index<size;index++)
        {
            a[index]=rand()%10;
        }
        cout<<"Size of array "<<input_size<<" :"<<size<<endl;
        count=0;
        mergeSort(a, 0, size-1);
        cout<<"Number of comparisions of array "<<input_size<<" :"<<count<<endl;
        cout<<endl;
    }

    return 0;
}
