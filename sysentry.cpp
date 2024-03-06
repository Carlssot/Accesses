#include "sysentry.h"

Sysentry::Sysentry() {
  this->name = nullptr;
  this->mCount = 0;
}

void Sysentry::setPerson(const char *who) {
  this->name = new char[strlen(who) + 1];

  strcpy(this->name, who);
}

void Sysentry::incr() { this->mCount += 1; }

const char *Sysentry::getPerson() { return this->name; }

int Sysentry::getCount() { return this->mCount; }

Sysentry::Sysentry(const Sysentry &otherSysentry) {
  this->name = new char[strlen(otherSysentry.name) + 1];

  strcpy(this->name, otherSysentry.name);

  this->mCount = otherSysentry.mCount;
}

Sysentry &Sysentry::operator=(const Sysentry &otherSysentry) {
  if (this->name) {
    delete[] this->name;
  } else {
    strcpy(this->name, otherSysentry.name);
    this->mCount = otherSysentry.mCount;
  }

  return *this;
}

Sysentry::~Sysentry() { delete[] this->name; }
