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

    void brake(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off! Cannot apply brake." << endl;
        }
        currentSpeed = 0;
        cout << brand << " " << model << " : brake applied" << endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
        }
        currentSpeed += 10;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << "Km/hr" << endl;
    }

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
};

int main(){
    
    ManualCar* m1 = new ManualCar("mahindra","thar");
    m1->startEngine();
    m1->shiftGear(1);
    m1->accelerate();
    m1->accelerate();
    m1->shiftGear(2);
    m1->accelerate();
    m1->accelerate();
    m1->brake();
    m1->stopEngine();

    cout << "-------------------------" << endl;

    ElectricCar* e1 = new ElectricCar("tata","nexon");
    e1->startEngine();
    e1->accelerate();
    e1->accelerate();
    e1->brake();
    e1->chargeBattery();
    e1->accelerate();
    e1->accelerate();
    e1->brake();
    e1->stopEngine();
    
    return 0;
}