#include "Application.h"


 void Application::Run()
{
    Draw D = Draw();
    Clock C;
    while (true)
    {
        D.setBuffer();
        D.drawMap();
        D.drawHourHand(C.GetHour());
        D.drawMinHand(C.GetMinute());
        D.drawSecondHand(C.GetSecond());
        D.drawDay(C.GetDay(), C.GetDayNumber());
        D.print();


    }
}
