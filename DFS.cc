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
for(int i=0; i<u->adj.size();++i)//voy por su lista de adyacencias
{
    v=u->adj[i].first;
    if(v->color==WHITE)//si no fue visitado
    {
        v->pi=u;//indico su padre
        DFS_VISIT(grafo,v);//lo visito
    }
}
u->color=BLACK;//TERMINA DE RECORRER
timer=timer+1;
u->f=timer;//aumenta el tiempo global y se lo asigna
cout<<"  "<< u->id<<" fin "<<u->f<<endl;

}
void DFS(vector<Node*>& grafo)
{
    for(int i=0; i<grafo.size();++i)
        {
        grafo[i]->color=WHITE;//inicializacion
        grafo[i]->pi=NULL;
        }
    timer=0;
    for(int i=0; i<grafo.size();++i)
        {
            if(grafo[i]->color==WHITE)//Si no fue visitado lo visito
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
    {cin>>a>>b>>peso;
    grafo[a]->adj.push_back(make_pair(grafo[b],peso));
    //grafo[b]->adj.push_back(make_pair(grafo[a],peso));//doble direccion
    }
    DFS(grafo);
    return 0;

}
///6 8 626
/*
0 1 1
0 3 1
1 4 1
2 4 1
3 1 1
4 3 1
2 5 1
5 5 1
*/
