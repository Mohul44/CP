class Solution {
public:
     bool dfs(vector<bool> &vis, vector<bool> &recvis, vector<vector<int>> &prerequisites,int ind)
    {
        vis[ind] = true;
        recvis[ind] = true;
        for(int i=0;i<prerequisites[ind].size();i++){
            int node = prerequisites[ind][i];
                if(!vis[node]){
                   if(dfs(vis,recvis,prerequisites,prerequisites[ind][i]))return true; 
                }
                else{
                    cout<<i<<node<<recvis[node]<<endl;
                    if(recvis[node])return true;
                }
        }
        
        recvis[ind] = false;
        return false;
    }
    
    void topodfs(vector<bool> &vis, vector<vector<int>> & prerequisites, int ind, stack<int>& mystk){
        vis[ind] = true;
        cout<<ind;
        for(auto x : prerequisites[ind]){
            if(!vis[x]){
                topodfs(vis,prerequisites,x,mystk);
            }
        }
        
        mystk.push(ind);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    
         vector<bool> vis(numCourses,false);
        vector<bool> recvis(numCourses,false);
        vector<int> answer;
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(dfs(vis,recvis,adj,i))return answer;
        }
        
        vector<bool> vis2(numCourses,false);
        stack<int> mystk;
        for(int i=0;i<numCourses;i++){
                    if(!vis2[i]){
                        topodfs(vis2,adj,i,mystk);
                    }
        }
    
        
        while(!mystk.empty()){
            cout<<mystk.top();
            answer.push_back(mystk.top());
            mystk.pop();
        }
    
        return answer;
    }
};
