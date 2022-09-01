/*
*
* Question: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1
*/

#include <bits/stdc++.h>
using namespace std;

// A binary tree node
struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int solve(Node* root){
        if(root == NULL)
            return 0;
            
        int leftSum = solve(root->left);    // sum for left subtree
        int rightSum = solve(root->right);  // sum for right subtree
        int rootData = root -> data;        // the current root's data
        
        root->data = leftSum + rightSum;    // updating the root data to left+right subtree.
        
        return leftSum + rightSum + rootData;   // the left subtree + right subtree + original root data.
    }
    
    void toSumTree(Node *node)
    {
        solve(node);
    }
};