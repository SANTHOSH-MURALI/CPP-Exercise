#include <iostream>

class Rectangle{
    public:
        int *left,*top,*width,*height,*area;
        Rectangle(){
            left = new int(0);     
            top = new int(0);
            width = new int(0);
            height = new int(0);
            area = nullptr;
        }
        Rectangle(int w,int h){
            left = new int(0);     
            top = new int(0);
            width = new int(w);
            height = new int(h);
            area = nullptr;

        }
        Rectangle(int l,int t,int w,int h){
            left = new int(l);     
            top = new int(t);
            width = new int(w);
            height = new int(h);
            area=nullptr;
        }
        Rectangle(float l,float t,float w,float h){
            left = new int(std::round(l));     
            top = new int(std::round(t));
            width = new int(std::round(w));
            height = new int(std::round(h));
            area = nullptr;

        }
        Rectangle(const Rectangle& obj) {
            left = new int(*obj.left);
            top = new int(*obj.top);
            width = new int(*obj.width);
            height = new int(*obj.height);
            area = new int((*width) * (*height));  
        }
        void printValues(){
            std::cout<< "Left = " << *left <<std::endl;
            std::cout<< "Top = " << *top <<std::endl;
            std::cout<< "Width = " << *width <<std::endl;
            std::cout<< "Height = " << *height <<std::endl;
            if (area != nullptr) {
                std::cout<< "Area = " << *area <<std::endl;
            }
        }

        ~Rectangle() {
            delete left;
            delete top;
            delete width;
            delete height;
            if (area != nullptr) {
                delete area;
            }
        }   
};
int main(){
    Rectangle rect1(1.1f,1.5f,2.7f,2.1f);
    rect1.printValues();

    // Rectangle* rect1 = new Rectangle(1.1f, 1.5f, 2.7f, 2.1f);
    // rect1->printValues();
    // delete rect1;
    

    Rectangle rect2 = rect1;
    rect2.printValues();

    return 0;
}
