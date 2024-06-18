#include <iostream>
#include<sstream>

using namespace std;

bool isSpecial(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    string input;
    getline(cin, input);

    ostringstream oss;

    char previousChar = 0;

    for (int i = 0; i < input.size(); i++) {
        char curr = input[i];
        if (isSpecial(curr)) {
            previousChar = curr;
            oss << curr;
        }
        else {
            if (previousChar != curr) {
                previousChar = curr;
                oss << curr;
            }
        }
    }


    cout << oss.str() << endl;
}
