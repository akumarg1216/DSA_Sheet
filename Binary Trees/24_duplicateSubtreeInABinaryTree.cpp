/*
*
* Question: https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1
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

class Solution {
  
  private:
  
    unordered_map <string, int> mp;
    
    string solve(Node* root){
        if(root == NULL)
            return "$";
            
        string s = "";
        if(root->left == NULL && root->right == NULL){
            s = to_string(root->data);
            return s;
        }
        
        s+= to_string(root->data);
        s+= "_";
        s+= solve(root->left);
        s+= solve(root->right);
        mp[s]++;
        return s;
    }
    
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
        mp.clear();
        solve(root);
         
        for(auto i: mp){
         if(i.second >= 2)
            return 1;
        }
        
        return 0;
         
    }
};