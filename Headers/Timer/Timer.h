#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>
#include <cstdio>
#include <sstream>
#include <fstream>
#include "../Data/Definitions.h"
#include <sys/time.h>

using namespace std;

extern std::string nameModel;
extern std::string numberProcess;

//[0]= Inicialização
//[1]= Estimativa de carga
//[2]= Geração da Malha Inicial
//[3]= Adaptação das curvas
//[4]= Adaptação do domínio
//[5]= ...
//[6]= ...
//[7]= Calculo do erro
//[8]= Overhead
//[9]= Timer send and recv process
//[10]= Full

class Timer
{

public:

    Timer();
    Timer(int sizeRank, int sizeThread, int sizeType);
    bool openFile(string);
    void closeFile();
    bool deleteFile(string);

    void initTimerParallel(int _rank, int _thread, int _type);
    void endTimerParallel(int _rank, int _thread, int _type);
    void calculateTime(int _rank, int _thread, int _type);
    void printTime();
    double getRankThreadTime(int _rank, int _thread, int _type);
    vector<double> getMaxTime();
    vector<double> getMinTime();

    vector<vector<vector<timeval> > > getTimerParallelInit() const;
    void setTimerParallelInit(const vector<vector<vector<timeval> > > &value);

    vector<vector<vector<timeval> > > getTimerParallelEnd() const;
    void setTimerParallelEnd(const vector<vector<vector<timeval> > > &value);

    vector<vector<vector<double> > > getTimerParallel() const;
    void setTimerParallel(const vector<vector<vector<double> > > &value);

//private:

    vector<vector<vector<double>>> timerParallelInitMpi;
    vector<vector<vector<double>>> timerParallelEndMpi;

    vector<vector<vector<timeval>>> timerParallelInit;
    vector<vector<vector<timeval>>> timerParallelEnd;

    vector<vector<vector<double>>> timerParallel;

    string locationName;
    fstream file;
    //clock_t time_clock;
};

#endif // TIMER_H
