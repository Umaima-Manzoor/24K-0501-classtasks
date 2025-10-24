#include <iostream>
#include <string>
using namespace std;

void merge(string names[], int times[], int left, int mid, int right) {
    int n1 = mid - left+1;
    int n2 = right - mid;

    int LeftTime[n1], RightTime[n2];
    string LeftName[n1], RightName[n2];

    for (int i=0; i<n1; i++) {
        LeftTime[i]= times[left + i];
        LeftName[i] = names[left + i];
    }
    for (int j=0; j<n2; j++) {
        RightTime[j] = times[mid + 1 + j];
        RightName[j] = names[mid + 1 + j];
    }

    int i=0, j=0, k=left;
    while (i <n1 && j< n2) {
        if (LeftTime[i] <= RightTime[j]) {
            times[k] = LeftTime[i];
            names[k] = LeftName[i];
            i++;
        } else {
            times[k] = RightTime[j];
            names[k] = RightName[j];
            j++;
        }
        k++;
    }

    while (i<n1) {
        times[k] = LeftTime[i];
        names[k] = LeftName[i];
        i++;
        k++;
    }
    while (j < n2) {
        times[k] = RightTime[j];
        names[k] = RightName[j];
        j++;
        k++;
    }
}

void mergeSort(string names[], int times[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(names, times, left, mid);
        mergeSort(names, times, mid + 1, right);
        merge(names, times, left, mid, right);
    }
}

int main() {
    string names[10];
    int times[10];
    int n = 10;

    cout << "Enter names and finish times (in seconds)"<<endl;
    for (int i = 0; i < n; i++) {
        cout << "Runner " << i + 1 << " name: ";
        cin >> names[i];
        cout << "Finish time (in seconds): ";
        cin >> times[i];
    }

    mergeSort(names, times, 0, n-1);

    cout << "\nTop 5 Fastest Runners:"<<endl;
    cout << "---------------------------------------------------------------"<<endl;
    cout << "Rank\tName\tTime(seconds)"<<endl;
    cout << "---------------------------------------------------------------"<<endl;

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << "\t " << names[i] << "\t" << times[i] << endl;
    }

    return 0;
}
