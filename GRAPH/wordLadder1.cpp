#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<string>wordList(N);
  for(int i=0;i<N;i++)
  {
    cin>>wordList[i];
  }
  string startWord,endWord;
  cin>>startWord>>endWord;


  unordered_set<string>st;
  queue<pair<string,int >>q;

  for(auto word:wordList){
    st.insert(word);

  }
  q.push({startWord,1});
  st.erase(startWord);

  while(!q.empty()){
    string w=q.front().first;
    int level=q.front().second;
    q.pop();
    if(w==endWord){
          cout<<level;
          return 1;
        }

    int j=0;
    while(j<w.length()){
      int ch=w[j];
      for(char i='a';i<='z';i++){
        w[j]=i;
        

        if(st.find(w)!=st.end()){
          st.erase(w);
          q.push({w,level+1});
        }
      }
      w[j]=ch;
      j++;
    }

  }



  return 0;
}