#include "Clock.h"
tm Clock::GetLocalTime()
{
	time_t now = time(0);
	return *localtime(&now);
}
int Clock::GetHour()
{
	tm time = GetLocalTime();
	return time.tm_hour;

}
int Clock::GetMinute()
{
	tm time = GetLocalTime();
	return time.tm_min;
}
int Clock::GetSecond()
{
	tm time = GetLocalTime();
	return time.tm_sec;
}
int Clock::GetDay()
{
	tm time = GetLocalTime();
	return time.tm_wday;
}
int Clock::GetDayNumber()
{
	tm time = GetLocalTime();
	return time.tm_mday;
}