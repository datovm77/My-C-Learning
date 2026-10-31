#include <iostream>
#include <queue>
#include <vector>

struct nodetree
{
    int val;
    nodetree *left;
    nodetree *right;

    nodetree(int data) : val(data), left(nullptr), right(nullptr) {}
};

nodetree *buildtree(const std::vector<int> &v)
{
    if (v.empty() || v[0] == -1)
    {
        return nullptr;
    }
    nodetree *root = new nodetree(v[0]);
    std::queue<nodetree *> q;
    q.push(root);
    int index = 1;
    while (!q.empty() && index < static_cast<int>(v.size()))
    {
        nodetree *current = q.front();
        q.pop();

        if (v[index] != -1)
        {
            current->left = new nodetree(v[index]);
            q.push(current->left);
        }
        index++;

        if (index < static_cast<int>(v.size()))
        {
            if (v[index] != -1)
            {
                current->right = new nodetree(v[index]);
                q.push(current->right);
            }
            index++;
        }
    }

    return root;
}

void preorder(nodetree *root)
{
    if (!root)
        return;
    std::cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(nodetree *root)
{
    if (!root)
        return;
    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}

void postorder(nodetree *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->val << " ";
}

int main()
{
    int t;
    if (!(std::cin >> t))
        return 0;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int number;
            std::cin >> number;
            v.push_back(number);
        }
        nodetree *root = buildtree(v);
        preorder(root);
        std::cout << '\n';
        inorder(root);
        std::cout << '\n';
        postorder(root);
        std::cout << '\n';
    }
}