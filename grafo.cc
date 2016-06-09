#include <bits/stdc++.h>
using namespace std;
void imprimir(vector<vector<int>> grafo)
{
    for(int i=0;i<grafo.size();++i)
    {
        for(int j=0;j<grafo[i].size();++j)
        {cout<<grafo[i][j]<<" ";
        }
        cout<<endl;
    }
}
void inserta()
{
vector<vector<int>> grafo;
cout<<"inserte numero de nodos";
int n,j;
int k;
cin>>n;
cout<<endl;
for(int i=0;i<n;++i)
    {
    cout<<"el nodo "<<i<<" se relaciona con (Y/N)"<<endl;
    vector<int>grafo2;
    for(int j=0;j<n;++j)
    {
    cout<<"nodo "<<j<<" : ";
    cin>>k;
    cout<<endl;
    if(k==1)
        grafo2.push_back(1);
    else
        grafo2.push_back(0);
    }
    grafo.push_back(grafo2);
    }
imprimir( grafo);
}
void undirected()
{   vector<vector<int>> grafo;
    cout<<"GRAFO NO DIRIGIDO"<<endl;
    grafo.push_back({0,1,0,0,1});
    grafo.push_back({1,0,1,1,1});
    grafo.push_back({0,1,0,1,0});
    grafo.push_back({0,1,1,0,1});
    grafo.push_back({1,1,0,1,0});
    for(int i=0;i<grafo.size();++i)
    {
        for(int j=0;j<grafo[i].size();++j)
        {cout<<grafo[i][j]<<" ";
        }
        cout<<endl;
    }
}
void directed()
{   vector<vector<int>> grafo;
    cout<<"GRAFO DIRIGIDO"<<endl;
    grafo.push_back({0,1,0,1,0,0});
    grafo.push_back({0,0,0,0,1,0});
    grafo.push_back({0,0,0,0,1,1});
    grafo.push_back({0,1,0,0,0,0});
    grafo.push_back({0,0,0,1,0,0});
    grafo.push_back({0,0,0,0,0,1});
    for(int i=0;i<grafo.size();++i)
    {
        for(int j=0;j<grafo[i].size();++j)
        {cout<<grafo[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    inserta();
    cout<<"EJEMPLOS LIBRO"<<endl;
    undirected();
    directed();
        return 0;
}
