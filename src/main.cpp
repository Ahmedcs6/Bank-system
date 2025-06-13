#include "include.h"
vector<Client> Client::m_clients;
bool Client::m_updated = false;
int main()
{
  /*
  Client::sync();
  Client::printClients();
  */
  int choice = -1;
  string pinCode;
  Client::sync();
  Client client;
  zeroPoint :
  while(choice != 7)
  {
    system("clear");
    mainMenu();
    cout<<"enter your choice: ";
    cin >> choice;
    while (cin.fail())
    {
      cin.clear();
      cin.ignore(20000, '\n');
      cout << "Invalid number please try again : ";
      cin >> choice;
    }
    Client client = Client();
    Client* pclient;
    switch (choice)
    {
      case 1:
        system("clear");
        client.printClients();
        system("read -n 1 -s -r -p \"\nPress any key to continue . . .\";clear");
        break;
      case 2:
        system("clear");
        client.readClients();
        system("read -n 1 -s -r -p \"\nPress any key to continue . . .\";clear");
        break;
      case 3:
        system("clear");
        cout << "enter pinCode : ";
        cin>>pinCode;
        client.deleteClient(pinCode);
        system("read -n 1 -s -r -p \"\nPress any key to continue . . .\";clear");
        break;
      case 4:
        system("clear");
        cout << "enter pinCode : ";
        cin>>pinCode;
        client.updateClient(pinCode);
        system("read -n 1 -s -r -p \"\nPress any key to continue . . .\";clear");
        break;
      case 5:
        system("clear");
        cout << "enter pinCode : ";
        cin>>pinCode;
        pclient = client.searchClient(pinCode);
        if(pclient != nullptr)
        {
          pclient->print();
        }
        system("read -n 1 -s -r -p \"\nPress any key to continue . . .\";clear");
        break;
      case 6:
        while(choice != 4)
        {
          system("clear");
          transactionsMenu();
          cout<<"enter your choice: ";
          cin >> choice;
          while (cin.fail())
          {
            cin.clear();
            cin.ignore(20000, '\n');
            cout << "Invalid number please try again : ";
            cin >> choice;
          }
          switch(choice)
          {
            case 1:
              system("clear");
              cout << "enter the pinCode : " << endl;
              cin >> pinCode;
              Client::deposite(pinCode);
              system("read -n 1 -s -r -p \"\nPress any key to continue . . .\";clear");
              break;
            case 2:
              system("clear");
              cout << "enter the pinCode : " << endl;
              cin >> pinCode;
              Client::withDraw(pinCode);
              system("read -n 1 -s -r -p \"\nPress any key to continue . . .\";clear");
              break;
            case 3:
              cout << "Total Balance : " << Client::getTotalBalance() << endl ;
              system("read -n 1 -s -r -p \"\nPress any key to continue . . .\";clear");
              break;
            case 4:
              goto zeroPoint;
              break;
          }
        }
        break;
      case 7:
        system("clear");
        cout<<"goodby.....\n";
        return 0;
        break;
    }
  }
  //   /* vector<oop::sclient> clients; */
  /* const string path = "db.txt"; */
  /* string pinCode; */
  /* cout << "enter pincode : \n"; */
  /* cin >> pinCode; */
  /* func::updateClient(pinCode, path); */
  /* func::importClients(clients, path); */
  /* func::printClients(clients); */
  /* /1* func::readClients(clients); *1/ */
  /* func::saveClients(clients, path); */
  /* func::importClients(clients, path); */
  /* string p; */
  /* cout << "insert pincode : "; */
  /* cin >> p; */
  /* oop::sclient* client = func::searchClient(p, clients); */
  /* if(client == nullptr)cout << "not found\n"; */
  /* else */
  /* { */
  /*     string c; */
  /*     func::printClient(*client); */
  /*     cout << "Are you sure you want to delete this client(y/n)?\n"; */
  /*     cin >> c; */
  /*     if(c=="y") */
  /*     { */
  /*         func::deleteClient(p, path); */
  /*     } */
  /*     func::importClients(clients, path); */
  /*     func::printClients(clients); */
  /* } */
  /* // string s = "200.000000 #//# 1 #//# Ahmed Mahmoud #//# 01225937120 #//# A1"; */
  // vector<string> words;
  // func::spilitLine(s,words," #//# ");
  // for(string &s : words)cout << s << endl;
  /*
       split line
       save client atts
    */
  /*
  vector<oop::sclient> clients;
  ifstream file("db.txt");
  if (!file)
  {
    cerr << "error in file opening" << endl;
    return 0;
  }
  string line = "";
  while (std::getline(file, line))
  {
    oop::sclient client;
    vector<string> elements;
    string separator = "#//#";
    func::spilitLine(line, elements, separator);
    func::saveClientAtts(client, elements);
    clients.push_back(client);
  }
  file.close();
  func::printClients(clients);
  */
  /*
  vector<string> words;
  string s ="Ahmed--Mahmoud_Mostsfa";
  func::spilitLine(s,words,"--");
  for(string &ss : words)cout<<ss<<'\n';
  */
  /*
  vector<oop::sclient> clients;
  vector<string> elements;
  string s;
  func::readClients(clients);
  ofstream file("db.txt", ios::app | ios::out);
  for (oop::sclient &client : clients)
  {
    func::saveClientElementsInVector(elements, client);
    func::separateElements(s, elements, "#//#");
    func::printClient(client);
    if (!file)
    {
      cerr << "\nError opening file: " << strerror(errno) << "\n";
    }

    file << s << '\n';
    cout << "\nSaved!\n";
  }
  */
  /*
  string s = "Ahmed is a java dev";
  func::replaces(s,"java","python");
  cout<<s;
  */
  /*
  srand(time(NULL));
  string s="  c     ";
  cout<<'-'<<s<<'-';
  cout<<'\n';
  func::trimLeft(s);
  cout<<'-'<<s<<'-';
  */
  /*
  func::printLower("Ahmed Mahmoud Mostafa");
  */
  /*
  string x = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
  func::printFirstLetter(x);
  */
  /*
  func::printRecursiveFibonacci(20,0,1);
  */
  /*
  int arr1[10][10];
  int arr2[10][10];

  int *ptr1=&arr1[0][0];
  int *ptr2=&arr2[0][0];

  func::fillRangedRandomMatrix(ptr1,10,10,0,100);
  func::fillRangedRandomMatrix(ptr2,10,10,0,100);

  func::print2dArray(ptr1,10,10,100);
  cout<<'\n';
  func::print2dArray(ptr2,10,10,100);

  cout<<'\n';
    func::printInterSectedNymbersInToMatrices(ptr1,10,10,ptr2,10,10);
  */
  /*
  int arr[4][4];
  int *ptr=&arr[0][0];
  func::makeMatrixIdentity(ptr, 4, 4);
  func::print2dArray(ptr,4,4,1);
  cout<<func::isIdentityMatrix(ptr,4,4);
  */
  /*
  int arr[3][3];
  int arr2[3][3];
  int *ptr2 = &arr2[0][0];
  func::fillOrderedMatrix(ptr2, 3, 3);
  int *ptr = &arr[0][0];
  func::fillRangedRandomMatrix(ptr, 3, 3, 0, 100);
  func::print2dArray(ptr, 3, 3, 100);
  func::printMidleRowsAndColumns(ptr, 3, 3);
  cout << "\nsum of matrix : \n";
  cout << func::sumOfMatrix(ptr, 3, 3);
  cout << "\nis matrix equal : \n";
  cout << func::isMatricesEqual(ptr, ptr2, 3, 3);
  */
  /*
  int matrix1[6][6];
  int *ptr1 = &matrix1[0][0];
  func::fillOrderedMatrix(ptr1, 6, 6);
  cout << "the oredered matrix : \n";
  func::print2dArray(ptr1, 6, 6, 100);
  cout << '\n';
  func::printSummtionOfRowsIn2dArray(ptr1, 6, 6);
  cout << '\n';
  func::printSummtionOfColumnsIn2dArray(ptr1, 6, 6);
  cout << '\n';
  cout << "Matrix after revers : \n";
  func::reversMatrix(ptr1, 6);
  cout << '\n';
  func::print2dArray(ptr1, 6, 6, 100);
  cout << '\n';
  func::printSummtionOfRowsIn2dArray(ptr1, 6, 6);
  cout << '\n';
  func::printSummtionOfColumnsIn2dArray(ptr1, 6, 6);
  cout << "\n====================\n";
  int matrix2[6][6];
  int *ptr2 = &matrix2[0][0];
  func::fillRangedRandomMatrix(ptr2, 6, 6, 0, 100);
  cout << "the random matrix : \n";
  func::print2dArray(ptr2, 6, 6, 100);
  cout << '\n';
  func::printSummtionOfRowsIn2dArray(ptr2, 6, 6);
  cout << '\n';
  func::printSummtionOfColumnsIn2dArray(ptr2, 6, 6);
  cout << '\n';
  cout << "Matrix after revers : \n";
  func::reversMatrix(ptr2, 6);
  cout << '\n';
  func::print2dArray(ptr2, 6, 6, 100);
  cout << '\n';
  func::printSummtionOfRowsIn2dArray(ptr2, 6, 6);
  cout << '\n';
  func::printSummtionOfColumnsIn2dArray(ptr2, 6, 6);
  cout << "\n====================\n";
  int matrix3[6][6];
  int *ptr3 = &matrix3[0][0];
  func::fillMatrixWithMultiplyOfTowMatrises(ptr3, ptr2, ptr1, 6, 6);
  cout << "the multi matrix : \n";
  func::print2dArray(ptr3, 6, 6, 10000);
  cout << '\n';
  func::printSummtionOfRowsIn2dArray(ptr3, 6, 6);
  cout << '\n';
  func::printSummtionOfColumnsIn2dArray(ptr3, 6, 6);
  cout << '\n';
  cout << "Matrix after revers : \n";
  func::reversMatrix(ptr3, 6);
  cout << '\n';
  func::print2dArray(ptr3, 6, 6, 10000);
  cout << '\n';
  func::printSummtionOfRowsIn2dArray(ptr3, 6, 6);
  cout << '\n';
  func::printSummtionOfColumnsIn2dArray(ptr3, 6, 6);
  */
  /*
  1  2  3
  4  5  6
  7  8  9

  1  4  7
  2  5  8
  3  6  9
  */
  /*
  oop::Student Ahmed("Ahmed", 99);
  oop::Student Mohamed("Mohamed", 77);
  oop::Student Mahmod("Mahmod", 88);
  oop::Student *arr = new oop::Student[3]{Ahmed, Mahmod, Mohamed};
  oop::Student *s = &arr[0];
  cout << s->getAverage();
  delete[] arr;
  */
  //===============
  /*
  oop::Student arr[3] = {Ahmed, Mohamed, Mahmod};
  int len = sizeof(arr) / sizeof(arr[0]);
  float total = 0.0f, counter = 0.0f;
  for (oop::Student *i = arr; i != &arr[len]; i++)
  {
    total += i->getAverage();
    counter++;
  }
  cout << total / counter;
  */
  //	== == == == == == == ==
  /*
    vector<oop::Student> arr = {Ahmed, Mohamed, Mahmod};
  vector<oop::Student>::iterator iter;
  int total = 0, counter = 0;
  for (iter = arr.begin(); iter != arr.end(); iter++)
  {
    counter++;
    total += iter->getAverage();
  }
  cout << total / double(counter);
  */
}
