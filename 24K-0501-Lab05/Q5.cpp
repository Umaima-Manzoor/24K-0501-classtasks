#include <iostream>
using namespace std;


int sumDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumDigits(n / 10);
}


int nestedSum(int n, int step) {
    if (n >= 0 && n <= 9)  
        return n;

    int sum = sumDigits(n);
    

    cout << "Step " << step << ": ";
    int temp = n;
    bool first = true;
    while (temp > 0) {
        if (first == false) {
            cout << " + "; }
            
        cout << temp % 10;
        temp /= 10;
        first = false;
    }

    cout << " = " << sum << endl;
    step++;

    return nestedSum(sum, step);  
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int step = 1;
    int result = nestedSum(num, step);

    cout << "Output: " << result << endl;

    return 0;
}
