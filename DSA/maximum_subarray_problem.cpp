//  using divide and conquer

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int max_sum(int arr[], int i, int l) {
    if(i == l) return arr[i];
    int mid = (i+l)/2;
    int max_sum_left = max_sum(arr, i, mid);
    int max_sum_right = max_sum(arr, mid+1, l);
    int max_l = INT_MIN, max_r = INT_MIN, sum = 0;
    for(int k = mid; k >= 0; k--) {
        sum += arr[k];
        if(sum > max_l) max_l = sum;
    }
    sum = 0;
    for(int k = mid+1; k <= l; k++) {
        sum += arr[k];
        if(sum > max_r) max_r = sum;
    }
    sum = max_l + max_r;
    return max({max_sum_left, max_sum_right, sum});
}

int main() {
    int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = max_sum(arr, 0, n-1);
    cout << sum << endl;
}