#include <bits/stdc++.h>
using namespace std;

    void swap(int *a ,int *b)
    {
    int temp = *a;
    *a= *b;
    *b= temp;
    }
    int heapsize;

    void max_heapify(int *arr,int i)
{
    int l=2*i,r=2*i+1,largest;
    if(l<heapsize && arr[l]>arr[i])
        largest = l;
    else
        largest = i;
    if(r<heapsize && arr[r]>arr[largest])
        largest = r;

    if(largest != i)
    {
        swap(&arr[i],&arr[largest]);
        max_heapify(arr,largest);
    }
     }
void build_max_heap(int *arr,int len)
{
    heapsize = len;
    int i;
    for(i =len/2;i>=0;i--)
    {
        max_heapify(arr,i);
    }
}
 void heapsort(int *arr,int len)
 {
   int i;
   build_max_heap(arr,len);
    for(i= len-1;i>=1;i--)
    {
        swap(&arr[0],&arr[i]);
        heapsize = heapsize -1;
        max_heapify(arr,0);
    }
 }

    int main()
    {
            int *arr,n,i;
            cout<<"inserte numero de elementos: ";
            cin>>n;
            arr=(int *)malloc(sizeof(int)*n);
            cout<<"inserte elementos:";
            for(i=0;i<n;i++)
            {
             cin>>arr[i];
            }
            //heapsize = n;
            heapsort(arr,n);
            cout<<"ordenado: "<< endl;
            for(i=0;i<n;i++)
            {
                cout<<" "<<arr[i];
            }
        return 0;
    }



