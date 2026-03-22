#include <iostream>
#include <string>

using namespace std;

class Car{
  protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
  
  public:
    Car(string brand,string model){
        this->brand = brand;
        this->model = model;
        isEngineOn = false;
        currentSpeed = 0;
    }

    // Common methods for all cars
    void startEngine(){
        isEngineOn = 1;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }

    void stopEngine(){
         if(!isEngineOn){
            cout << brand << " " << model << " : Engine is already off!" << endl;
        }
        isEngineOn = 0;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine stops!" << endl;
    }

    virtual void brake() = 0; //Abstract method for dynamic polymorphism

    virtual void accelerate() = 0; //Abstract method for dynamic polymorphism

};

class ManualCar : public Car{ //inherits from car class
   private:
    int currentGear; //specific to manual car

   public:

    ManualCar(string brand,string model) : Car(brand,model){
       currentGear = 0;
    }

    void shiftGear(int gear){ //unique method for manual car
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off! Cannot shift Gear." << endl;
        }
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }
    
    // Overriding accelerate - Dynamic Polymorphism
    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << "Km/hr" << endl;
    }
    
    // Overriding brake - Dynamic Polymorphism
    void brake(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off! Cannot apply brake." << endl;
        }
        currentSpeed -= 20;
        if(currentSpeed < 0){
            currentSpeed = 0;
        }
        cout << brand << " " << model << " : brake applied" << endl;
    }
};

class ElectricCar : public Car{ //inherits from car class
   private:
    int batteryPercentage; //specific to electric car
 
   public:

    ElectricCar(string brand,string model) : Car(brand,model){
        batteryPercentage = 30;
    } 

    void chargeBattery(){ //unique method for electric car
        batteryPercentage = 100;
        cout << "Battery is charged fully" << endl;
    }
    
    // Overriding accelerate - Dynamic Polymorphism
    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
        }
        if(batteryPercentage<=0){
            cout << brand << " " << model << " : Battery is dead! Cannot accelerate." << endl;
        }
        batteryPercentage -= 10;
        currentSpeed += 15;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << "Km/hr" << endl;
    }
    
    // Overriding brake - Dynamic Polymorphism
    void brake(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off! Cannot apply brake." << endl;
        }
        currentSpeed -= 15;
        if(currentSpeed < 0){
            currentSpeed = 0;
        }
        cout << brand << " " << model << " : brake applied" << endl;
    }
};

int main(){
    
    ManualCar* m1 = new ManualCar("mahindra","scorpio-n");
    m1->startEngine();
    m1->shiftGear(1);
    m1->accelerate();
    m1->accelerate();
    m1->shiftGear(2);
    m1->accelerate();
    m1->accelerate();
    m1->brake();
    m1->stopEngine();

    cout << "-----------------------" << endl;

    ElectricCar* e1 = new ElectricCar("tata","nexon");
    e1->startEngine();
    e1->accelerate();
    e1->accelerate();
    e1->brake();
    e1->brake();
    e1->chargeBattery();
    e1->accelerate();
    e1->accelerate();
    e1->brake();
    e1->stopEngine();

    return 0;
}