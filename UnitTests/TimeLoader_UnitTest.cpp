#include "TimeLoader.h"
#include <gtest/gtest.h>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QFileInfo>
#include <QtSql/QSqlError>
#include <QDebug>

class TimeLoaderTest: public  testing::Test
{
public:
  TimeLoaderTest()
      : TimeLoaderObj()
  {

  }

  ~TimeLoaderTest()
  {

  }

  bool CreateSampleDatabase()
  {
      QSqlDatabase db;

      bool ret = false;
      if(CreateAndOpenTestDB(db))
      {
         if(AddTable(db))
           if(AddSampleRecords(db))
        ret = CloseDb(db);
      }
      else
      {
          qDebug() << "Error CreateAndOpenTestDB()";
      }

      QSqlDatabase::removeDatabase("QSQLITE");

      return (ret);
  }

  bool CreateAndOpenTestDB(QSqlDatabase& db)
  {
     db = QSqlDatabase::addDatabase("QSQLITE", "TestConnection");
     db.setDatabaseName("./master.db");

     return (db.open());
  }

  bool AddTable(QSqlDatabase& db)
  {
    QString queryString("CREATE Table PrayerTimes(Day DateTime UNIQUE,"
                        "Fajar Time, Zuhur Time, Asar Time, Maghrib Time, Isha Time);");

    QSqlQuery query(db);

    bool ret = query.exec(queryString);

    if(!ret)
        qDebug() << "AddTable() Failed " << query.lastError() << "\n";

    return(ret);
  }

  bool AddRecord(QSqlDatabase& db, QDate day ,QTime fajr, QTime zuhur, QTime asr, QTime maghrib, QTime isha)
  {
    QString queryString = QString("INSERT INTO PrayerTimes('Day', 'Fajar', 'Zuhur', 'Asar', 'Maghrib', 'Isha')\
            VALUES('%1','%2', '%3', '%4', '%5', '%6');")
            .arg(day.toString("MM/dd/yyyy"))
            .arg(fajr.toString("hh:mm"))
            .arg(zuhur.toString("hh:mm"))
            .arg(asr.toString("hh:mm"))
            .arg(maghrib.toString("hh:mm"))
            .arg(isha.toString("hh:mm"));

    QSqlQuery query(db);

    bool ret = query.exec(queryString);

    if(!ret) qDebug() << "AddRecord Failed! " << query.lastError();

    return(ret);
  }

  bool AddSampleRecords(QSqlDatabase& db)
  {
    bool ret = false;
    QDate today = QDate::currentDate();
    ret = AddRecord(db, today, QTime::fromString("06:00"), QTime::fromString("01:00"), QTime::fromString("04:00"), QTime::fromString("06:15"), QTime::fromString("08:00"));
    ret = AddRecord(db, today.addDays(1), QTime::fromString("06:15"), QTime::fromString("01:05"), QTime::fromString("04:15"), QTime::fromString("06:23"), QTime::fromString("08:15"));
    ret = AddRecord(db, today.addDays(2), QTime::fromString("06:20"), QTime::fromString("01:10"), QTime::fromString("04:18"), QTime::fromString("06:30"), QTime::fromString("09:05"));

    return ret;
  }

  bool TestDbFileExists()
  {
      QFileInfo file("./master.db");

      return (file.exists());
  }

  bool CloseDb(QSqlDatabase& db)
  {
     db.close();
     db.removeDatabase("QSQLITE");

     return !db.isOpen();
  }

  bool DeleteTestDbFile()
  {
      QFile file("./master.db");


      if(file.exists())
        return  file.remove();
      else
        return true;

  }

   TimeLoader TimeLoaderObj;

};

/////////////////////////////////////////////////////////////////////
TEST_F(TimeLoaderTest, TestDatabaseIsCreated)
{
  QSqlDatabase db;
  ASSERT_FALSE(TestDbFileExists());
  ASSERT_TRUE(CreateAndOpenTestDB(db));
  ASSERT_TRUE(TestDbFileExists());
  ASSERT_TRUE(DeleteTestDbFile());
  ASSERT_FALSE(TestDbFileExists());
}

/////////////////////////////////////////////////////////////////////
TEST_F(TimeLoaderTest, GivenValidDatabaseWhenLoadTimesIsCalledThenItReturnsTrue)
{
  ASSERT_TRUE(DeleteTestDbFile());
  ASSERT_TRUE(CreateSampleDatabase());

  ASSERT_TRUE(TimeLoaderObj.LoadTimes());
  QMap<QString, QTime> times = TimeLoaderObj.GetLoadedTime();

  ASSERT_TRUE(times.size() > 0);
  EXPECT_EQ(QTime::fromString("06:00"), times["Fajar"]);
  ASSERT_TRUE(DeleteTestDbFile());

}
