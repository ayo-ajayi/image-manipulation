#include <iostream>
#include "rgb.h"
#include "pixelmatrix.h"

int main(){
    pixelmatrix pic(4,3, rgb(3,4,5));
    pic(2,2) = rgb(0,0,0);
    std::cout << pic << std::endl;
    return 0;
}