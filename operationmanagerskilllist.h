#ifndef OPERATIONMANAGERSKILLLIST_H
#define OPERATIONMANAGERSKILLLIST_H

#include "skillchecklist.h"

class OperationManagerSkillList : public SkillCheckList
{
    Q_OBJECT
public:
    explicit OperationManagerSkillList(QWidget *parent = nullptr);
    virtual ~OperationManagerSkillList();
protected:
    void populate() override;
};

#endif // OPERATIONMANAGERSKILLLIST_H
