#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the majority element in an array using Divide-and-Conquer
int DCME(vector<int>& arr, int left, int right) {
    if (left == right) {
        return arr[left];
    }

    int mid = (left + right) / 2;
    int leftME = DCME(arr, left, mid);
    int rightME = DCME(arr, mid + 1, right);

    if (leftME == rightME) {
        return leftME;
    }

    int leftCount = count(arr.begin(), arr.end(), leftME);
    int rightCount = count(arr.begin(), arr.end(), rightME);

    return (leftCount > rightCount) ? leftME : rightME;
}

// Function to find the majority element in an array
int findMajority(vector<int>& arr) {
    int n = arr.size();
    return DCME(arr, 0, n - 1);
}

int main() {
    vector<int> arr = {3, 5, 3, 3, 4, 3};
    int result = findMajority(arr);
    cout << "Majority element in the array is " << result << endl;

    return 0;
}