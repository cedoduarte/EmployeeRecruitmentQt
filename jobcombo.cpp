#include "jobcombo.h"
#include "enums.h"

JobCombo::JobCombo(QWidget *parent)
    : QComboBox(parent)
{
    populate();
}

JobCombo::~JobCombo()
{
}

void JobCombo::populate()
{
    addItem("Gerente de operaciones", OPERATIONS_MANAGER);
    addItem("Jefe de mantenimiento", MAINTENANCE_BOSS);
    addItem("Jefe de seguridad", SECURITY_BOSS);
    addItem("Técnico eléctrico", ELECTRICAL_TECHNICIAN);
    addItem("Operador", OPERATOR);
}
