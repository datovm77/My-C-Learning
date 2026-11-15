// P1305 新二叉树
#include <iostream>
#include <string>
#include <unordered_map>
struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char d) : val(d), left(nullptr), right(nullptr) {}
};

// 根据字符返回TreeNode节点
TreeNode *getNode(std::unordered_map<char, TreeNode *> &mp, char c)
{
    if (!mp.count(c))
    {
        mp[c] = new TreeNode(c);
    }
    return mp[c];
}
void preorder(TreeNode *root)
{
    if (!root)
        return;
    std::cout << root->val;
    preorder(root->left);
    preorder(root->right);
}

void destroy(TreeNode *root)
{
    if (!root)
        return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

int main()
{
    int n;
    if (!(std::cin >> n))
        return 0;
    std::unordered_map<char, TreeNode *> mp;
    TreeNode *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        char v = s[0];
        char l = s[1];
        char r = s[2];

        TreeNode *cur = getNode(mp, v);
        if (i == 0)
            root = cur;
        if (l != '*')
            cur->left = getNode(mp, l);
        if (r != '*')
            cur->right = getNode(mp, r);
    }
    preorder(root);
    std::cout << '\n';
    destroy(root);
    return 0;
}