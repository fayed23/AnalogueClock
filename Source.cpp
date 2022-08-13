#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <string>

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

const int BUFFERWIDTH = 100;
const int BUFFERHEIGHT = 50;
char buffer[BUFFERHEIGHT][BUFFERWIDTH]{ '*' };
#define PI 3.141592f 

int radius = 20; 
int centerX = 50; 
int centerY = 25; 

void goToXY(short x, short y) //Set the console cursor position to (x,y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ x, y });
}

void drawHourHand(int hour)
{
    int rawHour = hour % 12;
    float a = PI / 2 - rawHour * (2 * PI / 12);
    

    for(int k=0;k<radius-10;++k)
    {

        buffer[centerY - (int)(k * sin(a))][centerX + (int)(k * cos(a))] = 'H';
    }
   
}

void drawMinHand(int min)
{
    
    float a = PI / 2 - min * (2 * PI / 60);


    for (int k = 0; k < radius-2; ++k)
    {

        buffer[centerY - (int)(k * sin(a))][centerX + (int)(k * cos(a))] = 'M';
    }

}

void drawSecondHand(int second)
{

    float a = PI / 2 - second * (2 * PI / 60);


    for (int k = 0; k < radius; ++k)
    {

        buffer[centerY - (int)(k * sin(a))][centerX + (int)(k * cos(a))] = 'S';
    }

}

void draw()
    {
    memset((void*)buffer, ' ', BUFFERWIDTH * BUFFERHEIGHT); //clear the buffer
    // Render
    for (int x = 0; x <= radius * 0.7071f /*cos(PI / 4)*/; ++x)
    {
        int y = round(sqrt(radius * radius - x * x));

        buffer[centerY + y][centerX + x] = '*';
        buffer[centerY + y][centerX - x] = '*';
        buffer[centerY - y][centerX - x] = '*';
        buffer[centerY - y][centerX + x] = '*';

        buffer[centerY + x][centerX + y] = '*';
        buffer[centerY - x][centerX + y] = '*';
        buffer[centerY - x][centerX - y] = '*';
        buffer[centerY + x][centerX - y] = '*';


    }
 
  
}

void drawNumbers()
{
    float a = PI / 2 - 12 * (2 * PI / 12);
    buffer[centerY - (int)(radius * sin(a))-1][centerX + (int)(radius * cos(a))] = '1';
    buffer[centerY - (int)(radius * sin(a))-1][centerX + (int)(radius * cos(a))+1] = '2';
    a = PI / 2 - 1 * (2 * PI / 12);
    buffer[centerY - (int)(radius * sin(a))-1][centerX + (int)(radius * cos(a))+1] = '1';
    a = PI / 2 - 2 * (2 * PI / 12);
    buffer[centerY - (int)(radius * sin(a)) - 1][centerX + (int)(radius * cos(a)) + 1] = '2';
    a = PI / 2 - 3 * (2 * PI / 12);
    buffer[centerY - (int)(radius * sin(a))][centerX + (int)(radius * cos(a)) + 1] = '3';
    a = PI / 2 - 4 * (2 * PI / 12);
    buffer[centerY - (int)(radius * sin(a))+1][centerX + (int)(radius * cos(a)) + 1] = '4';
    a = PI / 2 - 5 * (2 * PI / 12);
    buffer[centerY - (int)(radius * sin(a))+1][centerX + (int)(radius * cos(a)) + 1] = '5';
    a = PI / 2 - 6 * (2 * PI / 12);
    buffer[centerY - (int)(radius * sin(a))+1][centerX + (int)(radius * cos(a))] = '6';
    a = PI / 2 - 7 * (2 * PI / 12);
    buffer[centerY - (int)(radius * sin(a)) + 1][centerX + (int)(radius * cos(a))-1] = '7';
    a = PI / 2 - 8 * (2 * PI / 12);
    buffer[centerY - (int)(radius * sin(a)) + 1][centerX + (int)(radius * cos(a))-1] = '8';
    a = PI / 2 - 9 * (2 * PI / 12);
    buffer[centerY - (int)(radius * sin(a))][centerX + (int)(radius * cos(a))-1] = '9';
    a = PI / 2 - 10 * (2 * PI / 12);
    buffer[centerY - (int)(radius * sin(a))][centerX + (int)(radius * cos(a))-2] = '0';
    buffer[centerY - (int)(radius * sin(a))][centerX + (int)(radius * cos(a)) - 3] = '1';
    a = PI / 2 - 11 * (2 * PI / 12);
    buffer[centerY - (int)(radius * sin(a))][centerX + (int)(radius * cos(a)) - 2] = '1';
    buffer[centerY - (int)(radius * sin(a))][centerX + (int)(radius * cos(a)) - 3] = '1';




}

void drawDay(int day, int num )
{
    std::string ch1="";
    switch (day)
    {
    case 0:
        ch1 = "SUN";
            break;
    case 1:
        ch1 = "MON";
        break;
    case 2:
        ch1 = "TUE";
        break;
    case 3:
        ch1 = "WED";
        break;
    case 4:
        ch1 = "THU";
        break;
    case 5:
        ch1 = "FRI";
        break;
    case 6:
        ch1 = "SAT";
        break;
    default:
        break;

        
    }
    std::string ch2 = std::to_string(num);
    int posy = centerY - 4 ;
    int posx = centerX + (int)(radius * cos(PI/4)) - 2;
    
    buffer[posy][posx-5] = '|';
    buffer[posy][posx-4] = ch1[0];
    buffer[posy][posx -3] = ch1[1];
    buffer[posy][posx - 2] = ch1[2];
    buffer[posy][posx-1] ='|';
    buffer[posy][posx] = ch2[0];
    buffer[posy][posx+1] = ch2[1];
    buffer[posy][posx +2] = '|';

    


}

void print()
{
   

    for (int i = 0; i < BUFFERHEIGHT; ++i)
    {
        for (int j = 0; j < BUFFERWIDTH; j++)
        {
            putchar(buffer[i][j]);
            putchar(' ');
        }
        putchar('\n');
    }
    memset((void*)buffer, ' ', BUFFERWIDTH * BUFFERHEIGHT);
}

int main()
{
    
    struct tm tstruct;
    
    while (1)
    {
    
        time_t now = time(0);
        tstruct = *localtime(&now);
        int hour = tstruct.tm_hour;
        int min = tstruct.tm_min;
        int second = tstruct.tm_sec;
        int day = tstruct.tm_wday;
        int num = tstruct.tm_mday;
        goToXY(0, 0);
        memset((void*)buffer, ' ', BUFFERWIDTH * BUFFERHEIGHT);

        draw();
        drawHourHand(hour);
        drawMinHand(min);
        drawSecondHand(second);
        drawNumbers();
        drawDay(day,num);
        print();
        
        
    }

    return 0;
}
