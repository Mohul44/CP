class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int start, int end) {
        vector<vector<pair<double,int>>> adj(n);
        
        for(int i=0;i<edges.size();i++){
            int x = edges[i][0];
            int y =  edges[i][1];
            adj[x].push_back({prob[i],y});
            adj[y].push_back({prob[i],x});
        }
        vector<double> proba(n,0.0);
        proba[start] = 1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        vector<bool> vis(n,false);
        while(!pq.empty()){
            int size = pq.size();
            while(size--){
             int node = pq.top().second;   
             vis[node] = true;
             double temp = pq.top().first;
             pq.pop();
             for(auto x : adj[node]){
                 if(vis[x.second])continue;
                 int index = x.second;
                 double pro_b = temp*(x.first);
                 if(pro_b>proba[index]){
                     proba[index] = pro_b;
                     pq.push({pro_b,index});
                 }
             }
            }
        }
            
        return proba[end];
    }
};
