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

int bitpos_sum(ll x) {
  int s = 0;
  while (x) { s += __builtin_ctzll(x); x &= x - 1; }
  return s;
}

ll f(ll n) {
  if (n <= 1) return n;
  ll M = n / 2;
  ll A = (M + 1) / 2 * 2;           
  while (A - __builtin_popcountll(A) < M) A += 2;

  ll best = 2*A + bitpos_sum(A);
  forn(b, 1, 61) {
    if (A >> b & 1) continue;
    ll cand = ((A >> (b+1)) << (b+1)) | (1LL << b);
    if (2*cand >= best) break;
    chmin(best, 2*cand + (ll)bitpos_sum(cand));
  }
  return best - n;
}

void solve() {
  ll l, r; cin >> l >> r;
  ll sum = 0;
  for (ll n = l; n <= r; n++) sum += f(n);
  cout << sum % MOD << '\n';
}

int main() {
  helmor

  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}