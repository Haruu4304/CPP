#include <bits/stdc++.h>
using namespace std;

//time complexity for this -> O(n^4)
int BruteForce(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;

    // generate all subarrays
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            
            // make a subarray nums[i..j]
            vector<int> sub;
            for (int k = i; k <= j; k++) {
                sub.push_back(nums[k]);
            }

            // try deleting each element from this subarray
            for (int del = 0; del < sub.size(); del++) {
                vector<int> temp = sub;
                temp.erase(temp.begin() + del);

                // count longest consecutive ones in temp
                int curr = 0, onesCount = 0;
                for (int x : temp) {
                    if (x == 1) {
                        curr++;
                        onesCount = max(onesCount, curr);
                    } else {
                        curr = 0;
                    }
                }

                ans = max(ans, onesCount);
            }
        }
    }

    return ans;
}

//tc -> O(n)
int longestSubarry(vector<int> &nums){
    int i=0 , j=0;
    int maxOnes = 0;
    int n = nums.size();
    int zeroCount = 0 , onesCount = 0;

    while(j < n){//while my nums arrays do not get fully run
        if(nums[j] == 0){
            zeroCount++;
        }

        while(zeroCount > 1){
            if(nums[i] == 0){ //if it contents 0 value then remove it
                zeroCount--;
            }
            i++;
        }
        //here j-i+1 means window size - 
        //why here only j-i because we have to delelte atlease one even no zero;s are present 
        maxOnes = max(maxOnes , j-i);
        j++;
    }

    return maxOnes;
}

int main() {
    vector<int> nums = {1, 1, 1};
    cout << longestSubarry(nums);
}
