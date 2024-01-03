#include "skillchecklist.h"

#include <QListWidgetItem>

SkillCheckList::SkillCheckList(QWidget *parent)
    : QListWidget(parent)
{
}

SkillCheckList::~SkillCheckList()
{
}

int SkillCheckList::checkedItemCount() const
{
    int counter = 0;
    for (int i = 0; i < count(); i++)
    {
        if (item(i)->checkState() == Qt::Checked)
        {
            counter++;
        }
    }
    return counter;
}

void SkillCheckList::addSkill(const QString &name)
{
    QListWidgetItem *skillItem = new QListWidgetItem;
    skillItem->setText(name);
    skillItem->setFlags(skillItem->flags() | Qt::ItemIsUserCheckable);
    skillItem->setCheckState(Qt::Unchecked);
    addItem(skillItem);
}
