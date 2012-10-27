#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

static void
display(void)
{
	static GLfloat color[4]={0.0f, 0.0f, 0.0f, 1.0f};
	int i;

	for (i=0; i<3; i++) {
		color[i]+=1.0f/3.0f;
		if (color[i] > 1.0f) 
			color[i]=0.0f;
		else
			break;
	}

	glClearColor(color[0],color[1],color[2],color[3]);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glutSwapBuffers();
}

static void
idle(void)
{
	glutPostRedisplay();
}

static void
keyboard(unsigned char key, int x, int y)
{
	switch(key) {
		case 27:
		case 'q':
		case 'Q':
			exit(0);
		case 'f':
			glutFullScreen();
			break;
		case 'F':
			glutPositionWindow(0,0);
			glutReshapeWindow(640,480);
			break;
		default:
			fprintf(stderr,"key '%c' not handled\n",key);	
	}
}

int main(int argc, char **argv)
{

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);

	glutCreateWindow("TEST");
	glutFullScreen();

	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}

