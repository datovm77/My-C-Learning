#include <iostream>
#include <string>
using namespace std;

struct TreeNode
{
    char data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char d) : data(d), left(nullptr), right(nullptr) {}
};

// pre: 先序序列, in: 中序序列
TreeNode *buildTree(string pre, string in)
{
    if (pre.empty())
        return nullptr;

    // 1. 先序第一个字符就是根
    char rootVal = pre[0];
    TreeNode *root = new TreeNode(rootVal);

    // 2. 在中序中找到根的位置
    int rootPos = in.find(rootVal);

    // 3. 分割出左子树和右子树的先序、中序
    string leftIn = in.substr(0, rootPos);           // 左子树的中序
    string rightIn = in.substr(rootPos + 1);         // 右子树的中序
    string leftPre = pre.substr(1, leftIn.size());   // 左子树的先序
    string rightPre = pre.substr(1 + leftIn.size()); // 右子树的先序

    // 4. 递归构建
    root->left = buildTree(leftPre, leftIn);
    root->right = buildTree(rightPre, rightIn);

    return root;
}

// 验证：后序遍历输出
void postorder(TreeNode *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main()
{
    string preorder = "ABDEGHCF";
    string inorder = "DBGEHACF";

    TreeNode *root = buildTree(preorder, inorder);

    cout << "恢复后的后序遍历: ";
    postorder(root);
    cout << endl;
    // 应输出: DGHEBFCA

    return 0;
}