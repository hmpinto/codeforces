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

vll calc(const string& X, const string& Y) {
  int n = sz(X), m = sz(Y);

  vi w;
  forn(i, 0, m) if (Y[i] == 'W') w.pb(i + 1);

  vll g;
  forn(i, 1, sz(w)) g.pb(w[i] - w[i - 1]);
  sort(all(g));

  vll pre(sz(g) + 1, 0);
  forn(i, 0, sz(g)) pre[i + 1] = pre[i] + g[i];

  ll bl = w.empty() ? 0 : w.back();

  vll res;
  int a = 0;
  forn(i, 0, n) {
    int p = i + 1;
    if (X[i] == 'W') { a = p; continue; }

    if (a == 0) {
      ll L = p, ans = 1;
      if (!w.empty()) {
        int idx = upper_bound(all(g), L) - g.begin();
        ans += L + pre[idx] + L * (sz(g) - idx);
      }
      res.pb(ans);
    } else res.pb(m + 1 + (w.empty() ? 0 : max(0LL, bl + (p - a) - 1 - m)));
  }
  return res;
}

void solve() {
  int n, m; cin >> n >> m;
  string s, t; cin >> s >> t;

  auto print = [](const vll& v) {
    forn(i, 0, sz(v)) cout << v[i] << " \n"[i == sz(v) - 1];
  };
  print(calc(s, t));
  print(calc(t, s));
}

int main() {
  helmor

  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}