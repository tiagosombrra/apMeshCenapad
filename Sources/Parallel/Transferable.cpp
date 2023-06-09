#include "../../Headers/Parallel/Transferable.h"

using namespace Parallel;

Parallel::Transferable::Transferable(UInt type) { this->setType(type); }

Parallel::Transferable::~Transferable() {}

void Parallel::Transferable::setType(UInt type) { this->type = type; }

UInt Parallel::Transferable::getType() { return this->type; }

void Parallel::Transferable::free(Package &p) { delete[] p.second; }
