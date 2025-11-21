#include <iostream>
#include <string>
using namespace std;
class Product {
private:
    string name;
    double price;
    string description;
    bool available;
public:
    Product(string n = "", double p = 0.0, string desc = "", bool avail = false) 
        : name(n), price(p), description(desc), available(avail) {}
    string getName() const { return name; }
    double getPrice() const { return price; }
    string getDescription() const { return description; }
    bool isAvailable() const { return available; }
    void setName(string n) { name = n; }
    void setPrice(double p) { price = p; }
    void setDescription(string desc) { description = desc; }
    void setAvailable(bool avail) { available = avail; }
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Description: " << description << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
        cout << "------------------------" << endl;
    }
};
void swap(Product& a, Product& b) {
    Product temp = a;
    a = b;
    b = temp;
}
int partition(Product arr[], int low, int high) {
    double pivot = arr[high].getPrice();
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].getPrice() <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int partitionMiddle(Product arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    double pivot = arr[mid].getPrice();
    swap(arr[mid], arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].getPrice() <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSortMiddlePivot(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partitionMiddle(arr, low, high);
        quickSortMiddlePivot(arr, low, pi - 1);
        quickSortMiddlePivot(arr, pi + 1, high);
    }
}
void displayProducts(Product products[], int size) {
    cout << "\n=== PRODUCT LIST ===" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Product " << (i + 1) << ":" << endl;
        products[i].display();
    }
}
void displaySortedByPrice(Product products[], int size) {
    cout << "\n=== PRODUCTS SORTED BY PRICE (Ascending Order) ===" << endl;
    for (int i = 0; i < size; i++) {
        cout << (i + 1) << ". " << products[i].getName() 
             << " - $" << products[i].getPrice() 
             << " (" << (products[i].isAvailable() ? "Available" : "Out of Stock") << ")" << endl;
    }
}
int main() {
    const int NUM_PRODUCTS = 3;
    Product products[NUM_PRODUCTS];
    products[0] = Product("Product 1", 10.99, "This is product 1.", true);
    products[1] = Product("Product 2", 5.99, "This is product 2.", false);
    products[2] = Product("Product 3", 2.99, "This is product 3.", true);
    cout << "=== ONLINE SHOPPING PLATFORM - PRODUCT SORTING ===" << endl;
    cout << "Original Products (Unsorted):" << endl;
    displayProducts(products, NUM_PRODUCTS);
    Product productsToSort[NUM_PRODUCTS];
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        productsToSort[i] = products[i];
    }
    quickSort(productsToSort, 0, NUM_PRODUCTS - 1);
    displaySortedByPrice(productsToSort, NUM_PRODUCTS);
    cout << "\n\n=== USING MIDDLE PIVOT STRATEGY ===" << endl;
    Product productsMiddlePivot[NUM_PRODUCTS];
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        productsMiddlePivot[i] = products[i];
    }
    quickSortMiddlePivot(productsMiddlePivot, 0, NUM_PRODUCTS - 1);
    displaySortedByPrice(productsMiddlePivot, NUM_PRODUCTS);
    char addMore;
    cout << "\nWould you like to add more products? (y/n): ";
    cin >> addMore;
    if (addMore == 'y' || addMore == 'Y') {
        int additionalProducts;
        cout << "How many additional products would you like to add? ";
        cin >> additionalProducts;
        int totalProducts = NUM_PRODUCTS + additionalProducts;
        Product* allProducts = new Product[totalProducts];
        for (int i = 0; i < NUM_PRODUCTS; i++) {
            allProducts[i] = products[i];
        }
        for (int i = NUM_PRODUCTS; i < totalProducts; i++) {
            string name, description;
            double price;
            bool available;
            char availChar;
            cout << "\nEnter details for Product " << (i + 1) << ":" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Price: $";
            cin >> price;
            cout << "Description: ";
            cin.ignore();
            getline(cin, description);
            cout << "Available (y/n): ";
            cin >> availChar;
            available = (availChar == 'y' || availChar == 'Y');
            allProducts[i] = Product(name, price, description, available);
        }
        quickSort(allProducts, 0, totalProducts - 1);
        cout << "\n=== ALL PRODUCTS SORTED BY PRICE ===" << endl;
        for (int i = 0; i < totalProducts; i++) {
            cout << (i + 1) << ". " << allProducts[i].getName() 
                 << " - $" << allProducts[i].getPrice() 
                 << " (" << (allProducts[i].isAvailable() ? "Available" : "Out of Stock") << ")" << endl;
        }
        delete[] allProducts;
    }
    cout << "\nThank you for using the Online Shopping Platform!" << endl;
    return 0;
}
