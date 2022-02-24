TUNE=peak
LABEL=collect-build-flags-m64
NUMBER=602
NAME=gcc_s
SOURCES= main.c cc1-checksum.c alias.c alloca.c alloc-pool.c argv.c \
	 attribs.c auto-inc-dec.c bb-reorder.c bid2dpd_dpd2bid.c bitmap.c \
	 bt-load.c c-lang.c c-errors.c c-lex.c c-pragma.c c-decl.c c-typeck.c \
	 c-convert.c c-aux-info.c c-common.c c-opts.c c-format.c c-semantics.c \
	 c-ppoutput.c c-objc-common.c c-dump.c c-parser.c c-gimplify.c \
	 c-pretty-print.c c-omp.c caller-save.c calls.c cfg.c cfganal.c \
	 cfgbuild.c cfgcleanup.c cfgexpand.c cfghooks.c cfglayout.c cfgloop.c \
	 cfgloopanal.c cfgloopmanip.c cfgrtl.c cgraph.c cgraphbuild.c \
	 cgraphunit.c combine.c combine-stack-adj.c concat.c convert.c coverage.c \
	 cp-demangle.c cp-demint.c cplus-dem.c cpp_directives.c cpp_lex.c \
	 cpp_errors.c cpp_expr.c cpp_charset.c cpp_macro.c cpp_traditional.c \
	 cpp_line-map.c cpp_symtab.c cpp_identifiers.c cpp_mkdeps.c cpp_pch.c \
	 cpp_directives-only.c crc32.c cse.c cselib.c dbxout.c dbgcnt.c dce.c \
	 ddg.c debug.c decContext.c decimal128.c decimal32.c decimal64.c \
	 decNumber.c df-byte-scan.c df-core.c df-problems.c df-scan.c dfp.c \
	 diagnostic.c dojump.c dominance.c domwalk.c double-int.c dse.c \
	 dwarf2asm.c dwarf2out.c dyn-string.c ebitmap.c emit-rtl.c et-forest.c \
	 except.c explow.c expmed.c expr.c fdmatch.c fibheap.c filename_cmp.c \
	 final.c fixed-value.c floatformat.c fold-const.c fopen_unlocked.c \
	 function.c fwprop.c gcse.c genrtl.c getopt1.c getopt.c getpwd.c \
	 getruntime.c ggc-common.c ggc-page.c gimple.c gimple-iterator.c \
	 gimple-low.c gimple-pretty-print.c gimplify.c graph.c graphds.c \
	 graphite.c graphite-blocking.c graphite-clast-to-gimple.c \
	 graphite-dependences.c graphite-interchange.c graphite-poly.c \
	 graphite-ppl.c graphite-scop-detection.c graphite-sese-to-poly.c \
	 gtype-desc.c haifa-sched.c hashtab.c hex.c hooks.c host-ieee128.c \
	 host-ieee32.c host-ieee64.c host-linux.c i386.c i386-c.c ifcvt.c \
	 incpath.c init-regs.c insn-attrtab.c insn-automata.c insn-emit.c \
	 insn-extract.c insn-modes.c insn-opinit.c insn-output.c insn-peep.c \
	 insn-preds.c insn-recog.c integrate.c ipa-cp.c ipa-inline.c ipa-prop.c \
	 ipa-pure-const.c ipa-reference.c ipa-struct-reorg.c ipa-type-escape.c \
	 ipa-utils.c ipa.c ira.c ira-build.c ira-costs.c ira-conflicts.c \
	 ira-color.c ira-emit.c ira-lives.c jump.c lambda-code.c lambda-mat.c \
	 lambda-trans.c langhooks.c lbasename.c lcm.c lists.c loop-doloop.c \
	 loop-init.c loop-invariant.c loop-iv.c loop-unroll.c loop-unswitch.c \
	 lower-subreg.c lrealpath.c lto-cgraph.c lto-streamer-in.c \
	 lto-streamer-out.c lto-section-in.c lto-section-out.c lto-symtab.c \
	 lto-opts.c lto-streamer.c lto-wpa-fixup.c make-relative-prefix.c \
	 make-temp-file.c partition.c matrix-reorg.c mcf.c md5.c mkstemps.c \
	 mode-switching.c modulo-sched.c objalloc.c obstack.c omega.c omp-low.c \
	 optabs.c options.c opts-common.c opts.c params.c passes.c physmem.c \
	 plugin.c pointer-set.c postreload-gcse.c postreload.c predict.c \
	 pretty-print.c print-rtl.c print-tree.c profile.c recog.c reg-stack.c \
	 regcprop.c regex.c reginfo.c regmove.c regrename.c regstat.c reload.c \
	 reload1.c reorg.c resource.c rtl-error.c rtl.c rtlanal.c rtlhooks.c \
	 safe-ctype.c sbitmap.c sched-deps.c sched-ebb.c sched-rgn.c sched-vis.c \
	 sdbout.c sel-sched-ir.c sel-sched-dump.c sel-sched.c sese.c sha1.c \
	 simplify-rtx.c sort.c spaces.c sparseset.c splay-tree.c sreal.c \
	 stack-ptr-mod.c statistics.c stmt.c stor-layout.c store-motion.c \
	 stringpool.c strsignal.c stub-objc.c targhooks.c timevar.c tracer.c \
	 tree-affine.c tree-call-cdce.c tree-cfg.c tree-cfgcleanup.c tree-chrec.c \
	 tree-complex.c tree-data-ref.c tree-dfa.c tree-dump.c tree-eh.c \
	 tree-if-conv.c tree-inline.c tree-into-ssa.c tree-iterator.c \
	 tree-loop-distribution.c tree-loop-linear.c tree-mudflap.c tree-nested.c \
	 tree-nrv.c tree-object-size.c tree-optimize.c tree-outof-ssa.c \
	 tree-parloops.c tree-phinodes.c tree-predcom.c tree-pretty-print.c \
	 tree-profile.c tree-scalar-evolution.c tree-sra.c \
	 tree-switch-conversion.c tree-ssa-address.c tree-ssa-alias.c \
	 tree-ssa-ccp.c tree-ssa-coalesce.c tree-ssa-copy.c tree-ssa-copyrename.c \
	 tree-ssa-dce.c tree-ssa-dom.c tree-ssa-dse.c tree-ssa-forwprop.c \
	 tree-ssa-ifcombine.c tree-ssa-live.c tree-ssa-loop-ch.c \
	 tree-ssa-loop-im.c tree-ssa-loop-ivcanon.c tree-ssa-loop-ivopts.c \
	 tree-ssa-loop-manip.c tree-ssa-loop-niter.c tree-ssa-loop-prefetch.c \
	 tree-ssa-loop-unswitch.c tree-ssa-loop.c tree-ssa-math-opts.c \
	 tree-ssa-operands.c tree-ssa-phiopt.c tree-ssa-phiprop.c tree-ssa-pre.c \
	 tree-ssa-propagate.c tree-ssa-reassoc.c tree-ssa-sccvn.c tree-ssa-sink.c \
	 tree-ssa-structalias.c tree-ssa-ter.c tree-ssa-threadedge.c \
	 tree-ssa-threadupdate.c tree-ssa-uncprop.c tree-ssa.c tree-ssanames.c \
	 tree-stdarg.c tree-tailcall.c tree-vect-generic.c tree-vect-patterns.c \
	 tree-vect-data-refs.c tree-vect-stmts.c tree-vect-loop.c \
	 tree-vect-loop-manip.c tree-vect-slp.c tree-vectorizer.c tree-vrp.c \
	 tree.c unlink-if-ordinary.c value-prof.c var-tracking.c varpool.c \
	 varasm.c varray.c vec.c vmsdbgout.c web.c xatexit.c xcoffout.c xexit.c \
	 xmalloc.c xmemdup.c xstrdup.c xstrerror.c xstrndup.c c-cppbuiltin.c \
	 c-pch.c cpp_files.c cpp_init.c cppdefault.c intl.c prefix.c strerror.c \
	 toplev.c vasprintf.c version.c builtins.c real.c mini-gmp.c \
	 spec_qsort/spec_qsort.c
EXEBASE=sgcc
NEED_MATH=yes
BENCHLANG=C

BENCH_FLAGS      = -I. -I./include -I./spec_qsort -DSPEC_602 -DIN_GCC -DHAVE_CONFIG_H
CC               = $(SPECLANG)gcc-8     -std=c99   -m64
CC_VERSION_OPTION = -v
CXX              = $(SPECLANG)g++-8     -std=c++03 -m64
CXX_VERSION_OPTION = -v
EXTRA_COPTIMIZE  = -fgnu89-inline
EXTRA_OPTIMIZE   = -fopenmp -DSPEC_OPENMP
EXTRA_PORTABILITY = -DSPEC_LP64
FC               = $(SPECLANG)gfortran-8           -m64
FC_VERSION_OPTION = -v
OPTIMIZE         = -O3 -march=native -fno-unsafe-math-optimizations  -fno-tree-loop-vectorize
OS               = unix
SPECLANG         = /volatile/zephyr/wayedt/linuxbrew_updated/opt/gcc@8/bin/
absolutely_no_locking = 0
abstol           = 
action           = validate
allow_label_override = 0
backup_config    = 1
baseexe          = sgcc
basepeak         = 0
benchdir         = benchspec
benchmark        = 602.gcc_s
binary           = 
bindir           = exe
builddir         = build
bundleaction     = 
bundlename       = 
calctol          = 0
changedhash      = 0
check_version    = 0
clean_between_builds = no
command_add_redirect = 1
commanderrfile   = speccmds.err
commandexe       = sgcc_peak.collect-build-flags-m64
commandfile      = speccmds.cmd
commandoutfile   = speccmds.out
commandstdoutfile = speccmds.stdout
comparedir       = compare
compareerrfile   = compare.err
comparefile      = compare.cmd
compareoutfile   = compare.out
comparestdoutfile = compare.stdout
compile_error    = 0
compwhite        = 
configdir        = config
configfile       = collect-build-flags.cfg
configpath       = /scratch/wayedt/spec2017_root/config/collect-build-flags.cfg
copies           = 1
current_range    = 
datadir          = data
default_size     = ref
default_submit   = $command
delay            = 0
deletebinaries   = 0
deletework       = 0
dependent_workloads = 0
device           = 
difflines        = 10
dirprot          = 511
discard_power_samples = 0
enable_monitor   = 1
endian           = 12345678
env_vars         = 0
expand_notes     = 0
expid            = 
exthash_bits     = 256
failflags        = 0
fake             = 0
feedback         = 1
flag_url_base    = https://www.spec.org/auto/cpu2017/Docs/benchmarks/flags/
floatcompare     = 1
force_monitor    = 0
from_runcpu      = 2
fw_bios          = 
hostname         = n235.local
http_proxy       = 
http_timeout     = 30
hw_avail         = 
hw_cpu_max_mhz   = 
hw_cpu_name      = could not determine
hw_cpu_nominal_mhz = 
hw_disk          = 50 TB  add more disk info here
hw_memory        = 'N GB (N x N GB nRxn PC4-nnnnX-X)'
hw_memory001     = format is 'n GB (n x n GB nRxn PCn-nnnnnR-n, ECC)' part 001
hw_memory002     = format is 'n GB (n x n GB nRxn PCn-nnnnnR-n, ECC)' part 002
hw_model         = 
hw_nchips        = could not determine
hw_ncores        = 
hw_ncpuorder     = 
hw_nthreadspercore = 
hw_ocache        = 
hw_other         = 
hw_pcache        = 
hw_scache        = 
hw_tcache        = 
hw_vendor        = My Corporation
idle_current_range = 
idledelay        = 10
idleduration     = 60
ignore_errors    = 1
ignore_sigint    = 0
ignorecase       = 
info_wrap_columns = 50
inputdir         = input
inputgenerrfile  = inputgen.err
inputgenfile     = inputgen.cmd
inputgenoutfile  = inputgen.out
inputgenstdoutfile = inputgen.stdout
iteration        = -1
iterations       = 1
keeptmp          = 0
label            = collect-build-flags-m64
license_num      = nnn (Your SPEC license number)
line_width       = 1020
link_input_files = 1
locking          = 1
log              = CPU2017
log_line_width   = 1020
log_timestamp    = 0
logfile          = /scratch/wayedt/spec2017_root/tmp/CPU2017.007/templogs/preenv.intspeed.007.1
logname          = /scratch/wayedt/spec2017_root/tmp/CPU2017.007/templogs/preenv.intspeed.007.1
lognum           = 007.1
mail_reports     = all
mailcompress     = 0
mailmethod       = smtp
mailport         = 25
mailserver       = 127.0.0.1
mailto           = 
make             = specmake
make_no_clobber  = 0
makefile_template = Makefile.YYYtArGeTYYYspec
makeflags        = --jobs=8
max_average_uncertainty = 1
max_hum_limit    = 0
max_report_runs  = 3
max_unknown_uncertainty = 1
mean_anyway      = 1
meter_connect_timeout = 30
meter_errors_default = 5
meter_errors_percentage = 5
min_report_runs  = 2
min_temp_limit   = 20
minimize_builddirs = 0
minimize_rundirs = 0
name             = gcc_s
nansupport       = no
need_math        = yes
no_input_handler = close
no_monitor       = 
noratios         = 0
note_preenv      = 1
notes_plat_sysinfo_000 =  Sysinfo program /scratch/wayedt/spec2017_root/bin/sysinfo
notes_plat_sysinfo_005 =  Rev: r5974 of 2018-05-19 9bcde8f2999c33d61f64985e45859ea9
notes_plat_sysinfo_010 =  running on n235.local Wed Jun 23 20:55:45 2021
notes_plat_sysinfo_015 = 
notes_plat_sysinfo_020 =  SUT (System Under Test) info as seen by some common utilities.
notes_plat_sysinfo_025 =  For more information on this section, see
notes_plat_sysinfo_030 =     https://www.spec.org/cpu2017/Docs/config.html\#sysinfo
notes_plat_sysinfo_035 = 
notes_plat_sysinfo_040 =  From /proc/cpuinfo
notes_plat_sysinfo_045 =  *
notes_plat_sysinfo_050 =  * Did not identify cpu model.  If you would
notes_plat_sysinfo_055 =  * like to write your own sysinfo program, see
notes_plat_sysinfo_060 =  * www.spec.org/cpu2017/config.html\#sysinfo
notes_plat_sysinfo_065 =  *
notes_plat_sysinfo_070 =  *
notes_plat_sysinfo_075 =  * 0 "physical id" tags found.  Perhaps this is an older system,
notes_plat_sysinfo_080 =  * or a virtualized system.  Not attempting to guess how to
notes_plat_sysinfo_085 =  * count chips/cores for this system.
notes_plat_sysinfo_090 =  *
notes_plat_sysinfo_095 =         "processors"
notes_plat_sysinfo_100 =     cores, siblings (Caution: counting these is hw and system dependent. The following
notes_plat_sysinfo_105 =     excerpts from /proc/cpuinfo might not be reliable.  Use with caution.)
notes_plat_sysinfo_110 = 
notes_plat_sysinfo_115 =  From lscpu:
notes_plat_sysinfo_120 =       Architecture:        x86_64
notes_plat_sysinfo_125 =       CPU op-mode(s):      32-bit, 64-bit
notes_plat_sysinfo_130 =       Byte Order:          Little Endian
notes_plat_sysinfo_135 =       CPU(s):              16
notes_plat_sysinfo_140 =       On-line CPU(s) list: 0-15
notes_plat_sysinfo_145 =       Thread(s) per core:  1
notes_plat_sysinfo_150 =       Core(s) per socket:  8
notes_plat_sysinfo_155 =       Socket(s):           2
notes_plat_sysinfo_160 =       NUMA node(s):        2
notes_plat_sysinfo_165 =       Vendor ID:           GenuineIntel
notes_plat_sysinfo_170 =       CPU family:          6
notes_plat_sysinfo_175 =       Model:               45
notes_plat_sysinfo_180 =       Model name:          Intel(R) Xeon(R) CPU E5-2660 0 @ 2.20GHz
notes_plat_sysinfo_185 =       Stepping:            7
notes_plat_sysinfo_190 =       CPU MHz:             2699.914
notes_plat_sysinfo_195 =       CPU max MHz:         3000.0000
notes_plat_sysinfo_200 =       CPU min MHz:         1200.0000
notes_plat_sysinfo_205 =       BogoMIPS:            4399.66
notes_plat_sysinfo_210 =       Virtualization:      VT-x
notes_plat_sysinfo_215 =       L1d cache:           32K
notes_plat_sysinfo_220 =       L1i cache:           32K
notes_plat_sysinfo_225 =       L2 cache:            256K
notes_plat_sysinfo_230 =       L3 cache:            20480K
notes_plat_sysinfo_235 =       NUMA node0 CPU(s):   0,2,4,6,8,10,12,14
notes_plat_sysinfo_240 =       NUMA node1 CPU(s):   1,3,5,7,9,11,13,15
notes_plat_sysinfo_245 =       Flags:               fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov
notes_plat_sysinfo_250 =       pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp
notes_plat_sysinfo_255 =       lm constant_tsc arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc aperfmperf
notes_plat_sysinfo_260 =       eagerfpu pni pclmulqdq dtes64 ds_cpl vmx smx est tm2 ssse3 cx16 xtpr pdcm pcid dca
notes_plat_sysinfo_265 =       sse4_1 sse4_2 x2apic popcnt tsc_deadline_timer aes xsave avx lahf_lm tpr_shadow vnmi
notes_plat_sysinfo_270 =       flexpriority ept vpid xsaveopt dtherm ida arat pln pts
notes_plat_sysinfo_275 =     WARNING: the 'lscpu' utility claims that 2 "Socket(s)" were seen, which does not match
notes_plat_sysinfo_280 =     the could not determine "physyical id"s seen in /proc/cpuinfo.  The tester should
notes_plat_sysinfo_285 =     verify the count independently.
notes_plat_sysinfo_290 = 
notes_plat_sysinfo_295 =  From numactl --hardware  WARNING: a numactl 'node' might or might not correspond to a
notes_plat_sysinfo_300 =  physical chip.
notes_plat_sysinfo_305 = 
notes_plat_sysinfo_310 =  From /proc/meminfo
notes_plat_sysinfo_315 =  Did not find total memory in /proc/meminfo
notes_plat_sysinfo_320 = 
notes_plat_sysinfo_325 =  /usr/bin/lsb_release -d
notes_plat_sysinfo_330 =     CentOS Linux release 7.2.1511 (Core)
notes_plat_sysinfo_335 = 
notes_plat_sysinfo_340 =  From /etc/*release* /etc/*version*
notes_plat_sysinfo_345 =     centos-release: CentOS Linux release 7.2.1511 (Core)
notes_plat_sysinfo_350 =     centos-release-upstream: Derived from Red Hat Enterprise Linux 7.2 (Source)
notes_plat_sysinfo_355 =     os-release:
notes_plat_sysinfo_360 =        NAME="CentOS Linux"
notes_plat_sysinfo_365 =        VERSION="7 (Core)"
notes_plat_sysinfo_370 =        ID="centos"
notes_plat_sysinfo_375 =        ID_LIKE="rhel fedora"
notes_plat_sysinfo_380 =        VERSION_ID="7"
notes_plat_sysinfo_385 =        PRETTY_NAME="CentOS Linux 7 (Core)"
notes_plat_sysinfo_390 =        ANSI_COLOR="0;31"
notes_plat_sysinfo_395 =        CPE_NAME="cpe:/o:centos:centos:7"
notes_plat_sysinfo_400 =     redhat-release: CentOS Linux release 7.2.1511 (Core)
notes_plat_sysinfo_405 =     system-release: CentOS Linux release 7.2.1511 (Core)
notes_plat_sysinfo_410 =     system-release-cpe: cpe:/o:centos:centos:7
notes_plat_sysinfo_415 = 
notes_plat_sysinfo_420 =  uname -a:
notes_plat_sysinfo_425 =     Linux n235.local 3.10.0-862.14.4.el7.x86_64 \#1 SMP Wed Sep 26 15:12:11 UTC 2018 x86_64
notes_plat_sysinfo_430 =     GNU/Linux
notes_plat_sysinfo_435 = 
notes_plat_sysinfo_440 =  Kernel self-reported vulnerability status:
notes_plat_sysinfo_445 = 
notes_plat_sysinfo_450 =  CVE-2017-5754 (Meltdown):          No status reported
notes_plat_sysinfo_455 =  CVE-2017-5753 (Spectre variant 1): No status reported
notes_plat_sysinfo_460 =  CVE-2017-5715 (Spectre variant 2): No status reported
notes_plat_sysinfo_465 = 
notes_plat_sysinfo_470 =  run-level 3 2021-06-22 12:56
notes_plat_sysinfo_475 = 
notes_plat_sysinfo_480 =  SPEC is set to: /scratch/wayedt/spec2017_root
notes_plat_sysinfo_485 =     Filesystem               Type   Size  Used Avail Use% Mounted on
notes_plat_sysinfo_490 =     panfs://pfs.local:global panfs   50T   17T   34T  33% /panfs
notes_plat_sysinfo_495 = 
notes_plat_sysinfo_500 =  Cannot run dmidecode; consider saying 'chmod +s /usr/sbin/dmidecode'
notes_plat_sysinfo_505 = 
notes_plat_sysinfo_510 =  (End of data from sysinfo program)
notes_wrap_columns = 0
notes_wrap_indent =   
num              = 602
obiwan           = 
oldhash          = 
os_exe_ext       = 
output_format    = txt,html,cfg,pdf,csv
output_root      = 
outputdir        = output
parallel_test    = 0
parallel_test_submit = 0
parallel_test_workloads = 
path             = /scratch/wayedt/spec2017_root/benchspec/CPU/602.gcc_s
plain_train      = 1
platform         = 
power            = 0
preENV_LD_LIBRARY_PATH = %{gcc_dir}/lib64/:%{gcc_dir}/lib/:/lib64
preenv           = 0
prefix           = 
prepared_by      = wayedt  (is never output, only tags rawfile)
ranks            = 1
rawhash_bits     = 256
rebuild          = 0
reftime          = reftime
reltol           = 
reportable       = 0
resultdir        = result
review           = 0
run              = all
runcpu           = /scratch/wayedt/spec2017_root/bin/harness/runcpu --configfile collect-build-flags.cfg --action run --noreportable --nopower --runmode speed --tune peak --size refspeed intspeed --nopreenv --note-preenv --logfile /scratch/wayedt/spec2017_root/tmp/CPU2017.007/templogs/preenv.intspeed.007.1 --lognum 007.1 --from_runcpu 2
rundir           = run
runmode          = speed
safe_eval        = 1
save_build_files = 
section_specifier_fatal = 1
setprocgroup     = 1
setup_error      = 0
sigint           = 2
size             = refspeed
size_class       = ref
skipabstol       = 
skipobiwan       = 
skipreltol       = 
skiptol          = 
smarttune        = peak
specdiff         = specdiff
specrun          = specinvoke
srcalt           = 
srcdir           = src
srcsource        = /scratch/wayedt/spec2017_root/benchspec/CPU/502.gcc_r/src
stagger          = 10
strict_rundir_verify = 1
sw_avail         = 
sw_base_ptrsize  = 64-bit
sw_compiler001   = C/C++/Fortran: Version 7.2.1 of GCC, the
sw_compiler002   = GNU Compiler Collection
sw_file          = panfs
sw_os001         = CentOS Linux release 7.2.1511 (Core)
sw_os002         = 3.10.0-862.14.4.el7.x86_64
sw_other         = 
sw_peak_ptrsize  = 64-bit
sw_state         = Run level 3 (add definition here)
sysinfo_hash_bits = 256
sysinfo_program  = specperl /scratch/wayedt/spec2017_root/bin/sysinfo
sysinfo_program_hash = sysinfo:SHA:32259ebd59f3e93740723202f27c44c82ee68e0f2e40cd2ca50cfd5519772397
table            = 1
teeout           = 0
test_date        = Jun-2021
test_sponsor     = My Corporation
tester           = My Corporation
threads          = 4
top              = /scratch/wayedt/spec2017_root
train_single_thread = 0
train_with       = train
tune             = peak
uid              = 100358403
unbuffer         = 1
uncertainty_exception = 5
update           = 0
update_url       = http://www.spec.org/auto/cpu2017/updates/
use_submit_for_compare = 0
use_submit_for_speed = 0
username         = wayedt
verbose          = 5
verify_binaries  = 1
version          = 0.905000
version_url      = http://www.spec.org/auto/cpu2017/current_version
voltage_range    = 
worklist         = list
OUTPUT_RMFILES   = 200.opts-O3_-finline-limit_50000.s scilab.opts-O3_-finline-limit_50000.s train01.opts-O3_-finline-limit_50000.s
