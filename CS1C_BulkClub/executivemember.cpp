#include "executivemember.h"

//overloaded constructor
ExecutiveMember::ExecutiveMember(const Member& member) : m_RebateAmount(0.02) {
    this->m_Name = member.name();
    this->m_Number = member.id();
    this->m_Type = true;
    this->m_ExpirationDate = member.expiration();
    this->m_Receipt = member.receipt();
    this->m_RunningTotal = 120;
}

//overloaded constructor
ExecutiveMember::ExecutiveMember(const QString& name, const int& id, const bool& type, const Date& date) : Member(name, id, type, date), m_RebateAmount(0.02) {
    this->m_RunningTotal = 120;
}

//rebate amount
float ExecutiveMember::rebateAmount() const {
    return this->m_RebateAmount;
}

//set rebate amount
void ExecutiveMember::setRebateAmount(const float& amt) {
    this->m_RebateAmount = amt;
}
