/*
*
* Question: https://leetcode.com/problems/maximum-depth-of-binary-tree/
*
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

// using BFS ---> Time Complexity: O(n) ----> Space Complexity: O(n)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int maxDepthLeft = maxDepth(root->left);     // max depth of the left subtree
        int maxDepthRight = maxDepth(root->right);   // max depth of the right subtree
        
        return max(maxDepthRight, maxDepthLeft) + 1;  // getting the max of left & right and adding 1 for the root.
    }
};

// using DFS ---> Time Complexity: O(n) ----> Space Complexity: O(nlogn)

class Solution {
public:

    int maxDepth(TreeNode* root) {
           
           queue <TreeNode* > q;                // queue to store the elements
           int res = 0;                         // counter for the depth
           
           if(root == NULL)
               return 0;
           
           q.push(root);                        // pushing root into queue
           
           
           while(!q.empty()){
               ++res;
               
               int n = q.size();    
               
               for(int i = 0; i < n; ++i){          
                   TreeNode* p = q.front();         // extract element to find it's left & right children
                   q.pop();
                   
                   if(p->left != NULL)              // push the left child if any exists
                       q.push(p->left);

                   if(p->right != NULL)         // push the right child
                       q.push(p->right);
               }
           }
           
           return res;      // return the depth counter
       }
    
};
