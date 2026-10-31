#include <iostream>
#include <string>
#include <vector>
struct treenode
{
    treenode *left;
    treenode *right;
    char data;
    treenode(char data) : data(data), left(nullptr), right(nullptr) {}
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

void counttree(treenode *root,
               std::vector<char> &father,
               std::vector<char> &son)
{
    if (root == nullptr)
        return;

    // ① 先判断左孩子是不是叶子
    if (root->left != nullptr &&
        root->left->left == nullptr &&
        root->left->right == nullptr)
    {
        son.push_back(root->left->data);
        father.push_back(root->data);
    }

    // ② 递归访问左子树
    counttree(root->left, father, son);

    // ③ 再判断右孩子是不是叶子
    if (root->right != nullptr &&
        root->right->left == nullptr &&
        root->right->right == nullptr)
    {
        son.push_back(root->right->data);
        father.push_back(root->data);
    }

    // ④ 递归访问右子树
    counttree(root->right, father, son);
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
        std::vector<char> son;
        std::vector<char> father;
        treenode *root = buildtree(s, index);
        counttree(root, father, son);
        if (root != nullptr &&
            root->left == nullptr &&
            root->right == nullptr)
        {
            son.push_back(root->data);
            father.push_back(root->data);
        }
        for (char c : son)
        {
            std::cout << c << ' ';
        }
        std::cout << '\n';

        for (char c : father)
        {
            std::cout << c << ' ';
        }
        std::cout << '\n';
        destroyTree(root);
    }

    return 0;
}