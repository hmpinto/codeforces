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

int a[MAXN];

int count_bits(int x) {
  int bits = 0;
  while (x) { bits += x & 1; x >>= 1; }
  return bits;
}
 
int main() {
  helmor

  int T; cin >> T;
  while(T--) {
    int n, q; cin >> n >> q;
    int cnt = 0;
    forn(i, 1, n+1) {
      cin >> a[i];
      cnt += (count_bits(a[i]) % 2 == 0);
    }
    cout << cnt;

    while(q--) {
      int p, x;
      cin >> p >> x;
      cnt -= (count_bits(a[p]) % 2 == 0);

      a[p] = x;
      cnt += (count_bits(a[p]) % 2 == 0);
      cout << " " << cnt;
    }
    cout << endl;
  }
  return 0;
}