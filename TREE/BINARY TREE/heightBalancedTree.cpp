#include <iostream>
#include <vector>
#include <stack>
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
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);
}
bool isBalanced(TreeNode *root)
{
    if (root == nullptr)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
        return true;
    }
    return false;
}

int main()
{
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->left->right->right = new TreeNode(6);
    root1->left->right->right->right = new TreeNode(7);
   
    isBalanced(root1)==1?cout<<"Tree is Balanced":cout<<"Tree isnot Balanced";

    return 0;
}