#include "../../../Headers/Crabmesh/Performer/IdManager.h"

using namespace Performer;

Performer::IdManager::IdManager(ULInt id, UInt size) {
  this->size = size;

  this->ids = new ULInt[size];

  for (UInt i = 0; i < size; i++) {
    this->setId(i, id);
  }
}

Performer::IdManager::~IdManager() { delete[] this->ids; }

void Performer::IdManager::setId(UInt i, ULInt id) { this->ids[i] = id; }

void Performer::IdManager::setId(ULInt id) { this->setId(0, id); }

ULInt Performer::IdManager::getId(UInt i) const { return this->ids[i]; }

ULInt Performer::IdManager::getId() const { return this->getId(0); }

ULInt Performer::IdManager::current(UInt i) const { return this->getId(i); }

ULInt Performer::IdManager::current() const { return this->getId(); }
