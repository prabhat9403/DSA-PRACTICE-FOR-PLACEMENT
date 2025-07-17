#include<iostream>
#include<vector>
#include<stack>
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
void preOrder(TreeNode*root){
    if(root==nullptr)return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void preorder(TreeNode*root){
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode*r=st.top();
        st.pop();
        cout<<r->data<<" ";
        if(r->right!=nullptr){
            st.push(r->right);
        }
        if(r->left!=nullptr){
            st.push(r->left);
        }
    }
}
int main(){
       TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    preorder(root);
    return 0;
}