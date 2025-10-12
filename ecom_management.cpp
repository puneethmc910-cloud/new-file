#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    Product(int productId, string productName, double productPrice, int productQuantity) {
        id = productId;
        name = productName;
        price = productPrice;
        quantity = productQuantity;
    }

    void displayProduct() {
        cout << "ID: " << id << " | Name: " << name << " | Price: $" << price << " | Quantity: " << quantity << endl;
    }

    int getId() { return id; }
    string getName() { return name; }
    double getPrice() { return price; }
    int getQuantity() { return quantity; }
    void setQuantity(int qty) { quantity = qty; }
};

class Order {
private:
    int orderId;
    vector<Product> products;
    double totalAmount;

public:
    Order(int id) {
        orderId = id;
        totalAmount = 0;
    }

    void addProduct(Product product, int quantity) {
        if (product.getQuantity() >= quantity) {
            products.push_back(product);
            totalAmount += product.getPrice() * quantity;
            cout << "Product added to order" << endl;
        } else {
            cout << "Insufficient stock" << endl;
        }
    }

    void displayOrder() {
        cout << "Order ID: " << orderId << endl;
        cout << "Products in order:" << endl;
        for (auto &product : products) {
            product.displayProduct();
        }
        cout << "Total Amount: $" << totalAmount << endl;
    }
};

class ECommerceSystem {
private:
    vector<Product> products;
    vector<Order> orders;
    int nextOrderId;

public:
    ECommerceSystem() {
        nextOrderId = 1;
        initializeProducts();
    }

    void initializeProducts() {
        products.push_back(Product(1, "Laptop", 999.99, 10));
        products.push_back(Product(2, "Smartphone", 499.99, 20));
        products.push_back(Product(3, "Headphones", 79.99, 30));
    }

    void displayProducts() {
        cout << "Available Products:" << endl;
        for (auto &product : products) {
            product.displayProduct();
        }
    }

    Product* findProduct(int id) {
        for (auto &product : products) {
            if (product.getId() == id) {
                return &product;
            }
        }
        return nullptr;
    }

    void createOrder() {
        Order newOrder(nextOrderId++);
        int productId, quantity;
        char continueAdding;

        do {
            displayProducts();
            cout << "Enter product ID: ";
            cin >> productId;
            cout << "Enter quantity: ";
            cin >> quantity;

            Product* product = findProduct(productId);
            if (product != nullptr) {
                newOrder.addProduct(*product, quantity);
            } else {
                cout << "Product not found!" << endl;
            }

            cout << "Add another product? (y/n): ";
            cin >> continueAdding;
        } while (continueAdding == 'y' || continueAdding == 'Y');

        orders.push_back(newOrder);
        newOrder.displayOrder();
    }
};

int main() {
    ECommerceSystem ecommerce;
    int choice;

    while (true) {
        cout << "\n1. View Products\n2. Create Order\n3. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ecommerce.displayProducts();
                break;
            case 2:
                ecommerce.createOrder();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}