#include "TimeLoader.h"
#include <QtCore/QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>

const QString DB_PATH = "./master.db";

///////////////////////////////////////////////////////
TimeLoader::TimeLoader()
    : PrayerTimes()
    , Db()
    , DBPath(DB_PATH)

{

}

///////////////////////////////////////////////////////
TimeLoader::~TimeLoader()
{

}

///////////////////////////////////////////////////////
QMap<QString, QTime> & TimeLoader::GetLoadedTime()
{
    return PrayerTimes;
}

///////////////////////////////////////////////////////
bool TimeLoader::LoadTimes()
{
    bool retVal = false;
    if( OpenDatabase() )
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
        retVal = true;
    }

    return retVal;
}

///////////////////////////////////////////////////////
bool TimeLoader::OpenDatabase()
{
    Db = QSqlDatabase::addDatabase("QSQLITE");
    Db.setDatabaseName(DBPath);

    return (Db.open());
}

///////////////////////////////////////////////////////
bool TimeLoader::ExecuteQuery(const QString & queryString)
{
    QSqlQuery query(queryString);
    QSqlRecord record =  query.record();

    int id_date = record.indexOf("Date");
    int id_Fajr = record.indexOf("Fajr");
    int id_Zuhur = record.indexOf("Zuhur");
    int id_Asar = record.indexOf("Asar");
    int id_Maghrib = record.indexOf("Maghrib");
    int id_Isha = record.indexOf("Isha");

    if(query.exec())
    {
        while(query.next())
        {
            PrayerTimes.insert("Fajr", query.value(id_Fajr).toTime());
            PrayerTimes.insert("Zuhur", query.value(id_Zuhur).toTime());
            PrayerTimes.insert("Asar", query.value(id_Asar).toTime());
            PrayerTimes.insert("Maghrib", query.value(id_Maghrib).toTime());
            PrayerTimes.insert("Isha", query.value(id_Isha).toTime());
        }
    }
}
