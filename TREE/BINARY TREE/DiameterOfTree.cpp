#include <iostream>
#include <algorithm>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int val = 0)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
int diameter(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    return max({lh+rh,diameter(root->left),diameter(root->right)});
}

int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->left->right->right = new TreeNode(6);
    root1->left->right->right->right = new TreeNode(7);

    TreeNode *root2 = new TreeNode(5);
    root2->left = new TreeNode(8);
    root2->right = new TreeNode(6);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(9);

    
    diameter(root2);
    cout << "Diameter Of the Tree is : "<<diameter(root2);
    return 0;
}