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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){return {};}
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        vector<vector<int>> output;
        while(!q.empty()){
            int size = q.size();
            int mmin = q.front().second;
            int first, last;
            vector<int> bla;
            for(int i=0; i<size; i++){
                int curr_id = q.front().second-mmin;
                TreeNode* node = q.front().first;
                q.pop();
                bla.push_back(node->val);
                if(node->left) q.push({node->left, curr_id*2+1});
                if(node->right) q.push({node->right, curr_id*2+2});
            }
            output.push_back(bla);
        }
        return output;
    }
};
