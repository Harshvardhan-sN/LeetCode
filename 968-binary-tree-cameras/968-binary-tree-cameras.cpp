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
    set<TreeNode*> s1;
    void dfs(TreeNode *node, TreeNode* parent){
        if(node){
            dfs(node->left,node);
            dfs(node->right,node);
            
                if((!parent and !s1.count(node)) || 
                    (!s1.count(node->left)) || (!s1.count(node->right))){
                ans++;
                s1.insert(node);
                s1.insert(parent);
                s1.insert(node->left);
                s1.insert(node->right);
            }
        }
    }
public:
    int minCameraCover(TreeNode* root) {
        if(!root)    return 0;
        s1.insert(nullptr);
        dfs(root,nullptr);
        return ans;
    }
};