#include <iostream>
#include <string>
#include <algorithm>
struct treenode
{
    /* data */
    treenode *left;
    treenode *right;
    char c;
    treenode() : left(nullptr), right(nullptr) {}
    treenode(char c) : left(nullptr), right(nullptr), c(c) {}
};

treenode *buildtree(std::string &s, int &index)
{
    if (index >= static_cast<int>(s.size()))
        return nullptr;
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
int treehight(treenode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + std::max(treehight(root->left), treehight(root->right));
}
int main()
{
    int t;
    if (!(std::cin >> t))
        return 0;

    while (t--)
    {
        std::string s;
        std::cin >> s;
        int index = 0;
        treenode *root = buildtree(s, index);
        int high = treehight(root);
        std::cout << high << '\n';
    }
}