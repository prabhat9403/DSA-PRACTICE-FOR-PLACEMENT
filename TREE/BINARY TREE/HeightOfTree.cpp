#include<iostream>
using namespace std;
class TreeNode{
public:
    int data;
    TreeNode*left;
    TreeNode*right;

    TreeNode(){
        data=0;
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int val=0){
        data=val;
        left=nullptr;
        right=nullptr;
    }

};

int height(TreeNode*root){
    if(root==nullptr)return 0;
    return 1+max(height(root->left),height(root->right));
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    cout<<"height of tree : "<<height(root)<<endl;


    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->left->right->right = new TreeNode(6);
    root1->left->right->right->right = new TreeNode(7);
    cout<<"height of tree : "<<height(root1);
    return 0;
}