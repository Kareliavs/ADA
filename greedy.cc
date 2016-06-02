#include <bits/stdc++.h>
using namespace std;
vector<int> a;
void Recursive(int s[], int f[],int k, int n)
{

int m =k+1;
cout<<" "<<k;
while(m<=n and s[m]<f[k])
    ++m;
if(m<=n)
 {
 Recursive(s,f,m,n);
 }
//return;
}
void greedy(int s[], int f[], int n)
{
    int i, m;
    i = 0;
    cout<<endl<<"Actividades seleccionadas Greedy"<<endl;
    cout<<i;
    for (m = 1; m < n; m++)
    {
      if (s[m] >= f[i])
      {
          cout<<" "<<m;
          i = m;
      }
    }
}

int main()
{
    int s[] =  {1, 3, 0, 5, 3, 5, 6, 8, 8, 2,12};
    int f[] =  {2, 4, 6, 7, 9, 9,10,11,12,14,16};
    int n = sizeof(s)/sizeof(s[0]);
    cout<<"Actividades seleccionadas Recursivo"<<endl;
    Recursive(s, f,0, n);
    greedy(s, f, n);
    getchar();
    return 0;
}
