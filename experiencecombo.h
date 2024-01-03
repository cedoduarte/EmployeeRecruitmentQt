#ifndef EXPERIENCECOMBO_H
#define EXPERIENCECOMBO_H

#include <QComboBox>

class ExperienceCombo : public QComboBox
{
    Q_OBJECT
public:
    explicit ExperienceCombo(QWidget *parent = nullptr);
    virtual ~ExperienceCombo();
private:
    void populate();
};

#endif // EXPERIENCECOMBO_H
