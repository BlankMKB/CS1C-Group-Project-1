#include "parser.h"

Parser::Parser() {

}

Date Parser::readDate(QString& line) {
    QStringList temp;
    int day, month, year;

    for(size_t i = 0; i < 3; i++) {
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

        case 3:
            break;
        }
    }

    Date date(day, month, year);

    return date;
}

bool Parser::read(std::vector<Member>& memberList) {

    readMembers(memberList);
    readItems(memberList);

}

bool Parser::addToReceipt(const QString& itemName, const float& itemPrice, const int& itemQuantity, const Date& purchaseDate, const int& id, std::vector<Member>& memberList) {
    Item item(itemName, itemPrice);

    for(auto& member : memberList) {
        if(member.id() == id) {
            member.purchase(&item, itemQuantity, purchaseDate);
            return true;
        }
    }
    return false;
}

bool Parser::readItems(std::vector<Member>& memberList) {
    QFile inFile(SALES_PATH);

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

    while(!inFile.atEnd()) {
        if(count % 6 != 5) {
            line = inFile.readLine();
            temp = line.split("\n");
        }

        switch(count % 6) {
            //purchase date
            case 0:
                purchaseDate = readDate(line);
                break;
            case 1:
            //member id
                id = (temp[0]).toInt();
                break;
            //item name
            case 2:
                itemName = temp[0];
                break;
            //item price
            case 3:
                itemPrice = (temp[0]).toFloat();
                break;
            //item quantity
            case 4:
                itemQuantity = (temp[0]).toInt();
                break;
            case 5:
                addToReceipt(itemName, itemPrice, itemQuantity, purchaseDate, id, memberList);
                break;
            default:
                break;
        }

        count++;
        line = "";
    }
    debug(memberList);
    return true;

}

bool Parser::readMembers(std::vector<Member>& memberList) {

    QFile inFile(MEMBER_PATH);

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

    while (!inFile.atEnd())
    {
        if (count % 5 != 4)
        {
            line = inFile.readLine();
            temp = line.split("\n");
        }
        switch (count % 5)
        {

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
        case 3:
            tempDate = readDate(line);
            break;
        case 4:
            addMember(memberList, name, number, type, tempDate);
            break;
        default:
            break;
        }

        count++;
        line = "";
    }
    debug(memberList);

    return true;
}

void Parser::addMember(std::vector<Member>& memberList, const QString& name, const int& number, const bool& type, const Date& tempDate) {
    if(type) {
        Member temp(name, number, type, tempDate);
        memberList.push_back(temp);
    }
    else {
        ExecutiveMember temp(name, number, type, tempDate);
        memberList.push_back(temp);
    }
}

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
        dbg << "receipt: " << member.receipt().size() << "\n\n";

    }
}
