#ifndef MAINTENANCEBOSSSKILLLIST_H
#define MAINTENANCEBOSSSKILLLIST_H

#include "skillchecklist.h"

class MaintenanceBossSkillList : public SkillCheckList
{
    Q_OBJECT
public:
    explicit MaintenanceBossSkillList(QWidget *parent = nullptr);
    virtual ~MaintenanceBossSkillList();
protected:
    void populate() override;
};

#endif // MAINTENANCEBOSSSKILLLIST_H
