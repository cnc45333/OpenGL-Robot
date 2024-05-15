#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

double translateX = 0.0;
double translateY = 0.0;
double translateZ = 0.0;
double rotateX = 0.0;
double rotateY = 0.0;
double rotateZ = 0.0;
double animationY = 0.0;
double rotateArmUD = 0.0;
double rotateArmFB = 0.0;
double rotateForearmUD = 0.0;
double rotateForearmFB = 0.0;
int animation = 2;
int t = 0;

void drawLeftArm() {
  double convert = 3.1415926535/180;
  glBegin(GL_QUAD_STRIP);
  //cylinder side
  for ( int j = 0; j <= 360; j+=5) {
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-1, 0.25*cos(convert*j)+2,.25*sin(convert*j));
    glVertex3f(-2.5, 0.25*cos(convert*j)+2,.25*sin(convert*j));
  } //for
  glEnd();

  //top and bottom
  for (double i = -1; i <= -2.5; i-=1.5) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 1.0, 0.5);
    glVertex3f(i,2,0);
    for (int k = 0; k <= 360; k+= 5){
      glVertex3f(i,0.25*cos(convert*k)+2, .25*sin(convert*k));
    }
    glEnd();
  }
} //drawLeftArm


void drawRightArm() {
  double convert = 3.1415926535/180;
  glBegin(GL_QUAD_STRIP);
  //cylinder side
  for ( int j = 0; j <= 360; j+=5) {
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1, 0.25*cos(convert*j)+2,.25*sin(convert*j));
    glVertex3f(1.75, 0.25*cos(convert*j)+2,.25*sin(convert*j));
  } //for
  glEnd();

  //top and bottom
  for (double i = 1; i <= 1.75; i+=0.75) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 1.0, 0.5);
    glVertex3f(i,2,0);
    for (int k = 0; k <= 360; k+= 5){
      glVertex3f(i,0.25*cos(convert*k)+2, .25*sin(convert*k));
    }
    glEnd();
  }
}//drawRightArm

void drawRightArmBottom() {
 double convert = 3.1415926535/180;
  glBegin(GL_QUAD_STRIP);
  //cylinder side
  for ( int j = 0; j <= 360; j+=5) {
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.75, 0.25*cos(convert*j)+2,.25*sin(convert*j));
    glVertex3f(2.5, 0.25*cos(convert*j)+2,.25*sin(convert*j));
  } //for
  glEnd();

  //top and bottom
  for (double i = 1.75; i <= 2.5; i+=0.75) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 1.0, 0.5);
    glVertex3f(i,2,0);
    for (int k = 0; k <= 360; k+= 5){
      glVertex3f(i,0.25*cos(convert*k)+2, .25*sin(convert*k));
    }
    glEnd();
  }
}

void drawHead() {
 //Back 
  glBegin(GL_POLYGON);
  glColor3f(0.0,1.0,1.0);
  glVertex3f(.5, 4, -.5);
  glColor3f(0.0, 0.5, 1.0);
  glVertex3f(.5, 3, -.5);
  glColor3f(0.0, 1.0, 0.5);
  glVertex3f(-.5, 3, -.5);
  glColor3f(0.0, 0.5, 0.5);
  glVertex3f(-.5, 4, -.5);
  glEnd();

  //Front
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 1.0);
  glVertex3f(-.5, 4, .5);
  glColor3f(0.0, 0.5, 1.0);
  glVertex3f(-.5, 3, .5);
  glColor3f(0.0, 1.0, 0.5);
  glVertex3f(.5, 3, .5);
  glColor3f(0.0, 0.5, 0.5);
  glVertex3f(.5, 4, .5);
  glEnd();

  //Right
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 1.0);
  glVertex3f(.5,4,.5);
   glColor3f(0.0, 0.5, 1.0);
  glVertex3f(.5,3,.5);
   glColor3f(0.0, 1.0, 0.5);
  glVertex3f(.5,3,-.5);
   glColor3f(0.0, 0.5, 0.5);
  glVertex3f(.5,4,-.5);
  glEnd();

  //Left
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 1.0);
  glVertex3f(-.5,4,.5);
   glColor3f(0.0, 0.5, 1.0);
  glVertex3f(-.5,4,-.5);
   glColor3f(0.0, 1.0, 0.5);
  glVertex3f(-.5,3,-.5);
   glColor3f(0.0, 0.5, 0.5);
  glVertex3f(-.5,3,.5);
  glEnd();

  //Top
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 1.0);
  glVertex3f(-.5,4,.5);
   glColor3f(0.0, 0.5, 1.0);
  glVertex3f(-.5,4,-.5);
   glColor3f(0.0, 1.0, 0.5);
  glVertex3f(.5,4,-.5);
   glColor3f(0.0, 0.5, 0.5);
  glVertex3f(.5,4,.5);
  glEnd();

  //Bottom
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 1.0);
  glVertex3f(-.5,3,.5);
   glColor3f(0.0, 0.5, 1.0);
  glVertex3f(-.5,3,-.5);
  glColor3f(0.0, 1.0, 0.5);
  glVertex3f(.5,3,-.5);
  glColor3f(0.0, 0.5, 0.5);
  glVertex3f(.5,3,.5);
  glEnd();
}//drawHead

void drawBody() {
  //Back 
  glBegin(GL_POLYGON);
  glColor3f(0.0,1.0,1.0);
  glVertex3f(-1, 3, -1);
  glVertex3f(1, 3, -1);
  glVertex3f(1, 1, -1);
  glVertex3f(-1, 1, -1);
  glEnd();

  //Front
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 1.0);
  glVertex3f(1, 1, 1);
  glVertex3f(-1, 1, 1);
  glVertex3f(-1, 3, 1);
  glVertex3f(1, 3, 1);
  glEnd();

  //Right
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 1.0);
  glVertex3f(1,3,1);
  glVertex3f(1,1,1);
  glVertex3f(1,1,-1);
  glVertex3f(1,3,-1);
  glEnd();

  //Left
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 1.0);
  glVertex3f(-1,3,1);
  glVertex3f(-1,3,-1);
  glVertex3f(-1,1,-1);
  glVertex3f(-1,1,1);
  glEnd();

  //Top
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 1.0);
  glVertex3f(1,3,1);
  glVertex3f(-1,3,-1);
  glVertex3f(1,3,-1);
  glVertex3f(1,3,1);
  glEnd();

  //Bottom
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 1.0);
  glVertex3f(-1,1,1);
  glVertex3f(-1,1,-1);
  glVertex3f(1,1,-1);
  glVertex3f(1,1,1);
  glEnd();
}//drawBody

void drawRightLeg() {
  double convert = 3.1415926535/180;
  glBegin(GL_QUAD_STRIP);
  //cylinder side
  for ( int j = 0; j <= 360; j+=5) {
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.25*cos(convert*j)+0.5, 1, .25*sin(convert*j));
    glVertex3f(0.25*cos(convert*j)+0.5, -1,.25*sin(convert*j));
  } //for
  glEnd();

  //top and bottom
  for (int i = -1; i <= 1; i+=2) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 1.0, 0.5);
    glVertex3f(0.5,i,0);
    for (int k = 0; k <= 360; k+= 5){
      glVertex3f(0.25*cos(convert*k)+0.5, i, .25*sin(convert*k));
    }
    glEnd();
  }
}//drawRightLeg

void drawLeftLeg() {
  double convert = 3.1415926535/180;
  glBegin(GL_QUAD_STRIP);
  //cylinder side
  for ( int j = 0; j <= 360; j+=5) {
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.25*cos(convert*j)-.5, 1, .25*sin(convert*j));
    glVertex3f(0.25*cos(convert*j)-.5, -1,.25*sin(convert*j));
  } //for
  glEnd();

  //top and bottom
  for (int i = -1; i <= 1; i+=2) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 1.0, 0.5);
    glVertex3f(-.5,i,0);
    for (int k = 0; k <= 360; k+= 5){
      glVertex3f(0.25*cos(convert*k)-.5, i, .25*sin(convert*k));
    }
    glEnd();
  }
} //drawLeftLeg

void drawAxis() {
  glBegin(GL_LINES);
  glColor3f(1.0, 1.0, 1.0);
  glVertex3f(0.0,0.0,0.0);
  glVertex3f(10.0, 0.0, 0.0);

  glColor3f(1.0, 1.0, 1.0);
  glVertex3f(0.0,0.0,0.0);
  glVertex3f(0.0, 10.0, 0.0);

  glColor3f(1.0, 1.0, 1.0);
  glVertex3f(0.0,0.0,0.0);
  glVertex3f(0.0, 0.0, 10.0);
  glEnd();
}

void reset() {
  translateX = 0.0;
  translateY = 0.0;
  translateZ = 0.0;
  rotateX = 0.0;
  rotateY = 0.0;
  rotateZ = 0.0;
  animationY = 0.0;
  rotateArmUD = 0.0;
  rotateArmFB = 0.0;
  rotateForearmUD = 0.0;
  rotateForearmFB = 0.0;
  t = 0;
  
  
  glClearColor(0.0, 0.0, 0.0, 1.0);
  
  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  
  gluPerspective(80, 4.0/3.0, 1, 40);
 
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(3.0,4.0,5.0,0,0,0,0,1,0);
   
  drawLeftLeg();
  drawRightLeg();
  drawBody();
  drawHead();
  drawLeftArm();
  drawRightArm();
  drawRightArmBottom();
  drawAxis();
  
  glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y)
{
  if (key ==  '0') {
      exit(0); //exit program
  }else if (key == '1') {
    //animation
    animation = 1;
  }else if (key == '2') {
    //no animation
    animation = 2;
  }else if (key == 'w') {
    //translate up
    translateY += 0.5;
  }else if (key == 's') {
    //translate down
    translateY -= 0.5;
  }else if (key == 'a') {
    //translate left
    translateX -= 0.5;
  }else if (key == 'd') {
    //translate right
    translateX += 0.5;
  }else if (key == 'q') {
    //translate toward WCS
    if (animation == 2)
      translateZ -= 0.5;
    else {
      	if(t == 0) {
	  animationY -= 20;
	  translateZ -= 0.1;
	  t++;
	}else if(t == 1) {
	  animationY += 20;
	  translateZ -= 0.1;
	  t++; 
        }else if (t == 2) {
	  animationY += 20;
	  translateZ -= 0.1;
	  t++;
	}else if( t == 3) {
	  animationY -= 20;
	  translateZ -= 0.1;
	  t = 0;
	}
    }
  }else if (key == 'e') {
    //translate away from WCS
    if (animation == 2) {
      translateZ += 0.5;
    }  else {
	if(t == 0) {
	  animationY += 20;
	  translateZ += 0.1;
	  t++;
	}else if(t == 1) {
	  animationY -= 20;
	  translateZ += 0.1;
	  t++; 
        }else if (t == 2) {
	  animationY -= 20;
	  translateZ += 0.1;
	  t++;
	}else if( t == 3) {
	  animationY += 20;
	  translateZ += 0.1;
	  t = 0;
	}
    }
  }else if (key == 'x') {
    //rotate around x axis
    rotateX += 1;
  }else if (key == 'c') {
    //rotate around y axis
    rotateY += 1;
  }else if (key == 'z') {
    //rotate around z axis
    rotateZ += 1;
  }else if (key == 'j') {
    // rotate arm clockwise up and down
    if (rotateArmUD > -75)
      rotateArmUD -= 1;
  }else if (key == 'u') {
    //rotate arm counterclockwise up and down
    if (rotateArmUD < 75)
      rotateArmUD += 1;
  }else if (key == 'i'){
    //rotate arm clockwise up front and back
    if (rotateArmFB > -75)
      rotateArmFB -= 1;
  }else if (key == 'k') {
    //rotate arm counterclockwise front and back
    if (rotateArmFB < 75)
      rotateArmFB += 1;
  }else if (key == 'h') {
    //rotate forearm clockwise up and down
     if (rotateForearmUD > -75)
      rotateForearmUD -= 1;
  }else if (key == 'y') {
    //rotate forearm counterclockwise up and down
    if (rotateForearmUD < 75)
      rotateForearmUD += 1;
  }else if (key == 'o') {
    //rotate forearm clockwise front and back
    if (rotateForearmFB > -75)
      rotateForearmFB -= 1;
  }else if (key == 'l') {
    //rotate forearm counterclockwise front and back
    if (rotateForearmFB < 75)
      rotateForearmFB += 1;
  }else if (key == 'r') {
    //reset display
    reset();
  }
}



void display(void)   // Create The Display Function
{
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
 gluPerspective(80, 4.0/3.0, 1, 40);
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(3.0,4.0,5.0,0,0,0,0,1,0);
  
  glPushMatrix();
  glTranslatef(translateX, translateY, translateZ);
  glRotatef(rotateX, 1, 0, 0);
  glRotatef(rotateY, 0, 1, 0);
  glRotatef(rotateZ, 0, 0, 1);

  drawHead();
  drawLeftArm();

  glPushMatrix();
  glRotatef(animationY, 0, 1, 0);
  
  drawLeftLeg();
  drawRightLeg();
  drawBody();
  glPopMatrix();
 

  glPushMatrix();
  glTranslatef(1, 2, 0);
  glRotatef(rotateArmFB, 0, 1 ,0);
  glTranslatef(-1, -2, 0);

  glTranslatef(1,2,0);
  glRotatef(rotateArmUD, 0, 0, 1 );
  glTranslatef(-1, -2,0);

  drawRightArm();

  glPushMatrix();
  glTranslatef(1.75, 2, 0);
  glRotatef(rotateForearmFB, 0, 1 ,0);  
  glRotatef(rotateForearmUD, 0, 0, 1 );
  glTranslatef(-1.75, -2, 0);
  drawRightArmBottom();
  glPopMatrix();

  glPopMatrix();
 
  
  drawAxis();

  
  
  glutSwapBuffers();
}//display

void init() {
  
 
  glClearColor(0.0, 0.0, 0.0, 1.0);
  
  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  
  gluPerspective(80, 4.0/3.0, 1, 40);
 
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(3.0,4.0,5.0,0,0,0,0,1,0);
   
  drawLeftLeg();
  drawRightLeg();
  drawBody();
  drawHead();
  drawLeftArm();
  drawRightArm();
  drawRightArmBottom();
  drawAxis();


  glutSwapBuffers();
}


int main (int argc, char** argv)
{
/* This main function sets up the main loop of the program and continues the
   loop until the end of the data is reached.  Then the window can be closed
   using the 0 key.						  */
	
	//while (currExample != 0)
	{
	  glutInit            ( &argc, argv ); 
	  glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH ); 
	  glutInitWindowSize  ( WIDTH,HEIGHT );
	  glutInitWindowPosition(100,100);
	  glutCreateWindow    ( "6050 Assignment 4" );
	  glEnable(GL_DEPTH_TEST);
	  glutDisplayFunc     (display);
	  glutIdleFunc	      (display);
	  glutKeyboardFunc    (keyPressed);
	  //glutSpecialFunc     (keySpecial);
	  init();			       //create_window
		
	  glutMainLoop();                 // Initialize The Main Loop

		
	}

} //main

