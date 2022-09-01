/*
 *
 * Question: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node* newNode(int data){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void preOrder(Node *root)           // testing function
{

    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int findIndex(string str, int si, int ei)   // function to return the index of closed parenthesis
{

    if (si > ei)
        return -1;

    stack<char> s;              // stack

    for (int i = si; i <= ei; i++)
    {
        if (str[i] == '(')              // push open parenthesis in the stack
            s.push(str[i]);

        else if (str[i] == ')')         // if closed parenthesis
        {
            if (s.top() == '(')         // check if stack contains the following open parenthesis
            {
                s.pop();

                if (s.empty())          // if stack is empty, then this is the required index
                    return i;
            }
        }
    }

    return -1;              // denotes that index not found
}

Node* treeFromString(string str, int si, int ei){           // fn to constuct tree from string

    // base case
    if(si > ei)
        return NULL;
    
    Node* root = newNode(str[si] - '0');            // new root
    int index = -1;

    if(si+1 <= ei && str[si+1] == '(')              // if next char is '(' find the index of its complement ')'
        index = findIndex(str, si+1, ei);

    if(index != -1){                        // if index found
        root->left = treeFromString(str, si+2, index-1);        // call for left subtree
        root->right = treeFromString(str, index+2, ei-1);       // call for right subtree
    }
    return root;
}


// Driver code

int main(){
    string str = "4(2(3)(1))(6(5))";
    Node* root = treeFromString(str, 0, str.length()-1);
    preOrder(root);
}