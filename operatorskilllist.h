#ifndef OPERATORSKILLLIST_H
#define OPERATORSKILLLIST_H

#include "skillchecklist.h"

class OperatorSkillList : public SkillCheckList
{
    Q_OBJECT
public:
    explicit OperatorSkillList(QWidget *parent = nullptr);
    virtual ~OperatorSkillList();
protected:
    void populate() override;
};

#endif // OPERATORSKILLLIST_H
