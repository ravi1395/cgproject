#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>

#define n 10

char **list, **xlist, **ylist;
float pos_x[n], pos_y[n];

void drawbitmap(char *string, float x, float y)
{
    char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
    }
}

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
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
    glColor3f(0, 1, 0);
    for(int i = 0; i < n; i++)
        drawbitmap(xlist[i],pos_x[i], 0);
    for( int i = 0; i < n; i++)
        drawbitmap(ylist[i],0, pos_y[i]);
    for( int i = 0; i < n; i++)
        drawbitmap(list[i], pos_x[i], pos_y[i]);
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    /* input functions for entering the list names */
    /* calculating co-ordinates of the text functions i.e pos_x and pos_y */
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("data visualistaion project");
    glutDisplayFunc(render);
    glutIdleFunc(render);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();

    return 0;
}
