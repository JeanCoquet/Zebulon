# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux-x86
TARGET = Zebulon
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
QT = core gui
SOURCES += Model/MagistralClass.cpp Model/Date.cpp Model/Module.cpp Gui/WindowAddClassPeriod.cpp Model/TutorialClassroom.cpp Model/PracticalClass.cpp Model/Controller.cpp Gui/QTimeSlot.cpp Model/TutorialClass.cpp Gui/main.cpp Model/TimeSlot.cpp Model/PracticalClassroom.cpp Model/ClassPeriod.cpp sqlite/lib/sqlite3.c Model/LectureHall.cpp Model/Schedule.cpp Model/Student.cpp Gui/QSchedule.cpp Gui/WindowAddClassroom.cpp Model/Classroom.cpp Model/Group.cpp Gui/WindowAdministrator.cpp Gui/WindowEditTimeSlot.cpp sqlite/Database.cpp Gui/mainwindow.cpp
HEADERS += Gui/QSchedule.h Model/LectureHall.h Model/Controller.h Gui/WindowAdministrator.h sqlite/Database.h Model/PracticalClass.h Gui/mainwindow.h Model/PracticalClassroom.h Model/TimeSlot.h sqlite/lib/sqlite3.h Model/Schedule.h Model/ClassPeriod.h Gui/WindowEditTimeSlot.h Model/Group.h Gui/ui_WindowEditTimeSlot.h Gui/WindowAddClassroom.h Gui/QTimeSlot.h Model/TutorialClassroom.h Gui/ui_mainwindow.h sqlite/lib/sqlite3ext.h Model/Module.h Model/Classroom.h Gui/WindowAddClassPeriod.h Model/Date.h Model/MagistralClass.h Model/TutorialClass.h Model/Student.h
FORMS += Gui/WindowAddClassroom.ui Gui/WindowAdministrator.ui Gui/WindowEditTimeSlot.ui Gui/WindowAddClassPeriod.ui Gui/mainwindow.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
