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

// Violating SRP: ShoppingCart is handling many responsibilities
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
    
    // Violating SRP: Prints invoice should be in different class
    void printInvoice(){
        cout << "Shopping Cart Details:\n";
        for(int i=0; i<products.size(); i++){
            cout << products[i]->name << " - $" << products[i]->price << endl;
        }
        cout << "Total Price: $" << total_price() << endl;
    }

    // Violating SRP: Saves to DB should be in differnet class
    void DB_Save(){
        cout << "Shopping Cart is saved to db sucessfully" << endl;
    }     
};

int main(){

    ShoppingCart* s1 = new ShoppingCart();
    s1->addProduct(new Product("Iphone",1000));
    s1->addProduct(new Product("macbook m4",5000));

    s1->total_price();
    s1->printInvoice();
    s1->DB_Save();

    return 0;
}