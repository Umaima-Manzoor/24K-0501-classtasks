#include <iostream>
#include <string>
using namespace std;

void quickSort(float price[], string name[], string desc[], string avail[], int left, int right) {
    if (left >= right) return;

    float pivot = price[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (price[j] < pivot) {
            float tempP = price[i];
            price[i] = price[j];
            price[j] = tempP;

            string tempN = name[i];
            name[i] = name[j];
            name[j] = tempN;

            string tempD = desc[i];
            desc[i] = desc[j];
            desc[j] = tempD;

            string tempA = avail[i];
            avail[i] = avail[j];
            avail[j] = tempA;

            i++;
        }
    }

    float tempP = price[i];
    price[i] = price[right];
    price[right] = tempP;

    string tempN = name[i];
    name[i] = name[right];
    name[right] = tempN;

    string tempD = desc[i];
    desc[i] = desc[right];
    desc[right] = tempD;

    string tempA = avail[i];
    avail[i] = avail[right];
    avail[right] = tempA;

    quickSort(price, name, desc, avail, left, i - 1);
    quickSort(price, name, desc, avail, i + 1, right);
}

int main() {
    string name[3], desc[3], avail[3];
    float price[3];

    cout << "Enter details for 3 products:\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nProduct " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> ws;
        getline(cin, name[i]);
        cout << "Price: ";
        cin >> price[i];
        cout << "Description: ";
        cin >> ws;
        getline(cin, desc[i]);
        cout << "Availability (in stock / out of stock): ";
        cin >> ws;
        getline(cin, avail[i]);
    }

    quickSort(price, name, desc, avail, 0, 2);

    cout << "\nProducts sorted by price:\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nName: " << name[i];
        cout << "\nPrice: " << price[i];
        cout << "\nDescription: " << desc[i];
        cout << "\nAvailability: " << avail[i] << "\n";
    }

    return 0;
}
