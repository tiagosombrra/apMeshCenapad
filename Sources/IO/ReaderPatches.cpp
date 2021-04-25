#include "../../Headers/IO/ReaderPatches.h"

ReaderPatches::ReaderPatches()
{

}

std::list<BezierPatch *> ReaderPatches::loaderBezierPatchFile(string fileName)

{
    patch = new BezierPatch();

    if (!fileName.empty()) {
        std::ifstream fin(fileName);

        if (fin) {
            while (fin) {
                std::string line;
                std::vector<double> v;
                std::vector<Ponto> vectorControlPoints;
                std::vector<long> p;
                long id_ponto = 0;

                while (std::getline(fin, line)) {

                    if (line[0] == 'v') {

                        line = line.erase(0, 1);
                        std::istringstream iss(line);
                        //int id_ponto;
                        //iss >> id_ponto;

                        //line = line.erase(0, 1);
                        double n;
                        while (iss >> n) {
                            v.push_back(n);
                        }

                        Ponto ponto(v[0], v[1], v[2], id_ponto);
                        id_ponto++;
                        vectorControlPoints.push_back(ponto);
                        v.erase(v.begin(), v.end());
                    }

                    if (line[0] == 'p') {

                        line = line.erase(0, 1);
                        std::istringstream iss(line);
                        long n;
                        while (iss >> n) {
                            p.push_back(n);
                        }

                        for (unsigned int i = 0; i < p.size(); i++) {
                            if (i == 0) {
                                patch->setPt00(getPointVectorControlPoints(vectorControlPoints, p[i]));
                            } else if (i == 1) {
                                patch->setPt10(getPointVectorControlPoints(vectorControlPoints, p[i]));
                            } else if (i == 2) {
                                patch->setPt20(getPointVectorControlPoints(vectorControlPoints, p[i]));
                            } else if (i == 3) {
                                patch->setPt30(getPointVectorControlPoints(vectorControlPoints, p[i]));
                            } else if (i == 4) {
                                patch->setPt01(getPointVectorControlPoints(vectorControlPoints, p[i]));
                            } else if (i == 5) {
                                patch->setPt11(getPointVectorControlPoints(vectorControlPoints, p[i]));
                            } else if (i == 6) {
                                patch->setPt21(getPointVectorControlPoints(vectorControlPoints, p[i]));
                            } else if (i == 7) {
                                patch->setPt31(getPointVectorControlPoints(vectorControlPoints, p[i]));
                            } else if (i == 8) {
                                patch->setPt02(getPointVectorControlPoints(vectorControlPoints, p[i]));
                            } else if (i == 9) {
                                patch->setPt12(getPointVectorControlPoints(vectorControlPoints, p[i]));
                            } else if (i == 10) {
                                patch->setPt22(getPointVectorControlPoints(vectorControlPoints, p[i]));
                            } else if (i == 11) {
                                patch->setPt32(getPointVectorControlPoints(vectorControlPoints, p[i]));
                            } else if (i == 12) {
                                patch->setPt03(getPointVectorControlPoints(vectorControlPoints, p[i]));
                            } else if (i == 13) {
                                patch->setPt13(getPointVectorControlPoints(vectorControlPoints, p[i]));
                            } else if (i == 14) {
                                patch->setPt23(getPointVectorControlPoints(vectorControlPoints, p[i]));
                            } else if (i == 15) {
                                patch->setPt33(getPointVectorControlPoints(vectorControlPoints, p[i]));
                            }
                        }

                        p.erase(p.begin(), p.end());
                        patches.push_back(patch);
                        patch = new BezierPatch();
                    }
                }
            }
        } else {
            std::cout << "Error: file .bp is not readable." << std::endl;
        }

        fin.close();

    } else {
        std::cout << "Erro ao abrir o arquivo .bp" << std::endl;
    }

    return patches;
}

Ponto ReaderPatches::getPointVectorControlPoints(std::vector<Ponto> vectorPoints, unsigned long idPoint)
{
    for (std::vector<Ponto>::iterator it = vectorPoints.begin(); it != vectorPoints.end(); ++it) {
        if ((*it).getId() == idPoint) {
            return (*it);
        }
    }

    Ponto ponto;
    return ponto;
}

Geometria *ReaderPatches::readerPatches(Geometria *geo, string fileName)
{
    ReaderPatches* pt = new ReaderPatches();
    std::list<BezierPatch*> listBezierPt = pt->loaderBezierPatchFile(fileName);
    delete pt;

    Ponto* p00; Ponto* p01; Ponto* p02; Ponto* p03;
    Ponto* p10; Ponto* p11; Ponto* p12; Ponto* p13;
    Ponto* p20; Ponto* p21; Ponto* p22; Ponto* p23;
    Ponto* p30; Ponto* p31; Ponto* p32; Ponto* p33;
    Curva* patch_c1; Curva* patch_c2; Curva* patch_c3; Curva* patch_c4;

    for (std::list<BezierPatch*>::iterator it = listBezierPt.begin(); it != listBezierPt.end(); it++) {

        p00 = new Vertice((*it)->getPt00().x, (*it)->getPt00().y, (*it)->getPt00().z);
        p00->setId((*it)->getPt00().id);
        p10 = new Vertice((*it)->getPt10().x, (*it)->getPt10().y, (*it)->getPt10().z);
        p10->setId((*it)->getPt10().id);
        p20 = new Vertice((*it)->getPt20().x, (*it)->getPt20().y, (*it)->getPt20().z);
        p20->setId((*it)->getPt20().id);
        p30 = new Vertice((*it)->getPt30().x, (*it)->getPt30().y, (*it)->getPt30().z);
        p30->setId((*it)->getPt30().id);

        p01 = new Vertice((*it)->getPt01().x, (*it)->getPt01().y, (*it)->getPt01().z);
        p01->setId((*it)->getPt01().id);
        p11 = new Vertice((*it)->getPt11().x, (*it)->getPt11().y, (*it)->getPt11().z);
        p11->setId((*it)->getPt11().id);
        p21 = new Vertice((*it)->getPt21().x, (*it)->getPt21().y, (*it)->getPt21().z);
        p21->setId((*it)->getPt21().id);
        p31 = new Vertice((*it)->getPt31().x, (*it)->getPt31().y, (*it)->getPt31().z);
        p31->setId((*it)->getPt31().id);

        p02 = new Vertice((*it)->getPt02().x, (*it)->getPt02().y, (*it)->getPt02().z);
        p02->setId((*it)->getPt02().id);
        p12 = new Vertice((*it)->getPt12().x, (*it)->getPt12().y, (*it)->getPt12().z);
        p12->setId((*it)->getPt12().id);
        p22 = new Vertice((*it)->getPt22().x, (*it)->getPt22().y, (*it)->getPt22().z);
        p22->setId((*it)->getPt22().id);
        p32 = new Vertice((*it)->getPt32().x, (*it)->getPt32().y, (*it)->getPt32().z);
        p32->setId((*it)->getPt32().id);

        p03 = new Vertice((*it)->getPt03().x, (*it)->getPt03().y, (*it)->getPt03().z);
        p03->setId((*it)->getPt03().id);
        p13 = new Vertice((*it)->getPt13().x, (*it)->getPt13().y, (*it)->getPt13().z);
        p13->setId((*it)->getPt13().id);
        p23 = new Vertice((*it)->getPt23().x, (*it)->getPt23().y, (*it)->getPt23().z);
        p23->setId((*it)->getPt23().id);
        p33 = new Vertice((*it)->getPt33().x, (*it)->getPt33().y, (*it)->getPt33().z);
        p33->setId((*it)->getPt33().id);

        if (geo->verifyCurveGeometria(p00, p10, p20, p30) == NULL) {
            patch_c1 = new CurvParamBezier(*p00, *p10, *p20, *p30);
            geo->insereCurva(patch_c1);
        } else {
            patch_c1 = geo->verifyCurveGeometria(p00, p10, p20, p30);
        }

        if (geo->verifyCurveGeometria(p30, p31, p32, p33) == NULL) {
            patch_c2 = new CurvParamBezier(*p30, *p31, *p32, *p33);
            geo->insereCurva(patch_c2);
        } else {
            patch_c2 = geo->verifyCurveGeometria(p30, p31, p32, p33);
        }

        if (geo->verifyCurveGeometria(p03, p13, p23, p33) == NULL) {
            patch_c3 = new CurvParamBezier(*p03, *p13, *p23, *p33);
            geo->insereCurva(patch_c3);
        } else {
            patch_c3 = geo->verifyCurveGeometria(p03, p13, p23, p33);
        }

        if (geo->verifyCurveGeometria(p00, p01, p02, p03) == NULL) {
            patch_c4 = new CurvParamBezier(*p00, *p01, *p02, *p03);
            geo->insereCurva(patch_c4);
        } else {
            patch_c4 = geo->verifyCurveGeometria(p00, p01, p02, p03);
        }

        (*it) = new BezierPatch(patch_c1, patch_c2, patch_c3, patch_c4, *p11, *p21, *p12, *p22);

        geo->inserePatch((*it));
    }

    return geo;
}

