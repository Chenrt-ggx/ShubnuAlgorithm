#include <vector>
#include <iostream>
#include <algorithm>

bool check(std::vector<int> &buf, int gap, int count) {
    for (int i = 1; i < buf.size(); ++i) {
        if (buf[i] - buf[i - 1] >= gap) {
            count -= (buf[i] - buf[i - 1] - 1) / gap;
        }
    }
    return count >= 0;
}

void solve() {
    int distance, total, add;
    std::cin >> distance >> total >> add;
    std::vector<int> buf(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> buf[i];
    }
    std::sort(buf.begin(), buf.end());
    int left = 1, right = distance + 1;
    while (right - left > 1) {
        int mid = (left + right) >> 1;
        if (check(buf, mid, add)) right = mid;
        else left = mid;
    }
    std::cout << right;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
