/*
*
* Question: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
*
*/

#include <bits/stdc++.h>
using namespace std;

void solve(Node* root, vector <int> &ans, int level){
    
    // base case
    if(root == NULL)
        return;
        
    if(level == ans.size())
        ans.push_back(root->data);          
        
    solve(root->left, ans, level+1);        // for left subtree with increasing level by 1 call function recursively.
    solve(root->right, ans, level+1);       // increase the level by 1 and recursively call the function for right part.
}

vector<int> leftView(Node *root)
{
   vector <int> ans;            // ans to store the ans
   solve(root, ans, 0);         // 0 denotes the level. It increases with depth of the tree.
   return ans;
}
