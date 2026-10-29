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
  int n, x; cin >> n >> x;
  vll a(n);
  for (auto& v : a) cin >> v;

  auto ok = [&](ll k) -> bool {
    vector<bool> iso(n);
    forn(i, 0, n) {
      bool l = (i == 0)     || a[i] - a[i - 1] > k;
      bool r = (i == n - 1) || a[i + 1] - a[i] > k;
      iso[i] = l && r;
    }
    ll need = 0;
    for (int i = 0; i < n; ) {
      if (!iso[i]) { i++; continue; }
      int j = i;
      while (j + 1 < n && iso[j + 1] && a[j + 1] - a[j] <= 2 * k) j++;
      need += (j - i + 2) / 2;
      i = j + 1;
    }
    return need <= x;
  };

  ll lo = 1, hi = 1e9;
  while (lo < hi) {
    ll mid = (lo + hi) / 2;
    if (ok(mid)) hi = mid;
    else lo = mid + 1;
  }
  cout << lo << '\n';
}

int main() {
  helmor

  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}