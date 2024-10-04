#include <iostream>
#include<stdexcept>

class ValidVoterException : public std::exception{
    private:   
        std::string message;
    public: 
        ValidVoterException(const std::string& msg): message(msg){}
        const char* what() const noexcept override {
            return message.c_str();
        }

};


bool isValidInteger(const std::string& input) {
    if (input.empty()) return false;

    size_t start = 0;
    if (input[0] == '-') {
        if (input.size() == 1) return false; // Just a negative sign
        start = 1; // Start checking digits from index 1
    }

    for (size_t i = start; i < input.size(); ++i) {
        if (!isdigit(input[i])) return false;
    }

    return true;
}

int main(){
    
    try{
        //Get two integers for division
        int a,b;
        std::cout<<"Enter two numbers to division : "<<std::endl;
        std::cin>>a;
        std::cin>>b;
        //throw error if the denominator is 0
        if(b==0){
            throw std::runtime_error("Invalid Division!");
        }   
        std::cout<<"Division result = "<<a/b<<std::endl;


        //get input for string and an index and return the character if index exists or throw out_of_range error
        std::string str;
        std::cout<<"Enter a string : "<<std::endl;
        std::cin>>str;
        int strlen = str.length() ;

        int accessChar;
        std::cout<<"Enter a index to access the character in the string : "<<std::endl;
        std::cin>>accessChar;

        if(accessChar > strlen-1 || accessChar < 0 ){
            throw std::out_of_range("Index is invalid!");
        }
        std::cout<<"Char at specified Index = "<<str[accessChar]<<std::endl;

        //Get input as string and validate. throw format mismatch error
        std::string input;
        std::cout << "Enter an integer: ";
        std::cin>>input;
        if(!isValidInteger(input)){
            throw std::invalid_argument("Format mismatch");
        }
        std::cout << "Valid integer: " << input << std::endl;


        //Get array input and and index. If the index is not within the range, throw out_of_range error
        int n,index;
        std::cout <<"Enter array size :"<< std::endl;
        std::cin >> n;
        int* array = new int[n];
        std::cout<<"Enter Array Elements : "<<std::endl;
        for(int i=0;i<n;i++){
            std::cin >> array[i] ;
        }
        std::cout<<"Enter index to fetch element from array : "<<std::endl;
        std::cin>>index;
        if(index < 0 || index > n){
            throw std::out_of_range("Index is invalid!");
        }
        std::cout<<"Element at specified index from array  = "<<array[index]<<std::endl;


        int age ;
        std::cout << "Enter the age : "<< std::endl;
        std::cin >> age;
        if(age <18 ){
            throw ValidVoterException("Invalid voter !");
        }
        std::cout<<"Valid Voter!"<<std::endl;
        

    }
    catch(const std::runtime_error& e){
        std::cout<<e.what()<<std::endl;
    }
     catch(const std::out_of_range& e){
        std::cout<<e.what()<<std::endl;
    }
     catch(const std::invalid_argument& e){
        std::cout<<e.what()<<std::endl;
    }
    catch(const ValidVoterException& e){
        std::cout<<e.what()<<std::endl;
    }
    catch(const std::exception& e){
        std::cout<<"Exception encountered"<<std::endl;
        std::cout<<"Exception Handling Accomplished"<<std::endl;
    }
    return 0;
}

