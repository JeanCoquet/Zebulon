# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = Zebulon
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
QT = core gui
SOURCES += ClassPeriod.cpp TutorialClassroom.C Group.cpp Controller.cpp Student.cpp main.cpp Module.cpp MagistralClass.cpp Gui/QTimeSlot.cpp PracticalClass.cpp Classroom.cpp sqlite/lib/sqlite3.c LectureHall.C Gui/QSchedule.cpp TimeSlot.cpp Schedule.cpp TutorialClass.cpp Date.cpp Gui/WindowEditTimeSlot.cpp PracticalClassroom.cpp sqlite/Database.cpp Gui/mainwindow.cpp
HEADERS += TutorialClassroom.h Gui/QSchedule.h Classroom.h TimeSlot.h Date.h PracticalClass.h Group.h PracticalClassroom.h sqlite/Database.h sqlite/lib/sqlite3.h Gui/mainwindow.h Student.h Gui/WindowEditTimeSlot.h TutorialClass.h LectureHall.h Schedule.h ClassPeriod.h MagistralClass.h Gui/QTimeSlot.h sqlite/lib/sqlite3ext.h Controller.h Module.h
FORMS += Gui/WindowEditTimeSlot.ui Gui/mainwindow.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
