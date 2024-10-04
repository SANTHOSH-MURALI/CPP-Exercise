#include<iostream>
#include<stdexcept>
class AgeNotWithinRangeException: public std::exception{
    private :
        std::string message;
    public:
        AgeNotWithinRangeException(const std::string& msg):message(msg){}
        const char* what() const noexcept override{
            return message.c_str();
        }
};
class NameNotValidException: public std::exception{
    private :
        std::string message;
    public:
        NameNotValidException(const std::string& msg):message(msg){}
        const char* what() const noexcept override{
            return message.c_str();
        }
};
class InvalidCouseException: public std::exception{
    private :
        std::string message;
    public:
        InvalidCouseException(const std::string& msg):message(msg){}
        const char* what() const noexcept override{
            return message.c_str();
        }
};
class Student{
    private:
        std::string rollno;
        std::string name;
        int age;
        static bool instanceFlag;
        std::vector<std::string> courses = {"dsa","designing","drawing"};
        std::string course;
    public:
        Student(std::string roll,std::string n, int age,std::string course):rollno(roll),name(n), age(age),course(course){
            if(instanceFlag){
                std::cout<<"Only one object can be created at a time !" <<std::endl;
            }
            instanceFlag=true;
            
            if(!validName(name)){
                throw NameNotValidException("Name InValid !");
            }
            if(!(age>=15 && age<=21)){
                throw AgeNotWithinRangeException("Age is not within the range !");
            }
            if(!validCourse(course)){
                throw InvalidCouseException("Course Invalid !");
            }   
            
        }
        void printDetails(){
            std::cout<<"rollno = "<<rollno<<std::endl;
            std::cout<<"Name = "<<name<<std::endl;
            std::cout<<"Age = "<<age<<std::endl;
            std::cout<<"Course = "<<course<<std::endl;
        }
        bool validName(std::string name){
            int len = name.length();
            bool flag = true;
            for(int i=0;i<len;i++){
                if(!isalpha(name[i])){
                    flag=false;break;
                }
            }
            return flag;
        }
        bool validCourse(std::string course){
            return std::find(courses.begin(), courses.end(), course) != courses.end();
        }
        ~Student() {
            instanceFlag = false;
        }
};

bool Student::instanceFlag = false;

int main(){
    
    try{
        std::cout<<"Enter Following details :"<<std::endl;
        std::string name,rollno,course;
        int age;
        std::cout<<"Enter the name : "<<std::endl;
        std::cin>>name;
        std::cout<<"Enter the roll no : "<<std::endl;
        std::cin>>rollno;
        std::cout<<"Enter the age [15-21]: "<<std::endl;
        std::cin>>age;
        std::cout<<"Enter the Course [dsa, designing, drawing]: "<<std::endl;
        std::cin>>course;
    
        Student student(rollno,name,age,course);
    }catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}