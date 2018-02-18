/* Problem 1.4 from "Cracking the coding interview" */
#include <map>
#include <iostream>

using namespace std;

bool palindromePermutation(std::string st) {
    std::map<char,int> hashPalindrome;
    std::map<char,int>::iterator it;
    for (int i = 0; i < st.length(); i++) {
        st[i] = tolower(st[i]);
        if (st[i] != ' ') {
            it = hashPalindrome.find(st[i]);
            if (it != hashPalindrome.end()) {
                it->second++;    
            }
            else {
                hashPalindrome.insert(std::pair<char,int>(st[i],1));    
            }    
        }
    }
    int count = 0;
    for (it = hashPalindrome.begin(); it != hashPalindrome.end(); ++it) {
        if ((it->second % 2) != 0) {
            if (count == 0) { 
                count++;
            }
            else {
                cout << it->first << endl;
                return false;    
            }
        }
    }
    return true;
}

int main()
{
    std::string st = "Tact Coa";
    cout << palindromePermutation(st) << endl;
    return 0;
}
