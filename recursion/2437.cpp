#include <vector>
#include <iostream>

inline void add(std::vector<int> &lhs, std::vector<int> &rhs, const int mask) {
    int adc = 0;
    for (int i = 0; i < std::max(lhs.size(), rhs.size()); ++i) {
        if (i == lhs.size()) lhs.emplace_back(0);
        if (i < rhs.size()) adc += rhs[i];
        adc += lhs[i], lhs[i] = adc % mask, adc /= mask;
    }
    if (adc) lhs.emplace_back(adc);
}

inline void dump(std::vector<int> &val, const int width) {
    std::cout << val.back();
    for (int i = (int) val.size() - 2; i >= 0; --i) {
        std::string str = std::to_string(val[i]);
        std::cout << std::string(width - str.length(), '0') << str;
    }
}

void solve() {
    int m, n;
    std::cin >> m >> n;
    int total = ((n - m) >> 1) + 1;
    std::vector<int> x(1, 1), y(1, 1);
    const int mask = 1e8, width = 8;
    for (int i = 1; i < total; ++i) {
        add(x, y, mask);
        add(y, x, mask);
    }
    if ((n - m) & 1) dump(y, width);
    else dump(x, width);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
