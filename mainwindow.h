#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "databasemanager.h"

#include <QMainWindow>
#include <map>

namespace Ui
{
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();
private slots:
    void on_jobCombo_currentIndexChanged(int index);
    void on_saveRecordButton_clicked();
    void on_showRecordsButton_clicked();
private:
    double getProfessionalDegreeValue(int degree, int requiredDegree) const;
    int getProfessionalSkillCount() const;
    double getProjectWeighting() const;

    Ui::MainWindow *ui;
    DatabaseManager m_dbManager;
    double m_degreeValue;
    static const std::map<int, int> s_jobPage;
    static const std::map<int, int> s_jobDegree;
    static const std::map<int, int> s_jobProject;
};

#endif // MAINWINDOW_H
