#include "Physics.h"

void Object::refresh(double dt) {
    radius_v = radius_v + velocity*dt;
}

void Object::acceler(Vector g, double dt) {
    velocity = velocity + g*dt;
}

Vector Object::coordinate() {
    return radius_v;
}
