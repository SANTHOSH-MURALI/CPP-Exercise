#include <iostream>

namespace Root{
    namespace Math{
        class First{
            public:
                static int sum(int a, int b){
                    return a+b;
                }
                static std::string sum(std::string a,std::string b){
                    return a+b;
                }
        };
        
    }
    inline namespace MathClone{
        static int multiply(int a,int b){
            return a*b;
        }
    }
}
    
namespace alais = Root::Math;

int main(){
    std::cout<<  alais::First:: sum("hari","haran") << std::endl;
    std::cout<<  alais::First:: sum(1,2) << std::endl;
    std::cout<<  Root::multiply(7,5) << std::endl;
    return 0;
}
