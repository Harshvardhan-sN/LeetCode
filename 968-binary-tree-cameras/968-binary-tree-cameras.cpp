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
class Solution {
private:
    int ans = 0;
    int dfs(TreeNode* node){
        if(!node)   return 1;
        int Left = dfs(node->left); 
        int Right = dfs(node->right);
        
        if(!Left || !Right){
            ans++;
            return 2;
        }
        if(Left==2 || Right==2)     return 1;
        
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        return (!dfs(root) ? ++ans : ans);
    }
};