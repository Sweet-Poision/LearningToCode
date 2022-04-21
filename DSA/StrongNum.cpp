// Program to check if the number is strong number or not

#include <iostream>
using namespace std;

int dp[10] = {0};

int factorial(int num) {
    if(dp[num] != 0) return dp[num];
    if(num == 0){
        dp[num] = 1;
        return 1;
    } 
    dp[num] = num * factorial(num-1);
    return dp[num];
}

bool isStrong(int num) {
    int temp = num, sum {0};
    for(; num; num/=10) 
        sum += factorial(num%10);
    return (sum == temp)?true:false;
}

int main() {
    int num;
    cout << "Give a number to check if it is a Strong Number: ";
    cin >> num;
    if(isStrong(num)) cout << num << " is Strong Number.\n";
    else cout << num << " is not a Strong Number.\n";  
}
