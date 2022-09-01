/*
*
* Question: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
*
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int depth(Node* root){
        if(root == NULL)
            return 0;
            
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        
        // return (abs(leftDepth - rightDepth)) <=1;
        
        return 1+max(leftDepth, rightDepth);
    }
    
    bool isBalanced(Node *root)
    {

        if(root == NULL)
            return true;
            
        if(abs(depth(root->left) - depth(root->right)) > 1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
};