#include <iostream>

using namespace std;

// 结构体示例
struct address {
  char* name;
  long int number; // 8 bytes
  char* street;
  char* town;
  //char state[2]; // 2 bytes
  long zip;
  char state[2]; // 2 bytes
}; //很多机器上，sizeof(address)是42

void printAD(address);

int main(){
  cout << "struct size is: " << sizeof(struct address) << endl;

  // address jd1 = { "Jim Dandy", 61, "South St", "New Providence", 
    // {'N', 'J'}, 7974};
  address jd1 = { "Jim Dandy", 61, "South St", "New Providence", 7974, {'N', 'J'}};
  printAD(jd1);

  address* jd2;
  // jd2 = &jd1;
  jd2 = new struct address();

  jd2->name = "Michael Jackson";
  jd2->number = 2007;
  jd2->street = "US city";
  jd2->town = "Seattle";
  jd2->state[0] = 'M';
  jd2->state[1] = 'J';
  jd2->zip = 100876;

  printAD(*jd2);

  delete jd2;
  return 0;
}

void printAD(address jd)
{
  cout << "name:\t" << jd.name << endl;
  cout << "number:\t" << jd.number << endl;
  cout << "street:\t" << jd.street << endl;
  cout << "town:\t" << jd.town << endl;
  cout << "state:\t" << jd.state[0] << "." << jd.state[1] << endl;
  cout << "zip:\t" << jd.zip << endl;
}
