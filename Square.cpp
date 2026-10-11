
#include "Square.h"
#include <stdexcept>

Square::Square()
    : Rectangle() {
    Point2D vertices[N_VERTICES] = {
        Point2D(-1, 1),
        Point2D(1, 1),
        Point2D(1, -1),
        Point2D(-1, -1)
    };

    set_vertices(vertices);
}

Square::Square(std::string color, Point2D* vertices)
    : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Cuadrado invalido");
    }
}

bool Square::check(Point2D* vertices){
	double lado = Point2D::distance(vertices[0], vertices[1]);
	return Point2D::distance(vertices[1], vertices[2]) == lado &&
           Point2D::distance(vertices[2], vertices[3]) == lado &&
           Point2D::distance(vertices[3], vertices[0]) == lado;
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Cuadrado invalido");
    }

    Rectangle::set_vertices(vertices);
}

std::ostream& operator<<(std::ostream& out, const Square& square) {
    out << "[Square: color = " << square.get_color()
        << "; vertices = ";

    for (int i = 0; i < Rectangle::N_VERTICES; i++) {
        if (i > 0) {
            out << ", ";
        }

        out << square[i];
    }

    out << "]";
    return out;
}

void Square::print() {
    std::cout << *this << std::endl;
}
