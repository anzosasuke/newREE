#!/bin/sh

../602.gcc_s_build/sgcc gcc-pp.c  -O5 -fipa-pta -o gcc-pp.opts-O5_-fipa-pta.s > gcc-pp.opts-O5_-fipa-pta.out 2>> gcc-pp.opts-O5_-fipa-pta.err
../602.gcc_s_build/sgcc  gcc-pp.c -O5 -finline-limit=1000 -fselective-scheduling -fselective-scheduling2 -o gcc-pp.opts-O5_-finline-limit_1000_-fselective-scheduling_-fselective-scheduling2.s > gcc-pp.opts-O5_-finline-limit_1000_-fselective-scheduling_-fselective-scheduling2.out 2>> gcc-pp.opts-O5_-finline-limit_1000_-fselective-scheduling_-fselective-scheduling2.err
../602.gcc_s_build/sgcc gcc-pp.c -O5 -finline-limit=24000 -fgcse -fgcse-las -fgcse-lm -fgcse-sm -o gcc-pp.opts-O5_-finline-limit_24000_-fgcse_-fgcse-las_-fgcse-lm_-fgcse-sm.s > gcc-pp.opts-O5_-finline-limit_24000_-fgcse_-fgcse-las_-fgcse-lm_-fgcse-sm.out 2>> gcc-pp.opts-O5_-finline-limit_24000_-fgcse_-fgcse-las_-fgcse-lm_-fgcse-sm.err













#-o gcc-pp.opts-O5_-fipa-pta.out -e gcc-pp.opts-O5_-fipa-pta.err ../run_base_refspeed_mytest-m64.0000/sgcc_base.mytest-m64 gcc-pp.c -O5 -fipa-pta -o gcc-pp.opts-O5_-fipa-pta.s > gcc-pp.opts-O5_-fipa-pta.out 2>> gcc-pp.opts-O5_-fipa-pta.err
#-o gcc-pp.opts-O5_-finline-limit_1000_-fselective-scheduling_-fselective-scheduling2.out -e gcc-pp.opts-O5_-finline-limit_1000_-fselective-scheduling_-fselective-scheduling2.err ../run_base_refspeed_mytest-m64.0000/sgcc_base.mytest-m64 gcc-pp.c -O5 -finline-limit=1000 -fselective-scheduling -fselective-scheduling2 -o gcc-pp.opts-O5_-finline-limit_1000_-fselective-scheduling_-fselective-scheduling2.s > gcc-pp.opts-O5_-finline-limit_1000_-fselective-scheduling_-fselective-scheduling2.out 2>> gcc-pp.opts-O5_-finline-limit_1000_-fselective-scheduling_-fselective-scheduling2.err
#-o gcc-pp.opts-O5_-finline-limit_24000_-fgcse_-fgcse-las_-fgcse-lm_-fgcse-sm.out -e gcc-pp.opts-O5_-finline-limit_24000_-fgcse_-fgcse-las_-fgcse-lm_-fgcse-sm.err ../run_base_refspeed_mytest-m64.0000/sgcc_base.mytest-m64 gcc-pp.c -O5 -finline-limit=24000 -fgcse -fgcse-las -fgcse-lm -fgcse-sm -o gcc-pp.opts-O5_-finline-limit_24000_-fgcse_-fgcse-las_-fgcse-lm_-fgcse-sm.s > gcc-pp.opts-O5_-finline-limit_24000_-fgcse_-fgcse-las_-fgcse-lm_-fgcse-sm.out 2>> gcc-pp.opts-O5_-finline-limit_24000_-fgcse_-fgcse-las_-fgcse-lm_-fgcse-sm.err
