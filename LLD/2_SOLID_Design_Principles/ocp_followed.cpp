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

// This class is handling only 1 business logic of saving the cart to different database
// Now, I have to integrate new features of saving the cart to sql db and file
// For this, I have to do extension not modification by OCP
class ShoppingCartDatabase{
    private:
     ShoppingCart* cart;
    
   public:
    ShoppingCartDatabase(ShoppingCart* cart){
        this->cart = cart;
    }

    virtual void save() = 0;
};

class MongoDB : public ShoppingCartDatabase{
    public:
     MongoDB(ShoppingCart* cart) : ShoppingCartDatabase(cart){

     }

     void save(){
        cout << "Shopping Cart is saved to Mongo DB sucessfully\n"; 
     }
};

class SQLDB : public ShoppingCartDatabase{
    public:
     SQLDB(ShoppingCart* cart) : ShoppingCartDatabase(cart){

     }

     void save(){
        cout << "Shopping Cart is saved to SQL DB sucessfully\n"; 
     }
};

class File : public ShoppingCartDatabase{
    public:
     File(ShoppingCart* cart) : ShoppingCartDatabase(cart){

     }

     void save(){
        cout << "Shopping Cart is saved to File sucessfully\n"; 
     }
};

int main(){

    ShoppingCart* s1 = new ShoppingCart();
    s1->addProduct(new Product("Iphone",1000));
    s1->addProduct(new Product("macbook m4",5000));

    cout << "Total Price: $" << s1->total_price() << endl;

    ShoppingCartPrinter* p1 = new ShoppingCartPrinter(s1);
    p1->printInvoice();

    ShoppingCartDatabase* mdb = new MongoDB(s1);
    ShoppingCartDatabase* sqldb = new SQLDB(s1);
    ShoppingCartDatabase* file = new File(s1);

    mdb->save();
    sqldb->save();
    file->save();

    return 0;
}