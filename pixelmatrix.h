#ifndef PIXELMATRIX_H
#define PIXELMATRIX_H
#include <iostream>
#include <vector>
#include "rgb.h"
using namespace std;

class pixelmatrix{
    public: 
    typedef rgb value_type;
    typedef vector<value_type> store_type; //vector of rgb objs
    typedef unsigned int size_type;
    typedef store_type::iterator iterator; //pointer to one rgb obj
    typedef store_type::const_iterator const_iterator; //const pointer to one rgb obj
    private:
    size_type W; //width of matrix
    size_type H; //height of matrix
    store_type pixels; //vector of rgb objs to store pixels
    public:
    pixelmatrix()=delete;
     
    //create a vector with W*H rgb objs...vector uses empty constructor of rgb
    pixelmatrix(size_type w, size_type h): W(w), H(h), pixels(W*H){} 
    
    //create a vector with W*H rgb objs, all have color of col
    //the copy constructor of rgb is used here
    pixelmatrix(size_type w, size_type h, const value_type & col): W(w), H(h), pixels(W*H, col){}

    pixelmatrix(const pixelmatrix & orig) =default; //copy constructor
    pixelmatrix & operator = (const pixelmatrix & orig) =default; //assignment operator

    ~pixelmatrix()=default;

    //get pixel at x,y as a color(rgb obj)
    const value_type & operator ()(size_type x, size_type y)const{return pixels[W*y+x];}

    //set pixel at x,y with a color(rgb obj)
    value_type & operator ()(size_type x, size_type y){return pixels[W*y+x];}

    size_type width()const{return W;}
    size_type height()const{return H;}
    iterator begin(){return pixels.begin();}
    iterator end(){return pixels.end();}
    const_iterator begin()const{return pixels.begin();}
    const_iterator end()const{return pixels.end();}
};

inline ostream & operator << (ostream & s, const pixelmatrix & pm){
    for(auto & pixel : pm)s<<pixel<<' ';
    return s;
}

inline istream & operator >> (istream & s, pixelmatrix & pm){
    for (auto & pixel :pm)s>>pixel;
    return s;
}

#endif