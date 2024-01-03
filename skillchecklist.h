#ifndef SKILLCHECKLIST_H
#define SKILLCHECKLIST_H

#include <QListWidget>

class SkillCheckList : public QListWidget
{
    Q_OBJECT
public:
    explicit SkillCheckList(QWidget *parent = nullptr);
    virtual ~SkillCheckList();
    int checkedItemCount() const;
protected:
    virtual void populate() = 0;
    void addSkill(const QString &name);
};

#endif // SKILLCHECKLIST_H
