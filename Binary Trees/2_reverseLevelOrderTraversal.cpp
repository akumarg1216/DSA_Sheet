/*
*
* Question: https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1
* 
* Queue has special property where you can push from one end and pop from another end. Like in level order traversal we * mark nodes visited and pop them, From other end we push the elements to be mark visited, This is what level order 
* traversal does.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};


vector<int> reverseLevelOrder(Node *root)
{
    if(root == NULL)
        return {};
        
    vector <int> ans;       // return type of fn is vector
    queue <Node* > q;       
    q.push(root);
    
    while(!q.empty()){
        
        Node* temp = q.front();  // finding front element
        q.pop();
        
        ans.push_back(temp->data);      // pushing the data of the front element
        
        if(temp->right != NULL)         // pushing the data of front's right child
            q.push(temp->right);
            
        if(temp->left != NULL)          // pushing the data of front's left child
            q.push(temp->left);
            
        // right is pushed first because we want the reverse of the push.
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
    
}