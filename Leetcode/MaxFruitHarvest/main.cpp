/*

*/
#include<bits/stdc++.h>
using namespace std;

int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        vector<int> prefixSum(n);     // prefix sum of fruits
        vector<int> positions(n);     // store positions

        for(int i = 0; i < n; ++i) {
            positions[i] = fruits[i][0];
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        int maxFruit = 0;

        for(int d = 0; d <= k / 2; ++d) {
            // Case I: go left d steps, then right (k - 2d)
            int i = startPos - d;
            int j = startPos + (k - 2 * d);

            int leftPos = lower_bound(positions.begin(), positions.end(), i) - positions.begin();
            int rightPos = upper_bound(positions.begin(), positions.end(), j) - positions.begin() - 1;

            if (leftPos <= rightPos) {
                int total = prefixSum[rightPos] - (leftPos > 0 ? prefixSum[leftPos - 1] : 0);
                maxFruit = max(maxFruit, total);
            }

            // Case II: go right d steps, then left (k - 2d)
            i = startPos - (k - 2 * d);
            j = startPos + d;

            leftPos = lower_bound(positions.begin(), positions.end(), i) - positions.begin();
            rightPos = upper_bound(positions.begin(), positions.end(), j) - positions.begin() - 1;

            if (leftPos <= rightPos) {
                int total = prefixSum[rightPos] - (leftPos > 0 ? prefixSum[leftPos - 1] : 0);
                maxFruit = max(maxFruit, total);
            }
        }

        return maxFruit;
    }

int main() {
    vector<vector<int>> fruits;
    int n;
    cin >> n; // number of fruits
    for(int i = 0; i < n; ++i) {
        int pos, amt;
        cin >> pos >> amt;
        fruits.push_back({pos, amt});
    }

    int startPos, k;
    cin >> startPos >> k;
    int result = maxTotalFruits(fruits, startPos , k);
    cout << "Result is : " << result << endl;

    return 0;
}