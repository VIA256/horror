#include "game.h"
#include "event.h"

#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

#define INIT_WINDOW_WIDTH 640
#define INIT_WINDOW_HEIGHT 480
#define WINDOW_TITLE "open world :3"

static GLFWwindow* window;

void game_init(){
  if(!glfwInit()){
    printf("Unable to initialize GLFW\n");
    exit(-1);
  }
  
  window = glfwCreateWindow(INIT_WINDOW_WIDTH,
			    INIT_WINDOW_HEIGHT,
			    WINDOW_TITLE,
			    NULL,
			    NULL);
  if(!window){
    printf("Unable to create window\n");
    glfwTerminate();
    exit(-1);
  }
  
  glfwMakeContextCurrent(window);
  
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glViewport(-1, -1, INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT);

  glfwSetWindowSizeCallback(window, event_resize);
  glfwSetWindowAspectRatio(window, INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT);
}

void game_loop(){
  while(!glfwWindowShouldClose(window)){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor4d(1.0, 0.0, 0.0, 1.0);
    glVertex2d(0.0, 0.5);
    glColor4d(0.0, 1.0, 0.0, 1.0);
    glVertex2d(0.5, -0.5);
    glColor4d(0.0, 0.0, 1.0, 1.0);
    glVertex2d(-0.5, -0.5);
    glEnd();
    
    glfwSwapBuffers(window);
    
    glfwPollEvents();
  }
}

void game_cleanup(){
  glfwTerminate();
}
