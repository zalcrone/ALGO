#include <iostream>
#include <cmath>
using namespace std;
int count;
void heap(int a[],int n,int i)
{
   int l=2*i+1;
   int r=2*i+2;
   int largest=i;
   if(l<n && a[l]>a[largest])
   {
      largest=l;
   }
   if(l<n)
   {
      count++;
   }
   if(r<n)
   {
      count++;
   }
   if(r<n && a[r]>a[largest])
   {
      largest=r;
   }
   if(largest!=i)
   {
      swap(a[largest],a[i]);
      heap(a,n,largest);
   }
}
void heapsort(int a[],int n)
{
   for(int i=floor((n-1)/2);i>=0;i--)
   {
      heap(a,n,i);
   }
   for(int i=n-1;i>=0;i--)
   {
      swap(a[0],a[i]);
      heap(a,i,0);
   }
}
int main()
{ 
  for(int input_size=1;input_size<101;input_size++)
    {
      int a[30+input_size*9];
      int size = sizeof(a)/sizeof(a[0]);
      for(int index=0;index<size;index++)
      {
         a[index]=rand()%10;
      }
      cout<<"Size of array "<<input_size<<" is:"<<size<<endl;
      count=0;
      heapsort(a, size);
      cout<<"Number of comparisions of array "<<input_size<<" is:"<<count<<endl;
      cout<<endl;
    }
  return 0;
}
