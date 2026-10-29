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

int a[MAXN], b[MAXN];

ll solve(int x, int y) {
  return x == y ? 2 : 1;
}
 
int main() {
  helmor

  int T; cin >> T;
  while(T--) {
    int n; cin >> n;
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];

    ll fixed = solve(a[n-1], b[n-1]);
    forn(j, 0, n-1) fixed += solve(b[j], a[j+1]);

    ll cur = 0;
    forn(j, 0, n-1) cur += solve(a[j], b[j+1]);

    ll best = cur;
    forn(m, 0, n-1) {
      cur += solve(a[m], b[m]) - solve(a[m], b[m+1]);
      best = max(best, cur);
    }

    cout << (fixed + best) << endl;
  }
  return 0;
}