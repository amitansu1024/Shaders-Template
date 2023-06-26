#include <iostream>
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

using namespace std;
int HEIGHT = 640;
int WIDTH = 640;
double x, y;

int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "My triangle", NULL, NULL);
    if (!window) {
	fprintf(stderr, "Failed to open window\n");
	exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);


    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    for (;;) {
	double t = glfwGetTime();

	glfwGetWindowSize(window, &WIDTH, &HEIGHT);
	glfwGetCursorPos(window, &x, &y);

	HEIGHT = HEIGHT > 0 ? HEIGHT : 1;

	glViewport(0, 0, WIDTH, HEIGHT);

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.f, (GLfloat) WIDTH / (GLfloat) HEIGHT, 1.f, 100.f);
	

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.1f, 1.f, 0.f,
		  0.f, 20.f, 0.f,
		  0.f, 0.f, 1.f);

	glTranslatef(0.f, 15.f, 0.f);
	glRotatef(0.3f * (GLfloat) x + (GLfloat)t * 100, 0.f, 0.f, 1.f);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.f, 0.f);
	glVertex3f(-5.f, 0.f, -4.f);
	glColor3f(0.0f, 1.f, 1.f);
	glVertex3f(5.f, 0.f, -4.f);
	glColor3f(1.0, 2.f, 1.f);
	glVertex3f(0.f, 0.f, 6.f);
	glEnd();
	
	glMatrixMode(GL_MODELVIEW);

	glfwSwapBuffers(window);
	glfwPollEvents();

	if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
	    break;
	}
    }

    glfwTerminate();
    exit(EXIT_SUCCESS);
}
