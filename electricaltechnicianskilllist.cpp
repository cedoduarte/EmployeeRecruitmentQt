#include "electricaltechnicianskilllist.h"

ElectricalTechnicianSkillList::ElectricalTechnicianSkillList(QWidget *parent)
    : SkillCheckList(parent)
{
    populate();
}

ElectricalTechnicianSkillList::~ElectricalTechnicianSkillList()
{
}

void ElectricalTechnicianSkillList::populate()
{
    addSkill("Instalación de equipos eléctricos y mecánicos");
    addSkill("Lectura de planos eléctricos");
}
