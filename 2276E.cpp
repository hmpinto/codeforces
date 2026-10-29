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
  int n; cin >> n;
  string s; cin >> s;

  const int D[4] = {0, 2, 5, 6};
  enum { ZERO = 0, TWO = 1, FIVE = 2, SIX = 3 };

  vector<array<int, 4>> nxt(n + 3);
  nxt[n + 1] = nxt[n + 2] = {n + 1, n + 1, n + 1, n + 1};
  forr(p, n, 1) {
    nxt[p] = nxt[p + 1];
    int c = s[p - 1] - '0';
    forn(j, 0, 4) if (c == D[j]) nxt[p][j] = p;
  }
  auto go = [&](int p, int j) { return p > n ? n + 1 : nxt[p][j]; };

  vll dc(n + 3, 0), dl(n + 3, 0);
  auto add = [&](int lo, int hi, ll c, ll k) {
    if (lo > hi) return;
    dc[lo] += c; dc[hi + 1] -= c;
    dl[lo] += k; dl[hi + 1] -= k;
  };

  forn(l, 1, n + 1) {
    int p0 = go(l, TWO);
    int p1 = go(p0 + 1, ZERO);
    int p2 = go(p1 + 1, TWO);
    if (p2 > n) break;
    int A = go(p2 + 1, FIVE);
    int B = go(p2 + 1, SIX); 
    if (A > n || A > B) continue;
    add(l, A - 1, B - A, 0); 
    add(A, B - 1, B, -1);         
  }

  ll C = 0, L = 0;
  forn(i, 1, n + 1) {
    C += dc[i];
    L += dl[i];
    ll bad = C + L * i;
    ll total = 1LL * i * (n - i + 1);
    cout << total - bad << " \n"[i == n];
  }
}

int main() {
  helmor

  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}