#ifndef EMPLOYEETABLEDIALOG_H
#define EMPLOYEETABLEDIALOG_H

#include <QDialog>

class QSqlQueryModel;

namespace Ui
{
class EmployeeTableDialog;
}

class EmployeeTableDialog : public QDialog
{
    Q_OBJECT
public:
    explicit EmployeeTableDialog(QWidget *parent = nullptr);
    virtual ~EmployeeTableDialog();
private:
    Ui::EmployeeTableDialog *ui;
    QSqlQueryModel *m_employeeModel;
};

#endif // EMPLOYEETABLEDIALOG_H
