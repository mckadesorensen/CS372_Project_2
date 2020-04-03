//  Matt Perry, Tailon Russell, Chenyi Ling, McKade Sorensen

#include "shape.hpp"

using std::initializer_list;
using std::vector;
using std::shared_ptr;

std::shared_ptr<Shape> makeCircle(double radius)
{
	return std::make_shared<Circle>(radius);
}

std::shared_ptr<Shape> makePolygon(int numSides, double length)
{
	return std::make_shared<Polygon>(numSides, length);
}

std::shared_ptr<Shape> makeRectangle(double width, double height)
{
	return std::make_shared<Rectangle>(width,height);
}

std::shared_ptr<Shape> makeSpacer(double width, double height)
{
	return std::make_shared<Spacer>(width, height);
}

std::shared_ptr<Shape> makeSquare(double length)
{
	return std::make_shared<Rectangle>(length,length);
}

std::shared_ptr<Shape> makeTriangle(double length)
{
	return std::make_shared<Triangle>(length);
}

std::shared_ptr<Shape> makeRotatedShape(std::shared_ptr<Shape> s, Angle a)
{
	return std::make_shared<RotatedShape>(s,a);
}

std::shared_ptr<Shape> makeScaledShape(std::shared_ptr<Shape> s, double sx, double sy)
{
	return std::make_shared<ScaledShape>(s, sx, sy);
}

std::shared_ptr<Shape> makeLayeredShape(std::initializer_list<std::shared_ptr<Shape>> i)
{
	return std::make_shared<LayeredShape>(i);
}

std::shared_ptr<Shape> makeVerticalShape(std::initializer_list<std::shared_ptr<Shape>> i)
{
	return std::make_shared<VerticalShape>(i);
}

std::shared_ptr<Shape> makeHorizontalShape(std::initializer_list<std::shared_ptr<Shape>> i)
{
	return std::make_shared<HorizontalShape>(i);
}

Circle::Circle(double radius): _radius(radius){}

double Circle::getHeight() const
{
	return (2 * _radius);
}

double Circle::getWidth() const
{
	return (2 * _radius);
}

void Circle::genPostScript(std::ostream& os) const 
{
}

Polygon::Polygon(int numSides, double length): _numSides(numSides), _length(length){}

double Polygon::getHeight() const
{
	if (_numSides % 2 == 1)
		return (_length * (1 + std::cos(M_PI / _numSides))/(2 * std::sin(M_PI / _numSides)));
	if (_numSides % 4 == 0)
		return (_length * (std::cos(M_PI / _numSides)) / std::sin(M_PI / _numSides));
	if (_numSides % 2 == 0)
		return (_length * (std::cos(M_PI / _numSides)) / std::sin(M_PI / _numSides));
	
	return 0.0;
}

double Polygon::getWidth() const
{
	if (_numSides % 2 == 1)
		return ((_length * std::sin(M_PI * (_numSides - 1.0) / (2.0 * _numSides))) / std::sin(M_PI / _numSides));
	if (_numSides % 4 == 0)
		return ((_length * std::cos(M_PI / _numSides)) / std::sin(M_PI / _numSides));
	if (_numSides % 2 == 0)
		return (_length / std::sin(M_PI / _numSides));

	return 0.0;
}

void Polygon::genPostScript(std::ostream& os) const
{
    
}


Rectangle::Rectangle(double width, double height): _width(width), _height(height){}

double Rectangle::getHeight() const
{
	return _height;
}

double Rectangle::getWidth() const
{
	return _width;
}


void Rectangle::genPostScript(std::ostream& os) const
{
	os << "newpath\n";
	os << "moveto";
	os << getWidth() << " inch 0 inch rlineto\n";
	os << getWidth() << " inch " << getHeight() << " inch rlineto\n";
	os << "0 inch " << getHeight() << " inch rlineto\n";
	os << "closepath\n";
	os << "stroke\n";
}



Spacer::Spacer(double width, double height): _width(width), _height(height){}

double Spacer::getHeight() const
{
	return _height;
}

double Spacer::getWidth() const
{
	return _width;
}


void Spacer::genPostScript(std::ostream& os) const
{
	os << "1 setgray\n";
	os << "newpath\n";
	os << "1 inch  1 inch moveto\n";
	os << getWidth() << " inch 1 inch moveto\n";
	os << getWidth() << " inch " << getHeight() << " inch moveto\n";
	os << "1 inch " << getHeight() << " inch moveto\n";
	os << "closepath\n";
	os << "stroke\n";
}


Triangle::Triangle(double length): _length(length){}

double Triangle::getHeight() const
{
	return Polygon(3, _length).getHeight();
}

double Triangle::getWidth() const
{
	return Polygon(3, _length).getWidth();
}


void Triangle::genPostScript(std::ostream& os) const
{
	os << "/inch {72 mul} def\n";
	os << "newpath\n";
	os << "1 inch " << getWidth() << " inch moveto\n";
	os << getWidth() << " inch 1 inch moveto\n";
	os << getWidth() << " inch " << getHeight() << " inch moveto\n";
	os << "1 inch " << getHeight() << " inch moveto\n";
	os << "closepath\n";
	os << "stroke\n";
	os << "showpage\n";
}


RotatedShape::RotatedShape(std::shared_ptr<Shape> s, Angle a)
{
	_s = s;
	switch (a) {
	case Angle::R90:
		_a = 90;
		break;
	case Angle::R180:
		_a = 180;
		break;
	case Angle::R270:
		_a = 270;
		break;
	}
}

double RotatedShape::getHeight() const
{
	if (_a == 90 || _a == 270)
		return _s->getWidth();
	if (_a == 180)
		return _s->getHeight();

	return 0.0;
}

double RotatedShape::getWidth() const
{
	if (_a == 90 || _a == 270)
		return _s->getHeight();
	if (_a == 180)
		return _s->getWidth();

	return 0.0;
}


void RotatedShape::genPostScript(std::ostream& os) const
{

}


ScaledShape::ScaledShape(std::shared_ptr<Shape> s, double xscale, double yscale): _s(s), _xscale(xscale), _yscale(yscale){}

double ScaledShape::getHeight() const
{
	return (_s->getHeight() * _yscale);
}

double ScaledShape::getWidth() const
{
	return (_s->getWidth() * _xscale);
}


void ScaledShape::genPostScript(std::ostream& os) const
{
	_s->genPostScript(os);
}


LayeredShape::LayeredShape(initializer_list<shared_ptr<Shape>> i)
{
	vector<shared_ptr<Shape>> temp(i.begin(), i.end());
	_shapes = temp;
}

double LayeredShape::getHeight() const
{
	return 0.0;
}

double LayeredShape::getWidth() const
{
	return 0.0;
}


void LayeredShape::genPostScript(std::ostream& os) const
{
	for (size_t i = 0; i < _shapes.size(); i++)
	{
		_shapes[i]->genPostScript(os);
	}
}


VerticalShape::VerticalShape(initializer_list<shared_ptr<Shape>> i)
{
	vector<shared_ptr<Shape>> temp(i.begin(), i.end());
	_shapes = temp;
}

double VerticalShape::getHeight() const
{
	return 0.0;
}

double VerticalShape::getWidth() const
{
	return 0.0;
}


void VerticalShape::genPostScript(std::ostream& os) const
{
	for (size_t i = 0; i < _shapes.size(); i++)
	{
		_shapes[i]->genPostScript(os);
	}
}


HorizontalShape::HorizontalShape(initializer_list<shared_ptr<Shape>> i)
{
	vector<shared_ptr<Shape>> temp(i.begin(), i.end());
	_shapes = temp;
}

double HorizontalShape::getHeight() const
{
	return 0.0;
}

double HorizontalShape::getWidth() const
{
	return 0.0;
}


void HorizontalShape::genPostScript(std::ostream& os) const
{
	for (size_t i = 0; i < _shapes.size(); i++)
	{
		_shapes[i]->genPostScript(os);
	}
}

