#include <cmath>
#include <iostream>

void solve() {
    double a, b, c, d, x1, x2, x3;
    double alpha, beta, tau, theta;
    std::cin >> a >> b >> c >> d;
    alpha = b * b - 3 * a * c;
    beta = b * c - 9 * a * d;
    tau = (2 * alpha * b - 3 * a * beta) / (2 * sqrt(alpha * alpha * alpha));
    theta = acos(tau);
    x1 = (-b - 2 * sqrt(alpha) * cos(theta / 3)) / (3 * a);
    x2 = (-b + sqrt(alpha) * (cos(theta / 3) - sqrt(3) * sin(theta / 3))) / (3 * a);
    x3 = (-b + sqrt(alpha) * (cos(theta / 3) + sqrt(3) * sin(theta / 3))) / (3 * a);
    printf("%.2lf %.2lf %.2lf", x1, x2, x3);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
