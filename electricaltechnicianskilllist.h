#ifndef ELECTRICALTECHNICIANSKILLLIST_H
#define ELECTRICALTECHNICIANSKILLLIST_H

#include "skillchecklist.h"

class ElectricalTechnicianSkillList : public SkillCheckList
{
    Q_OBJECT
public:
    explicit ElectricalTechnicianSkillList(QWidget *parent = nullptr);
    virtual ~ElectricalTechnicianSkillList();
protected:
    void populate() override;
};

#endif // ELECTRICALTECHNICIANSKILLLIST_H
