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

ll solve(int n, int k) {
  return 2*(k-1) + pow(2, n-k+1);
}
 
int main() {
  helmor

  int T; cin >> T;
  while(T--) {
    int n, k; cin >> n >> k;
    
    cout << solve(n, k) << endl;
  }
  return 0;
}