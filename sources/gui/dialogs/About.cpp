// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "About.hpp"

#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QDialogButtonBox>
#include <QtGlobal>

const QString htmlText(
  "<b>LayoutViewer</b> is the software aimed to test and implement layout processing operations and algorithm.<br/><br/>"
);


Dialog_About::Dialog_About(QWidget *parent) : QDialog(parent) {
  setWindowTitle(tr("About LayoutViewer"));

  QVBoxLayout* p_globalLayout = new QVBoxLayout(this);
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  p_globalLayout->setMargin(0);
#endif

  QHBoxLayout* p_logoLayout = new QHBoxLayout(this);
  p_logoLayout->setAlignment(Qt::AlignBottom);

  QImage pic(":/dialogs/logo.png");
  QLabel *p_logoLabel = new QLabel(this);
  p_logoLabel->setPixmap(QPixmap::fromImage(pic));
  p_logoLayout->addWidget(p_logoLabel);

  QVBoxLayout *p_textLayout = new QVBoxLayout(this);
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  p_textLayout->setMargin(10);
#endif

  QLabel *p_labelName = new QLabel("LayoutViewer");
  QFont f(p_labelName->font().family());
  f.setPointSize(24);
  f.setWeight(QFont::Bold);
  p_labelName->setFont(f);
  p_textLayout->addWidget(p_labelName);
  QLabel *p_labelVersion = new QLabel(QString("LayoutViewer version 0.0.1"));
  p_textLayout->addWidget(p_labelVersion);
  QLabel *p_buildTime = new QLabel(QString("Built on %1 %2").arg(__DATE__).arg(__TIME__));
  p_textLayout->addWidget(p_buildTime);
  QTextEdit *p_infoText = new QTextEdit(this);
  p_textLayout->addWidget(p_infoText);
  p_infoText->setFixedHeight(235);
  //p_infoText->setEd(false);
  p_infoText->setReadOnly(true);
  p_infoText->setHtml(htmlText);

  p_logoLayout->addLayout(p_textLayout);
  p_globalLayout->addLayout(p_logoLayout);

  QVBoxLayout *p_buttonLayout = new QVBoxLayout(this);
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  p_buttonLayout->setMargin(10);
#endif
  QDialogButtonBox *p_buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok);
  connect(p_buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);

  p_buttonLayout->addWidget(p_buttonBox);
  p_globalLayout->addLayout(p_buttonLayout);
}

