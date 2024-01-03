#include "securitybossskilllist.h"

SecurityBossSkillList::SecurityBossSkillList(QWidget *parent)
    : SkillCheckList(parent)
{
    populate();
}

SecurityBossSkillList::~SecurityBossSkillList()
{
}

void SecurityBossSkillList::populate()
{
    addSkill("Interpretación de las normas de seguridad");
    addSkill("Manejo de software de seguridad industrial");
    addSkill("Manejo de Excel y Word");
}
