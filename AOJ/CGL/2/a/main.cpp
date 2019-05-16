#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), i##_max = (b); i < i##_max; ++i)
#define RFOR(i, a, b) for (int i = (b)-1, i##_min = (a); i >= i##_min; --i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP(i, n) for (int i = (n)-1; i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using vi = vector<int>;
using vl = vector<i64>;
using vd = vector<double>;
using pi = pair<int, int>;
using pl = pair<i64, i64>;
using pd = pair<double, double>;

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

template <typename T>
class Vec2 {
 public:
  Vec2(){};
  Vec2(T x, T y) : x(x), y(y){};
  Vec2<T> operator+(Vec2<T> p);
  Vec2<T> operator-(Vec2<T> p);
  T dot(Vec2<T> p);
  bool is_paralell(Vec2<T> p);
  bool is_vertical(Vec2<T> p);
  T x, y;
};

template <typename T>
Vec2<T> Vec2<T>::operator+(Vec2<T> p) {
  return Vec2(x + p.x, y + p.y);
}

template <typename T>
Vec2<T> Vec2<T>::operator-(Vec2<T> p) {
  return Vec2(x - p.x, y - p.y);
}

template <typename T>
T Vec2<T>::dot(Vec2<T> p) {
  return x * p.x + y * p.y;
}

template <typename T>
bool Vec2<T>::is_paralell(Vec2<T> p) {
  return x * p.y == y * p.x;
}

template <typename T>
bool Vec2<T>::is_vertical(Vec2<T> p) {
  return this->dot(p) == (T)0;
}

int main() {
  int q, x, y;
  Vec2<int> p0, p1, p2, p3;
  cin >> q;
  REP(i, q) {
    cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    if ((p1 - p0).is_paralell(p3 - p2)) {
      cout << "2" << endl;
    } else if ((p1 - p0).is_vertical(p3 - p2)) {
      cout << "1" << endl;
    } else {
      cout << "0" << endl;
    }
  }
}
