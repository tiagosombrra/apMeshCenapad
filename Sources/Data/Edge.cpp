#include "../../Headers/Data/Edge.h"

Edge::Edge(Vertex *v1, Vertex *v2, long int id) : Shape(id) {
  mid = vector = NULL;

  xmax = ymax = DBL_MAX;
  xmin = ymin = DBL_MIN;

  len = -1.0;

  setVertices(v1, v2);
  setCell(NULL);
  setFree(true);
  setInBoundary(false);
  setCurva(NULL);
  //#if USE_OPENGL
  //    setWidth(1.0);
  //    //figura
  //    //setColor(1.0, 1.0, 1.0);
  //    setColor(0.0, 0.0, 0.0);
  //    //endfigura
  //#endif //#if USE_OPENGL
}

Edge::~Edge() {
  if (v[0]) {
    delete v[0];
  }
  if (v[1]) delete v[1];
  if (mid) delete mid;
  if (vector) delete vector;
}

Vertex *Edge::makeMid() {
  Vertex *v = new Vertex();

  if (this->v[0] && this->v[1]) {
    v->setPosition((this->v[0]->getX() + this->v[1]->getX()) / 2.0,
                   (this->v[0]->getY() + this->v[1]->getY()) / 2.0);
  }

  return v;
}

Vertex *Edge::makeVector() {
  Vertex *v = new Vertex();

  if (this->v[0] && this->v[1]) {
    v->setPosition(this->v[1]->getX() - this->v[0]->getX(),
                   this->v[1]->getY() - this->v[0]->getY());
  }

  return v;
}

void Edge::setV1(Vertex *v) { this->v[0] = v; }

void Edge::setV2(Vertex *v) { this->v[1] = v; }

void Edge::setVertices(Vertex *v1, Vertex *v2) {
  setV1(v1);
  setV2(v2);

  if (v1 && v2) {
    if (v1->getX() > v2->getX()) {
      xmin = v2->getX();
      xmax = v1->getX();
    } else {
      xmin = v1->getX();
      xmax = v2->getX();
    }

    if (v1->getY() > v2->getY()) {
      ymin = v2->getY();
      ymax = v1->getY();
    } else {
      ymin = v1->getY();
      ymax = v2->getY();
    }
  }

  if (mid) {
    delete mid;

    mid = NULL;
  }

  if (vector) {
    delete vector;

    vector = NULL;
  }

  mid = makeMid();
  vector = makeVector();
}

Vertex *Edge::getV1() { return v[0]; }

Vertex *Edge::getV2() { return v[1]; }

void Edge::setInBoundary(bool inBoundary) { this->inBoundary = inBoundary; }

bool Edge::isInBoundary() { return inBoundary; }

//#if USE_OPENGL
// void Edge::setWidth(double width)
//{
//    this->width = width;
//}
//#endif //#if USE_OPENGL

void Edge::setFree(bool free) { this->free = free; }

bool Edge::isFree() { return free; }

void Edge::setCell(QuadtreeCell *cell) { this->cell = cell; }

QuadtreeCell *Edge::getCell() { return cell; }

Vertex *Edge::getMid() { return mid; }

double Edge::length() { return vector->norm(); }

bool Edge::intercept(Edge *e) { return intercept(e->v[0], e->v[1]); }

bool Edge::intercept(Vertex *va, Vertex *vb) {
  /*if ((va == v[0]) || (va == v[1]) || (vb == v[0]) || (vb == v[1]))
  {
      return false;
  }*/

  // teste de bounding boxes
  /*static*/ double exmin, exmax, eymin, eymax;

  if (va->getX() >= vb->getX()) {
    exmax = va->getX();
    exmin = vb->getX();
  } else {
    exmax = vb->getX();
    exmin = va->getX();
  }

  /*//testa se os intervalos das bounding boxes se interceptam no eixo x
  if (((txmin < exmin) || (txmin > exmax)) &&
      ((txmax < exmin) || (txmax > exmax)))
  {
      return false;
  }*/

  if ((xmin > exmax) || (xmax < exmin)) {
    return false;
  }

  if (va->getY() >= vb->getY()) {
    eymax = va->getY();
    eymin = vb->getY();
  } else {
    eymax = vb->getY();
    eymin = va->getY();
  }

  if ((ymin > eymax) || (ymax < eymin)) {
    return false;
  }

  // teste de intersecao
  /*static*/ Vertex ab, ac, ad, cd, ca, cb;
  /*static*/ double tivx, tivy, tfvx, tfvy, eivx, eivy, efvx, efvy;

  tivx = v[0]->getX();
  tivy = v[0]->getY();
  tfvx = v[1]->getX();
  tfvy = v[1]->getY();

  eivx = va->getX();
  eivy = va->getY();
  efvx = vb->getX();
  efvy = vb->getY();

  ab.setPosition(tfvx - tivx, tfvy - tivy);
  ac.setPosition(eivx - tivx, eivy - tivy);
  ad.setPosition(efvx - tivx, efvy - tivy);

  cd.setPosition(efvx - eivx, efvy - eivy);
  ca.setPosition(tivx - eivx, tivy - eivy);
  cb.setPosition(tfvx - eivx, tfvy - eivy);

  return ((ab.cross(&ac) * ab.cross(&ad) < 0) &&
          (cd.cross(&ca) * cd.cross(&cb) < 0));
}

bool Edge::intercept(Vertex *v) {
  return (distance(v) < TOLERANCIA_AFT);

  /*static Vertex ac, bc;

  ac.setPosition(v->getX() - this->v[0]->getX(), v->getY() -
  this->v[0]->getY()); bc.setPosition(v->getX() - this->v[1]->getX(), v->getY()
  - this->v[1]->getY());

  return ((ac.dot(vector) > 0.0) &&
          (ac.dot(vector) > 0.0) &&
          (straightDistance(v) > tolerance));*/

  /*static double distAB;

  distAB = length() + tolerance;

  return ((fabs(vector->cross(&ac)) < tolerance) &&
          (this->v[0]->distance(v) <= distAB) &&
          (this->v[1]->distance(v) <= distAB));*/
}

bool Edge::intercept(double x, double y) {
  /*static*/ Vertex v;

  v.setPosition(x, y);

  return intercept(&v);
}

double Edge::straightDistance(Vertex *v) {
  return 2.0 * v->surface(this->v[0], this->v[1]) / length();

  /*static Vertex w, p;
  static double c1, c2, b;

  w.setPosition(v->getX() - this->v[0]->getX(), v->getY() - this->v[0]->getY());

  c1 = w.dot(vector);
  c2 = vector->dot(vector);

  if (c2 <= tolerance)
  {
      return -1.0;
  }

  b = c1/c2;

  p.setPosition(this->v[0]->getX() + b*vector->getX(), this->v[0]->getY() +
  b*vector->getY());

  return p.distance(v);*/
}

double Edge::distance(Vertex *v) {
  /*static*/ Vertex ac, vec;

  ac.setPosition(v->getX() - this->v[0]->getX(),
                 v->getY() - this->v[0]->getY());
  vec.setPosition(this->v[1]->getX() - this->v[0]->getX(),
                  this->v[1]->getY() - this->v[0]->getY());

  ac.scalarMultiplication(1.0 / ac.norm());
  vec.scalarMultiplication(1.0 / vec.norm());

  if (ac.dot(&vec) < TOLERANCIA_AFT) {
    return this->v[0]->distance(v);
  }

  ac.setPosition(v->getX() - this->v[1]->getX(),
                 v->getY() - this->v[1]->getY());

  ac.scalarMultiplication(1.0 / ac.norm());
  vec.scalarMultiplication(-1.0);

  if (ac.dot(&vec) < TOLERANCIA_AFT) {
    return this->v[1]->distance(v);
  }

  return straightDistance(v);

  /*static Vertex w, p;
  static double c1, c2, b;

  w.setPosition(v->getX() - this->v[0]->getX(), v->getY() - this->v[0]->getY());

  c1 = w.dot(vector);
  c2 = vector->dot(vector);

  if (c1 < 0.0)
  {
      return this->v[0]->distance(v);
  }

  if (c1 > c2)
  {
      return this->v[1]->distance(v);
  }

  b = c1/c2;

  p.setPosition(this->v[0]->getX() + b*vector->getX(), this->v[0]->getY() +
  b*vector->getY());

  return p.distance(v);*/

  /*if (c1 <= tolerance)
  {
      return this->v[0]->distance(v);
  }
  else if (c2 <= c1)
  {
      return this->v[1]->distance(v);
  }
  else
  {
      b = c1/c2;

      p.setPosition(this->v[0]->getX() + b*vector->getX(), this->v[0]->getY() +
  b*vector->getY());

      return p.distance(v);
  }*/

  //    double ivx, ivy, fvx, fvy, vx, vy;
  //    ivx = v[0]->getX();
  //    ivy = v[0]->getY();
  //    fvx = v[1]->getX();
  //    fvy = v[1]->getY();
  //    vx = v->getX();
  //    vy = v->getY();
  //
  //    if (((ivx == vx) && (ivy == vy)) ||
  //        ((fvx == vx) && (fvy == vy)) ||
  //        ((ivy - vy)*(fvx - vx) == (fvy - vy)*(ivx - vx)))
  //    {
  //        return 0.0;
  //    }
  //
  //    double t = (vx - ivx)/(fvx - ivx);
  //    double y = (ivy + (fvy - ivy)*t);
  //
  //    if (y == vy)
  //    {
  //        if (t < 0.0)
  //        {
  //            return v[0]->distance(v);
  //        }
  //        else if (t > 1.0)
  //        {
  //            return v[1]->distance(v);
  //        }
  //        else
  //        {
  //            return 0.0;
  //        }
  //    }
  //
  //    Edge *e1 = new Edge(0, v[0], v);
  //    Edge *e2 = new Edge(0, v, v[1]);
  //
  //    if (angle(e1) >= M_PI/2.0)
  //    {
  //        return v[0]->distance(v);
  //    }
  //
  //    if (angle(e2) >= M_PI/2.0)
  //    {
  //        return v[1]->distance(v);
  //    }
  //
  //    double l1 = e1->length();
  //    double l2 = e2->length();
  //    double l = length();
  //
  //    if (l1+l2 - l < 0.001)
  //    {
  //        return 0.0;
  //    }
  //
  //    double l1l1 = l1*l1;
  //    double l2l2 = l2*l2;
  //
  //    double m = (l*l - (l2l2 - l1l1))/(2.0*l);
  //
  //    double val = l1l1 - m*m;
  //    double d = val < 0.0 ? 0.0 : sqrt(val);
  //
  //    delete e1;
  //    delete e2;
  //
  //    return d;
}

double Edge::distance(double x, double y) {
  /*static*/ Vertex v;

  v.setPosition(x, y);

  return distance(&v);
}

double Edge::dot(Vertex *v) {
  /*static*/ Vertex vAux;

  vAux.setPosition(v->getX() - this->v[0]->getX(),
                   v->getY() - this->v[0]->getY());

  return vector->dot(&vAux);
}

bool Edge::left(Vertex *v) { return left(v->getX(), v->getY()); }

bool Edge::left(double x, double y) {
  /*static*/ Vertex vAux;

  vAux.setPosition(x - this->v[0]->getX(), y - this->v[0]->getY());

  return vAux.right(vector);
}

bool Edge::right(Vertex *v) { return right(v->getX(), v->getY()); }

bool Edge::right(double x, double y) {
  /*static*/ Vertex vAux;

  vAux.setPosition(x - this->v[0]->getX(), y - this->v[0]->getY());

  return vAux.left(vector);
}

bool Edge::accordingToNormal(Vertex *v, bool inEdgeTest) {
  if (inEdgeTest) {
    return !right(v);
  }

  return left(v);
}

double Edge::angle(Edge *e) {
  /*static*/ Vertex va, vb, vc;

  if (v[0]->matches(e->v[0])) {
    va = *v[0];
    vb = *v[1];
    vc = *(e->v[1]);
  } else if (v[0]->matches(e->v[1])) {
    va = *v[0];
    vb = *v[1];
    vc = *(e->v[0]);
  } else if (v[1]->matches(e->v[0])) {
    va = *v[1];
    vb = *v[0];
    vc = *(e->v[1]);
  } else if (v[1]->matches(e->v[1])) {
    va = *v[1];
    vb = *v[0];
    vc = *(e->v[0]);
  } else {
    return -1.0;
  }

  vb.setPosition(vb.getX() - va.getX(), vb.getY() - va.getY());
  vc.setPosition(vc.getX() - va.getX(), vc.getY() - va.getY());

  return vb.angle(&vc);
}

double Edge::angle(Vertex *va, Vertex *vb) {
  /*static*/ Edge e;
  /*static*/ double result;

  e.setVertices(va, vb);

  result = angle(&e);

  e.setVertices(NULL, NULL);

  return result;
}

Vertex *Edge::normal() {
  Vertex *normal = new Vertex();

  if (v[0]->matches(v[1])) {
    normal->setPosition(0.0, 0.0);
  } else if (v[0]->getX() == v[1]->getX()) {
    if (v[0]->getY() > v[1]->getY()) {
      normal->setPosition(1.0, 0.0);
    } else {
      normal->setPosition(-1.0, 0.0);
    }
  } else if (v[0]->getY() == v[1]->getY()) {
    if (v[0]->getX() > v[1]->getX()) {
      normal->setPosition(0.0, -1.0);
    } else {
      normal->setPosition(0.0, 1.0);
    }
  } else {
    normal->setPosition(v[0]->getY() - v[1]->getY(),
                        v[1]->getX() - v[0]->getX());

    double n = normal->norm();

    normal->setPosition(normal->getX() / n, normal->getY() / n);
  }

  return normal;
}

bool Edge::equals(Edge *e) {
  return (((v[0] == e->v[0]) && (v[1] == e->v[1])) ||
          ((v[0] == e->v[1]) && (v[1] == e->v[0])));
}

bool Edge::equals(Vertex *v1, Vertex *v2) {
  return (((this->v[0] == v1) && (this->v[1] == v2)) ||
          ((this->v[0] == v2) && (this->v[1] == v1)));
}

bool Edge::matches(Edge *e) { return ((v[0] == e->v[0]) && (v[1] == e->v[1])); }

bool Edge::matches(Vertex *v1, Vertex *v2) {
  return ((this->v[0] == v1) && (this->v[1] == v2));
}

void Edge::setCurva(CurvaParametrica *c) { this->c = c; }

void Edge::setLen(double len) { this->len = len; }

double Edge::getLen() { return len; }

void Edge::makeParamMid() {
  if (!c) {
    return;
  }

  if (mid) {
    delete mid;

    mid = NULL;
  }

  double t = -1.0;

  if ((v[0]->getY() == 0.0) && (v[0]->getX() < 1.0)) {
    // curva 1
    // Ponto p = c->pontoMedio(v[0]->getX(), v[1]->getX());

    t = c->pontoMedio(v[0]->getX(), v[1]->getX());

    mid = new Vertex(t, 0.0);

    len = c->comprimento(v[0]->getX(), v[1]->getX()) / c->get_L();
  } else if ((v[0]->getX() == 1.0) && (v[0]->getY() < 1.0)) {
    // curva 2
    // Ponto p = c->pontoMedio(v[0]->getY(), v[1]->getY());

    t = c->pontoMedio(v[0]->getY(), v[1]->getY());

    mid = new Vertex(1.0, t);

    len = c->comprimento(v[0]->getY(), v[1]->getY()) / c->get_L();
  } else if ((v[0]->getY() == 1.0) && (v[0]->getX() > 0.0)) {
    // curva 3
    // Ponto p = c->pontoMedio(v[0]->getX(), v[1]->getX());

    t = c->pontoMedio(v[1]->getX(), v[0]->getX());

    mid = new Vertex(t, 1.0);

    len = c->comprimento(v[1]->getX(), v[0]->getX()) / c->get_L();
  } else if ((v[0]->getX() == 0.0) && (v[0]->getY() > 0.0)) {
    // curva 4
    // Ponto p = c->pontoMedio(v[0]->getY(), v[1]->getY());

    t = c->pontoMedio(v[1]->getY(), v[0]->getY());

    mid = new Vertex(0.0, t);

    len = c->comprimento(v[1]->getY(), v[0]->getY()) / c->get_L();
  } else {
    mid = makeMid();

    len = -1.0;
  }
}

string Edge::getText() {
  ostringstream stream;

  stream << id << " " << v[0]->getId() << " " << v[1]->getId();

  string s = stream.str();

  return s;
}

//#if USE_OPENGL
// void Edge::highlight()
//{
//    highlight(true);
//}

// void Edge::highlight(bool highlightCell)
//{
//     width = 3.0;

//    if (highlightCell && cell)
//    {
//        cell->highlight(false);
//    }
//}

// void Edge::unhighlight()
//{
//     unhighlight(true);
// }

// void Edge::unhighlight(bool unhighlightCell)
//{
//     width = 1.0;

//    if (unhighlightCell && cell)
//    {
//        cell->unhighlight(false);
//    }
//}

// void Edge::draw()
//{
//     glLineWidth(width);

//    glColor3d(r, g, b);
//    glBegin(GL_LINES);
//    glVertex2d(v[0]->getX(), v[0]->getY());
//    glVertex2d(v[1]->getX(), v[1]->getY());
//    glEnd();

//    glLineWidth(1.0);
//}

// void Edge::drawNormal()
//{
//     glLineWidth(1.0);

//    Vertex *normal = this->normal();
//    normal->scalarMultiplication(1.0/normal->norm()*length()/10.0);
//    normal->sum(mid);

//    glColor3d(r, g, b);
//    glBegin(GL_LINES);
//    glVertex2d(mid->getX(), mid->getY());
//    glVertex2d(normal->getX(), normal->getY());
//    glEnd();

//    delete normal;
//}
//#endif //#if USE_OPENGL
