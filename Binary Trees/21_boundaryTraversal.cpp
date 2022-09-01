/*
*
* Question: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
*
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:
    
    void traverseLeft(Node *root, vector <int>&ans){
        
        // base case
        if ((root == NULL) || (root->left == NULL && root->right == NULL)) // left traversal except left leaf nodes.
            return;
            
        ans.push_back(root->data);      // pushing the node into the vector
        
        if(root->left)            
            traverseLeft(root->left, ans);      // going recursively for left subtree
        else
            traverseLeft(root->right, ans);     // // going recursively for right subtree
    }
    
    void traverseLeaf(Node* root, vector <int> &ans){       // to traverse the leaf nodes
        
        // base case
        if(root == NULL)
            return;
            
        if(root->left == NULL && root->right == NULL){      // condition that proves the node is a *leaf node*
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left, ans);                  // // going recursively for left subtree
        traverseLeaf(root->right, ans);                 // going recursively for right subtree
    }
    
    void traverseRight(Node* root, vector <int> &ans){      // printing the right subtree without the leaf nodes
        
        // base case
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return;
        
        if(root->right)            
            traverseRight(root->right, ans);            // going recursively for left subtree
        else
            traverseRight(root->left, ans);             // going recursively for right subtree
            
        ans.push_back(root->data);
        
    }
    
    vector <int> boundary(Node *root)
    {
        vector <int> ans;
        
        if(root == NULL)
            return ans;
            
        ans.push_back(root->data);              // pushing the root data at the starting.
            
        // left part print
        traverseLeft(root->left, ans);          // first printing left part ----> accorsing to the question
        
        // Traverse Leaf Nodes
        
        // left leaf Node
        traverseLeaf(root->left, ans);
        // right leaf node
        traverseLeaf(root->right, ans);
        
        // right part print
        traverseRight(root->right, ans);
        
        return ans;
    }
};