/*
Longest substring with k unique characters - 
*/

#include<bits/stdc++.h>
using namespace std;

//brute force method - O(n^3)
int longestSubstringWithKUnique(string str, int k){
    int i=0, j=0;
    int maxlen = 0;
    int size = str.size();
    for(int i=0; i<size ; ++i){
        for(int j=0; j<size; ++j){
            string sub = str.substr(i , j-i+1);

            int freq[256] = {0};
            int uniqueChar = 0;
            for(char ch : sub){
                if(freq[ch] == 0){
                    uniqueChar++;
                }
                freq[ch]++;
            }

            if(uniqueChar == k){
                int len =  j-i+1;
                if(maxlen < len){
                    maxlen = len;
                }
            }
        }
    }
    return maxlen;
}

//optimized method - O()
int longestSub(vector<string> ss , int size , int k){
    int i=0, j=0;
    unordered_map<string, int>mp;
    int ans = INT_MIN;
    while(j < size){
        //condition - 
        mp[ss[j]]++;

        //case I
        if(mp.size() < k){
            j++;
        }
        //case II
        else if(mp.size() == k){
            ans = max(ans , j-i+1);
            j++;
        }
        //case III
        else if(mp.size() > k){
            while(mp.size() > k){
                mp[ss[i]]--;
                if(mp[ss[i]] == 0){
                    mp.erase(ss[i]);
                }
                i++;
            }
            j++;
        }
    }
    return (ans == INT_MIN) ? -1 : ans;
}

int main(){
    vector<string> s;
    int size , k;
    cout << "enter the size of string and then enter the k unique characters : "<< endl;
    cin >> size >> k;
    cout << "enter the elements : " << endl;
    for(int i=0; i<size; ++i){
        string ss;
        cin >> ss;
        s.push_back(ss);
    }

    int result = longestSub(s , size , k);
    cout << "Result : " << result << " ";

    return 0;
}