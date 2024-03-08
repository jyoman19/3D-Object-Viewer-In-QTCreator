// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QApplication>
#include <QLabel>
#include <QSurfaceFormat>
#include <QMainWindow>
#include <QFile>
#include <QWidget>
#ifndef QT_NO_OPENGL
#include "mainwidget.h"
#endif

#include "dialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}

/*
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);

    app.setApplicationName("cube");
    app.setApplicationVersion("0.1");

    // Create a loader for .ui files
    QUiLoader loader;

    // Open the .ui file and create the widget
    QFile file(":/your_form.ui"); // Replace with the actual path to your .ui file
    file.open(QFile::ReadOnly);
    QWidget *widget = loader.load(&file);
    file.close();

    // Find your MainWidget within the loaded widget
    MainWidget *mainWidget = widget->findChild<MainWidget*>("mainWidget"); // Replace "mainWidget" with the actual name of your MainWidget in the .ui file

    if (mainWidget) {
        mainWidget->show();
    }

    // Show the widget
    //widget->show();
#ifndef QT_NO_OPENGL

    // Step 1: Create a QMainWindow
    QMainWindow mainWindow;

    // Step 2: Create an instance of MainWidget
    MainWidget* mainWidget = new MainWidget(&mainWindow); // Pass the parent (mainWindow)

    // Step 3: Set MainWidget as the central widget of the QMainWindow
    mainWindow.setCentralWidget(mainWidget);

    mainWindow.setWindowTitle("My 3D Application");
    mainWindow.resize(800, 600);
    mainWindow.show();

    //MainWidget widget;
    //widget.show();
#else
    QLabel note("OpenGL Support required");
    note.show();
#endif
    return app.exec();
}
*/
