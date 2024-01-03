#include "operatorskilllist.h"

OperatorSkillList::OperatorSkillList(QWidget *parent)
    : SkillCheckList(parent)
{
    populate();
}

OperatorSkillList::~OperatorSkillList()
{
}

void OperatorSkillList::populate()
{
    addSkill("Manejo de equipos eléctricos y mecánicos");
}
