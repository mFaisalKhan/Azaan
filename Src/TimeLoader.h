#ifndef TIME_LOADER_H
#define TIME_LOADER_H

#include <QtCore/QList>
#include <qt5/QtSql/QSqlDatabase>
#include <QtCore/QTime>
#include <QtCore/QMap>
#include <QVariant>
#include "TimerInterface.h"

/*
 * Loads time from database and return a list if loaded times
 */
class TimeLoader
{
 public:
    TimeLoader();
    ~TimeLoader();
    QMap<QString, QTime>  & GetLoadedTime();
    bool LoadTimes();

private:
    bool OpenDatabase();
    bool ExecuteQuery(const QString & queryString);
    bool ReadRecord(const QDate dateTime);

    QMap<QString, QTime> PrayerTimes;
    QMap<QString, QVariant> Result;
    QSqlDatabase Db;
    QString DBPath;
};




#endif // TIME_LOADER_H
