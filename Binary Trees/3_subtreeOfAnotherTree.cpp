/*
*
* Question: https://leetcode.com/problems/subtree-of-another-tree/submissions/
*
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL)
            return false;
        
        // check for the left and right subtree
        return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL)     // if both are null then the structure and value is same
            return true;
        
        if(root == NULL || subRoot == NULL)         // even if one is null while other is not then they are not same.
            return false;
        
        if(root->val == subRoot->val)           // check also for the value since mentioned in the question

            // recursively checking for the left and the right subtree
            return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
        else
            
            // return false if the value does not matches.
            return false;
    }
};