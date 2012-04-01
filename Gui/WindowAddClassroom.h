/* 
 * File:   WindowAddClassroom.h
 * Author: bicodul
 *
 * Created on April 1, 2012, 10:50 PM
 */

#ifndef _WINDOWADDCLASSROOM_H
#define	_WINDOWADDCLASSROOM_H

#include "ui_WindowAddClassroom.h"

class WindowAddClassroom : public QDialog {
    Q_OBJECT
public:
    WindowAddClassroom();
    virtual ~WindowAddClassroom();
private:
    Ui::WindowAddClassroom widget;
};

#endif	/* _WINDOWADDCLASSROOM_H */
