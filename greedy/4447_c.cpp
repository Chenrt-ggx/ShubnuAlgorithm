#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

class node {
private:
    int length, last;

public:
    inline node(int length, int last) : length(length), last(last) {}

    inline int get_last() const {
        return this->last;
    }

    inline int get_length() const {
        return this->length;
    }

    bool operator<(const node &rhs) const {
        return this->last == rhs.last ? this->length > rhs.length : this->last > rhs.last;
    }
};

void solve() {
    int total;
    std::cin >> total;
    std::vector<int> score(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> score[i];
    }
    std::sort(score.begin(), score.end());
    std::priority_queue<node> pq;
    int ans = INT32_MAX;
    for (int i : score) {
        while (!pq.empty() && pq.top().get_last() < i - 1) {
            ans = std::min(ans, pq.top().get_length());
            pq.pop();
        }
        if (!pq.empty() && pq.top().get_last() == i - 1) {
            node top = pq.top();
            pq.pop();
            pq.emplace(top.get_length() + 1, i);
        } else {
            pq.emplace(1, i);
        }
    }
    while (!pq.empty()) {
        ans = std::min(ans, pq.top().get_length());
        pq.pop();
    }
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
