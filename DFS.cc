#include <bits/stdc++.h>
using namespace std;
#define INFI INT_MAX
typedef vector<pair<int,int>> vec;
int timer;
enum colores{
    WHITE,
    GREY,
    BLACK
};
struct Node
{
  colores color;
  int id;
  int dist;
  Node* pi;
  int f;
  vector<pair<Node*,int>> adj;
  Node(int t_id)
  {
  id=t_id;
  dist=0;
  color =WHITE;
  pi=NULL;
  f=0;
  }
};
void DFS_VISIT(vector<Node*>& grafo, Node* u)
{

Node * v;
timer++;
u->dist=timer;
cout<< u->id <<" inicio "<<u->dist<<endl;
u->color=GREY;
for(int i=0; i<u->adj.size();++i)
{
    v=u->adj[i].first;
    if(v->color==WHITE)
    {
        v->pi=u;
        DFS_VISIT(grafo,v);
    }
}
u->color=BLACK;//TERMINA DE RECORRER
timer=timer+1;
u->f=timer;
cout<<"  "<< u->id<<" fin "<<u->f<<endl;

}
void DFS(vector<Node*>& grafo)
{
    for(int i=0; i<grafo.size();++i)
        {
        grafo[i]->color=WHITE;
        grafo[i]->pi=NULL;
        }
    timer=0;
    for(int i=0; i<grafo.size();++i)
        {
            if(grafo[i]->color==WHITE)
            {
            DFS_VISIT(grafo,grafo[i]);
            }
        }

}

int main()
{//lista de adyacencias
 int vertices,aristas,a,b,peso,inicio;
 cout<<"Numero de vertices: ";
 cin>>vertices;
 cout<<endl<<"Numero de aristas: ";
 cin>>aristas;
 vector<Node*>grafo;
    for(int i=0;i<vertices;++i)
    {grafo.push_back(new Node(i));
    }
  cout<<endl<<"ingrese nodo de partida, llegada y peso "<<endl;
    for(int i=0;i<aristas;++i)
    {cin>>a>>b;
    grafo[a]->adj.push_back(make_pair(grafo[b],0));
    //grafo[b]->adj.push_back(make_pair(grafo[a],peso));//doble direccion
    }
    DFS(grafo);
    return 0;

}
///6 8 626
/*
0 1
0 3
1 4
2 4
3 1
4 3
2 5
5 5
*/
