#include <iostream>
using namespace std;

int main()
{  int n,key,j,count=0;
   cout<<endl<<"Enter number of elements of the array to sort:";
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   {
       a[i]=rand()%10; 
   }
   cout<<endl;
   cout<<"Auto generated array is: "<<endl;
   for(int i=0;i<n;i++)
   {
       cout<<a[i]<<" ";
   }
   cout<<endl;
   for(int i=1;i<n;i++)
   {   
       key=a[i];
       j=i;
       while(j>0 && a[j-1]>key)
       {   count++;
           a[j]=a[j-1];
           j--;
       }
       count++;
       a[j]=key;
   }
   cout<<endl;
   cout<<"Sorted array is: "<<endl;
   for(int i=0;i<n;i++)
   {
       cout<<a[i]<<" ";
   }
   cout<<endl<<endl;
   cout<<"No. of comparisions in the above array is: "<<count<<endl;
   return 0;
}
