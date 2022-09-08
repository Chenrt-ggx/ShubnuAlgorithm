#include <vector>
#include <iostream>

bool is_prime(int val) {
    if (val < 2) return false;
    for (int i = 2; i * i <= val; ++i) {
        if (val % i == 0) return false;
    }
    return true;
}

int dfs(std::vector<int> &input, int index, int sum, int count) {
    if (!count) return is_prime(sum);
    int result = 0;
    for (int i = index; i < input.size(); ++i) {
        result += dfs(input, i + 1, sum + input[i], count - 1);
    }
    return result;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> input[i];
    }
    std::cout << dfs(input, 0, 0, k);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
