/* Solution O(n) time and O(1) extra space */
/* Delete duplicates from a given array */

#include <vector>
#include <iostream>

using namespace std;

void deleteDuplicates(vector<int>& arr) {
    int write_index = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[write_index-1] != arr[i]) {
            arr[write_index++] = arr[i];
        }
    }
    for (int i = write_index; i < arr.size(); i++) {
        arr[i] = 0;
    }
}

int main()
{
    vector<int> arr = {2,3,5,5,5,7,7,11,11,11,13,13};
    deleteDuplicates(arr);
    for (auto i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
