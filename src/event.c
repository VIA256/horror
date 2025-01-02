#include "event.h"

#include <GL/gl.h>

#define UNUSED(arg) (void)(arg)

void event_resize(GLFWwindow* window, int width, int height){
  UNUSED(window);
  
  glViewport(-1, -1, width, height);
}
