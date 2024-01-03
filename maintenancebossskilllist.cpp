#include "maintenancebossskilllist.h"

MaintenanceBossSkillList::MaintenanceBossSkillList(QWidget *parent)
    : SkillCheckList(parent)
{
    populate();
}

MaintenanceBossSkillList::~MaintenanceBossSkillList()
{
}

void MaintenanceBossSkillList::populate()
{
    addSkill("Lectura de planos eléctricos e instrumentación");
    addSkill("Instalación de equipos eléctricos y mecánicos");
    addSkill("Manejo de software de mantenimiento");
}
