// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "mainwidget.h"

#include <QMouseEvent>
#include<iostream>
using namespace std;
#include <cmath>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTimer>
#include <QLabel>

MainWidget::~MainWidget()
{
    // Make sure the context is current when deleting the texture
    // and the buffers.
    makeCurrent();
    delete texture;
    delete geometries;
    doneCurrent();
}

//! [0]
void MainWidget::mousePressEvent(QMouseEvent *e)
{
    // Save mouse press position
    mousePressPosition = QVector2D(e->position());
}

void MainWidget::mouseReleaseEvent(QMouseEvent *e)
{
    // Mouse release position - mouse press position
    QVector2D diff = QVector2D(e->position()) - mousePressPosition;

    // Rotation axis is perpendicular to the mouse position difference
    // vector
    QVector3D n = QVector3D(diff.y(), diff.x(), 0.0).normalized();

    // Accelerate angular speed relative to the length of the mouse sweep
    qreal acc = diff.length() / 100.0;

    // Calculate new rotation axis as weighted sum
    rotationAxis = (rotationAxis * angularSpeed + n * acc).normalized();

    // Increase angular speed
    angularSpeed += acc;
}

void MainWidget::autoRotateLeft()
{
    angularSpeed = 1.0; // Set your desired initial angular speed
    connect(rotationTimer, &QTimer::timeout, this, &MainWidget::autoLeft);
    rotationTimer->start(10); // Adjust the interval as needed (e.g., 10 milliseconds)
}
void MainWidget::autoLeft() {
    rotation = QQuaternion::fromAxisAndAngle(QVector3D(0.0, 0.1, 0.0), autoRotationSpeed) * rotation;
    update();
}
/*
void MainWidget::stopRotation(){
    //rotation.setScalar(1.0); // Set the scalar component to 1.0 (default)
    //rotation.setVector(QVector3D(0.0, 0.0, 0.0)); // Set the vector component to (0, 0, 0) (default)
    rotation=QQuaternion();
    update();

}
*/

void MainWidget::autoRotateUp()
{
    angularSpeed = 1.0; // Set your desired initial angular speed
    connect(rotationTimer, &QTimer::timeout, this, &MainWidget::autoUp);
    rotationTimer->start(10); // Adjust the interval as needed (e.g., 10 milliseconds)
}
void MainWidget::autoUp() {
    rotation = QQuaternion::fromAxisAndAngle(QVector3D(0.1, 0.0, 0.0), autoRotationSpeed) * rotation;
    update();
}

void MainWidget::autoRotateDown()
{
    angularSpeed = 1.0; // Set your desired initial angular speed
    connect(rotationTimer, &QTimer::timeout, this, &MainWidget::autoDown);
    rotationTimer->start(10); // Adjust the interval as needed (e.g., 10 milliseconds)
}
void MainWidget::autoDown() {
    rotation = QQuaternion::fromAxisAndAngle(QVector3D(-0.1, 0.0, 0.0), autoRotationSpeed) * rotation;
    update();
}


void MainWidget::autoRotateRight()
{

    angularSpeed = 1.0; // Set your desired initial angular speed
    connect(rotationTimer, &QTimer::timeout, this, &MainWidget::autoRight);
    rotationTimer->start(10); // Adjust the interval as needed (e.g., 10 milliseconds)
}

void MainWidget::autoRight() {
    rotation = QQuaternion::fromAxisAndAngle(QVector3D(0.0, -0.1, 0.0), autoRotationSpeed) * rotation;
    update();
}
//! [0]
/*
void MainWidget::keyPressEvent(QKeyEvent *event) {
    // Check which arrow key was pressed and adjust the rotation accordingly
    if (event->key() == Qt::Key_Left) {
        // Rotate left (counter-clockwise)
        rotateLeft();
    } else if (event->key() == Qt::Key_Right) {
        // Rotate right (clockwise)
        rotateRight();
    } else if (event->key() == Qt::Key_Up) {
        // Rotate up
        rotateUp();
    } else if (event->key() == Qt::Key_Down) {
        // Rotate down
        rotateDown();
    }
}
*/
void MainWidget::rotateLeft() {
    // Adjust the rotation based on your desired rotation speed
    // For example, you can use the QQuaternion to perform rotations
    rotation = QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), rotationSpeed) * rotation;
    update(); // Request a repaint
}

void MainWidget::rotateClockwise(){
    rotation = QQuaternion::fromAxisAndAngle(QVector3D(0, 0, -1), rotateAboutZ) * rotation;
    update();
}
void MainWidget::rotateAntiClockwise(){
    rotation = QQuaternion::fromAxisAndAngle(QVector3D(0, 0, 1), rotateAboutZ) * rotation;
    update();
}
void MainWidget::rotateRight() {
    // Rotate right (clockwise) by adjusting the rotation speed
    rotation = QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), -rotationSpeed) * rotation;
    update(); // Request a repaint
}

void MainWidget::rotateUp() {
    // Rotate up by adjusting the rotation speed
    rotation = QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), rotationSpeed) * rotation;
    update(); // Request a repaint
}

void MainWidget::rotateDown() {
    // Rotate down by adjusting the rotation speed
    rotation = QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), -rotationSpeed) * rotation;
    update(); // Request a repaint
}

//! [1]
void MainWidget::timerEvent(QTimerEvent *)
{
    // Decrease angular speed (friction)
    angularSpeed *= 0.99;

    // Stop rotation when speed goes below threshold
    if (angularSpeed < 0.01) {
        angularSpeed = 0.0;
    } else {
        // Update rotation
        rotation = QQuaternion::fromAxisAndAngle(rotationAxis, angularSpeed) * rotation;

        // Request an update
        update();
    }
}


void MainWidget::zoomIn()
{
    zoomFactor *= 1.1; // Increase zoom factor
    updateProjectionMatrix();
}

void MainWidget::zoomOut()
{
    zoomFactor *= 0.9; // Decrease zoom factor
    updateProjectionMatrix();
}

void MainWidget::updateProjectionMatrix()
{
    qreal aspect = qreal(width()) / qreal(height() ? height() : 1);
    const qreal zNear = 3.0 / zoomFactor, zFar = 7.0;
    projection.setToIdentity();
    projection.perspective(45.0, aspect, zNear, zFar);
    update();
}

//! [1]'

void MainWidget::translateZBack()
{
    translation += QVector3D(0.0, 0.0, -zStep/10.0);
    update(); // Request a repaint
}

void MainWidget::translateZFront()
{
    translation += QVector3D(0.0, 0.0, zStep/10.0);
    update(); // Request a repaint
}



void MainWidget::translateUp()
{
    translation += QVector3D(0.0, translateFactor, 0.0); // Move up
    update(); // Request a repaint
}

void MainWidget::translateDown()
{
    translation -= QVector3D(0.0, translateFactor, 0.0); // Move down
    update(); // Request a repaint
}

void MainWidget::translateLeft()
{
    translation -= QVector3D(translateFactor, 0.0, 0.0); // Move left
    update(); // Request a repaint
}

void MainWidget::translateRight()
{
    translation += QVector3D(translateFactor, 0.0, 0.0); // Move right
    update(); // Request a repaint
}


void MainWidget::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 1);

    initShaders();
    initTextures();

    geometries = new GeometryEngine;

    // Use QBasicTimer because its faster than QTimer
    timer.start(12, this);
}

//! [3]
void MainWidget::initShaders()
{
    // Compile vertex shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vshader.glsl"))
        close();

    // Compile fragment shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fshader.glsl"))
        close();

    // Link shader pipeline
    if (!program.link())
        close();

    // Bind shader pipeline for use
    if (!program.bind())
        close();
}
//! [3]

//! [4]
void MainWidget::initTextures()
{
    // Load cube.png image
    texture = new QOpenGLTexture(QImage(":/cube.png").mirrored());

    // Set nearest filtering mode for texture minification
    texture->setMinificationFilter(QOpenGLTexture::Nearest);

    // Set bilinear filtering mode for texture magnification
    texture->setMagnificationFilter(QOpenGLTexture::Linear);

    // Wrap texture coordinates by repeating
    // f.ex. texture coordinate (1.1, 1.2) is same as (0.1, 0.2)
    texture->setWrapMode(QOpenGLTexture::Repeat);
}
//! [4]

//! [5]

void MainWidget::resizeGL(int w, int h)
{

    // Calculate aspect ratio
    aspect = qreal(w) / qreal(h ? h : 1);

    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
    //const qreal zNear = 1.0, zFar = 7.0, fov = 45.0;
    cout<<"BACK: "<<zNear<<" "<<zFar<<" "<<fov<<endl;
    // Reset projection
    projection.setToIdentity();

    // Set perspective projection
    projection.perspective(fov, aspect, zNear, zFar);

}

//! [5]
void MainWidget::reset()
{
    // Reset rotation to identity (no rotation)
    rotation = initialRotation;

    // Reset translation to (0, 0, 0)
    translation = initialTranslation;
    //initializeGL();
    //resizeGL();
    projection.setToIdentity();
    // Set perspective projection
    projection.perspective(fov, aspect, zNear, zFar);
    update();
}

void MainWidget::paintGL()
{
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//! [2]
    // Enable depth buffer
    glEnable(GL_DEPTH_TEST);

    // Enable back face culling
    glEnable(GL_CULL_FACE);
//! [2]

    texture->bind();
    program.bind();

//! [6]
    // Calculate model view transformation
    QMatrix4x4 matrix;
    matrix.translate(translation);
    matrix.rotate(rotation);

    // Set modelview-projection matrix
    program.setUniformValue("mvp_matrix", projection * matrix);
//! [6]

    // Use texture unit 0 which contains cube.png
    program.setUniformValue("texture", 0);

    // Draw cube geometry
    geometries->drawCubeGeometry(&program);
}
