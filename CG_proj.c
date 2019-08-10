#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <Gl/freeglut.h>
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#define MENU_SCREEN 4	
int d_sr[] = { 1,-1,4,2,6,-1 };
int wkt = 10;
int n=6;
int j;
char *str = "";
int a, b, c, d;
int click = 0, finish = 0;
int bal1 = 0, bal2 = 0;
char score[] = "0", over[2] = "0",ball[]="0", wic[2] = "0";
char scoret2[] = "0", overt2[] = "0",ballt2[]="0", wict2[] = "0";
int  player1 = 1, player2 = 0, ball1 = 0, ball2 = 0, wkt1 = 0, wkt2 = 0, score1 = 0, score2 = 0;
int theta[] = { 0.0,0.0,0.0 };
int flag = 1;
static GLint axis = 1;
void *font = GLUT_BITMAP_TIMES_ROMAN_24;
int xc = 1000, yc = 600;
float angle;
GLfloat x, y, z, r;
int startGame = 0, gameOver = 0;


void turn(int a, int b,int c,int d)
{
	
	glBegin(GL_QUADS);
	glVertex2i(a,860);
	glVertex2i(b,900);
	glVertex2i(c,900);
	glVertex2i(d,860);
	glEnd();
	glFlush();
}

void needle()
{
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_QUADS);
	glVertex2f(1000, 600);  
	glVertex2f(1150, 630);   
	glVertex2f(1300, 600);   
	glVertex2f(1150,570);
	glEnd();
}

void needle1()
{
	glColor3f(0.6, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(1150, 630);
	glVertex2f(1300, 600);
	glVertex2f(1150, 570);
	glEnd();
}

void circle1(GLfloat x, GLfloat y, GLfloat z, GLfloat r)
{
	glColor3f(x,y,z);
	glBegin(GL_LINE_LOOP);
	for (angle = 0.0; angle <= 2 * 3.142; angle += 0.7)
	{
		int x = xc + (r * cos(angle));
		int y = yc + (r * sin(angle));
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

void circle(GLfloat x, GLfloat y, GLfloat z, GLfloat r)
{
	glColor3f(x,y,z);
	glBegin(GL_POLYGON);
	for (angle = 0.0; angle <= 2 * 3.142; angle += 0.1)
	{
		int x = xc + (r * cos(angle));
		int y = yc + (r * sin(angle));
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}


void line()
{
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	
	glVertex2i(1000, 600);
	glVertex2i(1350, 600);

	glVertex2i(1000, 600);
	glVertex2f(1175, 903.108);

	glVertex2i(1000, 600);
	glVertex2i(825,903.108);

	glVertex2i(1000, 600);
	glVertex2i(650,600);

	glVertex2i(1000, 600);
	glVertex2i(825,296.89);

	glVertex2i(1000, 600);
	glVertex2i(1175,296.891);

	glEnd();
	glFlush();
}


void output(int x, int y, char *string)
{
	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}



void startScreenDisplay()
{
	
	glClearColor(0.658, 0.643, 0.713,0);
	glColor3f(1, 0, 0);
	output(800, 900, "BOARD");
	glColor3f(1,1,1);
	output(950, 900, "CRICKET");
	glColor3f(0, 0, 0);
	output(800, 890, "_________________");
	glColor3f(1, 0, 0);
	output(100, 800, "INSTRUCTIONS");
	glColor3f(0, 0, 0);
	output(100, 790, "______________");
	glColor3f(1, 1, 1);
	output(100, 700, "Press 'q' to Exit");
	glColor3f(1, 0, 0);
	output(100, 600, "Press 't' or 'left mouse button' to spin the needle ");
	glColor3f(1, 1, 1);
	output(100, 500, "Press 'g' or 'right mouse button' to stop the needle");
	glColor3f(1, 0, 0);
	output(100, 400, "Press 's' to start the game ");
	glColor3f(1, 1, 1);
	output(100, 300, "Press r to restart the game");
	glColor3f(1, 0, 0);
	output(100, 200, "Press Middle Mouse Button to Choose Number of overs ");

}
void quad(int a, int b, int c, int d, int e, int f,int g, int h)
{
	glBegin(GL_LINE_LOOP);
	glVertex2i(e, a);
	glVertex2i(f, b);
	glVertex2i(g, c);
	glVertex2i(h, d);
	glEnd();
	glFlush();
}

void gameScreen()
{
	glClearColor(0.658, 0.643, 0.713, 0);
	glColor3f(0,0,1);
	if (str[1] == 'I')
	{
		output(900, 850, str);
	}
	else {
		output(800, 900, "CONGRATULATIONS!!!!!!");
		output(920, 850, str);
		 }  
	glColor3f(1, 0,0);
	output(900, 700, "TEAM1 :");
	glColor3f(0, 0, 1);
	output(750, 625, "SCORE:");
	output(750, 525, "OVER:");
	output(750, 425, "WICKET:");
	glColor3f(0, 0, 0);
	quad(600, 650, 650, 600, 900, 900, 1000, 1000);
	quad(500, 550, 550, 500, 900, 900, 1000, 1000);
	quad(400, 450, 450, 400, 900, 900, 1000, 1000);
	glColor3f(1, 1, 1);
	output(950, 620, score);
	output(950, 520, over);
	output(950, 420, wic);

	glColor3f(1,0,0);
	output(1100, 700, "TEAM2 :");
	glColor3f(0, 0, 0);
	quad(600, 650, 650, 600, 1100, 1100, 1200, 1200);
	quad(500, 550, 550, 500, 1100, 1100, 1200, 1200);
	quad(400, 450, 450, 400, 1100, 1100, 1200, 1200);
	glColor3f(1, 1, 1);
	output(1150, 620, scoret2);
	output(1150, 520, overt2);
	output(1150, 420, wict2);
	glColor3f(0, 0, 1);
	output(750, 300, "PRESS 'r' TO START A NEW GAME");
	
}

void GameScreenDisplay()
{
	circle(0.403, 0.360, 0.541, 420);
	circle(0.450, 0.427, 0.533, 350);   
	circle1(1, 1, 1, 450);
	circle1(0, 0, 0, 430);
	circle1(1, 1, 1, 400);
	circle1(0, 0, 0, 370);
    
	glColor3f(1, 1, 1);
	output(980, 900, "OUT");
	glColor3f(1, 1, 1);
	output(1263.10, 765, "1");
	glColor3f(1, 1, 1);
	output(736.89, 755, "4");
	glColor3f(1, 1, 1);
	output(736.89, 445, "2");
	glColor3f(1, 1, 1);
	output(1000, 290, "6");
	glColor3f(1, 1, 1);
	output(1223.10, 445, "OUT");

	glColor3f(1,1,1);
	output(100, 1000, "CLICK TO BEGIN THE GAME......");
	
	glColor3f(0,0,1);
	output(100, 860, "TEAM1 :");
	//glColor3f(1, 1, 1);
	output(100, 725, "SCORE:");
	output(100, 625, "OVER:");
	output(100, 525, "WICKET:");
	glColor3f(0, 0, 0);
	quad(700,750,750,700 ,250,250,400,400);
	quad(600, 650, 650, 600, 250, 250, 400, 400);
	quad(500, 550, 550, 500, 250, 250, 400, 400);
	glColor3f(1, 1, 1);
	output(325, 720, score);
	output(325, 615, over);
	output(340, 620, "(");
	output(350, 615, ball);
	output(365, 620, ")");
	output(325, 520, wic);
	glColor3f(1, 0, 0);
	turn(250, 250, 300, 300);
	
	if (ball1 == n || wkt1 == wkt)
	{
		
		glColor3f(0.658, 0.643, 0.713);
		turn(250, 250, 300, 300);
		glColor3f(1, 0, 0);
		turn(1650, 1650, 1700, 1700);
		
	}
	
	glColor3f(0, 0, 1);
    output(1500, 860, "TEAM2 :");
	output(1500, 725, "SCORE:");
	output(1500, 625, "OVER:");
	output(1500, 525, "WICKET:");
	glColor3f(0, 0, 0);
	quad(700, 750, 750, 700, 1650,1650,1800,1800);
	quad(600, 650, 650, 600, 1650, 1650, 1800, 1800);
	quad(500, 550, 550, 500, 1650, 1650, 1800, 1800);
	glColor3f(1, 1, 1);
	output(1725, 720, scoret2);
	output(1725, 615, overt2);
	output(1740, 620, "(");
	output(1750, 615, ballt2);
	output(1765, 620, ")");
	output(1725, 520, wict2);
	line();
	glPushMatrix();
	glTranslatef(1000, 600, 0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);
	glTranslatef(-1000, -600, 0);
	needle();
	needle1();
	glPopMatrix();
}



void display()
{

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0.658, 0.643, 0.713, 0);   
	if (!startGame&&!gameOver)
		startScreenDisplay();
	
	if (startGame && !gameOver )
	     GameScreenDisplay();
	
	if (finish == 1)
		gameScreen();
    glutSwapBuffers();

}
void spin()
{
	theta[axis] += 5;
	if (theta[axis] >= 360.0)
		theta[axis] -= 360.0;
	glutPostRedisplay();
}



void scoreboard1(int j)
{
	ball1++;
	printf("%d", ball1);
	bal1++;
	printf("%d", bal1);
	if (ball1 <= n && wkt1 < wkt)
	{
		if (d_sr[j] == -1)
		{
			wkt1++;
			printf("\tout\twkt=%d\n", wkt1);
			itoa(wkt1,wic,10);
		}
		
		else
		{
			score1 += d_sr[j];
			printf("\t%d\n", d_sr[j]);
			itoa(score1, score, 10);
		}
	}
	if (ball1 == n || wkt1 == wkt)
	{
		printf("final score of the player1=%d/%d\n", score1, wkt1);
		player1 = 0;
		player2 = 1;
		glColor3f(0.658, 0.643, 0.713);
		turn(250, 250, 300, 300);
		glColor3f(1, 0, 0);
		turn(1600, 1600, 1650, 1650);
		printf("\n\nTEAM2 turn\n");
	}
}
void scoreboard2(int j)
{
	ball2++;
	bal2++;
	if (ball2 <= n && wkt2 < wkt)
	{
		if (d_sr[j] == -1)
		{
			wkt2++;
			printf("\tout\twkt=%d\n", wkt2);
			itoa(wkt2, wict2, 10);
		}
		else
		{
			score2 += d_sr[j];
			printf("\t%d\n", d_sr[j]);
			itoa(score2, scoret2, 10);
		}
	}
}

int get_j(int a)
{
	if (a > 0 && a <= 60)
		return 0;
	else if (a > 60 && a <= 120)
		return 1;
	else if (a > 120 && a <= 180)
		return 2;
	else if (a > 180 && a <= 240)
		return 3;
	else if (a > 240 && a <= 300)
		return 4;
	else if (a > 300 && a <= 0)
		return 5;

	else
		return 1;
}


void gameFunc()
{
	if (click == 1)
	{
		axis = 1;
		j = get_j(theta[2]);
		if (player1 == 1 && player2 == 0)
		{
			
			
			if (ball1 % 6 == 0) {
				printf("over%d\n", ball1 / 6  +1);
				itoa(ball1 / 6 +1 , over, 10);
				bal1 = 0;
				itoa(bal1, ball, 10);
			}
			scoreboard1(j);
			itoa(bal1, ball, 10);
		}
		else if (player1 == 0 && player2 == 1 && finish == 0)
		{
			
			if (ball2 % 6 == 0) {
				printf("over%d\n", ball2 / 6 + 1);
				itoa(ball2 / 6 + 1, overt2, 10);
				bal2 = 0;
			}
			scoreboard2(j);
			itoa(bal2, ballt2, 10);
			if (score2 > score1 || ball2 == n || wkt2 == wkt)
			{
				printf("final score of player2=%d/%d\n", score2, wkt2);
				if (score1 > score2)
				{
					printf("TEAM1 wins\n");
					str = "TEAM 1";
				}
				else if (score1 < score2)
				{
					printf("TEAM2 wins\n");
					str = "TEAM 2";
				}
				else {
					printf("tie\n");
					str = "TIE";
				}
				startGame = 0;
				finish = 1;
				gameOver = 1;
				
			}
		}
		click = 0;
	}
}


void myKeyboardFunc(unsigned char key, int x, int y)
{
	
	switch (key)
	{
	case 27:if (finish == 1)
		        exit(0);
		    break;
		
	case 'q':exit(0);
		     break;
		
	case 't':if (finish == 1)
	         {
		        glColor3f(1, 0, 0);
		        output(100, 500, str);
	         }
			 click = 1;
			 axis = 2;
			 break;
	
	case 'g':gameFunc();
		     break;

	case 's': startGame = 1;
		      gameOver = 0;
			  break;
	case 'r':startGame = 1;
		     gameOver = 0;
		     click = 0, finish = 0;
		     player1 = 1, player2 = 0, ball1 = 0, ball2 = 0, wkt1 = 0, wkt2 = 0, score1 = 0, score2 = 0;
		     theta[2] = 0;
		     flag = 1;
		     axis = 1;
			 bal1 = 0, bal2 = 0;
		     itoa(0, score, 10);
		     itoa(0, over, 10);
		     itoa(0, wic, 10);
			 itoa(0, ballt2, 10);
			 itoa(0, ball,10);
		     itoa(0, scoret2, 10);
		     itoa(0, overt2, 10);
		     itoa(0, wict2, 10);
		     GameScreenDisplay();
		     break;
	}
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (finish == 1)
			exit(0);
		click = 1;
		axis = 2;

	}
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		gameFunc();
	}
	
}
void selection(int ch)
{
	switch (ch)
	{
	case 1:n = 1;
		   n = n * 6;
		   break;
	case 2:n = 2;
		   n = n * 6;
		   break;
	case 3:n = 5;
		   n = n * 6;
		   break;
	case 4:n = 10;
		   n = n * 6;
		   break;
	case 5:n = 20;
		   n = n * 6;
		   break;
	}

}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1500, 1000);
    glutCreateWindow("Board Cricket");
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, 1850, 0, 1100 ,-20, 20);
	glMatrixMode(GL_MODELVIEW);
	glutDisplayFunc(display);
	glutIdleFunc(spin);
	glutKeyboardFunc(myKeyboardFunc);
	glutMouseFunc(mouse);
	glutCreateMenu(selection);
	glutAddMenuEntry("1 Over",1);
	glutAddMenuEntry("2 Overs", 2);
	glutAddMenuEntry("5 Overs", 3);
	glutAddMenuEntry("10 Overs", 4);
	glutAddMenuEntry("20 Overs", 5);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	glEnable(GL_DEPTH);
	glEnable(GL_LINE_SMOOTH);
	glutMainLoop();
}