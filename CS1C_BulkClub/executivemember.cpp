#include "executivemember.h"

//default constructor
ExecutiveMember::ExecutiveMember() : Member(), m_RebateAmount(0.02) {
    m_RunningTotal = 120;
}


//overloaded constructor
ExecutiveMember::ExecutiveMember(const Member& member) : m_RebateAmount(0.02) {
    m_Name = member.Name();
    m_Number = member.Id();
    m_Type = true;
    m_ExpirationDate = member.Expiration();
    m_Receipt = member.receipt();
    m_RunningTotal = member.RunningTotal();
}

//overloaded constructor
ExecutiveMember::ExecutiveMember(const QString& name, const int& id, const bool& type, const Date& date) : Member(name, id, type, date), m_RebateAmount(0.02) { m_RunningTotal = 120; }

//rebate amount
float ExecutiveMember::RebateAmount() const { return m_RebateAmount; }

//set rebate amount
void ExecutiveMember::SetRebateAmount(const float& amt) { m_RebateAmount = amt; }
