#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define helmor ios::sync_with_stdio(false); cin.tie(nullptr);
#define forn(i, a, b) for (int i = (a); i < (b); i++)
#define forr(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define fi first
#define se second

template <class T> bool chmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template <class T> bool chmax(T& a, const T& b) { return a < b ? a = b, true : false; }

#ifdef LOCAL
#define dbg(...) cerr << "[L" << __LINE__ << "] " << #__VA_ARGS__ << endl
#else
#define dbg(...) ((void)0)
#endif

// mex do prefixo a[0..m-1]
int prefMex(const vi& a, int m) {
  vector<bool> seen(sz(a) + 1, false);
  forn(i, 0, m) seen[a[i]] = true;
  int x = 0;
  while (seen[x]) x++;
  return x;
}

void solve() {
  int n, k; cin >> n >> k;
  vi a(n);
  for (auto& x : a) cin >> x;

  int m = n - k + 1;
  int base = prefMex(a, m);
  int best = base, bi = -1, bj = -1;

  forn(i, 0, n) forn(j, i + 1, n) {
    swap(a[i], a[j]);
    if (chmax(best, prefMex(a, m))) bi = i, bj = j;
    swap(a[i], a[j]);
  }

  if (bi == -1) cout << -1 << '\n';
  else cout << bi + 1 << ' ' << bj + 1 << '\n';
}

int main() {
  helmor

  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}