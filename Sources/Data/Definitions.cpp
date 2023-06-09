#include "../../Headers/Data/Definitions.h"

#include <cstdio>
#include <cstdlib>

#if defined(__linux__)
#include <execinfo.h>
#include <unistd.h>
#endif  //#if defined(__linux__)

//#include "Data/State.h"
//#include "Data/Exact.h"

//#if USE_POOL
//#include "Data/Point2D.h"
//#include "Data/Point3D.h"
//#include "Data/Triangle2D.h"
//#include "Data/Tetrahedron.h"
//#include "Data/Box.h"
//#include "Data/FrontElementBoxSearchTreeCell.h"
//#include "Data/VertexBoxSearchTreeCell.h"
//#endif //#if USE_POOL

#if USE_TIMING
#if defined(__linux__)
#include <sys/time.h>
#elif USE_OPENMP
#include <omp.h>
#else
#include <ctime>
#endif  //#if defined(__linux__)
#endif  //#if USE_TIMING

//#include "Data/OStream.h"

using namespace Data;

void printBuffer(void *buffer, int size) {
  char *c;
  int counter = 0;
  int i;
  for (i = 2; i < size + 2; i++) {
    c = (char *)buffer + i;
    if (*c != '\0') {
      printf("%c", *c);
      counter++;
    } else {
      printf("NULL ");
    }
  }
}

std::string Data::trace(int maxLines) {
  std::stringstream str;

  void *buffer[20];

  int nptrs = backtrace(buffer, 20);

  char **strings = backtrace_symbols(buffer, nptrs);

  if (maxLines > 0) {
    nptrs = maxLines + 1;
  }

  printBuffer(buffer[0], nptrs);

  // starts from 1 to hide the call to the trace() function
  for (int i = 1; i < nptrs; i++) {
    std::stringstream stmp;
    stmp << strings[i];
    stmp << buffer[i];
    std::string trimmed = Data::trim(stmp.str());

    if (!trimmed.empty()) {
      str << trimmed << std::endl;
    }
  }

  free(strings);

  return str.str();
}

#if USE_TIMING
Real Data::time() {
#if defined(__linux__)
  struct timeval t;
  gettimeofday(&t, NULL);
  return static_cast<Real>(t.tv_sec) + static_cast<Real>(t.tv_usec) * 0.000001;
#elif ((USE_OPENMP) && (defined(_OPENMP)))
  return static_cast<Real>(omp_get_wtime());
#else
  return static_cast<Real>(time(NULL));
#endif  //#if defined(__linux__)
}
#endif  //#if USE_TIMING

std::string Data::time(Real seconds) {
  return Data::time(static_cast<UInt>(seconds));
}

std::string Data::time(UInt seconds) {
  UInt secs = seconds;
  UInt mins = secs / 60;
  UInt hours = mins / 60;

  secs = secs % 60;
  mins = mins % 60;

  return Data::time(hours, mins, secs);
}

std::string Data::time(Real hours, Real mins, Real secs) {
  return Data::time(static_cast<UInt>(hours), static_cast<UInt>(mins),
                    static_cast<UInt>(secs));
}

std::string Data::time(UInt hours, UInt mins, UInt secs) {
  std::stringstream str;

  str << hours << ":";

  if (mins < 10) {
    str << "0";
  }

  str << mins << ":";

  if (secs < 10) {
    str << "0";
  }

  str << secs;

  return str.str();
}

#if defined(__linux__)
// code for trim() functions from
// http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
void Data::ltrim(std::string &s) {
  s.erase(s.begin(),
          std::find_if(s.begin(), s.end(),
                       std::not1(std::ptr_fun<int, int>(std::isspace))));
}

void Data::rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(),
                       std::not1(std::ptr_fun<int, int>(std::isspace)))
              .base(),
          s.end());
}

void Data::trim(std::string &s) {
  rtrim(s);
  ltrim(s);
}

std::string Data::ltrim(const std::string &s) {
  std::string tmp = s;

  ltrim(tmp);

  return tmp;
}

std::string Data::rtrim(const std::string &s) {
  std::string tmp = s;

  rtrim(tmp);

  return tmp;
}

std::string Data::trim(const std::string &s) {
  std::string tmp = s;

  trim(tmp);

  return tmp;
}
#endif  //#if defined(__linux__)

std::string Data::position(enum Position pos) {
  switch (pos) {
    case UNKNOWN:
      return "unknown";

    case IN:
      return "in";

    case ON:
      return "on";

    case OUT:
      return "out";
  }

  return "other";
}

#if USE_BUFFER
void Data::setBuffer(const std::string &buffer) {
  Data::state.setBuffer(buffer);
}

const std::string &Data::getBuffer() { return Data::state.getBuffer(); }
#endif  //#if USE_BUFFER

#if USE_GUI
void Data::setStepByStep(bool stepByStep) {
  Data::state.setStepByStep(stepByStep);
}

bool Data::isStepByStep() { return Data::state.isStepByStep(); }

void Data::glColor(Real r, Real g, Real b) {
#if USE_DOUBLE
  glColor3d(r, g, b);
#else   //#if USE_DOUBLE
  glColor3f(r, g, b);
#endif  //#if USE_DOUBLE

  GLfloat amb[] = {0.2f, 0.2f, 0.2f, 1.0f};
  GLfloat col[] = {static_cast<GLfloat>(r), static_cast<GLfloat>(g),
                   static_cast<GLfloat>(b), 1.0};

  // glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, col);
  glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, col);
}

void Data::glColor(Real r, Real g, Real b, Real a) {
#if USE_DOUBLE
  glColor4d(r, g, b, a);
#else   //#if USE_DOUBLE
  glColor4f(r, g, b, a);
#endif  //#if USE_DOUBLE

  GLfloat amb[] = {0.2f, 0.2f, 0.2f, static_cast<GLfloat>(a)};
  GLfloat col[] = {static_cast<GLfloat>(r), static_cast<GLfloat>(g),
                   static_cast<GLfloat>(b), static_cast<GLfloat>(a)};

  // glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, col);
  glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, col);
}

void Data::glVertex(Real x, Real y) {
#if USE_DOUBLE
  glVertex2d(x, y);
#else   //#if USE_DOUBLE
  glVertex2f(x, y);
#endif  //#if USE_DOUBLE
}

void Data::glVertex(Real x, Real y, Real z) {
#if USE_DOUBLE
  glVertex3d(x, y, z);
#else   //#if USE_DOUBLE
  glVertex3f(x, y, z);
#endif  //#if USE_DOUBLE
}

void Data::glNormal(Real x, Real y, Real z) {
#if USE_DOUBLE
  glNormal3d(x, y, z);
#else   //#if USE_DOUBLE
  glNormal3f(x, y, z);
#endif  //#if USE_DOUBLE
}

void Data::glTranslate(Real x, Real y) { glTranslate(x, y, 0.0); }

void Data::glTranslate(Real x, Real y, Real z) {
#if USE_DOUBLE
  glTranslated(x, y, z);
#else   //#if USE_DOUBLE
  glTranslatef(x, y, z);
#endif  //#if USE_DOUBLE
}

void Data::glScale(Real x, Real y) { glScale(x, y, 1.0); }

void Data::glScale(Real x, Real y, Real z) {
#if USE_DOUBLE
  glScaled(x, y, z);
#else   //#if USE_DOUBLE
  glScalef(x, y, z);
#endif  //#if USE_DOUBLE
}

void Data::glText(Real x, Real y, const std::string &text) {
  glText(x, y, 0.0, text);
}

void Data::glText(Real x, Real y, Real z, const std::string &text) {
  void *font = getState().getGlutFont();

  if (!font) {
    return;
  }

#if USE_DOUBLE
  glRasterPos3d(x, y, z);
  // glWindowPos3d(x, y, z);
#else
  glRasterPos3f(x, y, z);
  // glWindowPos3f(x, y, z);
#endif  //#if USE_DOUBLE

  const char *s = text.c_str();

  /*GLboolean lighting = 0;

  glGetBooleanv(GL_LIGHTING, &lighting);

  if (lighting)
  {
          glDisable(GL_LIGHTING);
  }*/

  for (UInt i = 0; i < text.size(); i++, s++) {
    glutBitmapCharacter(font, *s);
  }

  /*if (lighting)
  {
          glEnable(GL_LIGHTING);
  }*/
}

UInt Data::glTextWidth(const std::string &text) {
  void *font = getState().getGlutFont();

  if (!font) {
    return 0;
  }

  UInt width = 0;

  const char *s = text.c_str();

  for (UInt i = 0; i < text.size(); i++, s++) {
    width += static_cast<UInt>(glutBitmapWidth(font, *s));
  }

  return width;
}

void Data::glTextId(Real x, Real y, ULInt id) { glTextId(x, y, 0.0, id); }

void Data::glTextId(Real x, Real y, Real z, ULInt id) {
  glText(x, y, z, convert(id));
}

void Data::pallete(Int index, Real &r, Real &g, Real &b) {
  r = g = b = 0.0;

  if (index < 0) {
#if (!USE_SCREENSHOT)
    r = g = b = 1.0;
#endif  //#if (!USE_SCREENSHOT)

    return;
  }

  switch (index % 25) {
    case 0:
      r = 1.0;
      break;
    case 1:
      g = 1.0;
      break;
    case 2:
      b = 1.0;
      break;
    case 3:
      r = g = 1.0;
      break;
    case 4:
      r = b = 1.0;
      break;
    case 5:
      b = g = 1.0;
      break;
    case 6:
      r = 0.5;
      break;
    case 7:
      g = 0.5;
      break;
    case 8:
      b = 0.5;
      break;
    case 9:
      r = g = 0.5;
      break;
    case 10:
      r = b = 0.5;
      break;
    case 11:
      g = b = 0.5;
      break;
    case 12:
      r = g = b = 0.5;
      break;
    case 13:
      r = 1.0;
      g = 0.5;
      break;
    case 14:
      r = 1.0;
      b = 0.5;
      break;
    case 15:
      r = 0.5;
      g = 1.0;
      break;
    case 16:
      r = 0.5;
      b = 1.0;
      break;
    case 17:
      g = 1.0;
      b = 0.5;
      break;
    case 18:
      g = 0.5;
      b = 1.0;
      break;
    case 19:
      r = g = 1.0;
      b = 0.5;
      break;
    case 20:
      r = b = 1.0;
      g = 0.5;
      break;
    case 21:
      r = 0.5;
      g = b = 1.0;
      break;
    case 22:
      r = 1.0;
      g = b = 0.5;
      break;
    case 23:
      g = 1.0;
      r = b = 0.5;
      break;
    case 24:
      b = 1.0;
      r = g = 0.5;
      break;
  }
}
#endif  //#if USE_GUI
