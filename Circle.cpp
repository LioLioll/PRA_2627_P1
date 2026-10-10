#include "Circle.h"
#include <cmath>
#include <stdexcept>
#define PI 3.141592

Circle::Circle() : center(0.0, 0.0), radius(1) {}

Circle::Circle(std::string color, Point2D center, double radius):Shape(color), center(center) {
	if( radius < 0 ){
		throw std::invalid_argument("Radio NEGATIVO, invalido");
	}else{
		this->radius = radius;
	}
}

Point2D Circle::get_center() const{
	return center;
}

void Circle::set_center(Point2D p){
	center = p;
}

double Circle::get_radius() const{
	return radius;
}

void Circle::set_radius(double r){
	if (r < 0) {
        throw std::invalid_argument("Radio negativo, invalido");
    } else {
        radius = r;
    }
}

double Circle::area() const {
	return PI * pow(radius,2);
}

double Circle::perimeter() const {
	return 2 * PI * radius;
}

void Circle::translate(double incX, double incY){
	center.x += incX;
	center.y += incY;
}

std::ostream& operator<<(std::ostream &out, const Circle &c){
	out<<	"[Circle: color = "<<c.color<<"; center = "<<c.center<<"; radius = "<<c.radius<< "]";
	return out;
}

void Circle::print() {
	std::cout << *this << std::endl;
}
