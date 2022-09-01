#include <bits/stdc++.h>
using namespace std;

// binary tree Node
struct Node{
    int data;
    Node* left, *right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


// function to print the vector
void printVector(const vector<int>&v, int i){

    for(int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}


// function to print the path summing to K
void printPathUtil(Node* root, vector <int>&path, int k){

    if( root == NULL )
        return;

    path.push_back(root->data);              // add current node to the path

    printPathUtil(root->left, path, k);         // check for K sum path in the left subtree
    printPathUtil(root->right, path, k);        // check for K sum path in the right subtree

    int sum = 0;
    for(int j = path.size()-1; j >= 0; j--){        // check for any K sum path that terminates at this node
        sum += path[j];                            

        if(sum == k)                                // if sum == K
            printVector(path, j);                   // print the path
    }

    path.pop_back();                            // remove the current element from the path
}

void printKPath(Node* root, int k){             // wrapper class for pathUtil function
    vector <int> path;
    printPathUtil(root, path, k);
}

// Driver code
int main()
{
	Node* root = new Node(1);
	root->left = new Node(3);
	root->left->left = new Node(2);
	root->left->right = new Node(1);
	root->left->right->left = new Node(1);
	root->right = new Node(-1);
	root->right->left = new Node(4);
	root->right->left->left = new Node(1);
	root->right->left->right = new Node(2);
	root->right->right = new Node(5);
	root->right->right->right = new Node(2);

	int k = 5;
	printKPath(root, k);

	return 0;
}


