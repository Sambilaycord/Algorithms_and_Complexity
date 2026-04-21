#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

bool wordBreak(string s, unordered_set<string>& wordDict) {
    int n = s.length();
    vector<bool> dp(n + 1, false);

    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    string s = "applepie";
    unordered_set<string> wordDict = {"apple", "pear", "pie"};

    cout << "Dictionary: ";
    for (const string& word : wordDict) {
        cout << word << " ";
    }
    cout << "\nString: " << s << "\nResult: " << (wordBreak(s, wordDict) ? "True" : "False");
    if (wordBreak(s, wordDict)) {
        cout << " (\"apple pie\")";
    }
    cout << endl;

    return 0;
}