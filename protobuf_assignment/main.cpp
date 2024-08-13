#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "compile.pb.h"

using namespace std;

/*Serialize and Deserialize message*/
// void DeserializeMessage(const std::string& serializedData, Person& msg) {
//     if (!msg.ParseFromString(serializedData)) {
//         cerr << "Failed to parse message." << endl;
//         exit(EXIT_FAILURE);
//     }
// }

// int main() {
//     Person p;
//     p.set_id(20);
//     p.set_name("Proto");
//     p.set_email("proto@xyz.com");
//     p.set_phone_number("1234567890");

//     string SerializedData;
//     p.SerializeToString(&SerializedData);

//     Person DeserializedData;
//     DeserializeMessage(SerializedData, DeserializedData);

//     cout << "ID: " << DeserializedData.id() << "\nNAME: " << DeserializedData.name() << "\nEMAIL: " << DeserializedData.email() << "\nPHONE_NUMBER: " << DeserializedData.phone_number() << endl;

//     google::protobuf::ShutdownProtobufLibrary();
//     return 0;
// }

void PromptForAddress(Person* person) {
    cout << "Enter person ID: ";
    int id;
    cin >> id;
    person->set_id(id);
    cin.ignore(256, '\n');

    cout << "Enter Name: ";
    getline(cin, *person->mutable_name());

    cout << "Enter Email: ";
    string email;
    getline(cin, email);
    if (!email.empty()) {
        person->set_email(email);
    }

    cout << "Enter a phone number: ";
    string number;
    getline(cin, number);
    if (!number.empty()) {
        person->set_phone_number(number);
    }

    Person::Address *person_address = person->mutable_address();

    cout << "Enter street: ";
    string street;
    getline(cin, street);
    if (!street.empty()) {
        person_address->set_street(street);
    }

    cout << "Enter city: ";
    string city;
    getline(cin, city);
    if (!city.empty()) {
        person_address->set_city(city);
    }

    cout << "Enter zipcode: ";
    string zipcode;
    getline(cin, zipcode);
    if (!zipcode.empty()) {
        person_address->set_zipcode(zipcode);
    }
}  

void ListPeople(const AddressBook& address_book) {
    cout << "*************************************************************************************" << endl;
    for (int i = 0; i < address_book.people_size(); i++) {
        const Person &person = address_book.people(i);
        cout << "Person ID: " << person.id() << endl;
        cout << "Person NAME: " << person.name() << endl;
        cout << "Person EMAIL: " << person.email() << endl;
        cout << "Person PHONE_NUMBER: " << person.phone_number() << endl;

        const Person::Address &address = person.address();
        cout << "Person STREET: " << address.street() << endl;
        cout << "Person CITY: " << address.city() << endl;
        cout << "Person ZIPCODE: " << address.zipcode() << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " ADRESSBOOK_FILE" << endl;
        return -1;
    }

    AddressBook address_book;
    /*Read existing address book*/
    fstream input(argv[1], ios::in | ios::binary);
    if (!input) {
        cout << argv[1] << ": file not found. createing a new file." << endl;
    } else if (!address_book.ParseFromIstream(&input)) {
        cerr << "Failes to parse address book." << endl;
        return -1;
    }
    
    int num_of_persons;
    cout << "Enter no of persons: ";
    cin >> num_of_persons;

    /*Add person data*/
    for (int i=0; i<num_of_persons; i++) {
        PromptForAddress(address_book.add_people());
    }

    /*write new addressbook back to disk*/
    fstream output(argv[1], ios::out | ios::trunc | ios::binary);
    if (!address_book.SerializeToOstream(&output)) {
        cerr << "Failed to write address book." << endl;
        return -1; 
    }

    cout << "Displaying file content ... " << endl; 
    ListPeople(address_book);
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}