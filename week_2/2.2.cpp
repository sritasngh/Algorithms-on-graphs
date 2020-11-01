//Determining an Order of Courses 
//TopologicalSort
#include<bits/stdc++.h>
using namespace std;
stack <int> post; 
class Graph{
	size_t V;//depending on size input size
	list <int> *adj;//for each node there is a list
	void DFSrec(int v,bool visited[]);//so that we can reach variabals of this class
	public:
		Graph(int V);
		void add_edge(int v,int w);
		void DFS();
		
};
Graph::Graph(int V){
	this->V=V;//when same name is used for local and class parameter
	adj=new list<int>[V];//upon getting no. of vertexes...allocate memory to list of each vertex
}
void Graph::add_edge(int v,int w){
	adj[v].push_back(w);
}
void Graph::DFSrec(int v,bool visited[]){
	visited[v]=true;
	list<int>::iterator	i;
	for(i=adj[v].begin();i!=adj[v].end();++i){
		if(!visited[*i])
			DFSrec(*i,visited);	
	}
	post.push(v);
	}
void Graph::DFS(){
	bool *visited= new bool[V];
	for (int i = 0; i <V; i++) 
        visited[i] = false; 
    for(int i=0;i<V;i++){
    	if(!visited[i])
    		DFSrec(i,visited);
	}}
int main(){
    int V,n;
	cin>>V>>n;//V->no of vertex,n->no of edges
	Graph g(V);
	int a,b;
	for(int i=0;i<n;++i){
		cin>>a>>b;
		g.add_edge(a-1,b-1);//vertexes are 0,1,2,3...
	}
	g.DFS();
	while(!post.empty()){
		cout<<post.top()+1<<" ";
		post.pop();
	}
	return 0;
}
