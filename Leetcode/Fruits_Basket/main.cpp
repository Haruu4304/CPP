#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    int n = fruits.size();
    int i = 0, j = 0;
    unordered_map<int, int> mp;
    int mx = 0;
    int k = 2;

    while (j < n) {
        mp[fruits[j]]++;

        // Shrink window if more than k types
        while (mp.size() > k) {
            mp[fruits[i]]--;
            if (mp[fruits[i]] == 0) {
                mp.erase(fruits[i]);
            }
            i++;
        }

        // Now we have at most k fruit types
        mx = max(mx, j - i + 1);

        j++;
    }

    return mx;
}

int main() {
    vector<int> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push_back(x);
    }

    int result = totalFruit(s);
    cout << result << endl;
}
