#!/bin/sh



#rm -rf *.o  aminos.out gcn4dna.out
#find . \( -name \*.o -o -name '*.fppized.f*' -o -name '*.i' -o -name '*.mod' \) -print | xargs rm -rf
#rm -rf nab_s
#rm -rf nab_s.exe
#rm -rf core

/usr/bin/gcc     -std=c99   -m64 -c -o nabmd.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  nabmd.c
/usr/bin/gcc     -std=c99   -m64 -c -o sff.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  sff.c
/usr/bin/gcc     -std=c99   -m64 -c -o nblist.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  nblist.c
/usr/bin/gcc     -std=c99   -m64 -c -o prm.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  prm.c
/usr/bin/gcc     -std=c99   -m64 -c -o memutil.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  memutil.c
/usr/bin/gcc     -std=c99   -m64 -c -o molio.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  molio.c
/usr/bin/gcc     -std=c99   -m64 -c -o molutil.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  molutil.c
/usr/bin/gcc     -std=c99   -m64 -c -o errormsg.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  errormsg.c
/usr/bin/gcc     -std=c99   -m64 -c -o binpos.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  binpos.c
/usr/bin/gcc     -std=c99   -m64 -c -o rand2.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  rand2.c
/usr/bin/gcc     -std=c99   -m64 -c -o select_atoms.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  select_atoms.c
/usr/bin/gcc     -std=c99   -m64 -c -o reslib.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  reslib.c
/usr/bin/gcc     -std=c99   -m64 -c -o database.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  database.c
/usr/bin/gcc     -std=c99   -m64 -c -o traceback.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  traceback.c
/usr/bin/gcc     -std=c99   -m64 -c -o chirvol.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  chirvol.c
/usr/bin/gcc     -std=c99   -m64 -c -o specrand/specrand.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  specrand/specrand.c
/usr/bin/gcc     -std=c99   -m64 -c -o regex-alpha/regcomp.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  regex-alpha/regcomp.c
/usr/bin/gcc     -std=c99   -m64 -c -o regex-alpha/regerror.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  regex-alpha/regerror.c
/usr/bin/gcc     -std=c99   -m64 -c -o regex-alpha/regexec.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  regex-alpha/regexec.c
/usr/bin/gcc     -std=c99   -m64 -c -o regex-alpha/regfree.o -DSPEC -DNDEBUG -Ispecrand -Iregex-alpha -DNDEBUG -DNOPERFLIB -DNOREDUCE  -g           -fopenmp -DSPEC_OPENMP    -DSPEC_LP64  regex-alpha/regfree.c
/usr/bin/gcc     -std=c99   -m64      -g        -fopenmp -DSPEC_OPENMP  nabmd.o sff.o nblist.o prm.o memutil.o molio.o molutil.o errormsg.o binpos.o rand2.o select_atoms.o reslib.o database.o traceback.o chirvol.o specrand/specrand.o regex-alpha/regcomp.o regex-alpha/regerror.o regex-alpha/regexec.o regex-alpha/regfree.o             -lm         -o nab_s
