/*
*
* Question: https://leetcode.com/problems/binary-tree-level-order-traversal/
*
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int> > ans;       // vector <vector> to return ans
        queue <TreeNode* > q;           
        
        if (root == NULL)
            return {};
        
        q.push(root);
        
        while(!q.empty()){
             
            int n = q.size();
            vector <int> v;             // temp vector to store in ans after each level traversal.
            
            for(int i = 0; i < n; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                v.push_back(temp->val);         // push the value of front item.
                
                if(temp->left)              
                    q.push(temp->left);         // push the left tree value into the queue
                
                if(temp->right) 
                    q.push(temp->right);        // push the right subtree value node into the queue
            }
            
            ans.push_back(v);                   // return the actual vector of vectors.
        }
        
        return ans;
    }
};