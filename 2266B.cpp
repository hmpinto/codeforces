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

int solve(int value) {
  return 0;
}
 
int main() {
  helmor

  int T; cin >> T;
  while(T--) {
    int a,b,c; cin >> a >> b >> c;
    
    int score = abs(a - b);
    if(abs(a+c - b) > abs(a - b)) score = abs(a+c - b);
    else if(abs(a - (b+c)) < abs(a - b)) score = abs(a - (b+c));
    cout << score << endl;
  }
  return 0;
}