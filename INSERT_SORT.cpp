#include <iostream>
#include <vector>
using namespace std;

vector<int> INSERTION_SORT( vector<int> A)
{

    for(int j=1; j<A.size();++j)
    {
        int key=A[j];
        int i=j-1;
        while(i>-1 and A[i]> key)
        {
            A[i+1]=A[i];
            i=i-1;
        }
        A[i+1]=key;
    }
    for(int i=0; i<A.size();++i)
    {
    cout<<A[i]<<" , ";
    }
    return A;
}
int main ()
{
 vector<int> A;
    int num;
    cin>>num;
    for(int i=0; i<num;++i)
    {   int dato;
        cin>>dato;
        A.push_back(dato);
    }
    INSERTION_SORT(A);
}