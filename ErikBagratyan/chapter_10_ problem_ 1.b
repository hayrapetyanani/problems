#include <iostream>
using namespace std;

class A {
public:
    int* f() const {return &c;} //const ֆունկցաների ներսում հնարավոր չէ փոփոխություն կատարել 
                                //this-ի փոփոխականների հետ,ինչպես նաև հնարավոր չէ դրանք վերադարձնել հասցեով։
                                
    void ~A() {} //destructor-ը վերադարձի տիպ չունի:

private:
    int c;
    int d = 15;
};

int main()
{  
    return 0;
}
