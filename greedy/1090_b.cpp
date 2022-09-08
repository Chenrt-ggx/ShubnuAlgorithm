#include <vector>
#include <iostream>
#include <algorithm>

inline int offer(std::vector<int> &items, int &i, std::vector<int> &buf, int &j) {
    if (i >= items.size()) return buf[j++];
    if (j >= buf.size()) return items[i++];
    return items[i] < buf[j] ? items[i++] : buf[j++];
}

void solve() {
    int total;
    std::cin >> total;
    std::vector<int> items(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> items[i];
    }
    std::sort(items.begin(), items.end());
    int sum = 0;
    std::vector<int> buf;
    for (int i = 0, j = 0, k = 1; k < total; ++k) {
        int x = offer(items, i, buf, j);
        int y = offer(items, i, buf, j);
        buf.emplace_back(x + y), sum += x + y;
    }
    std::cout << sum;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
