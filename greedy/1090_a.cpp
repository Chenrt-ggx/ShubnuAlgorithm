#include <queue>
#include <iostream>

void solve() {
    int total;
    std::cin >> total;
    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    for (int i = 0, next; i < total; ++i) {
        std::cin >> next;
        pq.emplace(next);
    }
    int result = 0;
    for (int x, y; pq.size() != 1;) {
        x = pq.top(), pq.pop();
        y = pq.top(), pq.pop();
        result += x + y;
        pq.emplace(x + y);
    }
    std::cout << result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
