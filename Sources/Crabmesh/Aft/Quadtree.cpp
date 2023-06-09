#include "../../../Headers/Crabmesh/Aft/Quadtree.h"

void escreve(Quadtree *q, int i) {
  static int passo = 0;

  string s;

  if (i == 1) {
    s = "borda";
    passo++;
  } else if (i == 2)
    s = "interior";
  else if (i == 3)
    s = "restrita";

  stringstream nome;
  nome << passo;
  nome << "quadtree_";
  nome << s;
  nome << ".pos";

  ofstream arq(nome.str().c_str());

  arq << "%HEADER" << endl
      << "Arquivo da quadtree gerado pelo gerador de malhas de superficie do "
         "Daniel Siqueira"
      << endl
      << endl;

  arq << "%HEADER.VERSION" << endl
      << "0-005 - Oct/93" << endl
      << endl
      << "%HEADER.ANALYSIS" << endl
      << "\'shell\'" << endl
      << endl;

  QuadtreeCellList folhas = q->getLeaves();

  list<Vertex> vertices;

  int id = 0;

  for (QuadtreeCellList::iterator iter = folhas.begin(); iter != folhas.end();
       iter++) {
    Vertex *min = (*iter)->getMin();
    Vertex *max = (*iter)->getMax();

    Vertex v1(min->getX(), min->getY(), ++id);
    Vertex v2(max->getX(), min->getY(), ++id);
    Vertex v3(max->getX(), max->getY(), ++id);
    Vertex v4(min->getX(), max->getY(), ++id);

    vertices.push_back(v1);
    vertices.push_back(v2);
    vertices.push_back(v3);
    vertices.push_back(v4);
  }

  arq << "%NODE" << endl << vertices.size() << endl << endl;

  arq << "%NODE.COORD" << endl << vertices.size() << endl;

  for (list<Vertex>::iterator iter = vertices.begin(); iter != vertices.end();
       iter++) {
    Vertex n = (*iter);

    arq << n.getId() << " " << n.getX() << " " << n.getY() << " "
        << "0" << endl;
  }

  arq << endl;

  arq << "%MATERIAL" << endl
      << "1" << endl
      << endl
      << "%MATERIAL.LABEL" << endl
      << "1" << endl
      << "1\t\'m1\'" << endl
      << endl
      << "%MATERIAL.ISOTROPIC" << endl
      << "1" << endl
      << "1\t1000.0\t0.0" << endl
      << endl
      << "%THICKNESS" << endl
      << "1" << endl
      << "1\t1.0" << endl
      << endl
      << "%INTEGRATION.ORDER" << endl
      << "1" << endl
      << "1\t3\t1\t1\t3\t1\t1" << endl
      << endl;

  arq << "%ELEMENT" << endl << 2 * folhas.size() << endl << endl;

  arq << "%ELEMENT.T3" << endl << 2 * folhas.size() << endl;

  int idv = 1;
  int idq = 0;

  for (QuadtreeCellList::iterator iter = folhas.begin(); iter != folhas.end();
       iter++) {
    /*arq << ++idq << " "
             << "1 1 1 "
             << ++idv << " "
             << ++idv << " "
             << ++idv << " "
             << ++idv << endl;*/

    arq << ++idq << " "
        << "1 1 1 " << idv << " " << idv + 1 << " " << idv + 2 << endl;

    arq << ++idq << " "
        << "1 1 1 " << idv << " " << idv + 2 << " " << idv + 3 << endl;

    idv += 4;
  }

  arq << endl;
  arq << "%END";

  arq.flush();

  arq.close();

  cout << "escreveu o arquivo para a quadtree " << s << " para o passo "
       << passo << endl;
}

Quadtree::Quadtree(Boundary *boundary, double factor) : Shape() {
  setBoundary(boundary);
  setFactor(factor);
  setRoot(NULL);

  //#if USE_OPENGL
  //    setColor(0.0, 1.0, 0.0);
  //    ////figura
  //    //setColor(0.0, 0.0, 0.0);
  //    ////endfigura
  //#endif //#if USE_OPENGL

  lastVertexId = lastEdgeId = lastFaceId = 0;
}

Quadtree::~Quadtree() {
  // quando boundary == NULL, entao a quadtree mate estah envolvida.
  //  nesse caso, os root->min e root->max sao os mesmos para as
  //  duas quadtrees, assim como a boundary. logo, root->min, root->max e
  //  boundary sao apagadas somente por uma das quadtrees

  if (root) {
    if (boundary) {
      delete root->getMin();
      delete root->getMax();
    }

    delete root;
  }

  if (boundary) {
    delete boundary;
  }

  leaves.clear();
}

void Quadtree::setFactor(double factor) { this->factor = factor; }

double Quadtree::getFactor() { return factor; }

void Quadtree::setBoundary(Boundary *boundary) { this->boundary = boundary; }

Boundary *Quadtree::getBoundary() { return boundary; }

void Quadtree::setRoot(QuadtreeCell *root) {
  this->root = root;

  if (root) {
    QuadtreeCellList breadthSearch;

    leaves.clear();

    breadthSearch.push_back(root);

    while (!breadthSearch.empty()) {
      QuadtreeCell *cell = breadthSearch.front();
      breadthSearch.pop_front();

      if (cell->subdivided()) {
        breadthSearch.push_back(cell->getChild(QUAD_BOTTOM_LEFT));
        breadthSearch.push_back(cell->getChild(QUAD_BOTTOM_RIGHT));
        breadthSearch.push_back(cell->getChild(QUAD_TOP_RIGHT));
        breadthSearch.push_back(cell->getChild(QUAD_TOP_LEFT));
      } else {
        leaves.push_back(cell);
      }
    }
  }
}

QuadtreeCell *Quadtree::getRoot() { return root; }

void Quadtree::addLeaves(QuadtreeCell *cell) {
  leaves.remove(cell);

  leaves.push_back(cell->getChild(QUAD_BOTTOM_LEFT));
  leaves.push_back(cell->getChild(QUAD_BOTTOM_RIGHT));
  leaves.push_back(cell->getChild(QUAD_TOP_RIGHT));
  leaves.push_back(cell->getChild(QUAD_TOP_LEFT));
}

QuadtreeCellList Quadtree::getLeaves() { return leaves; }

int Quadtree::getNumCells() { return root ? root->getNumCells() : 0; }

Vertex *Quadtree::getMin() { return root ? root->getMin() : NULL; }

Vertex *Quadtree::getMax() { return root ? root->getMax() : NULL; }

long int Quadtree::getCellId() { return ++id; }

void Quadtree::findCell(Edge *e) {
  QuadtreeCell *q = root->findCell(e);

  if (!q) {
    return;
  }

  e->setCell(q);

  while (q) {
    q->addEdge(e);

    q = q->getParent();
  }
}

bool Quadtree::in(Vertex *v) { return root->in(v); }

bool Quadtree::on(Vertex *v) { return root->on(v); }

bool Quadtree::out(Vertex *v) { return root->out(v); }

enum MethodStatus Quadtree::generate(const FaceList &oldmesh) {
  // 1o Passo
  if (!root) {
    double minX, minY, maxX, maxY;

    boundary->getBox(&minX, &minY, &maxX, &maxY);

    double spanX = maxX - minX;
    double spanY = maxY - minY;

    double midX = (minX + maxX) / 2.0;
    double midY = (minY + maxY) / 2.0;

    if (spanX > spanY) {
      minY = midY - spanX / 2.0;
      maxY = midY + spanX / 2.0;
    } else {
      minX = midX - spanY / 2.0;
      maxX = midX + spanY / 2.0;
    }

    Vertex *min = new Vertex(minX, minY);
    Vertex *max = new Vertex(maxX, maxY);

    root = new QuadtreeCell(getCellId(), /*mainDrive, */ this, min, max);
  }

  leaves.push_back(root);

  EdgeList edges = boundary->getEdges();

  for (EdgeList::iterator iter = edges.begin(); iter != edges.end(); iter++) {
    root->subdivide((*iter));
  }

  //    escreve(this, 1);

  for (FaceList::const_iterator iter = oldmesh.begin(); iter != oldmesh.end();
       iter++) {
    root->subdivide((*iter));
  }

  //	escreve(this, 2);

  for (EdgeList::iterator iter = edges.begin(); iter != edges.end(); iter++) {
    findCell((*iter));
  }

  for (EdgeList::iterator iter = edges.begin(); iter != edges.end(); iter++) {
    (*iter)->setLen(-1.0);
  }

  return QUAD_INITIAL_TREE_DONE;
}

enum MethodStatus Quadtree::refineToLevel() {
  // 2o Passo
  EdgeList edges = boundary->getEdges();

  long int minLevel = __LONG_MAX__;

  for (EdgeList::iterator iter = edges.begin(); iter != edges.end(); iter++) {
    long int level = (*iter)->getCell()->getLevel();

    if (level < minLevel) {
      minLevel = level;
    }
  }

  root->subdivideToLevel(minLevel);

  return QUAD_REFINE_TO_LEVEL_DONE;
}

enum MethodStatus Quadtree::refineAccordingToNeighbors() {
  QuadtreeCellList oldLeaves = leaves;

  while (!oldLeaves.empty()) {
    QuadtreeCell *cell = oldLeaves.front();
    oldLeaves.pop_front();

    if (cell->subdivideAccordingToNeighbors()) {
      oldLeaves = leaves;
    }
  }

  //	escreve(this, 3);

  return QUAD_REFINE_ACCORDING_TO_NEIGHBORS_DONE;
}

bool Quadtree::execute(const FaceList &oldmesh) {
  if (generate(oldmesh) != QUAD_INITIAL_TREE_DONE) {
    return false;
  }

  if (refineToLevel() != QUAD_REFINE_TO_LEVEL_DONE) {
    return false;
  }

  if (refineAccordingToNeighbors() != QUAD_REFINE_ACCORDING_TO_NEIGHBORS_DONE) {
    return false;
  }

  return true;
}

long int Quadtree::vertexId() { return ++lastVertexId; }

long int Quadtree::edgeId() { return ++lastEdgeId; }

long int Quadtree::faceId() { return ++lastFaceId; }

EdgeList Quadtree::getFront() { return front; }

EdgeList Quadtree::getEdges() { return edges; }

VertexList Quadtree::getVertices() { return vertices; }

FaceList Quadtree::getMesh() { return mesh; }

void Quadtree::add(Vertex *v) { vertices.push_back(v); }

void Quadtree::add(Edge *e) { edges.push_back(e); }

void Quadtree::add(Face *f) { mesh.push_back(f); }

void Quadtree::addFront(Edge *e) {
  front.push_back(e);

  e->setFree(true);

  // GAMBIARRA
  e->setInBoundary(true);
}

enum MethodStatus Quadtree::makeTemplateBasedMesh() {
  root->sortNeighbors();

  // cout << "ordenou vizinhos" << endl;

  lastVertexId = boundary->getLastVertexId();
  lastEdgeId = boundary->getLastEdgeId();

  root->makeOuterVertices();

  // cout << "criou vertices" << endl;

  root->makeOuterEdges();

  // cout << "criou arestas" << endl;

  root->makeTemplateBasedMesh();

  // cout << "fez a malha" << endl;

  return QUAD_MAKE_TEMPLATE_BASED_MESH_DONE;
}

string Quadtree::getText() {
  string s;

  return s;
}

//#if USE_OPENGL
// void Quadtree::highlight()
//{
//    setColor(0.0, 0.0, 1.0);
//}

// void Quadtree::unhighlight()
//{
//     setColor(1.0, 0.0, 0.0);
// }

// void Quadtree::draw()
//{
//     if (root)
//     {
//         /*Vertex *v[4] = {
//             new Vertex(root->getMin()->getX(), root->getMin()->getY()),
//             new Vertex(root->getMax()->getX(), root->getMin()->getY()),
//             new Vertex(root->getMax()->getX(), root->getMax()->getY()),
//             new Vertex(root->getMin()->getX(), root->getMax()->getY())
//         };

//        Edge *e[4] = {
//            new Edge(v[0], v[1]),
//            new Edge(v[1], v[2]),
//            new Edge(v[2], v[3]),
//            new Edge(v[3], v[0])
//        };

//        e[0]->setColor(r, g, b);
//        e[1]->setColor(r, g, b);
//        e[2]->setColor(r, g, b);
//        e[3]->setColor(r, g, b);

//        e[0]->draw();
//        e[1]->draw();
//        e[2]->draw();
//        e[3]->draw();

//        e[0]->setVertices(NULL, NULL);
//        e[1]->setVertices(NULL, NULL);
//        e[2]->setVertices(NULL, NULL);
//        e[3]->setVertices(NULL, NULL);

//        delete e[0];
//        delete e[1];
//        delete e[2];
//        delete e[3];

//        delete v[0];
//        delete v[1];
//        delete v[2];
//        delete v[3];*/

//        root->draw();
//    }
//}
//#endif //#if USE_OPENGL
