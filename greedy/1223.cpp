#include <vector>
#include <iostream>
#include <algorithm>

void solve() {
    int total;
    std::cin >> total;
    std::vector<std::pair<int, int>> buf(total);
    for (int i = 0; i < total; ++i) {
        buf[i].first = i + 1;
        std::cin >> buf[i].second;
    }
    std::sort(buf.begin(), buf.end(), [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
        return lhs.second == rhs.second ? lhs.first < rhs.first : lhs.second < rhs.second;
    });
    double result = 0, sum = 0;
    for (std::pair<int, int> &i : buf) {
        std::cout << i.first << ' ';
        result += sum;
        sum += i.second;
    }
    std::cout << std::endl;
    printf("%.2lf", 1.0 * result / total);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
