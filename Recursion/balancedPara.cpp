#include <bits/stdc++.h>
using namespace std;

void solve(int open, int close, string op, vector<string> &v) {
    // Base condition
    if (open == 0 && close == 0) {
        v.push_back(op);
        return;
    }

    if (open > 0) {
        solve(open - 1, close, op + '(', v);
    }

    if (close > open) {
        solve(open, close - 1, op + ')', v);
    }
}

vector<string> func(int n) {
    vector<string> v;
    int open = n;
    int close = n;
    string op = "";
    solve(open, close, op, v);
    return v;
}

int main() {
    int n;
    cin >> n;

    vector<string> result = func(n);

    for (auto value : result) {
        cout << value << endl;
    }

    return 0;
}
