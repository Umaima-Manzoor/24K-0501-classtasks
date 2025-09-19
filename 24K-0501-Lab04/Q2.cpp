#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void BubbleSort(int arr[], int n) {
    int count = 0;
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

    cout << "Sorted Array By Bubble Sort: "<<endl;
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons performed in bubble sort: "<< count<<endl<<endl;
    
}

void InsertionSort(int arr[], int n) {
    int count =0;
    for (int i=0; i<n; i++) {
        int key = arr[i];
        int j = i-1;
        
        while (j>=0 && arr[j]>key) {
            count++;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    cout << "Sorted Array By Insertion Sort: "<<endl;
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons performed in Insertion sort: "<< count<<endl<<endl;
}

void SelectionSort(int arr[], int n) {
    int count = 0;
    for (int i=0; i<n-1; i++) {
        int min_index = i;
        
        for (int j=i+1; j<n; j++) {
            if (arr[j]< arr[min_index]) {
                count++;
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    cout << "Sorted Array By Selection Sort: "<<endl;
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons performed in Selection sort: "<< count<<endl<<endl;
}

void ShellSort(int arr[], int n) {
    int count =0;
    for (int gap=n/2; gap>0; gap/= 2) {
        for (int j=gap; j<n; j++) {
            int temp = arr[j];
            int res= j;

            while ( res>=gap && arr[res-gap]>temp) {
                count++;
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
    cout << endl;
    cout << "Number of comparisons performed in Shell sort: "<< count<<endl<<endl;

}


int main() {
    srand(time(0)); 
    int* arr = new int[20];

    for (int i=0; i<20; i++) {
        arr[i] = rand() % 100 + 1;
    }

    cout << "Initial Array: "<<endl;
    for (int i=0; i<20; i++) {
        cout << arr[i] << " ";
    }
    cout << endl<<endl;
    

    int* copyArr = new int[20];
    for (int i=0; i<20; i++) {
        copyArr[i] = arr[i];
    }
    
    BubbleSort(copyArr, 20);
    
    for (int i=0; i<20; i++) {
        copyArr[i] = arr[i];
    }
    
    InsertionSort(copyArr, 20);
    
    for (int i=0; i<20; i++) {
        copyArr[i] = arr[i];
    }
    
    SelectionSort(copyArr, 20);
    
    for (int i=0; i<20; i++) {
        copyArr[i] = arr[i];
    }

    ShellSort(copyArr, 20);





    int *temp = new int[100];
    
    for (int i=0; i<100; i++) {
        temp[i] = arr[i];
    }

    for (int i=20; i<100;i++) {
        temp[i] = rand() %100 + 1;
    }

    delete[] arr;

    arr = temp;

    cout << "Initial Array (Size=100): "<<endl;
    for (int i=0; i<100; i++) {
        cout << arr[i] << " ";
    }
    cout << endl<<endl;

    delete[] copyArr;

    copyArr = new int [100];

    for (int i=0; i<100; i++) {
        copyArr[i] = arr[i];
    }
    
    BubbleSort(copyArr, 100);
    
    for (int i=0; i<100; i++) {
        copyArr[i] = arr[i];
    }
    
    InsertionSort(copyArr, 100);
    
    for (int i=0; i<100; i++) {
        copyArr[i] = arr[i];
    }
    
    SelectionSort(copyArr, 100);
    
    for (int i=0; i<100; i++) {
        copyArr[i] = arr[i];
    }

    ShellSort(copyArr, 100);




    return 0;
}
