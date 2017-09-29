#include <vector>

std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>>& a) {
    int n = a[0].size();
    int j = 0;
    int shift = n-1;
    int maxSize = n;
    
    while ( maxSize > 1 ) {
        for ( int i = j; i < shift; i++ ) {
            int tmp = a[j][i];
            a[j][i] = a[shift-i+j][j];
            a[shift-i+j][j] = a[shift][shift-i+j];
            a[shift][shift-i+j] = a[i][shift];
            a[i][shift] = tmp;
        }       
        j++;
        shift--;
        maxSize -= 2;
    }
    return a;
}