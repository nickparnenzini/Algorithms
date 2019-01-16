// Kadane's algorithm
// Algorithm : O(n) time, O(1) space

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main() {
	int T;
	std::cin >> T;
	for (int k = 0; k < T; k++) {
	    int N;
	    std::cin >> N;
	    std::vector<int> arr(N,0);
	    for (int i = 0; i < N; i++) {
	        std::cin >> arr[i];
	    }
	    int max_overall = arr[0];
	    int current_max = arr[0];
	    for (int j = 1; j < arr.size(); j++) {
	        current_max = std::max(current_max+arr[j],arr[j]);
	        max_overall = std::max(max_overall,current_max);
	    }
	    std::cout << max_overall << std::endl;
	}
	return 0;
}
