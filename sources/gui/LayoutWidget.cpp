// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "LayoutWidget.hpp"

#include <QFileInfo>
#include <QMenu>
#include <QVBoxLayout>

LayoutWidget::LayoutWidget(QWidget *parent, Layout *layout) : QTabWidget(parent), p_layout(layout) {
  setTabPosition(QTabWidget::South);

  p_treeLayout = new QTreeWidget(this);
  p_treeLayout->setHeaderHidden(true);
  QTreeWidgetItem *p_designTopItem = new QTreeWidgetItem;
  p_designTopItem->setText(0, "There is no layout");
  p_treeLayout->insertTopLevelItem(0, p_designTopItem);
  addTab(p_treeLayout, QIcon(QPixmap(":/tabicons/icon_circuit.png")), "Structure");

  addTab(new QWidget(this), QIcon(QPixmap(":/tabicons/icon_circuit.png")), "Layers");

   
/*
  QWidget* p_wgt = new QWidget(this);
  QVBoxLayout *p_vLayout = new QVBoxLayout(p_wgt);
  p_cbShowUsed = new QCheckBox("Show used cells only", p_wgt);
  connect(p_cbShowUsed, SIGNAL(clicked(bool)), this, SLOT(OnShowUsedOnlyClicked(bool)));
  p_vLayout->addWidget(p_cbShowUsed);
  p_treeLibrary = new QTreeWidget(p_wgt);
  p_vLayout->addWidget(p_treeLibrary);
  p_treeLibrary->setHeaderHidden(true);
  QTreeWidgetItem *p_libraryTopItem = new QTreeWidgetItem;
  p_libraryTopItem->setText(0, "No libraries were loaded");
  p_treeLibrary->insertTopLevelItem(0, p_libraryTopItem);
  p_treeLibrary->setContextMenuPolicy(Qt::CustomContextMenu);
  connect(p_treeLibrary, &QTreeWidget::customContextMenuRequested, this, &ProjectWidget::OnLibraryContextMenu);
  p_wgt->setLayout(p_vLayout);
  addTab(p_wgt, QIcon(QPixmap(":/tabicons/icon_library.png")), "Libraries");
*/
}

void LayoutWidget::UpdateLayoutInfo() {
  p_treeLayout->clear();
  for (const Library *lib : p_layout->libraries) {
    QTreeWidgetItem *p_libItem = new QTreeWidgetItem;
    p_libItem->setText(0, QString("%1 [%2 cells]").arg(lib->name.c_str()).arg(lib->elements.size()));
    p_treeLayout->insertTopLevelItem(0, p_libItem);
    for (const Element *cell : lib->elements) {
      QTreeWidgetItem *p_cellItem = new QTreeWidgetItem;
      p_cellItem->setText(0, cell->name.c_str());
      p_libItem->addChild(p_cellItem);
    }
  }
}
