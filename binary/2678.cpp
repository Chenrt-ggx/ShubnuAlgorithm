#include <vector>
#include <iostream>

bool check(std::vector<int> &buf, int gap, int count) {
    for (int l = 0, r = 1; l < buf.size() && r < buf.size(); l = r++) {
        while (r < buf.size() && buf[r] - buf[l] < gap) ++r, --count;
    }
    return count >= 0;
}

void solve() {
    int distance, total, remove;
    std::cin >> distance >> total >> remove;
    std::vector<int> buf(total + 2, 0);
    for (int i = 1; i <= total; ++i) {
        std::cin >> buf[i];
    }
    buf.back() = distance;
    int left = 1, right = distance + 1;
    while (right - left > 1) {
        int mid = (left + right) >> 1;
        if (check(buf, mid, remove)) left = mid;
        else right = mid;
    }
    std::cout << left;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
