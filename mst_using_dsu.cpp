#include<bits/stdc++.h>
#define pii pair<int,pair<int,int>>
using namespace std;
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
    int minCostConnectPoints(vector<vector<int>>& points) {
            int n = points.size();
            priority_queue<pii,vector<pii>,greater<pii>> pq;
           vector<int> par(n);
        for(int i=0;i<n;i++)par[i]=i;
            for(int i=0;i<points.size();i++){
                for(int j=0;j<points.size();j++)
                {
                    if(i==j)continue;
                    int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                    pq.push({dist,{i,j}});
                }
            }
        int answer =0;
            int count = n-1;
        while(!pq.empty() && count>0){
            pii top = pq.top();
            pq.pop();
            int x = top.second.first;
            int y = top.second.second;
            int dist = top.first;
            if(find_set(x,par)==find_set(y,par))continue;
            merge_set(x,y,par);
            answer +=dist;
            count--;
        }
        return answer;
    }
};
