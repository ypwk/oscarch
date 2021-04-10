//
// Created by ojcch on 2/20/2020.
//

#include <entity/MailingAddress.h>

MailingAddress::MailingAddress(string street, string city, string state, int zipCode) {
    //move avoids making copies of the parameters
    this->street = std::move(street);
    this->city = std::move(city);
    this->state = std::move(state);
    this->zipCode = zipCode;
}

bool MailingAddress::equals(const MailingAddress &addr) {
    if (this->street != addr.street) return false;
    if (this->city != addr.city) return false;
    if (this->state != addr.state) return false;
    return zipCode == addr.zipCode;
}

string MailingAddress::toString() {
    string str = "{";
    str.append(street).append(", ").append(city).append(", ").append(state).append(", ").append(
            to_string(zipCode)).append("}");
    return str;
}


bool  MailingAddress::operator<(MailingAddress const &addr) {
    if (street < addr.street) return true;
    if (street == addr.street && city < addr.city) return true;
    if (street == addr.street && city == addr.city && state < addr.state) return true;
    return street == addr.street && city == addr.city && state == addr.state && zipCode < addr.zipCode;
}

bool  MailingAddress::operator<=(MailingAddress const &addr) {
    return *this < addr || this->equals(addr);
}

string MailingAddress::getStreet() {
    return street;
}

string MailingAddress::getCity() {
    return city;
}

string MailingAddress::getState() {
    return state;
}

int MailingAddress::getZipCode() {
    return zipCode;
}
