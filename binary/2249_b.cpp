#include <iostream>
#include <unordered_map>

void solve() {
    int total, query;
    std::cin >> total >> query;
    std::unordered_map<int, int> buf;
    for (int i = 0, value; i < total; ++i) {
        std::cin >> value;
        if (buf.find(value) == buf.end()) {
            buf[value] = i;
        }
    }
    for (int i = 0, value; i < query; ++i) {
        std::cin >> value;
        if (buf.find(value) != buf.end()) {
            std::cout << buf[value] + 1 << ' ';
        } else {
            std::cout << "-1 ";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
