include &lt;iostream&gt;
#include &lt;vector&gt;
#include &lt;algorithm&gt;
using namespace std;
  
#define graph_edge pair&lt;int,int&gt;
  
class Graph {
private:
int V;      // number of nodes in graph
vector&lt;pair&lt;int, graph_edge&gt;&gt; G; // vector for graph
vector&lt;pair&lt;int, graph_edge&gt;&gt; T; // vector for mst
int *parent;
     
public:
Graph(int V);
void AddEdge(int u, int v, int wt);
int find_set(int i);
void union_set(int u, int v);
void kruskal_algorithm();
void display_mst();
};
Graph::Graph(int V) {
parent = new int[V];
  
for (int i = 0; i &lt; V; i++)
parent[i] = i;
  
G.clear();
T.clear();
}
void Graph::AddEdge(int u, int v, int wt) {
G.push_back(make_pair(wt, graph_edge(u, v)));
}
int Graph::find_set(int i) {
    // If i is the parent of itself
    if (i == parent[i])
        return i;
    else
        //else recursively find the parent of i
        return find_set(parent[i]);
}
void Graph::union_set(int u, int v) {
    parent[u] = parent[v];
}
void Graph::kruskal_algorithm() {
    int i, uSt, vEd;
    sort(G.begin(), G.end()); // sort the edges ordered on increasing weight
    for (i = 0; i &lt; G.size(); i++) {
        uSt = find_set(G[i].second.first);
        vEd = find_set(G[i].second.second);
        if (uSt != vEd) {
            T.push_back(G[i]); // add to mst vector
            union_set(uSt, vEd);
        }
    }
}
void Graph::display_mst() {
    cout &lt;&lt; "Edge :" &lt;&lt; " Weight" &lt;&lt; endl;
    for (int i = 0; i &lt; T.size(); i++) {
        cout &lt;&lt; T[i].second.first &lt;&lt; " - " &lt;&lt; T[i].second.second &lt;&lt; " : "
                &lt;&lt; T[i].first;
        cout &lt;&lt; endl;
    }
}
int main() {
    Graph gmst(5);
    gmst.AddEdge(0,1,3);
    gmst.AddEdge(0,3,3);
    gmst.AddEdge(2,3,2);
    gmst.AddEdge(2,4,1);
    gmst.AddEdge(1,4,4);
     
    gmst.kruskal_algorithm();
    cout&lt;&lt;"The Minimum Spanning Tree according to Kruskal's Algorithm:"&lt;&lt;endl;
    gmst.display_mst();
    return 0;
}

Then, Krsukal's algo:

#include &lt;iostream&gt;
#include &lt;cstring&gt;
using namespace std;
  
#define INF 9999
// graph contains 5 vertices
#define V 5 
// an array G that stores adjacency matrix for input graph
 int G[V][V] = {    
    {0, 3, 0, 3, 0},
    {3, 0, 0, 0, 4},
    {0, 0, 0, 2, 1},
    {3, 3, 2, 0, 0},
    {0, 4, 1, 0, 0}};
 
int main () {
int num_edge;            // number of edge
  
  // mst_vertex - array to track vertices selected for spanning tree
  int mst_vertex[V];
   
 // set selected false initially
  memset (mst_vertex, false, sizeof (mst_vertex));
  
 // set number of edge to 0
  num_edge = 0;
  
   //let 0th vertex be the first to be selected
  mst_vertex[0] = true;
   int x;            //  row 
  int y;            //  col 
  
   // print details of MST
  cout&lt;&lt;"The Minimum Spanning Tree as per Prim's Algorithm:"&lt;&lt;endl;
  cout &lt;&lt; "Edge" &lt;&lt; " : " &lt;&lt; "Weight";
  cout &lt;&lt; endl;
  while (num_edge &lt; V - 1) {
  
   //Prim's algorithm code
int min = INF;
    x = 0;
    y = 0;
  
for (int i = 0; i &lt; V; i++) {
if (mst_vertex[i]) {
for (int j = 0; j &lt; V; j++) {
if (!mst_vertex[j] &amp;&amp; G[i][j]) { // not in mst_vertex and there is an edge
if (min &gt; G[i][j]) {
min = G[i][j];
                      x = i;
                      y = j;
                  }
             }
          }
        }
      }
cout &lt;&lt; x &lt;&lt;  " - " &lt;&lt; y &lt;&lt; " :  " &lt;&lt; G[x][y];
cout &lt;&lt; endl;
mst_vertex[y] = true;
num_edge++;
    }
  
return 0;
}
