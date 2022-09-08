#include <string>
#include <vector>
#include <iostream>

class node;

class item;

class item {
private:
    int count, child;

public:
    inline explicit item(int count, int child) : count(count), child(child) {}

    void dump(std::vector<node> &nodes) const;
};

class node {
private:
    std::vector<item> child;

public:
    inline void add_child(item next) { this->child.emplace_back(next); }

    void dump(std::vector<node> &nodes) const;
};

item parse_item(std::vector<node> &nodes, int &index, std::string &line);

int parse_node(std::vector<node> &nodes, int &index, std::string &line);

void item::dump(std::vector<node> &nodes) const {
    if (this->child == -1) {
        std::cout << (char) this->count;
    } else {
        for (int i = 0; i < this->count; ++i) {
            nodes[this->child].dump(nodes);
        }
    }
}

void node::dump(std::vector<node> &nodes) const {
    for (item j : this->child) {
        j.dump(nodes);
    }
}

item parse_item(std::vector<node> &nodes, int &index, std::string &line) {
    if ('A' <= line[index] && line[index] <= 'Z') {
        return item(line[index++], -1);
    } else {
        ++index;
        int count = 0;
        while ('0' <= line[index] && line[index] <= '9') {
            count = count * 10 + (line[index++] ^ 48);
        }
        item result(count, parse_node(nodes, index, line));
        ++index;
        return result;
    }
}

int parse_node(std::vector<node> &nodes, int &index, std::string &line) {
    node result;
    while (index < line.length() && line[index] != ']') {
        result.add_child(parse_item(nodes, index, line));
    }
    nodes.emplace_back(result);
    return (int) nodes.size() - 1;
}

void solve() {
    int index = 0;
    std::string line;
    std::getline(std::cin, line);
    std::vector<node> nodes;
    int id = parse_node(nodes, index, line);
    nodes[id].dump(nodes);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
