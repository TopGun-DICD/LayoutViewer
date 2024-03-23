// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once

#include <QTextEdit>
#include <QFile>
#include <QTextStream>

class LogWidget : public QTextEdit {
  Q_OBJECT
public:
  LogWidget(QWidget *parent);
 ~LogWidget() = default;
public:
  void Info(const QString &message);
  void Success(const QString &message);
  void Warning(const QString &message);
  void Error(const QString &message);
private:
  void MoveCursorToTheEnd();
};

struct Logger {
  static  LogWidget *p_logWidget;
public:
  static void Init(QWidget *parent);
  static void Free();
public:
  static void Info(const QString &message);
  static void Success(const QString &message);
  static void Warning(const QString &message);
  static void Error(const QString &message);
  static void AddPadding();
  static void RemovePadding();
};
