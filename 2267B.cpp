#include<bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    
    map<int, int> m;
    int most_freq = 0;

    for(int i = 0; i < n; i++) {
      int ai; cin >> ai;
      
      if(m.count(ai) == 0) m[ai] = 0;
      m[ai]++;
      
      if(m[ai] > most_freq) most_freq = m[ai];
    }
    
    for(int i = 0; i < most_freq; i++) {
      for(auto it = m.rbegin(); it != m.rend(); it++) {
        if(it->second) {
          cout << it->first << " ";
          it->second--;
        }
      }
    }
    cout << endl;
  }
}