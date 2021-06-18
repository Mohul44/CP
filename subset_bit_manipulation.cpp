#define fr(i,a,n) for(int i=a;i<=n;i++)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        int mask = 0;
        int n = nums.size();
        int total = 1<<n;
        
        fr(i,1,total){
            vector<int> temp;
            temp.clear();
            for(int j=0;j<n;j++){
                int num = 1<<j;
                if((i&num)!=0)temp.push_back(nums[j]);
            }
            answer.push_back(temp);
        }
        
        return answer;
    }
