#include <bits/stdc++.h>
using namespace std;
 
#define helmor cin.tie(nullptr); cout.tie(NULL); cin.sync_with_stdio(false);
 
#define ll long long
#define pii pair<int,int>
#define mii map<int,int>
#define vint vector<int>
#define forn(_i,_j,_k) for(int _i = _j; _i <  _k; _i++)
#define forr(_i,_j,_k) for(int _i = _j; _i >= _k; _i--)
 
const int MAXN = 1e6+100;

int spf[MAXN];
int cnt[MAXN];

int solve(int value) {
  return 0;
}

int main() {
  helmor

  forn(i, 2, MAXN) {
    if(spf[i] == 0) {
      for(int j = i; j < MAXN; j += i)
        if(spf[j] == 0) spf[j] = i;
    }
  }

  int T; cin >> T;
  while(T--) {
    int n; cin >> n;
    vector<int> a(n), sq(n);

    forn(i, 0, n) {
      cin >> a[i];
      int x = a[i], s = 1;
      while(x > 1) {
        int p = spf[x];
        x /= p;
        if(s % p == 0) s /= p; else s *= p;
      }
      sq[i] = s;
      cnt[s]++;
    }

    ll ans = 0;
    set<int> odds;
    forn(j, 0, n) {
      int x = a[j];
      while(x > 1) {
        int p = spf[x];
        x /= p;
        if(odds.count(p)) odds.erase(p); else odds.insert(p);
      }

      if(odds.size() <= 7) {
        ll prod = 1;
        for(int p : odds) {
          prod *= p;
          if(prod >= MAXN) break;
        }
        if(prod < MAXN) ans += cnt[prod];
      }
    }

    cout << ans << '\n';

    forn(i, 0, n) cnt[sq[i]]--;
  }
  return 0;
}