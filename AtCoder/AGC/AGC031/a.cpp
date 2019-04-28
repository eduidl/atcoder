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
  int N;
  string S;
  cin >> N >> S;

  vector<int> count(26, 0);
  long long sum = 1;

  for (int i = 0; i < N; ++i) {
    count[S[i] - 'a'] += 1;
  }
  for (int i = 0; i < 26; ++i) {
    if (count[i] == 0) continue;
    sum = (sum * (count[i] + 1)) % MOD;
  }
  sum = (sum + 1000000006) % MOD;
  cout << sum << endl;
}
