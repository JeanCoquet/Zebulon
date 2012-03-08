DROP VIEW IF EXISTS VLectureHall;
DROP VIEW IF EXISTS VPracticalClassroom;
DROP VIEW IF EXISTS VTutorialClassroom;
DROP TABLE IF EXISTS Assign;
DROP TABLE IF EXISTS ClassPeriod; 
DROP TABLE IF EXISTS Classroom;
DROP TABLE IF EXISTS "Group";
DROP TABLE IF EXISTS LectureHall;
DROP TABLE IF EXISTS Module;
DROP TABLE IF EXISTS PracticalClassroom;
DROP TABLE IF EXISTS Studient;
DROP TABLE IF EXISTS TimeSlot;
DROP TABLE IF EXISTS TutorialClassroom;

CREATE TABLE "Assign" ("id_classPeriod" INTEGER NOT NULL , "id_group" VARCHAR NOT NULL , PRIMARY KEY ("id_classPeriod", "id_group"));
CREATE TABLE "ClassPeriod" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "id_module" VARCHAR, "name" VARCHAR, "teacher" VARCHAR);
CREATE TABLE "Classroom" ("id" VARCHAR PRIMARY KEY  NOT NULL , "capacity" INTEGER);
CREATE TABLE "Group" ("id" VARCHAR PRIMARY KEY  NOT NULL , "id_groupParent" VARCHAR);
CREATE TABLE "LectureHall" ("id" VARCHAR PRIMARY KEY  NOT NULL , "videoconferencing" BOOL);
CREATE TABLE "Module" ("id" VARCHAR PRIMARY KEY  NOT NULL , "name" VARCHAR, "theHead" VARCHAR);
CREATE TABLE "PracticalClassroom" ("id" VARCHAR PRIMARY KEY  NOT NULL , "elementsNumber" INTEGER);
CREATE TABLE "Studient" ("id" VARCHAR PRIMARY KEY  NOT NULL , "id_group" VARCHAR, "lastname" VARCHAR, "firstname" VARCHAR, "addr" VARCHAR, "email" VARCHAR);
CREATE TABLE "TimeSlot" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "id_classroom" VARCHAR, "id_classPeriod" INTEGER, "date" DATETIME);
CREATE TABLE "TutorialClassroom" ("id" VARCHAR PRIMARY KEY  NOT NULL , "videoprojector" BOOL);

CREATE VIEW VLectureHall as
select classroom.id as id , classroom.capacity as capacity, videoconferencing
from classroom join lectureHall
where classroom.id = lectureHall.id;

CREATE VIEW VPracticalClassroom as
select classroom.id as id , classroom.capacity as capacity, elementsNumber 
from classroom join practicalClassroom
where classroom.id = practicalClassroom.id;

CREATE VIEW VTutorialClassroom as
select classroom.id as id , classroom.capacity as capacity, videoprojector
from classroom join tutorialClassroom
where classroom.id = tutorialClassroom.id;