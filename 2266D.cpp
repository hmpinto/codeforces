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
    vector<ll> a(n);
    forn(i, 0, n) {
      ll ai;
      cin >> ai;
      a[i] = ai - (i + 1);
    }
    
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int best = 1, cur = 1;
    forn (i, 1, a.size()) {
      if (a[i] == a[i - 1] + 1) cur++;
      else cur = 1;
      best = max(best, cur);
    }

    cout << best << endl;
  }
  return 0;
}