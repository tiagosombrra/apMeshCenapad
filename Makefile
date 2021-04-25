PROGRAMA = apMesh

FONTES = Sources/Data/Definitions.cpp \
Sources/Estimate/ChargeEstimateProcess.cpp \
Sources/IO/PatchBezierReader.cpp \
Sources/IO/WriteOBJFile.cpp \
Sources/Adapter/Adaptador.cpp \
Sources/Adapter/AdaptadorPorCurvatura.cpp \
Sources/Crabmesh/Aft/AdvancingFront.cpp \
Sources/Crabmesh/Aft/Boundary.cpp \
Sources/Crabmesh/Aft/Quadtree.cpp \
Sources/Crabmesh/Aft/QuadtreeCell.cpp \
Sources/Crabmesh/Aft/Shape.cpp \
Sources/Crabmesh/Numerical/BisectionEquationRoot.cpp \
Sources/Crabmesh/Numerical/Function.cpp \
Sources/Crabmesh/Performer/IdManager.cpp \
Sources/Crabmesh/Performer/RangedIdManager.cpp \
Sources/Curvature/Adjacente.cpp \
Sources/Curvature/Curvatura.cpp \
Sources/Curvature/CurvaturaAnalitica.cpp \
Sources/Curvature/CurvaturaDiscreta.cpp \
Sources/Data/Curve/CurvParamBezier.cpp \
Sources/Data/Curve/CurvParamHermite.cpp \
Sources/Data/Curve/Curva.cpp \
Sources/Data/Curve/CurvaParametrica.cpp \
Sources/Data/Edge.cpp \
Sources/Data/Elemento.cpp \
Sources/Data/Face.cpp \
Sources/Data/Geometria.cpp \
Sources/Data/Mesh/Malha.cpp \
Sources/Data/Mesh/SubMalha.cpp \
Sources/Data/Modelo.cpp \
Sources/Data/Noh.cpp \
Sources/Data/Patch/BezierPatch.cpp \
Sources/Data/Patch/CoonsPatch.cpp \
Sources/Data/Patch/HermitePatch.cpp \
Sources/Data/Patch/Patch.cpp \
Sources/Data/Ponto.cpp \
Sources/Data/Tree/BinTree.cpp \
Sources/Data/Triangulo.cpp \
Sources/Data/Vertex.cpp \
Sources/Data/Vertice.cpp \
Sources/Data/Vetor.cpp \
Sources/Generator/Gerador.cpp \
Sources/Generator/GeradorAdaptativo.cpp \
Sources/Generator/GeradorAdaptativoPorCurvatura.cpp \
Sources/IO/Arquivo.cpp \
Sources/IO/Modelos3d.cpp \
Sources/IO/ReaderPatches.cpp \
Sources/Parallel/ApMeshCommunicator.cpp \
Sources/Parallel/Communicator.cpp \
Sources/Parallel/MPICommunicator.cpp \
Sources/Parallel/MPIMessage.cpp \
Sources/Parallel/Message.cpp \
Sources/Parallel/NoCommunicator.cpp \
Sources/Parallel/NoThreadManager.cpp \
Sources/Parallel/OMPThreadManager.cpp \
Sources/Parallel/ParallelMeshGenerator.cpp \
Sources/Parallel/TMCommunicator.cpp \
Sources/Parallel/ThreadManager.cpp \
Sources/Parallel/Transferable.cpp \
Sources/Timer/Timer.cpp \
Sources/main.cpp

OBJETOS = $(FONTES:.cpp=.o)

CC            = gcc
CXX           = g++
MPICC         = mpicc
MPICXX        = mpic++

INCPATH = -IHeaders/Adapter -IHeaders/Crabmesh/Aft -IHeaders/Crabmesh/Numerical -IHeaders/Curvature -IHeaders/Data -IHeaders/Data/Curve -IHeaders/Data/Mesh -IHeaders/Data/Patch -IHeaders/Data/Tree -IHeaders/Estimate -IHeaders/Generator -IHeaders/IO -IHeaders/Parallel -IHeaders/Timer

LIBPATH = -LSources/Adapter -LSources/Crabmesh/Aft -LSources/Crabmesh/Numerical -LSources/Curvature -LSources/Data -LSources/Data/Curve -LSources/Data/Mesh -LSources/Data/Patch -LSources/Data/Tree -LSources/Estimate -LSources/Generator -LSources/IO -LSources/Parallel -LSources/Timer

CXXFLAGS_EXTRA = -O3 -W -Wall
CXXFLAGS      = -std=c++17 $(CXXFLAGS_EXTRA)
CXXFLAGS_OMP  = -fopenmp  $(CXXFLAGS) 

$(PROGRAMA): $(OBJETOS)
	@echo "gerando o executavel..."
	$(MPICXX) $(INCPATH) $(CXXFLAGS_OMP) $(LIBPATH) $(OBJETOS) -o $@

.cpp.o:
	@echo "gerando os .o..."
	$(MPICXX) $(INCPATH) -c $(CXXFLAGS_OMP) $< -o $@

clean:
	rm -rfv *.o Sources/*.o Sources/Adapter/*.o Sources/Crabmesh/Aft/*.o  Sources/Crabmesh/Numerical/*.o Sources/Crabmesh/Performer/*.o Sources/Curvature/*.o Sources/Data/*.o Sources/Data/Curve/*.o Sources/Data/Mesh/*.o Sources/Data/Patch/*.o Sources/Data/Tree/*.o Sources/Estimate/*.o Sources/Generator/*.o Sources/IO/*.o Sources/Parallel/*.o Sources/Timer/*.o $(PROGRAMA)

exec: 
	./$(PROGRAMA)
