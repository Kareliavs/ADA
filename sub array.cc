#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
vector<int> MCSA(vector<int>A, int low, int mid , int high)
{
int left_sum=-99999999;
int max_left,right_sum, max_right;
int sum =0;
for (int i=mid; i>=low;--i)
{
    sum+=A[i];
    if(sum >left_sum)
    {
        left_sum=sum;
        max_left=i;
    }
}
right_sum=-99999999;
sum=0;
for(int j =mid+1; j<= high; ++j)
{
    sum = sum +A[j];
    if(sum>right_sum)
    {
        right_sum=sum ;
        max_right=j;
    }
}
vector<int> B;
B.push_back(max_left);
B.push_back(max_right);
B.push_back(left_sum+right_sum );
return B;
}
vector<int> FMS(vector<int>A, int low, int high)
{vector<int> B,C,D,E;
if(high== low)
{ B.push_back(low);B.push_back(high);B.push_back(A[low]);
       return B; cout<<"here"<<endl;
}
else
    {
    int mid=floor((low+high)/2);
    C=FMS(A,low,mid);
    D=FMS(A,mid+1,high);
    E=MCSA(A,low,mid,high);
    if(C[2]>=D[2]and C[2]>=E[2])
        return C;
    else if(D[2]>=C[2]and D[2]>=E[2])
        return D;
    else
        return E;
    }
}

int main()
{ vector<int> A={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
 vector<int> B= FMS(A,0,15);
 cout<<"inicio: "<<B[0]<<"  fin: "<<B[1]<<"  suma:"<<B[2];

    return 0;
}
