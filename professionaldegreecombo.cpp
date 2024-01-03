#include "professionaldegreecombo.h"
#include "enums.h"

ProfessionalDegreeCombo::ProfessionalDegreeCombo(QWidget *parent)
    : QComboBox(parent)
{
    populate();
    setCurrentIndex(0);
}

ProfessionalDegreeCombo::~ProfessionalDegreeCombo()
{
}

void ProfessionalDegreeCombo::populate()
{
    addItem("Cuarto Nivel o Superior", FOURTH_LEVEL);
    addItem("Tercer Nivel o Superior", THIRD_LEVEL);
    addItem("Bachillerato", HIGH_SCHOOL);
}
