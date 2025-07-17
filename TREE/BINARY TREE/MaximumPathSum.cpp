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
int findSum(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return root->data + max(findSum(root->left), findSum(root->right));
}
int maximumPathSum(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int ls = findSum(root->left);
    int rs = findSum(root->right);

    return max({ls+rs+root->data,maximumPathSum(root->left),maximumPathSum(root->right)});
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

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    
    
    cout << "Maximum path sum  Of the Tree is : "<<maximumPathSum(root);
    return 0;
}