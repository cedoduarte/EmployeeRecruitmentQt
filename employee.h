#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QObject>

class Employee : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString jobPosition READ jobPosition WRITE setJobPosition NOTIFY jobPositionChanged FINAL)
    Q_PROPERTY(int professionalSkillCount READ professionalSkillCount WRITE setProfessionalSkillCount NOTIFY professionalSkillCountChanged FINAL)
    Q_PROPERTY(int experienceYearCount READ experienceYearCount WRITE setExperienceYearCount NOTIFY experienceYearCountChanged FINAL)
    Q_PROPERTY(double professionalDegreeValue READ professionalDegreeValue WRITE setProfessionalDegreeValue NOTIFY professionalDegreeValueChanged FINAL)
    Q_PROPERTY(int projectCount READ projectCount WRITE setProjectCount NOTIFY projectCountChanged FINAL)
    Q_PROPERTY(double projectWeighting READ projectWeighting WRITE setProjectWeighting NOTIFY projectWeightingChanged FINAL)
    Q_PROPERTY(double score READ score WRITE setScore NOTIFY scoreChanged FINAL)
public:
    Employee(QObject *parent = nullptr);

    Employee(const Employee &other);

    Employee(const QString &jobPosition,
             int professionalSkillCount,
             int experienceYearCount,
             double professionalDegreeValue,
             int projectCount,
             double projectWeighting,
             double score,
             QObject *parent = nullptr);

    virtual ~Employee();

    static QString sqlCreational();
    static QString sqlInsertion();

    void print() const;

    void computeScore();

    Employee* setJobPosition(const QString &jobPosition);
    Employee* setProfessionalSkillCount(int professionalSkillCount);
    Employee* setExperienceYearCount(int experienceYearCount);
    Employee* setProfessionalDegreeValue(double professionalDegreeValue);
    Employee* setProjectCount(int projectCount);
    Employee* setProjectWeighting(double projectWeighting);
    Employee* setScore(double score);

    QString jobPosition() const { return m_jobPosition; }
    int professionalSkillCount() const { return m_professionalSkillCount; }
    int experienceYearCount() const { return m_experienceYearCount; }
    double professionalDegreeValue() const { return m_professionalDegreeValue; }
    int projectCount() const { return m_projectCount; }
    double projectWeighting() const { return m_projectWeighting; }
    double score() const { return m_score; }
signals:
    void jobPositionChanged(const QString &jobPosition);
    void professionalSkillCountChanged(int professionalSkillCount);
    void experienceYearCountChanged(int experienceYearCount);
    void professionalDegreeValueChanged(double professionalDegreeValue);
    void projectCountChanged(int projectCount);
    void projectWeightingChanged(double projectWeighting);
    void scoreChanged(double score);
private:
    QString m_jobPosition;
    int m_professionalSkillCount;
    int m_experienceYearCount;
    double m_professionalDegreeValue;
    int m_projectCount;
    double m_projectWeighting;
    double m_score;
};

#endif // EMPLOYEE_H
