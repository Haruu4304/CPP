/*
Minimum Window Substring- 
here they ask 2 type of questions - 
i) minimum window de do - 
ii) i sey us length tk ke elements return kar do - 
*/

#include<bits/stdc++.h>
using namespace std;

string minimumSubstring(string s, string t){
    int i=0, j=0;
    unordered_map<char, int> mp;
    //here we will insert charcter by char each element in map with count of pattern string
    for(char ch : t){ 
        mp[ch]++;
    }
    //count will store the unique character of map
    int count = mp.size();
    //ans to store minimum window size - 
    int minLen = INT_MAX;
    int n = s.size();
    int start = 0;
    string result = "";
    while(j < n){
        //search - if the string s charcter is present in map if yes then decrement count else move furter
        if(mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
            if(mp[s[j]] == 0){  //if any charcter count is 0 then decrement the size of count --;
                count--;
            }
        }

        //here we got that substring where our condition meets - all the pattern letters are found
         if(count == 0){
            // Shrink window by incrementing i when count == 0
            while(count == 0){
                if(mp.find(s[i]) != mp.end()){
                    // INC freq 
                    mp[s[i]]++;

                    // if char freq becomes 1 
                    if(mp[s[i]] == 1){
                        count++;
                        // calculate size of that window 
                        if(j - i + 1 < minLen){
                            start = i;
                            minLen = j - i + 1;
                        }
                    }
                }
                i++;
            }
        }
        j++;
    }
        result = s.substr(start, minLen);
    return (minLen != INT_MAX) ? result : "";
}


int main(){
    string s, t;
    cout << "enter the first string : " << endl;
    cin >> s;
    cout << "enter the pattern string : " << endl;
    cin >> t;

    string result = minimumSubstring(s, t);

    cout << "minimum substring window size : " << result << endl;
}