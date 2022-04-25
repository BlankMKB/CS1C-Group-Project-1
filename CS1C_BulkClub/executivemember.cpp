#include "executivemember.h"

ExecutiveMember::ExecutiveMember(const QString& name, const int& id, const bool& type, const Date& date) : Member(name, id, type, date) {
    this->m_RebateAmount = 0.02;
    this->m_RunningTotal = 120;
}
