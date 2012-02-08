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
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ClassPeriod.o \
	${OBJECTDIR}/TutorialClassroom.o \
	${OBJECTDIR}/Controller.o \
	${OBJECTDIR}/Group.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Module.o \
	${OBJECTDIR}/MagistralClass.o \
	${OBJECTDIR}/PracticalClass.o \
	${OBJECTDIR}/Classroom.o \
	${OBJECTDIR}/LectureHall.o \
	${OBJECTDIR}/TimeSlot.o \
	${OBJECTDIR}/Schedule.o \
	${OBJECTDIR}/TutorialClass.o \
	${OBJECTDIR}/Date.o \
	${OBJECTDIR}/Subject.o \
	${OBJECTDIR}/Studient.o \
	${OBJECTDIR}/PracticalClassroom.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/zebulon

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/zebulon: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/zebulon ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/ClassPeriod.o: ClassPeriod.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ClassPeriod.o ClassPeriod.cpp

${OBJECTDIR}/TutorialClassroom.o: TutorialClassroom.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/TutorialClassroom.o TutorialClassroom.C

${OBJECTDIR}/Controller.o: Controller.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Controller.o Controller.cpp

${OBJECTDIR}/Group.o: Group.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Group.o Group.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Module.o: Module.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Module.o Module.cpp

${OBJECTDIR}/MagistralClass.o: MagistralClass.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/MagistralClass.o MagistralClass.cpp

${OBJECTDIR}/PracticalClass.o: PracticalClass.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/PracticalClass.o PracticalClass.cpp

${OBJECTDIR}/Classroom.o: Classroom.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Classroom.o Classroom.cpp

${OBJECTDIR}/LectureHall.o: LectureHall.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/LectureHall.o LectureHall.C

${OBJECTDIR}/TimeSlot.o: TimeSlot.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/TimeSlot.o TimeSlot.cpp

${OBJECTDIR}/Schedule.o: Schedule.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Schedule.o Schedule.cpp

${OBJECTDIR}/TutorialClass.o: TutorialClass.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/TutorialClass.o TutorialClass.cpp

${OBJECTDIR}/Date.o: Date.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Date.o Date.cpp

${OBJECTDIR}/Subject.o: Subject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Subject.o Subject.cpp

${OBJECTDIR}/Studient.o: Studient.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Studient.o Studient.cpp

${OBJECTDIR}/PracticalClassroom.o: PracticalClassroom.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/PracticalClassroom.o PracticalClassroom.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/zebulon

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
