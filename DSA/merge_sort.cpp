#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

void generate_random_numbers(int arr[], int n, int rand_lim) {
    for(int i=0; i<n; i++) {
        arr[i] = rand() % rand_lim;
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int p, int q, int r) { 
    int n1 = q - p + 2;
    int n2 = r - q + 1;
    int l[n1], ri[n2];
    for(int i = 0; i < n1 - 1; i++) {
        l[i] = arr[p + i];
    }
    for(int i = 0; i < n2 - 1; i++) {
        ri[i] = arr[q + 1 + i]; 
    }
    l[n1-1] = __INT_MAX__;
    ri[n2-1] = __INT_MAX__;
    for(int k = p, i = 0, j = 0; k <= r; k++) {
        if(l[i] <= ri[j]) 
            arr[k] = l[i++];
        else 
            arr[k] = ri[j++];
    }
}

void merge_sort(int arr[], int p, int r) {
    if(p < r) {
        int mid = p + (r - p) / 2;
        merge_sort(arr, p, mid);
        merge_sort(arr, mid+1, r);
        merge(arr, p, mid, r);
    }
}

int main() {
    srand(time(NULL));
    int size = rand() % 100, random_limit = rand() % 10000;
    int arr[size];
    random_shuffle(arr, arr+size);
    generate_random_numbers(arr, size, random_limit);
    merge_sort(arr, 0, size-1);
    printArray(arr, size);
    return 0;
}