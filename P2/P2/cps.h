//
//  cps.h
//  P2
//
//  Created by Chenyi Ling on 3/24/20.
//  Copyright © 2020 Chenyi Ling. All rights reserved.
//

#ifndef cps_h
#define cps_h

#include <iostream>

// A shape language that allows basic shapes such as squares, circles, and polygons to be defined, rotated and scaled versions, and aggregate shapes.

class Shape{
public:
    void getWidth(int _width){
        width = _width;
    }
    
    void getHeight(int _height){
        height = _height;
    }
    
    // Bounding box is centered around the current coordinates.
    void drawBoundingBox(int _x, int _y){
        
        
    }
    
protected:
    int width;
    int height;
    int cor_x; // current point x coordinates.
    int cor_y; // current point y coordinates.
    
};



// Derived class
class Circle: public Shape{
    double radius = 0.5 * width;
    
};

class Polygon: public Shape{
    
    
//    Case 1: n is odd.
//    height = e(1+cos(π/n))/(2sin(π/n))
//    width = (e sin(π(n-1)/2n))/(sin(π/n))
//
//    Case 2: n is divisible by 4.
//    height = e(cos(π/n))/(sin(π/n))
//    width = (e cos(π/n))/(sin(π/n))
//
//    Case 3: n is divisible by 2, but not by 4.
//    height = e(cos(π/n))/(sin(π/n))
//    width = e/(sin(π/n))
    
    
    
};

class Rectangle: public Shape{
};


class Spacer: public Shape{
};

class Square: public Shape{
};

class Triangle: public Shape{
};





// A shapes-to-PostScript translator



#endif /* cps_h */
