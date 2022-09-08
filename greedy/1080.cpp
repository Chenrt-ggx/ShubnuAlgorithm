#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

void cpy(std::vector<int> &to, std::vector<int> &from) {
    to.resize(from.size());
    for (int i = 0; i < from.size(); ++i) {
        to[i] = from[i];
    }
}

bool cmp(std::vector<int> &lhs, std::vector<int> &rhs) {
    if (lhs.size() != rhs.size()) {
        return lhs.size() > rhs.size();
    }
    for (int i = (int) lhs.size() - 1; i >= 0; --i) {
        if (lhs[i] != rhs[i]) {
            return lhs[i] > rhs[i];
        }
    }
    return false;
}

void mul(std::vector<int> &buf, int val) {
    int adc = 0;
    for (int &i : buf) {
        int update = i * val + adc;
        i = update % 10000, adc = update / 10000;
    }
    if (adc) {
        buf.emplace_back(adc);
    }
}

void div(std::vector<int> &to, std::vector<int> &buf, int val) {
    to.resize(buf.size(), 0);
    int remain = 0;
    for (int i = (int) buf.size() - 1; i >= 0; --i) {
        remain = remain * 10000 + buf[i];
        to[i] = remain / val, remain %= val;
    }
    while (to.size() > 1 && to.back() == 0) {
        to.pop_back();
    }
}

void write(std::vector<int> &buf) {
    std::cout << buf.back();
    for (int i = (int) buf.size() - 2; i >= 0; --i) {
        std::string str = std::to_string(buf[i]);
        std::cout << std::string(4 - str.length(), '0') << str;
    }
}

void solve() {
    int total, a, b;
    std::cin >> total >> a >> b;
    std::vector<std::pair<int, int>> buf(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> buf[i].first >> buf[i].second;
    }
    std::sort(buf.begin(), buf.end(), [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
        return lhs.first * lhs.second < rhs.first * rhs.second;
    });
    std::vector<int> cur(1, a), result(1, 0), clone;
    for (int i = 0; i < total; ++i) {
        div(clone, cur, buf[i].second);
        if (cmp(clone, result)) cpy(result, clone);
        mul(cur, buf[i].first);
    }
    write(result);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
