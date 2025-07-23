/*
Question 4 - 
Count vowels/consonants
*/

#include <bits/stdc++.h>
using namespace std;

void countVowelsConsonants(string s) {
    int vowelCount = 0;
    int consonantsCount = 0;
    for (int i = 0; i < s.length(); ++i) {
        char ch = tolower(s[i]);  // Convert to lowercase
        if (isalpha(ch)) {        // Check only alphabetic characters
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;
            } else {
                consonantsCount++;
            }
        }
    }
    cout << "vowels count : " << vowelCount << endl;
    cout << "consonants count : " << consonantsCount << endl;
}

int main() {
    string s;
    getline(cin, s);
    countVowelsConsonants(s);
}
