#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

inline int fmul(int x, int y) {
  int ans = 0;
  for(; y; y >>= 1) {
    if(y & 1) {
      ans = (ans + x) % mod;
    }
    x = (x + x) % mod;
  }
  return ans;
}

inline int fexp(int x, int e) {
  int ans = 1;
  for(; e; e >>= 1) {
    if(e & 1) {
      ans = fmul(ans, x);
    }
    x = fmul(x, x);
  }
  return ans;
}

int main() {
  int a, b;
  while(cin >> a >> b) {
    cout << fexp(a, b) << '\n';
  }
  return 0;
}
