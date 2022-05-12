#include "executivemember.h"

//default constructor
ExecutiveMember::ExecutiveMember() : Member(), m_RebateAmount(0) {
    m_RunningTotal = 120;
}


//overloaded constructor
ExecutiveMember::ExecutiveMember(const Member& member) : m_RebateAmount(0.02) {
    m_Name = member.name();
    m_Number = member.id();
    m_Type = true;
    m_ExpirationDate = member.expiration();
    m_Receipt = member.receipt();
    m_RunningTotal = member.runningTotal();
}

//overloaded constructor
ExecutiveMember::ExecutiveMember(const QString& name, const int& id, const bool& type, const Date& date) : Member(name, id, type, date), m_RebateAmount(0.02) {
    m_RunningTotal = 120;
}

//rebate amount
float ExecutiveMember::rebateAmount() const {
    return m_RebateAmount;
}

//set rebate amount
void ExecutiveMember::setRebateAmount(const float& amt) {
    m_RebateAmount = amt;
}
