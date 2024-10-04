#include <iostream>
#include <stdexcept>

class ValidVoterException : public std::exception {
private:
    std::string message;

public:
    ValidVoterException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

int main() {
    try {
        
        try {
            //Case 1 : If an exception occurs within outer try block.
            // Inner try block to handle string length error
            std::string str;
            std::cout << "Enter a string: ";
            std::cin >> str;
            int accessChar;
            std::cout << "Enter an index to access character: ";
            std::cin >> accessChar;

            if (accessChar >= str.length()) {
                throw std::out_of_range("Index out of range in inner block");
            }

            std::cout << "Character: " << str[accessChar] << std::endl;
        }
        catch (const std::out_of_range& e) {
            std::cout << "Caught in inner catch block: " << e.what() << std::endl;
            // Case 4: To re-throw an exception already catched.
            throw;
        }

        // Case 2:  If an exception occurs inside inner try block.
        int a,b;
        std::cout<<"Enter two numbers to division : "<<std::endl;
        std::cin>>a;
        std::cin>>b;
        //throw error if the denominator is 0
        if(b==0){
            throw std::runtime_error("Invalid Division!");
        }   
        std::cout<<"Division result = "<<a/b<<std::endl;

        // Case 3:In case of no such notable exceptions. The catch blocks won't execute
        std::cout << "Program completed successfully." << std::endl;

    } catch (const std::runtime_error& e) {
        std::cout << "Caught in outer catch block: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught in generic outer catch block: " << e.what() << std::endl;
    }

    return 0;
}





