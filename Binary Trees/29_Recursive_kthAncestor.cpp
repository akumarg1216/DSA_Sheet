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


Node* solve(Node* root, int &k, int node){

    if( root == NULL )                      // base case
        return NULL;

    if(root->data == node)                  // if root itself is the node
        return root;

    Node* leftAns = solve(root->left, k, node);         // for left children of each node
    Node* rightAns = solve(root->right, k, node);       // for right children of each node

    if(leftAns != NULL && rightAns == NULL){            // if node matches in left part of a node then leftAns != NULL.
        k--;                                            // decrement k till it reaches 0 => the ancestral node
        if(k <= 0){
            k = INT_MAX;                                // locking answer
            return root;                        
        }       
        return leftAns;                                 // returning leftAns since right is NULL and leftAns has answer.
    }

    if(rightAns != NULL && leftAns == NULL){            // if node matches in left part of a node then leftAns != NULL.
        k--;                                           // decrement k till it reaches 0 => the ancestral node
        if(k <= 0){
            k = INT_MAX;
            return root;                               // locking answer
        }
        return rightAns;                             // returning rightAns since left is NULL and rightAns has answer.
    }

    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);

    if(ans == NULL || ans->data == node)            // if ans == NULL implies the node is not found or the ancestor required is greater than in the tree. ans->data == node implies that suppose for root node the required ancestor is any number but that is not in tree. So ancestor of root always returns -1.
        return -1;

    else
        return ans->data
}