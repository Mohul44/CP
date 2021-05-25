class Solution {
public:
    
    bool dfs(vector<vector<int>>&graph, int par,vector<bool> &vis,vector<int> &color,int ind){
        
        vis[ind]= true;
        
        for(int i=0;i<graph[ind].size();i++){
            int node = graph[ind][i];
            
            if(vis[node] == true){
                if(color[node] == color[ind])return false;
            }
            else{
                color[node] = color[ind]^1;
                if(dfs(graph,ind,vis,color,graph[ind][i])==false)return false;
            }
            
        }
        
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<bool> vis(graph.size(),false);
        vector<int> color(graph.size(),-1);
        vector<vector<int>> adj(graph.size());
        color[0] = 1;
        
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
            if(dfs(graph,-1,vis,color,i)==false)return false;
            }
        }
        return true;
    }
};
