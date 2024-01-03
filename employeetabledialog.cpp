#include "employeetabledialog.h"
#include "ui_employeetabledialog.h"

#include <QSqlQueryModel>
#include <QSqlQuery>

EmployeeTableDialog::EmployeeTableDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EmployeeTableDialog)
{
    ui->setupUi(this);
    m_employeeModel = new QSqlQueryModel(this);
    m_employeeModel->setQuery(QSqlQuery("SELECT * FROM employee"));
    ui->tableView->setModel(m_employeeModel);
}

EmployeeTableDialog::~EmployeeTableDialog()
{
    delete ui;
}
