#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class MobileConnection {
public:
    std::string mobileNumber;
    double billAmount;

    MobileConnection(const std::string& number, double amount)
        : mobileNumber(number), billAmount(amount) {}
    
    void payBill() {
        billAmount = 0;  
    }

    void updateBill(double newAmount) {
        billAmount += newAmount;  
    }
};


class LandlineConnection {
public:
    std::string stdCode;
    std::string landlineNumber;
    double billAmount;

    LandlineConnection(const std::string& std, const std::string& number, double amount)
        : stdCode(std), landlineNumber(number), billAmount(amount) {}

    void payBill() {
        billAmount = 0;  
    }

    void updateBill(double newAmount) {
        billAmount += newAmount;  
    }
};
template <typename T>
class BillingSystem {
private:
    std::unordered_map<std::string, T*> connections;

public:
    void addConnection(const std::string& connectionKey, T* connection) {
        connections[connectionKey] = connection;  
    }

    void payBill(const std::string& connectionKey) {
        if (connections.find(connectionKey) != connections.end()) {
            connections[connectionKey]->payBill();  
            std::cout << "Bill paid for connection: " << connectionKey << std::endl;
        } else {
            std::cout << "Connection not found!" << std::endl;
        }
    }

    void updateBill(const std::string& connectionKey, double newAmount) {
        if (connections.find(connectionKey) != connections.end()) {
            connections[connectionKey]->updateBill(newAmount);  
            std::cout << "Bill updated for connection: " << connectionKey << std::endl;
        } else {
            std::cout << "Connection not found!" << std::endl;
        }
    }
};
int main() {
    BillingSystem<MobileConnection> mobileBilling;
    BillingSystem<LandlineConnection> landlineBilling;

    int choice;

    do {
        std::cout << "1. Add a new mobile connection\n";
        std::cout << "2. Add a new landline connection\n";
        std::cout << "3. Pay bill using connection number\n";
        std::cout << "4. Update bill amount using connection number\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string mobileNumber;
            double amount;
            std::cout << "Enter mobile number (10 digits): ";
            std::cin >> mobileNumber;
            std::cout << "Enter bill amount: ";
            std::cin >> amount;
            mobileBilling.addConnection(mobileNumber, new MobileConnection(mobileNumber, amount));

        } else if (choice == 2) {
            std::string stdCode, landlineNumber;
            double amount;
            std::cout << "Enter STD code: ";
            std::cin >> stdCode;
            std::cout << "Enter landline number (6 digits): ";
            std::cin >> landlineNumber;
            std::cout << "Enter bill amount: ";
            std::cin >> amount;
            landlineBilling.addConnection(stdCode + landlineNumber, new LandlineConnection(stdCode, landlineNumber, amount));

        } else if (choice == 3) {
            std::string connectionKey;
            std::cout << "Enter connection number (mobile number or STD code + landline number): ";
            std::cin >> connectionKey;
            // Check if the connectionKey is mobile or landline and call appropriate function
            if (connectionKey.size() == 10) {
                mobileBilling.payBill(connectionKey);
            } else {
                landlineBilling.payBill(connectionKey);
            }

        } else if (choice == 4) {
            std::string connectionKey;
            double newAmount;
            std::cout << "Enter connection number (mobile number or STD code + landline number): ";
            std::cin >> connectionKey;
            std::cout << "Enter new bill amount: ";
            std::cin >> newAmount;
            // Check if the connectionKey is mobile or landline and call appropriate function
            if (connectionKey.size() == 10) {
                mobileBilling.updateBill(connectionKey, newAmount);
            } else {
                landlineBilling.updateBill(connectionKey, newAmount);
            }
        }
    } while (choice != 5);

    return 0;
}