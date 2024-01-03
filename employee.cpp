#include "employee.h"

#include <QDebug>

Employee::Employee(QObject *parent)
    : QObject(parent)
{
    setJobPosition("");
    setProfessionalSkillCount(0);
    setExperienceYearCount(0);
    setProfessionalDegreeValue(0.0);
    setProjectCount(0);
    setProjectWeighting(0.0);
    setScore(0.0);
}

Employee::Employee(const Employee &other)
    : QObject(other.parent())
{
    setJobPosition(other.m_jobPosition);
    setProfessionalSkillCount(other.m_professionalSkillCount);
    setExperienceYearCount(other.m_experienceYearCount);
    setProfessionalDegreeValue(other.m_professionalDegreeValue);
    setProjectCount(other.m_projectCount);
    setProjectWeighting(other.m_projectWeighting);
    setScore(other.m_score);
}

Employee::Employee(const QString &jobPosition,
                   int professionalSkillCount,
                   int experienceYearCount,
                   double professionalDegreeValue,
                   int projectCount,
                   double projectWeighting,
                   double score,
                   QObject *parent)
    : QObject(parent)
{
    setJobPosition(jobPosition);
    setProfessionalSkillCount(professionalSkillCount);
    setExperienceYearCount(experienceYearCount);
    setProfessionalDegreeValue(professionalDegreeValue);
    setProjectCount(projectCount);
    setProjectWeighting(projectWeighting);
    setScore(score);
}

Employee::~Employee()
{
}

QString Employee::sqlCreational()
{
    return "CREATE TABLE IF NOT EXISTS employee"
           "(id INTEGER PRIMARY KEY AUTOINCREMENT,"
           "job_position VARCHAR(256),"
           "professional_skill_count INTEGER,"
           "experience_year_count INTEGER,"
           "professional_degree_value REAL,"
           "project_count INTEGER,"
           "project_weighting REAL,"
           "score REAL)";
}

QString Employee::sqlInsertion()
{
    return "INSERT INTO employee("
           "job_position,"
           "professional_skill_count,"
           "experience_year_count,"
           "professional_degree_value,"
           "project_count,"
           "project_weighting,"
           "score) VALUES("
           ":job_position,"
           ":professional_skill_count,"
           ":experience_year_count,"
           ":professional_degree_value,"
           ":project_count,"
           ":project_weighting,"
           ":score)";
}

void Employee::print() const
{
    qDebug() << "job position:" << m_jobPosition;
    qDebug() << "professional skill count:" << m_professionalSkillCount;
    qDebug() << "experience year count:" << m_experienceYearCount;
    qDebug() << "professional degree value:" << m_professionalDegreeValue;
    qDebug() << "project count:" << m_projectCount;
    qDebug() << "project weighting:" << m_projectWeighting;
    qDebug() << "score" << m_score;
}

void Employee::computeScore()
{
    double score = m_experienceYearCount
                   * m_professionalDegreeValue
                   + m_professionalSkillCount
                   + m_projectWeighting;
    setScore(score);
}

Employee* Employee::setJobPosition(const QString &jobPosition)
{
    if (m_jobPosition != jobPosition)
    {
        m_jobPosition = jobPosition;
        emit jobPositionChanged(m_jobPosition);
    }
    return this;
}

Employee* Employee::setProfessionalSkillCount(int professionalSkillCount)
{
    if (m_professionalSkillCount != professionalSkillCount)
    {
        m_professionalSkillCount = professionalSkillCount;
        emit professionalSkillCountChanged(m_professionalSkillCount);
    }
    return this;
}

Employee* Employee::setExperienceYearCount(int experienceYearCount)
{
    if (m_experienceYearCount != experienceYearCount)
    {
        m_experienceYearCount = experienceYearCount;
        emit experienceYearCountChanged(m_experienceYearCount);
    }
    return this;
}

Employee* Employee::setProfessionalDegreeValue(double professionalDegreeValue)
{
    if (m_professionalDegreeValue != professionalDegreeValue)
    {
        m_professionalDegreeValue = professionalDegreeValue;
        emit professionalDegreeValueChanged(m_professionalDegreeValue);
    }
    return this;
}

Employee* Employee::setProjectCount(int projectCount)
{
    if (m_projectCount != projectCount)
    {
        m_projectCount = projectCount;
        emit projectCountChanged(m_projectCount);
    }
    return this;
}

Employee* Employee::setProjectWeighting(double projectWeighting)
{
    if (m_projectWeighting != projectWeighting)
    {
        m_projectWeighting = projectWeighting;
        emit projectWeightingChanged(m_projectWeighting);
    }
    return this;
}

Employee* Employee::setScore(double score)
{
    if (m_score != score)
    {
        m_score = score;
        emit scoreChanged(m_score);
    }
    return this;
}
