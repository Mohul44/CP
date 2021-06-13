class Solution {
public:
    
    int find_set(int x,vector<int> & par){
        if(par[x]==x)return x;
        return par[x] = find_set(par[x],par);
    }
    
    void merge_set(int x, int y, vector<int> &par){
        int par_x = find_set(x,par);
        int par_y = find_set(y,par);
      
        if(par[par_x]>par[par_y]){
            par[par_x] = par[par_y];
        }
        else{
            par[par_y] = par[par_x];
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> par(n);
        for(int i=0;i<n;i++)par[i]=i;
        int count = 1;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                merge_set(i,adj[i][j],par);
            }
        }
        
        for(int i=0;i<n;i++){
            if(find_set(par[0],par)==find_set(i,par))continue;
            else{
                count++;
                cout<<i<<par[0]<<par[i]<<endl;
                merge_set(par[0],i,par);
            }
        }
        
        return count;
    }
};
