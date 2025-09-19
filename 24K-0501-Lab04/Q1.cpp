#include <iostream>
using namespace std;



int main() {
    int arr[] = {64, 32, 25, 12, 22, 11, 90};
     int n = sizeof(arr)/sizeof(arr[0]);
     int count =0;

    cout << "Initial Array: "<<endl;
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl<<endl;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-1; j++) {
            if ( arr[j] > arr[j+1]) {
                count++;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    cout << "Sorted Array: "<<endl;
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl<<endl;
    cout << "Number of comparisons performed: "<< count;

    return 0;
}
