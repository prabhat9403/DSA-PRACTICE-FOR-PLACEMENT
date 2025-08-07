#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<string>wordList(N);
  vector<vector<string>>seq;

  for(int i=0;i<N;i++)
  {
    cin>>wordList[i];
  }
  string startWord,endWord;
  cin>>startWord>>endWord;


  unordered_set<string>st;
  queue<vector<string>>q;

  for(auto word:wordList){
    st.insert(word);
  }
  q.push(startWord);
  st.erase(startWord);

  while(!q.empty()){
    string w=q.front();
   
    q.pop();
    
    int j=0;
    while(j<w.length()){
      vector<string>temp;
      int ch=w[j];
      for(char i='a';i<='z';i++){
        w[j]=i;
        
        if(w==endWord){
          seq.push_back(temp);
          return 1;
        }

        if(st.find(w)!=st.end()){
          st.erase(w);
          temp.push_back(w);

          q.push({w,level+1});
        }
      }

      w[j]=ch;
      j++;
    }

  }



  return 0;
}