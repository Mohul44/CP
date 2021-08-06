class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto x : nums)sum+=x;
        if(sum%2!=0)return false;
        sum=sum/2;
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        vector<bool> dp2(sum+1,false);
        dp2[0] = true;
        dp[0][0] = true;
        for(int i=0;i<=n;i++)dp[i][0] = true;
        for(int i=1;i<=n;i++){
            for(int j=sum;j>0;j--){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j]; 
                }
                else dp[i][j] = dp[i-1][j];
              //if you want to use 1D dp you need to start sum from bottom because it would access the j-nums[i-1] sum which wont be affected as we are moving backwards also you 
              //dont need to do the same for i because doesnt matter array element arrangement
                if(j>=nums[i-1])dp2[j] = dp2[j] || dp2[j-nums[i-1]];
            }
        }
        return dp2[sum];
    }
};
