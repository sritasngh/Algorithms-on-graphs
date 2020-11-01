//BFS for a graph
#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    int t;
    list <int> *adj;
    public:
    Graph(int v);
    void add_edge(int p,int q);
    int getdist( );
    void BFS(int s,int w);
    
};
Graph::Graph(int v){
	t=-1;
    V=v;
    adj=new list<int>[V];
}
void Graph::add_edge(int p,int q){
    adj[p].push_back(q);
    adj[q].push_back(p);
}
int Graph::getdist( ){
	return t;
}
void Graph::BFS(int s,int w){
	int *dist = new int[V];
	for(int i=0;i<V;i++)
		dist[i]=V+1;
	list <int> queue;
	dist[s]=0;
	queue.push_back(s);
	list<int>::iterator i;
	while(!queue.empty()){
		s=queue.front();
		queue.pop_front();
		if(s==w)
			t=dist[s];
		for(i=adj[s].begin();i!=adj[s].end();++i){
			if(dist[*i]==V+1){
				dist[*i]=dist[s]+1;
				queue.push_back(*i);
			}
		}
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
	cin>>u>>v;
    g.BFS(u-1,v-1);
    cout<<g.getdist();
    return 0;
    }
