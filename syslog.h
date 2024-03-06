#ifndef SYSLOG_H
#define SYSLOG_H

#include "sysentry.h"

class Syslog {
private:
  char *mSysName;
  int mStaffNum;
  Sysentry *mEntries;
  int totalEntries;

public:
  Syslog(const char *sysname, const int numStaff);
  ~Syslog();
  void addEntry(const char *sys, const char *who);
  void printAll();
  const char *getSecond();
  const char *getTop();

  int findPerson(const char *);
  int findEmptyspot() const;
  double getPercent(int number) const;

  //Copy constructor test
  // void copySysentry();

  //assignment operator test
  // void assignmentoperator();
};

#endif
