//
// Created by Артем Чумаченко on 13.12.2017.
//

#ifndef GRAVITY_PHYSICS_H
#define GRAVITY_PHYSICS_H
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/gtx/norm.hpp>

const float G = 0.000001;

class Object{
private:
    float mass;
    glm::vec2 cordinate;
    glm::vec2 velocity;
public:
    void set(float mass, glm::vec2 cordinate, glm::vec2 velocity);
    float m();
    void a(glm::vec2 ac, float t);
    void update(float t);
    void update(glm::vec2 s);
    void v_set(glm::vec2 v);
    glm::vec2 r();
    glm::vec2 v();
};

class Physics {
public:
    static glm::vec2 Force(Object a, Object b);
    static void Collision(Object *a, Object *b);
};


#endif //GRAVITY_PHYSICS_H
