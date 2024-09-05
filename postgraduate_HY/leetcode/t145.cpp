// https://leetcode.cn/problems/binary-tree-postorder-traversal/description/
//  后序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void backtrace(TreeNode *root ,vector<int>&vec){
        if(root==nullptr)return ;
        backtrace(root->left,vec);
        backtrace(root->right,vec);
        vec.push_back(root->val);

    }

    void printVec(std::vector<int> &nums)
    {
        cout<<"数组所有元素为:\n";
        for (auto x : nums)
            printf("%d  ", x);
        cout << endl;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>vec;
        backtrace(root,vec);
        printVec(vec);
        return vec;
    }
};
