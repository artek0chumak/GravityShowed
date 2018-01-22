#include <iostream>
#include "Scene.h"

int main(int argc, char *argv[]) {
    Scene s;
    s.Init();
    s.Loop();
    s.Exit();

    return 0;
}