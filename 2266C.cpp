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

int a[MAXN];

int solve(int value) {
  return 0;
}
 
int main() {
  helmor

  int T; cin >> T;
  while(T--) {
    int n; cin >> n;
    string s; cin >> s;

    int zeros = count(s.begin(), s.end(), '0');

    if (s[0] == '1') {
      cout << zeros << '\n';
      continue;
    }

    // k = 0: nenhum prefixo, todos os zeros estão no sufixo
    int onesPrefix = 0, zerosSuffix = zeros;
    int best = zerosSuffix;

    forn(k, 1, n+1) {
      if (s[k - 1] == '1') onesPrefix++;
      else zerosSuffix--;
      best = min(best, onesPrefix + zerosSuffix);
    }
    
    cout << best << endl;
  }
  return 0;
}