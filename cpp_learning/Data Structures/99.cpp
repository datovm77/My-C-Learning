#include <iostream>
#include <string>

struct treenode
{
    treenode *left;
    treenode *right;
    char data;
    treenode(int data) : data(data), left(nullptr), right(nullptr) {}
};

void destroyTree(treenode *root)
{
    if (root == nullptr)
        return;

    destroyTree(root->left);
    destroyTree(root->right);

    delete root;
}

treenode *buildtree(const std::string &s, int &index)
{
    if (s[index] == '0')
    {
        index++;
        return nullptr;
    }

    treenode *root = new treenode(s[index]);
    index++;
    root->left = buildtree(s, index);
    root->right = buildtree(s, index);

    return root;
}

int countl(treenode *root)
{
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;
    return countl(root->left) + countl(root->right);
}

int main()
{
    std::ios::sync_with_stdio(0);
    int t;
    if (!(std::cin >> t))
        return 0;

    while (t--)
    {
        std::string s;
        std::cin >> s;
        int index = 0;
        treenode *root = buildtree(s, index);
        int count = countl(root);
        std::cout << count << '\n';
    }

    return 0;
}