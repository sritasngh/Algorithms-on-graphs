//strongly connected components
#include<bits/stdc++.h>
using namespace std;
stack <int> post; 
bool flag=false;
int cc=0;
class Graph{
	int V;//depending on size input size
	public:
		list <int> *adj;//for each node there is a list
		list<int> *radj;
		Graph(int V);
		void add_edge(int v,int w);
		void DFSrec(int v,bool visited[],list<int>*l);
		void DFS(list<int>*l);
		void DFS(int v,list<int>*l);
		
};
Graph::Graph(int V){
	this->V=V;//when same name is used for local and class parameter
	adj=new list<int>[V];//upon getting no. of vertexes...allocate memory to list of each vertex
	radj=new list<int>[V];
}
void Graph::add_edge(int v,int w){
	adj[v].push_back(w);
	radj[w].push_back(v);
}
void Graph::DFSrec(int v,bool visited[],list<int>*l){
	visited[v]=true;
	list<int>::iterator	i;
	for(i=l[v].begin();i!=l[v].end();++i){
		if(!visited[*i])
			DFSrec(*i,visited,l);	
	}
	if(!flag)
		post.push(v);
	else
		post.pop();
	}
void Graph::DFS(list<int>*l){
	bool *visited= new bool[V];
	for (int i = 0; i <V; i++) 
        visited[i] = false; 
    for(int i=0;i<V;i++){
    	if(!visited[i])
    		DFSrec(i,visited,l);
	}}
void Graph::DFS(int v,list<int>*l){
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	if(!visited[v]){
		DFSrec(v,visited,l);
	}
}
int main(){
    int V,n;
	cin>>V>>n;//V->no of vertex,n->no of edges
	Graph g(V);
	int a,b;
	for(int i=0;i<n;++i){
		cin>>a>>b;
		g.add_edge(a-1,b-1);//vertexes are 0,1,2,3...
	}
	g.DFS(g.radj);
	flag=true;
	cout<<cc<<" ";
	while(!post.empty()){
		int v=post.top();
		g.DFS(v,g.adj);
		cc++;
		cout<<cc<<" ";		
	}
	cout<<cc;
	return 0;
}
