/* Problem 1.1 from "Cracking the coding interview" */
#include <algorithm>
#include <iostream>

using namespace std;

bool isUnique(std::string st) {
    std::sort(st.begin(),st.end());
    int i = 1;
    while (i < st.length()) {
        if (st[i]==st[i-1]) 
            return false;
            
        i++;
    }
    return true;
}

int main()
{
    std::string st = "none";
    
    cout << isUnique(st) << endl;

    return 0;
}
