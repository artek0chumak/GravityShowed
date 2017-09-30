#ifndef GRAVITYSHOWED_VECTORS_H
#define GRAVITYSHOWED_VECTORS_H

#include <math.h>

class Vector {
private: double x;
    double y;
    double z;

public:
    Vector();
    ~Vector();

    template< typename T>
    Vector(T x);

    template< typename T>
    Vector(T x, T y );

    template< typename T>
    Vector(T x, T y, T z );

    Vector& operator=(Vector a);
    Vector operator+(Vector a);
    Vector operator-(Vector a);
    bool operator==(Vector a);
    Vector operator*(double a);

    double abs(Vector a);
};


#endif //GRAVITYSHOWED_VECTORS_H
