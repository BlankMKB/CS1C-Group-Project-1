#include "parser.h"

//default constructor
Parser::Parser() {

}

//==========================================PRIVATE MEMBER FUNCTIONS==========================================

//readMembers
bool Parser::readMembers(std::vector<Member>& memberList) {
    //read member file
    QFile inFile(MEMBER_PATH);

    //check to see if file opens correctly
    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "error reading file\n";
        return false;
    }

    int count = 0;
    QString name;
    int number;
    bool type;
    Date tempDate;
    QString line;
    QStringList temp;

    //while member.txt has data to be parsed
    while (!inFile.atEnd()) {

        //only read line if case is between 0 - 3
        if (count % 5 != 4) {
            line = inFile.readLine();
            temp = line.split("\n");
        }

        /* switch case format
         * 0: name
         * 1: id
         * 2: type
         * 3: date
         * 4: create member object and add to vector
         */
        switch (count % 5) {
        // name
        case 0:
            name = temp[0];
            break;
        // number
        case 1:
            number = (temp[0]).toInt();
            break;
        // type
        case 2:
            if (temp[0] == "Executive")
            {
                type = true;
            }
            else if (temp[0] == "Regular")
            {
                type = false;
            }
            break;
        // date
        case 3:
            tempDate = readDate(line);
            break;
        // add member
        case 4:
            addMember(memberList, name, number, type, tempDate);
            break;
        default:
            break;
        }

        count++;
        line = "";
    }

    //everything parsed correctly
    return true;
}

//readItems
bool Parser::readItems(std::vector<Member>& memberList) {
    //parse sales file
    QFile inFile(SALES_PATH);

    //check to see if file opened correctly
    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "error reading file\n";
        return false;
    }

    int count = 0;
    Date purchaseDate;
    int id;
    QString itemName;
    float itemPrice;
    int itemQuantity;

    QString line;
    QStringList temp;

    //while sales.txt has data to be parsed
    while(!inFile.atEnd()) {

        //only read line if case is between 0 - 4
        if(count % 6 != 5) {
            line = inFile.readLine();
            temp = line.split("\n");
        }

        /* switch case format
         * 0: purchase date
         * 1: id
         * 2: item name
         * 3: item price
         * 4: item quantity
         * 5: create receipt object and add to vector
         */
        switch(count % 6) {
        // purchase date
        case 0:
            purchaseDate = readDate(line);
            break;
        // member id
        case 1:
            id = (temp[0]).toInt();
            break;
        // item name
        case 2:
            itemName = temp[0];
            break;
         // item price
        case 3:
            itemPrice = (temp[0]).toFloat();
            break;
        //item quantity
        case 4:
            itemQuantity = (temp[0]).toInt();
            break;
        //create receipt object and add it to the vector of members
        case 5:
            addToReceipt(itemName, itemPrice, itemQuantity, purchaseDate, id, memberList);
            break;
        default:
            break;
        }

        count++;
        line = "";
    }

    //everything parsed correctly
    return true;

}


//readDate
Date Parser::readDate(QString& line) {
    QStringList temp;
    int day, month, year;

    for(size_t i = 0; i < 3; i++) {

        /* switch case format
         * 0: day
         * 1: month
         * 2: year
         */
        switch (i) {
        // day
        case 0:
            temp = line.split("/");
            day = (temp[0]).toInt();
            break;
        // month
        case 1:
            temp = line.split("/");
            month = (temp[1]).toInt();
            break;
        // year
        case 2:
            temp = line.split("/");
            year = (temp[2]).toInt();
            break;
        default:
            break;
        }
    }

    Date date(day, month, year);

    return date;
}

//addMember
void Parser::addMember(std::vector<Member>& memberList, const QString& name, const int& number, const bool& type, const Date& tempDate) {
    //create member object based on member type:
    //true = executive
    //false = regular
    if(type) {
        ExecutiveMember temp(name, number, type, tempDate);
        memberList.push_back(temp);
    }
    else {
        Member temp(name, number, type, tempDate);
        memberList.push_back(temp);
    }
}

//addToReceipt
bool Parser::addToReceipt(const QString& itemName, const float& itemPrice, const int& itemQuantity, const Date& purchaseDate, const int& id, std::vector<Member>& memberList) {
    Item* item = new Item(itemName, itemPrice);


    for(auto& member : memberList) {
        if(member.id() == id) {
            //purchase the item
            member.purchase(item, itemQuantity, purchaseDate);
            this->m_Inventory.insertInventory(item, itemQuantity);
            return true;
        }
    }

    delete item;
    return false;
}

//round
void Parser::round(float& number) const {

}

//=============================================================================================================


//===========================================PUBLIC MEMBER FUNCTIONS===========================================

//read
bool Parser::read(std::vector<Member>& memberList) {
    bool members = readMembers(memberList);
    bool items = readItems(memberList);

    debug(memberList);

    //everything parsed correctly
    return members && items;
}

ItemList Parser::inventory() const {
    return this->m_Inventory;
}

//debug
void Parser::debug(const std::vector<Member>& memberList) {
    for(const auto& member : memberList) {

        QString type = "Regular";

        if(member.type()) {
            type = "Executive";
        }

        QDebug dbg = qDebug().noquote().nospace();
        dbg << "name: " << member.name() << "\n";
        dbg << "number: " << member.id() << "\n";
        dbg << "type: " << type << "\n";
        dbg << "expiration date: " << member.expiration().dateString() << "\n";
        dbg << "running total: " << member.runningTotal() << "\n";
        dbg << "receipt: " << member.receipt().receiptString() << "\n\n";
    }
}

//=============================================================================================================
