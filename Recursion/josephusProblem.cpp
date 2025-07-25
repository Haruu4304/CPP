#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &v, int k , int index , int &ans){
    if(v.size() == 1){
        ans = v[0];
        return;
    }

    index = (index + k) % v.size();
    v.erase(v.begin() + index);
    solve(v , k , index , ans);
}

int main(){
    int n , k;
    cin >> n >> k;

    vector<int> v;
    for(int i = 0; i < n; i++){
        v.push_back(i);
    }

    int index = 0;
    int ans = -1;
    k = k - 1;

    solve(v , k , index , ans);
    cout << "result : " << ans+1;
}
