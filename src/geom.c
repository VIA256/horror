#include <GL/gl.h>

void geom_drawQuad(double x, double y, double z,
		   double w, double h,
		   double ax, double ay, double az,
		   double r, double g, double b, double a){
  glPushMatrix();
  
  glTranslated(x, y, z);
  glRotated(ax, 1.0, 0.0, 0.0);
  glRotated(ay, 0.0, 1.0, 0.0);
  glRotated(az, 0.0, 0.0, 1.0);
  glTranslated(-x, -y, -z);
  
  glBegin(GL_TRIANGLES);
  
  glColor4d(r, g, b, a);
  
  glVertex3d(x-w, y+h, z);
  glVertex3d(x+w, y+h, z);
  glVertex3d(x+w, y-h, z);
  
  glVertex3d(x+w, y-h, z);
  glVertex3d(x-w, y-h, z);
  glVertex3d(x-w, y+h, z);
  
  glEnd();

  glPopMatrix();
}

/*TODO:
  switch to gles
 */
