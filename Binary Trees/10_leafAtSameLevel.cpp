/*
 *
 * Question: https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// ****************************** SOLUTION - 1 (USING SET) *********************************************************

class Solution
{
public:
    /*You are required to complete this method*/
    set<int> s;
    bool check(Node *root, int l = 0)
    {
        if (root == NULL)
            return true;

        if (!root->left && !root->right)
            s.insert(l);

        check(root->left, l + 1);
        check(root->right, l + 1);

        return s.size() == 1;
    }
};

// ****************************** SOLUTION - 2 (USING NATIVE APPROACH) ***********************************************

class Solution
{
    void answer(vector<int> &ans, Node *root, int level)
    {

        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(level);
        }

        answer(ans, root->left, level + 1);
        answer(ans, root->right, level + 1);
    }

    bool check(Node *root)
    {
        vector<int> ans;
        int level = 0;

        answer(ans, root, level);

        for (int i = 0; i < ans.size() - 1; i++)
        {
            if (ans[i] != ans[i + 1])
                return false;
        }
        return true;
    }
};
