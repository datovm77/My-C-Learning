#include <iostream>
#include <string>

struct treenode
{
    treenode *left;
    treenode *right;
    char data;
    treenode(int data) : data(data), left(nullptr), right(nullptr) {}
};

void preorder(treenode *root)
{
    if (root == nullptr)
        return;

    std::cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

void destroyTree(treenode *root)
{
    if (root == nullptr)
        return;

    destroyTree(root->left);
    destroyTree(root->right);

    delete root;
}

void inorder(treenode *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    std::cout << root->data;
    inorder(root->right);
}

void postorder(treenode *root)
{
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    std::cout << root->data;
}

treenode *buildtree(const std::string &s, int &index)
{
    if (s[index] == '#')
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

        treenode *root;
        int index = 0;
        root = buildtree(s, index);
        preorder(root);
        std::cout << '\n';

        inorder(root);
        std::cout << '\n';

        postorder(root);
        std::cout << '\n';

        destroyTree(root);
    }

    return 0;
}