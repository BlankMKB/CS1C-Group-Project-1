#include "membermanager.h"

//constructor
MemberManager::MemberManager(const QString& path) {
    //add database to QT
    m_Database = QSqlDatabase::addDatabase("QSQLITE");
    //set database path
    m_Database.setDatabaseName(path);

    //check if database opened successfully
    if(!m_Database.open()) { DEBUG << "connection with database unsuccessful\n"; }
    else { DEBUG << "connection with database successful\n"; }
}

//destructor
MemberManager::~MemberManager() {
    //close database
    m_Database.close();
    DEBUG << "database connection closed\n";
}





//initializes database with text file
bool MemberManager::InitializeMemberDB() {
    if(Empty()) {
        std::vector<Member> ALLMEMBERS;
        m_FileParser.Read(ALLMEMBERS);
        for(const auto& member : ALLMEMBERS) {
            if(!AddMember(member)) { return false; }
        }
    }
    //everything initialized correctly
    return true;
}

//get member by id
Member MemberManager::MemberById(const int& id) const {
    Member member;

    QSqlQuery query;
    query.prepare("SELECT * FROM ALLMEMBERS WHERE ID = ?");
    query.addBindValue(id);
    query.exec();
    query.next();
    auto record = query.record();

    member = MemberFromRecord(record);

    return member;
}

//get a vector of all members
std::vector<Member> MemberManager::AllMembers() const {
    std::vector<Member> memberList;

    QSqlQuery query("SELECT * FROM ALLMEMBERS");

    while(query.next()) {
        memberList.push_back(MemberFromRecord(query.record()));
    }

    return memberList;
}

//get a vector of [Member, Receipt] pairs
std::vector<std::pair<Member, Receipt>> MemberManager::AllReceipts() const {
    std::vector<std::pair<Member, Receipt>> receipts;
    QSqlQuery query("SELECT * FROM ALLMEMBERS");

    while(query.next()) {
        receipts.push_back(std::make_pair(MemberFromRecord(query.record()), ReceiptFromRecord(query.record())));
    }

    return receipts;
}

//return member count
size_t MemberManager::MemberCount() const {
    QSqlQuery query("SELECT * FROM ALLMEMBERS");

    size_t count = 0;

    if(query.last()) { count = query.at() + 1; }

    return count;
}

//empty
bool MemberManager::Empty() const { return MemberCount() == 0; }





//add member to database
bool MemberManager::AddMember(const Member& member) {
    //parse member object
    const QString name = member.Name();
    const int id = member.Id();
    const bool type = member.Type();
    const QString expirationDate = member.Expiration().DateString();
    const double total = member.RunningTotal();
    const QString receipt = member.receipt().ReceiptString();

    //create an insert query with the perameters to load the table
    QSqlQuery query;
    query.prepare("INSERT INTO ALLMEMBERS (name, id, type, expiration, total, receipt) VALUES (:NAME, :ID, :TYPE, :EXPIRATION, :TOTAL, :RECEIPT)");

    //bind member information to their respective columns
    query.bindValue(":NAME", name);
    query.bindValue(":ID", id);
    query.bindValue(":TYPE", type);
    query.bindValue(":EXPIRATION", expirationDate);
    query.bindValue(":TOTAL", total);
    query.bindValue(":RECEIPT", receipt);

    //check to see if member was added successfully
    if(query.exec()) {
        DEBUG.noquote().nospace() << name << " added successfully\n";
        return true;
    }

    DEBUG << "could not add member";
    return false;
}

//update member in database
bool MemberManager::UpdateMember(const Member& member) {
    const Member* p_Member = &member;
    ExecutiveMember execMember;

    if(member.Type()) {
        execMember = member;
        p_Member = &execMember;
    }
    //parse member object
    const QString name = p_Member->Name();
    const int id = p_Member->Id();
    const bool type = p_Member->Type();
    const QString expirationDate = p_Member->Expiration().DateString();
    const double total = p_Member->RunningTotal();
    const QString receipt = p_Member->receipt().ReceiptString();


    //create an insert query with the perameters to load the table
    QSqlQuery query;
    query.prepare("UPDATE ALLMEMBERS SET NAME = :NAME, ID = :ID, TYPE = :TYPE, EXPIRATION = :EXPIRATION, TOTAL = :TOTAL, RECEIPT = :RECEIPT WHERE NAME = :NAME");
    //bind member information to their respective columns
    query.bindValue(":NAME", name);
    query.bindValue(":ID", id);
    query.bindValue(":TYPE", type);
    query.bindValue(":EXPIRATION", expirationDate);
    query.bindValue(":TOTAL", total);
    query.bindValue(":RECEIPT", receipt);

    //check to see if member was updated successfully
    if(query.exec()) {
        DEBUG.noquote().nospace() << name << " updated successfully\n";
        return true;
    }

    DEBUG << "could not update member";
    return false;
}

//delete member by id
bool MemberManager::DeleteMemberById(const int& id) {
    QSqlQuery query;

    query.prepare("DELETE FROM ALLMEMBERS WHERE ID = ?");
    query.addBindValue(id);

    if(query.exec()) { return true; }
    DEBUG << "could not delete member";
    return false;
}

//delete all
void MemberManager::DeleteAllMembers() { QSqlQuery query("DELETE FROM ALLMEMBERS"); }





//for debug purposes
void MemberManager::PrintMemberDB() const {
    QSqlQuery query("SELECT * FROM ALLMEMBERS");

    while(query.next()) {
        DEBUG << "member: ";
        for(size_t i = 0; i < NUM_MEMBER_COLUMNS; i++) {
            QString value = query.value(i).toString();

            value = "1" ? "Executive" : "Regular";
        }
        DEBUG << "";
    }
}

// reset with text file
void MemberManager::ResetWithTextFile() {
    DeleteAllMembers();
    InitializeMemberDB();
}





//parse receipt string into date object
Receipt MemberManager::ParseReceipt(Member& member, const QString& line) const {
    //receipt object
    Receipt receipt;

    //if receipt is empty, return empty receipt
    if(line == "") { return receipt; }

    //split receipts by day using '#' flag
    auto fullReceipt = line.split("#");

    //for each day
    for(auto& receiptDay : fullReceipt) {
        Item* item;
        QString itemName;
        float itemPrice;
        int itemQuantity;
        int count = 1;

        //split day by items
        auto items = receiptDay.split(", ");

        //ignore extraneous split ""
        if(items[0] == "") { continue; }

        //first item is the purchase date
        Date date(Date::ParseDate(items[0]));

        //for all of the items
        int i = 1;
        while(count < items.size()) {
            /* switch case format
             * 1: item name
             * 2: item price
             * 3: item quantity
             * 4: create item and add to receipt object
             */
            switch(i % 5) {
            // item name
            case 1:
                itemName = items[count];
                count++;
                break;
            // item price
            case 2:
                itemPrice = items[count].toFloat();
                count++;
                break;
            // item quantity
            case 3:
                itemQuantity = items[count].toInt();
                count++;
                break;
            // create item and add to receipt
            case 4:
                //create item
                item = new Item(itemName, itemPrice, itemQuantity);
                //add to receipt
                member.Purchase(item, date);
                receipt.Add(date, item);
                break;
            default:
                itemName = "";
                itemPrice = 0;
                itemQuantity = 0;
                break;
            }
            i++;
        }
    }

    return receipt;
}

//get member from record into member object
Member MemberManager::MemberFromRecord(const QSqlRecord& record) const {
    //assign member information from SQL
    const QString name = record.value("NAME").toString();
    const int id = record.value("ID").toInt();
    const bool type = record.value("TYPE").toBool();
    const QString dateString = record.value("EXPIRATION").toString();
    const float total = record.value("TOTAL").toFloat();
    const QString receiptString = record.value("RECEIPT").toString();

    const Date date = Date::ParseDate(dateString);

    if(type) {
        ExecutiveMember member(name, id, type, date);

        ParseReceipt(member, receiptString);
        member.SetRunningTotal(total);

        return member;
    }
    else {
        Member member(name, id, type, date);

        ParseReceipt(member, receiptString);
        member.SetRunningTotal(total);

        return member;
    }

}

//get receipt from record into receipt object
Receipt MemberManager::ReceiptFromRecord(const QSqlRecord& record) const {
    const QString receiptString = record.value("RECEIPT").toString();
    Member member;
    Receipt receipt = ParseReceipt(member, receiptString);

    return receipt;
}
