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

class Solution{
    
    public:
    
    Node* lca(Node* root, int n1, int n2){

        if( root == NULL )
            return NULL;

        if(root->data == n1 || root->data == n2)
            return root;

        int left = lca(root->left, n1, n2);
        int right = lca(root->right, n1, n2);

        if(left != NULL && right != NULL)
            return root;

        if(left == NULL && right != NULL)
            return right;

        if(left != NULL && right == NULL)
            return left;

        else
            return NULL;
    }
}