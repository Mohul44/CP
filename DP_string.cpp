//longest common substring only else condition is different
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int answer = 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    answer = max(answer,dp[i][j]);}
                
                    else dp[i][j] = 0;
            }
        }
        
        return answer;
    }
};
