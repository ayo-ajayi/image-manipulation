#ifndef CANVAS_H
#define CANVAS_H
#include "pixelmatrix.h"

class canvas: public pixelmatrix{
    public:
    typedef int coord_type;
    private:
    bool onscreen(coord_type x, coord_type y)const{
        return x>=0 && x < static_cast<coord_type>(width()) && y>=0 && y < static_cast<coord_type>(height());
    }
    mutable value_type offscreen;

    public:
    value_type::value_type max_color_component; //type is int

    canvas()=delete;
    canvas(size_type w, size_type h):pixelmatrix(w,h), max_color_component(255){}
    canvas(size_type w, size_type h, const value_type & color):pixelmatrix(w,h), max_color_component(255){}

    canvas(const canvas &)=default; //copy constructor
    ~canvas()=default;
    canvas & operator= (const canvas &)=default;
    value_type & operator()(coord_type x, coord_type y){
        return onscreen(x,y) ? pixelmatrix::operator()(x,y):offscreen;
    }
    const value_type & operator()(coord_type x, coord_type y)const{
        return onscreen(x,y) ? pixelmatrix::operator()(x,y):offscreen;
    }
};
inline ostream & operator <<(ostream & s, const canvas & image){
    return s <<
    "P3\n" <<
    image.width() << " " << image.height() << "\n"
    << image.max_color_component << "\n" <<
    dynamic_cast<const pixelmatrix &>(image);
}


#endif