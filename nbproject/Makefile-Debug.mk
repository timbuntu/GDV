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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/bab0b6eb/Drone.o \
	${OBJECTDIR}/_ext/bab0b6eb/Vector.o \
	${OBJECTDIR}/_ext/bab0b6eb/Wuerfel.o \
	${OBJECTDIR}/main_drone.o


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
LDLIBSOPTIONS=-lGL -lGLU -lGLEW -lglut

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl_test

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl_test: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl_test ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/bab0b6eb/Drone.o: /home/tim/NetBeansProjects/OpenGL_Test/Drone.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/bab0b6eb
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/bab0b6eb/Drone.o /home/tim/NetBeansProjects/OpenGL_Test/Drone.cpp

${OBJECTDIR}/_ext/bab0b6eb/Vector.o: /home/tim/NetBeansProjects/OpenGL_Test/Vector.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/bab0b6eb
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/bab0b6eb/Vector.o /home/tim/NetBeansProjects/OpenGL_Test/Vector.cpp

${OBJECTDIR}/_ext/bab0b6eb/Wuerfel.o: /home/tim/NetBeansProjects/OpenGL_Test/Wuerfel.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/bab0b6eb
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/bab0b6eb/Wuerfel.o /home/tim/NetBeansProjects/OpenGL_Test/Wuerfel.cpp

${OBJECTDIR}/main_drone.o: main_drone.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_drone.o main_drone.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl_test

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
