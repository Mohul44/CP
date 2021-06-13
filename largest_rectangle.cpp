class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
    int answer = 0;
    for(int i=0;i<heights.size();){
        int ii = i;
         if(stk.empty() || stk.top()<=heights[ii]){
          stk.push(i++);
     }else{
        int maxarea = 0;
        int top = stk.top();
        stk.pop();
        if(stk.empty()){
            maxarea = heights[top]*ii;
        }
        
        else{
            maxarea = heights[top]*(ii-stk.top()-1);
        }
        
        if(maxarea>answer)answer = maxarea;
    }
    
    
    while(!stk.empty()){
        
        int maxarea = 0;
        int top = stk.top();
        stk.pop();
        if(stk.empty()){
            maxarea = heights[top]*i;
        }
        
        else{
            maxarea = heights[top]*(i-stk.top()-1);
        }
        
        if(maxarea>answer)answer = maxarea;
    }
    }
    return answer;
    }
};

 // int n=A.size();
 //    vector<int>left(n),right(n,n-1);
 //    stack<int>a,b;
 //    for(int i=0;i<n;i++){
 //        while(!a.empty() && A[a.top()]>=A[i])a.pop();
 //        if(!a.empty())left[i]=a.top()+1;
 //        a.push(i);
 //    }
 //    for(int i=n-1;i>=0;i--){
 //        while(!b.empty() && A[b.top()]>=A[i])b.pop();
 //        if(!b.empty())right[i]=b.top()-1;
 //        b.push(i);
 //    }
 //    int ans=0;
 //    for(int i=0;i<n;i++)ans=max(ans,A[i]*(right[i]-left[i]+1));
 //    return ans;
