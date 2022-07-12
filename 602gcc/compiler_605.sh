#!/bin/sh

#rm -rf *.o  inp.out mcf.out
#find . \( -name \*.o -o -name '*.fppized.f*' -o -name '*.i' -o -name '*.mod' \) -print | xargs rm -rf
#rm -rf mcf_s
#rm -rf mcf_s.exe
#rm -rf core

/usr/bin/gcc     -std=c99   -m64 -c -o mcf.o -DSPEC -DNDEBUG  -Ispec_qsort -DSPEC_AUTO_SUPPRESS_OPENMP -g           -fopenmp -DSPEC_OPENMP -fno-strict-aliasing -fgnu89-inline   -DSPEC_LP64  mcf.c
/usr/bin/gcc     -std=c99   -m64 -c -o mcfutil.o -DSPEC -DNDEBUG  -Ispec_qsort -DSPEC_AUTO_SUPPRESS_OPENMP -g           -fopenmp -DSPEC_OPENMP -fno-strict-aliasing -fgnu89-inline   -DSPEC_LP64  mcfutil.c
/usr/bin/gcc     -std=c99   -m64 -c -o readmin.o -DSPEC -DNDEBUG  -Ispec_qsort -DSPEC_AUTO_SUPPRESS_OPENMP -g           -fopenmp -DSPEC_OPENMP -fno-strict-aliasing -fgnu89-inline   -DSPEC_LP64  readmin.c
/usr/bin/gcc     -std=c99   -m64 -c -o implicit.o -DSPEC -DNDEBUG  -Ispec_qsort -DSPEC_AUTO_SUPPRESS_OPENMP -g           -fopenmp -DSPEC_OPENMP -fno-strict-aliasing -fgnu89-inline   -DSPEC_LP64  implicit.c
/usr/bin/gcc     -std=c99   -m64 -c -o pstart.o -DSPEC -DNDEBUG  -Ispec_qsort -DSPEC_AUTO_SUPPRESS_OPENMP -g           -fopenmp -DSPEC_OPENMP -fno-strict-aliasing -fgnu89-inline   -DSPEC_LP64  pstart.c
/usr/bin/gcc     -std=c99   -m64 -c -o output.o -DSPEC -DNDEBUG  -Ispec_qsort -DSPEC_AUTO_SUPPRESS_OPENMP -g           -fopenmp -DSPEC_OPENMP -fno-strict-aliasing -fgnu89-inline   -DSPEC_LP64  output.c
/usr/bin/gcc     -std=c99   -m64 -c -o treeup.o -DSPEC -DNDEBUG  -Ispec_qsort -DSPEC_AUTO_SUPPRESS_OPENMP -g           -fopenmp -DSPEC_OPENMP -fno-strict-aliasing -fgnu89-inline   -DSPEC_LP64  treeup.c
/usr/bin/gcc     -std=c99   -m64 -c -o pbla.o -DSPEC -DNDEBUG  -Ispec_qsort -DSPEC_AUTO_SUPPRESS_OPENMP -g           -fopenmp -DSPEC_OPENMP -fno-strict-aliasing -fgnu89-inline   -DSPEC_LP64  pbla.c
/usr/bin/gcc     -std=c99   -m64 -c -o pflowup.o -DSPEC -DNDEBUG  -Ispec_qsort -DSPEC_AUTO_SUPPRESS_OPENMP -g           -fopenmp -DSPEC_OPENMP -fno-strict-aliasing -fgnu89-inline   -DSPEC_LP64  pflowup.c
/usr/bin/gcc     -std=c99   -m64 -c -o psimplex.o -DSPEC -DNDEBUG  -Ispec_qsort -DSPEC_AUTO_SUPPRESS_OPENMP -g           -fopenmp -DSPEC_OPENMP -fno-strict-aliasing -fgnu89-inline   -DSPEC_LP64  psimplex.c
/usr/bin/gcc     -std=c99   -m64 -c -o pbeampp.o -DSPEC -DNDEBUG  -Ispec_qsort -DSPEC_AUTO_SUPPRESS_OPENMP -g           -fopenmp -DSPEC_OPENMP -fno-strict-aliasing -fgnu89-inline   -DSPEC_LP64  pbeampp.c
/usr/bin/gcc     -std=c99   -m64 -c -o spec_qsort/spec_qsort.o -DSPEC -DNDEBUG  -Ispec_qsort -DSPEC_AUTO_SUPPRESS_OPENMP -g           -fopenmp -DSPEC_OPENMP -fno-strict-aliasing -fgnu89-inline   -DSPEC_LP64  spec_qsort/spec_qsort.c

echo "/usr/bin/gcc     -std=c99   -m64      -g        -fopenmp -DSPEC_OPENMP -fno-strict-aliasing -fgnu89-inline mcf.o mcfutil.o readmin.o implicit.o pstart.o output.o treeup.o pbla.o pflowup.o psimplex.o pbeampp.o spec_qsort/spec_qsort.o             -lm         -o mcf_s"
/usr/bin/gcc     -std=c99   -m64      -g        -fopenmp -DSPEC_OPENMP -fno-strict-aliasing -fgnu89-inline mcf.o mcfutil.o readmin.o implicit.o pstart.o output.o treeup.o pbla.o pflowup.o psimplex.o pbeampp.o spec_qsort/spec_qsort.o             -lm         -o mcf_s
