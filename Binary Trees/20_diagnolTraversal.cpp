/*
*
* Question: https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
*
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};


vector<int> diagonal(Node *root)
{
    if(root == NULL){
        return {};
   }
   
    vector <int> ans;           // ans to store the diagnol traversal
    queue<Node *> q;            // queue to store the left elements
    q.push(root);               // pushing root to the queue.
   
    while(!q.empty()){          
       
        Node* node = q.front();             // get the front element
        q.pop();                            // pop that element from the queue
        while(node){    
            ans.push_back(node->data);      // push that element to the answer vector
            if(node->left)                  // if any left children of that node, push it to the queue for future.
                q.push(node->left);         // left part means that it will be traversed after right is done.
            
            node = node->right;             // make node as right node till the node becomes NULL.
       }
   }
   return ans;          // RETURN THE VECTOR.
}