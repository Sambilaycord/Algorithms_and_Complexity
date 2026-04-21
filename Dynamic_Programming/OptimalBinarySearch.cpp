#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct Node {
    char key;
    Node* left;
    Node* right;
    Node(char k) : key(k), left(nullptr), right(nullptr) {}
};

int sum(vector<int>& freq, int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

Node* constructTree(vector<char>& keys, vector<int>& freq, vector<vector<vector<int>>>& root, int i, int j);

Node* optimalBST(vector<char>& keys, vector<int>& freq) {
    int n = keys.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MAX)));
    vector<vector<vector<int>>> root(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));

    for (int i = 0; i < n; i++) {
        dp[i][i][i] = freq[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len + 1; i++) {
            int j = i + len - 1;
            for (int k = i; k <= j; k++) {
                int cost = (k > i ? dp[i][k - 1][root[i][k - 1][i]] : 0) +
                           (k < j ? dp[k + 1][j][root[k + 1][j][j]] : 0) +
                           sum(freq, i, j);
                if (cost < dp[i][j][k]) {
                    dp[i][j][k] = cost;
                    root[i][j][k] = k;
                }
            }
        }
    }

    return constructTree(keys, freq, root, 0, n - 1);
}

Node* constructTree(vector<char>& keys, vector<int>& freq, vector<vector<vector<int>>>& root, int i, int j) {
    if (i > j) {
        return nullptr;
    }

    int k = root[i][j][i];
    Node* node = new Node(keys[k]);
    node->left = constructTree(keys, freq, root, i, k - 1);
    node->right = constructTree(keys, freq, root, k + 1, j);

    return node;
}

void printTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->key;
    if (root->left || root->right) {
        cout << " (";
        if (root->left) {
            cout << "left: ";
            printTree(root->left);
        }
        if (root->right) {
            if (root->left) {
                cout << ", right: ";
            } else {
                cout << "right: ";
            }
            printTree(root->right);
        }
        cout << ")";
    }
}

int main() {
    vector<char> keys = {'A', 'B', 'C', 'D'};
    vector<int> freq = {2, 3, 1, 4};

    cout << "Keys: ";
    for (char key : keys) {
        cout << key << " ";
    }
    cout << "\nFrequencies: ";
    for (int f : freq) {
        cout << f << " ";
    }

    Node* root = optimalBST(keys, freq);
    cout << "\nOptimal BST: ";
    printTree(root);
    cout << endl;

    return 0;
}