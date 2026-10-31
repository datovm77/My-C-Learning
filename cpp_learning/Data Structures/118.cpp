#include <iostream>
#include <string>
#include <queue>
struct treenode
{
    /* data */
    treenode *left;
    treenode *right;
    char c;
    treenode() : left(nullptr), right(nullptr), c('\0') {}
    treenode(char c) : left(nullptr), right(nullptr), c(c) {}
    ~treenode()
    {
        delete left;
        delete right;
    }
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

    treenode *newnode = new treenode(s[index++]);
    newnode->left = buildtree(s, index);
    newnode->right = buildtree(s, index);

    return newnode;
}
void levelOrder(treenode *root)
{
    if (root == nullptr)
    {
        std::cout << '\n';
        return;
    }
    std::queue<treenode *> q;
    q.push(root);

    while (!q.empty())
    {
        treenode *node = q.front();
        q.pop();

        std::cout << node->c;

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    std::cout << '\n';
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
        levelOrder(root);
        delete root;
    }
    return 0;
}