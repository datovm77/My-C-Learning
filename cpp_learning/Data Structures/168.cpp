// P1030 [NOIP 2001 普及组] 求先序排列
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

std::string mid_tree;
std::string post_tree;
std::unordered_map<char, int> mid_tree_map;

struct treenode
{
    /* data */
    char data;
    treenode *left = nullptr;
    treenode *right = nullptr;
    treenode(int data) : data(data) {};
};

treenode *buildtree(int postStart, int postEnd, int inStart, int inEnd)
{
    if (postStart > postEnd || inStart > inEnd)
        return nullptr;
    // 根节点
    treenode *root = new treenode(post_tree[postEnd]);

    // 在中序遍历中的根节点的下标
    int rootindexinorder = mid_tree_map[post_tree[postEnd]];

    int left_size = rootindexinorder - inStart;

    root->left = buildtree(postStart, postStart + left_size - 1, inStart, inStart + left_size - 1);
    root->right = buildtree(postStart + left_size, postEnd - 1, rootindexinorder + 1, inEnd);

    return root;
}
void preorderRecursive(treenode *root)
{
    if (!root)
        return;
    std::cout << root->data;        // 根
    preorderRecursive(root->left);  // 左
    preorderRecursive(root->right); // 右
}
void build_map(std::string mid_tree)
{
    int size = (int)mid_tree.size();
    for (int i = 0; i < size; i++)
    {
        mid_tree_map[mid_tree[i]] = i;
    }
}

int main()
{
    std::cin >> mid_tree;
    std::cin >> post_tree;
    build_map(mid_tree);
    treenode *root = buildtree(0, (int)post_tree.size() - 1, 0, mid_tree.size() - 1);
    preorderRecursive(root);
}