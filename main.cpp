#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

class Product {
public:
    std::string name;
    std::string category;
    double price;
    int stock;

    Product(std::string n, std::string c, double p, int s) : name(n), category(c), price(p), stock(s) {}
};

int main() {
    std::vector<Product> products = {
        Product("Product A", "Electronics", 150.0, 5),
        Product("Product B", "Clothing", 50.0, 20),
        Product("Product C", "Electronics", 100.0, 3),
        Product("Product D", "Home", 200.0, 2),
        Product("Product E", "Clothing", 30.0, 15)
    };

    std::sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
        return a.price < b.price;
    });

    for (const auto& product : products) {
        std::cout << product.name << " - " << product.price << " USD\n";
    }

    std::vector<Product> lowStockProducts;
    std::copy_if(products.begin(), products.end(), std::back_inserter(lowStockProducts), [](const Product& p) {
        return p.stock < 10;
    });

    for (const auto& product : lowStockProducts) {
        std::cout << product.name << " - " << product.stock << " units\n";
    }

    double totalPrice = 0.0;
    int count = 0;
    std::for_each(products.begin(), products.end(), [&totalPrice, &count](const Product& p) {
        if (p.category == "Electronics") {
            totalPrice += p.price;
            count++;
        }
    });

    double avgPrice = (count > 0) ? totalPrice / count : 0.0;
    std::cout << "\nAverage price of Electronics: " << avgPrice << " USD\n";

    double totalStockValue = std::accumulate(products.begin(), products.end(), 0.0, [](double sum, const Product& p) {
        return sum + (p.price * p.stock);
    });

    std::cout << "\nTotal value of all products in stock: " << totalStockValue << " USD\n";

    return 0;
}
