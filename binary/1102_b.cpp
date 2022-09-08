#include <vector>
#include <iostream>
#include <unordered_map>

void solve() {
    int total, sub;
    std::cin >> total >> sub;
    std::vector<int> buf(total);
    std::unordered_map<int, int> map;
    for (int i = 0, value; i < total; ++i) {
        std::cin >> value;
        buf[i] = value - sub;
        ++map[value];
    }
    long long result = 0;
    for (int i = 0; i < total; ++i) {
        if (map.find(buf[i]) != map.end()) {
            result += map[buf[i]];
        }
    }
    std::cout << result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
