// Understand comparator as condition to swap a and b, a coming first as index in priorityqueue in general a<b means a first b later

class comp
{
  public:
    bool operator()(pair<string, int> a, pair<string, int> b)
    {
           if(a.second<b.second)return true;
        else if(a.second==b.second && a.first>b.first)return true;
        return false;
    }
};
class Solution {
public:
 
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> answer;
        map<string,int> mp;
        priority_queue<pair<string,int>, vector<pair<string,int>>, comp> qu;
        for(auto x : words)mp[x]++;
        for(auto x: mp){
            qu.push(x);
        }
        
        for(int i=0;i<k;i++){
            answer.push_back(qu.top().first);
            qu.pop();
        }
        
        
        
        return answer;
    }
};
