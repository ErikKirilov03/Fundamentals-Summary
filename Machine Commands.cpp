#include <iostream>
#include<list>
#include<sstream>

using namespace std;

int main()
{
    list<int> numbers;
    string command;

    while (cin >> command) {
        istringstream istr(command);
        int num;

        if (istr >> num) {
            numbers.push_back(num);
        }
        else if (command == "end") {
            break;
        }
        else if (command == "discard") {
            numbers.pop_back();
        }
        else {
            int b = numbers.back();
            numbers.pop_back();

            int a = numbers.back();
            numbers.pop_back();

            if (command == "sum") {
                numbers.push_back(a + b);
            }
            else if (command == "subtract") {
                numbers.push_back(b - a);
            }
            else { // command -> concat
                ostringstream ostr;
                ostr << a << b;

                istringstream istr(ostr.str());
                istr >> num;
                numbers.push_back(num);
            }
        }
    }

    for (list<int>::iterator i = numbers.begin(); i != numbers.end(); i++) {
        cout << *i;
    }
}