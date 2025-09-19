#include <iostream>
using namespace std;

int  interpolationSearch(int arr[], int n, int num) {
    int low =0;
    int high = n-1;

    while (low<=high && num>=arr[low] && num <= arr[high]) {
        if (low == high) {
            if (arr[low] == num) return low;
            return -1;
        }

        int pos = low + ((num-arr[low]) * (high-low))/ (arr[high] - arr[low]);
        if (arr[pos] == num) return pos;

        if (arr[pos]< num) low = pos + 1;
        else high = pos -1;
    }
    return -1;

}

int main() {
    int arr[] = {11, 12, 22, 25, 34, 64, 90};


    int val = interpolationSearch(arr, 7, 22);
    if (val == -1) {
        cout << 22 << " not found in the array"<<endl;
    }
    
    else {
        cout << 22 << " found in the array at position "<< val<<endl;
    }
    


    return 0;
}
