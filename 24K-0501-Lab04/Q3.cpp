#include <iostream>
using namespace std;

int main() {
    int arr[5];
    int n=5;
    cout << "Enter 5 elements: "<<endl;
    for (int i=0; i<n; i++) {
        cout << "Element "<< i+1<<": ";
        cin >> arr[i];
    }
    
    cout << "Array Before Sorting: "<<endl;
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    for (int gap=n/2; gap>0; gap/= 2) {
        for (int j=gap; j<n; j++) {
            int temp = arr[j];
            int res= j;

            while ( res>=gap && arr[res-gap]>temp) {

                arr[res] = arr[res-gap];
                res -= gap;
                
            }
            arr[res] = temp;
    }

}
    cout << "Sorted Array By Shell Sort: "<<endl;
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }




    
    return 0;
}
