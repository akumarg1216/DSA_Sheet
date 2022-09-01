/*
*
* Question: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
*
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

/********************************************* SOLUTION - 1 *****************************************************/

/* The below solution - solution 1 has a time complexity of O(n^2) since the diameter function also calls the height function and hence the time complexity is not optimized. The optimized approach is in solution - 2. */

class Solution{

    int height(Node* root){

        if( root == NULL )
            return 0;

        int leftHeight = height(root->left);        // height of left subtree
        int rightHeight = height(root->right);      // height of right subtree

        return max(leftHeight, rightHeight) + 1         // adding 1 because of the root node.
    }

    int diameter(Node* root){

        if( root == NULL )
            return 0;

        int op1 = diameter(root->left);         // suppose the diameter is only for the left subtree
        int op2 = diameter(root->right);        // suppose the diameter is only for the right subtree
        int op3 = height(root->left) + 1 + height(root->right);     // diameter is both from left & right subtree.

        int ans = max(op1, max(op2, op3));
        return ans;
    }
};

/********************************************* SOLUTION - 2 *****************************************************/

/* The below solution - solution 2 has a time complexity of O(n) since the diameterFast function returns a pair from each node that consists of both the diameter and the height of the node till that point. So there is no need to call the height function specifically, thereby optimizing our code to O(n) from O(n^2). */

class Solution{

    pair<int, int> diameterFast(Node* root){

        if( root == NULL ){
            pair <int, int> p = make_pair(0, 0);        // pair <int, int > = pair<diameter, height> which is 0 in root.
            return p;
        }

        pair <int, int> left = diameterFast(root->left);    // gets the diameter & height pair for left subtree.
        pair <int, int> right = diameterFast(root->right);  // gets the diameter & height pair for right subtree.

        int op1 = left.first;                             // diameter of the left subtree
        int op2 = right.first                            // first stores the diameter, hence diameter of right subtree.
        int op3 = left.second + right.second  + 1       // height of left & right subtree + 1 (for root)

        pair <int, int> ans;

        ans.first = max(op1, max(op2, op3));  // first stores the diameter, and this is the formula for diameter 
        ans.second = max(left.second + right.second) +1  // second stores the height, and formula for height of tree.

        return ans;
    }

    int diameter(Node* root){

        return diameterFast(root).first;
    }
};

/**********************************************************************************************************************/
