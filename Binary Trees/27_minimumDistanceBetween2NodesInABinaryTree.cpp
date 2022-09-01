/*
*
* Question: https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
*
* Approach: To find the LCA (Lowest Common Ancestor)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    
    Node* solve(Node* root, int n1, int n2){
        
        // base case
        if( root == NULL )
            return NULL;
            
        if(root -> data == n1 || root -> data == n2){
            return root;        // suppose root is n1 or n2
        }
        
        Node* left = solve(root -> left, n1, n2);   // for left subtree
        Node* right = solve(root -> right, n1, n2); // for right subtree
        
        if(left != NULL && right == NULL)  // if left != NULL implies n1 is found in left.
            return left;                  // of the node, hence return left
        
        if(left == NULL && right != NULL) // if right!= NULL implies n1 is found in right.
            return right;               //// of the node, hence return right
            
        if(left == NULL && right == NULL)  // both NULL means n1 & n2 not found either
            return NULL;                   // in left or right of node. Hence return NULL.
            
        else
            return root;        // else return the root
    }
    
    int height(Node* root, int val){ // height to get the depth of left & right subtree.
        if(root == NULL)
            return 0;
            
        if(root -> data == val)
            return 1;
            
        int left = height(root->left, val); // left tree height recursively
        int right = height(root->right, val); // right subtree height recursively
        
        if(left == 0 && right == 0)     
            return 0;
        else
            return max(left, right) + 1;    // +1 to add the root node.
    }
    
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        Node* lca = solve(root, a, b);      // finding lowest common ancestor.
        int l = height(lca, a);
        int r = height(lca, b);
        
        return l + r - 2;
    }
};