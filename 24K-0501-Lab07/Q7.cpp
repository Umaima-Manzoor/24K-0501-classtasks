#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

void countSort(int arr[], int studentID[], int n, int exp) {
    int output[50];
    int outputID[50];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        outputID[count[index] - 1] = studentID[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
        studentID[i] = outputID[i];
    }
}

void radixsort(int arr[], int studentID[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, studentID, n, exp);
}

int main() {
    int arr[50];
    int studentID[50];
    int n = 50;

    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101;
        studentID[i] = i + 1;
    }

    cout << "Generated Scores:\n";
    for (int i = 0; i < n; i++)
        cout << "Student " << studentID[i] << ": " << arr[i] << "\n";

    radixsort(arr, studentID, n);

    cout << "\nScores sorted in ascending order with ranks of each student (highest score = Rank 1 and lowest score is Rank 50):\n";
    for (int i = 0; i < n; i++) {
        cout << "Rank " << n-i << " -> Student " << studentID[i]
             << " (Score: " << arr[i] << ")\n";
    }

    return 0;
}
