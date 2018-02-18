/* Problem 1.6 from "Cracking the coding interview" */
#include <string>
#include <iostream>

std::string stringCompression(std::string st) {
    std::string result;
    
    if (st.empty()) 
        return result;
    
    int i = 1;
    int count = 1;
    char currChar = st[0];
    int moreThanOne = 0;
    
    while(i < st.length()) {
        if (st[i] == currChar) {
            moreThanOne++;
            while (st[i++] == currChar) { 
                count++;   
            }
            result.push_back(currChar);
            result  = result + std::to_string(count);
            count = 1;
            currChar = st[--i]; 
        } 
        else { 
            result.push_back(currChar);
            result = result + "1";
            count = 1;
            currChar = st[i];
        }
        i++;
    }  
    
    /* check if there was really a compression. If this is not the case, return the original string */
    if (moreThanOne >= 1)
        return result;
    
    return st;
}

int main()
{
    std::string st = "aabcccccaaa";
    std::cout << stringCompression(st) << std::endl;
    return 0;
}
