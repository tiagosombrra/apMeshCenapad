cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(ap_mesh VERSION 1.0)

if(UNIX)
    message("This is a Unix System")
elseif(WIN32)
    message("This is a Windows System")
endif()

set(CMAKE_CXX_STANDARD 17)
message("CXX Standard: ${CMAKE_CXX_STANDARD}")

set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -O3 -W -Wall -ftree-vectorize -flto -fno-strict-aliasing -Wno-cast-function-type")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Sources)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Headers)

file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")

add_executable(ap_mesh ${SOURCES})

target_include_directories(ap_mesh PRIVATE ${INC_DIR})
target_link_directories(ap_mesh PRIVATE ${SRC_DIR})

# Adiciona opção para escolher entre gcc e mpi
option(USE_MPI "Use MPI for parallel computing" OFF)

if (USE_MPI)
    message("Compiling with MPI")

    # Adiciona a detecção do MPI
    find_package(MPI REQUIRED)

    # Define os caminhos para os compiladores do MPI
    set(MPI_C_COMPILER /usr/local/bin/mpicc)
    set(MPI_CXX_COMPILER /usr/local/bin/mpicxx)

    # Adiciona os compiladores do MPI ao projeto
    set(CMAKE_C_COMPILER ${MPI_C_COMPILER})
    set(CMAKE_CXX_COMPILER ${MPI_CXX_COMPILER})

    # Adiciona os flags do MPI ao projeto
    set(CMAKE_CXX_COMPILE_FLAGS ${CMAKE_CXX_COMPILE_FLAGS} ${MPI_CXX_COMPILE_FLAGS})
    set(CMAKE_CXX_LINK_FLAGS ${CMAKE_CXX_LINK_FLAGS} ${MPI_CXX_LINK_FLAGS})

    # Adiciona as bibliotecas do MPI ao projeto
    target_link_libraries(ap_mesh ${MPI_CXX_LIBRARIES})
else()
    message("Compiling with gcc")

    # Usa o compilador gcc padrão
    set(CMAKE_C_COMPILER gcc)
    set(CMAKE_CXX_COMPILER g++)

    # Adiciona flags do compilador gcc
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

    # Adiciona a biblioteca do OpenMP ao projeto
    target_link_libraries(ap_mesh gomp)
endif()
