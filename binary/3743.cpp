#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

bool check(std::vector<std::pair<double, double>> &buf, double time, double speed) {
    double sum = 0;
    for (std::pair<double, double> &i : buf) {
        sum += std::max(time * i.first - i.second, 0.0);
    }
    return sum < speed * time;
}

void solve() {
    int total, speed;
    std::cin >> total >> speed;
    typedef std::pair<double, double> pdd;
    std::vector<pdd> buf(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> buf[i].first >> buf[i].second;
    }
    double sum = std::accumulate(buf.begin(), buf.end(), 0.0, [](double l, pdd r) {
        return l + r.first;
    });
    if (speed >= sum) {
        std::cout << -1;
    } else {
        double left = 0, right = sum * speed;
        while (right - left > 0.00001) {
            double mid = (left + right) / 2;
            if (check(buf, mid, speed)) left = mid;
            else right = mid;
        }
        std::cout << left;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
