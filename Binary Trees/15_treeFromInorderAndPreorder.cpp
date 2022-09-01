/*
*
* Question: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &rootIndex, int inOrderStart, int inOrderEnd){
        
        // base case
        if( inOrderStart > inOrderEnd ){
            return NULL;
        }
        
        int element = inOrderStart;
        
        while(inorder[element] != preorder[rootIndex]){
            element++;
        }
        
        rootIndex++;
        
        TreeNode* newNode= new TreeNode(inorder[element]);
        
        // recursive calls
        newNode -> left = solve(preorder, inorder, rootIndex, inOrderStart, element-1);
        newNode -> right = solve(preorder, inorder, rootIndex, element+1, inOrderEnd);
        
        return newNode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int rootIndex = 0;
        return solve(preorder, inorder, rootIndex, 0, inorder.size()-1);
    }
};