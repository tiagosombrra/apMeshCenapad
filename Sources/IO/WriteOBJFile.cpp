//
//  WriteOBJFile.cpp
//  apMesh
//
//  Created by Tiago Guimarães Sombra on 05/12/15.
//  Copyright © 2015 TMeshSurf. All rights reserved.
//

#include "../../Headers/IO/WriteOBJFIle.h"

WriteOBJFIle::WriteOBJFIle() {}

void WriteOBJFIle::writeCurvaturePatches(
    std::vector<double> vecCurvaturePatches, double maxValue) {
  stringstream nameFile;
  nameFile << "analise_curvature.txt";

  ofstream file(nameFile.str().c_str());

  file << "File Analise Curvature" << endl << endl;

  std::vector<double> vec_0_10;
  std::vector<double> vec_10_20;
  std::vector<double> vec_20_30;
  std::vector<double> vec_30_40;
  std::vector<double> vec_40_50;
  std::vector<double> vec_50_60;
  std::vector<double> vec_60_70;
  std::vector<double> vec_70_80;
  std::vector<double> vec_80_90;
  std::vector<double> vec_90_100;

  for (std::vector<double>::iterator it = vecCurvaturePatches.begin();
       it != vecCurvaturePatches.end(); it++) {
    double value;
    value = (*it) / maxValue;
    // cout<<value<<endl;
    if (0.0 <= value and value <= 0.1) {
      vec_0_10.push_back(value);
    } else if (0.1 < value and value <= 0.2) {
      vec_10_20.push_back(value);
    } else if (0.2 < value and value <= 0.3) {
      vec_20_30.push_back(value);
    } else if (0.3 < value and value <= 0.4) {
      vec_30_40.push_back(value);
    } else if (0.4 < value and value <= 0.5) {
      vec_40_50.push_back(value);
    } else if (0.5 < value and value <= 0.6) {
      vec_50_60.push_back(value);
    } else if (0.6 < value and value <= 0.7) {
      vec_60_70.push_back(value);
    } else if (0.8 < value and value <= 0.9) {
      vec_70_80.push_back(value);
    } else if (0.8 < value and value <= 0.9) {
      vec_80_90.push_back(value);
    } else if (0.9 < value and value <= 1) {
      vec_90_100.push_back(value);
    }
  }

  file << vec_0_10.size() / (double)vecCurvaturePatches.size() << endl;
  file << vec_10_20.size() / (double)vecCurvaturePatches.size() << endl;
  file << vec_20_30.size() / (double)vecCurvaturePatches.size() << endl;
  file << vec_30_40.size() / (double)vecCurvaturePatches.size() << endl;
  file << vec_40_50.size() / (double)vecCurvaturePatches.size() << endl;
  file << vec_50_60.size() / (double)vecCurvaturePatches.size() << endl;
  file << vec_60_70.size() / (double)vecCurvaturePatches.size() << endl;
  file << vec_70_80.size() / (double)vecCurvaturePatches.size() << endl;
  file << vec_80_90.size() / (double)vecCurvaturePatches.size() << endl;
  file << vec_90_100.size() / (double)vecCurvaturePatches.size() << endl;

  file.flush();

  file.close();
}

bool WriteOBJFIle::writeMeshOBJFile(Malha* malha, unsigned int passo,
                                    int process) {
  stringstream nameFile;
  nameFile << "mesh_";
  nameFile << passo;
  nameFile << "_process_";
  nameFile << process;
  nameFile << ".obj";

  ofstream file(nameFile.str().c_str());

  file << " File Wavefront OBJ generated apMesh" << endl << endl;

  time_t t = time(0);  // get time now
  struct tm* now = localtime(&t);
  file << "# File created: " << (now->tm_year + 1900) << '-'
       << (now->tm_mon + 1) << '-' << now->tm_mday << endl;

  unsigned long int Nv, Nt;
  Nv = Nt = 0;

  for (unsigned int i = 0; i < malha->getNumDeSubMalhas(); i++) {
    SubMalha* sub = malha->getSubMalha(i);

    Nv += sub->getNumDeNos();
    Nt += sub->getNumDeElementos();
  }

  file << "# of vertices" << endl << Nv << endl << endl;

  for (unsigned int i = 0; i < malha->getNumDeSubMalhas(); i++) {
    SubMalha* sub = malha->getSubMalha(i);

    for (unsigned int j = 0; j < sub->getNumDeNos(); j++) {
      Noh* n = sub->getNoh(j);
      file << "v " << n->x << " " << n->y << " " << n->z << endl;
    }
  }

  file << "# of faces " << endl << Nt << endl;

  for (unsigned int i = 0; i < malha->getNumDeSubMalhas(); i++) {
    SubMalha* sub = malha->getSubMalha(i);

    for (unsigned int j = 0; j < sub->getNumDeElementos(); j++) {
      Triangulo* t = (Triangulo*)sub->getElemento(j);
      file << "f " << t->getN(1).id << " " << t->getN(2).id << " "
           << t->getN(3).id << endl;
    }
  }

  file.flush();

  file.close();

  return true;
}

WriteOBJFIle::~WriteOBJFIle() {}
