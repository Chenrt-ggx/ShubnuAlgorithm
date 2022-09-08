#include <vector>
#include <iostream>
#include <algorithm>

void solve() {
    int total, strength, chair, arm;
    std::cin >> total >> strength >> chair >> arm;
    std::vector<int> buf;
    for (int i = 0; i < total; ++i) {
        int height, cost;
        std::cin >> height >> cost;
        if (height <= chair + arm) {
            buf.emplace_back(cost);
        }
    }
    std::sort(buf.begin(), buf.end());
    int count = 0;
    for (int i : buf) {
        if (i <= strength) {
            strength -= i;
            ++count;
        }
    }
    std::cout << count;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
