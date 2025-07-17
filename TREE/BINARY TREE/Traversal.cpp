#include<iostream>
using namespace std;
class TreeNode{
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

int main(){
    return 0;
}