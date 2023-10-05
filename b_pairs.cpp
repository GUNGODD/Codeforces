#include <iostream>
#include <vector>
#include <cstdio> // Include cstdio for freopen
using namespace std;

bool isValidPair(int x, int y, const vector<pair<int, int>>& pairs) {
    for (const auto& p : pairs) {
        if (p.first != x && p.first != y && p.second != x && p.second != y) {
            return false;
        }
    }
    return true;
}

int main() {
   
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pairs;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        pairs.emplace_back(a, b);
    }

    for (const auto& p : pairs) {
        int x = p.first;
        int y = p.second;

        if (isValidPair(x, -1, pairs)) {
            cout << "YES" << "\n";
            return 0;
        }

        if (isValidPair(x, y, pairs) || isValidPair(y, x, pairs)) {
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";

    return 0;
}
