#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 定义二叉树节点
struct TreeNode
{
    char data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char x) : data(x), left(nullptr), right(nullptr) {}
};

// 1. 根据先序序列建立二叉树
TreeNode *buildTree(const string &s, int &index)
{
    char c = s[index++];

    if (c == '0')
        return nullptr;

    TreeNode *root = new TreeNode(c);

    root->left = buildTree(s, index);
    root->right = buildTree(s, index);

    return root;
}

// 2. DFS 收集叶子和对应父节点
void dfs(TreeNode *root,
         TreeNode *parent,
         vector<pair<char, char>> &ans)
{

    if (root == nullptr)
        return;

    // 当前节点没有左右孩子，说明它是叶子
    if (root->left == nullptr && root->right == nullptr)
    {

        // 如果没有父节点，说明整棵树只有根节点
        char father = (parent == nullptr)
                          ? root->data
                          : parent->data;

        // 保存：叶子节点、父节点
        ans.push_back({root->data, father});

        return;
    }

    // 先递归左子树
    dfs(root->left, root, ans);

    // 再递归右子树
    dfs(root->right, root, ans);
}

// 3. 释放内存
void destroyTree(TreeNode *root)
{
    if (root == nullptr)
        return;

    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int index = 0;
        TreeNode *root = buildTree(s, index);

        vector<pair<char, char>> ans;

        dfs(root, nullptr, ans);

        // 第一行：输出叶子节点
        for (int i = 0; i < (int)ans.size(); i++)
        {
            if (i > 0)
                cout << ' ';
            cout << ans[i].first;
        }
        cout << '\n';

        // 第二行：输出对应父节点
        for (int i = 0; i < (int)ans.size(); i++)
        {
            if (i > 0)
                cout << ' ';
            cout << ans[i].second;
        }
        cout << '\n';

        destroyTree(root);
    }

    return 0;
}
