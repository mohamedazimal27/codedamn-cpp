#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor to initialize length and width
    Rectangle(double l, double w) : length(l), width(w) {}

    // Method to calculate and return the area of the rectangle
    double calculateArea() const {
        return length * width;
    }

    // Method to calculate and return the perimeter of the rectangle
    double calculatePerimeter() const {
        return 2 * (length + width);
    }

    // Friend function to compare areas of two Rectangle objects
    friend bool isEqual(const Rectangle& r1, const Rectangle& r2) {
        return r1.calculateArea() == r2.calculateArea();
    }
};


int main() {
    Rectangle rect1(4.0, 5.0);
    Rectangle rect2(6.0, 3.0);

    if (isEqual(rect1, rect2)) {
        std::cout << "The two rectangles have the same area." << std::endl;
    } else {
        std::cout << "The two rectangles have different areas." << std::endl;
    }

    return 0;
}
