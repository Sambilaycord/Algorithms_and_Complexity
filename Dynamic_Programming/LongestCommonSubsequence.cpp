#include <iostream>
#include <vector>
#include <string>

using namespace std;

string findLCS(string X, string Y)
{
    int m = X.length();
    int n = Y.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Initialization
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    // Table Construction
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Finding the LCS
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main()
{
    string X = "AGTGAT";
    string Y = "TGATCA";

    cout << "Sequences: X = " << X << " Y = " << Y << endl;
    string lcs = findLCS(X, Y);
    cout << "Length of LCS: " << lcs.length() << " (LCS: " << lcs << ")" << endl;

    return 0;
}