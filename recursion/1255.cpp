#include <vector>
#include <string>
#include <iostream>

void solve() {
    int total;
    std::cin >> total;
    if (total == 0 || total == 1) {
        std::cout << 1;
        return;
    }
    const int width = 8, mask = 1e8;
    std::vector<int> a(1, 1), b(1, 1);
    for (int i = 2; i <= total; ++i) {
        int adc = 0;
        std::vector<int> c;
        for (int j = 0; j < std::max(a.size(), b.size()); ++j) {
            if (j < a.size()) adc += a[j];
            if (j < b.size()) adc += b[j];
            c.emplace_back(adc % mask), adc /= mask;
        }
        if (adc) c.emplace_back(adc);
        b = a, a = c;
    }
    std::cout << a.back();
    for (int i = (int) a.size() - 2; i >= 0; --i) {
        std::string str = std::to_string(a[i]);
        std::cout << std::string(width - str.length(), '0') << str;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
