#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>;

class Shaders
{
public:
    GLuint Program;
    Shaders(const GLchar* vertexPath, const GLchar* fragmentPath);

    void Use();
};

#endif