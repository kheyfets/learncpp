#include <iostream>
#include <cmath>

class Point2d {
private:
    double m_x;
    double m_y;
    
public:
    Point2d(double x = 0.0, double y = 0.0) {
        m_x = x;
        m_y = y;
    }
    
    void print() {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")" << std::endl;
    }
    
    friend double distanceFrom(Point2d p1, Point2d p2);
};

double distanceFrom(Point2d p1, Point2d p2) {
    return sqrt((p2.m_x - p1.m_x) * (p2.m_x - p1.m_x) + (p2.m_y - p1.m_y) * (p2.m_y - p1.m_y));
}

int main() {
    Point2d p1;
    Point2d p2(3.0, 4.0);
    p1.print();
    p2.print();
    std::cout << "Distance between two points: " << distanceFrom(p1, p2) << std::endl;
}
