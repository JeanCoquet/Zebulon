#############################################################################
# Makefile for building: dist/Debug/GNU-Linux-x86/Zebulon
# Generated by qmake (2.01a) (Qt 4.7.4) on: Thu Mar 22 21:03:16 2012
# Project:  nbproject/qt-Debug.pro
# Template: app
# Command: /usr/bin/qmake VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -Inbproject -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -IGui/moc -IGui -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/Debug/GNU-Linux-x86/

####### Files

SOURCES       = Model/MagistralClass.cpp \
		Model/Date.cpp \
		Model/TutorialClassroom.cpp \
		Model/Module.cpp \
		Model/PracticalClass.cpp \
		Model/Controller.cpp \
		Gui/QTimeSlot.cpp \
		Model/TutorialClass.cpp \
		Gui/main.cpp \
		Model/TimeSlot.cpp \
		Model/PracticalClassroom.cpp \
		Model/ClassPeriod.cpp \
		sqlite/lib/sqlite3.c \
		Model/LectureHall.cpp \
		Model/Schedule.cpp \
		Model/Student.cpp \
		Gui/QSchedule.cpp \
		Model/Studient.cpp \
		Model/Group.cpp \
		Model/Classroom.cpp \
		Gui/WindowEditTimeSlot.cpp \
		sqlite/Database.cpp \
		Gui/mainwindow.cpp Gui/moc/moc_QSchedule.cpp \
		Gui/moc/moc_mainwindow.cpp \
		Gui/moc/moc_WindowEditTimeSlot.cpp \
		Gui/moc/moc_QTimeSlot.cpp
OBJECTS       = build/Debug/GNU-Linux-x86/MagistralClass.o \
		build/Debug/GNU-Linux-x86/Date.o \
		build/Debug/GNU-Linux-x86/TutorialClassroom.o \
		build/Debug/GNU-Linux-x86/Module.o \
		build/Debug/GNU-Linux-x86/PracticalClass.o \
		build/Debug/GNU-Linux-x86/Controller.o \
		build/Debug/GNU-Linux-x86/QTimeSlot.o \
		build/Debug/GNU-Linux-x86/TutorialClass.o \
		build/Debug/GNU-Linux-x86/main.o \
		build/Debug/GNU-Linux-x86/TimeSlot.o \
		build/Debug/GNU-Linux-x86/PracticalClassroom.o \
		build/Debug/GNU-Linux-x86/ClassPeriod.o \
		build/Debug/GNU-Linux-x86/sqlite3.o \
		build/Debug/GNU-Linux-x86/LectureHall.o \
		build/Debug/GNU-Linux-x86/Schedule.o \
		build/Debug/GNU-Linux-x86/Student.o \
		build/Debug/GNU-Linux-x86/QSchedule.o \
		build/Debug/GNU-Linux-x86/Studient.o \
		build/Debug/GNU-Linux-x86/Group.o \
		build/Debug/GNU-Linux-x86/Classroom.o \
		build/Debug/GNU-Linux-x86/WindowEditTimeSlot.o \
		build/Debug/GNU-Linux-x86/Database.o \
		build/Debug/GNU-Linux-x86/mainwindow.o \
		build/Debug/GNU-Linux-x86/moc_QSchedule.o \
		build/Debug/GNU-Linux-x86/moc_mainwindow.o \
		build/Debug/GNU-Linux-x86/moc_WindowEditTimeSlot.o \
		build/Debug/GNU-Linux-x86/moc_QTimeSlot.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		nbproject/qt-Debug.pro
QMAKE_TARGET  = Zebulon
DESTDIR       = dist/Debug/GNU-Linux-x86/
TARGET        = dist/Debug/GNU-Linux-x86/Zebulon

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: qttmp-Debug.mk $(TARGET)

$(TARGET): Gui/ui_WindowEditTimeSlot.h Gui/ui_mainwindow.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) dist/Debug/GNU-Linux-x86/ || $(MKDIR) dist/Debug/GNU-Linux-x86/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

qttmp-Debug.mk: nbproject/qt-Debug.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro

dist: 
	@$(CHK_DIR_EXISTS) build/Debug/GNU-Linux-x86/Zebulon1.0.0 || $(MKDIR) build/Debug/GNU-Linux-x86/Zebulon1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/Debug/GNU-Linux-x86/Zebulon1.0.0/ && $(COPY_FILE) --parents Gui/QSchedule.h Model/LectureHall.h Model/Controller.h sqlite/Database.h Model/PracticalClass.h sqlite/lib/sqlite3.h Gui/mainwindow.h Model/PracticalClassroom.h Model/TimeSlot.h Model/Schedule.h Model/Studient.h Model/ClassPeriod.h Gui/WindowEditTimeSlot.h Model/Group.h Gui/ui_WindowEditTimeSlot.h Gui/QTimeSlot.h Model/TutorialClassroom.h Gui/ui_mainwindow.h sqlite/lib/sqlite3ext.h Model/Module.h Model/Classroom.h Model/Date.h Model/MagistralClass.h Model/TutorialClass.h Model/Student.h build/Debug/GNU-Linux-x86/Zebulon1.0.0/ && $(COPY_FILE) --parents Model/MagistralClass.cpp Model/Date.cpp Model/TutorialClassroom.cpp Model/Module.cpp Model/PracticalClass.cpp Model/Controller.cpp Gui/QTimeSlot.cpp Model/TutorialClass.cpp Gui/main.cpp Model/TimeSlot.cpp Model/PracticalClassroom.cpp Model/ClassPeriod.cpp sqlite/lib/sqlite3.c Model/LectureHall.cpp Model/Schedule.cpp Model/Student.cpp Gui/QSchedule.cpp Model/Studient.cpp Model/Group.cpp Model/Classroom.cpp Gui/WindowEditTimeSlot.cpp sqlite/Database.cpp Gui/mainwindow.cpp build/Debug/GNU-Linux-x86/Zebulon1.0.0/ && $(COPY_FILE) --parents Gui/WindowEditTimeSlot.ui Gui/mainwindow.ui build/Debug/GNU-Linux-x86/Zebulon1.0.0/ && (cd `dirname build/Debug/GNU-Linux-x86/Zebulon1.0.0` && $(TAR) Zebulon1.0.0.tar Zebulon1.0.0 && $(COMPRESS) Zebulon1.0.0.tar) && $(MOVE) `dirname build/Debug/GNU-Linux-x86/Zebulon1.0.0`/Zebulon1.0.0.tar.gz . && $(DEL_FILE) -r build/Debug/GNU-Linux-x86/Zebulon1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) qttmp-Debug.mk


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: Gui/moc/moc_QSchedule.cpp Gui/moc/moc_mainwindow.cpp Gui/moc/moc_WindowEditTimeSlot.cpp Gui/moc/moc_QTimeSlot.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) Gui/moc/moc_QSchedule.cpp Gui/moc/moc_mainwindow.cpp Gui/moc/moc_WindowEditTimeSlot.cpp Gui/moc/moc_QTimeSlot.cpp
Gui/moc/moc_QSchedule.cpp: Gui/QTimeSlot.h \
		Gui/QSchedule.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Gui/QSchedule.h -o Gui/moc/moc_QSchedule.cpp

Gui/moc/moc_mainwindow.cpp: Gui/QSchedule.h \
		Gui/QTimeSlot.h \
		Gui/WindowEditTimeSlot.h \
		Gui/mainwindow.h \
		Gui/ui_WindowEditTimeSlot.h \
		Gui/mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Gui/mainwindow.h -o Gui/moc/moc_mainwindow.cpp

Gui/moc/moc_WindowEditTimeSlot.cpp: Gui/mainwindow.h \
		Gui/QSchedule.h \
		Gui/QTimeSlot.h \
		Gui/WindowEditTimeSlot.h \
		Gui/ui_WindowEditTimeSlot.h \
		Gui/WindowEditTimeSlot.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Gui/WindowEditTimeSlot.h -o Gui/moc/moc_WindowEditTimeSlot.cpp

Gui/moc/moc_QTimeSlot.cpp: Gui/QTimeSlot.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Gui/QTimeSlot.h -o Gui/moc/moc_QTimeSlot.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: Gui/qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) Gui/qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: Gui/ui_WindowEditTimeSlot.h Gui/ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) Gui/ui_WindowEditTimeSlot.h Gui/ui_mainwindow.h
Gui/ui_WindowEditTimeSlot.h: Gui/WindowEditTimeSlot.ui
	/usr/bin/uic-qt4 Gui/WindowEditTimeSlot.ui -o Gui/ui_WindowEditTimeSlot.h

Gui/ui_mainwindow.h: Gui/mainwindow.ui
	/usr/bin/uic-qt4 Gui/mainwindow.ui -o Gui/ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

build/Debug/GNU-Linux-x86/MagistralClass.o: Model/MagistralClass.cpp Model/MagistralClass.h \
		Model/ClassPeriod.h \
		Model/Group.h \
		Model/Student.h \
		Model/Module.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/MagistralClass.o Model/MagistralClass.cpp

build/Debug/GNU-Linux-x86/Date.o: Model/Date.cpp Model/Date.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Date.o Model/Date.cpp

build/Debug/GNU-Linux-x86/TutorialClassroom.o: Model/TutorialClassroom.cpp Model/TutorialClassroom.h \
		Model/Classroom.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/TutorialClassroom.o Model/TutorialClassroom.cpp

build/Debug/GNU-Linux-x86/Module.o: Model/Module.cpp Model/Module.h \
		Model/ClassPeriod.h \
		Model/Group.h \
		Model/Student.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Module.o Model/Module.cpp

build/Debug/GNU-Linux-x86/PracticalClass.o: Model/PracticalClass.cpp Model/PracticalClass.h \
		Model/ClassPeriod.h \
		Model/Group.h \
		Model/Student.h \
		Model/Module.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/PracticalClass.o Model/PracticalClass.cpp

build/Debug/GNU-Linux-x86/Controller.o: Model/Controller.cpp Model/Controller.h \
		Model/Student.h \
		Model/PracticalClass.h \
		Model/ClassPeriod.h \
		Model/Group.h \
		Model/Module.h \
		Model/TutorialClass.h \
		Model/MagistralClass.h \
		Model/Schedule.h \
		Model/TimeSlot.h \
		Model/Date.h \
		Model/Classroom.h \
		Model/LectureHall.h \
		Model/PracticalClassroom.h \
		Model/TutorialClassroom.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Controller.o Model/Controller.cpp

build/Debug/GNU-Linux-x86/QTimeSlot.o: Gui/QTimeSlot.cpp Gui/QTimeSlot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/QTimeSlot.o Gui/QTimeSlot.cpp

build/Debug/GNU-Linux-x86/TutorialClass.o: Model/TutorialClass.cpp Model/TutorialClass.h \
		Model/ClassPeriod.h \
		Model/Group.h \
		Model/Student.h \
		Model/Module.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/TutorialClass.o Model/TutorialClass.cpp

build/Debug/GNU-Linux-x86/main.o: Gui/main.cpp Gui/mainwindow.h \
		Gui/QSchedule.h \
		Gui/QTimeSlot.h \
		Gui/WindowEditTimeSlot.h \
		Gui/ui_WindowEditTimeSlot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/main.o Gui/main.cpp

build/Debug/GNU-Linux-x86/TimeSlot.o: Model/TimeSlot.cpp Model/TimeSlot.h \
		Model/Date.h \
		Model/Classroom.h \
		Model/ClassPeriod.h \
		Model/Group.h \
		Model/Student.h \
		Model/Module.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/TimeSlot.o Model/TimeSlot.cpp

build/Debug/GNU-Linux-x86/PracticalClassroom.o: Model/PracticalClassroom.cpp Model/PracticalClassroom.h \
		Model/Classroom.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/PracticalClassroom.o Model/PracticalClassroom.cpp

build/Debug/GNU-Linux-x86/ClassPeriod.o: Model/ClassPeriod.cpp Model/ClassPeriod.h \
		Model/Group.h \
		Model/Student.h \
		Model/Module.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/ClassPeriod.o Model/ClassPeriod.cpp

build/Debug/GNU-Linux-x86/sqlite3.o: sqlite/lib/sqlite3.c 
	$(CC) -c $(CFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/sqlite3.o sqlite/lib/sqlite3.c

build/Debug/GNU-Linux-x86/LectureHall.o: Model/LectureHall.cpp Model/LectureHall.h \
		Model/Classroom.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/LectureHall.o Model/LectureHall.cpp

build/Debug/GNU-Linux-x86/Schedule.o: Model/Schedule.cpp Model/Schedule.h \
		Model/TimeSlot.h \
		Model/Date.h \
		Model/Classroom.h \
		Model/ClassPeriod.h \
		Model/Group.h \
		Model/Student.h \
		Model/Module.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Schedule.o Model/Schedule.cpp

build/Debug/GNU-Linux-x86/Student.o: Model/Student.cpp Model/Student.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Student.o Model/Student.cpp

build/Debug/GNU-Linux-x86/QSchedule.o: Gui/QSchedule.cpp Gui/QSchedule.h \
		Gui/QTimeSlot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/QSchedule.o Gui/QSchedule.cpp

build/Debug/GNU-Linux-x86/Studient.o: Model/Studient.cpp Model/Studient.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Studient.o Model/Studient.cpp

build/Debug/GNU-Linux-x86/Group.o: Model/Group.cpp Model/Group.h \
		Model/Student.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Group.o Model/Group.cpp

build/Debug/GNU-Linux-x86/Classroom.o: Model/Classroom.cpp Model/Classroom.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Classroom.o Model/Classroom.cpp

build/Debug/GNU-Linux-x86/WindowEditTimeSlot.o: Gui/WindowEditTimeSlot.cpp Gui/WindowEditTimeSlot.h \
		Gui/mainwindow.h \
		Gui/QSchedule.h \
		Gui/QTimeSlot.h \
		Gui/ui_WindowEditTimeSlot.h \
		Gui/ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/WindowEditTimeSlot.o Gui/WindowEditTimeSlot.cpp

build/Debug/GNU-Linux-x86/Database.o: sqlite/Database.cpp sqlite/Database.h \
		sqlite/lib/sqlite3.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Database.o sqlite/Database.cpp

build/Debug/GNU-Linux-x86/mainwindow.o: Gui/mainwindow.cpp Gui/mainwindow.h \
		Gui/QSchedule.h \
		Gui/QTimeSlot.h \
		Gui/WindowEditTimeSlot.h \
		Gui/ui_WindowEditTimeSlot.h \
		Gui/ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/mainwindow.o Gui/mainwindow.cpp

build/Debug/GNU-Linux-x86/moc_QSchedule.o: Gui/moc/moc_QSchedule.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_QSchedule.o Gui/moc/moc_QSchedule.cpp

build/Debug/GNU-Linux-x86/moc_mainwindow.o: Gui/moc/moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_mainwindow.o Gui/moc/moc_mainwindow.cpp

build/Debug/GNU-Linux-x86/moc_WindowEditTimeSlot.o: Gui/moc/moc_WindowEditTimeSlot.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_WindowEditTimeSlot.o Gui/moc/moc_WindowEditTimeSlot.cpp

build/Debug/GNU-Linux-x86/moc_QTimeSlot.o: Gui/moc/moc_QTimeSlot.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_QTimeSlot.o Gui/moc/moc_QTimeSlot.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

