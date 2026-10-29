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
    int n, k; cin >> n >> k;

    ll sum_tot = 0;
    forn(i, 1, n+1) {
      cin >> a[i];
      sum_tot += a[i];
    }
    
    ll rest = 0;
    forn(i, 1, k) {
      int j = n + 1 - i;
      if (j > k - 1) rest += min(a[i], a[j]);
      else rest += a[i];
    }

    cout << sum_tot - rest << endl;
  }
  return 0;
}