/*
*
* Question: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
*
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector <int> ans;               // vector to store the answer
        map <int, int> topNode;         // map to store the horizontal distance and their corresponding element
        
        if(root == NULL)
            return ans;
            
        queue <pair<Node* , int> > q;       // make pair to get the Node with their hoizontal distance
        q.push(make_pair(root, 0));         // first push root with hoizontal distance as 0.
        
        while(!q.empty()){
            
            pair<Node* ,int> temp = q.front();      // take a node 
            q.pop();                                // remove the taken node
            
            Node* frontNode = temp.first;           // see the data of the Node
            int hd = temp.second;                   // see the hoizontal distance of the node
            
            if(topNode.find(hd) == topNode.end())       // check if the distance is present, then do nothing
                topNode[hd] = frontNode -> data;        // else add the new node and its hoizontal distance
                
            if(frontNode -> left)                           // check for left subtree
                q.push(make_pair(frontNode->left, hd-1));   // hd-1 since left hoizontal distance always < 0 (root)
            if(frontNode -> right)
                q.push(make_pair(frontNode->right, hd+1));  // hd+1 since right hoizontal distance > 0 (root)
                
        }
        
        for(auto i : topNode)                   // iterating through the map
            ans.push_back(i.second);            // pushing the pair's second value to the vector.
            
        return ans;                     // returning the vector.
    }
    
    

};
