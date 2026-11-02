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
const int MOD = 998244353;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  int n; cin >> n;
  vector<vi> adj(n + 1);
  forn(i, 0, n - 1) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }
  string x, y; cin >> x >> y;

  vi dep(n + 1, -1), carry(n + 1, 0), order;
  order.reserve(n);
  dep[1] = 0; order.pb(1);
  forn(h, 0, n) {
    int v = order[h];
    for (int w : adj[v]) if (dep[w] < 0) {
      dep[w] = dep[v] + 1;
      order.pb(w);
    }
  }

  ll ans = 0, p2 = 1;
  int i = 0;
  while (i < n) {
    int d = dep[order[i]], j = i, bit = -1;

    while (j < n && dep[order[j]] == d) {
      int v = order[j];
      int req = (x[v - 1] - '0') ^ (y[v - 1] - '0') ^ carry[v];
      if (bit == -1) bit = req;
      else if (bit != req) { cout << -1 << '\n'; return; }
      j++;
    }

    forn(k, i, j) {
      int v = order[k];
      int s = bit + (x[v - 1] - '0') + carry[v];
      for (int w : adj[v]) if (dep[w] == d + 1) carry[w] = s >> 1;
    }

    ans = (ans + bit * p2) % MOD;
    p2 = p2 * 2 % MOD;
    i = j;
  }
  cout << ans << '\n';
}

int main() {
  helmor

  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}