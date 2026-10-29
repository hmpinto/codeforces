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

const int MOD = 998244353;
const int LMAX = 60, U = 4096;

ll S(ll x) { ll s = 0; for (int b = 0; x; x >>= 1, b++) if (x & 1) s += b; return s; }
int pcnt(ll x) { return __builtin_popcountll(x); }
int ctz(ll x) { return __builtin_ctzll(x); }
ll phi(ll B) { return 4*B + S(B) + pcnt(B); }

ll psi(ll B) {
  ll r = phi(B);
  forn(L, 1, LMAX + 1) chmin(r, phi(((B + (1LL<<L) - 1) >> L) << L));
  return r;
}

int lim_[LMAX+1], pw2[LMAX+1];
vll pv_[LMAX+1];
vi sPW_[LMAX+1], sW_[LMAX+1], Psum(LMAX+1);

int Wsum(int L) { return (int)(((2LL*(pw2[L]-1+MOD) - L) % MOD + MOD) % MOD); }

int Clip(int L, ll y) {
  int lim = lim_[L]; if (!lim) return 0;
  int lo = 0, hi = lim;
  while (lo < hi) { int m = (lo+hi+1)/2; if (pv_[L][m] > y) lo = m; else hi = m-1; }
  if (!lo) return 0;
  ll ym = ((y % MOD) + MOD) % MOD;
  return (int)(((sPW_[L][lo] - ym * sW_[L][lo]) % MOD + MOD) % MOD);
}

void init() {
  pw2[0] = 1; forn(L, 1, LMAX+1) pw2[L] = (int)(2LL*pw2[L-1] % MOD);
  forn(L, 0, LMAX+1) {
    ll base = 1LL << L;
    int lim = (int)min<ll>(U, base - 1); lim_[L] = lim;
    pv_[L].assign(lim+1, LLONG_MAX); sPW_[L].assign(lim+1, 0); sW_[L].assign(lim+1, 0);
    ll cur = LLONG_MAX;
    forn(u, 1, lim+1) {
      ll R = base - u; chmin(cur, phi(R));
      int w = 1 + ctz(R);
      pv_[L][u] = cur;
      sPW_[L][u] = (int)((sPW_[L][u-1] + cur % MOD * w) % MOD);
      sW_[L][u]  = (int)((sW_[L][u-1] + w) % MOD);
    }
  }
  Psum[0] = 0;
  forn(L, 1, LMAX+1) {
    ll Q = (1LL<<(L+1)) + L;
    ll Qm = Q % MOD;
    Psum[L] = (int)((( (ll)Psum[L-1] - Clip(L-1, Q) + Qm*L + Qm*Wsum(L-1) + Psum[L-1] ) % MOD + MOD) % MOD);
  }
}

ll Bmin(ll M) { ll B = max(0LL, M/2); while (2*B - pcnt(B) < M) B++; return B; }

int Tsum(ll K) {
  if (K <= 0) return 0;
  ll Bmax = Bmin(K), N = Bmax + 1;
  vector<pll> blocks; ll cur = 0;
  forr(L, LMAX, 0) if (N >> L & 1) { blocks.pb({cur, L}); cur += 1LL << L; }
  ll esc = psi(N), total = 0;
  for (int i = sz(blocks)-1; i >= 0; i--) {
    ll s = blocks[i].fi; int L = (int)blocks[i].se;
    ll C = phi(s), y = esc - C;
    int w0 = s ? 1 + ctz(s) : 1;
    ll Wtot = (w0 + Wsum(L)) % MOD;
    ll part = (min(0LL, y) % MOD + MOD) % MOD * w0 % MOD;
    part = ((part + Psum[L] - Clip(L, y)) % MOD + MOD) % MOD;
    total = (total + C % MOD * Wtot + part) % MOD;
    chmin(esc, C);
  }
  ll hB = 2*Bmax - pcnt(Bmax);
  return (int)(((total - psi(Bmax) % MOD * ((hB - K) % MOD)) % MOD + MOD) % MOD);
}

ll inv2;
int F(ll X) {
  if (X < 1) return 0;
  ll r = (2 + 2LL*Tsum(X/2)) % MOD;
  if (X % 2 == 0) r -= psi(Bmin(X/2)) % MOD;
  r -= X % MOD * ((X+1) % MOD) % MOD * inv2 % MOD;
  return (int)((r % MOD + 2LL*MOD) % MOD);
}

void solve() {
  ll l, r; cin >> l >> r;
  cout << ((F(r) - F(l-1)) % MOD + MOD) % MOD << '\n';
}

int main() {
  helmor
  inv2 = (MOD + 1) / 2;
  init();
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}