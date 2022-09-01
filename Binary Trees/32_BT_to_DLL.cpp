/*
*
* Question Description: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
*
* Approach Discussion: https://www.youtube.com/watch?v=nGNoTdav5bQ
*
*/


#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        x = data;
        left = right = NULL;
    }
};

class Solution{

    public:

    Node* prev = NULL;
    Node* head = NULL;

    void converter(Node* root){

        if( root == NULL )
            return;

        // LNR ----> inorder traversal (mentioned in question)

        // processing left subtree because inorder = LNR
        converter(root->left);

        // processing for N -> node
        if(prev == NULL)        // implies first node entry in DLL
            head = root;

        else{
            root -> left = prev;        // linking the node to the prev (back node)
            prev -> right = root;       // linking the node to the next (next node)
        }

        prev = root;                    // updating the prev node to be the current node for further processing

        // calling for right subtree because inorder = LNR . L & N has been processed.
        converter(root -> right);
    }

    Node* bToDLL(Node* root){
        converter(root);
        return head;
    }
}