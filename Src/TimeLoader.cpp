#include "TimeLoader.h"
#include <QtCore/QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>

const QString DB_PATH = "./master.db";

///////////////////////////////////////////////////////
TimeLoader::TimeLoader()
    : PrayerTimes()
    , Result()
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
    QMap<QString, QVariant>::iterator it = Result.begin();

    for(; it != Result.end(); it++)
    {
        PrayerTimes.insert(it.key(), (*it).value<QTime>());
    }

    return PrayerTimes;
}

///////////////////////////////////////////////////////
bool TimeLoader::LoadTimes()
{
    bool retVal = false;
    if( !OpenDatabase() )
    {
        qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.ms MM/dd/yyyy") << "Error: connection with database fail";
    }
    else
    {
        qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.ms MM/dd/yyyy") << "Database: connection ok";

        retVal = ReadRecord(QDate::currentDate());
    }

    return retVal;
}

///////////////////////////////////////////////////////
bool TimeLoader::OpenDatabase()
{
    Db = QSqlDatabase::addDatabase("QSQLITE", "Master_DB");
    Db.setDatabaseName(DBPath);

    bool ret = Db.open();

    if(!Db.isOpen())
        qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.ms MM/dd/yyyy") << "Connot open database " << DBPath << "Err:" << Db.lastError();

    return (ret) ;
}

///////////////////////////////////////////////////////
bool TimeLoader::ExecuteQuery(const QString & queryString)
{
    bool ret = false;

    QSqlQuery query(Db);

    if(query.exec(queryString))
    {
       qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.ms MM/dd/yyyy") << "Query successful. query size:" << query.size();

       while(query.next())
        {
          QSqlRecord record =  query.record();

          for(int i=0 ; i<record.count(); i++)
            {
                QVariant val = query.value(i);
                QString key = record.fieldName(i);
                Result.insert(key, val);
                ret = true;
            }
        }

    }
    else
    {
        qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.ms MM/dd/yyyy") << "Query execution failed.";
    }

    return (ret);
}

///////////////////////////////////////////////////////
bool TimeLoader::ReadRecord(const QDate dateTime)
{
    QString str = QString("SELECT * From PrayerTimes Where Day='%1'").arg(dateTime.toString("MM/dd/yyyy"));

    return ExecuteQuery(str);
}

