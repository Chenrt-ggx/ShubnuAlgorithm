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
    double result = 0;
    for (double gap = 0.0001; gap > 1e-6;) {
        if (check(total, each, times, result + gap)) gap /= 2;
        else result += gap, gap *= 2;
    }
    printf("%.1lf", result * 100);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
