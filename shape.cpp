//  Matt Perry, Tailon Russell, Chenyi Ling, McKade Sorensen

#include "shape.hpp"

using std::initializer_list;
using std::vector;
using std::shared_ptr;

std::shared_ptr<Shape> makeLayeredShape(std::initializer_list<std::shared_ptr<Shape>> list) {
    return std::make_shared<LayeredShape>(list);
}

std::shared_ptr<Shape> makeVerticalShape(std::initializer_list<std::shared_ptr<Shape>> list) {
    return std::make_shared<VerticalShape>(list);
}

std::shared_ptr<Shape> makeHorizontalShape(std::initializer_list<std::shared_ptr<Shape>> list) {
    return std::make_shared<HorizontalShape>(list);
}

LayeredShape::LayeredShape(initializer_list<shared_ptr<Shape>> list) {
    vector<shared_ptr<Shape>> temp(list.begin(), list.end());
    _shapes = temp;
}

double LayeredShape::getWidth() const {
    return 0.0;
}

double LayeredShape::getHeight() const {
    return 0.0;
}
 // Horizontal Shape
HorizontalShape::HorizontalShape(initializer_list<shared_ptr<Shape>> list) {
    vector<shared_ptr<Shape>> temp(list.begin(), list.end());
    _shapes = temp;
}

double HorizontalShape::getHeight() const {
    return 0.0;
}

double HorizontalShape::getWidth() const {
    return 0.0;
}

void HorizontalShape::move(int index, std::ostream& os) const {
    _shapes[index]->genPostScript(os);
    os << _shapes[index]->getWidth() <<" 0 translate\n";
}


void LayeredShape::move(int index, std::ostream& os) const {
    _shapes[index]->genPostScript(os);
}

//
//  Vertical Shape
VerticalShape::VerticalShape(initializer_list<shared_ptr<Shape>> list) {
    vector<shared_ptr<Shape>> temp(list.begin(), list.end());
    _shapes = temp;
}

double VerticalShape::getHeight() const {
    return 0.0;
}

double VerticalShape::getWidth() const {
    return 0.0;
}

void VerticalShape::move(int index, std::ostream& os) const {
    _shapes[index]->genPostScript(os);
    os  << "0 " << _shapes[index]->getHeight() << " translate\n";
}


