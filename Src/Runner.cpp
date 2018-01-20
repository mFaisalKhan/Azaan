#include "Runner.h"
#include "TimeLoader.h"
#include <iostream>
#include <unistd.h>
#include <QDebug>

///////////////////////////////////////////////////////////
Runner::Runner(TimerInterface &timer)
    : Checker(timer)
{

    qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.ms MM/dd/yyyy") << " Runner started";

    TimeLoader loader;

    if(loader.LoadTimes())
    {
        qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.ms MM/dd/yyyy")  << "Times Loaded";

        QMap<QString, QTime> times = loader.GetLoadedTime();

        qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.ms MM/dd/yyyy") << "Date   : " <<  QDateTime::currentDateTime().toString("MM/dd/yyyy");
        qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.ms MM/dd/yyyy") << "Fajar  : " <<  times["Fajar"].toString("hh:mm:ss");
        qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.ms MM/dd/yyyy") << "Zuhur  : " <<  times["Zuhur"].toString("hh:mm:ss");
        qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.ms MM/dd/yyyy") << "Asar   : " <<  times["Asar"].toString("hh:mm:ss");
        qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.ms MM/dd/yyyy") << "Maghrib: " <<  times["Maghrib"].toString("hh:mm:ss");
        qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.ms MM/dd/yyyy") << "Isha   : " <<  times["Isha"].toString("hh:mm:ss");

        Checker.AddTime(times["Fajar"]);
        Checker.AddTime(times["Zuhur"]);
        Checker.AddTime(times["Asar"]);
        Checker.AddTime(times["Maghrib"]);
        Checker.AddTime(times["Isha"]);

    }
    else
    {
        qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.ms MM/dd/yyyy") << "LoadTime failed";
    }

}

///////////////////////////////////////////////////////////
Runner::~Runner()
{

}

///////////////////////////////////////////////////////////
void Runner::Run()
{
    while(1)
    {
        if(Checker.IsTimeToPlay())
        {
            qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.ms MM/dd/yyyy") << "Time to play";
        }
        sleep(10);
    }
}

