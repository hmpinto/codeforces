#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int a[MAXN];

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      int v; cin >> v;
      a[v] = i;
    }

    int l = 1, r = n;
    bool flag = true;
    for (int v = 1; v <= n && flag; v++) {
      int p = a[v] % 2;
      if ((r - l + 1) % 2 == 0) {
        if (l % 2 == p) l++;
        else r--;
      } else {
        if (l % 2 == p) l++;
        else flag = false;
      }
    }
    cout << (flag ? "YES" : "NO") << endl;
  }
}