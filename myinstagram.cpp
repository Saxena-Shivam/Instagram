#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Account {
private:
    string firstname;
    string lastname;
    string username;
    string password; 
    
public:

    static long userid;
    long   getUserId() { return userid; }
    string getFirstName() { return firstname; }
    string getLastName() { return lastname; }
    string getUserName() { return username; }
    string getPassword() { return password; } 
    void create_account(string fname, string lname, string uname, string pward); 
};
long Account::userid = 2039;
ostream& operator<<(ostream& os, Account& acc) {
    os << "First Name: " << acc.getFirstName() << endl;
    os << "Last Name: " << acc.getLastName() << endl;
    os << "User Name: " << acc.getUserName() << endl;
    os << "Password: " << acc.getPassword() << endl; 
    os << "UserId: " << acc.getUserId() << endl;
    
    return os;
}

int main() {
    Account acc;
    int choice;
    // long UsserId,PostId;
    string fname, lname, uname, pward;
    cout << "***INSTAGRAM***" << endl;
    do {
        cout << "\n\tSelect one option below ";
        cout << "\n\t1 Create an Account"; 
        cout << "\n\t2 See Post"; 
        cout << "\n\t3 Add a post"; 
        cout << "\n\t4 Delete a Post"; 
        cout << "\n\t5 Delete an Account"; 
        cout << "\n\t6 Show All Accounts";
        cout << "\n\t7 Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter First Name: ";
            cin >> fname;
            cout << "Enter Last Name: ";
            cin >> lname;
            cout << "Enter User Name: "; 
            cin >> uname;
            cout << "Enter Password: "; 
            cin >> pward;
            acc.create_account(fname, lname, uname, pward);
            cout << endl << "Congratulations! Account is Created" << endl;
            cout << acc; 
            break;
        
        }
    } while (choice != 7); 
    return 0;
}
 void Account::create_account(string fname, string lname, string uname, string pward) {
        firstname = fname;
        lastname = lname;
        username = uname;
        password = pward; 
        userid++;
  }
