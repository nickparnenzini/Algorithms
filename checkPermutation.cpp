/* Problem 1.2 from "Cracking the coding interview" */
#include <algorithm>
#include <iostream>

using namespace std;

bool checkPermutation(std::string st1, std::string st2) {
    if (st1.length() != st2.length())
        return false;
        
    std::sort(st1.begin(),st1.end());
    std::sort(st2.begin(),st2.end());
    
    for (int i = 0; i < st1.length(); i++) {
        if (st1[i] != st2[i])
            return false;
    }
    return true;
}

int main()
{
    std::string st1 = "oll";
    std::string st2 = "lol";
    cout << checkPermutation(st1,st2) << endl;
    return 0;
}
