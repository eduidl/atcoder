#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), i##_max = (b); i < i##_max; ++i)
#define RFOR(i, a, b) for (int i = (b)-1, i##_min = (a); i >= i##_min; --i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP(i, n) for (int i = (n)-1; i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;
using vi = vector<int>;
using vd = vector<double>;
using i64 = int64_t;

constexpr int INF = 1 << 30;
constexpr int MOD = 1000000007;

template <typename T>
void print(vector<T> &v) {
  REP(i, v.size()) {
    if (i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

void max_heapify(vi &A, int H, int i) {
  auto l = 2 * i;
  auto r = 2 * i + 1;

  auto largest = (l <= H && A[l] > A[i]) ? l : i;
  if (r <= H && A[r] > A[largest]) largest = r;
  if (largest != i) {
    swap(A[i], A[largest]);
    max_heapify(A, H, largest);
  }
}

int main() {
  int H;
  cin >> H;
  vi A(H + 1);
  FOR(i, 1, H + 1) cin >> A[i];
  RFOR(i, 1, H / 2 + 1) max_heapify(A, H, i);
  FOR(i, 1, H + 1) cout << " " << A[i];
  cout << endl;
}
