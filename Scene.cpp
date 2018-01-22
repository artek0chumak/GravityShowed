//
// Created by Артем Чумаченко on 13.12.2017.
//

#include "Scene.h"

int key;
int action;

void Scene::Init() {
    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(800, 800, "Gravity", NULL, NULL);
    if(!window) {
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    int h, w;
    glfwGetFramebufferSize(window, &h, &w);
    glfwSetKeyCallback(window, key_callback);
    glViewport(0, 0, h, w);
    glOrtho(-zoom, zoom, -zoom, zoom, 0.0, -1.0);
}

void Scene::Loop() {
    while(!glfwWindowShouldClose(window)) {
        const float delta_T = 0.005;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if( i != j) {
                    obj[i].update(delta_T);
                    obj[i].a(Physics::Force(obj[j], obj[i]) / obj[i].m(), delta_T);
                    //Physics::Collision(&obj[i], &obj[j]);
                }
            }
        }
        if(velocity[0] < glm::length(obj[0].v())) {
            velocity[0] = glm::length(obj[0].v());
        }
        if(velocity[1] > glm::length(obj[0].v())) {
            velocity[1] = glm::length(obj[0].v());
        }

        track.push_back(std::array<std::pair<float, float>, 3>{std::pair<float, float>(obj[0].r().x, obj[0].r().y),
                         std::pair<float, float>(obj[1].r().x, obj[1].r().y),
                         std::pair<float, float>(obj[2].r().x, obj[2].r().y)});


        Display();
        Key();
        glfwSwapBuffers(window);
    }
}

void Scene::Exit() {
    std::fstream fout("/Users/artek.chumak/CLionProjects/Gravity/log");
    fout<<"v_max = "<<velocity[0]<<" v_min = "<<velocity[1]<<std::endl;
    fout.close();
    glfwTerminate();
}

Scene::Scene() {
    std::ifstream fin;

    fin.open("/Users/artek.chumak/CLionProjects/Gravity/init");
    float r1, ar, v1, av, m;
    fin>>r1>>ar>>v1>>av>>m;
    fin.close();

    glm::vec2 r = {r1 * 1.0f, 0.0}, v = {v1 * 1.0f, 0.0f};
    r = glm::rotate(r, ar / 180.0f * glm::pi<float>());
    v = glm::rotate(v, av / 180.0f * glm::pi<float>());
    velocity[0] = glm::length(v);
    velocity[1] = glm::length(v);

    for(int i = 0; i < N; i++) {
        obj[i].set(m, r, v);
        r = glm::rotate(r, glm::two_pi<float>() / N);
        v = glm::rotate(v, glm::two_pi<float>() / N);
    }

    mainObj = 2;
    rel = 1;
    zoom = 2;
}

void Scene::Display() {
    glfwPollEvents();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(int i = 0; i < N; i++) {
        glColor3d(1.0f / (i + 1) , 1.0f / (i + 2), 1.0f / (i + 4));
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(obj[i].r().x - obj[mainObj].r().x * rel, obj[i].r().y - obj[mainObj].r().y * rel);
        for (int j = 0; j <= 10; j++) {
            glVertex2f(
                    obj[i].r().x - obj[mainObj].r().x * rel + (0.05f * glm::cos(j * glm::two_pi<float>()/ (float)10.0)),
                    obj[i].r().y - obj[mainObj].r().y * rel + (0.05f * glm::sin(j * glm::two_pi<float>()/ (float)10.0))
            );
        }
        glEnd();
    }

    glColor3d(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    for(auto i = 0; i != track.size(); i++) {
        glVertex2f(track[i][0].first - track[i][mainObj].first * rel,
                   track[i][0].second - track[i][mainObj].second * rel);
    }
    glEnd();
    glColor3d(0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    for(auto i = 0; i != track.size(); i++) {
        glVertex2f(track[i][1].first - track[i][mainObj].first * rel,
                   track[i][1].second - track[i][mainObj].second * rel);
    }
    glEnd();
    glColor3d(0.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    for(auto i = 0; i != track.size(); i++) {
        glVertex2f(track[i][2].first - track[i][mainObj].first * rel,
                   track[i][2].second - track[i][mainObj].second * rel);
    }
    glEnd();
}

void Scene::Key()
{
    if (key == GLFW_KEY_1 && action == GLFW_PRESS) {
        rel = 1;
        mainObj = 0;
    }
    if (key == GLFW_KEY_2 && action == GLFW_PRESS) {
        rel = 1;
        mainObj = 1;
    }
    if (key == GLFW_KEY_3 && action == GLFW_PRESS) {
        rel = 1;
        mainObj = 2;
    }
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        rel = 0;
    }
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_I && action == GLFW_PRESS) {
        zoom += 0.1;
        Update_Zoom();
    }
    if (key == GLFW_KEY_O && action == GLFW_PRESS) {
        zoom -= 0.1;
        Update_Zoom();
    }
}

void Scene::Update_Zoom() {
    //glOrtho(-zoom, zoom, -zoom, zoom, 0.0, -1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-zoom, zoom, -zoom, zoom, 0.0, -1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void key_callback(GLFWwindow* window, int k, int scancode, int a, int mods) {
    key = k;
    action = a;
}