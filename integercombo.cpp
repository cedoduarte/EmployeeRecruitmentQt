#include "integercombo.h"

IntegerCombo::IntegerCombo(QWidget *parent)
    : QComboBox(parent)
{
    populate();
    setEditable(true);
    setMaxVisibleItems(10);
}

IntegerCombo::~IntegerCombo()
{
}

void IntegerCombo::populate()
{
    for (int iValue = 0; iValue <= 100; iValue++)
    {
        addItem(QString::number(iValue));
    }
}
