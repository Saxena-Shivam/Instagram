#include<iostream>
#include<map>
#include<fstream>
#include<list>
using namespace std;
class Account{
    private:
    long userid;
    string firstname;
    string lastname;
    string username;
    static long nextuserid;
    public:
    list<long>postcontainer;
    list<long>storycontaner;
    Account(){}
    Account(string fname, string lname, string uname);
    long getuserid(){return userid;};
    string getfirstname(){return firstname;};
    string getlastname(){return lastname;};
    string getusername(){return username;};
    void addpost(long postid);
    void addstory(long storyid);
    void getposts();
    void getstories();
    void follow(long userid1,long userid2);
    void unfollow(long userid1 ,long userid2);
    static void setlastuserid(long userid);
    static long getlastuserid();
    friend ofstream & operator<<(ofstream &ofs,Account &acc);
    friend ifstream & operator>>(ifstream &ifs,Account &acc);
    friend ostream & operator<<(ostream &os,Account &acc);
};
long Account:: nextuserid=2039;
class Instagram {
    private:
    map<long,Account>accounts;
    public:
    Instagram();
    Account create_account(string fname, string lname, string uname);
    Account addpost(long userid ,long postid);
    Account upload_story( long userid, long storyid);
    // Account follow( long userid, long userid1);
    // Account unfollow( long userid, long userid1);
    void showallaccounts();
    ~Instagram();
};
int main() {
    Instagram b;
    Account acc;
    int choice;
    long  userid,userid1,storyid,postid;
    string fname, lname, uname;
    cout << "***INSTAGRAM***" << endl;
    do {
        cout << "\n\tSelect one option below ";
        cout << "\n\t1 Create an Account"; 
        cout << "\n\t2 Add Post"; 
        cout << "\n\t3 Upload story"; 
        cout << "\n\t4 Follow an Account"; 
        cout << "\n\t5 Unfollow  an Account"; 
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
            acc=b.create_account(fname, lname, uname);
            cout << endl << "Congratulations! Account is Created" << endl;
            cout << acc; 
            break;
         case 2:
            cout << "Enter Your UserId: ";
                cin >> userid;
                cout << "Enter your Post id: ";
                cin >> postid;
                acc = b.addpost(userid, postid);
                cout << endl << "Your Post is Added" << endl;
                cout << acc;
                break;
        case 3:
            cout<<"Enter userid:";
            cin>>userid;
            cout<<"Enter storyid:";
            cin>>storyid;
            acc=b.upload_story(userid, storyid);
            cout<<endl<<"Story is Uploaded"<<endl;
            cout<<acc;
            
            break;
        // case 4:
        //     cout<<"Enter your Userid:";
        //     cin>>userid;
        //     cout<<"Enter Others userid :";
        //     cin>>userid1;
        //     acc=b.follow(userid, userid1);
        //     cout<<endl<<"You start folowing "<<userid1<<endl;
        //     cout<<acc;
        //     break;
        // case 5:
        //     cout<<"Enter your Userid:";
        //     cin>>userid;
        //     cout<<"Enter Others userid :";
        //     cin>>userid1;
        //     acc=b.unfollow(userid, userid1);
        //     cout<<endl<<"You Unfollow "<<userid1<<endl;
        //     cout<<acc;
        //     break;
        case 6:
            b.showallaccounts();
            break;
        case 7:
             break;
        default:
            cout<<"\nEnter corret choice";
            exit(0);
        }
    } while (choice != 7); 
    return 0;
}
Account::Account(string fname,string lname,string uname)
{
 nextuserid++;
 userid=nextuserid;
 firstname=fname;
 lastname=lname;
 username=uname;
}
void Account::setlastuserid(long userid)
{
 nextuserid=userid;
}
long Account::getlastuserid()
{
 return nextuserid;
}
ofstream & operator<<(ofstream &ofs,Account &acc)
{
 ofs<<acc.userid<<endl;
 ofs<<acc.firstname<<endl;
 ofs<<acc.lastname<<endl;
 ofs<<acc.username<<endl;
 return ofs;
}
ifstream & operator>>(ifstream &ifs,Account &acc)
{
 ifs>>acc.userid;
 ifs>>acc.firstname;
 ifs>>acc.lastname;
 ifs>>acc.username;
 return ifs;
 
}
ostream & operator<<(ostream &os,Account &acc)
{
 os<<"User Id:"<<acc.getuserid()<<endl;
 os<<"First Name:"<<acc.getfirstname()<<endl;
 os<<"Last Name:"<<acc.getlastname()<<endl;
 os<<"User Name:"<<acc.getusername()<<endl;
 os << "Posts: ";
    acc.getposts();
    os << endl;
    os << "Stories: "; acc.getstories();
    os << endl;
    return os;
 return os;
}
Instagram::Instagram()
{
 Account account;
 ifstream infile;
 infile.open("Insta.data");
 if(!infile)
 {
 //cout<<"Error in Opening! File Not Found!!"<<endl;
 return;
 }
 while(!infile.eof())
 {
 infile>>account;
 accounts.insert(pair<long,Account>(account.getuserid(),account));
 }
 Account::setlastuserid(account.getuserid());
 
 infile.close();
 
}
Account Instagram::create_account(string fname,string lname,string uname)
{
 ofstream outfile;
 Account account(fname,lname,uname);
 accounts.insert(pair<long,Account>(account.getuserid(),account));
 
 outfile.open("Insta.data", ios::trunc);
 
 map<long,Account>::iterator itr;
 for(itr=accounts.begin();itr!=accounts.end();itr++)
 {
 outfile<<itr->second;
 }
 outfile.close();
 return account;
}
void Instagram::showallaccounts()
{
 map<long,Account>::iterator itr;
 for(itr=accounts.begin();itr!=accounts.end();itr++)
 {
 cout<<"Account "<<itr->first<<endl<<itr->second<<endl;
 }
}
Instagram::~Instagram()
{
 ofstream outfile;
 outfile.open("insta.data", ios::trunc);
 
 map<long,Account>::iterator itr;
 for(itr=accounts.begin();itr!=accounts.end();itr++)
 {
 outfile<<itr->second;
 }
 outfile.close();
}

Account Instagram::addpost(long userid, long postid) {
    map<long, Account>::iterator itr = accounts.find(userid);
    itr->second.addpost(postid);
    return itr->second;
}

Account Instagram::upload_story(long userid, long storyid) {
    map<long, Account>::iterator itr = accounts.find(userid);
    itr->second.addstory(storyid);
    return itr->second;
}

void Account::addpost(long postid) {
    postcontainer.push_back(postid);
}

void Account::addstory(long storyid) {
    storycontaner.push_back(storyid);
}

void Account::getposts() {
    for (list<long>::iterator it = postcontainer.begin(); it != postcontainer.end(); ++it) {
        cout << *it << " ";
    }
}

void Account::getstories() {
    for (list<long>::iterator it = storycontaner.begin(); it != storycontaner.end(); ++it) {
        cout << *it << " ";
    }
}