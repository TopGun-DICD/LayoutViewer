// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "Logger.hpp"

//========== LOG WIDGET ==========

LogWidget::LogWidget(QWidget *parent) : QTextEdit(parent) {
  setReadOnly(true);
}

void LogWidget::Info(const QString &message) {
  MoveCursorToTheEnd();
  insertHtml(message + "<br />");
}

void LogWidget::Success(const QString &message) {
  MoveCursorToTheEnd();
  insertHtml("<font color='#090'>Success</font> : " + message + "<br />");
}

void LogWidget::Warning(const QString &message) {
  MoveCursorToTheEnd();
  insertHtml("<font color='#888'>Warning</font> : " + message + "<br />");
}

void LogWidget::Error(const QString &message) {
  MoveCursorToTheEnd();
  insertHtml("<font color='#f00'>Error</font> : " + message + "<br />");
}

void LogWidget::MoveCursorToTheEnd() {
  QTextCursor cursor = this->textCursor();
  cursor.clearSelection();
  cursor.movePosition(QTextCursor::End);
  this->setTextCursor(cursor);
}

//========== LOGGER ==========

LogWidget *Logger::p_logWidget = nullptr;

void Logger::Init(QWidget *parent) {
  if (p_logWidget)
    return;
  p_logWidget = new LogWidget(parent);
}

void Logger::Free() {
  if (p_logWidget)
    return;
  delete p_logWidget;
  p_logWidget = nullptr;
}

void Logger::Info(const QString &message) {
  if (!p_logWidget)
    return;
  p_logWidget->Info(message);
}

void Logger::Success(const QString &message) {
  if (!p_logWidget)
    return;
  p_logWidget->Success(message);
}

void Logger::Warning(const QString &message) {
  if (!p_logWidget)
    return;
  p_logWidget->Warning(message);
}

void Logger::Error(const QString &message) {
  if (!p_logWidget)
    return;
  p_logWidget->Error(message);
}
