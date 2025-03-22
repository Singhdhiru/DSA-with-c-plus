#include <iostream>
#include <vector>

using namespace std;

class DisjointSet{
    public :
        vector<int> parent,size;
        
        DisjointSet(int n){
            size.resize(n+1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
                size[i]=1;
            }
            
        }
        
        
        int findUpar(int node){
            if(parent[node]==node) 
                return node;
            
            return parent[node]=findUpar(parent[node]);
            
        }
        
        
        void UnionbySize(int u , int v){
            
            int ulp_u=findUpar(u);
            int ulp_v=findUpar(v);
            
            if(ulp_u==ulp_v){
                return;
            }
            else if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};
int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds (V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    ds.UnionbySize(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<V;i++){
            
            if(ds.parent[i]==i) cnt++;
        }
        
        return cnt;
    }

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adjacencyMatrix(V, vector<int>(V, 0));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    int provinces = numProvinces(adjacencyMatrix, V);
    cout << "Number of provinces: " << provinces << endl;

    return 0;
}
