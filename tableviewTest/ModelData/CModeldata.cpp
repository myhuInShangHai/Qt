#include "CModelData.h"

CModelData::CModelData(const QString & StrAge, const QString & StrSex, const QString & StrJoin, const QDateTime & dateTime,
                       const int &iProcess):
    m_strAge(StrAge), m_strSex(StrSex), m_strJoin(StrJoin), m_dateTime(dateTime), m_process(iProcess)
{

}

CModelData::~CModelData()
{

}

void CModelData::setAge(const QString &StrAge)
{
    m_strAge = StrAge;
}

QString CModelData::getAge() const
{
    return m_strAge;
}

void CModelData::setJoin(const QString &StrJoin)
{
    m_strJoin = StrJoin;
}

QString CModelData::getJoin() const
{
    return m_strJoin;
}

void CModelData::setSex(const QString &StrSex)
{
    m_strSex = StrSex;
}

QString CModelData::getSex() const
{
    return m_strSex;
}

void CModelData::setTime(const QDateTime &dateTime)
{
    m_dateTime = dateTime;
}

QDateTime CModelData::getTime() const
{
    return m_dateTime;
}

void CModelData::setProcess(const int &iProcess)
{
    m_process = iProcess;
}

int CModelData::getProcess() const
{
    return m_process;
}
