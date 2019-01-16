/*
Stickler the thief wants to loot money from a society having n houses in a single line. 
He is a weird person and follows a certain rule when looting the houses. 
According to the rule, he will never loot two consecutive houses. 
At the same time, he wants to maximize the amount he loots. 
The thief knows which house has what amount of money but is 
unable to come up with an optimal looting strategy. 
He asks for your help to find the maximum money he can get 
if he strictly follows the rule. Each house has a[i] amount of money present in it.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() { 
	int T;
	std::cin >> T;
	for (int k = 0; k < T; k++) {
	    int N;
	    std::cin >> N;
	    std::vector<int> arr(N,0);
	    std::vector<int> dp(N,0);
	    for (int i = 0; i < N; i++) {
	        std::cin >> arr[i];
	    }
	    dp[0] = arr[0];
	    dp[1] = arr[1] > arr[0] ? arr[1] : arr[0];
	    for (int j = 2; j < N; j++) {
	        dp[j] = std::max(dp[j-1],dp[j-2]+arr[j]);
	    }
	    int max_overall = std::max(dp[N-1],dp[N-2]);
	    std::cout << max_overall << std::endl;
	}
	return 0;
}
