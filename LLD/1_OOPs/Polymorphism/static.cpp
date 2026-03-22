#include <iostream>
#include <string>

using namespace std;

class ManualCar{
   private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyre;

   public:
    ManualCar(string brand,string model){
        this->brand = brand;
        this->model = model;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0; // Neutral
        tyre = "MRF";
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
    
    // Overloading accelerate - Static Polymorphism
    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
        }
        currentSpeed += 10;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << "Km/hr" << endl;
    }

    void accelerate(int speed){
        if(!isEngineOn){
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
        }
        currentSpeed += speed;
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

    ManualCar* myCar = new ManualCar("ford","mustang");

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->accelerate(40);
    myCar->brake();
    myCar->stopEngine();

    return 0;
}