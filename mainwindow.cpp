#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "employee.h"
#include "employeetabledialog.h"
#include "enums.h"

const std::map<int, int> MainWindow::s_jobPage {
    { OPERATIONS_MANAGER, 0 },
    { MAINTENANCE_BOSS, 4 },
    { SECURITY_BOSS, 1 },
    { ELECTRICAL_TECHNICIAN, 2 },
    { OPERATOR, 3 }
};

const std::map<int, int> MainWindow::s_jobDegree {
    { OPERATIONS_MANAGER, FOURTH_LEVEL },
    { MAINTENANCE_BOSS, THIRD_LEVEL },
    { SECURITY_BOSS, THIRD_LEVEL },
    { ELECTRICAL_TECHNICIAN, THIRD_LEVEL },
    { OPERATOR, HIGH_SCHOOL }
};

const std::map<int, int> MainWindow::s_jobProject {
    { OPERATIONS_MANAGER, 50 },
    { MAINTENANCE_BOSS, 25 },
    { SECURITY_BOSS, 30 },
    { ELECTRICAL_TECHNICIAN, 15 },
    { OPERATOR, 5 }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_dbManager.init();
    m_dbManager.connectSqlite();
    m_dbManager.setupDatabase();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_jobCombo_currentIndexChanged(int idx)
{
    (void) idx;
    int job = ui->jobCombo->currentData().toInt();
    int pageIndex = s_jobPage.find(job)->second;
    ui->stackedWidget->setCurrentIndex(pageIndex);
}

void MainWindow::on_saveRecordButton_clicked()
{
    int job = ui->jobCombo->currentData().toInt();
    int degree = ui->professionalDegreeCombo->currentData().toInt();
    int requiredDegree = s_jobDegree.find(job)->second;
    m_degreeValue = getProfessionalDegreeValue(degree, requiredDegree);

    Employee *employee = new Employee;
    employee->setJobPosition(ui->jobCombo->currentText())
        ->setProfessionalSkillCount(getProfessionalSkillCount())
        ->setExperienceYearCount(ui->yearsOfExperienceCombo->currentText().toInt())
        ->setProfessionalDegreeValue(m_degreeValue)
        ->setProjectCount(ui->projectCountCombo->currentText().toInt())
        ->setProjectWeighting(getProjectWeighting())
        ->computeScore();
    if (m_dbManager.insertEmployee(employee))
    {
        ui->statusbar->showMessage("Empleado registrado con éxito");
    }
    delete employee;
}

void MainWindow::on_showRecordsButton_clicked()
{
    EmployeeTableDialog employeeDialog(this);
    employeeDialog.exec();
}

double MainWindow::getProfessionalDegreeValue(int degree, int requiredDegree) const
{
    double professionalDegreeValue = 0.0;
    if (degree == requiredDegree)
    {
        professionalDegreeValue = 1.0;
    }
    else if (degree > requiredDegree)
    {
        professionalDegreeValue = 1.5;
    }
    else if (degree == requiredDegree - 1)
    {
        professionalDegreeValue = 0.5;
    }
    return professionalDegreeValue;
}

int MainWindow::getProfessionalSkillCount() const
{
    int job = -1;
    for (auto it = s_jobPage.cbegin(); it != s_jobPage.cend(); it++)
    {
        if (it->second == ui->stackedWidget->currentIndex())
        {
            job = it->first;
            break;
        }
    }
    switch (job)
    {
        case OPERATIONS_MANAGER: return ui->operationManagerSkillList->checkedItemCount();
        case MAINTENANCE_BOSS: return ui->maintenanceBossSkillList->checkedItemCount();
        case SECURITY_BOSS: return ui->securityBossSkillList->checkedItemCount();
        case ELECTRICAL_TECHNICIAN: return ui->electricalTechnicianSkillList->checkedItemCount();
        case OPERATOR: return ui->operatorSkillList->checkedItemCount();
    }
        return 0;
}

double MainWindow::getProjectWeighting() const
{
    int job = ui->jobCombo->currentData().toInt();
    int minimumProjectCount = s_jobProject.find(job)->second;
    int projectCount = ui->projectCountCombo->currentText().toInt();
    if (projectCount == minimumProjectCount)
    {
        return 90.0;
    }
    if (projectCount > minimumProjectCount)
    {
        return 100.0;
    }
    return 0.0;
}

