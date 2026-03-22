#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Product class representing any item of any ecommerce
class Product{
   public:
    string name;
    int price;
   
   public:
    Product(string name,int price){
        this->name = name;
        this->price = price;
    }
};

// SRP followed as this class is handling only one business logic of calculating total price of items in cart
class ShoppingCart{
   private:
    vector<Product*> products;

   public:

    // Setter
    void addProduct(Product* product){
        products.push_back(product);
    }

    // Getter
    vector<Product*> getProducts(){
        return products;
    }

    // Calculating total price in cart
    double total_price(){
        double total = 0;
        for(int i=0; i<products.size(); i++){
            total += products[i]->price;
        }
        return total;
    } 
};

// This class is handling only 1 business logic of printing invoice
class ShoppingCartPrinter{
   private:
    ShoppingCart* cart;
    
   public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart = cart;
    }

    double printInvoice(){
        cout << "Shopping Cart Details:\n";
        for(int i=0; i<cart->getProducts().size(); i++){
            cout << cart->getProducts()[i]->name << " - $" << cart->getProducts()[i]->price << endl;
        }
        cout << "Total Price: $" << cart->total_price() << endl;
    }
};

// This class is handling only 1 business logic of saving the cart to database
class ShoppingCartDatabase{
    private:
     ShoppingCart* cart;
    
   public:
    ShoppingCartDatabase(ShoppingCart* cart){
        this->cart = cart;
    }

    void saveToDatabse(){
        cout << "Shopping Cart is saved to db sucessfully" << endl;
    }
};

int main(){

    ShoppingCart* s1 = new ShoppingCart();
    s1->addProduct(new Product("Iphone",1000));
    s1->addProduct(new Product("macbook m4",5000));

    cout << "Total Price: $" << s1->total_price() << endl;

    ShoppingCartPrinter* p1 = new ShoppingCartPrinter(s1);
    p1->printInvoice();

    ShoppingCartDatabase* d1 = new ShoppingCartDatabase(s1);
    d1->saveToDatabse();

    return 0;
}