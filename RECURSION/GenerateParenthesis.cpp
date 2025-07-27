#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void generate(int n, string s, unordered_set<string> &st)
{
  if (n % 2 != 0)
    return;
  if (n == s.length())
  {
    st.insert(s);
    return;
  }
  generate(n, s + "()", st);
  generate(n, "(" + s + ")", st);
}
int main()
{
  int n;
  cin >> n;
  unordered_set<string> st;
  auto start = high_resolution_clock::now();

  generate(n, "", st);
  for (string s : st)
  {
    cout << s << " , ";
  }

  auto end = high_resolution_clock::now();

  auto duration = duration_cast<milliseconds>(end - start);
  cout << "Runtime: " << duration.count() << " ms" << endl;

  return 0;
}