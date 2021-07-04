// Compiled with: g++ -Wall -std=c++14 -pthread

#include <iostream>
#include <vector>
#include <math.h>  
using namespace std;

/*Տրված է շրջանագծերի (x0,y0,r0), (x1,y1,r1), … ,
(xn–1,yn-1,rn-1) հաջորդականությունը, որտեղ (xi,yi)-ն iրդ շրջանագծի կենտրոնի կոորդինատներն են, իսկ ri-ն նրա
շառավիղն է: Արտածել
ա) YES, եթե բոլոր շրջանագծերը ներդրված են մեկը մյուսի
մեջ, և NO՝ հակառակ դեպքում,*/

class Circle
{
    
public:

    int x;
    int y;
    int r;
  
    Circle(int x1, int y1, int r1)
        : x(x1), y(y1), r(r1)
    {}

    void print() const
    {
        cout << "[ " << x << ", " << y << " ] - " << r  << endl;
    }

    double center_distance(const Circle& other) const
    {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }

};


bool nerdrvac(const Circle& small, const Circle& big)
{
    if (small.r > big.r)
        return false;

    double dis = small.center_distance(big); 
    
    if (dis + small.r <= big.r)
        return true;
    return false;
}

bool nerdrvac(const vector<Circle>& array, int maxIndex)
{
    for(const auto elem : array)
    {
         if ( nerdrvac(elem, array[maxIndex]) == false)
             return false;
    }
    return true;
}


int main(){

    const vector<Circle> array = { Circle(5, 5, 1) , Circle(0, 0, 5), Circle(0, 0, 9), Circle(0, 7, 2)}; 
    
    int maxIndex = 0;

    for (uint i = 1; i < array.size(); ++i)
    {
        if (array[i].r >= array[maxIndex].r)
            maxIndex = i;   
    }

     
    cout << "Nerdrvac = " << ( (nerdrvac(array, maxIndex)) ? "true" : "false" ) << endl;

    return 0;
}


