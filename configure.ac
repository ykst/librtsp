#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([librtsp], [1.00])

#######################
# ARM
AC_ARG_ENABLE(
    [cross-prefix], 
    AS_HELP_STRING([--enable-cross-prefix=ARG],[cross compiler prefix]),
    [CROSS_PREFIX=$enableval],
    [CROSS_PREFIX=])

AC_SUBST([CROSS_PREFIX])

CC=["${CROSS_PREFIX}gcc"]
AC_SUBST([CC])

STRIP=["${CROSS_PREFIX}strip"]
AC_SUBST([STRIP])

AR=["${CROSS_PREFIX}ar"]
AC_SUBST([AR])

RANLIB=["${CROSS_PREFIX}ranlib"]
AC_SUBST([RANLIB])

#####################
# Project directory
PROJECT_ROOTDIR=[$(pwd)]
AC_SUBST([PROJECT_ROOTDIR])

INC_DIR=$PROJECT_ROOTDIR/include
AC_SUBST([INC_DIR])

SRC_DIR=$PROJECT_ROOTDIR/src
AC_SUBST([SRC_DIR])

LIB_DIR=$PROJECT_ROOTDIR/lib
AC_SUBST([LIB_DIR])

###############
# Target 
AC_ARG_ENABLE(
    [target-dir], 
    AS_HELP_STRING([--enable-target-dir=ARG],[where target root filesys exists]),
    [MASTER_ROOTDIR=$enableval],
    [MASTER_ROOTDIR=])
AC_SUBST([MASTER_ROOTDIR])

##################
# pre-defined commands
INSTALL=install
AC_SUBST([INSTALL])
INSTALL_DOC=["${INSTALL} -o root -g root -p -m 644"]
AC_SUBST([INSTALL_DOC])
INSTALL_APP=["${INSTALL} -o root -g root -p -m 755"]

AC_SUBST([INSTALL_APP])
AC_CONFIG_FILES([Makefile
                src/Makefile])

AC_OUTPUT
