/*
*
* Question: https://leetcode.com/problems/invert-binary-tree/
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
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL)
            return NULL;
        
        // swap the right & left subtree
        TreeNode* tempRight = root->right;      // stores right subtree in a tempRight tree
        root->right = root->left;           // makes right subtree = left subtree
        root->left = tempRight;             // make left equals the tempRight
        
        invertTree(root->left);         // recursively invert left subtree which was right earlier.
        invertTree(root->right);        // recursively invert right subtree which was left earlier.
        
        return root;        // returns the root.
    }
};