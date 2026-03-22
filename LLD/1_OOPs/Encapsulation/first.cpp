#include <iostream>
#include <string>

using namespace std;


// All their variables and methodsa are wrapped in one class or encapsulated in one class.
// This follows the first principle of encapsualtion.
// 2nd principle tells about us Data Security
class SportsCar{
  private:
    //Characters
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyre;
  
  public:
    SportsCar(string brand,string model){
        this->brand = brand;
        this->model = model;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0; // Neutral
        tyre = "MRF";
    }
    //Behaviours --> Methods
   
    // Since we make the currentSpped private we have to use getter for getting the current speed
    // Here we can't use setter
    int getCurrentSpeed(){
        return currentSpeed;
    }
    
    // Taking expample of tyre for understanding getter and setter
    string getTyre(){ //Getter
        return this->tyre;
    }

    void setTyre(string tyre){ //Setter
        // Validations can be applied
        this->tyre = tyre;
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

    SportsCar* myCar = new SportsCar("Ford","Mustang");

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    // Setting arbitary value to the speed
    // myCar->currentSpeed = 500;
    // cout << "Car speed is setted to " << myCar->currentSpeed << endl;
    // For preventing this we need the data security

    cout << "Car currentSpped is " << myCar->getCurrentSpeed() << endl;

    return 0;
}