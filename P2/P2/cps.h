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
    
    void drawBoundingBox(int _x, int _y){
        
    }
    
private:
    int width;
    int height;
    int cor_x; // current point x coordinates;
    int cor_y; // current point y coordinates;
    
};



// Derived class
class Circle: public Shape{
    
    
    
};

class Polygon: public Shape{
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
