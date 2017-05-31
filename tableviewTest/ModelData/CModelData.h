#ifndef CMODELDATA_H
#define CMODELDATA_H

#include <QString>
#include <QDateTime>

class CModelData
{
public:
    explicit CModelData(const QString & StrAge, const QString & StrSex, const QString & StrJoin, const QDateTime & dateTime, const int &iProcess);
    virtual ~CModelData();

    void setSex(const QString & StrSex);
    QString getSex() const;

    void setAge(const QString & StrAge);
    QString getAge() const;

    void setTime(const QDateTime & dateTime);
    QDateTime getTime() const;

    void setJoin(const QString & StrJoin);
    QString getJoin() const;

    void setProcess(const int & iProcess);
    int getProcess() const;

private:
    QString     m_strSex;   //性别
    QString     m_strAge;   //年龄
    QDateTime   m_dateTime;  //时间
    QString     m_strJoin;  //参与/不参与
    int         m_process;  //进度

};

#endif // CMODELDATA_H
