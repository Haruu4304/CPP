/*
Problem statement : range product query :
time complexity : O(q);
*/

#include<bits/stdc++.h>
using namespace std;

int M = 1e9 + 7; // 10^9 + 7

vector<int> productQueries(int n, vector<vector<int>>& queries){
    vector<int> powers; //create one vector powers 
    vector<int> result;
    for(int i=0; i<32; i++){
        if((n & (1 << i)) != 0){ //check each 2^0 and so on and take those only who having 1
            powers.push_back(1 << i);
        }
    }

    //now get the product by looping queries : 
    for(auto query : queries){
        int start = query[0];
        int end = query[1];
        long product = 1;
        for(int i=start; i<=end; i++){
            product = (product * powers[i]) % M;
        }
        result.push_back(product);
    }
    return result;
}

int main(){
    int n = 15;
    vector<vector<int>> queries= { {0,1}, {2,2}, {0,3} };

    vector<int> result = productQueries(n , queries);

    cout << "Result : " << endl;
    for(auto &val : result){
        cout << val << endl;
    }
}