#include "Vectors.h"

Vector::Vector() {
    x = 0;
    y = 0;
    z = 0;
}

Vector::~Vector() {
    free x;
    free y;
    free z;
}

template<typename T>
Vector::Vector(T x) {
    this->x = x;
    y = 0;
    z = 0;
}

template<typename T>
Vector::Vector(T x, T y) {
    this->x = x;
    this->y = y;
    z = 0;
}

template<typename T>
Vector::Vector(T x, T y, T z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector& Vector::operator=(Vector a) {
    return Vector(a.x, a.y, a.z) *;
}

Vector Vector::operator+(Vector a) {
    return Vector(a.x+x, a.y+y, a.z+z);
}

Vector Vector::operator-(Vector a) {
    return Vector(x-a.x, y-a.y, z-a.z);
}

bool Vector::operator==(Vector a) {
    return (x==a.x)&&(y==a.y)&&(z==a.z);
}

Vector Vector::operator*(double a) {
    return Vector(a*x, a*y, a*z);
}

double Vector::abs(Vector a) {
    return math.sqrt(x*x+y*y+z*z);
}
