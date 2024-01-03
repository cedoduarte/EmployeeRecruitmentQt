#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>

class Employee;

class DatabaseManager
{
public:
    explicit DatabaseManager();
    virtual ~DatabaseManager();
    void init();
    void connectSqlite();
    void setupDatabase();
    bool insertEmployee(Employee *employee);
private:
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
