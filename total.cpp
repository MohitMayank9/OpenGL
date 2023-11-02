//1)final Square rotation translation

#include <GL/freeglut.h>

float squareX = 0.0;
float squareY = 0.0;
float rotationAngle = 0.0;
float translationStep = 0.05;
float rotationStep = 5.0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();

    // Apply translation and rotation
    glTranslatef(squareX, squareY, 0.0);
    glRotatef(rotationAngle, 0.0, 0.0, 1.0);

    // Draw the square
    glBegin(GL_QUADS);
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.2, 0.2);
    glVertex2f(-0.2, 0.2);
    glEnd();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
    case 'W':
        squareY += translationStep;  // Move the square up
        break;
    case 's':
    case 'S':
        squareY -= translationStep;  // Move the square down
        break;
    case 'a':
    case 'A':
        squareX -= translationStep;  // Move the square left
        break;
    case 'd':
    case 'D':
        squareX += translationStep;  // Move the square right
        break;
    case 'r':
    case 'R':
        rotationAngle += rotationStep;  // Rotate the square clockwise
        break;
    case 'l':
    case 'L':
        rotationAngle -= rotationStep;  // Rotate the square counterclockwise
        break;
    }

    glutPostRedisplay();  // Trigger redrawing
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Square Translation and Rotation");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);  // Register the keyboard callback

    glutMainLoop();
    return 0;
}
//==============================================

//2 triangle rotation and translation
#include <GL/freeglut.h>

float triangleX = 0.0;
float triangleY = 0.0;
float rotationAngle = 0.0;
float translationStep = 0.05;
float rotationStep = 5.0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();

    // Apply translation and rotation
    glTranslatef(triangleX, triangleY, 0.0);
    glRotatef(rotationAngle, 0.0, 0.0, 1.0);

    // Draw the triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.2);
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.2, -0.2);
    glEnd();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
    case 'W':
        triangleY += translationStep;  // Move the triangle up
        break;
    case 's':
    case 'S':
        triangleY -= translationStep;  // Move the triangle down
        break;
    case 'a':
    case 'A':
        triangleX -= translationStep;  // Move the triangle left
        break;
    case 'd':
    case 'D':
        triangleX += translationStep;  // Move the triangle right
        break;
    case 'r':
    case 'R':
        rotationAngle += rotationStep;  // Rotate the triangle clockwise
        break;
    case 'l':
    case 'L':
        rotationAngle -= rotationStep;  // Rotate the triangle counterclockwise
        break;
    }

    glutPostRedisplay();  // Trigger redrawing
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Triangle Translation and Rotation");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);  // Register the keyboard callback

    glutMainLoop();
    return 0;
}

//===========================================
//3)circle with translation
#include <GL/freeglut.h>
#include <math.h>

float circleX = 0.0;
float circleY = 0.0;
float circleRadius = 0.2;  // Radius of the circle
float stepSize = 0.05;     // Translation step size

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();

    // Translate the circle to its position
    glTranslatef(circleX, circleY, 0.0);

    // Draw the circle
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 360; i++) {
        float angle = i * M_PI / 180;
        glVertex2f(cos(angle) * circleRadius, sin(angle) * circleRadius);
    }
    glEnd();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h) {
        gluOrtho2D(-1.0, 1.0, -1.0 * (GLfloat)h / (GLfloat)w, 1.0 * (GLfloat)h / (GLfloat)w);
    }
    else {
        gluOrtho2D(-1.0 * (GLfloat)w / (GLfloat)h, 1.0 * (GLfloat)w / (GLfloat)h, -1.0, 1.0);
    }

    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
    case 'W':
        circleY += stepSize;  // Move the circle up
        break;
    case 's':
    case 'S':
        circleY -= stepSize;  // Move the circle down
        break;
    case 'a':
    case 'A':
        circleX -= stepSize;  // Move the circle left
        break;
    case 'd':
    case 'D':
        circleX += stepSize;  // Move the circle right
        break;
    }

    glutPostRedisplay();  // Trigger redrawing
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circle Translation Example");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);  // Register the keyboard callback

    glutMainLoop();
    return 0;
}
//==================================================

//4)final simple circle

#include <GL/freeglut.h>
#include <math.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);  // Set color to red (R, G, B)
    glLoadIdentity();

    // Draw the circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0, 0.0);  // Center of the circle
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159265 / 180.0;
        float x = 0.5 * cos(angle);  // Radius of 0.5 (adjust as needed)
        float y = 0.5 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspectRatio = (float)w / (float)h;
    gluOrtho2D(-1.0 * aspectRatio, 1.0 * aspectRatio, -1.0, 1.0);  // Adjust as needed
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Red Circle Example");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
//=====================================================
//5)cube rotation with mouse

#include <GL/freeglut.h>

GLfloat rotationAngle = 0.0;  // Initial rotation angle
int lastMouseX = -1;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();

    // Set the camera position and orientation
    gluLookAt(4.0, 4.0, 4.9, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0);

    // Apply the rotation transformation
    glRotatef(rotationAngle, 0.0, 1.0, 0.0);

    // Draw the cube wireframe
    glutWireCube(2.0);

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'r' || key == 'R') {
        rotationAngle += 5.0;  // Increase the rotation angle
        glutPostRedisplay();  // Trigger redrawing
    }
    if (key == 'l' || key == 'L') {
        rotationAngle -= 5.0;  // Decrease the rotation angle
        glutPostRedisplay();  // Trigger redrawing
    }
}

void mouseMotion(int x, int y) {
    if (lastMouseX >= 0) {
        int deltaX = x - lastMouseX;
        rotationAngle += deltaX;
        glutPostRedisplay();  // Trigger redrawing
    }
    lastMouseX = x;
}

void mousePassiveMotion(int x, int y) {
    lastMouseX = x;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Cube Wireframe");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);  // Register the keyboard callback
    glutMotionFunc(mouseMotion);  // Register the mouse motion callback
    glutPassiveMotionFunc(mousePassiveMotion);

    glutMainLoop();
    return 0;
}
//=================================================
//6)
//only rotation left and right with keyboard


#include <GL/freeglut.h>

GLfloat rotationAngle = 0.0;  // Initial rotation angle

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();

    // Set the camera position and orientation
    gluLookAt(4.0, 4.0, 4.9, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0);

    // Apply the rotation transformation
    glRotatef(rotationAngle, 0.0, 1.0, 0.0);

    // Draw the cube wireframe
    glutWireCube(2.0);

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'r' || key == 'R') {
        rotationAngle += 5.0;  // Increase the rotation angle
        glutPostRedisplay();  // Trigger redrawing
    }
    if (key == 'l' || key == 'L') {
        rotationAngle -= 5.0;  // Increase the rotation angle
        glutPostRedisplay();  // Trigger redrawing
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Cube Wireframe");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);  // Register the keyboard callback

    glutMainLoop();
    return 0;
}
