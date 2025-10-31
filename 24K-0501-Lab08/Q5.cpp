#include <iostream>
using namespace std;


class Node {
public:
    int productID;
    int quantity;
    Node* left;
    Node* right;

    Node(int id, int qty) {
        productID = id;
        quantity = qty;
        left = NULL;
        right = NULL;
    }
};


class Tree {
public:
    Node* root;

    Tree() {
        root = NULL;
    }
    
    Node* insert(Node* node, int id, int qty) {
        if (node == NULL) {
            return new Node(id, qty);
        }

        if (id < node->productID) {
            node->left = insert(node->left, id, qty);
        } else if (id > node->productID) {
            node->right = insert(node->right, id, qty);
        } else {
            
            node->quantity = qty;
        }
        return node;
    }

    
    Node* search(Node* node, int id) {
        if (node == NULL || node->productID == id) {
            return node;
        }
        if (id < node->productID) {
            return search(node->left, id);
        } else {
            return search(node->right, id);
        }
    }

    
    void findMaxQuantity(Node* node, Node*& maxNode) {
        if (node == NULL) return;

        if (maxNode == NULL || node->quantity > maxNode->quantity) {
            maxNode = node;
        }

        findMaxQuantity(node->left, maxNode);
        findMaxQuantity(node->right, maxNode);
    }

    
    void displayProducts(Node* node) {
        if (node == NULL) return;
        displayProducts(node->left);
        cout << "Product ID: " << node->productID << ", Quantity: " << node->quantity << endl;
        displayProducts(node->right); 
    }

    
    void insertProduct(int id, int qty) {
        root = insert(root, id, qty);
        cout << "Product " << id << " inserted/updated successfully." << endl;
    }

    void searchProduct(int id) {
        Node* res = search(root, id);
        if (res != NULL) {
            cout << "Product ID: " << res->productID << ", Quantity: " << res->quantity << endl;
        } else {
            cout << "Product ID " << id << " not found." << endl;
        }
    }

    void maxQuantityProduct() {
        Node* maxNode = NULL;
        findMaxQuantity(root, maxNode);
        if (maxNode != NULL) {
            cout << "Product with highest quantity: ID " << maxNode->productID
                 << ", Quantity " << maxNode->quantity << endl;
        } else {
            cout << "No products in the system." << endl;
        }
    }

    void displayAllProducts() {
        if (root == NULL) {
            cout << "No products in the system." << endl;
            return;
        }
        cout << "\n--- All Products (sorted by Product ID) ---" << endl;
        displayProducts(root);
    }
};

int main() {
    Tree tree;
    int choice, id, qty;

    do {
        cout << "\n--- Product Management Menu ---" << endl;
        cout << "1. Insert/Update Product" << endl;
        cout << "2. Search Product by ID" << endl;
        cout << "3. Find Product with Highest Quantity" << endl;
        cout << "4. Display All Products" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Product ID: ";
                cin >> id;
                cout << "Enter Quantity: ";
                cin >> qty;
                tree.insertProduct(id, qty);
                break;
            case 2:
                cout << "Enter Product ID to search: ";
                cin >> id;
                tree.searchProduct(id);
                break;
            case 3:
                tree.maxQuantityProduct();
                break;
            case 4:
                tree.displayAllProducts();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
