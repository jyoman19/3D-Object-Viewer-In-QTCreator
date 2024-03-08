// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "geometryengine.h"

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>
#include <QBasicTimer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

class GeometryEngine;

class MainWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    using QOpenGLWidget::QOpenGLWidget;
    //MainWidget();
    ~MainWidget();

    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void timerEvent(QTimerEvent *e) override;

    //void keyPressEvent(QKeyEvent *e);
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void updateProjectionMatrix();
    void rotateLeft(); void rotateRight(); void rotateUp(); void rotateDown();
    void zoomIn();
    void zoomOut();
    void initShaders();
    void initTextures();
    void translateZBack(); void translateZFront();
    void autoRotateLeft(); void autoRotateRight(); void autoRotateUp(); void autoRotateDown();
    bool stopRotate;
    void autorotate(QVector3D arg);
    void autoLeft(); void autoRight(); void autoUp(); void autoDown();
    void rotateClockwise(); void rotateAntiClockwise();
    void reset();
    qreal zFar, zNear, fov, aspect;
    double rotateAboutZ;
    //void stopRotation();
    QTimer* rotationTimer;
    //void draw3DAxes();
    float rotationSpeed; float autoRotationSpeed;
    float zoomFactor; float translateFactor;
    double zStep;
    QVector3D translation, initialTranslation;
    void translateUp(); void translateDown(); void translateRight(); void translateLeft();


    QBasicTimer timer;
    QOpenGLShaderProgram program;
    GeometryEngine *geometries = nullptr;

    QOpenGLTexture *texture = nullptr;

    QMatrix4x4 projection;

    QVector2D mousePressPosition;
    QVector3D rotationAxis;
    qreal angularSpeed = 0;
    QQuaternion rotation, initialRotation;
};

#endif // MAINWIDGET_H
