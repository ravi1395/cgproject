#include <stdio.h>
#include <GL/glut.h>

void display_bargraph();
void display_pigraph();
void display_graph3();

void drawbitmap(char *string, float x, float y)
{
    char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, h, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void render()
{
    /* let list be the list of elements to be displayed at the given position, with x and y being the co-ordinates now we shall dislay the given text as per the given input */
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1, 0, 0);
        drawbitmap(" CG project", 735, 150);
        drawbitmap(" data visualisation", 725, 250);
        drawbitmap(" by Ravi.C and Prajwal .DP", 1200, 700);
        drawbitmap(" press right mouse button for menu ", 650, 350);
    glutSwapBuffers();
    glFlush();
}
//menu function
void menu(int id)
{
  switch(id)
  {
      case 0: exit(0);

      case 1: display_bargraph();
              break;

      case 2: display_pigraph();
              break;

      case 3: display_graph3();
              break;

   }
  glutPostRedisplay();
}
void showmenu()
{
    glutCreateMenu(menu);
    glutAddMenuEntry("exit",0);
    glutAddMenuEntry("bar graph",1);
    glutAddMenuEntry("pi graph",2);
    glutAddMenuEntry("graph3",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("data visualistaion project");
    glutDisplayFunc(render);
    glutIdleFunc(render);
    glutReshapeFunc(reshape);
    gluOrtho2D(0, 1000, 0, 1000);
    showmenu();
    init();
    glutMainLoop();

    return 0;
}

void display_bargraph()
{
    /* enter code here */
}
void display_pigraph()
{
    /* enter the pigraph display code here */
}
void display_graph3()
{
    /* enter the code here */
}
