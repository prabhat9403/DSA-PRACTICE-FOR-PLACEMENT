#include<iostream>
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
void inOrder(TreeNode*root){

    if(root==nullptr)return;
    inOrder(root->left);
    cout<<root->data;
    inOrder(root->right);
}
void inorder(TreeNode*root){
    stack<TreeNode*>st;
    TreeNode*curr=root;

    while(curr!=nullptr||st.empty()==false){

        while(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
       
    }
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    inorder(root);
    return 0;
}