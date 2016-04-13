#include<bits/stdc++.h>
#define N 2
typedef double datatype;
typedef datatype mat[N][N];
int n,a[2][2],b[2][2],c[2][2],i,j;
int p1,p2,p3,p4,p5,p6,p7;

using namespace std;

int stre(int k, int m, int n)
{
  if (n==1)
    c[0][0]=a[0][0]*b[0][0];
  else if(n==2)
      {
      int aa=a[k][k];
      int ab=a[k][m];
      int ac=a[m][k];
      int ad=a[m][m];
      int be=b[k][k];
      int bf=b[k][m];
      int bg=b[m][k];
      int bh=b[m][m];


      p1= aa*(bf-bh);
      p2= (aa+ab)*bh;
      p3= (ac+ad)*be;
      p4= ad*(bg-be);
      p5= (aa+ad)*(be+bh);
      p6= (ab-ad)*(bg+bh);
      p7= (aa-ac)*(be+bf);

      c[0][0]=p5+p4-p2+p6;
      c[0][1]=p1+p2;
      c[1][0]=p3+p4;
      c[1][1]=p1+p5-p3-p7;
        }
  else
  {
     c[0][0]=stre(0,n/2,n/2);
     c[0][1]=stre(n/2,n,n/2);
     c[1][0]=stre(n/2,n/2,n);
     c[1][1]=stre(n/2,n,n/2);
  }
}

int main(){
int n;
  cout<<"ingrese longitud de la matriz: ";
  cin>>n;
  cout<<endl;
  cout<<"ingrese los n elementos de la primera matriz: "<<endl;
  for(i=0;i<n;i++)
      for(j=0;j<n;j++)
           scanf("%d",&a[i][j]);

  cout<<"ingrese los n elementos de la segunda matriz: "<<endl;
  for(i=0;i<n;i++)
      for(j=0;j<n;j++)
           scanf("%d",&b[i][j]);

  cout<<endl<<"La primera matriz"<<endl;
  for(i=0;i<n;i++){
      printf("\n");
      for(j=0;j<n;j++)
           printf("%d\t",a[i][j]);
  }

  cout<<endl<<"La segunda matriz"<<endl;
  for(i=0;i<n;i++){
      printf("\n");
      for(j=0;j<n;j++)
           printf("%d\t",b[i][j]);
  }

stre(0,n-1,n);

cout<<endl<<"resultado"<<endl;
   for(i=0;i<n;i++){
      cout<<endl;
      for(j=0;j<n;j++)
           printf("%d\t",c[i][j]);
   }
  }

