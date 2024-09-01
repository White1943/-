#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
// 定义树的节点结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 迭代 非递归 后序遍历
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    if (root == NULL) return result;

    stack<TreeNode *> st;
    st.push(root);
    stack<TreeNode *>output;

    while (!st.empty()) {
        TreeNode *node = st.top();
        st.pop();
        output.push(node);

        if (node->left != NULL) {
            st.push(node->left);
        }

        if (node->right != NULL) {
            st.push(node->right);
        }
    }

    while (!output.empty()) {
        TreeNode *node = output.top();
        output.pop();
        result.push_back(node->val);
    }

    return result;
}
vector<int> downToTopWithRL(TreeNode *root) {//从下到上,右到左的层次遍历
    queue<TreeNode *>t;
    stack<TreeNode *>res;
    if(root)t.push(root);
    while(!t.empty()){
        int len=t.size();
        while(len--){
            res.push(t.front());TreeNode *temp=t.front();t.pop();
            if(temp->left)t.push(temp->left);
            if(temp->right)t.push(temp->right);
        }
       

    }
    cout<<"二叉树从小到上且从右到左遍历\n";
    while(res.empty()==false){
        cout<<res.top()->val<<" ";res.pop();
    }

}
// 创建新节点
TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    return node;
}

// 主函数
int main() {
    TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    //  1
    //2  3
 // 4 5 6 7
    downToTopWithRL(root);
    vector<int> result = postorderTraversal(root);
    cout << "后序遍历: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}