
#include "MailingAddress.h"


MailingAddress::MailingAddress(string street, string city, string state, int zipCode) {
    this->street = std::move(street);
    this->city = std::move(city);
    this->state = std::move(state);
    this->zipCode = zipCode;
}

bool MailingAddress::equals(const MailingAddress &a) {
    if (this->street != a.street) return false;
    if (this->city != a.city) return false;
    if (this->state != a.state) return false;
    return zipCode == a.zipCode;
}

string MailingAddress::toString() {
    string str = "{";
    str.append(street).append(", ").append(city).append(", ").append(state).append(", ").append(
            to_string(zipCode)).append("}");
    return str;
}
