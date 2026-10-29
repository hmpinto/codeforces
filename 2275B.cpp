#include <bits/stdc++.h>
using namespace std;
 
#define helmor cin.tie(nullptr); cout.tie(NULL); cin.sync_with_stdio(false);
 
#define ll long long
#define pii pair<int,int>
#define mii map<int,int>
#define vint vector<int>
#define forn(_i,_j,_k) for(int _i = _j; _i <  _k; _i++)
#define forr(_i,_j,_k) for(int _i = _j; _i >= _k; _i--)
 
const int MAXN = 2e5+10;

// int a[MAXN];

int solve(int value) {
  return 0;
}
 
int main() {
  helmor
  int T; cin >> T;
  while(T--) {
    int n; cin >> n;
    string s; cin >> s;
    
    set<int> docs;
    forn(i, 0, n) docs.insert(i+1);
    
    stack<int> mem;
    forn(i, 0, n) {
      if(s[i] == '1') mem.push(i+1);

      if(s[i] == '2') {
        int doc_to_remove = (!mem.empty()) ? mem.top() : i+1;
        docs.erase(doc_to_remove);
        if(!mem.empty()) mem.pop();
      }

      if(s[i] == '3') docs.erase(i+1);
    }
    
    cout << docs.size() << endl;
    // if(docs.size() == 0) cout << endl;
    for(int doc : docs) cout << doc << " ";
    cout << endl;
  }
  return 0;
}