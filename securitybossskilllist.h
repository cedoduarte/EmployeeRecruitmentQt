#ifndef SECURITYBOSSSKILLLIST_H
#define SECURITYBOSSSKILLLIST_H

#include "skillchecklist.h"

class SecurityBossSkillList : public SkillCheckList
{
    Q_OBJECT
public:
    explicit SecurityBossSkillList(QWidget *parent = nullptr);
    virtual ~SecurityBossSkillList();
protected:
    void populate() override;
};

#endif // SECURITYBOSSSKILLLIST_H
