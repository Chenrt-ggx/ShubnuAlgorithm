#include <vector>
#include <iostream>
#include <algorithm>

bool check(std::vector<int> &buf, int gap, int count) {
    for (int l = 0, r = 1; l < buf.size() && r < buf.size();) {
        while (r < buf.size() && buf[r] - buf[l] < gap) ++r;
        if (r < buf.size()) {
            l = r, --count;
        }
    }
    return count <= 1;
}

void solve() {
    int total, count;
    std::cin >> total >> count;
    std::vector<int> buf(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> buf[i];
    }
    std::sort(buf.begin(), buf.end());
    int left = 1, right = buf.back() - buf.front();
    while (right - left > 1) {
        int mid = (left + right) >> 1;
        if (check(buf, mid, count)) left = mid;
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
