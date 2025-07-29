/*
Problem statement - 
First negative value in every window of size k 
give the ans in vector
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> FindFirstNegative(vector<int> &arr , int size , int k){
    int i = 0, j = 0;
    list<int> r;           // stores negative values in current window
    vector<int> ans;       // final result

    while(j < size){
        // step 1 - calculation
        if(arr[j] < 0){
            r.push_back(arr[j]);
        }

        // step 2 - check window size
        if(j - i + 1 < k){
            j++;
        }
        else if(j - i + 1 == k){
            // step 3 - store answer
            if(r.size() == 0){
                ans.push_back(0);
            }
            else{
                ans.push_back(r.front());
                if(arr[i] == r.front()){
                    r.pop_front();
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    vector<int> arr;
    int n , k;
    cout << "Enter n and k: ";
    cin >> n >> k;
    cout << "Enter the elements in vector: ";
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    vector<int> result = FindFirstNegative(arr , n , k);

    cout << "Result: ";
    for(auto value : result){
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
