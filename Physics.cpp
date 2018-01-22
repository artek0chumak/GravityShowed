//
// Created by Артем Чумаченко on 13.12.2017.
//

#include "Physics.h"

void Object::set(float mass, glm::vec2 cordinate, glm::vec2 velocity) {
    this->mass = mass;
    this->cordinate = cordinate;
    this->velocity = velocity;
}

float Object::m() {
    return this->mass;
}

void Object::update(float t) {
    this->cordinate += this->velocity * t;
}

void Object::a(glm::vec2 ac, float t) {
    this->velocity += ac * t;
}

glm::vec2 Object::r() {
    return this->cordinate;
}

glm::vec2 Object::v() {
    return this->velocity;
}

void Object::update(glm::vec2 s) {
    this->cordinate -= s;
}

void Object::v_set(glm::vec2 v) {
    this->velocity -= v;
}

glm::vec2 Physics::Force(Object a, Object b) {
    glm::vec2 F;
    glm::vec2 R = (a.r() - b.r());
    F = G * a.m() * b.m() / (glm::length(R) * glm::length(R) * glm::length(R)) * R;
    return F;
}

void Physics::Collision(Object *a, Object *b) {
    if(glm::distance(a->r(), b->r()) < 0.1f) {
        glm::vec2 R = a->r() - b->r();
        float m = a->m(), M = b->m();
        float u_ = glm::length(b->v());
        float v_ = glm::length(a->v());

        glm::vec2 u = R * R * u_ / glm::length2(R);
        glm::vec2 v = R * R * v_ / glm::length2(R);
        glm::vec2 u1 = (2 * m * v + (m - M) * u) / (M + m);
        glm::vec2 v1 = (2 * M * u + (M - m) * v) / (M + m);

        a->v_set((v - v1));
        b->v_set((u - u1));
    }
}
