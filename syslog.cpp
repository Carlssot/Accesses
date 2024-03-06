#include "syslog.h"
#include "sysentry.h"
#include <iostream>
using namespace std;
#include <cstring>

void Syslog::addEntry(const char *sys, const char *who)
{
  if (strcmp(sys, this->mSysName) == 0)
  {
    int index = 0;

    if (this->mEntries[0].getPerson() == nullptr)
    {
      this->mEntries[0].setPerson(who);
    }

    index = findPerson(who);

    if (index != -1)
    {
      this->mEntries[index].incr();
    }
    else
    {

      index = findEmptyspot();

      this->mEntries[index].setPerson(who);
      this->mEntries[index].incr();
    }
  }
}

void Syslog::printAll()
{

  cout << "System: " << this->mSysName << endl;
  cout << "  Top: " << getTop() << endl;
  cout << "  Sencond: " << getSecond() << endl;
  cout << "  All:" << endl;

  for (int i = 0; i < findEmptyspot(); ++i)
  {
    cout << "    " << this->mEntries[i].getPerson() << " "
         << this->mEntries[i].getCount() << " ("  
         << static_cast<int>(getPercent(this->mEntries[i].getCount())) << "%)" << endl;
  }
}

// Default Constructor
Syslog::Syslog(const char *sysname, const int numStaff)
{
  this->mSysName = new char[strlen(sysname) + 1];

  strcpy(this->mSysName, sysname);

  this->mEntries = new Sysentry[numStaff];

  this->mStaffNum = numStaff;
  this->totalEntries = 0;
}

const char *Syslog::getTop()
{
  int max = 0;

  for (int i = 1; i < findEmptyspot(); ++i)
  {
    if (this->mEntries[i].getCount() > this->mEntries[max].getCount())
    {
      max = i;
    }
  }

  return this->mEntries[max].getPerson();
}

const char *Syslog::getSecond()
{

  int largest = 0;
  int secondlargest = -1;

  // int position = (largest > secondlargest) ? 0 : 1;

  for (int i = 1; i < findEmptyspot(); i++)
  {
    if (this->mEntries[i].getCount() > this->mEntries[largest].getCount())
    {
      secondlargest = largest;
      largest = i;
    }
    else if (this->mEntries[i].getCount() < this->mEntries[largest].getCount())
    {
      if (secondlargest == -1 || this->mEntries[secondlargest].getCount() < this->mEntries[i].getCount())
      {
        secondlargest = i;
      }
    }
  }

  return this->mEntries[secondlargest].getPerson();
}

int Syslog::findEmptyspot() const
{
  int i = 0;

  while (i < this->mStaffNum && this->mEntries[i].getPerson() != nullptr)
  {
    ++i;
  }

  return i;
}

int Syslog::findPerson(const char *name)
{
  for (int i = 0; i < findEmptyspot(); i++)
  {
    if (strcmp(name, this->mEntries[i].getPerson()) == 0)
    {
      return i;
    }
  }

  return -1;
}

double Syslog::getPercent(int number) const
{
  int listTotal = 0;

  for (int i = 0; i < findEmptyspot(); i++)
  {
    listTotal += this->mEntries[i].getCount();
  }
  double percent = (number / static_cast<double>(listTotal)) * 100;

  return percent;
}

Syslog::~Syslog()
{
  delete[] this->mSysName;
  delete[] this->mEntries;
}

/*Copy Constructor test
void Syslog::copySysentry() {
  //Sysentry Copy(this->mEntries[0]);

  cout << mEntries[0].getPerson() << "  " <<  mEntries[0].getCount() << endl;
  cout << Copy.getPerson() << "  " <<  Copy.getCount() << endl;
}*/

/*Overloaded assignment operator test
void Syslog::assignmentoperator() {
  Sysentry newObj = mEntries[1];

  cout << mEntries[1].getPerson() << "  " <<  mEntries[1].getCount() << endl;
  cout << newObj.getPerson() << "  " <<  newObj.getCount() << endl;

}*/
