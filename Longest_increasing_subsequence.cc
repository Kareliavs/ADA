#include <bits/stdc++.h>

using namespace std;
auto lis(int X[])
{
int N=17, L=0,lo,hi,mid,newL;
int P[N];
int M[N+10];
int S[L];

    for(int i =0 ; i<N-1; ++i)
    {
    lo =1;
    hi = L;
    while(lo <= hi )
    {
        mid=ceil((lo+hi)/2);
        if(X[M[mid]]<X[i])
            lo =mid+1;
        else
            hi=mid-1;
    }
    newL=lo;
    P[i]=M[newL-1];
    M[newL]=i;
    if(newL>L)
       L=newL;
    int k=M[L];
    for ( int i =L-1; i>=0;--i)
    {
    S[i]= X[k];
    k= P[k];
    }
    }

    for(int i=0;i<L ; ++i)
        cout<<S[i]<<", ";
    cout<<endl;

//return S;
}


int main()
{
int X[]={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
lis(X);
}
