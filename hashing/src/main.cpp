

#include <fstream>
#include <sstream>
#include "MailingAddress.h"
#include "MAHashTable.h"


void hashFromFile( string& filePath );


int main(int argc, char *argv[]) {

    //check the arguments
    if(argc <= 1) {
        cout << "Please provide a file path" << endl;
        return 0;
    }

    //hash elements from file
    string filePath = string(argv[1]);
    hashFromFile(filePath);

    return 0;
}


void hashFromFile( string& filePath ) {
    MAHashTable table;

    //-----------------------------
    fstream newfile;
    newfile.open(filePath, ios::in); //open the file

    //file not found
    if (!newfile.is_open())
        throw "Could not find input file";

    //the read the file line by line
    string line;
    while (getline(newfile, line)) {
        stringstream ss(line);
        string item;

        //get the tokens
        vector<string> tokens;
        while (getline(ss, item, ',')) {
            tokens.push_back(item);
        }

        //build the address and hash
        MailingAddress address3 = MailingAddress(tokens.at(0), tokens.at(1), tokens.at(2), stoi(tokens.at(3)));
        table.insert(address3);
    }
    newfile.close(); //close the file

    //---------------------------------

    table.print();

    cout<< "Load Factor: " << table.getLoadFactor() << endl;

    MailingAddress address2 = MailingAddress("450 Highland Ave", "Salem", "MA", 1970);
    cout << (table.contains(address2) ? ("Address was found: " ) : ("Address not found: ")) <<  address2.toString() << endl;
    MailingAddress address3 = MailingAddress("450 Highland Avenue", "Salem", "MA", 1970);
    cout << (table.contains(address3) ? ("Address was found: " ) : ("Address not found: ")) <<  address3.toString() << endl;
}

