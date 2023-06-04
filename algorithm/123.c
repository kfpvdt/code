
#include <stdafx.h>

#include <GL/glut.h>

void myInit(void);

void myReshape(GLsizei w,GLsizei h);

void myDisplay(void);

void myInit(void)

//设置 OpenGL 运行初始环境



{

glClearColor(1.0,1.0,1.0,1.0);

//清除背景颜色为白色

glShadeModel(GL_SMOOTH);

//设置图形绘制模式

}

void myDisplay(void)

//绘制 5 个不同类型的多边形

{

//给出 6 个顶点的坐标

glClear(GL_COLOR_BUFFER_BIT);

//清除颜色缓冲区

glPolygonMode(GL_FRONT, GL_FILL);

// GL_LINE

GL_POINT

//此处需要注意通过改变 glPolygonMode 函数种第 2 个参数来指定使用填充模式绘制图形（GL_FILL），

//线框模式绘制图形（GL_LINE），顶点模式绘制图形（GL_POINT），产生的不同绘制效果。

//glLoadIdentity();

GLfloat tr_p1[] = {-1.0f, 0.0f, 0.0f}; GLfloat tr_p2[] = {-0.5f,-1.0f, 0.0f};

GLfloat tr_p3[] = {0.5f,-1.0f, 0.0f};

GLfloat tr_p4[] = {1.0f,0.0f, 0.0f};

GLfloat tr_p5[] = {0.5f,1.0f, 0.0f};

GLfloat tr_p6[] = {-0.5f,1.0f, 0.0f};

glTranslatef(-2.4f,1.5f,0.0f);

// 平移图形

glColor4f(1.0,1.0,0.0,1.0);

//设置三角形颜色为黄色

glBegin(GL_TRIANGLES);

// 绘制 2 个三角形

glVertex3fv(tr_p1); /* 第 1 个点*/ glVertex3fv(tr_p2);/* 第 2 个点*/

glVertex3fv(tr_p6); /* 第 3 个点*/ glVertex3fv(tr_p3);/* 第 4 个点*/

glVertex3fv(tr_p4); /* 第 5 个点*/ glVertex3fv(tr_p5);/* 第 6 个点*/

glEnd();

// 绘制完成

glTranslatef(2.5f,0.0f,0.0f);

//平移三角形带

glColor3f(1.0,0.0,1.0);

//紫色

glBegin(GL_TRIANGLE_STRIP);

// 绘制三角形带

glVertex3fv(tr_p1); glVertex3fv(tr_p2); glVertex3fv(tr_p6);

glVertex3fv(tr_p3); glVertex3fv(tr_p5); glVertex3fv(tr_p4);

glEnd();

glTranslatef(2.5f,0.0f,0.0f);

//平移三角形扇形

glColor3f(0.0,1.0,0.0);

//绿色

glBegin(GL_TRIANGLE_FAN);

// 绘制三角形扇形

glVertex3fv(tr_p1); glVertex3fv(tr_p2); glVertex3fv(tr_p3);

glVertex3fv(tr_p4); glVertex3fv(tr_p5); glVertex3fv(tr_p6);

glEnd();

// 绘制完成

//多边形顶点列表

GLfloat ply_p1[] = {-1.5f, 1.0f, 0.0f}; GLfloat ply_p2[] = {-1.5f,-1.0f, 0.0f};

GLfloat ply_p3[] = {-0.5f,-0.5f, 0.0f}; GLfloat ply_p4[] = {-0.5f,0.5f, 0.0f};

GLfloat ply_p5[] = {0.5f,0.7f, 0.0f}; GLfloat ply_p6[] = {0.5f,-0.5f, 0.0f};

GLfloat ply_p7[] = {1.5f,-0.6f, 0.0f}; GLfloat ply_p8[] = {1.5f,1.0f, 0.0f};

glTranslatef(-4.5f,-3.0f,0.0f);

//平移四边形

glColor3f(0.0,0.0,1.0);

glBegin(GL_QUADS);

// 绘制四边形

glVertex3fv(ply_p1); glVertex3fv(ply_p2); glVertex3fv(ply_p3);

glVertex3fv(ply_p4); glVertex3fv(ply_p5); glVertex3fv(ply_p6);

glVertex3fv(ply_p7); glVertex3fv(ply_p8);

glEnd();

// 绘制完成

glTranslatef(3.5f,0.0f,0.0f);

//平移四边形面扇

glColor3f(1.0,0.0,0.0);

glBegin(GL_QUAD_STRIP);

// 绘制相连四边形

glVertex3fv(ply_p1); glVertex3fv(ply_p2); glVertex3fv(ply_p4);

glVertex3fv(ply_p3); glVertex3fv(ply_p5); glVertex3fv(ply_p6);

glVertex3fv(ply_p8); glVertex3fv(ply_p7);

glEnd();

glFlush();

}

//此处根据窗口的变化设置视口和裁剪窗口

void myReshape(GLsizei w,GLsizei h)

{

GLfloat nR=8.0f;

if (h==0)

//防止被 0 除

h=1;

glViewport(0,0,w,h); //将视口区设置为原点位于左下角，宽度为 w，高度为 h

glMatrixMode(GL_PROJECTION); //设置当前投影矩阵堆栈

glLoadIdentity();

//建立裁剪体

gluOrtho2D(-nR,nR,-nR,nR);

glMatrixMode(GL_MODELVIEW); //设置模型观察矩阵堆栈

glLoadIdentity();

}

void main(int argc,char** argv)

{

//初始化显示模式，并将窗口显示模式定义为单缓冲区、RGBA 颜色

glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

glutInitWindowPosition(50,150);

//设置显示窗口左上角位置

glutInitWindowSize(500,500);

//设置显示窗口宽度和高度

glutCreateWindow("OpenGL 多边形区域单色填充函数");

//创建窗口并设置标题

myInit();

//绘制状态初始化

glutReshapeFunc(myReshape);

//当窗口发生变化时，调用 myReshape 重新定

义窗口属性

glutDisplayFunc(myDisplay);

glutMainLoop();