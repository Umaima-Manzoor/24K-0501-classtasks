#include <iostream>
#include <string>
using namespace std;

void merge(string names[], int id[], int salary[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int LeftSalary[n1], RightSalary[n2];
    int LeftID[n1], RightID[n2];
    string LeftName[n1], RightName[n2];

    for (int i = 0; i < n1; i++) {
        LeftID[i] = id[left + i];
        LeftName[i] = names[left + i];
        LeftSalary[i] = salary[left + i];
    }
    for (int j = 0; j < n2; j++) {
        RightID[j] = id[mid + 1 + j];
        RightName[j] = names[mid + 1 + j];
        RightSalary[j] = salary[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (LeftSalary[i] >= RightSalary[j]) {
            salary[k] = LeftSalary[i];
            id[k] = LeftID[i];
            names[k] = LeftName[i];
            i++;
        } else {
            salary[k] = RightSalary[j];
            id[k] = RightID[j];
            names[k] = RightName[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        salary[k] = LeftSalary[i];
        id[k] = LeftID[i];
        names[k] = LeftName[i];
        i++;
        k++;
    }
    while (j < n2) {
        salary[k] = RightSalary[j];
        id[k] = RightID[j];
        names[k] = RightName[j];
        j++;
        k++;
    }
}

void mergeSort(string names[], int id[], int salary[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(names, id, salary, left, mid);
        mergeSort(names, id, salary, mid + 1, right);
        merge(names, id, salary, left, mid, right);
    }
}

int main() {
    string names[12] = {"Moiz", "Raza", "Zahid", "Shama", "Sara", "Zohaib", "Kinza", "Yasir", "Sana", "Ali", "Laila", "Saba"};
    int ids[12] = {122, 10, 345, 100, 123, 477, 323, 156, 211, 191, 990, 121};
    int salary[12] = {39000, 84000, 54000, 24000, 12000, 49000, 80000, 47000, 63000, 56000, 28000, 32000};
    int n = 12;

    mergeSort(names, ids, salary, 0, n - 1);

    cout << "\nAll Employees (Sorted by Salary in Descending Order):\n";
    cout << "---------------------------------------------------------------\n";
    cout << "ID\tName\tSalary\n";
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << ids[i] << "\t" << names[i] << "\t" << salary[i] << endl;
    }

    cout << "\nTop 3 Highest Paid Employees:\n";
    cout << "---------------------------------------------------------------\n";
    cout << "Rank\tID\tName\tSalary\n";
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "\t" << ids[i] << "\t" << names[i] << "\t" << salary[i] << endl;
    }

    return 0;
}
