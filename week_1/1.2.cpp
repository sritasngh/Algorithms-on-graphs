//computing the number of connected components in the given graph
#include<bits/stdc++.h>
using namespace std;
int cc=0;
class Graph{
	size_t V;
	list <int> *adj;
	void DFSrec(int v,bool visited[]);
	public:
		Graph(int V);
		void add_edge(int v,int w);
		void DFS();
		
};
Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}
void Graph::add_edge(int v,int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}
void Graph::DFSrec(int v,bool visited[]){
	visited[v]=true;
	list<int>::iterator	i;
	for(i=adj[v].begin();i!=adj[v].end();++i){
		if(!visited[*i])
			DFSrec(*i,visited);
	}}
void Graph::DFS(){
	bool *visited= new bool[V];
	for (int i = 0; i< V; ++i) 
        visited[i] = false; 
    for(int i=0;i<V;++i){
	if(!visited[i]){
		DFSrec(i,visited);
		cc++;
	}}
}

int main()
{
	int l=0;
    int V,n;
	cin>>V>>n;
	Graph g(V);	
	int a,b;
	for(int i=0;i<n;++i){
		cin>>a>>b;
		g.add_edge(a-1,b-1);
	}
	g.DFS();//no starting node->complete dfs
	cout<<cc;
	return 0;
}
