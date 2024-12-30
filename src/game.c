#include "game.h"

#include <stdio.h>
#include <stdlib.h>

GLFWwindow* window;

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
  
  glClearColor(0.1, 0.1, 0.1, 1.0);
}

void game_loop(){
  while(!glfwWindowShouldClose(window)){
    glClear(GL_COLOR_BUFFER_BIT);
    
    glfwSwapBuffers(window);
    
    glfwPollEvents();
  }
}

void game_cleanup(){
  glfwTerminate();
}
