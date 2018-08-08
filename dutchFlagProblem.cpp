#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void dutchFlagProblem(vector<int>& A, int index) {
    int pivot = A[A.size()/2];
    int low = 0;
    int high = A.size() - 1;
    while (low < high) {
      while(A[low] <= pivot) {low++;}
      while (A[high] > pivot) {high--;}
      if ( low > high) {
        break;
      }
      std::swap(A[low], A[high]);
      low++;
      high--;
    } 
}

int main()
{
    std::vector<int> A = {3,1,2,0,2,1,1};
    dutchFlagProblem(A, 3);
    for (auto i : A) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
