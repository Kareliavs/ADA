#include <bits/stdc++.h>
const double CLK_TCK = 1000.0;
using namespace std;
int price[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
int r[10],s[10];
int longitud = 10;
///RECURSIVO
int Cut_Rod(int p[], int n)
{
   if (n <= 0)
     return 0;
   int q = INT_MIN;
   for (int i = 0; i<n; i++)
         q = max(q, p[i] + Cut_Rod(p, n-i-1));

   return q;
}
///MEMORIZANDO
auto Memorized_Cut_Rod_Aux(int p[], int n, int r[])
{   int q;
    if(r[n]>=0)
        return r[n];
    if(n<=0)
        q=0;
    else
    {   q=INT_MIN;
        for(int i=0;i<n;i++)
            q=max(q,p[i]+Memorized_Cut_Rod_Aux(p,n-i-1,r));
    }
    r[n]=q;
    return q;
}
auto Memorized_Cut_Rod(int p[],int n)
{
    int r[n];
    for (int i=0; i<n; ++i)
        r[i]=INT_MIN;
    return Memorized_Cut_Rod_Aux(p,n,r);

}

///BOTTOM UP CUT ROD
auto Bottom_Up_Cut_Rod(int p[], int n)
{   int q;
    int r[n];
    r[0]=0;
    for(int j=1;j<=n;++j)
    {   q=INT_MIN;
        for(int i=0;i<j;++i)
            q=max(q,p[i]+r[j-i-1]);
        r[j]=q;
    }
    return r[n];
}
///EXTENDED BOTTOM UP CUT ROD
void Print_Cut_Rod_Solution(int s[],int n)
{
    cout<<"Piezas usadas:\n";
   while(n >0)
    {  s[n]+=1;
     cout<<s[n]<<endl;
        n = n - s[n];
    }
}
auto Extended_Bottom_Up_Cut_Rod(int p[], int n)
{   int q;
    int r[n];
    r[0]=0;
    for(int j=1;j<=n;++j)
    {   q=INT_MIN;
        for(int i=0;i<j;++i)
        {   if (q<p[i]+r[j-i-1])
                {q=p[i]+r[j-i-1];
                s[j]=i;
                }
        }
        r[j]=q;
    }
    //Print_Cut_Rod_Solution(s,n);
    return r[n];
}


int main()
{   clock_t start, end;
    //Recursivo
    cout<<"______________RECURSIVO__O(2^n)__________________________________"<<endl;
    start = clock();
    cout<<"Maximo: "<<Cut_Rod(price, 4)<<endl;
    end = clock();
    printf("El tiempo es: %f\n", (end - start) / CLK_TCK);


    //Memorized
     cout<<"______________EN MEMORIA__mejora el anterior_____________________"<<endl;
    start = clock();
    cout<<"Maximo: "<<Memorized_Cut_Rod(price,4)<<endl;
    end = clock();
    printf("El tiempo es: %f\n", (end - start) / CLK_TCK);

    //Bottom up
     cout<<"______________BOTTOM UP__O(n^2)__________________________________"<<endl;
    start = clock();
    cout<<"Maximo: "<<Bottom_Up_Cut_Rod(price,4)<<endl;
     end = clock();
    printf("El tiempo es: %f\n", (end - start) / CLK_TCK);

    //Extended Bottom up
     cout<<"______________EXTENDED BOTTOM UP__mejora el anterior_____________"<<endl;
    start = clock();
    cout<<"Maximo: "<<Extended_Bottom_Up_Cut_Rod(price,4)<<endl;
     end = clock();
    printf("El tiempo es: %f\n", (end - start) / CLK_TCK);


    //PIEZAS USADAS
    cout<<"_________________________________________________________________"<<endl;
    Print_Cut_Rod_Solution(s,4);
    return 0;
}
