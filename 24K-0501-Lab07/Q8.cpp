#include <iostream>
#include <string>
using namespace std;

void quickSort(float price[], int orderID[], string customerName[], int left, int right) {
    if (left >= right) return;

    float pivot = price[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (price[j] < pivot) {
            float tempP = price[i];
            price[i] = price[j];
            price[j] = tempP;

            int tempID = orderID[i];
            orderID[i] = orderID[j];
            orderID[j] = tempID;

            string tempN = customerName[i];
            customerName[i] = customerName[j];
            customerName[j] = tempN;

            i++;
        }
    }

    float tempP = price[i];
    price[i] = price[right];
    price[right] = tempP;

    int tempID = orderID[i];
    orderID[i] = orderID[right];
    orderID[right] = tempID;

    string tempN = customerName[i];
    customerName[i] = customerName[right];
    customerName[right] = tempN;

    quickSort(price, orderID, customerName, left, i - 1);
    quickSort(price, orderID, customerName, i + 1, right);
}

int main() {
    int n;
    cout << "Enter number of orders: ";
    cin >> n;

    int orderID[n];
    string customerName[n];
    float totalPrice[n];

    cout << "\nEnter order details:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nOrder " << i + 1 << ":\n";
        cout << "Order ID: ";
        cin >> orderID[i];
        cout << "Customer Name: ";
        cin >> ws;
        getline(cin, customerName[i]);
        cout << "Total Price: ";
        cin >> totalPrice[i];
    }

    quickSort(totalPrice, orderID, customerName, 0, n - 1);

    cout << "\nOrders sorted by total price (ascending):\n";
    for (int i = 0; i < n; i++) {
        cout << "\nOrder ID: " << orderID[i];
        cout << "\nCustomer Name: " << customerName[i];
        cout << "\nTotal Price: " << totalPrice[i] << "\n";
    }

    return 0;
}
