#include "operationmanagerskilllist.h"

OperationManagerSkillList::OperationManagerSkillList(QWidget *parent)
    : SkillCheckList(parent)
{
    populate();
}

OperationManagerSkillList::~OperationManagerSkillList()
{
}

void OperationManagerSkillList::populate()
{
    addSkill("Liderazgo");
    addSkill("Manejo de idiomas");
    addSkill("Organización empresarial");
}
