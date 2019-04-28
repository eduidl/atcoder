#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), i##_max = (b); i < i##_max; ++i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;

const int INF = 1 << 25;
const int MOD = 1000000007;

template <class T>
void chmin(T& a, const T& b) {
  a = min(a, b);
}

template <class T>
void chmax(T& a, const T& b) {
  a = max(a, b);
}

int main() {
  size_t N;
  cin >> N;
  int c;

  vector<int> pos(200001, -1);
  vector<int> dp(0);
  for (int i = 0; i < N; ++i) {
    cin >> c;
    if (i == 0) {
      dp.push_back(1);
    } else if (0 <= pos[c] && pos[c] < i - 1) {
      dp.push_back((dp[i - 1] + dp[pos[c]]) % MOD);
    } else {
      dp.push_back(dp[i - 1]);
    }
    pos[c] = i;
  }
  cout << dp[N - 1] << endl;
}
