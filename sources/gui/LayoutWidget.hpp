// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once

#include <QTabWidget>
#include <QTreeWidget>
#include <QCheckBox>

#include "../layout/Layout.hpp"

class LayoutWidget : public QTabWidget {
  Q_OBJECT
private:
  QTreeWidget        *p_treeLayout = nullptr;
  Layout             *p_layout     = nullptr;
public:
  LayoutWidget(QWidget *parent, Layout *layout);
 ~LayoutWidget() = default;
public:
  void UpdateLayoutInfo();
};
