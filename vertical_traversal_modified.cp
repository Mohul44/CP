/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 /*
 Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
*/
#define mkp make_pair
class Solution {
public:
    static bool mysort(pair<int,int> &n1 , pair<int,int> &n2){
            
        if(n1.first == n2.first){
            return n1.second < n2.second;
        }
        
        
        return n1.first < n2.first;
        
        
            
    }
    
    void dfs(map<int, vector<pair<int,int>>>& mp, TreeNode * root, int depth, int row){
        
        if(root==nullptr)return ;
        int value = root->val;
        if(!mp[depth].size()){
            vector<pair<int,int>> temp;
            temp.push_back(mkp(row,value));
            mp[depth] = temp;
        }
        else{
            mp[depth].push_back(mkp(row,value));
        }
        if(root->left)dfs(mp,root->left,depth-1,row+1);
        if(root->right)dfs(mp,root->right,depth+1,row+1);
        return ;
    }
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> answer;
        answer.clear();
        map<int, vector<pair<int,int>>> mp;
        dfs(mp,root,0,0);
       
        for(pair<int, vector<pair<int,int>>> x : mp){
            vector<pair<int,int>> temp = x.second;
            sort(temp.begin(),temp.end(),mysort);
            vector<int> myv;
            for(pair<int,int> y : temp){
                myv.push_back(y.second);
            }
            answer.push_back(myv);
        }
            
        return answer;
            
    }
};
