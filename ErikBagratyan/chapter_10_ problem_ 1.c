#include <iostream>
using namespace std;

class B {
public:
    void f() const { ++b; g(); }  // const ֆունկցիաների ներսում պետք է կանչել const ֆունկցիաներ:

    void g() {}
private:
    static int b = 20; // static փոփոխականները սկզբնարժեքավորվում են class-ից դուրս;
};

int main()
{  
    return 0;
}
