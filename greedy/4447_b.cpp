#include <queue>
#include <vector>
#include <numeric>
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
        return this->length > rhs.length;
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
    std::vector<node> buf;
    int ans = INT32_MAX;
    for (int i = 0; i < score.size(); ++i) {
        if (i && score[i] != score[i - 1]) {
            while (!buf.empty()) {
                pq.push(buf.back());
                buf.pop_back();
            }
        }
        bool flag = false;
        while (!pq.empty() && !flag) {
            node top = pq.top();
            pq.pop();
            if (top.get_last() + 1 == score[i]) {
                buf.emplace_back(top.get_length() + 1, score[i]);
                flag = true;
            } else {
                ans = std::min(ans, top.get_length());
            }
        }
        if (!flag) {
            buf.emplace_back(1, score[i]);
        }
    }
    while (!pq.empty()) {
        ans = std::min(ans, pq.top().get_length());
        pq.pop();
    }
    std::cout << std::accumulate(buf.begin(), buf.end(), ans, [](int lhs, node &rhs) {
        return std::min(lhs, rhs.get_length());
    });
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
