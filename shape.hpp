//  Matt Perry, Tailon Russell, Chenyi Ling, McKade Sorensen
// Based on Dr. Hartmans CPS2020 example
#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double getHeight() const = 0;
    virtual double getWidth() const = 0;
    virtual void move(int i, std::ostream& os) const = 0;
    void genPostScript(std::ostream& os) {
        for (size_t i = 0; i < _shapes.size(); i++) { move(i,os); }
    }
private:
    std::vector<std::shared_ptr<Shape>> _shapes;
};

std::shared_ptr<Shape> makeLayeredShape(std::initializer_list<std::shared_ptr<Shape>> list);
std::shared_ptr<Shape> makeVerticalShape(std::initializer_list<std::shared_ptr<Shape>> list);
std::shared_ptr<Shape> makeHorizontalShape(std::initializer_list<std::shared_ptr<Shape>> list);


class LayeredShape : public Shape {
public:
    LayeredShape(std::initializer_list<std::shared_ptr<Shape>> list);
    double getHeight() const override;
    double getWidth() const override;
    void move(int index, std::ostream& os) const override;
    void genPostScript(std::ostream& os);
private:
    std::vector<std::shared_ptr<Shape>> _shapes;

};

class HorizontalShape : public Shape {
public:
    HorizontalShape(std::initializer_list<std::shared_ptr<Shape>> list);
    double getHeight() const override;
    double getWidth() const override;
    void move(int index, std::ostream& os) const override;
    void genPostScript(std::ostream& os);
private:
    std::vector<std::shared_ptr<Shape>> _shapes;
};

class VerticalShape : public Shape {
public:
    VerticalShape(std::initializer_list<std::shared_ptr<Shape>> list);
    double getHeight() const override;
    double getWidth() const override;
    void move(int index, std::ostream& os) const override;
    void genPostScript(std::ostream& os);
private:
    std::vector<std::shared_ptr<Shape>> _shapes;
};

#endif