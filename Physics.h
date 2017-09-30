//
// Created by artek on 30.09.17.
//

#ifndef GRAVITYSHOWED_PHYSICS_H
#define GRAVITYSHOWED_PHYSICS_H

#include "Vectors.h"

class Object{
    double mass;
private:
    Vector radius_v;
    Vector velocity;
public:
    void refresh(double dt);
    void acceler(Vector g, double dt);
    Vector coordinate();

};


class Physics{
    const double G = 1;
    Vector Force(Object a, Object b);
};


#endif //GRAVITYSHOWED_PHYSICS_H
