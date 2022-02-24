#!/bin/sh

../602.gcc_s_build/sgcc 200.c -O3 -finline-limit=50000 -o 200.opts-O3_-finline-limit_50000.s > 200.opts-O3_-finline-limit_50000.out 2>> 200.opts-O3_-finline-limit_50000.err
../602.gcc_s_build/sgcc scilab.c -O3 -finline-limit=50000 -o scilab.opts-O3_-finline-limit_50000.s > scilab.opts-O3_-finline-limit_50000.out 2>> scilab.opts-O3_-finline-limit_50000.err
../602.gcc_s_build/sgcc train01.c -O3 -finline-limit=50000 -o train01.opts-O3_-finline-limit_50000.s > train01.opts-O3_-finline-limit_50000.out 2>> train01.opts-O3_-finline-limit_50000.err


#-o 200.opts-O3_-finline-limit_50000.out -e 200.opts-O3_-finline-limit_50000.err ../run_base_train_mytest-m64.0000/sgcc_base.mytest-m64 200.c -O3 -finline-limit=50000 -o 200.opts-O3_-finline-limit_50000.s > 200.opts-O3_-finline-limit_50000.out 2>> 200.opts-O3_-finline-limit_50000.err
#-o scilab.opts-O3_-finline-limit_50000.out -e scilab.opts-O3_-finline-limit_50000.err ../run_base_train_mytest-m64.0000/sgcc_base.mytest-m64 scilab.c -O3 -finline-limit =50000 -o scilab.opts-O3_-finline-limit_50000.s > scilab.opts-O3_-finline-limit_50000.out 2>> scilab.opts-O3_-finline-limit_50000.err
#-o train01.opts-O3_-finline-limit_50000.out -e train01.opts-O3_-finline-limit_50000.err ../run_base_train_mytest-m64.0000/sgcc_base.mytest-m64 train01.c -O3 -finline-limit=50000 -o train01.opts-O3_-finline-limit_50000.s > train01.opts-O3_-finline-limit_50000.out 2>> train01.opts-O3_-finline-limit_50000.err

