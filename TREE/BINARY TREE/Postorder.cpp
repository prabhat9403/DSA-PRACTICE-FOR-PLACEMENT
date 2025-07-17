#include<iostream>
#include<stack>;
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
void postOrder(TreeNode*root){
    if(root==nullptr)return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data;
}
void postorder(TreeNode*root){
    stack<TreeNode*>st;
    TreeNode*curr=root;

    while(curr!=nullptr||st.empty()==false){

        while(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        curr=curr->right;
        if(curr==nullptr){
            st.pop();
        }
    
        // cout<<curr->data<<" ";
       
    }
}
int main(){
    return 0;
}