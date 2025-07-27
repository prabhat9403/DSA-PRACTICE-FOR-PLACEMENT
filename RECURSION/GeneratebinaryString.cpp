#include<bits/stdc++.h>
using namespace std;
void print(int n,string s){
  if(s.length()==n){
    cout<<s<<" ";
    return;
  }
  print(n,s+'0');
  print(n,s+'1');

}
int main(){
  int n;
  cin>>n;
  cout<<"[";
  print(n,"");
  cout<<"]";
  
  return 0;
}