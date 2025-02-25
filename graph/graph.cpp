#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class graph {
    public:
       unordered_map<int,list<int>> adj;

       void createGraph(int u,int v, bool dir){
            adj[u].push_back(v);
            //dir == 0 -> undir graph
            //dir == 1 -> dir graph
            if(dir==0){
                adj[v].push_back(u);
            }
       }

       void printGraph(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
       }
};

//adj mat
void addEdge(vector<vector<int>> &mat, int i, int j)
{
    mat[i][j] = 1;
    mat[j][i] = 1; // Since the graph is undirected
}

void displayMatrix(vector<vector<int>> &mat)
{
    int V = mat.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main(){

    // graph g;

    // int m;

    // cout<<"enter no of edges:"<<endl;
    // cin>>m;
    
    // cout<<"enter nodes"<<endl;
    // for(int i=0; i<m; i++){
    //     int u,v;
    //     cin>>u>>v;
    //     g.createGraph(u,v,0);
        
        
    // }

    // g.printGraph();
    


     // Create a graph with 4 vertices and no edges
    // Note that all values are initialized as 0
    int V = 4;
    vector<vector<int>> mat(V, vector<int>(V, 0));

    // Now add edges one by one
    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);

    /* Alternatively we can also create using below
       code if we know all edges in advacem

     vector<vector<int>> mat = {{ 0, 1, 0, 0 },
                               { 1, 0, 1, 0 },
                               { 0, 1, 0, 1 },
                               { 0, 0, 1, 0 } }; */

    cout << "Adjacency Matrix Representation" << endl;
    displayMatrix(mat);

    return 0;



}