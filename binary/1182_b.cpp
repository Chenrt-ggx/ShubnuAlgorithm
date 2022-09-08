#include <vector>
#include <numeric>
#include <iostream>

bool check(std::vector<int> &sum, int limit, int count) {
    int index = 1;
    for (int i = 1; i < sum.size(); ++i) {
        if (limit < sum[i] - sum[i - 1]) return false;
        if (sum[i] - sum[index - 1] > limit) {
            index = i, --count;
        }
    }
    return count > 0;
}

void solve() {
    int total, count;
    std::cin >> total >> count;
    std::vector<int> sum(total + 1, 0);
    for (int i = 0; i < total; ++i) {
        int value;
        std::cin >> value;
        sum[i + 1] = value + sum[i];
    }
    int left = 0, right = sum.back();
    while (right - left > 1) {
        int mid = (left + right) >> 1;
        if (check(sum, mid, count)) right = mid;
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
