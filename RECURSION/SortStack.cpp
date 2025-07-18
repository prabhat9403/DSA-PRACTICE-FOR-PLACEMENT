#include<bits/stdc++.h>
using namespace std;
void sortedInsert(stack<int>&s,int el){
    if(s.empty()||(!s.empty()&&s.top()<el)){
        s.push(el);
        return;
    }
    int tp=s.top();
    s.pop();
    sortedInsert(s,el);
    s.push(tp);
}
void sortStack(stack<int>&s){
    if(s.empty())return;
    int topEle=s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s,topEle);
}
void printStack(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main(){
    stack<int>s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        s.push(k);
    }
    printStack(s);
    sortStack(s);
    printStack(s);
    return 0;
}