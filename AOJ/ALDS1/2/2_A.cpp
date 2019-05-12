#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), i##_max = (b); i < i##_max; ++i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;

constexpr int INF = 1 << 30;
constexpr int MOD = 1000000007;

int bubble_sort(vector<int> &A) {
  int cnt = 0;
  auto flag = true;
  for (int i = 0; flag; ++i) {
    flag = false;
    for (int j = A.size() - 1; j >= 1; --j) {
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
        flag = true;
        ++cnt;
      }
    }
  }
  return cnt;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  auto cnt = bubble_sort(A);
  REP(i, N) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl << cnt << endl;
}
