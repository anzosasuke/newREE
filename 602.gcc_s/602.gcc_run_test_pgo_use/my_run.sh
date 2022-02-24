#!/bin/sh

../602.gcc_s_build/sgcc t1.c -O3 -finline-limit=50000 -o t1.opts-O3_-finline-limit_50000.s > t1.opts-O3_-finline-limit_50000.out 2>> t1.opts-O3_-finline-limit_50000.err
