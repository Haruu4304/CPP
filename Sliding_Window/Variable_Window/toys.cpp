/*
Pick a toy - 
John mom's conditions -
cond1 : continuous -> substring
cond2 : max 2 types
*/

#include <bits/stdc++.h>
using namespace std;


int MaxToys(vector<string> &ss, int k) {
    int i = 0, j = 0;
    int mx = INT_MIN;
    unordered_map<string, int> mp;
    int n = ss.size();

    while (j < n) {
        mp[ss[j]]++;

        // Case I: less than k types → just expand
        if (mp.size() < k) {
            j++;
        }

        // Case II: exactly k types → update max and expand
        else if (mp.size() == k) {
            mx = max(mx, j - i + 1);  // valid window
            j++;
        }

        // Case III: more than k types → shrink from left
        else if (mp.size() > k) {
            while (mp.size() > k) {
                mp[ss[i]]--;
                if (mp[ss[i]] == 0) {
                    mp.erase(ss[i]);
                }
                i++;
            }

            // After shrinking, still need to check max
            mx = max(mx, j - i + 1);
            j++;
        }
    }

    return mx;
}

int main() {
    vector<string> ss;
    int n;
    cout << "Size of string: ";
    cin >> n;
    cout << "Enter toy types: ";
    for (int i = 0; i < n; ++i) {
        string val;
        cin >> val;
        ss.push_back(val);
    }

    int k = 2; // Only 2 types allowed
    int result = MaxToys(ss, k);
    cout << "Max no of toys : " << result << endl;
    return 0;
}
