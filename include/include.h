#pragma once
#include <algorithm>
#include <ios>
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iomanip>
#include <cstring>
using namespace std;
const string path = "db.txt";
void trim(string &s);
void spilitLine(string &s, vector<string> &words, string seperator = " ");
class Client 
{
private:
  string m_accountNumber;
  string m_pinCode;
  string m_name;
  string m_phone;
  double m_accountBalance;
  static vector<Client> m_clients;
  static bool m_updated;
  void read(bool update = 0)
  {
    /*
       string accountNumber;
       string pinCode;
       string name;
       string phone;
       double accountBalance;
       */
    cout << "Enter accountNumber : ";
    cin >> m_accountNumber;
    if(!update)
    {
      cout << "Enter pinCode : ";
      cin >> m_pinCode;
    }
    cout << "Enter name : ";
    getline(cin >> ws, m_name);
    cout << "Enter phone : ";
    cin >> m_phone;
    cout << "Enter accountBalance : ";
    cin >> m_accountBalance;
    while (cin.fail())
    {
      cin.clear();
      cin.ignore(20000, '\n');
      cout << "Invalid number please try again : ";
      cin >> m_accountBalance;
    }
    if(update)
    {
      Client::saveClintsInFile();
      cout << "Client updated successfully!" << endl;
      return;
    }
    this->save(ios::app);
  }
  void save(ios_base::openmode mode = ios::out)
  {
    Client *q = Client::searchClient(this->getPinCode());
    if(q!=nullptr)
    {
      cout<<"Sorry this account have an existing pinCode try again!\n";
      return;
    }
    m_clients.push_back(*this);
    Client::saveClintsInFile();
    cout << "client saved !\n";
  }
  void saveClientElementsInString(string &s, string seperator)
  {
    s = "";
    s += this->getAccountNumber();
    s += seperator;
    s += this->getPinCode();
    s += seperator;
    s += this->getName();
    s += seperator;
    s += this->getPhone();
    s += seperator;
    s += to_string(this->getAccountBalance());
  }
  static void saveClients(ios_base::openmode mode = ios::out)
  {
    ofstream file;
    file.open(path, mode);
    file.close();
    for(Client &client : m_clients)
    {
      client.save(ios::app);
    }
  }

  void saveClientAtts(vector<string> &atts)
  {
    /*
  string accountNumber;
  string pinCode;
  string name;
  string phone;
  double accountBalance;
  */
    for(string &s : atts)trim(s);
    /* reverse(atts.begin(),atts.end()); */
    this->setAccountNumber(atts[0]);
    this->setPinCode(atts[1]);
    this->setName(atts[2]);
    this->setPhone(atts[3]);
    this->setAccountBalance(stod(atts[4]));
  }
public:
  //constructors
  Client (string acountNumber, string pinCode, string name, string phone, double accountBalance) :
    m_accountNumber(acountNumber), m_pinCode(pinCode), m_name(name), m_phone(phone), m_accountBalance(accountBalance)
  {

  }
  Client()
  {
  }
  //getter
  string getAccountNumber()const
  {
    return m_accountNumber;
  }
  string getPinCode()const
  {
    return m_pinCode;
  }
  string getName()const
  {
    return m_name;
  }
  string getPhone()const
  {
    return m_phone;
  }
  double getAccountBalance()const
  {
    return m_accountBalance;
  }
  static double getTotalBalance()
  {
    double total;
    for(Client &client : m_clients)total += client.m_accountBalance;
    return total;
  }
  //setter
  void setAccountNumber(string accountNumber)
  {
    m_accountNumber = accountNumber;
  }
  void setPinCode(string pinCode)
  {
    m_pinCode = pinCode;
  }
  void setName(string name)
  {
    m_name = name;
  }
  void setPhone(string phone)
  {
    m_phone = phone;
  }
  void setAccountBalance(double accountBalance)
  {
    m_accountBalance = accountBalance;
  }
  bool operator==(const Client &other)const
  {
    return this->m_pinCode == other.m_pinCode;
  }

  //=======================================================
  static void sync()
  {
    m_clients.clear();
    ifstream file(path);
    if(!file)
    {
      cerr << "error in file opening"<<endl;
      return;
    }
    string line = "";
    while(std::getline(file, line))
    {
      if(line == "")break;
      Client client;
      vector<string> elements;
      string separator = " #//# ";
      spilitLine(line, elements,separator);
      client.saveClientAtts(elements);
      m_clients.push_back(client);
    }
    file.close();
    m_updated = 1;
  }
  void print()
  {
    /*
       string accountNumber;
       string pinCode;
       string name;
       string phone;
       double accountBalance;
       */
    /*
       cout << "\n\033[35m============================\n";
       cout << setw(20) << left << "\033[33mAccount Number"
       << "\033[33m: " << client.accountNumber << endl;
       cout << setw(20) << left << "\033[33mPin Code"
       << "\033[33m: " << client.pinCode << endl;
       cout << setw(20) << left << "\033[33mName"
       << "\033[33m: " << client.name << endl;
       cout << setw(20) << left << "\033[33mPhone"
       << "\033[33m: " << client.phone << endl;
       cout << setw(20) << left << "\033[33mAccount Balance"
       << "\033[33m: " << fixed << setprecision(2) << client.accountBalance << endl;
       cout << "\033[35m============================\033[0m\n";
       */
    int sz = 20;
    cout << '|';
    cout << setw(sz) << right << m_accountNumber << '|' << setw(sz) << right << m_pinCode << '|' << setw(sz) << right << m_name << '|' << setw(sz) << right << m_phone << '|'<< setw(sz) << right << m_accountBalance <<"|\n";
  }

  static Client* searchClient(string pinCode)
  {
    Client *client=nullptr;
    for(Client &qclient : m_clients)
    {
      if(qclient.getPinCode() == pinCode)
      {
        /*
       client->pinCode = pinCode;
       client->accountBalance = qclient.accountBalance;
       client->accountNumber = qclient.accountNumber;
       client->name = qclient.name;
       client->phone = qclient.phone;
       */
        client = &qclient;
        break;
      }
    }
    return client;
  }

  void updateClient(string pinCode)
  {
    Client* client = Client::searchClient(pinCode);
    if(client == nullptr)
    {
      cout << "Cannot find the client!" << endl;
      return;
    }
    client->read(1);
  }

  static void deleteClient(string pinCode)
  {
    vector<Client>::iterator i = m_clients.begin();
    for(;i<=m_clients.end();i++)
    {
      if (i->getPinCode() == pinCode)
      {
        m_clients.erase(i);
        break;
      }
    }
    // for(int i = 0;i<clients.size();i++)
    // {
    //     if (clients[i].pinCode == pinCode)
    //     {
    //         clients.erase(i,1);
    //          break;
    //     }
    // }
    Client::saveClintsInFile();
    cout << "client deleted successfuly!" << endl;
  }
  static void saveClintsInFile()
  {
    ofstream file;
    file.open(path, ios::out);
    string s;
    for(Client &client : m_clients)
    {
      client.saveClientElementsInString(s, " #//# ");
      file << s;
      file << '\n';
    }
    file.close();
  }
  static void printClients()
  {
    /*
   string accountNumber;
   string pinCode;
   string name;
   string phone;
   double accountBalance;
   */
    cout << "\n\t\t\t\t\tclient(s) ("<<m_clients.size()<<")\t\t\t\t\t\n";
    int sz = 21;
    cout << "\n----------------------------------------------------------------------------------------------------------\n";
    cout << '|';
    cout << setw(sz ) << right << "Account Number|"<< setw(sz) << right << "Pin Code|"<< setw(sz) << right << "Name|"<< setw(sz) << right << "Phone|"<< setw(sz-1) << right << "Account Balance" << right;
    cout << '|';
    cout << "\n----------------------------------------------------------------------------------------------------------\n";

    for (Client &client : m_clients)
    {
      client.print();
    }
    cout << "----------------------------------------------------------------------------------------------------------\n";

  }
  void readClients()
  {
    char c = 'Y';
    Client client;
    while (c == 'Y' || c == 'y')
    {
      client.read(0);
      cout << "Do you want to add another client? (Y/N): ";
      cin >> c;
    }
  }
  static void deposite(string pinCode)
  {
    Client *client = Client::searchClient(pinCode);
    double amount=0;
    cout << "enter the Balance : ";
    cin >> amount;
    client->m_accountBalance += amount;
    Client::saveClintsInFile();
  }
  static void withDraw(string pinCode)
  {
    Client *client = Client::searchClient(pinCode);
    double amount=0;
    cout << "enter the Balance : ";
    cin >> amount;
    while(amount > client->getAccountBalance())
    {
      cout << "cannot withDraw this amount you have as a top range : " << client->getAccountBalance() << endl;
      cin >> amount;
    }
    client->m_accountBalance -= amount;
    Client::saveClintsInFile();
  }
};
void mainMenu()
{
  ifstream file("mainMenu.txt");
  string line;
  while(getline(file, line))
  {
    cout<<line<<'\n';
  }
  file.close();
}
void transactionsMenu()
{
  ifstream file("transactionsMenu.txt");
  string line;
  while(getline(file, line))
  {
    cout<<line<<'\n';
  }
  file.close();
}

void spilitLine(string &s, vector<string> &words, string seperator)
{
  int len = seperator.length();
  if (s.empty())
    return;
  for (int i = 0; i < s.length();)
  {
    string word = "";
    while (s.substr(i, len) != seperator && i < s.length())
    {
      word += s[i];
      i++;
    }
    i += len;
    words.push_back(word);
  }
}
void trimRight(string &s)
{
  int i = s.length()-1;
  while(s[i]==' '&&!s.empty())
  {
    i--;
  }
  s = s.substr(0, i+1);
}
void trimLeft(string &s)
{
  int i = 0;
  while (s[i] == ' ' && !s.empty())
  {
    i++;
  }
  s = s.substr(i, s.length()-i);
}
void trim(string &s)
{
  trimLeft(s);
  trimRight(s);
}

