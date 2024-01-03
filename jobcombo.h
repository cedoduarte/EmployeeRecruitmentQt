#ifndef JOBCOMBO_H
#define JOBCOMBO_H

#include <QComboBox>

class JobCombo : public QComboBox
{
    Q_OBJECT
public:
    explicit JobCombo(QWidget *parent = nullptr);
    virtual ~JobCombo();
private:
    void populate();
};

#endif // JOBCOMBO_H
