//Bipartite
#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    int t;
    list <int> *adj;
    public:
    Graph(int v);
    void add_edge(int p,int q);
    int part();
    void BFS( );
    
};
Graph::Graph(int v){
	t=1;
    V=v;
    adj=new list<int>[V];
}
void Graph::add_edge(int p,int q){
    adj[p].push_back(q);
    adj[q].push_back(p);
}
int Graph::part(){
	return t;
}
void Graph::BFS(){
	int s=0;
	int *col = new int[V];
	for(int i=0;i<V;i++)
		col[i]=0;
	list <int> queue;
	col[s]=1;
	queue.push_back(s);
	list<int>::iterator i;
	while(!queue.empty()){
		s=queue.front();
		queue.pop_front();
		for(i=adj[s].begin();i!=adj[s].end();++i){
			if(col[*i]==col[s]){
				t=0;
				break;
			}
			else if(col[*i]==0){
			col[*i]= -col[s];
			queue.push_back(*i);}
		}
		if(t==0)
			break;
		}
	}
int main(){
	int n,m,u,v;
	cin>>n>>m;
	Graph g(n);
	while(m--){
		cin>>u>>v;
		g.add_edge(u-1,v-1);
	}
    g.BFS();
    cout<<g.part();
    return 0;
    }
