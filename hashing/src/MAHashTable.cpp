
#include "MAHashTable.h"


void MAHashTable::insert(const MailingAddress &address) {
    long hash = hashAddress(address); //get the hash
    table[hash].push_back(address); //insert it
    N++; //one more element in the table
}

long MAHashTable::hashAddress(const MailingAddress &address) {
    long temp1 = (hashString(address.street) * R + hashString(address.city)) % M;
    long temp2 = (temp1 * R + hashString(address.state)) % M;
    long hash = (temp2 * R + hashInt(address.zipCode)) % M;
    return hash;
}


bool MAHashTable::contains(MailingAddress address) {
    long i = hashAddress(address); //get the hash
    vector<MailingAddress> &vect = table[i]; //get its vector
    for (const MailingAddress &a: vect) //check if the address is there in the list
        if (address.equals(a)) return true; //found
    return false; //not found
}

void MAHashTable::print(int i, const vector<MailingAddress> &vector) {
    string stringVec = "[";
    for (MailingAddress a: vector)
        stringVec.append(a.toString()).append("; ");
    if (!vector.empty())
        stringVec.erase(stringVec.end() - 2, stringVec.end());
    stringVec.append("]");
    cout << i << "->" << stringVec; // prints [i->vector]
}

void MAHashTable::print() {
    for (int i = 0; i < M; ++i) { //prints each slot in the table
        print(i, table[i]);
        cout << endl;
    }
}

long MAHashTable::hashString(const string &s) {
    long hash = 0;
    for (char w : s) {
        hash = (R * hash + w) % M;
    }
    return hash;
}

long MAHashTable::hashInt(int i) {
    return i % M;
}

MAHashTable::MAHashTable() {
    table.resize(M);
    N= 0;
}

float MAHashTable::getLoadFactor() const {
    return (float) N / M;
}

