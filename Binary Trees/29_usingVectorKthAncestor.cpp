/*
*
* Question: https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
*
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

int nodeToRoot(Node* root, int node , int k, int &ans){
    if( root == NULL )
        return 0;
        
    if(root->data == node)
        return 1;
        
    int l = nodeToRoot(root->left, node, k, ans);
    int r = nodeToRoot(root->right, node, k, ans);
    
    if(l == k || r == k)
        ans = root->data;
        
    if(l) return l+1;
    if(r) return r+1;
    else  return 0;
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    nodeToRoot(root, node, k, ans);
    return ans;
}