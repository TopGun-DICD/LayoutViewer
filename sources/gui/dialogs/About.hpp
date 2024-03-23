// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once

#include <QDialog>

class Dialog_About: public QDialog {
  Q_OBJECT
public:
  Dialog_About(QWidget *parent);
};
