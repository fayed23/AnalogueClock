#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <string>


class Clock
{
private:
	tm GetLocalTime();
public:

	int GetHour();
	int GetMinute();
	int GetSecond();
	int GetDay();
	int GetDayNumber();
	

};

