#ifndef EXECUTIVEMEMBER_H
#define EXECUTIVEMEMBER_H

#include "member.h"


class ExecutiveMember : public Member {
private:
    float m_RebateAmount;

public:
    ExecutiveMember(const Member&);
    ExecutiveMember(const QString&, const int&, const bool&, const Date&);
    float rebateAmount() const;
    void setRebateAmount(const float&);
};

#endif // EXECUTIVEMEMBER_H
