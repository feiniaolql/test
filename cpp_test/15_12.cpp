#include <iostream>

using namespace std;

class Figure {
public:
    Figure(double x, double y) { xSize = x; ySize = y; }
protected:
    double xSize, ySize;
};

class Figure_2D: public Figure {
public:
    Figure_2D(double x, double y) : Figure(x, y) {}
    virtual double area(ostream &os) = 0;
    virtual double perimeter(ostream &os) = 0;
};

class Figure_3D: public Figure {
public: Figure_3D(double x, double y, double z) : Figure(x, y), zSize(z) {}
    virtual double cubage(ostream &os) = 0;
protected:
    double zSize;
};

class Rectangle : public Figure_2D {
public:
    Rectangle(double x, double y) : Figure_2D(x, y) {}
    virtual double area(ostream &os);
    virtual double perimeter(ostream &os);
};

double Rectangle::area(ostream &os)
{
    os << "the area of rectangle: " << xSize * ySize << endl; 
}

double Rectangle::perimeter(ostream &os)
{
    os << "the perimeter of rectangle: " << (xSize + ySize) * 2 << endl;
}

class Cubic : public Figure_3D {
public:
    Cubic(double x, double y, double z) : Figure_3D(x, y, z) {}
    virtual double cubage(ostream &os);
};

double Cubic::cubage(ostream &os)
{
    os << "the cubage of Cubic: " << xSize * ySize * zSize << endl;
}

int main(int argc, char **argv)
{
    Figure_2D *figure;
    figure = new Rectangle(5.0, 3.0);
    figure->area(cout);
    figure->perimeter(cout);
    delete figure;

    Figure_3D *figure3D;
    figure3D = new Cubic(3.0, 4.0, 5.0);
    figure3D->cubage(cout);

    return 0;
}

