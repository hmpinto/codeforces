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

ll a[MAXN], b[MAXN], c[MAXN];

int solve(ll S, ll k, int n) {
  ll total = 0;
  forn(i, 0, n) {
    ll d = S - (a[i] + b[i] + c[i]);
    if(d <= 0) continue;
    if(a[i] > b[i] || a[i] > c[i] || b[i] > c[i]) total += d;
    else if(a[i] == c[i]) return false;
    else total += d + 2 * (min(b[i] - a[i], c[i] - b[i]) + 1);
    if(total > k) return false;
  }
  return true;
}
 
int main() {
  helmor

  int T; cin >> T;
  while(T--) {
    int n; ll k; cin >> n >> k;

    ll min_soma = LLONG_MAX;
    forn(i, 0, n) {
      cin >> a[i] >> b[i] >> c[i];
      min_soma = min(min_soma, a[i] + b[i] + c[i]);
    }
    
    ll lo = min_soma, hi = min_soma + k;
    while(lo < hi) {
      ll mid = lo + (hi - lo + 1) / 2;
      if(solve(mid, k, n)) lo = mid; else hi = mid - 1;
    }
    cout << lo << endl;
  }
  return 0;
}