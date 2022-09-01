/*
*
* Question: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
*
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

class Solution{

    int heightOfTree(Node* root){

        if(root == NULL)
            return 0;

        int leftHeight = heightOfTree(root -> left);
        int rightHeight = heightOfTree(root -> right);

        return 1 + max(leftHeight, rightHeight);
    }
}