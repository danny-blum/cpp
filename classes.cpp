#include <iostream>

using namespace std;

class Shape {
    int x;
    int y;

    public:

	Shape() : x(5), y(5) {
	    cout << "Shape default constructor: x:" << x << " y:" << y << endl;
	}

	Shape(int x1, int y1) {
	    x = x1;
	    y = y1;

	    cout << "Shape constructor: x:" << x << " y:" << y << endl;  
	}

	int getX() {
	    return x;
	}

	int getY() {
	    return y;
	}

	void setX(int x1) {
	    x = x1;
	}

	void setY(int y1) {
	    y = y1;
	}

	void test() {
	    cout << "Test method of Shape class called." << endl;
	}

	virtual ~Shape() {
	    cout << "Shape destructor: x:" << x << " y:" << y << endl;
	}
};




class Rectangle : public Shape {

    public:
	Rectangle() : Shape() {
	}

	Rectangle(int x1, int y1) : Shape(x1, y1) {
	}

	Rectangle(Rectangle &r) : Shape(r.getX(), r.getY()) {
	    //setX(r.getX());
	    //setY(r.getY());    
	}

	int getArea() {
	    return getX() * getY();
	}

	void test() {
	    Shape::test();
	    cout << "Test method of Rectangle class called." << endl;
	}

	~Rectangle() {
	    cout << "Rectangle destructor" << endl;
	}
};


int main() {
    Rectangle *rectnew = new Rectangle(9, 12);
    cout << "Area of new Rectangle: " << rectnew->getArea() << endl;

    Rectangle rect;
    cout << "Area of first Rectangle: " << rect.getArea() << endl;

    Rectangle rect2(2,8);
    cout << "Area of second Rectangle: " << rect2.getArea() << endl;

    Rectangle rectcopy = rect;
    cout << "Area of copy Rectangle: " << rectcopy.getArea() << endl;

    cout << endl;

    rect.test();

    cout << endl;

    delete rectnew;
}
