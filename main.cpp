#include <iostream>
#include "rgb.h"
#include "canvas.h"
#include <complex>
#include <cmath>
#include <fstream>
using namespace std;

typedef complex<double> dcomplex;
int iter(dcomplex c, int limit){
    dcomplex z=0;
    int i=0;
    while(abs(z)<2 && i<limit){
        z=z*z+c;
        i++;
    }
    return i<limit  ? i:0;
}

void save(const canvas & image, const string & filename){
    ofstream output(filename);
    output<<image<<endl;
    output.close();
}




int main(){
    dcomplex bl(-2, -2);
    dcomplex tr(2, 2);

    int resolution = 2000000;
    auto w = tr.real()-bl.real();
    auto h = tr.imag()-bl.imag();

    int W=sqrt(resolution*w/h);
    int H=sqrt(resolution*h/w);

    auto dx=w/W;
    auto dy=h/H;

    canvas pic(W,H);

    for(unsigned int y=0; y<pic.height(); y++){
        for(unsigned int x=0; x<pic.width(); x++){
            dcomplex c(bl.real()+x*dx, tr.imag()-y*dy);
            auto it = iter(c, pic.max_color_component);
            pic(x,y) = rgb(it, it, it);
        }
    }
    save(pic, "pic.ppm");
    return 0 ;
}