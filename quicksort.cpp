/* A possible implementation of quicksort in C++ */

#include <vector>
#include <iostream>

void exchange(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void quicksort(std::vector<int>& arr, int inf, int sup) {
    int pivot = arr[(inf+sup)/2];
    int h = inf;
    int k = sup;
    while (h < k) {
        while (arr[h] < pivot) {h++;}
        while (arr[k] > pivot) {k--;}
        if (h > k)
            return;
            
        exchange(arr[h], arr[k]);
        h++; 
        k--;
    }
    if (k > inf) 
        quicksort(arr,inf,k);
        
    if (h < sup)
        quicksort(arr,h,sup);
}

int main()
{
    std::vector<int> arr = {8,1,6,4,3};  
    quicksort(arr,0,arr.size()-1);
    
    for (auto i: arr) {
        std::cout << i << " ";
    }
    
    return 0;
}
