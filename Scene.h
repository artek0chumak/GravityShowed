//
// Created by Артем Чумаченко on 13.12.2017.
//

#ifndef GRAVITY_SCENE_H
#define GRAVITY_SCENE_H

#include "Physics.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/glm.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <array>

#define N 3

class Scene {
private:
    GLFWwindow * window;
    Object obj[N];
    std::vector<std::array<std::pair<float, float>, 3> > track;
    float velocity[2];
    int mainObj;
    short rel;
    float zoom;
public:
    Scene();
    void Init();
    void Display();
    void Loop();
    void Exit();
    void Key();
    void Update_Zoom();
};

void key_callback(GLFWwindow* window, int k, int scancode, int a, int mods);


#endif //GRAVITY_SCENE_H
