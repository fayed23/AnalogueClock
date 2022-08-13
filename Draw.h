#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <string>
#define PI 3.141592f 
const int BUFFERWIDTH = 100;
const int BUFFERHEIGHT = 50;
/*
*
* o: is a point
* (x,y): coordintes of a point
            (0,0)
              o-------------------------------------------------------------------------------------------------------->X
              |
              |
              |
              |                                  o --> (centerX, centerY-radius)
              |
              |                                       o --> (centerX+radius*cos(angle),centerY-radius*sin(angle)
              |                           radius --->/
              |                                     /
              |                                    / angle
              |                  --------------- o ------------------
              |                           (centerX,centerY)
              |
              |
              |
              v
              Y
*/

class Draw
{
private:
	char buffer[BUFFERHEIGHT][BUFFERWIDTH]{ '*' };
	int radius = 20;
	int centerX = 50;
	int centerY = 25;

private:
	void goToXY(short x, short y);
	void drawCircle();
	void drawNumbers();
	
public:
	void drawMap();
	void setBuffer();
	void drawHourHand(int hour);
	void drawMinHand(int min);
	void drawSecondHand(int second);
	void drawDay(int day, int num);
	void print();
	


};

