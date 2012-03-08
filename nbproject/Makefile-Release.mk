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
<<<<<<< HEAD
QMAKE=qmake
=======
>>>>>>> 147c2b0285400e32547caa52d601089228d27cb9

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
<<<<<<< HEAD
OBJECTFILES=
=======
OBJECTFILES= \
	${OBJECTDIR}/ClassPeriod.o \
	${OBJECTDIR}/TutorialClassroom.o \
	${OBJECTDIR}/Controller.o \
	${OBJECTDIR}/Group.o \
	${OBJECTDIR}/Gui/moc_QSchedule.o \
	${OBJECTDIR}/Student.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Module.o \
	${OBJECTDIR}/Gui/QTimeSlot.o \
	${OBJECTDIR}/MagistralClass.o \
	${OBJECTDIR}/Gui/moc_QTimeSlot.o \
	${OBJECTDIR}/Gui/moc_mainwindow.o \
	${OBJECTDIR}/PracticalClass.o \
	${OBJECTDIR}/Gui/main.o \
	${OBJECTDIR}/Classroom.o \
	${OBJECTDIR}/sqlite/lib/sqlite3.o \
	${OBJECTDIR}/LectureHall.o \
	${OBJECTDIR}/Gui/QSchedule.o \
	${OBJECTDIR}/TimeSlot.o \
	${OBJECTDIR}/Schedule.o \
	${OBJECTDIR}/TutorialClass.o \
	${OBJECTDIR}/Date.o \
	${OBJECTDIR}/Gui/windowEditTimeSlot.o \
	${OBJECTDIR}/PracticalClassroom.o \
	${OBJECTDIR}/sqlite/Database.o \
	${OBJECTDIR}/Gui/mainwindow.o
>>>>>>> 147c2b0285400e32547caa52d601089228d27cb9


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

<<<<<<< HEAD
nbproject/qt-${CND_CONF}.mk: nbproject/qt-${CND_CONF}.pro FORCE
	${QMAKE} VPATH=. -o qttmp-${CND_CONF}.mk nbproject/qt-${CND_CONF}.pro
	mv -f qttmp-${CND_CONF}.mk nbproject/qt-${CND_CONF}.mk

FORCE:

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS} nbproject/qt-${CND_CONF}.mk
	"${MAKE}" -f nbproject/qt-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/Zebulon

${CND_BUILDDIR}/Release/%.o: nbproject/qt-${CND_CONF}.mk
	${MAKE} -f nbproject/qt-${CND_CONF}.mk "$@"
=======
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

${OBJECTDIR}/Gui/moc_QSchedule.o: Gui/moc_QSchedule.cpp 
	${MKDIR} -p ${OBJECTDIR}/Gui
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Gui/moc_QSchedule.o Gui/moc_QSchedule.cpp

${OBJECTDIR}/Student.o: Student.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Student.o Student.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Module.o: Module.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Module.o Module.cpp

${OBJECTDIR}/Gui/QTimeSlot.o: Gui/QTimeSlot.cpp 
	${MKDIR} -p ${OBJECTDIR}/Gui
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Gui/QTimeSlot.o Gui/QTimeSlot.cpp

${OBJECTDIR}/MagistralClass.o: MagistralClass.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/MagistralClass.o MagistralClass.cpp

${OBJECTDIR}/Gui/moc_QTimeSlot.o: Gui/moc_QTimeSlot.cpp 
	${MKDIR} -p ${OBJECTDIR}/Gui
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Gui/moc_QTimeSlot.o Gui/moc_QTimeSlot.cpp

${OBJECTDIR}/Gui/moc_mainwindow.o: Gui/moc_mainwindow.cpp 
	${MKDIR} -p ${OBJECTDIR}/Gui
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Gui/moc_mainwindow.o Gui/moc_mainwindow.cpp

${OBJECTDIR}/PracticalClass.o: PracticalClass.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/PracticalClass.o PracticalClass.cpp

${OBJECTDIR}/Gui/main.o: Gui/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/Gui
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Gui/main.o Gui/main.cpp

${OBJECTDIR}/Classroom.o: Classroom.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Classroom.o Classroom.cpp

${OBJECTDIR}/sqlite/lib/sqlite3.o: sqlite/lib/sqlite3.c 
	${MKDIR} -p ${OBJECTDIR}/sqlite/lib
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/sqlite/lib/sqlite3.o sqlite/lib/sqlite3.c

${OBJECTDIR}/LectureHall.o: LectureHall.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/LectureHall.o LectureHall.C

${OBJECTDIR}/Gui/QSchedule.o: Gui/QSchedule.cpp 
	${MKDIR} -p ${OBJECTDIR}/Gui
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Gui/QSchedule.o Gui/QSchedule.cpp

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

${OBJECTDIR}/Gui/windowEditTimeSlot.o: Gui/windowEditTimeSlot.cpp 
	${MKDIR} -p ${OBJECTDIR}/Gui
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Gui/windowEditTimeSlot.o Gui/windowEditTimeSlot.cpp

${OBJECTDIR}/PracticalClassroom.o: PracticalClassroom.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/PracticalClassroom.o PracticalClassroom.cpp

${OBJECTDIR}/sqlite/Database.o: sqlite/Database.cpp 
	${MKDIR} -p ${OBJECTDIR}/sqlite
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/sqlite/Database.o sqlite/Database.cpp

${OBJECTDIR}/Gui/mainwindow.o: Gui/mainwindow.cpp 
	${MKDIR} -p ${OBJECTDIR}/Gui
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Gui/mainwindow.o Gui/mainwindow.cpp
>>>>>>> 147c2b0285400e32547caa52d601089228d27cb9

# Subprojects
.build-subprojects:

# Clean Targets
<<<<<<< HEAD
.clean-conf: ${CLEAN_SUBPROJECTS} nbproject/qt-${CND_CONF}.mk
	${MAKE} -f nbproject/qt-${CND_CONF}.mk distclean

# Subprojects
.clean-subprojects:
=======
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/zebulon

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
>>>>>>> 147c2b0285400e32547caa52d601089228d27cb9
