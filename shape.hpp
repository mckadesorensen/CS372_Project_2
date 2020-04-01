//  Matt Perry, Tailon Russell, Chenyi Ling, McKade Sorensen

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

//Enum for handling Angles.
enum class Angle { A90, A180, A270 };

class Shape {
public:
    virtual ~Shape() = default;
    virtual double getHeight() const = 0;
    virtual double getWidth() const = 0;
    virtual void generatePostScript(std::ostream& os) const = 0;
};

class Circle : public Shape {
public:
    Circle(double radius);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    double _radius;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    double _width;
    double _height;
};

class Polygon : public Shape {
public:
    Polygon(int numSides, double length);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    int _numSides;
    double _length;
};

class Triangle : public Shape {
public:
    Triangle(double length);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    double _length;
};

class Spacer : public Shape {
public:
    Spacer(double width, double height);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    double _width;
    double _height;
};

class RotatedShape : public Shape {
public:
    RotatedShape(std::shared_ptr<Shape> s, Angle a);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    std::shared_ptr<Shape> _s;
    int _a;
};

#endif