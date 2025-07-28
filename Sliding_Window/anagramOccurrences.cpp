/*
Question - 
Count Occurrences of annagrams - 
window size = k = size of pattern
ptr = pattern 
*/

#include <bits/stdc++.h>
using namespace std;

int CountOccurrences(string str, string ptr) {
    int k = ptr.size();
    int n = str.size();
    
    // Frequency map for pattern
    unordered_map<char, int> mp;
    for(char ch : ptr) mp[ch]++;
    
    int count = mp.size(); 
    int ans = 0;
    int i = 0, j = 0;

    while(j < n) {
        // If current char exists in map, decrease its frequency
        if(mp.find(str[j]) != mp.end()) {
            mp[str[j]]--;
            if(mp[str[j]] == 0)
                count--;
        }

        if(j - i + 1 < k)
            j++;
        else if(j - i + 1 == k) {
            if(count == 0)
                ans++;

            // Now slide the window
            if(mp.find(str[i]) != mp.end()) {
                if(mp[str[i]] == 0)
                    count++; 
                mp[str[i]]++; 
            }

            i++;
            j++;
        }
    }

    return ans;
}

int main() {
    string str, ptr;
    cout << "Enter the string and pattern: ";
    cin >> str >> ptr;
    
    int result = CountOccurrences(str, ptr);
    cout << "Count of occurrences in anagram is: " << result << endl;
    
    return 0;
}
