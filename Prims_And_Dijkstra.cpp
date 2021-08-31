#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> & adj, int src){
    int n = adj.size();
    vector<int> dis(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dis[src] = 0;
    pq.push({0,src});
    while(pq.size()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto x : adj[node]){
            if(dis[x]>d + 1){
                dis[x] = d+1;
                pq.push({dis[x],x});
            }
        }
    }
    return dis;
}

vector<int> prims(vector<vector<pair<int,int>>> & adj, int src){
    int n = adj.size();
    vector<int> par(n,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    par[src] = src;
    pq.push({0,src});
    vector<int> key(n,INT_MAX);
    vector<bool> vis(n,false);
    key[src] = 0;
    while(pq.size()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(vis[node]==true)continue;
        vis[node]= true;
        for(auto x : adj[node]){
            if(vis[x.first]==false && key[x.first]>x.second){
                key[x.first] = x.second;
                pq.push({key[x.first],x.first});
                par[x.first] = node;
            }
        }
    }
    return par;
}



int main(){
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);
    adj[0].push_back({1,10});
    adj[0].push_back({2,100});
    adj[1].push_back({3,1});
    adj[3].push_back({4,2});
    adj[4].push_back({2,7});
    vector<int> par = prims(adj,0);
    for(auto x : par)cout<<x<<" ";
    return 0;
}
