#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
#include<iostream>
#include <time.h>
using namespace std;

#define DEG2RAD 3.14159/180.0
float hexagon_r=20;
float op=0;
void *currentfont;
float hexagon_dx,hexagon_dy,hexagon_gx,hexagon_gy;
#define RADPERDEG 0.0174533
double theta=0;
int frameNumber =0;

int f=0,a=0,b=0,c=0,d=0;
float yLocation = 0.0f;
float bloby=0,blobx=0,cx1=0,cy1=0,cx2=0,cy2=0;
int c0=0,c1=0,c2=0,c3=0;
void init();
void draw_hexagon(float,float);
void drawCircle(float, float , float , int);
void drawCancerCells(float,float,int,int);

void setBackgroundColor();
void frame0();
void frame1();

void frame2();
void frame3();
void frame4();
void output(int, int ,const char *);
void verticleLine(int ,int ,int );
void hexagonCancer(int ,int);
void drawCircle(GLfloat , GLfloat , GLfloat,int ,int ,int );
void drawCircleCancer(GLfloat , GLfloat , GLfloat,int ,int ,int );
void drawFilledCircle(GLfloat , GLfloat , GLfloat);
void drawFilledCircle2(GLfloat , GLfloat , GLfloat);
void drawHollowCircle(GLfloat , GLfloat , GLfloat,int ,int ,int );
void CellCancer(int,int);
void cell(int,int);
void cell(int ,int ,int );
void cancerCellM(int,int);
void cancerCellB(int,int) ;
void melignant();
void secondSet();
void firstSet();
void humanBody();
void blobAnimation();

void bloodVessel();

void normalCells();

void cellanimation1();
void DrawEllipse(float, float,int,int);
void   hexagon(int,int);
void horzontalLine(int,int,int);


//void Arrow(GLdouble,GLdouble,GLdouble,GLdouble,GLdouble ,GLdouble ,GLdouble );
 void cancerCell(int ,int);
void mouseFunc(int,int,int,int);
void drawFilledElipse(GLfloat , GLfloat , GLfloat ,GLfloat);
void mouseMove(int, int);




void setFont(void *font)
{
    currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
    char *c;
    int len = (int) strlen(string);
    int i;
    glRasterPos3f(x,y,z);
    for(i = 0;i<len;i++)
    {
        glColor3f(0.0,0.0,0.0);
        glutBitmapCharacter(currentfont,string[i]);
    }
}
void *fonts[] = { GLUT_BITMAP_9_BY_15,
				  GLUT_BITMAP_TIMES_ROMAN_10,
				  GLUT_BITMAP_TIMES_ROMAN_24,
				  GLUT_BITMAP_HELVETICA_18,
                  GLUT_BITMAP_HELVETICA_12 };

typedef struct Point {
  GLfloat x;
  GLfloat y;
} Point;






  void drawBitmapText(const char *string, void *font,float x,float y){
    int len, i;
    glRasterPos2f(x, y);
    len = (int)strlen(string);
    for (i = 0; i<len; i++)
    {
      glutBitmapCharacter(font, string[i]);
    }
  }

  void frame0(){
    setBackgroundColor();

     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.5,1,1.5);

    drawstring(200-300,300,0.0,"A MINI PROJECT ON");
    glColor4f(1, 1, 1,1);
    drawstring(100-300,230,0.0,"CAUSES OF CANCER AND ITS EFFECTS");
    glColor3f(0.5,1,1.5);
    glFlush();
    drawstring(310-300,130,0.0,"BY:");
    glColor3f(0.0,0.5,0.5);
    drawstring(150-300,70,0.0,"UTTAMRAJ N A     (4NM18CS206)");
    glColor3f(0.0,0.5,0.5);
    drawstring(180-300,20,0.0,"VISHNU             (4NM18CS213)");
    glColor3f(1,1,1);
    drawstring(250-300,-80,0.0,"SUBMITTED TO:");
     glColor3f(0.5,1,1.5);
    drawstring(210-300,-140,0.0,"Mr. PRADEEP KANCHAN");
     glColor3f(0.5,1,1.5);
    drawstring(230-300,-180,0.0,"ASST PROF GRADE III");
     glColor3f(0.5,1,1.5);
    drawstring(225-300,-220,0.0,"DEPARTMENT OF CSE");
     glColor3f(0.5,1,1.5);
    drawstring(305-300,-260,0.0,"NMAMIT");
    glColor3f(1,0.0,0.0);
    drawstring(240-300,-330,0.0,"PRESS C FOR NEXT");
     glColor3f(1,1,0.478399288755);
    drawstring(240-300,-390,0.0,"PRESS B FOR BACK");
    glPointSize(100);
    glFlush();
  }
  void frame2(){
    glClear(GL_COLOR_BUFFER_BIT);

  glShadeModel(GL_SMOOTH);
    glBegin(GL_POLYGON);
     glColor3f( 0.32,0.49,0.46);
     glVertex2f(-600,400);
     glColor3f( 0.32,0.49,0.46);
     glVertex2f(-100,400);
     glColor3f( 0.55, 0.09, 0.09);
     glVertex2f(-100,-420);
     glColor3f( 0.55, 0.09, 0.09);
     glVertex2f(-600,-420);
     glColor3f( 0.55, 0.09, 0.09);
     glVertex2f(-600,400);

    glEnd();
    glShadeModel(GL_SMOOTH);
    glBegin(GL_POLYGON);
     glColor3f( 0.32,0.49,0.46);
     glVertex2f(100,400);
     glColor3f( 0.32,0.49,0.46);
     glVertex2f(560,400);
     glColor3f( 0.55, 0.09, 0.09);
     glVertex2f(560,-420);
     glColor3f( 0.55, 0.09, 0.09);
     glVertex2f(100,-420);
     glColor3f( 0.55, 0.09, 0.09);
     glVertex2f(100,400);

    glEnd();
    glPointSize(10);
glColor3f(1,1,1);

        glBegin(GL_LINE_STRIP);
     glVertex2f(-600,0);
     glVertex2f(-100,0);
     glVertex2f(-100,-420);
     glVertex2f(-600,-420);
     glVertex2f(-600,0);

    glEnd();
    glColor3f(1,1,1);

        glBegin(GL_LINE_STRIP);
     glVertex2f(-599,-1);
     glVertex2f(-101,-1);
     glVertex2f(-101,-419);
     glVertex2f(-599,-419);
     glVertex2f(-599,-1);

    glEnd();
    glColor3f(1,1,1);

        glBegin(GL_LINE_STRIP);
     glVertex2f(100,0);
     glVertex2f(559,0);
     glVertex2f(559,-420);
     glVertex2f(100,-420);
     glVertex2f(100,0);

    glEnd();
    glColor3f(1,1,1);

        glBegin(GL_LINE_STRIP);
     glVertex2f(101,-1);
     glVertex2f(558,-1);
     glVertex2f(558,-419);
     glVertex2f(101,-419);
     glVertex2f(101,-1);

    glEnd();
    glColor3f(1,1,1);

        glBegin(GL_LINE_STRIP);
     glVertex2f(-600,400);
     glVertex2f(-100,400);
     glVertex2f(-100,0);
     glVertex2f(-600,0);
     glVertex2f(-600,400);

    glEnd();
    glColor3f(1,1,1);

        glBegin(GL_LINE_STRIP);
     glVertex2f(-599,399);
     glVertex2f(-101,399);
     glVertex2f(-101,1);
     glVertex2f(-599,1);
     glVertex2f(-599,399);

    glEnd();
    glColor3f(1,1,1);

        glBegin(GL_LINE_STRIP);
     glVertex2f(100,400);
     glVertex2f(560,400);
     glVertex2f(560,0);
     glVertex2f(100,0);
     glVertex2f(100,400);

    glEnd();
     glColor3f(1,1,1);

        glBegin(GL_LINE_STRIP);
     glVertex2f(101,399);
     glVertex2f(559,399);
     glVertex2f(559,1);
     glVertex2f(101,1);
     glVertex2f(101,399);

    glEnd();
     glColor3f(1,1,1);
        int x=300;

        for(int i=0;i<61;i++){

                glBegin(GL_LINE_STRIP);
                glVertex2f(-100,x);
                glVertex2f(100,x);
                 glEnd();
                int y=x-10;
                x=y;
        }


    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.90 ,0.91,  0.98);

    drawstring(-430,362,0.0,"Benign Tumor");
    glColor3f(0.90 ,0.91,  0.98);

    drawstring(250,362,0.0,"Malignant Tumor");
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.5,1,1.5);

    drawstring(-550,320,0.0,"A tumor is an abnormal growth of cells that ");
    glColor3f(0.5,1,1.5);

    drawstring(-550,270,0.0,"serves no purpose.  ");
      glColor3f(0.5,1,1.5);

    drawstring(-550,220,0.0,"It does not invade nearby tissue or spread to");

    glColor3f(0.5,1,1.5);

    drawstring(-550,170,0.0,"other parts of the body the way cancer can.");

    glColor3f(0.5,1,1.5);

    drawstring(-550,120,0.0,"But benign tumors can be serious if they press");
    glColor3f(0.5,1,1.5);

    drawstring(-550,70,0.0,"on vital structures such as blood vessels or");
    glColor3f(0.5,1,1.5);

    drawstring(-550,20,0.0,"nerves.");
    glColor3f(0.5,1,1.5);

    drawstring(150,320,0.0,"A malignant tumor is a tumor that is");
    glColor3f(0.5,1,1.5);

    drawstring(150,270,0.0,"invasive, meaning it can invade the");
    glColor3f(0.5,1,1.5);

    drawstring(150,220,0.0,"surrounding tissues. ");
    glColor3f(0.5,1,1.5);

    drawstring(150,170,0.0,"Malignant tumors contain cells that are");
    glColor3f(0.5,1,1.5);

    drawstring(150,120,0.0,"cancerous, growing out of control and");
    glColor3f(0.5,1,1.5);

    drawstring(150,70,0.0,"capable of metastasizing.");
    glColor3f(0.5,1,1.5);

    drawstring(150,20,0.0,"Malignant tumors grow quickly.");
firstSet();
secondSet();

if(op<=1)
{
op+=0.01*5;
}else{
     glColor3f(1,1,1);

        glBegin(GL_LINE_STRIP);
     glVertex2f(-350,-185);
     glVertex2f(-750,-185);
        glEnd();
        glBegin(GL_LINE_STRIP);
     glVertex2f(-460,-100);
     glVertex2f(-750,-100);
        glEnd();
        glBegin(GL_LINE_STRIP);
     glVertex2f(380,-130);
     glVertex2f(740,-130);
        glEnd();
        glColor3f(1,1,1);
        setFont(GLUT_BITMAP_9_BY_15);
        drawstring(-750,-90,0.0,"Normal cells");
        glColor3f(1,1,1);
        drawstring(-750,-175,0.0,"Benign tumor");
        glColor3f(1,1,1);
        drawstring(600,-120,0.0,"Malignant tumor");
}

glFlush();
  }
  void frame3(){
    glClear(GL_COLOR_BUFFER_BIT);
    humanBody();
    blobAnimation();
    bloodVessel();
    cellanimation1();
    glFlush();
  }
 void frame31(){
    glClear(GL_COLOR_BUFFER_BIT);
    humanBody();
    blobAnimation();
    bloodVessel();
    cellanimation1();
    glFlush();
    glutSwapBuffers();
  }
  void setBackgroundColor(){
    glBegin(GL_POLYGON);
    glColor3f(.9492f, .9255f, .8745f );
    glVertex2f(-499,-499);
    glVertex2f(499,-499);

    glColor3f(1.0,1.0,1.0);
    glVertex2f(499,499);
    glVertex2f(-499,499);
    glEnd();
    glFlush();
  }
  void drawHollowElipse(GLfloat x, GLfloat y, GLfloat radiusx,GLfloat radiusy){
  int i;
  int lineAmount = 100;
  GLfloat twicePi = 2.0f * M_PI;

  glBegin(GL_LINE_LOOP);
  for(i = 0; i <= lineAmount;i++) {
    glVertex2f(
      x + (radiusx * cos(i *  twicePi / lineAmount)),
      y + (radiusy* sin(i * twicePi / lineAmount))
    );
  }
  glEnd();
}
void drawFilledElipse(GLfloat x, GLfloat y, GLfloat radiusx,GLfloat radiusy){
  int i;
  int triangleAmount = 20;
  GLfloat twicePi = 2.0f * M_PI;
  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(x, y);
  for(i = 0; i <= triangleAmount;i++) {
    glVertex2f(
      x + (radiusx * cos(i *  twicePi / triangleAmount)),
      y + (radiusy * sin(i * twicePi / triangleAmount))
    );
  }
  glEnd();
}


void Arrow(GLdouble x1,GLdouble y1,GLdouble z1,GLdouble x2,GLdouble y2,GLdouble z2,GLdouble D){
  double x=x2-x1;
  double y=y2-y1;
  double z=z2-z1;
  double L=sqrt(x*x+y*y+z*z);
  glColor3f(1,1,1);
  GLUquadricObj *quadObj;
  glPushMatrix();
  glTranslated(x1,y1,z1);
  if(theta<=180){
    theta= (frameNumber * (180.0/46));
  }
  if(theta>125){
    theta= (frameNumber * (-360.0/46));
  }
   if(theta<=-400){
    theta= (frameNumber * (300.0/46));
  }
   if(theta>=480){
    theta= (frameNumber * (-360.0/46));
  }
  if(theta<=-750){
    theta= (frameNumber * (320.0/46));
  }
  if(theta>=840){
    theta= (frameNumber * (-360.0/46));
  }
if(theta<=-1110){
    theta=320;
  }

  glRotated(-theta, 0, 0, 1);

  if((x!=0)||(y!=0)) {
        glColor3f(1,0,1);
    glRotated(atan2(y,x)/RADPERDEG,0.,0.,1.);
    glRotated(atan2(sqrt(x*x+y*y),z)/RADPERDEG,0.,1.,0.);
  } else if (z<0){
       glColor3f(1,1,1);
    glRotated(180,1.,0.,0.);
  }

  glColor3f(1,1,1);
  glTranslatef(0,0,L-4*D);
  quadObj = gluNewQuadric ();
  gluQuadricDrawStyle (quadObj, GLU_FILL);
  gluQuadricNormals (quadObj, GLU_SMOOTH);
  gluCylinder(quadObj, 2*D, 0.0, 4*D, 32, 1);
  gluDeleteQuadric(quadObj);

  quadObj = gluNewQuadric ();
  gluQuadricDrawStyle (quadObj, GLU_FILL);
  gluQuadricNormals (quadObj, GLU_SMOOTH);
  gluDisk(quadObj, 0.0, 2*D, 32, 1);
  gluDeleteQuadric(quadObj);

  glTranslatef(0,0,-L+4*D);

  quadObj = gluNewQuadric ();
  gluQuadricDrawStyle (quadObj, GLU_FILL);
  gluQuadricNormals (quadObj, GLU_SMOOTH);
  gluCylinder(quadObj, D, D, L-4*D, 32, 1);
  gluDeleteQuadric(quadObj);

  quadObj = gluNewQuadric ();
  gluQuadricDrawStyle (quadObj, GLU_FILL);
  gluQuadricNormals (quadObj, GLU_SMOOTH);
  gluDisk(quadObj, 0.0, D, 32, 1);
  gluDeleteQuadric(quadObj);

  glPopMatrix ();

}



void frame4(){
  glColor3f(	.725f, .933f, .871f);
  int x, y;
  x=350;
  y=250;
  double radius=85;
    glPushMatrix();
    glScalef(1,1.4,1);
    glColor3f(1,1,1);
    drawFilledCircle(400-x,450-y+25,radius);
    drawFilledCircle(200-x+10,390-y,radius);
    drawFilledCircle(600-x-10,390-y,radius);
    drawFilledCircle(50-x+40,260-y-10,radius);
    drawFilledCircle(750-x-40,260-y-10,radius);
    glColor3f(1,0.0,0.43445777);
    drawFilledCircle2(400-x,450-y+25,radius);
    drawFilledCircle2(200-x+10,390-y,radius);
    drawFilledCircle2(600-x-10,390-y,radius);
    drawFilledCircle2(50-x+40,260-y-10,radius);
    drawFilledCircle2(750-x-40,260-y-10,radius);
    radius=84;
    glColor3f(1,0,1);
    drawFilledCircle2(400-x,450-y+25,radius);
    drawFilledCircle2(200-x+10,390-y,radius);
    drawFilledCircle2(600-x-10,390-y,radius);
    drawFilledCircle2(50-x+40,260-y-10,radius);
    drawFilledCircle2(750-x-40,260-y-10,radius);

    radius=86;
    glColor3f(1,0.5,1);
    drawFilledCircle2(400-x,450-y+25,radius);
    drawFilledCircle2(200-x+10,390-y,radius);
    drawFilledCircle2(600-x-10,390-y,radius);
    drawFilledCircle2(50-x+40,260-y-10,radius);
    drawFilledCircle2(750-x-40,260-y-10,radius);

    radius=87;
    drawFilledCircle2(400-x,450-y+25,radius);
    drawFilledCircle2(200-x+10,390-y,radius);
    drawFilledCircle2(600-x-10,390-y,radius);
    drawFilledCircle2(50-x+40,260-y-10,radius);
    drawFilledCircle2(750-x-40,260-y-10,radius);

    glPopMatrix();
    glPushMatrix();
    glScalef(.5,.5,0);
    glTranslated(150-x,-(y+70),0);
    Arrow(300,100,0,90,290,0,8);
    glPopMatrix();


    glColor3f(1, 0.211764705, 0.149019607);
    drawBitmapText( "Treatments for Cancer", fonts[2],-70, -180);

    glColor3f(0,0,0);
    setFont(GLUT_BITMAP_HELVETICA_18);
    glPointSize(15);
    drawstring(-325,-7,0.0,"Chemotherapy");
    glColor3f(0,0,0);
    drawstring(305,-7,0.0,"Radiotherapy");
    glColor3f(0,0,0);
    drawstring(-205,185,0.0,"Immunotherapy");
    glColor3f(0,0,0);
    drawstring(210,185,0.0,"Surgery");
    glColor3f(0,0,0);
    drawstring(-30,305,0.0,"Precision Medicine");
}

void bloodVessel()
{
  glPushMatrix();

  glBegin(GL_POLYGON);

  glColor3f(1,0,0);

  glVertex2f(300,200); //1
  glVertex2f(210,-460);

  glVertex2f(290,-460); //3
  glVertex2f(340,-150);

  glVertex2f(340,-150); //4
  glVertex2f(370,190);

  glVertex2f(385,230); //5


  glVertex2f(900,600); //6
  glVertex2f(900,680);
  glColor3f(1,0,0);

  glVertex2f(400,360); //7
  glVertex2f(360,320);

  glVertex2f(300,500); //8
  glVertex2f(180,500);
  glEnd();

  glPopMatrix();

  glPushMatrix();

  glBegin(GL_LINE_LOOP);

  glColor3f(1,1,1);

  glVertex2f(300,200); //1
  glVertex2f(210,-460);

  glVertex2f(290,-460); //3
  glVertex2f(340,-150);

  glVertex2f(340,-150); //4
  glVertex2f(370,190);

  glVertex2f(385,230); //5

  glVertex2f(900,600); //6
  glVertex2f(900,680);

  glVertex2f(400,360); //7
  glVertex2f(360,320);

  glVertex2f(300,500); //8
  glVertex2f(180,500);
  glEnd();
  glPopMatrix();
  glPushMatrix();
  glColor3f(1,1,0);
  output(460,-100,"BLOOD VESSEL");
  glColor3f(1,1,1);
  horzontalLine(330,450,-90);
  glColor3f(1,0,0);
  output(-610,-200,"Malignant tumor travels from one part of the body to another.");
  glColor3f(1,1,1);
  setFont(GLUT_BITMAP_HELVETICA_18);
  drawstring(-400,210,0.0,"Human Body");
  glPopMatrix();

  }

  void cell(int x,int y,int r)
  {
    hexagon(x,y);
    drawCircle(x,y,r,1,0,0);
  }

  void init(){
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300,500,-300,500);
    glMatrixMode(GL_MODELVIEW);
  }
void keyboard(GLubyte key, GLint x, GLint y){
  switch(key){
    case 'c':f++;
             glutPostRedisplay();
             break;
     case 'b':f--;
              if(f==2)
              {
                 frame2();
              }
              glutPostRedisplay();
              break;
              }
  }




void initialize(){
  hexagon_dx=hexagon_r*cos(30.0*M_PI/180.0);
  hexagon_dy=hexagon_r*sin(30.0*M_PI/180.0);
  hexagon_gx=2.0*hexagon_dx;
  hexagon_gy=2.0*hexagon_dx*sin(60.0*M_PI/180.0);
}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
  int i;
  int triangleAmount = 20;
  GLfloat twicePi = 2.0f * M_PI;

  glBegin(GL_TRIANGLE_FAN);
  glColor3f(1,1,0);
  glVertex2f(x, y);
  for(i = 0; i <= triangleAmount;i++) {
    glColor3f(1,0,0);
    glVertex2f(
      x + (radius * cos(i *  twicePi / triangleAmount)),
      y + (radius * sin(i * twicePi / triangleAmount))
    );
  }
  glEnd();
}

void drawFilledCircle2(GLfloat x, GLfloat y, GLfloat radius){
  int i;
  int triangleAmount = 20;
  GLfloat twicePi = 2.0f * M_PI;
  glBegin(GL_LINE_STRIP);
  for(i = 0; i <= triangleAmount;i++) {
    glVertex2f(
      x + (radius * cos(i *  twicePi / triangleAmount)),
      y + (radius * sin(i * twicePi / triangleAmount))
    );
  }
  glEnd();
}

void draw_hexagon(float x,float y){
  glBegin(GL_LINE_LOOP);
  glVertex2f(x-hexagon_dx,y-hexagon_dy);
  glVertex2f(x-hexagon_dx,y+hexagon_dy);
  glVertex2f(x           ,y+hexagon_r );
  glVertex2f(x+hexagon_dx,y+hexagon_dy);
  glVertex2f(x+hexagon_dx,y-hexagon_dy);
  glVertex2f(x           ,y-hexagon_r );
  glEnd();
  drawCircle(x,y,4.0,20);
}

void drawCancerCell(float x,float y,float dx,float dy)
{
  glColor3f(0.831f,0.608f,0.627f);
  glBegin(GL_POLYGON);
  glVertex2f(x-hexagon_dx-2*dx,y-hexagon_dy+dy);
  glVertex2f(x-hexagon_dx+dx,y+hexagon_dy+dy);
  glVertex2f(x     +dx      ,y+hexagon_r );
  glVertex2f(x+hexagon_dx-dx,y+hexagon_dy-dy);
  glVertex2f(x+hexagon_dx-dx,y-hexagon_dy+dx);
  glVertex2f(x           ,y-hexagon_r );
  glEnd();

  glColor3f(0.612f,0.220f,0.290f);
  glBegin(GL_LINE_LOOP);
  glVertex2f(x-hexagon_dx-2*dx,y-hexagon_dy+dy);
  glVertex2f(x-hexagon_dx+dx,y+hexagon_dy+dy);
  glVertex2f(x     +dx      ,y+hexagon_r );
  glVertex2f(x+hexagon_dx-dx,y+hexagon_dy-dy);
  glVertex2f(x+hexagon_dx-dx,y-hexagon_dy+dx);
  glVertex2f(x           ,y-hexagon_r );
  glEnd();
  glColor3f(0.596f,0.537f,0.494f);
  drawFilledCircle(x,y,4);
  glFlush();
}
void drawCancerCells(float x,float y,int ni,int nj){
  int i,j; float x0,shiftP=2.0;
  float x1,y1;
  x-=((float)(ni-1))*hexagon_gx*0.5;
  x-=((float)(nj-1))*hexagon_dx*0.5;
  y-=((float)(nj-1))*hexagon_gy*0.5;
  x1=x+15*hexagon_gx*0.5,y1=y+9*hexagon_gx*0.5;
  glColor3f(1.0,1.0,0.0);

  shiftP+=2;

  for (x0=x1,j=5; j<nj-2; j++){
    for (i=5; i<ni-2; i++){
      float dx[]= {2,3,1,2,3,4,5,6};
      float  dy[]={7,4,5,3,2,5,7,8,3,2,3};

      drawCancerCell(x1,y1,dx[j-5],dy[j-5]);
      x1+=hexagon_gx+shiftP-.3*i;
    }
    x0+=hexagon_dx+shiftP +.5*i;
    x1=x0+shiftP;
    y1+=hexagon_gy+shiftP;
  }
}

void humanBody(){
    glBegin(GL_POLYGON);
    glColor3f( 0.32,0.49,0.46);
    glVertex2f(-450,-100);
    glColor3f( 0.32,0.49,0.46);
    glVertex2f(-250,-100);
    glColor3f( 0.55, 0.09, 0.09);
    glVertex2f(-250,200);
    glColor3f( 0.55, 0.09, 0.09);
    glVertex2f(-450,200);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-450,-100);
    glColor3f(1,1,1);
    glVertex2f(-250,-100);
    glVertex2f(-250,200);
    glColor3f(1,1,1);
    glVertex2f(-450,200);
    glVertex2f(-450,-100);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-449,-99);
    glColor3f(1,1,1);
    glVertex2f(-251,-99);
    glVertex2f(-251,199);
    glColor3f(1,1,1);
    glVertex2f(-449,199);
    glVertex2f(-449,-99);
    glEnd();

  glColor3f(1,0.87,0.77);
  glPushMatrix();
  glRotatef(-10,0,0,1);
  DrawEllipse(10,60,-355,-70); //left leg
  glPopMatrix();

  glPushMatrix();
  glRotatef(10,0,0,1);
  DrawEllipse(10,60,-333,50); //right leg
  glPopMatrix();
  DrawEllipse(20,60,-350,70); //center torso

  glPushMatrix();

  glRotatef(60,0,0,1);
  DrawEllipse(40,12,-116,370); // left arm
  glPopMatrix();

  glPushMatrix();
  glRotatef(-60,0,0,1);
  DrawEllipse(40,12,-234,-236);// right arm
  glPopMatrix();

  DrawEllipse(15,35,-350,140); //head

  glPushMatrix();

  glColor3f(1,0,0);
  glBegin(GL_LINES);
  glVertex2f(-350,30); // center blood vessel
  glVertex2f(-350,120);

  glVertex2f(-350,118); // left line
  glVertex2f(-370,90);

  glVertex2f(-370,90); // left arm
  glVertex2f(-392,60);

  glVertex2f(-350,118); // right vessel
  glVertex2f(-312,65);

  glVertex2f(-350,35); // right down  blood vessel
  glVertex2f(-337,10);


  glVertex2f(-337,10);  // right down calf blood vessel
  glVertex2f(-330,-28);

  glVertex2f(-350,35); // left down blood vessel
  glVertex2f(-360,10);

   // left down blood vessel
  glVertex2f(-360,10);
  glVertex2f(-367,-30);

  glEnd();

}

void blobAnimation(){
  glColor3f(1,0,0);
  glTranslatef(blobx,bloby,0);
  DrawEllipse(5,5,-350,35);
  glFlush();
  glPopMatrix();
  if(c0<33)
  {

    bloby+=0.5*5;
    c0++;

  }else if(c1<7)
    {
      bloby-=0.7*5;
      blobx-=0.5*5;
      c1++;

  }else{
    glPushMatrix();

    glColor3f(0.5,0,0);

    glPopMatrix();

    glColor3f(1,1,0);
    output(-640,85,"New tumour");
    output(-640,55,"METASTASIS");
    glColor3f(1,1,1);
    horzontalLine(-500,-370,92);
    glPopMatrix();
  }
}

void horzontalLine(int Lx1,int Lx2,int Ly){
  glBegin(GL_LINES);
  glVertex2f(Lx1,Ly);
  glVertex2f(Lx2,Ly);
  glEnd();
}
void DrawEllipse(float radiusX, float radiusY,int posx,int posy)
{
   int i;

   glBegin(GL_POLYGON);

   for(i=0;i<360;i++)
   {
      float rad = i*DEG2RAD;
      glVertex2f(posx+cos(rad)*radiusX,posy+sin(rad)*radiusY);
   }
   glEnd();
}
void doFrame(int v) {
  frameNumber++;
  glutPostRedisplay();
  glutTimerFunc(180,doFrame,0);
}
void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius,int r,int g,int b){
	int i;
	int lineAmount = 100;
	GLfloat twicePi = 2.0f * 3.14;
    glColor3f(r,g,b);
	glBegin(GL_POLYGON);
		for(i = 0; i <= 300;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}
 void cancerCell(int x,int y){
   int r=15,R=1,G=1,B=0;

   drawHollowCircle(x,y,r,R,G,B);
   drawHollowCircle(x+15,y,r,R,G,B);
   drawHollowCircle(x+5,y-15,r,R,G,B);
   drawHollowCircle(x+13,y-3,r,R,G,B);
   drawHollowCircle(x,y+16,r,R,G,B); // nucleus
   drawHollowCircle(x+3,y,5,0,1,1);

 }
void cellanimation1(){
 glPushMatrix();
 glTranslatef(cx1,cy1,0);
 cancerCell(300,100);
 cancerCell(335,120);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(cx2,cy2,0);
 cancerCell(330,35);
 cancerCell(320,0);
 glPopMatrix();

 if(c2<15)
 {
   cy1+=0.5*15;
   cx1+=0.08*15;
   c2++;
 }
 else if(c2<835){

     cy1+=0.5*15;
     cx1-=0.15*15;
     c2++;
 }
 if(c3<47){
   cy2+=0.5*10;
   cx2+=0.01*10;
   c3++;
 }else if(c3<30){
   cy2+=0.69*15;
   cx2+=0.45*15;
   c3++;
 }else if(c3<700){
   cy2+=0.50*15;
   cx2+=0.70*15;
   c3++;
 }
}

void normalCells(){
 cell(80,30,5);
 cell(80,65,5);
 cell(135,65,5);
 cell(170,65,5);
 cell(195,65,5);
 cell(265,85,5);
 cell(280,120,5);

 cell(100,100,5);
 cell(130,130,5);
 cell(160,160,5);
 cell(190,190,5);
 cell(220,220,5);
 cell(260,240,5);

 cell(170,105,5);
 cell(215,145,5);
 cell(100,185,5);
 cell(110,215,5);
 cell(120,255,5);
 for(int i=0;i<7;i++)
 {
   cell(100+(i*35),0,5);
 }

}



void draw_hexagon_grid(float x,float y,int ni,int nj){
   int i,j,xy; float x0,shiftP=2.0;
  x-=((float)(ni-1))*hexagon_gx*0.5;
  x-=((float)(nj-1))*hexagon_dx*0.5;
  y-=((float)(nj-1))*hexagon_gy*0.5;
 for (x0=x,j=0;j<nj;j++,x0+=hexagon_dx+shiftP,x=x0+shiftP,y+=hexagon_gy+shiftP)
  for (i=0;i<ni;i++,x+=hexagon_gx+shiftP){
    glColor3f(1,1,1);
    draw_hexagon(x,y);
    glColor3f(1,0.5,0);
    drawCircle(x,y,4.0,20);
}
}


void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.5, 0.0, 0.0);
  //setBackgroundColor();
  switch (f) {
    case 0:frame0();break;

    case 1:frame1();break;

    case 2:if(c==0)
             {
                 op=0;c++;
             }
           frame2();
           break;
    case 3:if(b==0)
           {
            yLocation = 0.0f;
            bloby=0,blobx=0,cx1=0,cy1=0,cx2=0,cy2=0;
            c0=0,c1=0,c2=0,c3=0;
            b=1;
           }
           frame3();
           break;
    case 4:frame4();break;

  }
  glutSwapBuffers();
}



void frame1(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glShadeModel(GL_SMOOTH);
    glBegin(GL_POLYGON);
     glColor3f(1,1,0);
     glVertex2f(-645,350);
     glColor3f(1,1,0);
     glVertex2f(-100,350);
     glColor3f(1,0,0);
     glVertex2f(-100,-340);
     glColor3f(1,0,0);
     glVertex2f(-645,-340);
     glColor3f(1,0,0);
     glVertex2f(-645,350);
    glEnd();
    glColor3f(0,0,1);
    drawstring(-450,300,0.0,"Causes of cancer");
    glColor3f(1,0,0);
    setFont(GLUT_BITMAP_HELVETICA_18);
    drawstring(-405,200,0.0,"Tobacco");
    glColor3f(1,0,0);
    drawstring(-401,100,0.0,"Alcohol");
    glColor3f(1,1,0);
    drawstring(-470,0,0.0,"Obesity and Overweight");
    glColor3f(1,1,0);
    drawstring(-460,-100,0.0,"Chemical carcinogens");
    glColor3f(2,0.5,0);
    drawstring(-440,-200,0.0,"Ionizing radiation");
    glColor3f(2,0.5,0);
    drawstring(-485,-300,0.0,"Viral and bacterial infection");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(1,1,0);
    drawstring(250,300,0.0,"CELL REPLICATION");

    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_LINE_STRIP);
    glVertex2f(-450, 295);
    glVertex2f(-278,295);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(250,295);
    glVertex2f(483,295);
    glEnd();
  glColor3f(0.5, 0.0, 0.0);
  draw_hexagon_grid(360,-20,10,10);
  glFlush();
}
void drawCircle(float cx, float cy, float r, int num_segments){
  glBegin(GL_LINE_LOOP);
  for(int ii = 0; ii < num_segments; ii++)
  {
    float theta = 2.0f * 3.1415926f * (float)ii / (float)(num_segments);//get the current angle

    float x = r * cosf(theta);//calculate the x component
    float y = r * sinf(theta);//calculate the y component

    glVertex2f(x + cx, y + cy);//output vertex

  }
  glEnd();
}

void hexagon(int x,int y){
  float rad;
  float hexagon_r=20;
  float hexagon_dx=hexagon_r*cos(30.0*M_PI/180.0);
  float hexagon_dy=hexagon_r*sin(30.0*M_PI/180.0);
  float hexagon_gx=2.0*hexagon_dx;
  float hexagon_gy=2.0*hexagon_dx*sin(60.0*M_PI/180.0);

  glColor3f(0,0.8,0);
  glBegin(GL_POLYGON);
  glVertex2f(x-hexagon_dx,y-hexagon_dy);
  glVertex2f(x-hexagon_dx,y+hexagon_dy);
  glVertex2f(x           ,y+hexagon_r );
  glVertex2f(x+hexagon_dx,y+hexagon_dy);
  glVertex2f(x+hexagon_dx,y-hexagon_dy);
  glVertex2f(x           ,y-hexagon_r );
  glEnd();
}
void hexagon2(int x,int y){
  float rad;
  float hexagon_r=20;
  float hexagon_dx=hexagon_r*cos(30.0*M_PI/180.0);
  float hexagon_dy=hexagon_r*sin(30.0*M_PI/180.0);
  float hexagon_gx=2.0*hexagon_dx;
  float hexagon_gy=2.0*hexagon_dx*sin(60.0*M_PI/180.0);

  glColor3f( 1,0,0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(x-hexagon_dx,y-hexagon_dy);
  glVertex2f(x-hexagon_dx,y+hexagon_dy);
  glVertex2f(x           ,y+hexagon_r );
  glVertex2f(x+hexagon_dx,y+hexagon_dy);
  glVertex2f(x+hexagon_dx,y-hexagon_dy);
  glVertex2f(x           ,y-hexagon_r );
  glVertex2f(x-hexagon_dx,y-hexagon_dy);
  glEnd();
}

void output(int x, int y,const char *string){
  int len, i;
  glRasterPos2f(x, y);
  len = (int)strlen(string);
  for (i = 0; i<len; i++)
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
  }

}

void verticleLine(int x,int y1,int y2){
  glBegin(GL_LINES);
  glVertex2f(x,y1);
  glVertex2f(x,y2);
  glEnd();
}

void hexagonCancer(int x,int y){
  float rad;
  float hexagon_r=15;
  float hexagon_dx=hexagon_r*cos(30.0*M_PI/180.0)-5;
  float hexagon_dy=hexagon_r*sin(30.0*M_PI/180.0)+2;
  float hexagon_gx=2.0*hexagon_dx;
  float hexagon_gy=2.0*hexagon_dx*sin(60.0*M_PI/180.0)+10;

  glColor3f(1,0.5,0);
  glBegin(GL_POLYGON);
  glVertex2f(x-hexagon_dx,y-hexagon_dy);
  glVertex2f(x-hexagon_dx,y+hexagon_dy);
  glVertex2f(x           ,y+hexagon_r );
  glVertex2f(x+hexagon_dx,y+hexagon_dy);
  glVertex2f(x+hexagon_dx,y-hexagon_dy);
  glVertex2f(x           ,y-hexagon_r );
  glEnd();
}

void hexagonCancer2(int x,int y){
  float rad;
  float hexagon_r=15;
  float hexagon_dx=hexagon_r*cos(30.0*M_PI/180.0)-5;
  float hexagon_dy=hexagon_r*sin(30.0*M_PI/180.0)+2;
  float hexagon_gx=2.0*hexagon_dx;
  float hexagon_gy=2.0*hexagon_dx*sin(60.0*M_PI/180.0)+10;

  glColor3f(0,0.5,1.5);
  glBegin(GL_LINE_STRIP);
  glVertex2f(x-hexagon_dx,y-hexagon_dy);
  glVertex2f(x-hexagon_dx,y+hexagon_dy);
  glVertex2f(x           ,y+hexagon_r );
  glVertex2f(x+hexagon_dx,y+hexagon_dy);
  glVertex2f(x+hexagon_dx,y-hexagon_dy);
  glVertex2f(x           ,y-hexagon_r );
  glVertex2f(x-hexagon_dx,y-hexagon_dy);
  glEnd();
  }

void drawCircle(GLfloat x, GLfloat y, GLfloat radius,int r,int g,int b){
  int i;
  int lineAmount = 100; //# of triangles used to draw circle

  //GLfloat radius = 0.8f; //radius
  GLfloat twicePi = 2.0f * 3.14;
  glColor3f(r,g,b);
  glBegin(GL_POLYGON);
  for(i = 0; i <= 300;i++) {
    glVertex2f(
      x + (radius * cos(i *  twicePi / lineAmount)),
      y + (radius* sin(i * twicePi / lineAmount))
    );
  }
  glEnd();
}

void drawCircleCancer(GLfloat x, GLfloat y, GLfloat radius,int r,int g,int b){
  int i;
  int lineAmount = 100; //# of triangles used to draw circle

  //GLfloat radius = 0.8f; //radius
  GLfloat twicePi = 2.0f * 3.14;
  glColor4f(r,g,b,op);
  glBegin(GL_POLYGON);
  for(i = 0; i <= 300;i++) {
    glVertex2f(
      x + (radius * cos(i *  twicePi / lineAmount)),
      y + (radius* sin(i * twicePi / lineAmount))
    );
  }
  glEnd();
}
void CellCancer(int x,int y){
  hexagonCancer(x,y);
  hexagonCancer2(x,y);
  drawCircle(x,y,2,1,0,0);
}
void cell(int x,int y){
  hexagon(x,y);
  hexagon2(x,y);
  drawCircle(x,y,5,1,0,0);
}
void cancerCellM(int x,int y){
  drawCircleCancer(20+x,10+y,13,1,1,0);
  drawCircleCancer(35+x,10+y,13,1,1,0);
  drawCircleCancer(30+x,20+y,10,1,1,0);
  drawCircleCancer(20+x,25+y,13,1,1,0);
  drawCircleCancer(15+x,10+y,10,1,1,0);
  drawCircleCancer(23+x,14+y,5,1,0,0);
}

void cancerCellB(int x,int y){
  drawCircleCancer(20+x,10+y,13,1,1,0);
  drawCircleCancer(35+x,10+y,13,1,1,0);
  drawCircleCancer(30+x,20+y,10,1,1,0);
  drawCircleCancer(20+x,25+y,13,1,1,0);
  drawCircleCancer(15+x,10+y,10,1,1,0);
  drawCircleCancer(23+x,14+y,5,1,0,0);
}
void melignant(){
  cancerCellM(350,-320);
  cancerCellM(330,-290);
  cancerCellM(294,-260);
  cancerCellM(290,-205);
  cancerCellM(315,-175);
  cancerCellM(350,-150);
  cancerCellM(390,-160);
  cancerCellM(410,-200);
  cancerCellM(395,-310);
  cancerCellM(420,-270);
}
void secondSet(){
  for(int i=0;i<5;i++)
  {
    hexagon(210+(i*30),-100);
    hexagon2(210+(i*30),-100);
    drawCircle(210+(i*30),-100,5,1,0,0);
  }

  for(int i=0;i<4;i++)
  {
    hexagon(210+(i*30),-150);
    hexagon2(210+(i*30),-150);
    drawCircle(210+(i*30),-150,5,1,0,0);
  }

  for(int i=0;i<3;i++)
  {
    hexagon(210+(i*30),-190);
    hexagon2(210+(i*30),-190);
    drawCircle(210+(i*30),-190,5,1,0,0);
  }

  for(int i=0;i<3;i++)
  {
    hexagon(210+(i*30),-240);
    hexagon2(210+(i*30),-240);
    drawCircle(210+(i*30),-240,5,1,0,0);
  }

  for(int i=0;i<4;i++)
  {
    hexagon(210+(i*30),-280);
    hexagon2(210+(i*30),-280);
    drawCircle(210+(i*30),-280,5,1,0,0);
  }

  for(int i=0;i<5;i++)
  {
    hexagon(210+(i*30),-320);
    hexagon2(210+(i*30),-320);
    drawCircle(210+(i*30),-320,5,1,0,0);
  }
  melignant();
  glPushMatrix();
  glColor3f(1,1,1);
  CellCancer(350,-230);
  glColor3f(1,1,1);
  CellCancer(370,-230);
  glPopMatrix();

  glPushMatrix();
  CellCancer(400,-210);
  CellCancer(390,-250);
  glPopMatrix();

  glPushMatrix();
  CellCancer(350,-180);
  CellCancer(410,-260);
  glPopMatrix();

  glPushMatrix();
  CellCancer(370,-190);
  CellCancer(390,-280);
  glPopMatrix();
}

void firstSet(){
  for(int i=0;i<5;i++)
  {
    hexagon(-450+(i*30),-50);
    hexagon2(-450+(i*30),-50);
    drawCircle(-450+(i*30),-50,5,1,0,0);
  }

  for(int i=0;i<4;i++)
  {
    hexagon(-450+(i*30),-100);
    hexagon2(-450+(i*30),-100);
    drawCircle(-450+(i*30),-100,5,1,0,0);
  }

  for(int i=0;i<3;i++)
  {
    hexagon(-450+(i*30),-140);
    hexagon2(-450+(i*30),-140);
    drawCircle(-450+(i*30),-140,5,1,0,0);
  }

  for(int i=0;i<2;i++)
  {
    hexagon(-450+(i*30),-190);
    hexagon2(-450+(i*30),-190);
    drawCircle(-450+(i*30),-190,5,1,0,0);
  }

  for(int i=0;i<2;i++)
  {
    hexagon(-450+(i*30),-230);
    hexagon2(-450+(i*30),-230);
    drawCircle(-450+(i*30),-230,5,1,0,0);
  }

  for(int i=0;i<2;i++)
  {
    hexagon(-450+(i*30),-270);
    hexagon2(-450+(i*30),-270);
    drawCircle(-450+(i*30),-270,5,1,0,0);
  }
  for(int i=0;i<4;i++)
  {
    hexagon(-450+(i*30),-330);
    hexagon2(-450+(i*30),-330);
    drawCircle(-450+(i*30),-330,5,1,0,0);
  }

  for(int i=0;i<5;i++)
  {
    hexagon(-450+(i*30),-370);
    hexagon2(-450+(i*30),-370);
    drawCircle(-450+(i*30),-370,5,1,0,0);
  }
cell(-290,-350);
cell(-260,-320);
cell(-245,-280);
cell(-285,-70);
cell(-265,-110);
cell(-245,-140);

cancerCellB(-335,-185);
cancerCellB(-375,-210);
cancerCellB(-375,-260);
cancerCellB(-345,-280);
cancerCellB(-355,-230);
cancerCellB(-335,-240);
cancerCellB(-305,-250);
}

int x10,y10; //cursor
int move_init=1; //flag to move
int lastX=0,lastY=0;
void mouseFunc(int button,int state,int x4,int y4){
      cout<<x4<<endl;
      cout<<y4<<endl;
    if(button==GLUT_LEFT_BUTTON){
		   if(state==GLUT_DOWN){
                if(x4>436 && x4<604 && y4>261 && y4<454){
                for(int i=0;i<1000;i++){

    glColor3f(0.890709078,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(-650,50);
    glVertex2f(-390,50);
    glVertex2f(-350,22.5);
    glVertex2f(-390,10);
    glVertex2f(-390,-210);
    glVertex2f(-650,-210);
    glVertex2f(-650,50);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-650,50);
    glVertex2f(-390,50);
    glVertex2f(-350,22.5);
    glVertex2f(-390,10);
    glVertex2f(-390,-210);
    glVertex2f(-650,-210);
    glVertex2f(-650,50);
    glEnd();

    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(1,0,0);

    drawstring(-640,20,0.0,"Chemotherapy is a form of");
    glColor3f(1,0,0);
    drawstring(-640,-10,0.0,"chemical drug therapy");
    glColor3f(1,0,0);
    drawstring(-640,-40,0.0,"meant to destroy rapidly");
    glColor3f(1,0,0);
    drawstring(-640,-70,0.0,"growing cells in the body.");
    glColor3f(1,0,0);
    drawstring(-640,-100,0.0,"Its usually used to treat");
    glColor3f(1,0,0);
    drawstring(-640,-130,0.0,"cancer, as cancer cells");
    glColor3f(1,0,0);
    drawstring(-640,-160,0.0,"grow and divide faster");
    glColor3f(1,0,0);
    drawstring(-640,-190,0.0,"than other cells.");
    glFlush();
    glutSwapBuffers();}}
    else if(x4>550 && x4<720 && y4>105 && y4<300){
    for(int i=0;i<1000;i++){

    glColor3f(0.890709078,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(-550,250);
    glVertex2f(-280,250);
    glVertex2f(-240,225);
    glVertex2f(-280,210);
    glVertex2f(-280,-10);
    glVertex2f(-550,-10);
    glVertex2f(-550,250);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_LINE_STRIP);
       glVertex2f(-550,250);
    glVertex2f(-280,250);
    glVertex2f(-240,225);
    glVertex2f(-280,210);
    glVertex2f(-280,-10);
    glVertex2f(-550,-10);
    glVertex2f(-550,250);
    glEnd();

    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(1,0,0);

    drawstring(-540,220,0.0,"Immunotherapy is treatment");
    glColor3f(1,0,0);

    drawstring(-540,190,0.0,"that uses a person's own");
    glColor3f(1,0,0);

    drawstring(-540,160,0.0,"immune system to fight");
    glColor3f(1,0,0);
    drawstring(-540,130,0.0,"cancer. Immunotherapy can");
    glColor3f(1,0,0);
    drawstring(-540,100,0.0,"boost or change how the");
    glColor3f(1,0,0);
    drawstring(-540,70,0.0,"immune system works so it");
    glColor3f(1,0,0);
    drawstring(-540,40,0.0,"can find and attack cancer");
    glColor3f(1,0,0);
    drawstring(-540,10,0.0,"cells.");
    glFlush();
    glutSwapBuffers();}
    }
    else if(x4>735 && x4<900 && y4>10 && y4<205){
    for(int i=0;i<1000;i++){

    glColor3f(0.890709078,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(-400,350);
    glVertex2f(-90,350);
    glVertex2f(-50,325);
    glVertex2f(-90,310);
    glVertex2f(-90,80);
    glVertex2f(-400,80);
    glVertex2f(-400,350);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-400,350);
    glVertex2f(-90,350);
    glVertex2f(-50,325);
    glVertex2f(-90,310);
    glVertex2f(-90,80);
    glVertex2f(-400,80);
    glVertex2f(-400,350);
    glEnd();

    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(1,0,0);

    drawstring(-390,320,0.0,"The aim of precision medicine,");
    glColor3f(1,0,0);

    drawstring(-390,290,0.0,"sometimes called personalized");
    glColor3f(1,0,0);

    drawstring(-390,260,0.0,"medicine, is to match treatments");
    glColor3f(1,0,0);
    drawstring(-390,230,0.0,"to individual patients taking");
    glColor3f(1,0,0);
    drawstring(-390,200,0.0,"into account their genetic");
    glColor3f(1,0,0);
    drawstring(-390,170,0.0,"makeup, medical history, test");
    glColor3f(1,0,0);
    drawstring(-390,140,0.0,"results,and other distinctive");
    glColor3f(1,0,0);
    drawstring(-390,110,0.0,"characteristics.");
    glFlush();
    glutSwapBuffers();}
    }
    else if(x4>920 && x4<1085 && y4>105 && y4<300){
    for(int i=0;i<1000;i++){

    glColor3f(0.890709078,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(380,250);
    glVertex2f(670,250);

    glVertex2f(670,-20);
    glVertex2f(380,-20);
    glVertex2f(380,210);
    glVertex2f(340,225);
    glVertex2f(380,250);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(380,250);
    glVertex2f(670,250);
    glVertex2f(670,-20);
    glVertex2f(380,-20);
    glVertex2f(380,210);
    glVertex2f(340,225);
    glVertex2f(380,250);
    glEnd();

    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(1,0,0);

    drawstring(390,220,0.0,"The goal of surgery is to");
    glColor3f(1,0,0);

    drawstring(390,190,0.0,"remove as much of the tumor ");
    glColor3f(1,0,0);

    drawstring(390,160,0.0,"as possible without damaging");
    glColor3f(1,0,0);
    drawstring(390,130,0.0,"the nearby normal tissue.");
    glColor3f(1,0,0);
    drawstring(390,100,0.0,"Surgery  is the oldest type");
    glColor3f(1,0,0);
    drawstring(390,70,0.0,"of cancer treatment. And");
    glColor3f(1,0,0);
    drawstring(390,40,0.0,"it is still effective for");
    glColor3f(1,0,0);
    drawstring(390,10,0.0,"many types of cancer today.");
    glFlush();
    glutSwapBuffers();}}
    else if(x4>1030 && x4<1200 && y4>260 && y4<460){
    for(int i=0;i<1000;i++){

    glColor3f(0.890709078,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(500,50);
    glVertex2f(770,50);
    glVertex2f(770,-210);
    glVertex2f(500,-210);
    glVertex2f(500,10);
    glVertex2f(460,22.5);
    glVertex2f(500,50);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(500,50);
    glVertex2f(770,50);
    glVertex2f(770,-210);
    glVertex2f(500,-210);
    glVertex2f(500,10);
    glVertex2f(460,22.5);
    glVertex2f(500,50);
    glEnd();

    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(1,0,0);

     drawstring(510,20,0.0,"Radiation therapy is a");
    glColor3f(1,0,0);

    drawstring(510,-10,0.0,"cancer treatment that uses");
    glColor3f(1,0,0);

    drawstring(510,-40,0.0,"high doses of radiation to");
    glColor3f(1,0,0);
    drawstring(510,-70,0.0,"kill cancer cells and");
    glColor3f(1,0,0);
    drawstring(510,-100,0.0,"shrink tumors. Doctors may");
    glColor3f(1,0,0);
    drawstring(510,-130,0.0,"use radiation therapy alone");
    glColor3f(1,0,0);
    drawstring(510,-160,0.0,"or with other cancer");
    glColor3f(1,0,0);
    drawstring(510,-190,0.0,"treatments.");
    glFlush();

    glutSwapBuffers();
    }
   }
  }
 }
}

int main(int argc, char** argv)
{
  glutInit(&argc,argv);
  initialize();
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
  glutInitWindowSize(1920,720);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Polygon");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouseFunc);
  glClearColor(0,0.0,0.0,0.0);
  glOrtho(-800.0,800.0,-450.0,450.0,-200.0,200.0);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glutTimerFunc(500,doFrame,0);
  glutMainLoop();
  return 1;
}
