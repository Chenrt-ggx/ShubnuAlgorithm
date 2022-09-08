#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

void solve() {
    double a, b, c, d;
    std::cin >> a >> b >> c >> d;
    for (double i = -100; i <= 100; i += 0.001 /* NOLINT */) {
        double j = i + 0.001;
        double l = a * i * i * i + b * i * i + c * i + d;
        double r = a * j * j * j + b * j * j + c * j + d;
        if (l >= 0 && r <= 0 || l <= 0 && r >= 0) {
            double mid = (i + j) / 2;
            printf("%.2lf ", mid);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
