#include "experiencecombo.h"

#include <QAbstractItemView>

ExperienceCombo::ExperienceCombo(QWidget *parent)
    : QComboBox(parent)
{
    populate();
    setMaxVisibleItems(10);
}

ExperienceCombo::~ExperienceCombo()
{
}

void ExperienceCombo::populate()
{
    for (int iYear = 1; iYear <= 100; iYear++)
    {
        addItem(QString::number(iYear), iYear);
    }
}
