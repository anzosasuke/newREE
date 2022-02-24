-E BASH_ENV /usr/share/lmod/lmod/init/bash
-E BASH_FUNC_ml() '() {  eval $($LMOD_DIR/ml_cmd "$@") }'
-E BASH_FUNC_module() '() {  eval $($LMOD_CMD bash "$@");  [ $? = 0 ] && eval $(${LMOD_SETTARG_CMD:-:} -s sh) }'
-E HISTCONTROL ignoredups
-E HISTSIZE 1000
-E HOME /users/s181p983
-E HOSTNAME login1.ittc.ku.edu
-E LANG en_US.UTF-8
-E LC_ALL C
-E LC_LANG C
-E LD_LIBRARY_PATH /usr/lib64/:/usr/lib/:/lib64
-E LESSOPEN '||/usr/bin/lesspipe.sh %s'
-E LIBC_FATAL_STDERR_ 1
-E LMOD_CMD /usr/share/lmod/lmod/libexec/lmod
-E LMOD_COLORIZE yes
-E LMOD_DIR /usr/share/lmod/lmod/libexec
-E LMOD_FULL_SETTARG_SUPPORT no
-E LMOD_PKG /usr/share/lmod/lmod
-E LMOD_PREPEND_BLOCK normal
-E LMOD_SETTARG_CMD :
-E LMOD_VERSION 6.3.4
-E LMOD_arch x86_64
-E LMOD_sys Linux
-E LOGNAME s181p983
-E LS_COLORS 'rs=0:di=38;5;27:ln=38;5;51:mh=44;38;5;15:pi=40;38;5;11:so=38;5;13:do=38;5;5:bd=48;5;232;38;5;11:cd=48;5;232;38;5;3:or=48;5;232;38;5;9:mi=05;48;5;232;38;5;15:su=48;5;196;38;5;15:sg=48;5;11;38;5;16:ca=48;5;196;38;5;226:tw=48;5;10;38;5;16:ow=48;5;10;38;5;21:st=48;5;21;38;5;15:ex=38;5;34:*.tar=38;5;9:*.tgz=38;5;9:*.arc=38;5;9:*.arj=38;5;9:*.taz=38;5;9:*.lha=38;5;9:*.lz4=38;5;9:*.lzh=38;5;9:*.lzma=38;5;9:*.tlz=38;5;9:*.txz=38;5;9:*.tzo=38;5;9:*.t7z=38;5;9:*.zip=38;5;9:*.z=38;5;9:*.Z=38;5;9:*.dz=38;5;9:*.gz=38;5;9:*.lrz=38;5;9:*.lz=38;5;9:*.lzo=38;5;9:*.xz=38;5;9:*.bz2=38;5;9:*.bz=38;5;9:*.tbz=38;5;9:*.tbz2=38;5;9:*.tz=38;5;9:*.deb=38;5;9:*.rpm=38;5;9:*.jar=38;5;9:*.war=38;5;9:*.ear=38;5;9:*.sar=38;5;9:*.rar=38;5;9:*.alz=38;5;9:*.ace=38;5;9:*.zoo=38;5;9:*.cpio=38;5;9:*.7z=38;5;9:*.rz=38;5;9:*.cab=38;5;9:*.jpg=38;5;13:*.jpeg=38;5;13:*.gif=38;5;13:*.bmp=38;5;13:*.pbm=38;5;13:*.pgm=38;5;13:*.ppm=38;5;13:*.tga=38;5;13:*.xbm=38;5;13:*.xpm=38;5;13:*.tif=38;5;13:*.tiff=38;5;13:*.png=38;5;13:*.svg=38;5;13:*.svgz=38;5;13:*.mng=38;5;13:*.pcx=38;5;13:*.mov=38;5;13:*.mpg=38;5;13:*.mpeg=38;5;13:*.m2v=38;5;13:*.mkv=38;5;13:*.webm=38;5;13:*.ogm=38;5;13:*.mp4=38;5;13:*.m4v=38;5;13:*.mp4v=38;5;13:*.vob=38;5;13:*.qt=38;5;13:*.nuv=38;5;13:*.wmv=38;5;13:*.asf=38;5;13:*.rm=38;5;13:*.rmvb=38;5;13:*.flc=38;5;13:*.avi=38;5;13:*.fli=38;5;13:*.flv=38;5;13:*.gl=38;5;13:*.dl=38;5;13:*.xcf=38;5;13:*.xwd=38;5;13:*.yuv=38;5;13:*.cgm=38;5;13:*.emf=38;5;13:*.axv=38;5;13:*.anx=38;5;13:*.ogv=38;5;13:*.ogx=38;5;13:*.aac=38;5;45:*.au=38;5;45:*.flac=38;5;45:*.mid=38;5;45:*.midi=38;5;45:*.mka=38;5;45:*.mp3=38;5;45:*.mpc=38;5;45:*.ogg=38;5;45:*.ra=38;5;45:*.wav=38;5;45:*.axa=38;5;45:*.oga=38;5;45:*.spx=38;5;45:*.xspf=38;5;45:'
-E MAIL /var/spool/mail/s181p983
-E MANPATH /usr/share/lmod/lmod/share/man::
-E MODULEPATH /nfs/apps/7/arch/generic/modules/all
-E MODULEPATH_ROOT /nfs/apps/7/arch/generic/modules/all
-E MODULESHOME /usr/share/lmod/lmod
-E OMP_NUM_THREADS 4
-E PATH /scratch/wayedt/spec2017_root/bin:/usr/lib64/qt-3.3/bin:/usr/local/bin:/usr/bin:/usr/local/sbin:/usr/sbin
-E QTDIR /usr/lib64/qt-3.3
-E QTINC /usr/lib64/qt-3.3/include
-E QTLIB /usr/lib64/qt-3.3/lib
-E QT_GRAPHICSSYSTEM_CHECKED 1
-E SELINUX_LEVEL_REQUESTED ''
-E SELINUX_ROLE_REQUESTED ''
-E SELINUX_USE_CURRENT_RANGE ''
-E SHELL /bin/bash
-E SPEC /scratch/wayedt/spec2017_root
-E SPECDB_PWD /scratch/wayedt/spec2017_root
-E SPECPERLLIB /scratch/wayedt/spec2017_root/bin/lib:/scratch/wayedt/spec2017_root/bin
-E SSH_ASKPASS /usr/libexec/openssh/lxqt-openssh-askpass
-E SSH_CLIENT '129.237.120.128 55452 22'
-E SSH_CONNECTION '129.237.120.128 55452 129.237.125.121 22'
-E SSH_TTY /dev/pts/7
-E TERM xterm-256color
-E USER s181p983
-E XDG_RUNTIME_DIR /run/user/100589214
-E XDG_SESSION_ID 20360
-r
-N C
-C /scratch/wayedt/spec2017_root/benchspec/CPU/602.gcc_s/run/run_base_test_mytest-m64.0000
-o t1.opts-O3_-finline-limit_50000.out -e t1.opts-O3_-finline-limit_50000.err ../run_base_test_mytest-m64.0000/sgcc_base.mytest-m64 t1.c -O3 -finline-limit=50000 -o t1.opts-O3_-finline-limit_50000.s > t1.opts-O3_-finline-limit_50000.out 2>> t1.opts-O3_-finline-limit_50000.err
