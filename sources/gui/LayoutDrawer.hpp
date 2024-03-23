// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include "../layout/Layout.hpp"

const Coord zeroOffset = { 0, 0 };

class LayoutDrawer : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT
private:
  Layout *p_layout;
  int     H, W, xPlus, yPlus;
  double  k, kX, kY;
public:
  LayoutDrawer(QWidget *parent, Layout *layout);
protected:
  void paintEvent(QPaintEvent* event);
private:
  void PrepareCoefficients();
  void DrawLayoutElement(QPainter &painter, Element *element, Coord offset = zeroOffset);
};