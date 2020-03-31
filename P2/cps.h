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
#include <string>
#include <math.h>

// A shape language that allows basic shapes such as squares, circles, and polygons to be defined, rotated and scaled versions, and aggregate shapes.

class Shape{

public:
    Shape(){};
    virtual ~Shape(){};
    
    
    virtual void setWidth(double width){
        _width = width;
    }
    
    virtual void setHeight(double height){
           _height = height;
       }
    
    void setCoor(double x, double y){
        _x = x;
        _y = y;
    }
    
    const double getWidth(){
        return _width;
    }
    const double getHeight(){
        return _height;
    }
    
    
private:
    double _width;
    double _height;
    double _x; // current point x coordinates.
    double _y; // current point y coordinates.
    
};

// Derived class
class Circle: public Shape{
public:
    
    Circle(double radius)
    : _radius(radius)
    {}
    
    void setWidth() {
        Shape::setWidth(2 * _radius);
    }
    void setHeight() {
           Shape::setHeight(2 * _radius);
    }
    double _radius;
};

class Polygon: public Shape{
public:
    
    Polygon(int numSides, double sideLength)
    : _numSides(numSides),
      _sideLength(sideLength)
    {}

    int _numSides;
    double _sideLength;
    
    
    
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

    void setHeight(){
        
        if (_numSides % 2 != 0){
        Shape::setHeight(
        
        M_E * (1+cos(M_PI/_numSides))/
        (2 * sin(M_PI/_numSides)));
            
        }
        else if(_numSides % 4 == 0){
        Shape::setHeight( exp(1)*(cos(M_PI/_numSides))/(sin(M_PI/_numSides)));
        }
        else if( _numSides % 2 == 0 && _numSides % 4 != 0 ){
            
            Shape::setHeight(exp(1)* (cos(M_PI/_numSides))/(sin(M_PI/_numSides)) );
            }
            
      }
};

class Rectangle: public Shape{
    
};


class Spacer: public Shape{
};

class Square: public Shape{
};

class Triangle: public Shape{
};

#endif /* cps_h */
