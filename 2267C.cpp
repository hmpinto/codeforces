#include<bits/stdc++.h>

using namespace std;

const int MAXN = 300005;
int a[MAXN];
int primos[10];

int main() {
  int t; cin >> t;
  while (t--) {
    int n, x; cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];

    int k = 0;
    int y = x;
    for (int p = 2; p * p <= y; p++)
      if (y % p == 0) {
        primos[k++] = p;
        while (y % p == 0) y /= p;
      }
    if (y > 1) primos[k++] = y;

    long long best = 0;
    for (int j = 0; j < k; j++) {
      long long s = 0;
      for (int i = 0; i < n; i++) if (a[i] % primos[j] == 0) s += a[i];
      best = max(best, s);
    }
    cout << best << "\n";
  }
}