#include <iostream>
#include <string>
using namespace std;

// Real Life Car

class Car{
   public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    virtual ~Car() {}
};

class SportsCar : public Car{
  public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    SportsCar(string brand,string model){
        this->brand = brand;
        this->model = model;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0; // Neutral
    }

    void startEngine(){
        isEngineOn = 1;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }

    void shiftGear(int gear){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off! Cannot shift Gear." << endl;
        }
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
        }
        currentSpeed += 10;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << "Km/hr" << endl;
    }

    void brake(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off! Cannot apply brake." << endl;
        }
        currentSpeed = 0;
        cout << brand << " " << model << " : brake applied" << endl;
    }

    void stopEngine(){
         if(!isEngineOn){
            cout << brand << " " << model << " : Engine is already off!" << endl;
        }
        isEngineOn = 0;
        currentSpeed = 0;
        currentGear = 0;
        cout << brand << " " << model << " : Engine stops!" << endl;
    }
};

int main(){
    
    Car *myCar = new SportsCar("Ford","Mustang"); // Parent class pointer can reference to child class object
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    delete myCar;

    // So here we don't need to know the functionality behind the behaviour
    // we get the interface to interactng with it
    // That is abstarction

    return 0;
}