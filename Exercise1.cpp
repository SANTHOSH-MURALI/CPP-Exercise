#include <iostream>
#include <string>
#include <iomanip>  // For setprecision and fixed

using namespace std;

class Vehicle {
    private:
        string vehicleType;
        string brand;
        string model;
        string color;
        double mileage;
        double price;
    public:
        Vehicle(string vehicleType, string brand, string model, string color, double mileage, double price) {
            this->vehicleType = vehicleType;
            this->brand = brand;
            this->model = model;
            this->color = color;
            this->mileage = mileage;
            this->price = price;
        }
        string getVehicleType() {
            return this->vehicleType;
        }
        string getBrand() {
            return this->brand;
        }
        string getModel() {
            return this->model;
        }
        string getColor() {
            return this->color;
        }
        double getMileage() {
            return this->mileage;
        }
        double getPrice() {
            return this->price;
        }
        void displayDetails() {
            cout << fixed << setprecision(2);  // Set fixed-point notation and 2 decimal places
            cout << "vehicleType = " << vehicleType 
                 << " brand = " << brand 
                 << " model = " << model 
                 << " color = " << color 
                 << " mileage = " << mileage 
                 << " price = " << price << endl;
        }
        virtual int getNoOfWheels() = 0;
};

class Bike : public Vehicle {
    private:
        double weight;
        string bikeType;
        int noOfWheels;
    public:
        Bike(string brand, string model, string color, double mileage, double price, double weight, string bikeType, int noOfWheels) :
            Vehicle("Bike", brand, model, color, mileage, price), weight(weight), bikeType(bikeType), noOfWheels(noOfWheels) {}
        double getWeight() {
            return this->weight;
        }
        string getBikeType() {
            return this->bikeType;
        }
        int getNoOfWheels() {
            return this->noOfWheels;
        }
        void displayDetails() {
            cout << "vehicleType = " <<  getVehicleType() << endl
                 << " brand = " << getBrand() << endl
                 << " model = " << getModel() << endl
                 << " color = " << getColor() << endl 
                 << fixed << setprecision(2)<<" mileage = " << getMileage() << endl
                 << fixed << setprecision(2)<<" price = " << getPrice() << endl 
                 <<fixed << setprecision(2)<<" weight = "<<getWeight() << endl
                 <<" bikeType = "<< getBikeType() << endl
                 <<" no of wheels = "<<getNoOfWheels()<<endl;
        }
};

class Car : public Vehicle {
    private:
        int noOfPersons;
        string carType;
        int noOfWheels;
    public:
        Car(string brand, string model, string color, double mileage, double price, int noOfPersons, string carType, int noOfWheels) :
            Vehicle("Car", brand, model, color, mileage, price), noOfPersons(noOfPersons), carType(carType), noOfWheels(noOfWheels) {}

        int getNoOfPersons() {
            return this->noOfPersons;
        }
        string getCarType() {
            return this->carType;
        }
        int getNoOfWheels() {
            return this->noOfWheels;
        }
        void displayDetails() {
            cout << fixed << setprecision(2);  // Set fixed-point notation and 2 decimal places
            cout << "vehicleType = " <<  getVehicleType() << endl
                 << " brand = " << getBrand() << endl
                 << " model = " << getModel() << endl
                 << " color = " << getColor() << endl
                 << " mileage = " << getMileage() << endl
                 << " price = " << getPrice() << endl
                 <<" no of persons = "<<getNoOfPersons() << endl
                 <<" carType = "<< getCarType() << endl
                 <<" no of wheels = "<<getNoOfWheels()<<endl;
        }


};

bool compare(Car v1, Bike v2) {
    return v1.getPrice() > v2.getPrice();
}

int main() {
    
    Car carObject("Audi", "2017", "Grey", 14.5, 100000.00, 4, "Sedan", 4);
    Bike bikeObject("Yamaha","2023", "Black", 52, 80000.00, 180, "off-road", 2);

    

    carObject.displayDetails();
    bikeObject.displayDetails();

   
    if (compare(carObject, bikeObject)) {
        cout << "Car is more expensive than Bike." << endl;
    } else {
        cout << "Bike is more expensive than Car." << endl;
    } 

    return 0;
}