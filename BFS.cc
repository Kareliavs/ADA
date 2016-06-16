#include <bits/stdc++.h>
using namespace std;
#define INFI INT_MAX
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
  vector<pair<Node*,int>> adj;
  Node(int t_id)
  {
  id=t_id;
  dist=0;
  color =WHITE;
  pi=NULL;
  }
};
void BFS(vector<Node*>& grafo, int s)
{
    Node* u;
    Node* v;
    for(int i=0; i<grafo.size();++i)
        {
        grafo[i]->color=WHITE;///INICIALIZACION
        grafo[i]->dist=INFI;
        grafo[i]->pi=NULL;
        }
    grafo[s]->color=GREY;//Lo esta visitando
    grafo[s]->dist=0;
    grafo[s]->pi=NULL;
    deque<Node*> Q;
    Q.push_front(grafo[s]);
    while(!Q.empty())
    {
        u=Q.front();//el primero
        cout<< u->id <<" dist "<<u->dist <<endl;
        for(int i =0;i<u->adj.size();++i)//voy por todas las adyacencias
        {
            v=u->adj[i].first;
            if(v->color==WHITE) //Si no fue visitado lo visito
            {   v->color=GREY;
                v->dist=u->dist+1;
                v->pi=u;
                Q.push_back(v); //lo pongo a la cola
            }
        }
        u->color=BLACK; //ya esta visitado
        Q.pop_front();

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
    grafo[b]->adj.push_back(make_pair(grafo[a],peso));//doble direccion
    }
    cout<<"Vertice en el cual iniciar: ";
 cin>>inicio;
    BFS(grafo,inicio);
    return 0;

}
///8 10 1 617
/*
0 4 1
0 1 1
1 5 1
2 5 1
2 3 1
2 6 1
3 6 1
3 7 1
5 6 1
6 7 1


*/
