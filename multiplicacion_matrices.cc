#include <cstdlib>
#include <math.h>
#include <iostream>

using namespace std;
int mul(int a[3][3], int b[])
{int c[3];
for (int i=0;i<3;i++){
         c[i]=0;
    }

    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            c[i]+=( a[i][j]*b[j]);
        }
    }

    for (int i=0;i<3;i++){
        cout<<c[i]<<"  "<<endl;
    }
}
int main()
{
    int a[3][3]={{ 2,4,3},{1,5,7},{0,2,3}};
    int b[]={2,5,6};
    mul(a,b);


}
