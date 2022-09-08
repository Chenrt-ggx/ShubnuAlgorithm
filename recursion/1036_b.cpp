#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

void euler_filter(std::vector<int> &array) {
    std::vector<int> prime(array.size());
    int count = 0;
    for (int i = 2; i < array.size(); ++i) array[i] = 1;
    for (int i = 2; i < array.size(); ++i) {
        if (array[i]) prime[count++] = i;
        for (int j = 0; j < count && i * prime[j] < array.size(); ++j) {
            array[i * prime[j]] = 0;
            if (i % prime[j] == 0) break;
        }
    }
}

void dfs(std::vector<int> &set, std::vector<int> &input, int index, int sum, int count, int max) {
    if (count == max) {
        set.emplace_back(sum);
    } else {
        for (int i = index; i < input.size(); ++i) {
            dfs(set, input, i + 1, sum + input[i], count + 1, max);
        }
    }
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> input[i];
    }
    std::vector<int> set;
    dfs(set, input, 0, 0, 0, k);
    static std::vector<int> prime(std::accumulate(set.begin(), set.end(), 0, [](int lhs, int rhs) {
        return std::max(lhs, rhs);
    }) + 1, 0);
    euler_filter(prime);
    std::cout << std::count_if(set.begin(), set.end(), [](int val) {
        return prime[val];
    });
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
