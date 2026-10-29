#include<bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int n;
    char c;
    cin >> n >> c;
    string s; cin >> s;
    
    int ans = 0;
    int m = (n % 2 == 1) ? (n-1) / 2 : n/2;
    // cout << n << " " << m << endl;
    for(int i = 0; i < m; i++) {
      if(s[i] != s[n-i-1]) {
        if(s[i] != c and s[n-i-1] != c) ans += 2;
        else ans += 1;
      }
    }
    cout << ans << endl;
  }
}