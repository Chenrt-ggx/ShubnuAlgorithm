#include <iostream>

inline double calculate(double x, double a, double b, double c, double d) {
    return a * x * x * x + b * x * x + c * x + d;
}

double search(double l, double r, double a, double b, double c, double d, bool inc) {
    while (r - l > 0.001) {
        double mid = (l + r) / 2;
        double value = calculate(mid, a, b, c, d);
        if (value > 0) {
            if (inc) r = mid;
            else l = mid;
        } else {
            if (inc) l = mid;
            else r = mid;
        }
    }
    return l;
}

void solve() {
    double a, b, c, d;
    std::cin >> a >> b >> c >> d;
    for (int i = -100; i < 100; ++i) {
        double l = calculate(i, a, b, c, d), r = calculate(i + 1, a, b, c, d);
        if (l == 0) {
            printf("%.2lf ", (double) i);
        } else if (l * r < 0) {
            printf("%.2lf ", search(i, i + 1, a, b, c, d, l < 0));
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
