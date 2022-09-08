#include <vector>
#include <iostream>
#include <algorithm>

void solve() {
    int total, query;
    std::cin >> total >> query;
    std::vector<int> lines(total);
    std::vector<int> scores(query);
    for (int i = 0; i < total; ++i) {
        std::cin >> lines[i];
    }
    std::sort(lines.begin(), lines.end());
    for (int i = 0; i < query; ++i) {
        std::cin >> scores[i];
    }
    std::sort(scores.begin(), scores.end());
    long long result = 0;
    for (int i = 0, j = 0; i < scores.size(); ++i) {
        int next = abs(scores[i] - lines[j]);
        while (j + 1 < lines.size() && abs(scores[i] - lines[j + 1]) <= next) {
            next = abs(scores[i] - lines[++j]);
        }
        result += next;
    }
    std::cout << result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
