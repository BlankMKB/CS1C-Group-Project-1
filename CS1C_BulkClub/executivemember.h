#ifndef EXECUTIVEMEMBER_H
#define EXECUTIVEMEMBER_H

#include "member.h"

/*!
 * \class ExecutiveMember
 * \brief The ExecutiveMember Class
 * \details This class is inherited from the Member class
 * \paragraph This class is used to create executive member
 * objects. The default constructor
 * sets the rebate amount to 2% (0.02) and the running
 * total to $120. The constructor that takes in a Member
 * parameter is to convert a member between regular to
 * executive. This class overridesRebateAmount() to return 2% (0.02).
 * \note This class has a defaulted copy constructor, default destructor, and operator=().
 */
class ExecutiveMember : public Member {
// constructors
public:
    /*!
     * \fn ExecutiveMember()
     * \brief Default constructor
     */
    ExecutiveMember();

    /*!
     * \fn ExecutiveMember(Member& member)
     * \brief Overloaded constructor
     * \param otherMember: Member
     */
    ExecutiveMember(const Member& member);

    /*!
     * \fn ExecutiveMember(const QString&, const int&, const bool& const Date&)
     * \brief Overloaded constructor
     * \param name: QString
     * \param id: int
     * \param member type: bool
     * \param expiration date: Date
     */
    ExecutiveMember(const QString& name, const int& id, const bool& type, const Date& date);

// accessors
public:
    /*!
     * \fn RebateAmount()
     * \brief Returns rebate amount
     * \return rebateAmount: float
     */
    float RebateAmount() const override;

// mutators
public:
    /*!
     * \fn SetRebateAmount(const float&)
     * \brief sets rebate amount
     * \param rebateAmount: float
     */
    void SetRebateAmount(const float& rebateAmount);

// default functions
public:
    /*!
     * \fn ExecutiveMember(const ExecutiveMember&)
     * \brief Default copy constructor
     * \param other: ExecutiveMember
     */
    ExecutiveMember(const ExecutiveMember& other) = default;

    /*!
     * \fn operator=(const ExecutiveMember&)
     * \brief Default operator=
     * \param other: ExecutiveMember
     */
    ExecutiveMember& operator=(const ExecutiveMember& other) = default;
    /*!
     * \fn ~ExecutiveMember()
     * \brief Default destructor
     */
    ~ExecutiveMember() = default;

// variables
private:
    float m_RebateAmount; /*!< \var rebate amount: float */

};

#endif // EXECUTIVEMEMBER_H
