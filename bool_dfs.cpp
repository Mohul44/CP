class Solution {
public:
    
    bool dfs(vector<vector<int>> &graph, int node, vector<int> & vis,vector<int> & recvis){
        vis[node] = true;
        recvis[node] = true;
        for(int i=0;i<graph[node].size();i++){
            if(!vis[graph[node][i]]){
                if(dfs(graph,graph[node][i],vis,recvis)==false)return false;
            }
            else{
                if(recvis[graph[node][i]]){
                    return false;
                }
            }
        }
        recvis[node]=false;
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vec;

        vector<int> vis(n,0);
        vector<int> recvis(n,0);
        
        for(int i=0;i<n;i++){
            if(dfs(graph,i,vis,recvis)==false)continue;
            vec.push_back(i);
        }
        
        
        return vec;
    }
};
