/*
*
* Question: https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
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
    
    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);

}
    

vector<int> leftView(Node *root)
{
   vector <int> ans;
   solve(root, ans, 0);
   return ans;
}
