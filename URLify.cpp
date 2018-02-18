/* Problem 1.3 from "Cracking the coding interview" */
#include <iostream>

using namespace std;

void URLify(std::string& st) {
    /* indexShift is the new position of shifted characters */
    int indexShift = st.length()-1;
    int indexEnd = st.length()-1;
    int indexBegin = st.length()-1;
    
    while(st[indexEnd] == ' ') {indexEnd--;}
    
    indexBegin = indexEnd;
    
    while(indexBegin > 0) {
        while( (indexBegin>0) && (st[indexBegin] != ' ')) { indexBegin--;}
            
        if (st[indexBegin] == ' ' || indexBegin== 0) {
            for (int i = indexEnd; i>indexBegin; i--) {
                st[indexShift--] = st[i];
            }
            if (indexBegin > 0) {
                st[indexShift--] = '0'; 
                st[indexShift--] = '2'; 
                st[indexShift--] = '%'; 
                indexEnd = (indexBegin > 0) ? indexBegin-1 : 0;
                indexBegin = indexEnd;
            }
        }
    }
}

int main()
{
    std::string st = "Mr  John Smith      ";
    URLify(st);
    cout << st << endl;
    return 0;
}
