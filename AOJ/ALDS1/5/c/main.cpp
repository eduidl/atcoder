#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), i##_max = (b); i < i##_max; ++i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;
using i64 = int64_t;

constexpr int INF = 1 << 25;
constexpr int MOD = 1000000007;

class Point {
 public:
  double x;
  double y;
  Point(double x_, double y_) : x(x_), y(y_){};
  ~Point() = default;
  void print();
};

void Point::print() { cout << this->x << " " << this->y << endl; }

Point operator+(Point lhs, Point rhs) {
  return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

// 内分点
Point div_point(Point p1, Point p2, double a, double b) {
  return Point((b * p1.x + a * p2.x) / (a + b),
               (b * p1.y + a * p2.y) / (a + b));
}

// 回転行列
Point rot_point(Point p1, Point p2, double theta) {
  return p1 + Point((p2.x - p1.x) * cos(theta) - (p2.y - p1.y) * sin(theta),
                    (p2.x - p1.x) * sin(theta) + (p2.y - p1.y) * cos(theta));
}

void koch(int d, Point p1, Point p2) {
  if (d == 0) return;

  auto theta = M_PI * 60. / 180.;
  auto s = div_point(p1, p2, 1., 2.);
  auto t = div_point(p1, p2, 2., 1.);
  auto u = rot_point(s, t, theta);

  koch(d - 1, p1, s);
  s.print();
  koch(d - 1, s, u);
  u.print();
  koch(d - 1, u, t);
  t.print();
  koch(d - 1, t, p2);
}

int main() {
  int n;
  cin >> n;

  Point a(0., 0.), b(100., 0.);
  a.print();
  koch(n, a, b);
  b.print();
}
