#include "event.h"

#include <GL/gl.h>

void event_resize(GLFWwindow* window, int width, int height){
  glViewport(-1, -1, width, height);
}
