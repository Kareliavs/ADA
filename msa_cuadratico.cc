#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int> FMS(vector<int>A, int a, int b)
{vector<int> R;
int maxi=-9999;
int num,p,q;
    for(int i=a; i<=b;++i)
    {num=A[i];
        for (int j=i+1;j<=b;++j)
         {num+=A[j];
            if(maxi<num)
            {
             maxi=num;
             p=i;
             q=j;
            }

         }
    }

R.push_back(p);
R.push_back(q);
R.push_back(maxi);
return R;

  //  return respuesta;
}

int main()
{ vector<int> A={-13,-3,-25,-20,3,10};
  vector<int> B=FMS(A,0,5);
  cout<<"inicio: "<<B[0]+1<<"  fin: "<<B[1]+1<<"  suma:"<<B[2];

    return 0;
}
