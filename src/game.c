#include "game.h"
#include "event.h"

#include <GLFW/glfw3.h>
#include <GL/glu.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INIT_WINDOW_WIDTH 640
#define INIT_WINDOW_HEIGHT 480
#define WINDOW_TITLE "open world :3"
#define FOVY 90.0
#define ZNEAR 0.1
#define ZFAR 100.0

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
  glfwSetWindowSizeCallback(window, event_resize);
  glfwSetWindowAspectRatio(window, INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT);
  
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glViewport(-1, -1, INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT);
  glClearDepth(1.0);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_SMOOTH);
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(FOVY, (double)INIT_WINDOW_WIDTH/(double)INIT_WINDOW_HEIGHT, ZNEAR, ZFAR);
}

void game_loop(){
  while(!glfwWindowShouldClose(window)){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(0.0, 0.0, 0.0,
	      0.0, 0.0, 1.0,
	      0.0, 1.0, 0.0);

    static double a = 0.0;
    static double b = 0.0;
    static double c = 0.0;

    glTranslated(0.0, 0.0, 1.0);
    glRotated(a, 0.0, 0.0, 1.0);
    glRotated(b, 0.0, 1.0, 0.0);
    glRotated(c, 1.0, 0.0, 0.0);
    glTranslated(0.0, 0.0, -1.0);

    a += 1.0;
    b += 1.0;
    c += 1.0;
    
    glBegin(GL_TRIANGLES);
    glColor4d(1.0, 0.0, 0.0, 1.0);
    glVertex3d(0.0, 0.5, 1.0);
    
    glColor4d(0.0, 1.0, 0.0, 1.0);
    glVertex3d(0.5, -0.5, 1.0);
    
    glColor4d(0.0, 0.0, 1.0, 1.0);
    glVertex3d(-0.5, -0.5, 1.0);
    glEnd();
    
    glfwSwapBuffers(window);
    
    glfwPollEvents();
  }
}

void game_cleanup(){
  glfwDestroyWindow(window);
  glfwTerminate();
}
