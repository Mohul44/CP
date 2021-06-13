class Solution {
public:
    void dfs(int n, vector<int> & parent, vector<int> & disc, vector<int> & low, vector<vector<int>> & adj, int ind,vector<vector<int>> &bridges ){
        static int time = 0;
        disc[ind] = time;
        low[ind]=time;
        time+=1;
        for(auto x : adj[ind]){
            if(disc[x]==-1){
                parent[x]=ind;
                dfs(n,parent,disc,low,adj,x,bridges);
                low[ind]=min(low[ind],low[x]);
                if(low[x]>disc[ind])bridges.push_back(vector<int>({ind,x}));
            }
            else if(x!=parent[ind])low[ind] = min(low[ind],disc[x]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> bridges;
     
        
        vector<vector<int>> adj(n);
        
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<int> disc(n,-1);
        vector<int> par(n,-1);
        vector<int> low(n,-1);
        
        
        for(int i=0;i<n;i++){
            if(disc[i]==-1){
                dfs(n,par,disc,low,adj,i,bridges);
            }
        }
        
        
        return bridges;
        
    }
};
