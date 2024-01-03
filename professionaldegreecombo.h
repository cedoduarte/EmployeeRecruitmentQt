#ifndef PROFESSIONALDEGREECOMBO_H
#define PROFESSIONALDEGREECOMBO_H

#include <QComboBox>

class ProfessionalDegreeCombo : public QComboBox
{
    Q_OBJECT
public:
    explicit ProfessionalDegreeCombo(QWidget *parent = nullptr);
    virtual ~ProfessionalDegreeCombo();
private:
    void populate();
};

#endif // PROFESSIONALDEGREECOMBO_H
