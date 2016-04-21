#include <bits/stdc++.h>
#define parent(i) i/2
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
  int heap_maximum(int *arr)
  {return arr[0];
  }

  int heap_extract_max(int *arr,int len)
  {
  if(len<1)
   cout<<"underflow";
  int maxi=arr[0];
  arr[0]=arr[len];
  heapsize--;
  max_heapify(arr,0);
  return maxi;
  }

int heap_increase_key(int *arr,int i, int key ,int len)
  {

  if(key<arr[i])
    cout<<"la nueva clave es mas pequeña que la actual";
  arr[i]= key;

  while(i>1 and arr[parent(i)]<arr[i])
    {
        swap(arr[i],arr[parent(i)]);
        i = parent(i);

    }
   cout<<endl<<"increas"<<i<<endl;
    return i;
  }

void max_heap_insert(int *arr,int key ,int len)
{
heapsize = len+1;
    int i;
    arr[len]=-9999;
    heap_increase_key(arr,heapsize,key ,len);

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
            max_heap_insert(arr,4,n);
            cout<<"ordenado: "<< endl;
            for(i=0;i<n;i++)
            {
                cout<<" "<<arr[i];
            }

        return 0;

}
