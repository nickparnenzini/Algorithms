/* Problem 1.5 from "Cracking the coding interview */
#include <map>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

bool oneAway(std::string st1, std::string st2) {
    int count = 0;
    int len = st1.length() - st2.length();
    if (abs(len)>1)
        return false;
    
    /* first check: if one string is one character longer than the other one */
    if ((st1.length() == st2.length()+1) || (st2.length() == st1.length()+1)) {
        int minLength = (st1.length() < st2.length()) ? st1.length() : st2.length();
        std::sort(st1.begin(),st1.end());
        std::sort(st2.begin(),st2.end());
        for (int i = 1; i < minLength; i++) {
            if ((st1[i] != st2[i]) && (st1[i] != st2[i-1])) {
                cout << st1[i] << endl;
                if (count == 0) {
                    count++;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
    
    /* st1 and st2 are supposed to have the same length */
    for (int i = 0; i < st1.length(); i++) {
        if (st1[i] != st2[i]) {
            if (count==0) {
                count++;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    std::string st1 = "pale";
    std::string st2 = "ple";
    cout << oneAway(st1,st2) << endl;
    return 0;
}
