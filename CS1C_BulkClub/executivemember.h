#ifndef EXECUTIVEMEMBER_H
#define EXECUTIVEMEMBER_H

#include "member.h"


class ExecutiveMember : public Member {
private:
    float m_RebateAmount; /*!< \var rebate amount */

public:
    /*!
     * \brief constructor
     */
    ExecutiveMember();

    /*!
     * \brief overloaded constructor
     * \param otherMember: Member
     */
    ExecutiveMember(const Member&);

    /*!
     * \brief overloaded constructor
     * \param name: QString
     * \param id: int
     * \param member type: bool
     * \param expiration date: Date
     */
    ExecutiveMember(const QString&, const int&, const bool&, const Date&);

    /*!
     * \brief returns rebate amount
     * \return rebateAmount: float
     */
    float RebateAmount() const override;

    /*!
     * \brief sets rebate amount
     * \param rebateAmount: float
     */
    void SetRebateAmount(const float&);
};

#endif // EXECUTIVEMEMBER_H
