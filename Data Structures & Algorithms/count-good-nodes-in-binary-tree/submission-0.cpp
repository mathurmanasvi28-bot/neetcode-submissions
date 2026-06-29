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
public:
    int goodNodes(TreeNode* root) {
       if(!root) {return 0;}
       int goodnode = root->val;
       int left_count = helper(root->left, goodnode);
       int right_count = helper(root->right, goodnode);
       return 1+left_count+right_count;
    }
    int helper(TreeNode* root, int goodnode){
        if(!root) return 0;
        int count = 0;
        if(goodnode <= root->val){
            count++;
            goodnode = root->val;
       }
       if(root->left) count+=helper(root->left, goodnode);
       if(root->right) count+=helper(root->right, goodnode);
       return count;
    }
};
