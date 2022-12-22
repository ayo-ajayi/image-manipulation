#ifndef RGB_H
#define RGB_H
#include <iostream>
using namespace std;

struct rgb
{
    typedef int value_type;

    value_type r;
    value_type g;
    value_type b;
    rgb() : r(0), g(0), b(0) {} //black color
    rgb(value_type r0, value_type g0, value_type b0) : r(r0), g(g0), b(b0) {}
    rgb(const rgb & orig)=default;
    rgb & operator =(const rgb & orig)=default;
    ~rgb(){}
};
inline ostream & operator<<(ostream & s, const rgb & color){
    return s<<color.r<<' '<<color.g<<' '<<color.b;
}
inline istream & operator >>(istream & s, rgb&color){
    return s>>color.r>>color.g>>color.b;
}
#endif