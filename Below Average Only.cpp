#include <iostream>
#include<vector>

using namespace std;

int main()
{
    int N;
    int average = 0;
    cin >> N;

    vector<int> numbers;
    numbers.reserve(N);

    for (int count = 0; count < N; count++) {
        int num;
        cin >> num;
        numbers.push_back(num);
        average += num;
    }

    average /= N;

    for (vector<int>::iterator i = numbers.begin(); i != numbers.end();) {
        if (*i > average) {
            i = numbers.erase(i);
        }
        else {
            i++;
        }
    }

    int oddSum = 0;
    int evenSum = 0;

    for (int i = 0; i < numbers.size(); i++) {
        if ((i % 2) != 0) {
            oddSum += numbers[i];
        }
        else {
            evenSum += numbers[i];
        }
    }

    cout << oddSum * evenSum << endl;
}