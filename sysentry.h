#ifndef SYSENTRY_H
#define SYSENTRY_H

#include <string>

class Sysentry {
private:
  char *name;
  int mCount;

public:
  Sysentry();
  ~Sysentry();
  void setPerson(const char *who);
  void incr();
  const char *getPerson();
  int getCount();

  // Copy Constructor
  Sysentry(const Sysentry &otherSysentry);

  // Overloaded assignment
  Sysentry &operator=(const Sysentry &otherSysentry);
};

#endif // !SYSENTRY_H
