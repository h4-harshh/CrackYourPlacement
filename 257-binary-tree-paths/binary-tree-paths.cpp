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
    void solve(TreeNode *root,string str,vector<string>&result){
        if(!root->left && !root->right) result.push_back(str);

        if(root->left)
        {
            solve(root->left,str+"->"+to_string(root->left->val),result);
        }
        if(root->right)
        {
            solve(root->right,str+"->"+to_string(root->right->val),result);
        }
        // if (root == nullptr)
        //     return;

        // // str.push_back(root->val);
        // str+=to_string(root->val)+"->";

        // if (!root->left && !root->right)
        // {
        //     str.pop_back();
        //     str.pop_back();
        //     result.push_back(str);
        //     return;
        // }

        // solve(root->left, str,result);
        // solve(root->right, str,result);
        // str.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
       if(root!=nullptr){
            solve(root,to_string(root->val),result);
       }
        return result;
    }
};