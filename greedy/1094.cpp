#include <vector>
#include <iostream>
#include <algorithm>

void solve() {
    int size, total;
    std::cin >> size >> total;
    std::vector<int> items(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> items[i];
    }
    std::sort(items.begin(), items.end());
    int count = 0;
    for (int l = 0, r = total - 1; l <= r;) {
        if (items[l] + items[r] <= size) ++l;
        --r, ++count;
    }
    std::cout << count;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
