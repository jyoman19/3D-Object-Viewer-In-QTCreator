#include "dialog.h"
#include "ui_dialog.h"
#include<iostream>
#include<QTimer>
using namespace std;
#include <QMouseEvent>
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#include <QQuaternion>
#include "mainwidget.h"
#include <QMouseEvent>
#include <cmath>
#include <QVBoxLayout>
#include <QPushButton>

#include <QLabel>

//MainWidget *w;
Dialog::Dialog(QWidget *parent) :  QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //w=(MainWidget*)this;
    ui->openGLWidget->zoomFactor=1.0;
    ui->openGLWidget->translation=QVector3D(0.0, 0.0, -5.0);
    ui->openGLWidget->translateFactor=0;
    ui->openGLWidget->stopRotate=false;
    ui->openGLWidget->rotationTimer = new QTimer(ui->openGLWidget);
    ui->openGLWidget->initialTranslation=ui->openGLWidget->translation;
    ui->openGLWidget->initialRotation=ui->openGLWidget->rotation;
    ui->doubleSpinBox_6->setValue(7.0);
    ui->doubleSpinBox_7->setValue(2.0);
    ui->doubleSpinBox_8->setValue(45.0);

    //ui->openGLWidget->draw3DAxes();
}

Dialog::~Dialog()
{
    delete ui;
}
/*
void Dialog::keyPressEvent(QKeyEvent *event) {
    // Check which arrow key was pressed and adjust the rotation accordingly
    if (event->key() == Qt::Key_Left) {
        // Rotate left (counter-clockwise)
        ui->openGLWidget->rotateLeft();
    } else if (event->key() == Qt::Key_Right) {
        // Rotate right (clockwise)
        ui->openGLWidget->rotateRight();
    } else if (event->key() == Qt::Key_Up) {
        // Rotate up
        ui->openGLWidget->rotateUp();
    } else if (event->key() == Qt::Key_Down) {
        // Rotate down
        ui->openGLWidget->rotateDown();
    }
}
*/

float rotationSpeed=1;
void Dialog::on_doubleSpinBox_valueChanged(double arg1)
{
    //rotationSpeed=(float)arg1;
    //w->rotateLeft();
    //cout<<"HELLO"<<endl;
    ui->openGLWidget->rotationSpeed=arg1;
}

void Dialog::on_pushButton_clicked()
{
    ui->openGLWidget->rotateDown();
}


void Dialog::on_pushButton_6_clicked()
{
    ui->openGLWidget->rotateUp();
}


void Dialog::on_pushButton_7_clicked()
{
    ui->openGLWidget->rotateLeft();
}


void Dialog::on_pushButton_4_clicked()
{
    ui->openGLWidget->rotateRight();
}



void Dialog::on_pushButton_2_clicked()
{
    ui->openGLWidget->rotateDown(); ui->openGLWidget->rotateLeft();
}


void Dialog::on_pushButton_3_clicked()
{
    ui->openGLWidget->rotateDown(); ui->openGLWidget->rotateRight();
}


void Dialog::on_pushButton_5_clicked()
{
    ui->openGLWidget->rotateUp(); ui->openGLWidget->rotateRight();
}


void Dialog::on_pushButton_8_clicked()
{
    ui->openGLWidget->rotateUp(); ui->openGLWidget->rotateLeft();
}


void Dialog::on_pushButton_10_clicked()
{
    ui->openGLWidget->translateZBack();
}


void Dialog::on_pushButton_11_clicked()
{
    ui->openGLWidget->translateZFront();
}


void Dialog::on_pushButton_14_clicked()
{
    ui->openGLWidget->translateUp();
}


void Dialog::on_pushButton_19_clicked()
{
    ui->openGLWidget->translateDown();
}


void Dialog::on_pushButton_13_clicked()
{
    ui->openGLWidget->translateRight();
}


void Dialog::on_pushButton_15_clicked()
{
    ui->openGLWidget->translateLeft();
}


void Dialog::on_pushButton_16_clicked()
{
    ui->openGLWidget->translateUp(); ui->openGLWidget->translateRight();
}


void Dialog::on_pushButton_12_clicked()
{
    ui->openGLWidget->translateUp(); ui->openGLWidget->translateLeft();
}


void Dialog::on_pushButton_18_clicked()
{
    ui->openGLWidget->translateDown(); ui->openGLWidget->translateLeft();
}

void Dialog::on_pushButton_20_clicked()
{
    ui->openGLWidget->translateDown(); ui->openGLWidget->translateRight();
}


void Dialog::on_doubleSpinBox_2_valueChanged(double arg1)
{
    ui->openGLWidget->translateFactor=arg1/10.0;
}

//int leftClickCount=0, rightClickCount=0;
void Dialog::on_pushButton_22_clicked()
{
    ui->openGLWidget->autoRotateLeft();
    //leftClickCount++;
}

void Dialog::on_pushButton_24_clicked()
{
    ui->openGLWidget->autoRotateRight();
    //rightClickCount++;
}


void Dialog::on_doubleSpinBox_3_valueChanged(double arg1)
{
    ui->openGLWidget->autoRotationSpeed=arg1;

}


void Dialog::on_pushButton_26_clicked()
{
    ui->openGLWidget->rotationTimer->stop();
    //ui->openGLWidget->rotation = QQuaternion::fromAxisAndAngle(QVector3D(0.0, -1*leftClickCount*0.1 + rightClickCount*0.1, 0.0), ui->openGLWidget->autoRotationSpeed)*ui->openGLWidget->rotation;
    //ui->openGLWidget->rotation = QQuaternion();
    //ui->openGLWidget->rotation.setScalar(1.0); // Set the scalar component to 1.0 (default)
    //ui->openGLWidget->rotation.setVector(QVector3D(0.0, 0.0, 0.0)); // Set the vector component to (0, 0, 0) (default)
    //ui->openGLWidget->stopRotation();
    //ui->openGLWidget->update();
    //leftClickCount=0; rightClickCount=0;
}




void Dialog::on_pushButton_23_clicked()
{
    ui->openGLWidget->autoRotateUp();
}


void Dialog::on_pushButton_28_clicked()
{
    ui->openGLWidget->autoRotateDown();
}


void Dialog::on_pushButton_25_clicked()
{
    ui->openGLWidget->autoRotateUp(); ui->openGLWidget->autoRotateRight();
}


void Dialog::on_pushButton_21_clicked()
{
    ui->openGLWidget->autoRotateUp(); ui->openGLWidget->autoRotateLeft();
}


void Dialog::on_pushButton_27_clicked()
{
    ui->openGLWidget->autoRotateDown(); ui->openGLWidget->autoRotateLeft();
}


void Dialog::on_pushButton_29_clicked()
{
    ui->openGLWidget->autoRotateUp(); ui->openGLWidget->autoRotateRight();
}


void Dialog::on_pushButton_31_clicked()
{
    ui->openGLWidget->rotateClockwise();
}


void Dialog::on_doubleSpinBox_4_valueChanged(double arg1)
{
    ui->openGLWidget->rotateAboutZ=arg1;
}


void Dialog::on_pushButton_30_clicked()
{
    ui->openGLWidget->rotateAntiClockwise();
}


void Dialog::on_doubleSpinBox_5_valueChanged(double arg1)
{
    ui->openGLWidget->zStep=arg1;
}


void Dialog::on_pushButton_32_clicked()
{
    ui->openGLWidget->reset();
}


void Dialog::on_doubleSpinBox_6_valueChanged(double arg1)
{
    ui->openGLWidget->zFar=arg1;
    cout<<"Value Changed"<<endl;
}


void Dialog::on_doubleSpinBox_7_valueChanged(double arg1)
{
    ui->openGLWidget->zNear=arg1;
}


void Dialog::on_doubleSpinBox_8_valueChanged(double arg1)
{
    ui->openGLWidget->fov=arg1;
}

