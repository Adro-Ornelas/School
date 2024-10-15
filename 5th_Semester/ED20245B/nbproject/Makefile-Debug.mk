#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/LDLCIRCIPCNC.o \
	${OBJECTDIR}/LDLCIRCIVSNC.o \
	${OBJECTDIR}/LDLTNIPSNC.o \
	${OBJECTDIR}/LSLCIRCIPCNC.o \
	${OBJECTDIR}/LSLCIRCIPSNC.o \
	${OBJECTDIR}/LSLCIRCIVCNC.o \
	${OBJECTDIR}/LSLCIRCIVSNC.o \
	${OBJECTDIR}/LSLTNIPCNC.o \
	${OBJECTDIR}/LSLTNIPSNC.o \
	${OBJECTDIR}/LSLTNIVCNC.o \
	${OBJECTDIR}/LSLTNIVSNC.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ed20245b.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ed20245b.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ed20245b ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/LDLCIRCIPCNC.o: LDLCIRCIPCNC.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LDLCIRCIPCNC.o LDLCIRCIPCNC.cpp

${OBJECTDIR}/LDLCIRCIVSNC.o: LDLCIRCIVSNC.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LDLCIRCIVSNC.o LDLCIRCIVSNC.cpp

${OBJECTDIR}/LDLTNIPSNC.o: LDLTNIPSNC.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LDLTNIPSNC.o LDLTNIPSNC.cpp

${OBJECTDIR}/LSLCIRCIPCNC.o: LSLCIRCIPCNC.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LSLCIRCIPCNC.o LSLCIRCIPCNC.cpp

${OBJECTDIR}/LSLCIRCIPSNC.o: LSLCIRCIPSNC.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LSLCIRCIPSNC.o LSLCIRCIPSNC.cpp

${OBJECTDIR}/LSLCIRCIVCNC.o: LSLCIRCIVCNC.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LSLCIRCIVCNC.o LSLCIRCIVCNC.cpp

${OBJECTDIR}/LSLCIRCIVSNC.o: LSLCIRCIVSNC.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LSLCIRCIVSNC.o LSLCIRCIVSNC.cpp

${OBJECTDIR}/LSLTNIPCNC.o: LSLTNIPCNC.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LSLTNIPCNC.o LSLTNIPCNC.cpp

${OBJECTDIR}/LSLTNIPSNC.o: LSLTNIPSNC.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LSLTNIPSNC.o LSLTNIPSNC.cpp

${OBJECTDIR}/LSLTNIVCNC.o: LSLTNIVCNC.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LSLTNIVCNC.o LSLTNIVCNC.cpp

${OBJECTDIR}/LSLTNIVSNC.o: LSLTNIVSNC.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LSLTNIVSNC.o LSLTNIVSNC.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
