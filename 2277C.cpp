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

// ---------- debug: so existe compilando com -DLOCAL ----------
#ifdef LOCAL
template <class A, class B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <class T, class = decltype(begin(declval<T>())),
          class = enable_if_t<!is_convertible<T, string>::value>>
ostream& operator<<(ostream& os, const T& v) {
  os << '{';
  bool first = true;
  for (const auto& x : v) { if (!first) os << ", "; first = false; os << x; }
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <class H, class... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << "[L" << __LINE__ << "] " << #__VA_ARGS__ << " =", dbg_out(__VA_ARGS__)
#else
#define dbg(...) ((void)0)
#endif
// --------------------------------------------------------------

const int INF = 1e9;
const ll LINF = 4e18;
const int MOD = 1e9 + 7;  // ou 998244353

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  int n, m; cin >> n >> m;
  vector<vi> g(n + 1);
  forn(i, 0, n - 1) {
    int x, y; cin >> x >> y;
    g[x].pb(y), g[y].pb(x);
  }

  vi dep(n + 1, -1), br(n + 1, 0), q;
  q.reserve(n);
  dep[1] = 0, q.pb(1);
  forn(i, 0, sz(q)) {
    int u = q[i];
    for (int w : g[u]) if (dep[w] < 0) {
      dep[w] = dep[u] + 1;
      br[w] = (u == 1 ? w : br[u]);
      q.pb(w);
    }
  }

  vi dn(n + 1, -1);
  q.clear(), dn[n] = 0, q.pb(n);
  forn(i, 0, sz(q)) {
    int u = q[i];
    for (int w : g[u]) if (dn[w] < 0) {
      dn[w] = dn[u] + 1;
      q.pb(w);
    }
  }

  int ans = dep[n];
  forn(i, 0, m) {
    int v; cin >> v;
    if (br[v] == br[n]) chmax(ans, 1 + dn[v]);
  }
  dbg(dep[n], br[n], ans);
  cout << ans << '\n';
}

int main() {
  helmor

  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}