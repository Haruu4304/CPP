/*
Maximum of all subarray of size k :
from all the subarray which lie in slide k give me max element - 
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> MaxElements(vector<int> arr , int size , int k){
    int i=0, j=0;
    list<int> ll;
    vector<int> ans;
    while(j<size){
        while(!ll.empty() && ll.back() < arr[j]){
            ll.pop_back();
        }
        ll.push_back(arr[j]);
        if(j-i+1 < k){
            j++;
        }
        else if(j-i+1 == k){
            ans.push_back(ll.front());
            //to slide window
            if(arr[i] == ll.front()){
                ll.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    vector<int> s;
    vector<int> result;
    int n , k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        s.push_back(x);
    }
    result = MaxElements(s , n , k);

    cout << "Result : " << endl;
    for(int value : result){
        cout << value << endl;
    }
}