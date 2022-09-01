/*
*
* Question: https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
*
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	bool leftToRight = true;
    	vector <int> result;
    	queue <Node* > q;
    	
    	if(root == NULL)
    	    return result;
    	    
    	q.push(root);
    	
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int> ans(size);
    	    
    	    // level order processing
    	    for(int i = 0; i < size; i++){
    	        Node* temp = q.front();
    	        q.pop();
    	        
    	        // check for L to R insertion or R to L insertion
    	        int index = leftToRight? i : size-i-1;
    	        ans[index] = temp->data;
    	        
    	        if(temp->left)
    	            q.push(temp->left);
    	            
    	        if(temp->right)
    	            q.push(temp->right);
    	    }
    	    
    	    leftToRight = !leftToRight;
    	    
    	    for(auto i: ans)
    	        result.push_back(i);
    	    
    	}
    }
};