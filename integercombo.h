#ifndef INTEGERCOMBO_H
#define INTEGERCOMBO_H

#include <QComboBox>

class IntegerCombo : public QComboBox
{
    Q_OBJECT
public:
    explicit IntegerCombo(QWidget *parent = nullptr);
    virtual ~IntegerCombo();
private:
    void populate();
};

#endif // INTEGERCOMBO_H
