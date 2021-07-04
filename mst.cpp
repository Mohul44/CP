//best kruskal
class Solution {
public:
    vector<int> parent;
    int count;
    int res;
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return (a[2] < b[2]);
    }
    
    int find(int i) {
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }
    void merge(int a, int b, int c){
          int rx = find(a), ry = find(b);
            if (rx != ry) {
                res += c;
                if(ry<rx)swap(ry,rx);
                parent[ry] = rx;
                count++;
            }
    }
    int minimumCost(int N, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), comp);
        parent.resize(N+1, 0);
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }
        res = 0;
        count = 1;
        for (auto& c : connections) {
            merge(c[0],c[1],c[2]);
        }
         if (count == N) return res;
        return -1;
    }
};

//prism
typedef pair<int,int> pii;
class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        vector<vector<pii>> mp(N+1);
        vector<bool> visited(N+1, false);
        vector<int> minCost(N+1, INT_MAX);
        for (auto& edge : connections) {
            mp[edge[0]].push_back({edge[2], edge[1]});
            mp[edge[1]].push_back({edge[2], edge[0]});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,1});
        int numVisited = 0, res = 0;
        while (numVisited < N && !pq.empty()) {
            int cost = pq.top().first, city = pq.top().second;
            pq.pop();
            if (visited[city]) continue;
            visited[city] = true;
            numVisited++;
            res += cost;
            for (auto& n : mp[city]) {
                cost = n.first;
                city = n.second;
                if (!visited[city] && cost < minCost[city]) {
                    minCost[city] = cost;
                    pq.push({cost, city});
                }
            }
        }
        return numVisited == N ? res : -1;
    }
};









//og
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> vpq(n+1);
        for(auto x : connections){
            int node =  x[0];
            int node_to = x[1];
            int val = x[2];
            vpq[node].push({val,node_to});
            vpq[node_to].push({val,node});
        }
        
        vector<int> vis(n+1,false);
        vis[0] = true;
        int cost = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        
        while(pq.size()){
            pair<int,int> y =  pq.top();
             pq.pop();
            if(vis[y.second]==true)continue;
            vis[y.second] = true;
            auto x = vpq[y.second];
            cost+=y.first;
            while(x.size()){
                if(vis[x.top().second]==false){
                    pq.push({x.top().first,x.top().second});
                }
                vpq[y.second].pop();
                x.pop();
            }
        }
        for(auto x : vis)if(!x)return -1;
        return cost;
    }
};
