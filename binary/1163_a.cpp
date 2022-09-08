#include <vector>
#include <iostream>
#include <algorithm>

bool check(double total, double each, double times, double rate) {
    double base = 1, sum = 0;
    for (int i = 0; i < times; ++i) {
        base /= 1 + rate;
        sum += base;
    }
    return sum * each < total;
}

void solve() {
    int total, each, times;
    std::cin >> total >> each >> times;
    double left = 0, right = 10;
    while (right - left > 0.0001) {
        double mid = (left + right) / 2;
        if (check(total, each, times, mid)) right = mid;
        else left = mid;
    }
    printf("%.1lf", left * 100);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
