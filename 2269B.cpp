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

int solve(ll x) {
  int s = 0;
  while (x > 0) {
    int d = x % 10;
    s += d * d;
    x /= 10;
  }
  return s;
}
 
int main() {
  helmor

  int T; cin >> T;
  while(T--) {
    int n; cin >> n;
    
    map<ll, ll> cnt;
    forn(i, 0, n) {
      ll ai; cin >> ai;
      forn(k, 0, 1000) ai = solve(ai);
      cnt[ai]++;
    }
    ll ans = 0;
    for (auto& [v, c] : cnt) ans += c * (c - 1) / 2;
    cout << ans << endl;
  }
  return 0;
}