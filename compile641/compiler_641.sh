#!/bin/sh



#rm -rf *.o  train.out
#find . \( -name \*.o -o -name '*.fppized.f*' -o -name '*.i' -o -name '*.mod' \) -print | xargs rm -rf
#rm -rf leela_s
#rm -rf leela_s.exe
#rm -rf core

g++     -std=c++03 -m64 -c -o FullBoard.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  FullBoard.cpp
g++     -std=c++03 -m64 -c -o KoState.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  KoState.cpp
g++     -std=c++03 -m64 -c -o Playout.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  Playout.cpp
g++     -std=c++03 -m64 -c -o TimeControl.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  TimeControl.cpp
g++     -std=c++03 -m64 -c -o UCTSearch.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  UCTSearch.cpp
g++     -std=c++03 -m64 -c -o GameState.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  GameState.cpp
g++     -std=c++03 -m64 -c -o Leela.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  Leela.cpp
g++     -std=c++03 -m64 -c -o SGFParser.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  SGFParser.cpp
g++     -std=c++03 -m64 -c -o Timing.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  Timing.cpp
g++     -std=c++03 -m64 -c -o Utils.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  Utils.cpp
g++     -std=c++03 -m64 -c -o FastBoard.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  FastBoard.cpp
g++     -std=c++03 -m64 -c -o Matcher.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  Matcher.cpp
g++     -std=c++03 -m64 -c -o SGFTree.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  SGFTree.cpp
g++     -std=c++03 -m64 -c -o TTable.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  TTable.cpp
g++     -std=c++03 -m64 -c -o Zobrist.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  Zobrist.cpp
g++     -std=c++03 -m64 -c -o FastState.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  FastState.cpp
g++     -std=c++03 -m64 -c -o GTP.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  GTP.cpp
g++     -std=c++03 -m64 -c -o MCOTable.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  MCOTable.cpp
g++     -std=c++03 -m64 -c -o Random.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  Random.cpp
g++     -std=c++03 -m64 -c -o SMP.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  SMP.cpp
g++     -std=c++03 -m64 -c -o UCTNode.o -DSPEC -DNDEBUG -I.  -g       -fopenmp -DSPEC_OPENMP  -DSPEC_LP64  UCTNode.cpp
g++     -std=c++03 -m64      -g        -fopenmp -DSPEC_OPENMP  FullBoard.o KoState.o Playout.o TimeControl.o UCTSearch.o GameState.o Leela.o SGFParser.o Timing.o Utils.o FastBoard.o Matcher.o SGFTree.o TTable.o Zobrist.o FastState.o GTP.o MCOTable.o Random.o SMP.o UCTNode.o                      -o leela_s
