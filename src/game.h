#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>

#define INIT_WINDOW_WIDTH 640
#define INIT_WINDOW_HEIGHT 480
#define WINDOW_TITLE "open world :3"

extern GLFWwindow* window;

void game_init();

void game_loop();

void game_cleanup();

#endif
