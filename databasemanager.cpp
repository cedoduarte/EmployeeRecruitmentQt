#include "databasemanager.h"
#include "employee.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager()
{
}

DatabaseManager::~DatabaseManager()
{
    m_db.close();
}

void DatabaseManager::init()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("employee_recruitment.sqlite");
}

void DatabaseManager::connectSqlite()
{
    if (m_db.open())
    {
        qDebug() << "database opened successfully!";
    }
    else
    {
        qDebug() << m_db.lastError().text() << __FILE__ << __LINE__;
    }
}

void DatabaseManager::setupDatabase()
{
    QSqlQuery query;
    if (query.prepare(Employee::sqlCreational()))
    {
        if (query.exec())
        {
            qDebug() << "employee table created successfully!";
        }
        else
        {
            qDebug() << query.lastError().text() << __FILE__ << __LINE__;
        }
    }
    else
    {
        qDebug() << query.lastError().text() << __FILE__ << __LINE__;
    }
}

bool DatabaseManager::insertEmployee(Employee *employee)
{
    QSqlQuery query;
    if (query.prepare(Employee::sqlInsertion()))
    {
        query.bindValue(":job_position", employee->jobPosition());
        query.bindValue(":professional_skill_count", employee->professionalSkillCount());
        query.bindValue(":experience_year_count", employee->experienceYearCount());
        query.bindValue(":professional_degree_value", employee->professionalDegreeValue());
        query.bindValue(":project_count", employee->projectCount());
        query.bindValue(":project_weighting", employee->projectWeighting());
        query.bindValue(":score", employee->score());
        if (query.exec())
        {
            qDebug() << "employee inserted successfully!";
            return true;
        }
        else
        {
            qDebug() << query.lastError().text() << __FILE__ << __LINE__;
        }
    }
    else
    {
        qDebug() << query.lastError().text() << __FILE__ << __LINE__;
    }
    return false;
}
