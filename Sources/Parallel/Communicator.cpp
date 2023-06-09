#include "../../Headers/Parallel/Communicator.h"

#include "../../Headers/Parallel/Transferable.h"

using namespace Parallel;

Parallel::Communicator::~Communicator() {}

void Parallel::Communicator::pack(char val, void *buffer, Int bufferSize,
                                  Int &position) const {
  this->pack(&val, 1, buffer, bufferSize, position, CHAR);
}

void Parallel::Communicator::pack(unsigned char val, void *buffer,
                                  Int bufferSize, Int &position) const {
  this->pack(&val, 1, buffer, bufferSize, position, UCHAR);
}

void Parallel::Communicator::pack(bool val, void *buffer, Int bufferSize,
                                  Int &position) const {
  this->pack(&val, 1, buffer, bufferSize, position, BOOL);
}

void Parallel::Communicator::pack(short val, void *buffer, Int bufferSize,
                                  Int &position) const {
  this->pack(&val, 1, buffer, bufferSize, position, SHORT);
}

void Parallel::Communicator::pack(unsigned short val, void *buffer,
                                  Int bufferSize, Int &position) const {
  this->pack(&val, 1, buffer, bufferSize, position, USHORT);
}

void Parallel::Communicator::pack(Int val, void *buffer, Int bufferSize,
                                  Int &position) const {
  this->pack(&val, 1, buffer, bufferSize, position, INT);
}

void Parallel::Communicator::pack(UInt val, void *buffer, Int bufferSize,
                                  Int &position) const {
  this->pack(&val, 1, buffer, bufferSize, position, UINT);
}

void Parallel::Communicator::pack(LInt val, void *buffer, Int bufferSize,
                                  Int &position) const {
  this->pack(&val, 1, buffer, bufferSize, position, LINT);
}

void Parallel::Communicator::pack(ULInt val, void *buffer, Int bufferSize,
                                  Int &position) const {
  this->pack(&val, 1, buffer, bufferSize, position, ULINT);
}

void Parallel::Communicator::pack(Real val, void *buffer, Int bufferSize,
                                  Int &position) const {
  this->pack(&val, 1, buffer, bufferSize, position, REAL);
}

void Parallel::Communicator::pack(LReal val, void *buffer, Int bufferSize,
                                  Int &position) const {
  this->pack(&val, 1, buffer, bufferSize, position, LREAL);
}

void Parallel::Communicator::pack(const char *val, Int size, void *buffer,
                                  Int bufferSize, Int &position) const {
  this->pack(val, size, buffer, bufferSize, position, CHAR);
}

void Parallel::Communicator::pack(const unsigned char *val, Int size,
                                  void *buffer, Int bufferSize,
                                  Int &position) const {
  this->pack(val, size, buffer, bufferSize, position, UCHAR);
}

void Parallel::Communicator::pack(const bool *val, Int size, void *buffer,
                                  Int bufferSize, Int &position) const {
  this->pack(val, size, buffer, bufferSize, position, BOOL);
}

void Parallel::Communicator::pack(const short *val, Int size, void *buffer,
                                  Int bufferSize, Int &position) const {
  this->pack(val, size, buffer, bufferSize, position, SHORT);
}

void Parallel::Communicator::pack(const unsigned short *val, Int size,
                                  void *buffer, Int bufferSize,
                                  Int &position) const {
  this->pack(val, size, buffer, bufferSize, position, USHORT);
}

void Parallel::Communicator::pack(const Int *val, Int size, void *buffer,
                                  Int bufferSize, Int &position) const {
  this->pack(val, size, buffer, bufferSize, position, INT);
}

void Parallel::Communicator::pack(const UInt *val, Int size, void *buffer,
                                  Int bufferSize, Int &position) const {
  this->pack(val, size, buffer, bufferSize, position, UINT);
}

void Parallel::Communicator::pack(const LInt *val, Int size, void *buffer,
                                  Int bufferSize, Int &position) const {
  this->pack(val, size, buffer, bufferSize, position, LINT);
}

void Parallel::Communicator::pack(const ULInt *val, Int size, void *buffer,
                                  Int bufferSize, Int &position) const {
  this->pack(val, size, buffer, bufferSize, position, ULINT);
}

void Parallel::Communicator::pack(const Real *val, Int size, void *buffer,
                                  Int bufferSize, Int &position) const {
  this->pack(val, size, buffer, bufferSize, position, REAL);
}

void Parallel::Communicator::pack(const LReal *val, Int size, void *buffer,
                                  Int bufferSize, Int &position) const {
  this->pack(val, size, buffer, bufferSize, position, LREAL);
}

void Parallel::Communicator::unpack(char &val, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(&val, 1, buffer, bufferSize, position, CHAR);
}

void Parallel::Communicator::unpack(unsigned char &val, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(&val, 1, buffer, bufferSize, position, UCHAR);
}

void Parallel::Communicator::unpack(bool &val, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(&val, 1, buffer, bufferSize, position, BOOL);
}

void Parallel::Communicator::unpack(short &val, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(&val, 1, buffer, bufferSize, position, SHORT);
}

void Parallel::Communicator::unpack(unsigned short &val, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(&val, 1, buffer, bufferSize, position, USHORT);
}

void Parallel::Communicator::unpack(Int &val, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(&val, 1, buffer, bufferSize, position, INT);
}

void Parallel::Communicator::unpack(UInt &val, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(&val, 1, buffer, bufferSize, position, UINT);
}

void Parallel::Communicator::unpack(LInt &val, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(&val, 1, buffer, bufferSize, position, LINT);
}

void Parallel::Communicator::unpack(ULInt &val, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(&val, 1, buffer, bufferSize, position, ULINT);
}

void Parallel::Communicator::unpack(Real &val, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(&val, 1, buffer, bufferSize, position, REAL);
}

void Parallel::Communicator::unpack(LReal &val, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(&val, 1, buffer, bufferSize, position, LREAL);
}

void Parallel::Communicator::unpack(char *val, Int size, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(val, size, buffer, bufferSize, position, CHAR);
}

void Parallel::Communicator::unpack(unsigned char *val, Int size,
                                    const void *buffer, Int bufferSize,
                                    Int &position) const {
  this->unpack(val, size, buffer, bufferSize, position, UCHAR);
}

void Parallel::Communicator::unpack(bool *val, Int size, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(val, size, buffer, bufferSize, position, BOOL);
}

void Parallel::Communicator::unpack(short *val, Int size, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(val, size, buffer, bufferSize, position, SHORT);
}

void Parallel::Communicator::unpack(unsigned short *val, Int size,
                                    const void *buffer, Int bufferSize,
                                    Int &position) const {
  this->unpack(val, size, buffer, bufferSize, position, USHORT);
}

void Parallel::Communicator::unpack(Int *val, Int size, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(val, size, buffer, bufferSize, position, INT);
}

void Parallel::Communicator::unpack(UInt *val, Int size, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(val, size, buffer, bufferSize, position, UINT);
}

void Parallel::Communicator::unpack(LInt *val, Int size, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(val, size, buffer, bufferSize, position, LINT);
}

void Parallel::Communicator::unpack(ULInt *val, Int size, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(val, size, buffer, bufferSize, position, ULINT);
}

void Parallel::Communicator::unpack(Real *val, Int size, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(val, size, buffer, bufferSize, position, REAL);
}

void Parallel::Communicator::unpack(LReal *val, Int size, const void *buffer,
                                    Int bufferSize, Int &position) const {
  this->unpack(val, size, buffer, bufferSize, position, LREAL);
}

void Parallel::Communicator::broadcast(char &val, Int root) const {
  this->broadcast(&val, 1, CHAR, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(unsigned char &val, Int root) const {
  this->broadcast(&val, 1, UCHAR, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(bool &val, Int root) const {
  this->broadcast(&val, 1, BOOL, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(short &val, Int root) const {
  this->broadcast(&val, 1, SHORT, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(unsigned short &val, Int root) const {
  this->broadcast(&val, 1, USHORT, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(Int &val, Int root) const {
  this->broadcast(&val, 1, INT, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(UInt &val, Int root) const {
  this->broadcast(&val, 1, UINT, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(LInt &val, Int root) const {
  this->broadcast(&val, 1, LINT, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(ULInt &val, Int root) const {
  this->broadcast(&val, 1, ULINT, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(Real &val, Int root) const {
  this->broadcast(&val, 1, REAL, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(LReal &val, Int root) const {
  this->broadcast(&val, 1, LREAL, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(char *val, Int size, Int root) const {
  this->broadcast(val, size, CHAR, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(unsigned char *val, Int size,
                                       Int root) const {
  this->broadcast(val, size, UCHAR, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(bool *val, Int size, Int root) const {
  this->broadcast(val, size, BOOL, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(short *val, Int size, Int root) const {
  this->broadcast(val, size, SHORT, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(unsigned short *val, Int size,
                                       Int root) const {
  this->broadcast(val, size, USHORT, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(Int *val, Int size, Int root) const {
  this->broadcast(val, size, INT, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(UInt *val, Int size, Int root) const {
  this->broadcast(val, size, UINT, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(LInt *val, Int size, Int root) const {
  this->broadcast(val, size, LINT, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(ULInt *val, Int size, Int root) const {
  this->broadcast(val, size, ULINT, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(Real *val, Int size, Int root) const {
  this->broadcast(val, size, REAL, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(LReal *val, Int size, Int root) const {
  this->broadcast(val, size, LREAL, (root < 0) ? this->rank() : root);
}

void Parallel::Communicator::broadcast(const Transferable *t) const {
  Package p = t->pack(this);

  Int rank = this->rank();

  this->broadcast(&p.first, 1, INT, rank);
  this->broadcast(p.second, p.first, PACKED, rank);

  Transferable::free(p);
}

Transferable *Parallel::Communicator::broadcast(Int root) const {
  Package p = std::make_pair(0, static_cast<char *>(NULL));

  this->broadcast(&p.first, 1, INT, root);

  p.second = new char[p.first];

  this->broadcast(p.second, p.first, PACKED, root);

  return this->unpack(p, true);
}

void Parallel::Communicator::broadcastv(Transferable **const t,
                                        Int size) const {
  Package p = std::make_pair(0, static_cast<char *>(NULL));
  Int sizes[size];

  // how many transferables and their sizes
  p.first += this->packSize(size + 1, INT);

  for (Int i = 0; i < size; i++) {
    sizes[i] = t[i]->packSize(this);
    p.first += sizes[i];
  }

  p.second = new char[p.first];

  Int position = 0;

  this->pack(size, p.second, p.first, position);

  for (Int i = 0; i < size; i++) {
    this->pack(sizes[i], p.second, p.first, position);
  }

  for (Int i = 0; i < size; i++) {
    t[i]->pack(this, p.second, p.first, position);
  }

  Int rank = this->rank();

  this->broadcast(&p.first, 1, INT, rank);
  this->broadcast(p.second, p.first, PACKED, rank);

  Transferable::free(p);
}

Transferable **Parallel::Communicator::broadcastv(Int &size, Int root) const {
  Package p = std::make_pair(0, static_cast<char *>(NULL));

  this->broadcast(&p.first, 1, INT, root);

  p.second = new char[p.first];

  this->broadcast(p.second, p.first, PACKED, root);

  Int position = 0;

  this->unpack(size, p.second, p.first, position);

  Int sizes[size];

  for (Int i = 0; i < size; i++) {
    this->unpack(sizes[i], p.second, p.first, position);
  }

  Transferable **t = new Transferable *[size];

  for (Int i = 0; i < size; i++) {
    Package p2;

    p2.first = sizes[i];
    p2.second = &p.second[position];

    this->unpack(p2, false);

    position += sizes[i];
  }

  return t;
}

void Parallel::Communicator::scatter(const char *val) const {
  char buf = ' ';

  this->scatter(val, 1, &buf, 1, CHAR, this->rank());
}

void Parallel::Communicator::scatter(char &val, Int root) const {
  char *buf = NULL;

  this->scatter(buf, 1, &val, 1, CHAR, root);
}

void Parallel::Communicator::scatter(const unsigned char *val) const {
  unsigned char buf = ' ';

  this->scatter(val, 1, &buf, 1, UCHAR, this->rank());
}

void Parallel::Communicator::scatter(unsigned char &val, Int root) const {
  unsigned char *buf = NULL;

  this->scatter(buf, 1, &val, 1, UCHAR, root);
}

void Parallel::Communicator::scatter(const bool *val) const {
  bool buf = false;

  this->scatter(val, 1, &buf, 1, BOOL, this->rank());
}

void Parallel::Communicator::scatter(bool &val, Int root) const {
  bool *buf = NULL;

  this->scatter(buf, 1, &val, 1, BOOL, root);
}

void Parallel::Communicator::scatter(const short *val) const {
  short buf = 0;

  this->scatter(val, 1, &buf, 1, SHORT, this->rank());
}

void Parallel::Communicator::scatter(short &val, Int root) const {
  short *buf = NULL;

  this->scatter(buf, 1, &val, 1, SHORT, root);
}

void Parallel::Communicator::scatter(const unsigned short *val) const {
  unsigned short buf = 0;

  this->scatter(val, 1, &buf, 1, USHORT, this->rank());
}

void Parallel::Communicator::scatter(unsigned short &val, Int root) const {
  unsigned short *buf = NULL;

  this->scatter(buf, 1, &val, 1, USHORT, root);
}

void Parallel::Communicator::scatter(const Int *val) const {
  Int buf = 0;

  this->scatter(val, 1, &buf, 1, INT, this->rank());
}

void Parallel::Communicator::scatter(Int &val, Int root) const {
  Int *buf = NULL;

  this->scatter(buf, 1, &val, 1, INT, root);
}

void Parallel::Communicator::scatter(const UInt *val) const {
  UInt buf = 0;

  this->scatter(val, 1, &buf, 1, UINT, this->rank());
}

void Parallel::Communicator::scatter(UInt &val, Int root) const {
  UInt *buf = NULL;

  this->scatter(buf, 1, &val, 1, UINT, root);
}

void Parallel::Communicator::scatter(const LInt *val) const {
  LInt buf = 0;

  this->scatter(val, 1, &buf, 1, LINT, this->rank());
}

void Parallel::Communicator::scatter(LInt &val, Int root) const {
  LInt *buf = NULL;

  this->scatter(buf, 1, &val, 1, LINT, root);
}

void Parallel::Communicator::scatter(const ULInt *val) const {
  ULInt buf = 0;

  this->scatter(val, 1, &buf, 1, ULINT, this->rank());
}

void Parallel::Communicator::scatter(ULInt &val, Int root) const {
  ULInt *buf = NULL;

  this->scatter(buf, 1, &val, 1, ULINT, root);
}

void Parallel::Communicator::scatter(const Real *val) const {
  Real buf = 0.0;

  this->scatter(val, 1, &buf, 1, REAL, this->rank());
}

void Parallel::Communicator::scatter(Real &val, Int root) const {
  Real *buf = NULL;

  this->scatter(buf, 1, &val, 1, REAL, root);
}

void Parallel::Communicator::scatter(const LReal *val) const {
  LReal buf = 0.0;

  this->scatter(val, 1, &buf, 1, LREAL, this->rank());
}

void Parallel::Communicator::scatter(LReal &val, Int root) const {
  LReal *buf = NULL;

  this->scatter(buf, 1, &val, 1, LREAL, root);
}

void Parallel::Communicator::scatter(const char *val, Int size) const {
  char *buf = new char[size];

  this->scatter(val, size, buf, size, CHAR, this->rank());

  delete[] buf;
}

void Parallel::Communicator::scatter(char *val, Int size, Int root) const {
  char *buf = NULL;

  this->scatter(buf, size, val, size, CHAR, root);
}

void Parallel::Communicator::scatter(const unsigned char *val, Int size) const {
  unsigned char *buf = new unsigned char[size];

  this->scatter(val, size, buf, size, UCHAR, this->rank());

  delete[] buf;
}

void Parallel::Communicator::scatter(unsigned char *val, Int size,
                                     Int root) const {
  unsigned char *buf = NULL;

  this->scatter(buf, size, val, size, UCHAR, root);
}

void Parallel::Communicator::scatter(const bool *val, Int size) const {
  bool *buf = new bool[size];

  this->scatter(val, size, buf, size, BOOL, this->rank());

  delete[] buf;
}

void Parallel::Communicator::scatter(bool *val, Int size, Int root) const {
  bool *buf = NULL;

  this->scatter(buf, size, val, size, BOOL, root);
}

void Parallel::Communicator::scatter(const short *val, Int size) const {
  short *buf = new short[size];

  this->scatter(val, size, buf, size, SHORT, this->rank());

  delete[] buf;
}

void Parallel::Communicator::scatter(short *val, Int size, Int root) const {
  short *buf = NULL;

  this->scatter(buf, size, val, size, SHORT, root);
}

void Parallel::Communicator::scatter(const unsigned short *val,
                                     Int size) const {
  unsigned short *buf = new unsigned short[size];

  this->scatter(val, size, buf, size, USHORT, this->rank());

  delete[] buf;
}

void Parallel::Communicator::scatter(unsigned short *val, Int size,
                                     Int root) const {
  unsigned short *buf = NULL;

  this->scatter(buf, size, val, size, USHORT, root);
}

void Parallel::Communicator::scatter(const Int *val, Int size) const {
  Int *buf = new Int[size];

  this->scatter(val, size, buf, size, INT, this->rank());

  delete[] buf;
}

void Parallel::Communicator::scatter(Int *val, Int size, Int root) const {
  Int *buf = NULL;

  this->scatter(buf, size, val, size, INT, root);
}

void Parallel::Communicator::scatter(const UInt *val, Int size) const {
  UInt *buf = new UInt[size];

  this->scatter(val, size, buf, size, UINT, this->rank());

  delete[] buf;
}

void Parallel::Communicator::scatter(UInt *val, Int size, Int root) const {
  UInt *buf = NULL;

  this->scatter(buf, size, val, size, UINT, root);
}

void Parallel::Communicator::scatter(const LInt *val, Int size) const {
  LInt *buf = new LInt[size];

  this->scatter(val, size, buf, size, LINT, this->rank());

  delete[] buf;
}

void Parallel::Communicator::scatter(LInt *val, Int size, Int root) const {
  LInt *buf = NULL;

  this->scatter(buf, size, val, size, LINT, root);
}

void Parallel::Communicator::scatter(const ULInt *val, Int size) const {
  ULInt *buf = new ULInt[size];

  this->scatter(val, size, buf, size, ULINT, this->rank());

  delete[] buf;
}

void Parallel::Communicator::scatter(ULInt *val, Int size, Int root) const {
  ULInt *buf = NULL;

  this->scatter(buf, size, val, size, ULINT, root);
}

void Parallel::Communicator::scatter(const Real *val, Int size) const {
  Real *buf = new Real[size];

  this->scatter(val, size, buf, size, REAL, this->rank());

  delete[] buf;
}

void Parallel::Communicator::scatter(Real *val, Int size, Int root) const {
  Real *buf = NULL;

  this->scatter(buf, size, val, size, REAL, root);
}

void Parallel::Communicator::scatter(const LReal *val, Int size) const {
  LReal *buf = new LReal[size];

  this->scatter(val, size, buf, size, LREAL, this->rank());

  delete[] buf;
}

void Parallel::Communicator::scatter(LReal *val, Int size, Int root) const {
  LReal *buf = NULL;

  this->scatter(buf, size, val, size, LREAL, root);
}

void Parallel::Communicator::scatter(Transferable **const t) const {
  Int numProcesses = this->numProcesses();

  Int sizes[numProcesses], displacements[numProcesses];

  Package p;

  p.first = 0;
  p.second = NULL;

  Int rank = this->rank();

  for (Int i = 0, j = 0; i < numProcesses; i++) {
    displacements[i] = p.first;

    if (i == rank) {
      sizes[i] = 0;
    } else {
      sizes[i] = t[j++]->packSize(this);
    }

    p.first += sizes[i];
  }

  Int iignore;

  this->scatter(sizes, 1, &iignore, 1, INT, rank);

  p.second = new char[p.first];

  Int position = 0;

  for (Int i = 0, j = 0; i < numProcesses; i++) {
    if (i == rank) {
      continue;
    }

    t[j++]->pack(this, p.second, p.first, position);
  }

  char ignore;

  this->scatterv(p.second, sizes, displacements, &ignore, sizes[rank], PACKED,
                 rank);

  Transferable::free(p);
}

Transferable *Parallel::Communicator::scatter(Int root) const {
  Package p = std::make_pair(0, static_cast<char *>(NULL));

  this->scatter(NULL, 0, &p.first, 1, INT, root);

  p.second = new char[p.first];

  this->scatterv(NULL, NULL, NULL, p.second, p.first, PACKED, root);

  return this->unpack(p, true);
}

void Parallel::Communicator::scatterv(Transferable **const t,
                                      Int sizes[]) const {
  Int numProcesses = this->numProcesses();

  Int tpsizes[numProcesses], displacements[numProcesses];

  Int numTransfs = 0;

  for (Int i = 0; i < numProcesses - 1; i++) {
    numTransfs += sizes[i];
  }

  Int psizes[numTransfs];

  Package p;

  p.first = 0;
  p.second = NULL;

  Int rank = this->rank();

  for (Int i = 0, j = 0, k = 0; i < numProcesses; i++) {
    displacements[i] = p.first;

    if (i == rank) {
      tpsizes[i] = 0;
    } else {
      tpsizes[i] = this->packSize(sizes[j] + 1, INT);

      for (Int l = 0; l < sizes[j]; l++) {
        psizes[k] = t[k]->packSize(this);
        tpsizes[i] += psizes[k++];
      }

      j++;
    }

    p.first += tpsizes[i];
  }

  Int iignore;

  this->scatter(tpsizes, 1, &iignore, 1, INT, rank);

  p.second = new char[p.first];

  Int position = 0;

  for (Int i = 0, j = 0, k = 0; i < numProcesses; i++) {
    if (i == rank) {
      continue;
    }

    this->pack(sizes[j], p.second, p.first, position);

    Int oldk = k;

    for (Int l = 0; l < sizes[j]; l++) {
      this->pack(psizes[k++], p.second, p.first, position);
    }

    for (Int l = 0; l < sizes[j]; l++) {
      t[oldk++]->pack(this, p.second, p.first, position);
    }
  }

  char ignore;

  this->scatterv(p.second, tpsizes, displacements, &ignore, tpsizes[rank],
                 PACKED, rank);

  Transferable::free(p);
}

Transferable **Parallel::Communicator::scatterv(Int &size, Int root) const {
  Package p;
  p.first = 0;
  p.second = NULL;

  this->scatter(NULL, 0, &p.first, 1, INT, root);

  p.second = new char[p.first];

  this->scatterv(NULL, NULL, NULL, p.second, p.first, PACKED, root);

  Int position = 0;

  this->unpack(size, p.second, p.first, position);

  Int sizes[size];

  for (Int i = 0; i < size; i++) {
    this->unpack(sizes[i], p.second, p.first, position);
  }

  Transferable **t = new Transferable *[size];

  for (Int i = 0; i < size; i++) {
    Package p2;
    p2.first = sizes[i];
    p2.second = &p.second[position];

    t[i] = this->unpack(p, false);

    position += sizes[i];
  }

  Transferable::free(p);

  return t;
}

void Parallel::Communicator::gather(char val, Int root) const {
  char *buf = NULL;

  this->gather(&val, 1, buf, 1, CHAR, root);
}

void Parallel::Communicator::gather(char val, char *buffer) const {
  this->gather(buffer, 1, &val, 1, CHAR, this->rank());
}

void Parallel::Communicator::gather(unsigned char val, Int root) const {
  unsigned char *buf = NULL;

  this->gather(&val, 1, buf, 1, UCHAR, root);
}

void Parallel::Communicator::gather(unsigned char val,
                                    unsigned char *buffer) const {
  this->gather(buffer, 1, &val, 1, UCHAR, this->rank());
}

void Parallel::Communicator::gather(bool val, Int root) const {
  bool *buf = NULL;

  this->gather(&val, 1, buf, 1, BOOL, root);
}

void Parallel::Communicator::gather(bool val, bool *buffer) const {
  this->gather(buffer, 1, &val, 1, BOOL, this->rank());
}

void Parallel::Communicator::gather(short val, Int root) const {
  short *buf = NULL;

  this->gather(&val, 1, buf, 1, SHORT, root);
}

void Parallel::Communicator::gather(short val, short *buffer) const {
  this->gather(buffer, 1, &val, 1, SHORT, this->rank());
}

void Parallel::Communicator::gather(unsigned short val, Int root) const {
  unsigned short *buf = NULL;

  this->gather(&val, 1, buf, 1, USHORT, root);
}

void Parallel::Communicator::gather(unsigned short val,
                                    unsigned short *buffer) const {
  this->gather(buffer, 1, &val, 1, USHORT, this->rank());
}

void Parallel::Communicator::gather(Int val, Int root) const {
  Int *buf = NULL;

  this->gather(&val, 1, buf, 1, INT, root);
}

void Parallel::Communicator::gather(Int val, Int *buffer) const {
  this->gather(&val, 1, buffer, 1, INT, this->rank());
}

void Parallel::Communicator::gather(UInt val, Int root) const {
  UInt *buf = NULL;

  this->gather(&val, 1, buf, 1, UINT, root);
}

void Parallel::Communicator::gather(UInt val, UInt *buffer) const {
  this->gather(&val, 1, buffer, 1, UINT, this->rank());
}

void Parallel::Communicator::gather(LInt val, Int root) const {
  LInt *buf = NULL;

  this->gather(&val, 1, buf, 1, LINT, root);
}

void Parallel::Communicator::gather(LInt val, LInt *buffer) const {
  this->gather(&val, 1, buffer, 1, LINT, this->rank());
}

void Parallel::Communicator::gather(ULInt val, Int root) const {
  ULInt *buf = NULL;

  this->gather(&val, 1, buf, 1, ULINT, root);
}

void Parallel::Communicator::gather(ULInt val, ULInt *buffer) const {
  this->gather(&val, 1, buffer, 1, ULINT, this->rank());
}

void Parallel::Communicator::gather(Real val, Int root) const {
  Real *buf = NULL;

  this->gather(&val, 1, buf, 1, REAL, root);
}

void Parallel::Communicator::gather(Real val, Real *buffer) const {
  this->gather(&val, 1, buffer, 1, REAL, this->rank());
}

void Parallel::Communicator::gather(LReal val, Int root) const {
  LReal *buf = NULL;

  this->gather(&val, 1, buf, 1, LREAL, root);
}

void Parallel::Communicator::gather(LReal val, LReal *buffer) const {
  this->gather(&val, 1, buffer, 1, LREAL, this->rank());
}

void Parallel::Communicator::gather(const char *val, Int size, Int root) const {
  char *buf = NULL;

  this->gather(val, size, buf, size, CHAR, root);
}

void Parallel::Communicator::gather(const char *val, Int size,
                                    char *buffer) const {
  this->gather(val, size, buffer, size, CHAR, this->rank());
}

void Parallel::Communicator::gather(const unsigned char *val, Int size,
                                    Int root) const {
  unsigned char *buf = NULL;

  this->gather(val, size, buf, size, UCHAR, root);
}

void Parallel::Communicator::gather(const unsigned char *val, Int size,
                                    unsigned char *buffer) const {
  this->gather(val, size, buffer, size, UCHAR, this->rank());
}

void Parallel::Communicator::gather(const bool *val, Int size, Int root) const {
  bool *buf = NULL;

  this->gather(val, size, buf, size, BOOL, root);
}

void Parallel::Communicator::gather(const bool *val, Int size,
                                    bool *buffer) const {
  this->gather(val, size, buffer, size, BOOL, this->rank());
}

void Parallel::Communicator::gather(const short *val, Int size,
                                    Int root) const {
  short *buf = NULL;

  this->gather(val, size, buf, size, SHORT, root);
}

void Parallel::Communicator::gather(const short *val, Int size,
                                    short *buffer) const {
  this->gather(val, size, buffer, size, SHORT, this->rank());
}

void Parallel::Communicator::gather(const unsigned short *val, Int size,
                                    Int root) const {
  unsigned short *buf = NULL;

  this->gather(val, size, buf, size, USHORT, root);
}

void Parallel::Communicator::gather(const unsigned short *val, Int size,
                                    unsigned short *buffer) const {
  this->gather(val, size, buffer, size, USHORT, this->rank());
}

void Parallel::Communicator::gather(const Int *val, Int size, Int root) const {
  Int *buf = NULL;

  this->gather(val, size, buf, size, INT, root);
}

void Parallel::Communicator::gather(const Int *val, Int size,
                                    Int *buffer) const {
  this->gather(val, size, buffer, size, INT, this->rank());
}

void Parallel::Communicator::gather(const UInt *val, Int size, Int root) const {
  UInt *buf = NULL;

  this->gather(val, size, buf, size, UINT, root);
}

void Parallel::Communicator::gather(const UInt *val, Int size,
                                    UInt *buffer) const {
  this->gather(val, size, buffer, size, UINT, this->rank());
}

void Parallel::Communicator::gather(const LInt *val, Int size, Int root) const {
  LInt *buf = NULL;

  this->gather(val, size, buf, size, LINT, root);
}

void Parallel::Communicator::gather(const LInt *val, Int size,
                                    LInt *buffer) const {
  this->gather(val, size, buffer, size, LINT, this->rank());
}

void Parallel::Communicator::gather(const ULInt *val, Int size,
                                    Int root) const {
  ULInt *buf = NULL;

  this->gather(val, size, buf, size, ULINT, root);
}

void Parallel::Communicator::gather(const ULInt *val, Int size,
                                    ULInt *buffer) const {
  this->gather(val, size, buffer, size, ULINT, this->rank());
}

void Parallel::Communicator::gather(const Real *val, Int size, Int root) const {
  Real *buf = NULL;

  this->gather(val, size, buf, size, REAL, root);
}

void Parallel::Communicator::gather(const Real *val, Int size,
                                    Real *buffer) const {
  this->gather(val, size, buffer, size, REAL, this->rank());
}

void Parallel::Communicator::gather(const LReal *val, Int size,
                                    Int root) const {
  LReal *buf = NULL;

  this->gather(val, size, buf, size, LREAL, root);
}

void Parallel::Communicator::gather(const LReal *val, Int size,
                                    LReal *buffer) const {
  this->gather(val, size, buffer, size, LREAL, this->rank());
}

Transferable **Parallel::Communicator::gather() const {
  Int numProcesses = this->numProcesses();
  Int rank = this->rank();

  Int sizes[numProcesses], displacements[numProcesses];

  Int iignore = 0;

  this->gather(&iignore, 1, sizes, 1, INT, rank);

  Package p;
  p.first = 0;
  p.second = NULL;

  for (Int i = 0; i < numProcesses; i++) {
    displacements[i] = p.first;

    p.first += sizes[i];
  }

  char ignore;

  p.second = new char[p.first];

  this->gatherv(&ignore, 0, p.second, sizes, displacements, PACKED, rank);

  Transferable **t = new Transferable *[numProcesses - 1];

  for (Int i = 0, j = 0; i < numProcesses; i++) {
    if (i == rank) {
      continue;
    }

    Package p2;

    p2.first = sizes[i];
    p2.second = &p.second[displacements[i]];

    t[j++] = this->unpack(p2, false);
  }

  Transferable::free(p);

  return t;
}

void Parallel::Communicator::gather(const Transferable *t, Int root) const {
  Package p = t->pack(this);

  this->gather(&p.first, 1, NULL, 0, INT, root);
  this->gatherv(p.second, p.first, NULL, NULL, NULL, PACKED, root);

  Transferable::free(p);
}

Transferable **Parallel::Communicator::gatherv(Int sizes[]) const {
  Package p;
  p.first = 0;
  p.second = NULL;

  Int numProcesses = this->numProcesses();
  Int rank = this->rank();

  Int tpsizes[numProcesses], displacements[numProcesses];

  Int iignore = 0;

  this->gather(&iignore, 1, tpsizes, 1, INT, rank);

  for (Int i = 0; i < numProcesses; i++) {
    displacements[i] = p.first;

    if (i == rank) {
      continue;
    }

    p.first += tpsizes[i];
  }

  char ignore;

  p.second = new char[p.first];

  this->gatherv(&ignore, 0, p.second, tpsizes, displacements, PACKED, rank);

  Int numTransfs = 0;

  for (Int i = 0, j = 0; i < numProcesses; i++) {
    if (i == rank) {
      continue;
    }

    Int position = displacements[i];

    this->unpack(sizes[j], p.second, p.first, position);

    numTransfs += sizes[j++];
  }

  Transferable **t = new Transferable *[numTransfs];

  for (Int i = 0, j = 0, k = 0; i < numProcesses; i++) {
    if (i == rank) {
      continue;
    }

    Int ignore;

    Int position = displacements[i];

    this->unpack(ignore, p.second, p.first, position);

    Int psizes[sizes[j]];

    for (Int l = 0; l < sizes[j]; l++) {
      this->unpack(psizes[l], p.second, p.first, position);
    }

    for (Int l = 0; l < sizes[j]; l++) {
      Package p2;
      p2.first = psizes[l];
      p2.second = &p.second[position];

      t[k++] = this->unpack(p2, false);

      position += psizes[l];
    }

    j++;
  }

  Transferable::free(p);

  return t;
}

void Parallel::Communicator::gatherv(Transferable **const t, Int size,
                                     Int root) const {
  Package p;
  p.first = 0;
  p.second = NULL;

  Int sizes[size];

  p.first += this->packSize(size + 1, INT);

  for (Int i = 0; i < size; i++) {
    sizes[i] = t[i]->packSize(this);
    p.first += sizes[i];
  }

  this->gather(&p.first, 1, NULL, 0, INT, root);

  p.second = new char[p.first];

  Int position = 0;

  this->pack(size, p.second, p.first, position);

  for (Int i = 0; i < size; i++) {
    this->pack(sizes[i], p.second, p.first, position);
  }

  for (Int i = 0; i < size; i++) {
    t[i]->pack(this, p.second, p.first, position);
  }

  this->gatherv(p.second, p.first, NULL, NULL, NULL, PACKED, root);

  Transferable::free(p);
}

char *Parallel::Communicator::allGather(char val) const {
  return this->allGather(&val, 1);
}

unsigned char *Parallel::Communicator::allGather(unsigned char val) const {
  return this->allGather(&val, 1);
}

bool *Parallel::Communicator::allGather(bool val) const {
  return this->allGather(&val, 1);
}

short *Parallel::Communicator::allGather(short val) const {
  return this->allGather(&val, 1);
}

unsigned short *Parallel::Communicator::allGather(unsigned short val) const {
  return this->allGather(&val, 1);
}

Int *Parallel::Communicator::allGather(Int val) const {
  return this->allGather(&val, 1);
}

UInt *Parallel::Communicator::allGather(UInt val) const {
  return this->allGather(&val, 1);
}

LInt *Parallel::Communicator::allGather(LInt val) const {
  return this->allGather(&val, 1);
}

ULInt *Parallel::Communicator::allGather(ULInt val) const {
  return this->allGather(&val, 1);
}

Real *Parallel::Communicator::allGather(Real val) const {
  return this->allGather(&val, 1);
}

LReal *Parallel::Communicator::allGather(LReal val) const {
  return this->allGather(&val, 1);
}

char *Parallel::Communicator::allGather(const char *val, Int size) const {
  Int numProcesses = this->numProcesses();

  char *buffer = new char[size * numProcesses];

  this->allGather(val, buffer, size, CHAR);

  return buffer;
}

unsigned char *Parallel::Communicator::allGather(const unsigned char *val,
                                                 Int size) const {
  Int numProcesses = this->numProcesses();

  unsigned char *buffer = new unsigned char[size * numProcesses];

  this->allGather(val, buffer, size, UCHAR);

  return buffer;
}

bool *Parallel::Communicator::allGather(const bool *val, Int size) const {
  Int numProcesses = this->numProcesses();

  bool *buffer = new bool[size * numProcesses];

  this->allGather(val, buffer, size, BOOL);

  return buffer;
}

short *Parallel::Communicator::allGather(const short *val, Int size) const {
  Int numProcesses = this->numProcesses();

  short *buffer = new short[size * numProcesses];

  this->allGather(val, buffer, size, SHORT);

  return buffer;
}

unsigned short *Parallel::Communicator::allGather(const unsigned short *val,
                                                  Int size) const {
  Int numProcesses = this->numProcesses();

  unsigned short *buffer = new unsigned short[size * numProcesses];

  this->allGather(val, buffer, size, USHORT);

  return buffer;
}

Int *Parallel::Communicator::allGather(const Int *val, Int size) const {
  Int numProcesses = this->numProcesses();

  Int *buffer = new Int[size * numProcesses];

  this->allGather(val, buffer, size, INT);

  return buffer;
}

UInt *Parallel::Communicator::allGather(const UInt *val, Int size) const {
  Int numProcesses = this->numProcesses();

  UInt *buffer = new UInt[size * numProcesses];

  this->allGather(val, buffer, size, UINT);

  return buffer;
}

LInt *Parallel::Communicator::allGather(const LInt *val, Int size) const {
  Int numProcesses = this->numProcesses();

  LInt *buffer = new LInt[size * numProcesses];

  this->allGather(val, buffer, size, LINT);

  return buffer;
}

ULInt *Parallel::Communicator::allGather(const ULInt *val, Int size) const {
  Int numProcesses = this->numProcesses();

  ULInt *buffer = new ULInt[size * numProcesses];

  this->allGather(val, buffer, size, ULINT);

  return buffer;
}

Real *Parallel::Communicator::allGather(const Real *val, Int size) const {
  Int numProcesses = this->numProcesses();

  Real *buffer = new Real[size * numProcesses];

  this->allGather(val, buffer, size, REAL);

  return buffer;
}

LReal *Parallel::Communicator::allGather(const LReal *val, Int size) const {
  Int numProcesses = this->numProcesses();

  LReal *buffer = new LReal[size * numProcesses];

  this->allGather(val, buffer, size, LREAL);

  return buffer;
}

Transferable **Parallel::Communicator::allGather(const Transferable *t) const {
  Package p;

  if (t) {
    p = t->pack(this);
  } else {
    p.first = 0;
    p.second = NULL;
  }

  Int numProcesses = this->numProcesses();
  Int rank = this->rank();

  Int sizes[numProcesses], displacements[numProcesses];

  this->allGather(&p.first, sizes, 1, INT);

  Package p2;

  p2.first = 0;
  p2.second = NULL;

  for (Int i = 0; i < numProcesses; i++) {
    displacements[i] = p2.first;
    p2.first += sizes[i];
  }

  p2.second = new char[p2.first];

  this->allGatherv(p.second, p.first, p2.second, sizes, displacements, PACKED);

  if (t) {
    Transferable::free(p);
  }

  Transferable **ts = new Transferable *[numProcesses];

  for (Int i = 0; i < numProcesses; i++) {
    if (sizes[i] == 0) {
      ts[i] = NULL;

      continue;
    }

    if (i == rank) {
      ts[i] = const_cast<Parallel::Transferable *>(t);

      continue;
    }

    p.first = sizes[i];
    p.second = &p2.second[displacements[i]];

    ts[i] = this->unpack(p, false);
  }

  Transferable::free(p2);

  return ts;
}

char *Parallel::Communicator::allToAll(char val) const {
  return this->allToAll(&val, 1);
}

unsigned char *Parallel::Communicator::allToAll(unsigned char val) const {
  return this->allToAll(&val, 1);
}

bool *Parallel::Communicator::allToAll(bool val) const {
  return this->allToAll(&val, 1);
}

short *Parallel::Communicator::allToAll(short val) const {
  return this->allToAll(&val, 1);
}

unsigned short *Parallel::Communicator::allToAll(unsigned short val) const {
  return this->allToAll(&val, 1);
}

Int *Parallel::Communicator::allToAll(Int val) const {
  return this->allToAll(&val, 1);
}

UInt *Parallel::Communicator::allToAll(UInt val) const {
  return this->allToAll(&val, 1);
}

LInt *Parallel::Communicator::allToAll(LInt val) const {
  return this->allToAll(&val, 1);
}

ULInt *Parallel::Communicator::allToAll(ULInt val) const {
  return this->allToAll(&val, 1);
}

Real *Parallel::Communicator::allToAll(Real val) const {
  return this->allToAll(&val, 1);
}

LReal *Parallel::Communicator::allToAll(LReal val) const {
  return this->allToAll(&val, 1);
}

char *Parallel::Communicator::allToAll(const char *val, Int size) const {
  Int numProcesses = this->numProcesses();

  char *buffer = new char[size * numProcesses];

  this->allToAll(val, buffer, size, CHAR);

  return buffer;
}

unsigned char *Parallel::Communicator::allToAll(const unsigned char *val,
                                                Int size) const {
  Int numProcesses = this->numProcesses();

  unsigned char *buffer = new unsigned char[size * numProcesses];

  this->allToAll(val, buffer, size, UCHAR);

  return buffer;
}

bool *Parallel::Communicator::allToAll(const bool *val, Int size) const {
  Int numProcesses = this->numProcesses();

  bool *buffer = new bool[size * numProcesses];

  this->allToAll(&val, buffer, size, BOOL);

  return buffer;
}

short *Parallel::Communicator::allToAll(const short *val, Int size) const {
  Int numProcesses = this->numProcesses();

  short *buffer = new short[size * numProcesses];

  this->allToAll(&val, buffer, size, SHORT);

  return buffer;
}

unsigned short *Parallel::Communicator::allToAll(const unsigned short *val,
                                                 Int size) const {
  Int numProcesses = this->numProcesses();

  unsigned short *buffer = new unsigned short[size * numProcesses];

  this->allToAll(&val, buffer, size, USHORT);

  return buffer;
}

Int *Parallel::Communicator::allToAll(const Int *val, Int size) const {
  Int numProcesses = this->numProcesses();

  Int *buffer = new Int[size * numProcesses];

  this->allToAll(&val, buffer, size, INT);

  return buffer;
}

UInt *Parallel::Communicator::allToAll(const UInt *val, Int size) const {
  Int numProcesses = this->numProcesses();

  UInt *buffer = new UInt[size * numProcesses];

  this->allToAll(&val, buffer, size, UINT);

  return buffer;
}

LInt *Parallel::Communicator::allToAll(const LInt *val, Int size) const {
  Int numProcesses = this->numProcesses();

  LInt *buffer = new LInt[size * numProcesses];

  this->allToAll(&val, buffer, size, LINT);

  return buffer;
}

ULInt *Parallel::Communicator::allToAll(const ULInt *val, Int size) const {
  Int numProcesses = this->numProcesses();

  ULInt *buffer = new ULInt[size * numProcesses];

  this->allToAll(&val, buffer, size, ULINT);

  return buffer;
}

Real *Parallel::Communicator::allToAll(const Real *val, Int size) const {
  Int numProcesses = this->numProcesses();

  Real *buffer = new Real[size * numProcesses];

  this->allToAll(&val, buffer, size, REAL);

  return buffer;
}

LReal *Parallel::Communicator::allToAll(const LReal *val, Int size) const {
  Int numProcesses = this->numProcesses();

  LReal *buffer = new LReal[size * numProcesses];

  this->allToAll(&val, buffer, size, LREAL);

  return buffer;
}

Transferable **Parallel::Communicator::allToAll(Transferable **const t) const {
  Int numProcesses = this->numProcesses();
  Int rank = this->rank();

  Package p, rp;
  Int sizes[numProcesses], displacements[numProcesses];
  Int rsizes[numProcesses], rdisplacements[numProcesses];

  p.first = 0;

  for (Int i = 0; i < numProcesses; i++) {
    sizes[i] = t[i] ? t[i]->packSize(this) : 0;

    p.first += sizes[i];

    displacements[i] = p.first;
  }

  this->allToAll(sizes, rsizes, 1, INT);

  rp.first = 0;

  for (Int i = 0; i < numProcesses; i++) {
    rp.first += rsizes[i];
    rdisplacements[i] = rp.first;
  }

  p.second = new char[p.first];
  rp.second = new char[rp.first];

  Int position = 0;

  for (Int i = 0; i < numProcesses; i++) {
    if (t[i]) {
      t[i]->pack(this, p.second, p.first, position);
    }
  }

  this->allToAllv(p.second, sizes, displacements, rp.second, rsizes,
                  rdisplacements, PACKED);

  Transferable::free(p);

  Transferable **ts = new Transferable *[numProcesses];

  for (Int i = 0; i < numProcesses; i++) {
    if (rsizes[i] == 0) {
      ts[i] = NULL;

      continue;
    }

    if (i == rank) {
      ts[i] = const_cast<Parallel::Transferable *>(t[i]);

      continue;
    }

    p.first = sizes[i];
    p.second = &rp.second[rdisplacements[i]];

    ts[i] = this->unpack(p, false);
  }

  Transferable::free(rp);

  return ts;
}

void Parallel::Communicator::send(char val, Int process, Int tag) const {
  this->send(&val, 1, CHAR, process, tag);
}

void Parallel::Communicator::send(unsigned char val, Int process,
                                  Int tag) const {
  this->send(&val, 1, UCHAR, process, tag);
}

void Parallel::Communicator::send(bool val, Int process, Int tag) const {
  this->send(&val, 1, BOOL, process, tag);
}

void Parallel::Communicator::send(short val, Int process, Int tag) const {
  this->send(&val, 1, SHORT, process, tag);
}

void Parallel::Communicator::send(unsigned short val, Int process,
                                  Int tag) const {
  this->send(&val, 1, USHORT, process, tag);
}

void Parallel::Communicator::send(Int val, Int process, Int tag) const {
  this->send(&val, 1, INT, process, tag);
}

void Parallel::Communicator::send(UInt val, Int process, Int tag) const {
  this->send(&val, 1, UINT, process, tag);
}

void Parallel::Communicator::send(LInt val, Int process, Int tag) const {
  this->send(&val, 1, LINT, process, tag);
}

void Parallel::Communicator::send(ULInt val, Int process, Int tag) const {
  this->send(&val, 1, ULINT, process, tag);
}

void Parallel::Communicator::send(Real val, Int process, Int tag) const {
  this->send(&val, 1, REAL, process, tag);
}

void Parallel::Communicator::send(LReal val, Int process, Int tag) const {
  this->send(&val, 1, LREAL, process, tag);
}

void Parallel::Communicator::send(const char *val, Int size, Int process,
                                  Int tag) const {
  this->send(val, size, CHAR, process, tag);
}

void Parallel::Communicator::send(const unsigned char *val, Int size,
                                  Int process, Int tag) const {
  this->send(val, size, UCHAR, process, tag);
}

void Parallel::Communicator::send(const bool *val, Int size, Int process,
                                  Int tag) const {
  this->send(val, size, BOOL, process, tag);
}

void Parallel::Communicator::send(const short *val, Int size, Int process,
                                  Int tag) const {
  this->send(val, size, SHORT, process, tag);
}

void Parallel::Communicator::send(const unsigned short *val, Int size,
                                  Int process, Int tag) const {
  this->send(val, size, USHORT, process, tag);
}

void Parallel::Communicator::send(const Int *val, Int size, Int process,
                                  Int tag) const {
  this->send(val, size, INT, process, tag);
}

void Parallel::Communicator::send(const UInt *val, Int size, Int process,
                                  Int tag) const {
  this->send(val, size, UINT, process, tag);
}

void Parallel::Communicator::send(const LInt *val, Int size, Int process,
                                  Int tag) const {
  this->send(val, size, LINT, process, tag);
}

void Parallel::Communicator::send(const ULInt *val, Int size, Int process,
                                  Int tag) const {
  this->send(val, size, ULINT, process, tag);
}

void Parallel::Communicator::send(const Real *val, Int size, Int process,
                                  Int tag) const {
  this->send(val, size, REAL, process, tag);
}

void Parallel::Communicator::send(const LReal *val, Int size, Int process,
                                  Int tag) const {
  this->send(val, size, LREAL, process, tag);
}

void Parallel::Communicator::send(const Transferable *t, Int process,
                                  Int tag) const {
  Package p = t->pack(this);

  this->send(&p.first, 1, INT, process, tag);

  this->send(p.second, p.first, PACKED, process, tag);

  Transferable::free(p);
}

void Parallel::Communicator::ssend(char val, Int process, Int tag) const {
  this->ssend(&val, 1, CHAR, process, tag);
}

void Parallel::Communicator::ssend(unsigned char val, Int process,
                                   Int tag) const {
  this->ssend(&val, 1, UCHAR, process, tag);
}

void Parallel::Communicator::ssend(bool val, Int process, Int tag) const {
  this->ssend(&val, 1, BOOL, process, tag);
}

void Parallel::Communicator::ssend(short val, Int process, Int tag) const {
  this->ssend(&val, 1, SHORT, process, tag);
}

void Parallel::Communicator::ssend(unsigned short val, Int process,
                                   Int tag) const {
  this->ssend(&val, 1, USHORT, process, tag);
}

void Parallel::Communicator::ssend(Int val, Int process, Int tag) const {
  this->ssend(&val, 1, INT, process, tag);
}

void Parallel::Communicator::ssend(UInt val, Int process, Int tag) const {
  this->ssend(&val, 1, UINT, process, tag);
}

void Parallel::Communicator::ssend(LInt val, Int process, Int tag) const {
  this->ssend(&val, 1, LINT, process, tag);
}

void Parallel::Communicator::ssend(ULInt val, Int process, Int tag) const {
  this->ssend(&val, 1, ULINT, process, tag);
}

void Parallel::Communicator::ssend(Real val, Int process, Int tag) const {
  this->ssend(&val, 1, REAL, process, tag);
}

void Parallel::Communicator::ssend(LReal val, Int process, Int tag) const {
  this->ssend(&val, 1, LREAL, process, tag);
}

void Parallel::Communicator::ssend(const char *val, Int size, Int process,
                                   Int tag) const {
  this->ssend(val, size, CHAR, process, tag);
}

void Parallel::Communicator::ssend(const unsigned char *val, Int size,
                                   Int process, Int tag) const {
  this->ssend(val, size, UCHAR, process, tag);
}

void Parallel::Communicator::ssend(const bool *val, Int size, Int process,
                                   Int tag) const {
  this->ssend(val, size, BOOL, process, tag);
}

void Parallel::Communicator::ssend(const short *val, Int size, Int process,
                                   Int tag) const {
  this->ssend(val, size, SHORT, process, tag);
}

void Parallel::Communicator::ssend(const unsigned short *val, Int size,
                                   Int process, Int tag) const {
  this->ssend(val, size, USHORT, process, tag);
}

void Parallel::Communicator::ssend(const Int *val, Int size, Int process,
                                   Int tag) const {
  this->ssend(val, size, INT, process, tag);
}

void Parallel::Communicator::ssend(const UInt *val, Int size, Int process,
                                   Int tag) const {
  this->ssend(val, size, UINT, process, tag);
}

void Parallel::Communicator::ssend(const LInt *val, Int size, Int process,
                                   Int tag) const {
  this->ssend(val, size, LINT, process, tag);
}

void Parallel::Communicator::ssend(const ULInt *val, Int size, Int process,
                                   Int tag) const {
  this->ssend(val, size, ULINT, process, tag);
}

void Parallel::Communicator::ssend(const Real *val, Int size, Int process,
                                   Int tag) const {
  this->ssend(val, size, REAL, process, tag);
}

void Parallel::Communicator::ssend(const LReal *val, Int size, Int process,
                                   Int tag) const {
  this->ssend(val, size, LREAL, process, tag);
}

void Parallel::Communicator::ssend(const Transferable *t, Int process,
                                   Int tag) const {
  Package p = t->pack(this);

  this->ssend(&p.first, 1, INT, process, tag);

  this->ssend(p.second, p.first, PACKED, process, tag);

  Transferable::free(p);
}

void Parallel::Communicator::bsend(char val, Int process, Int tag) const {
  this->bsend(&val, 1, CHAR, process, tag);
}

void Parallel::Communicator::bsend(unsigned char val, Int process,
                                   Int tag) const {
  this->bsend(&val, 1, UCHAR, process, tag);
}

void Parallel::Communicator::bsend(bool val, Int process, Int tag) const {
  this->bsend(&val, 1, BOOL, process, tag);
}

void Parallel::Communicator::bsend(short val, Int process, Int tag) const {
  this->bsend(&val, 1, SHORT, process, tag);
}

void Parallel::Communicator::bsend(unsigned short val, Int process,
                                   Int tag) const {
  this->bsend(&val, 1, USHORT, process, tag);
}

void Parallel::Communicator::bsend(Int val, Int process, Int tag) const {
  this->bsend(&val, 1, INT, process, tag);
}

void Parallel::Communicator::bsend(UInt val, Int process, Int tag) const {
  this->bsend(&val, 1, UINT, process, tag);
}

void Parallel::Communicator::bsend(LInt val, Int process, Int tag) const {
  this->bsend(&val, 1, LINT, process, tag);
}

void Parallel::Communicator::bsend(ULInt val, Int process, Int tag) const {
  this->bsend(&val, 1, ULINT, process, tag);
}

void Parallel::Communicator::bsend(Real val, Int process, Int tag) const {
  this->bsend(&val, 1, REAL, process, tag);
}

void Parallel::Communicator::bsend(LReal val, Int process, Int tag) const {
  this->bsend(&val, 1, LREAL, process, tag);
}

void Parallel::Communicator::bsend(const char *val, Int size, Int process,
                                   Int tag) const {
  this->bsend(val, size, CHAR, process, tag);
}

void Parallel::Communicator::bsend(const unsigned char *val, Int size,
                                   Int process, Int tag) const {
  this->bsend(val, size, UCHAR, process, tag);
}

void Parallel::Communicator::bsend(const bool *val, Int size, Int process,
                                   Int tag) const {
  this->bsend(val, size, BOOL, process, tag);
}

void Parallel::Communicator::bsend(const short *val, Int size, Int process,
                                   Int tag) const {
  this->bsend(val, size, SHORT, process, tag);
}

void Parallel::Communicator::bsend(const unsigned short *val, Int size,
                                   Int process, Int tag) const {
  this->bsend(val, size, USHORT, process, tag);
}

void Parallel::Communicator::bsend(const Int *val, Int size, Int process,
                                   Int tag) const {
  this->bsend(val, size, INT, process, tag);
}

void Parallel::Communicator::bsend(const UInt *val, Int size, Int process,
                                   Int tag) const {
  this->bsend(val, size, UINT, process, tag);
}

void Parallel::Communicator::bsend(const LInt *val, Int size, Int process,
                                   Int tag) const {
  this->bsend(val, size, LINT, process, tag);
}

void Parallel::Communicator::bsend(const ULInt *val, Int size, Int process,
                                   Int tag) const {
  this->bsend(val, size, ULINT, process, tag);
}

void Parallel::Communicator::bsend(const Real *val, Int size, Int process,
                                   Int tag) const {
  this->bsend(val, size, REAL, process, tag);
}

void Parallel::Communicator::bsend(const LReal *val, Int size, Int process,
                                   Int tag) const {
  this->bsend(val, size, LREAL, process, tag);
}

void Parallel::Communicator::bsend(const Transferable *t, Int process,
                                   Int tag) const {
  Package p = t->pack(this);

  this->bsend(&p.first, 1, INT, process, tag);

  this->bsend(p.second, p.first, PACKED, process, tag);

  Transferable::free(p);
}

void Parallel::Communicator::rsend(char val, Int process, Int tag) const {
  this->rsend(&val, 1, CHAR, process, tag);
}

void Parallel::Communicator::rsend(unsigned char val, Int process,
                                   Int tag) const {
  this->rsend(&val, 1, UCHAR, process, tag);
}

void Parallel::Communicator::rsend(bool val, Int process, Int tag) const {
  this->rsend(&val, 1, BOOL, process, tag);
}

void Parallel::Communicator::rsend(short val, Int process, Int tag) const {
  this->rsend(&val, 1, SHORT, process, tag);
}

void Parallel::Communicator::rsend(unsigned short val, Int process,
                                   Int tag) const {
  this->rsend(&val, 1, USHORT, process, tag);
}

void Parallel::Communicator::rsend(Int val, Int process, Int tag) const {
  this->rsend(&val, 1, INT, process, tag);
}

void Parallel::Communicator::rsend(UInt val, Int process, Int tag) const {
  this->rsend(&val, 1, UINT, process, tag);
}

void Parallel::Communicator::rsend(LInt val, Int process, Int tag) const {
  this->rsend(&val, 1, LINT, process, tag);
}

void Parallel::Communicator::rsend(ULInt val, Int process, Int tag) const {
  this->rsend(&val, 1, ULINT, process, tag);
}

void Parallel::Communicator::rsend(Real val, Int process, Int tag) const {
  this->rsend(&val, 1, REAL, process, tag);
}

void Parallel::Communicator::rsend(LReal val, Int process, Int tag) const {
  this->rsend(&val, 1, LREAL, process, tag);
}

void Parallel::Communicator::rsend(const char *val, Int size, Int process,
                                   Int tag) const {
  this->rsend(val, size, CHAR, process, tag);
}

void Parallel::Communicator::rsend(const unsigned char *val, Int size,
                                   Int process, Int tag) const {
  this->rsend(val, size, UCHAR, process, tag);
}

void Parallel::Communicator::rsend(const bool *val, Int size, Int process,
                                   Int tag) const {
  this->rsend(val, size, BOOL, process, tag);
}

void Parallel::Communicator::rsend(const short *val, Int size, Int process,
                                   Int tag) const {
  this->rsend(val, size, SHORT, process, tag);
}

void Parallel::Communicator::rsend(const unsigned short *val, Int size,
                                   Int process, Int tag) const {
  this->rsend(val, size, USHORT, process, tag);
}

void Parallel::Communicator::rsend(const Int *val, Int size, Int process,
                                   Int tag) const {
  this->rsend(val, size, INT, process, tag);
}

void Parallel::Communicator::rsend(const UInt *val, Int size, Int process,
                                   Int tag) const {
  this->rsend(val, size, UINT, process, tag);
}

void Parallel::Communicator::rsend(const LInt *val, Int size, Int process,
                                   Int tag) const {
  this->rsend(val, size, LINT, process, tag);
}

void Parallel::Communicator::rsend(const ULInt *val, Int size, Int process,
                                   Int tag) const {
  this->rsend(val, size, ULINT, process, tag);
}

void Parallel::Communicator::rsend(const Real *val, Int size, Int process,
                                   Int tag) const {
  this->rsend(val, size, REAL, process, tag);
}

void Parallel::Communicator::rsend(const LReal *val, Int size, Int process,
                                   Int tag) const {
  this->rsend(val, size, LREAL, process, tag);
}

void Parallel::Communicator::rsend(const Transferable *t, Int process,
                                   Int tag) const {
  Package p = t->pack(this);

  this->rsend(&p.first, 1, INT, process, tag);

  this->rsend(p.second, p.first, PACKED, process, tag);

  Transferable::free(p);
}

UInt Parallel::Communicator::isend(char val, Int process, Int tag) const {
  return this->isend(&val, 1, CHAR, process, tag);
}

UInt Parallel::Communicator::isend(unsigned char val, Int process,
                                   Int tag) const {
  return this->isend(&val, 1, UCHAR, process, tag);
}

UInt Parallel::Communicator::isend(bool val, Int process, Int tag) const {
  return this->isend(&val, 1, BOOL, process, tag);
}

UInt Parallel::Communicator::isend(short val, Int process, Int tag) const {
  return this->isend(&val, 1, SHORT, process, tag);
}

UInt Parallel::Communicator::isend(unsigned short val, Int process,
                                   Int tag) const {
  return this->isend(&val, 1, USHORT, process, tag);
}

UInt Parallel::Communicator::isend(Int val, Int process, Int tag) const {
  return this->isend(&val, 1, INT, process, tag);
}

UInt Parallel::Communicator::isend(UInt val, Int process, Int tag) const {
  return this->isend(&val, 1, UINT, process, tag);
}

UInt Parallel::Communicator::isend(LInt val, Int process, Int tag) const {
  return this->isend(&val, 1, LINT, process, tag);
}

UInt Parallel::Communicator::isend(ULInt val, Int process, Int tag) const {
  return this->isend(&val, 1, ULINT, process, tag);
}

UInt Parallel::Communicator::isend(Real val, Int process, Int tag) const {
  return this->isend(&val, 1, REAL, process, tag);
}

UInt Parallel::Communicator::isend(LReal val, Int process, Int tag) const {
  return this->isend(&val, 1, LREAL, process, tag);
}

UInt Parallel::Communicator::isend(const char *val, Int size, Int process,
                                   Int tag) const {
  return this->isend(val, size, CHAR, process, tag);
}

UInt Parallel::Communicator::isend(const unsigned char *val, Int size,
                                   Int process, Int tag) const {
  return this->isend(val, size, UCHAR, process, tag);
}

UInt Parallel::Communicator::isend(const bool *val, Int size, Int process,
                                   Int tag) const {
  return this->isend(val, size, BOOL, process, tag);
}

UInt Parallel::Communicator::isend(const short *val, Int size, Int process,
                                   Int tag) const {
  return this->isend(val, size, SHORT, process, tag);
}

UInt Parallel::Communicator::isend(const unsigned short *val, Int size,
                                   Int process, Int tag) const {
  return this->isend(val, size, USHORT, process, tag);
}

UInt Parallel::Communicator::isend(const Int *val, Int size, Int process,
                                   Int tag) const {
  return this->isend(val, size, INT, process, tag);
}

UInt Parallel::Communicator::isend(const UInt *val, Int size, Int process,
                                   Int tag) const {
  return this->isend(val, size, UINT, process, tag);
}

UInt Parallel::Communicator::isend(const LInt *val, Int size, Int process,
                                   Int tag) const {
  return this->isend(val, size, LINT, process, tag);
}

UInt Parallel::Communicator::isend(const ULInt *val, Int size, Int process,
                                   Int tag) const {
  return this->isend(val, size, ULINT, process, tag);
}

UInt Parallel::Communicator::isend(const Real *val, Int size, Int process,
                                   Int tag) const {
  return this->isend(val, size, REAL, process, tag);
}

UInt Parallel::Communicator::isend(const LReal *val, Int size, Int process,
                                   Int tag) const {
  return this->isend(val, size, LREAL, process, tag);
}

UInt Parallel::Communicator::isend(const Transferable *t, Int process,
                                   Int tag) const {
  Package p = t->pack(this);

  this->removeRequest(this->isend(&p.first, 1, INT, process, tag));

  // the package must not be freed until it has been completely sent
  return this->isend(p.second, p.first, PACKED, process, tag);
}

UInt Parallel::Communicator::issend(char val, Int process, Int tag) const {
  return this->issend(&val, 1, CHAR, process, tag);
}

UInt Parallel::Communicator::issend(unsigned char val, Int process,
                                    Int tag) const {
  return this->issend(&val, 1, UCHAR, process, tag);
}

UInt Parallel::Communicator::issend(bool val, Int process, Int tag) const {
  return this->issend(&val, 1, BOOL, process, tag);
}

UInt Parallel::Communicator::issend(short val, Int process, Int tag) const {
  return this->issend(&val, 1, SHORT, process, tag);
}

UInt Parallel::Communicator::issend(unsigned short val, Int process,
                                    Int tag) const {
  return this->issend(&val, 1, USHORT, process, tag);
}

UInt Parallel::Communicator::issend(Int val, Int process, Int tag) const {
  return this->issend(&val, 1, INT, process, tag);
}

UInt Parallel::Communicator::issend(UInt val, Int process, Int tag) const {
  return this->issend(&val, 1, UINT, process, tag);
}

UInt Parallel::Communicator::issend(LInt val, Int process, Int tag) const {
  return this->issend(&val, 1, LINT, process, tag);
}

UInt Parallel::Communicator::issend(ULInt val, Int process, Int tag) const {
  return this->issend(&val, 1, ULINT, process, tag);
}

UInt Parallel::Communicator::issend(Real val, Int process, Int tag) const {
  return this->issend(&val, 1, REAL, process, tag);
}

UInt Parallel::Communicator::issend(LReal val, Int process, Int tag) const {
  return this->issend(&val, 1, LREAL, process, tag);
}

UInt Parallel::Communicator::issend(const char *val, Int size, Int process,
                                    Int tag) const {
  return this->issend(val, size, CHAR, process, tag);
}

UInt Parallel::Communicator::issend(const unsigned char *val, Int size,
                                    Int process, Int tag) const {
  return this->issend(val, size, UCHAR, process, tag);
}

UInt Parallel::Communicator::issend(const bool *val, Int size, Int process,
                                    Int tag) const {
  return this->issend(val, size, BOOL, process, tag);
}

UInt Parallel::Communicator::issend(const short *val, Int size, Int process,
                                    Int tag) const {
  return this->issend(val, size, SHORT, process, tag);
}

UInt Parallel::Communicator::issend(const unsigned short *val, Int size,
                                    Int process, Int tag) const {
  return this->issend(val, size, USHORT, process, tag);
}

UInt Parallel::Communicator::issend(const Int *val, Int size, Int process,
                                    Int tag) const {
  return this->issend(val, size, INT, process, tag);
}

UInt Parallel::Communicator::issend(const UInt *val, Int size, Int process,
                                    Int tag) const {
  return this->issend(val, size, UINT, process, tag);
}

UInt Parallel::Communicator::issend(const LInt *val, Int size, Int process,
                                    Int tag) const {
  return this->issend(val, size, LINT, process, tag);
}

UInt Parallel::Communicator::issend(const ULInt *val, Int size, Int process,
                                    Int tag) const {
  return this->issend(val, size, ULINT, process, tag);
}

UInt Parallel::Communicator::issend(const Real *val, Int size, Int process,
                                    Int tag) const {
  return this->issend(val, size, REAL, process, tag);
}

UInt Parallel::Communicator::issend(const LReal *val, Int size, Int process,
                                    Int tag) const {
  return this->issend(val, size, LREAL, process, tag);
}

UInt Parallel::Communicator::issend(const Transferable *t, Int process,
                                    Int tag) const {
  Package p = t->pack(this);

  this->removeRequest(this->issend(&p.first, 1, INT, process, tag));

  // the package must not be freed until it has been completely sent
  return this->issend(p.second, p.first, PACKED, process, tag);
}

UInt Parallel::Communicator::ibsend(char val, Int process, Int tag) const {
  return this->ibsend(&val, 1, CHAR, process, tag);
}

UInt Parallel::Communicator::ibsend(unsigned char val, Int process,
                                    Int tag) const {
  return this->ibsend(&val, 1, UCHAR, process, tag);
}

UInt Parallel::Communicator::ibsend(bool val, Int process, Int tag) const {
  return this->ibsend(&val, 1, BOOL, process, tag);
}

UInt Parallel::Communicator::ibsend(short val, Int process, Int tag) const {
  return this->ibsend(&val, 1, SHORT, process, tag);
}

UInt Parallel::Communicator::ibsend(unsigned short val, Int process,
                                    Int tag) const {
  return this->ibsend(&val, 1, USHORT, process, tag);
}

UInt Parallel::Communicator::ibsend(Int val, Int process, Int tag) const {
  return this->ibsend(&val, 1, INT, process, tag);
}

UInt Parallel::Communicator::ibsend(UInt val, Int process, Int tag) const {
  return this->ibsend(&val, 1, UINT, process, tag);
}

UInt Parallel::Communicator::ibsend(LInt val, Int process, Int tag) const {
  return this->ibsend(&val, 1, LINT, process, tag);
}

UInt Parallel::Communicator::ibsend(ULInt val, Int process, Int tag) const {
  return this->ibsend(&val, 1, ULINT, process, tag);
}

UInt Parallel::Communicator::ibsend(Real val, Int process, Int tag) const {
  return this->ibsend(&val, 1, REAL, process, tag);
}

UInt Parallel::Communicator::ibsend(LReal val, Int process, Int tag) const {
  return this->ibsend(&val, 1, LREAL, process, tag);
}

UInt Parallel::Communicator::ibsend(const char *val, Int size, Int process,
                                    Int tag) const {
  return this->ibsend(val, size, CHAR, process, tag);
}

UInt Parallel::Communicator::ibsend(const unsigned char *val, Int size,
                                    Int process, Int tag) const {
  return this->ibsend(val, size, UCHAR, process, tag);
}

UInt Parallel::Communicator::ibsend(const bool *val, Int size, Int process,
                                    Int tag) const {
  return this->ibsend(val, size, BOOL, process, tag);
}

UInt Parallel::Communicator::ibsend(const short *val, Int size, Int process,
                                    Int tag) const {
  return this->ibsend(val, size, SHORT, process, tag);
}

UInt Parallel::Communicator::ibsend(const unsigned short *val, Int size,
                                    Int process, Int tag) const {
  return this->ibsend(val, size, USHORT, process, tag);
}

UInt Parallel::Communicator::ibsend(const Int *val, Int size, Int process,
                                    Int tag) const {
  return this->ibsend(val, size, INT, process, tag);
}

UInt Parallel::Communicator::ibsend(const UInt *val, Int size, Int process,
                                    Int tag) const {
  return this->ibsend(val, size, UINT, process, tag);
}

UInt Parallel::Communicator::ibsend(const LInt *val, Int size, Int process,
                                    Int tag) const {
  return this->ibsend(val, size, LINT, process, tag);
}

UInt Parallel::Communicator::ibsend(const ULInt *val, Int size, Int process,
                                    Int tag) const {
  return this->ibsend(val, size, ULINT, process, tag);
}

UInt Parallel::Communicator::ibsend(const Real *val, Int size, Int process,
                                    Int tag) const {
  return this->ibsend(val, size, REAL, process, tag);
}

UInt Parallel::Communicator::ibsend(const LReal *val, Int size, Int process,
                                    Int tag) const {
  return this->ibsend(val, size, LREAL, process, tag);
}

UInt Parallel::Communicator::ibsend(const Transferable *t, Int process,
                                    Int tag) const {
  Package p = t->pack(this);

  this->removeRequest(this->ibsend(&p.first, 1, INT, process, tag));

  // the package must not be freed until it has been completely sent
  return this->ibsend(p.second, p.first, PACKED, process, tag);
}

UInt Parallel::Communicator::irsend(char val, Int process, Int tag) const {
  return this->irsend(&val, 1, CHAR, process, tag);
}

UInt Parallel::Communicator::irsend(unsigned char val, Int process,
                                    Int tag) const {
  return this->irsend(&val, 1, UCHAR, process, tag);
}

UInt Parallel::Communicator::irsend(bool val, Int process, Int tag) const {
  return this->irsend(&val, 1, BOOL, process, tag);
}

UInt Parallel::Communicator::irsend(short val, Int process, Int tag) const {
  return this->irsend(&val, 1, SHORT, process, tag);
}

UInt Parallel::Communicator::irsend(unsigned short val, Int process,
                                    Int tag) const {
  return this->irsend(&val, 1, USHORT, process, tag);
}

UInt Parallel::Communicator::irsend(Int val, Int process, Int tag) const {
  return this->irsend(&val, 1, INT, process, tag);
}

UInt Parallel::Communicator::irsend(UInt val, Int process, Int tag) const {
  return this->irsend(&val, 1, UINT, process, tag);
}

UInt Parallel::Communicator::irsend(LInt val, Int process, Int tag) const {
  return this->irsend(&val, 1, LINT, process, tag);
}

UInt Parallel::Communicator::irsend(ULInt val, Int process, Int tag) const {
  return this->irsend(&val, 1, ULINT, process, tag);
}

UInt Parallel::Communicator::irsend(Real val, Int process, Int tag) const {
  return this->irsend(&val, 1, REAL, process, tag);
}

UInt Parallel::Communicator::irsend(LReal val, Int process, Int tag) const {
  return this->irsend(&val, 1, LREAL, process, tag);
}

UInt Parallel::Communicator::irsend(const char *val, Int size, Int process,
                                    Int tag) const {
  return this->irsend(val, size, CHAR, process, tag);
}

UInt Parallel::Communicator::irsend(const unsigned char *val, Int size,
                                    Int process, Int tag) const {
  return this->irsend(val, size, UCHAR, process, tag);
}

UInt Parallel::Communicator::irsend(const bool *val, Int size, Int process,
                                    Int tag) const {
  return this->irsend(val, size, BOOL, process, tag);
}

UInt Parallel::Communicator::irsend(const short *val, Int size, Int process,
                                    Int tag) const {
  return this->irsend(val, size, SHORT, process, tag);
}

UInt Parallel::Communicator::irsend(const unsigned short *val, Int size,
                                    Int process, Int tag) const {
  return this->irsend(val, size, USHORT, process, tag);
}

UInt Parallel::Communicator::irsend(const Int *val, Int size, Int process,
                                    Int tag) const {
  return this->irsend(val, size, INT, process, tag);
}

UInt Parallel::Communicator::irsend(const UInt *val, Int size, Int process,
                                    Int tag) const {
  return this->irsend(val, size, UINT, process, tag);
}

UInt Parallel::Communicator::irsend(const LInt *val, Int size, Int process,
                                    Int tag) const {
  return this->irsend(val, size, LINT, process, tag);
}

UInt Parallel::Communicator::irsend(const ULInt *val, Int size, Int process,
                                    Int tag) const {
  return this->irsend(val, size, ULINT, process, tag);
}

UInt Parallel::Communicator::irsend(const Real *val, Int size, Int process,
                                    Int tag) const {
  return this->irsend(val, size, REAL, process, tag);
}

UInt Parallel::Communicator::irsend(const LReal *val, Int size, Int process,
                                    Int tag) const {
  return this->irsend(val, size, LREAL, process, tag);
}

UInt Parallel::Communicator::irsend(const Transferable *t, Int process,
                                    Int tag) const {
  Package p = t->pack(this);

  this->removeRequest(this->irsend(&p.first, 1, INT, process, tag));

  // the package must not be freed until it has been completely sent
  return this->irsend(p.second, p.first, PACKED, process, tag);
}

void Parallel::Communicator::receive(char &val, Int process, Int tag) const {
  this->receive(&val, 1, CHAR, process, tag);
}

void Parallel::Communicator::receive(unsigned char &val, Int process,
                                     Int tag) const {
  this->receive(&val, 1, UCHAR, process, tag);
}

void Parallel::Communicator::receive(bool &val, Int process, Int tag) const {
  this->receive(&val, 1, BOOL, process, tag);
}

void Parallel::Communicator::receive(short &val, Int process, Int tag) const {
  this->receive(&val, 1, SHORT, process, tag);
}

void Parallel::Communicator::receive(unsigned short &val, Int process,
                                     Int tag) const {
  this->receive(&val, 1, USHORT, process, tag);
}

void Parallel::Communicator::receive(Int &val, Int process, Int tag) const {
  this->receive(&val, 1, INT, process, tag);
}

void Parallel::Communicator::receive(UInt &val, Int process, Int tag) const {
  this->receive(&val, 1, UINT, process, tag);
}

void Parallel::Communicator::receive(LInt &val, Int process, Int tag) const {
  this->receive(&val, 1, LINT, process, tag);
}

void Parallel::Communicator::receive(ULInt &val, Int process, Int tag) const {
  this->receive(&val, 1, ULINT, process, tag);
}

void Parallel::Communicator::receive(Real &val, Int process, Int tag) const {
  this->receive(&val, 1, REAL, process, tag);
}

void Parallel::Communicator::receive(LReal &val, Int process, Int tag) const {
  this->receive(&val, 1, LREAL, process, tag);
}

void Parallel::Communicator::receive(char *val, Int size, Int process,
                                     Int tag) const {
  this->receive(val, size, CHAR, process, tag);
}

void Parallel::Communicator::receive(unsigned char *val, Int size, Int process,
                                     Int tag) const {
  this->receive(val, size, UCHAR, process, tag);
}

void Parallel::Communicator::receive(bool *val, Int size, Int process,
                                     Int tag) const {
  this->receive(val, size, BOOL, process, tag);
}

void Parallel::Communicator::receive(short *val, Int size, Int process,
                                     Int tag) const {
  this->receive(val, size, SHORT, process, tag);
}

void Parallel::Communicator::receive(unsigned short *val, Int size, Int process,
                                     Int tag) const {
  this->receive(val, size, USHORT, process, tag);
}

void Parallel::Communicator::receive(Int *val, Int size, Int process,
                                     Int tag) const {
  this->receive(val, size, INT, process, tag);
}

void Parallel::Communicator::receive(UInt *val, Int size, Int process,
                                     Int tag) const {
  this->receive(val, size, UINT, process, tag);
}

void Parallel::Communicator::receive(LInt *val, Int size, Int process,
                                     Int tag) const {
  this->receive(val, size, LINT, process, tag);
}

void Parallel::Communicator::receive(ULInt *val, Int size, Int process,
                                     Int tag) const {
  this->receive(val, size, ULINT, process, tag);
}

void Parallel::Communicator::receive(Real *val, Int size, Int process,
                                     Int tag) const {
  this->receive(val, size, REAL, process, tag);
}

void Parallel::Communicator::receive(LReal *val, Int size, Int process,
                                     Int tag) const {
  this->receive(val, size, LREAL, process, tag);
}

Transferable *Parallel::Communicator::receive(Int process, Int tag) const {
  Package p = std::make_pair(0, static_cast<char *>(NULL));

  this->receive(&p.first, 1, INT, process, tag);

  p.second = new char[p.first];

  this->receive(p.second, p.first, PACKED, process, tag);

  return this->unpack(p, true);
}

UInt Parallel::Communicator::ireceive(char &val, Int process, Int tag) const {
  return this->ireceive(&val, 1, CHAR, process, tag);
}

UInt Parallel::Communicator::ireceive(unsigned char &val, Int process,
                                      Int tag) const {
  return this->ireceive(&val, 1, UCHAR, process, tag);
}

UInt Parallel::Communicator::ireceive(bool &val, Int process, Int tag) const {
  return this->ireceive(&val, 1, BOOL, process, tag);
}

UInt Parallel::Communicator::ireceive(short &val, Int process, Int tag) const {
  return this->ireceive(&val, 1, SHORT, process, tag);
}

UInt Parallel::Communicator::ireceive(unsigned short &val, Int process,
                                      Int tag) const {
  return this->ireceive(&val, 1, USHORT, process, tag);
}

UInt Parallel::Communicator::ireceive(Int &val, Int process, Int tag) const {
  return this->ireceive(&val, 1, INT, process, tag);
}

UInt Parallel::Communicator::ireceive(UInt &val, Int process, Int tag) const {
  return this->ireceive(&val, 1, UINT, process, tag);
}

UInt Parallel::Communicator::ireceive(LInt &val, Int process, Int tag) const {
  return this->ireceive(&val, 1, LINT, process, tag);
}

UInt Parallel::Communicator::ireceive(ULInt &val, Int process, Int tag) const {
  return this->ireceive(&val, 1, ULINT, process, tag);
}

UInt Parallel::Communicator::ireceive(Real &val, Int process, Int tag) const {
  return this->ireceive(&val, 1, REAL, process, tag);
}

UInt Parallel::Communicator::ireceive(LReal &val, Int process, Int tag) const {
  return this->ireceive(&val, 1, LREAL, process, tag);
}

UInt Parallel::Communicator::ireceive(char *val, Int size, Int process,
                                      Int tag) const {
  return this->ireceive(val, size, CHAR, process, tag);
}

UInt Parallel::Communicator::ireceive(unsigned char *val, Int size, Int process,
                                      Int tag) const {
  return this->ireceive(val, size, UCHAR, process, tag);
}

UInt Parallel::Communicator::ireceive(bool *val, Int size, Int process,
                                      Int tag) const {
  return this->ireceive(val, size, BOOL, process, tag);
}

UInt Parallel::Communicator::ireceive(short *val, Int size, Int process,
                                      Int tag) const {
  return this->ireceive(val, size, SHORT, process, tag);
}

UInt Parallel::Communicator::ireceive(unsigned short *val, Int size,
                                      Int process, Int tag) const {
  return this->ireceive(val, size, USHORT, process, tag);
}

UInt Parallel::Communicator::ireceive(Int *val, Int size, Int process,
                                      Int tag) const {
  return this->ireceive(val, size, INT, process, tag);
}

UInt Parallel::Communicator::ireceive(UInt *val, Int size, Int process,
                                      Int tag) const {
  return this->ireceive(val, size, UINT, process, tag);
}

UInt Parallel::Communicator::ireceive(LInt *val, Int size, Int process,
                                      Int tag) const {
  return this->ireceive(val, size, LINT, process, tag);
}

UInt Parallel::Communicator::ireceive(ULInt *val, Int size, Int process,
                                      Int tag) const {
  return this->ireceive(val, size, ULINT, process, tag);
}

UInt Parallel::Communicator::ireceive(Real *val, Int size, Int process,
                                      Int tag) const {
  return this->ireceive(val, size, REAL, process, tag);
}

UInt Parallel::Communicator::ireceive(LReal *val, Int size, Int process,
                                      Int tag) const {
  return this->ireceive(val, size, LREAL, process, tag);
}

UInt Parallel::Communicator::ireceive(Int process, Int tag) const {
  Package p = std::make_pair(0, static_cast<char *>(NULL));

  this->receive(&p.first, 1, INT, process, tag);

  p.second = new char[p.first];

  return this->ireceive(p.second, p.first, PACKED, process, tag);
}

char Parallel::Communicator::reduce(char val, enum Operation operation,
                                    Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  char buf = ' ';

  this->reduce(&val, &buf, 1, CHAR, operation, root);

  return buf;
}

unsigned char Parallel::Communicator::reduce(unsigned char val,
                                             enum Operation operation,
                                             Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  unsigned char buf = ' ';

  this->reduce(&val, &buf, 1, UCHAR, operation, root);

  return buf;
}

bool Parallel::Communicator::reduce(bool val, enum Operation operation,
                                    Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  bool buf = false;

  this->reduce(&val, &buf, 1, BOOL, operation, root);

  return buf;
}

short Parallel::Communicator::reduce(short val, enum Operation operation,
                                     Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  short buf = 0;

  this->reduce(&val, &buf, 1, SHORT, operation, root);

  return buf;
}

unsigned short Parallel::Communicator::reduce(unsigned short val,
                                              enum Operation operation,
                                              Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  unsigned short buf = 0;

  this->reduce(&val, &buf, 1, USHORT, operation, root);

  return buf;
}

Int Parallel::Communicator::reduce(Int val, enum Operation operation,
                                   Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  Int buf = 0;

  this->reduce(&val, &buf, 1, INT, operation, root);

  return buf;
}

UInt Parallel::Communicator::reduce(UInt val, enum Operation operation,
                                    Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  UInt buf = 0;

  this->reduce(&val, &buf, 1, UINT, operation, root);

  return buf;
}

LInt Parallel::Communicator::reduce(LInt val, enum Operation operation,
                                    Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  LInt buf = 0;

  this->reduce(&val, &buf, 1, LINT, operation, root);

  return buf;
}

ULInt Parallel::Communicator::reduce(ULInt val, enum Operation operation,
                                     Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  ULInt buf = 0;

  this->reduce(&val, &buf, 1, ULINT, operation, root);

  return buf;
}

Real Parallel::Communicator::reduce(Real val, enum Operation operation,
                                    Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  Real buf = 0.0;

  this->reduce(&val, &buf, 1, REAL, operation, root);

  return buf;
}

LReal Parallel::Communicator::reduce(LReal val, enum Operation operation,
                                     Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  LReal buf = 0.0;

  this->reduce(&val, &buf, 1, LREAL, operation, root);

  return buf;
}

char *Parallel::Communicator::reduce(const char *val, Int size,
                                     enum Operation operation, Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  char *buf = (root == this->rank()) ? new char[size] : NULL;

  this->reduce(val, buf, size, CHAR, operation, root);

  return buf;
}

unsigned char *Parallel::Communicator::reduce(const unsigned char *val,
                                              Int size,
                                              enum Operation operation,
                                              Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  unsigned char *buf = (root == this->rank()) ? new unsigned char[size] : NULL;

  this->reduce(val, buf, size, UCHAR, operation, root);

  return buf;
}

bool *Parallel::Communicator::reduce(const bool *val, Int size,
                                     enum Operation operation, Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  bool *buf = (root == this->rank()) ? new bool[size] : NULL;

  this->reduce(val, buf, size, BOOL, operation, root);

  return buf;
}

short *Parallel::Communicator::reduce(const short *val, Int size,
                                      enum Operation operation,
                                      Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  short *buf = (root == this->rank()) ? new short[size] : NULL;

  this->reduce(val, buf, size, SHORT, operation, root);

  return buf;
}

unsigned short *Parallel::Communicator::reduce(const unsigned short *val,
                                               Int size,
                                               enum Operation operation,
                                               Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  unsigned short *buf =
      (root == this->rank()) ? new unsigned short[size] : NULL;

  this->reduce(val, buf, size, USHORT, operation, root);

  return buf;
}

Int *Parallel::Communicator::reduce(const Int *val, Int size,
                                    enum Operation operation, Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  Int *buf = (root == this->rank()) ? new Int[size] : NULL;

  this->reduce(val, buf, size, INT, operation, root);

  return buf;
}

UInt *Parallel::Communicator::reduce(const UInt *val, Int size,
                                     enum Operation operation, Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  UInt *buf = (root == this->rank()) ? new UInt[size] : NULL;

  this->reduce(val, buf, size, UINT, operation, root);

  return buf;
}

LInt *Parallel::Communicator::reduce(const LInt *val, Int size,
                                     enum Operation operation, Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  LInt *buf = (root == this->rank()) ? new LInt[size] : NULL;

  this->reduce(val, buf, size, LINT, operation, root);

  return buf;
}

ULInt *Parallel::Communicator::reduce(const ULInt *val, Int size,
                                      enum Operation operation,
                                      Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  ULInt *buf = (root == this->rank()) ? new ULInt[size] : NULL;

  this->reduce(val, buf, size, ULINT, operation, root);

  return buf;
}

Real *Parallel::Communicator::reduce(const Real *val, Int size,
                                     enum Operation operation, Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  Real *buf = (root == this->rank()) ? new Real[size] : NULL;

  this->reduce(val, buf, size, REAL, operation, root);

  return buf;
}

LReal *Parallel::Communicator::reduce(const LReal *val, Int size,
                                      enum Operation operation,
                                      Int root) const {
  if (root < 0) {
    root = this->rank();
  }

  LReal *buf = (root == this->rank()) ? new LReal[size] : NULL;

  this->reduce(val, buf, size, LREAL, operation, root);

  return buf;
}

char Parallel::Communicator::allReduce(char val,
                                       enum Operation operation) const {
  char buf = ' ';

  this->allReduce(&val, &buf, 1, CHAR, operation);

  return buf;
}

unsigned char Parallel::Communicator::allReduce(
    unsigned char val, enum Operation operation) const {
  unsigned char buf = ' ';

  this->allReduce(&val, &buf, 1, UCHAR, operation);

  return buf;
}

bool Parallel::Communicator::allReduce(bool val,
                                       enum Operation operation) const {
  bool buf = false;

  this->allReduce(&val, &buf, 1, BOOL, operation);

  return buf;
}

short Parallel::Communicator::allReduce(short val,
                                        enum Operation operation) const {
  short buf = 0;

  this->allReduce(&val, &buf, 1, SHORT, operation);

  return buf;
}

unsigned short Parallel::Communicator::allReduce(
    unsigned short val, enum Operation operation) const {
  unsigned short buf = 0;

  this->allReduce(&val, &buf, 1, USHORT, operation);

  return buf;
}

Int Parallel::Communicator::allReduce(Int val, enum Operation operation) const {
  Int buf = 0;

  this->allReduce(&val, &buf, 1, INT, operation);

  return buf;
}

UInt Parallel::Communicator::allReduce(UInt val,
                                       enum Operation operation) const {
  UInt buf = 0;

  this->allReduce(&val, &buf, 1, UINT, operation);

  return buf;
}

LInt Parallel::Communicator::allReduce(LInt val,
                                       enum Operation operation) const {
  LInt buf = 0;

  this->allReduce(&val, &buf, 1, LINT, operation);

  return buf;
}

ULInt Parallel::Communicator::allReduce(ULInt val,
                                        enum Operation operation) const {
  ULInt buf = 0;

  this->allReduce(&val, &buf, 1, ULINT, operation);

  return buf;
}

Real Parallel::Communicator::allReduce(Real val,
                                       enum Operation operation) const {
  Real buf = 0.0;

  this->allReduce(&val, &buf, 1, REAL, operation);

  return buf;
}

LReal Parallel::Communicator::allReduce(LReal val,
                                        enum Operation operation) const {
  LReal buf = 0.0;

  this->allReduce(&val, &buf, 1, LREAL, operation);

  return buf;
}

char *Parallel::Communicator::allReduce(const char *val, Int size,
                                        enum Operation operation) const {
  char *buf = new char[size];

  this->allReduce(val, buf, size, CHAR, operation);

  return buf;
}

unsigned char *Parallel::Communicator::allReduce(
    const unsigned char *val, Int size, enum Operation operation) const {
  unsigned char *buf = new unsigned char[size];

  this->allReduce(val, buf, size, UCHAR, operation);

  return buf;
}

bool *Parallel::Communicator::allReduce(const bool *val, Int size,
                                        enum Operation operation) const {
  bool *buf = new bool[size];

  this->allReduce(val, buf, size, BOOL, operation);

  return buf;
}

short *Parallel::Communicator::allReduce(const short *val, Int size,
                                         enum Operation operation) const {
  short *buf = new short[size];

  this->allReduce(val, buf, size, SHORT, operation);

  return buf;
}

unsigned short *Parallel::Communicator::allReduce(
    const unsigned short *val, Int size, enum Operation operation) const {
  unsigned short *buf = new unsigned short[size];

  this->allReduce(val, buf, size, USHORT, operation);

  return buf;
}

Int *Parallel::Communicator::allReduce(const Int *val, Int size,
                                       enum Operation operation) const {
  Int *buf = new Int[size];

  this->allReduce(val, buf, size, INT, operation);

  return buf;
}

UInt *Parallel::Communicator::allReduce(const UInt *val, Int size,
                                        enum Operation operation) const {
  UInt *buf = new UInt[size];

  this->allReduce(val, buf, size, UINT, operation);

  return buf;
}

LInt *Parallel::Communicator::allReduce(const LInt *val, Int size,
                                        enum Operation operation) const {
  LInt *buf = new LInt[size];

  this->allReduce(val, buf, size, LINT, operation);

  return buf;
}

ULInt *Parallel::Communicator::allReduce(const ULInt *val, Int size,
                                         enum Operation operation) const {
  ULInt *buf = new ULInt[size];

  this->allReduce(val, buf, size, ULINT, operation);

  return buf;
}

Real *Parallel::Communicator::allReduce(const Real *val, Int size,
                                        enum Operation operation) const {
  Real *buf = new Real[size];

  this->allReduce(val, buf, size, REAL, operation);

  return buf;
}

LReal *Parallel::Communicator::allReduce(const LReal *val, Int size,
                                         enum Operation operation) const {
  LReal *buf = new LReal[size];

  this->allReduce(val, buf, size, LREAL, operation);

  return buf;
}

char *Parallel::Communicator::reduceScatter(const char *val,
                                            enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = 1;
  }

  char *buf = new char[count];

  this->reduceScatter(val, buf, counts, CHAR, operation);

  return buf;
}

unsigned char *Parallel::Communicator::reduceScatter(
    const unsigned char *val, enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = 1;
  }

  unsigned char *buf = new unsigned char[count];

  this->reduceScatter(val, buf, counts, UCHAR, operation);

  return buf;
}

bool *Parallel::Communicator::reduceScatter(const bool *val,
                                            enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = 1;
  }

  bool *buf = new bool[count];

  this->reduceScatter(val, buf, counts, BOOL, operation);

  return buf;
}

short *Parallel::Communicator::reduceScatter(const short *val,
                                             enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = 1;
  }

  short *buf = new short[count];

  this->reduceScatter(val, buf, counts, SHORT, operation);

  return buf;
}

unsigned short *Parallel::Communicator::reduceScatter(
    const unsigned short *val, enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = 1;
  }

  unsigned short *buf = new unsigned short[count];

  this->reduceScatter(val, buf, counts, USHORT, operation);

  return buf;
}

Int *Parallel::Communicator::reduceScatter(const Int *val,
                                           enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = 1;
  }

  Int *buf = new Int[count];

  this->reduceScatter(val, buf, counts, INT, operation);

  return buf;
}

UInt *Parallel::Communicator::reduceScatter(const UInt *val,
                                            enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = 1;
  }

  UInt *buf = new UInt[count];

  this->reduceScatter(val, buf, counts, UINT, operation);

  return buf;
}

LInt *Parallel::Communicator::reduceScatter(const LInt *val,
                                            enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = 1;
  }

  LInt *buf = new LInt[count];

  this->reduceScatter(val, buf, counts, LINT, operation);

  return buf;
}

ULInt *Parallel::Communicator::reduceScatter(const ULInt *val,
                                             enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = 1;
  }

  ULInt *buf = new ULInt[count];

  this->reduceScatter(val, buf, counts, ULINT, operation);

  return buf;
}

Real *Parallel::Communicator::reduceScatter(const Real *val,
                                            enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = 1;
  }

  Real *buf = new Real[count];

  this->reduceScatter(val, buf, counts, REAL, operation);

  return buf;
}

LReal *Parallel::Communicator::reduceScatter(const LReal *val,
                                             enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = 1;
  }

  LReal *buf = new LReal[count];

  this->reduceScatter(val, buf, counts, LREAL, operation);

  return buf;
}

char *Parallel::Communicator::reduceScatter(const char *val, Int size,
                                            enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = size;
  }

  count *= size;

  char *buf = new char[count];

  this->reduceScatter(val, buf, counts, CHAR, operation);

  return buf;
}

unsigned char *Parallel::Communicator::reduceScatter(
    const unsigned char *val, Int size, enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = size;
  }

  count *= size;

  unsigned char *buf = new unsigned char[count];

  this->reduceScatter(val, buf, counts, UCHAR, operation);

  return buf;
}

bool *Parallel::Communicator::reduceScatter(const bool *val, Int size,
                                            enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = size;
  }

  count *= size;

  bool *buf = new bool[count];

  this->reduceScatter(val, buf, counts, BOOL, operation);

  return buf;
}

short *Parallel::Communicator::reduceScatter(const short *val, Int size,
                                             enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = size;
  }

  count *= size;

  short *buf = new short[count];

  this->reduceScatter(val, buf, counts, SHORT, operation);

  return buf;
}

unsigned short *Parallel::Communicator::reduceScatter(
    const unsigned short *val, Int size, enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = size;
  }

  count *= size;

  unsigned short *buf = new unsigned short[count];

  this->reduceScatter(val, buf, counts, USHORT, operation);

  return buf;
}

Int *Parallel::Communicator::reduceScatter(const Int *val, Int size,
                                           enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = size;
  }

  count *= size;

  Int *buf = new Int[count];

  this->reduceScatter(val, buf, counts, INT, operation);

  return buf;
}

UInt *Parallel::Communicator::reduceScatter(const UInt *val, Int size,
                                            enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = size;
  }

  count *= size;

  UInt *buf = new UInt[count];

  this->reduceScatter(val, buf, counts, UINT, operation);

  return buf;
}

LInt *Parallel::Communicator::reduceScatter(const LInt *val, Int size,
                                            enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = size;
  }

  count *= size;

  LInt *buf = new LInt[count];

  this->reduceScatter(val, buf, counts, LINT, operation);

  return buf;
}

ULInt *Parallel::Communicator::reduceScatter(const ULInt *val, Int size,
                                             enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = size;
  }

  count *= size;

  ULInt *buf = new ULInt[count];

  this->reduceScatter(val, buf, counts, ULINT, operation);

  return buf;
}

Real *Parallel::Communicator::reduceScatter(const Real *val, Int size,
                                            enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = size;
  }

  count *= size;

  Real *buf = new Real[count];

  this->reduceScatter(val, buf, counts, REAL, operation);

  return buf;
}

LReal *Parallel::Communicator::reduceScatter(const LReal *val, Int size,
                                             enum Operation operation) const {
  Int count = this->numProcesses();

  Int counts[count];

  for (Int i = 0; i < count; i++) {
    counts[i] = size;
  }

  count *= size;

  LReal *buf = new LReal[count];

  this->reduceScatter(val, buf, counts, LREAL, operation);

  return buf;
}

Transferable *Parallel::Communicator::unpack(Package &p,
                                             bool freeUponSuccess) const {
  Transferable *t = this->unpack(p);

  if ((t) && (freeUponSuccess)) {
    t->free(p);

    p.first = 0;
    p.second = NULL;
  }

  return t;
}
