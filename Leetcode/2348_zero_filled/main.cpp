#include<bits/stdc++.h>
using namespace std;

//brute force method - O(n^3)
long long zeroFilledSubarrayBruteForce(vector<int>& nums){
    long long count = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){ // Generate possible sub arrays 
                // Count continuous 0 sub arrys
                bool allZero = true;
                for(int k = i; k <= j; k++){
                    if(nums[k] != 0){
                        allZero = false;
                        break;
                    }
                }

                if(allZero){
                    count++;
                }

            }
        }
        return count;
}

//now lets do optimized way - 
long long zeroFilledSubarray(vector<int> &nums){
    long long count = 0;
    long long streak = 0;
    for(auto n : nums){
        if(n == 0){ //if the current element is 0 
            streak++;
            count += streak;
        }else{ // if not 
            streak = 0;
        }
    }
    return count;
}

int main(){
    vector<int> nums = {0,0,0};
    cout << "Result : " << zeroFilledSubarrayBruteForce(nums) << endl;

    cout << "Now lets see optimized approach " << endl;

    cout << "Optimized Result : " << zeroFilledSubarray(nums);
}