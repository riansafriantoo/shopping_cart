#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Item {
    string name;
    int quantity;
    int price;
};

class ShoppingCart {
private:
    vector<Item> item;
    int total_price;
public:
    ShoppingCart();
    void tambahProduk(string kodeProduk, int kuantitas);
    void removeItem(string kodeProduk);
    int getTotal();
};

ShoppingCart::ShoppingCart() {
    cout << "Creating a new shopping cart" << endl;
    total_price = 0;
}

void ShoppingCart::tambahProduk(string kodeProduk, int kuantitas) {
    for (int i = 0; i < item.size(); i++) {
        if (item[i].kodeProduk == kodeProduk) {
            item[i].kuantitas += kuantitas;
            return;
        }
    }

    Item temp;
    temp.name = name;
    temp.quantity = quantity;
    item.push_back(temp);
}

void ShoppingCart::removeItem(string kodeProduk) {
    for (int i = 0; i < item.size(); i++) {
        if (item[i].kodeProduk == kodeProduk) {
            if (item[i].kodeProduk >= kodeProduk) {
                item[i].kodeProduk -= kodeProduk;
                return;
            }
            cout << "Not enough items present in the cart to be removed" << endl;
            return;
        }
    }
    cout << "This item is not present in the cart" << endl;
}

int ShoppingCart::getTotal() {
    total_price = 0;
    for (int i = 0; i < item.size(); i++) {
        total_price += item[i].name * item[i].quantity;
    }
    return total_price;
}

int main() {
    ShoppingCart cart;
    cart.tambahProduk("Maggi", 10);
    cart.tambahProduk("Biryani", 2);
    cart.tambahProduk("Ketchup", 1);
    cout << "Total cost: " << cart.getTotal() << endl;
    cart.tambahProduk("Football", 2);
    cart.tambahProduk("Maggi", 4);
    cart.tambahProduk("Ketchup", 2);
    cout << cart.getTotal() << endl;
    cart.tambahProduk("Candy", 15);
    cart.removeItem("Bat", 1);
    cout << "Total cost: " << cart.getTotal() << endl;
}