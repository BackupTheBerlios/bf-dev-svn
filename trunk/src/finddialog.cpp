#include <QtGui>

#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
{
    resize(275, 190);
    setMaximumSize(275, 190);
    setMinimumSize(275, 190);
    
    this->parent = parent;
    
    createDesign();
    
    connect(pushButtonClose, SIGNAL(clicked()), this, SLOT(close()));
    connect(pushButtonFind, SIGNAL(clicked()), parent, SLOT(findText()));
    connect(pushButtonFind, SIGNAL(clicked()), this, SLOT(close()));
    
    setWindowTitle(tr("Find..."));
}

QString FindDialog::getSearchFor()
{
    return lineEditSearchFor->text();
}

int FindDialog::getFindCaseSens()
{
    return checkBoxFindCaseSens->checkState();
}

int FindDialog::getFindWholeWords()
{
    return checkBoxFindWholeWords->checkState();
}

int FindDialog::getFindBackwards()
{
    return checkBoxFindBackwards->checkState();
}

void FindDialog::createDesign()
{
    QVBoxLayout *vboxLayoutFindDialog = new QVBoxLayout(this);
    
    QGroupBox *groupBoxFind = new QGroupBox(tr("Find"), this);
    
    QHBoxLayout *hboxLayoutFind = new QHBoxLayout(groupBoxFind);
    
    QLabel *labelSearchFor = new QLabel(tr("Search for:"), groupBoxFind);
    hboxLayoutFind->addWidget(labelSearchFor);
    
    lineEditSearchFor = new QLineEdit(groupBoxFind);
    hboxLayoutFind->addWidget(lineEditSearchFor);
    
    vboxLayoutFindDialog->addWidget(groupBoxFind);
    
    
    QGroupBox *groupBoxFindOptions = new QGroupBox(tr("Options"), this);   
    
    QGridLayout *gridLayoutOptions = new QGridLayout(groupBoxFindOptions);
    
    QSpacerItem *spacerItemOptions = new QSpacerItem(160, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    gridLayoutOptions->addItem(spacerItemOptions, 1, 1, 1, 1);
    
    checkBoxFindCaseSens = new QCheckBox(tr("Find case sensitively"), groupBoxFindOptions);
    gridLayoutOptions->addWidget(checkBoxFindCaseSens, 1, 0, 1, 1);
    
    checkBoxFindWholeWords = new QCheckBox(tr("Find whole words"), groupBoxFindOptions);
    gridLayoutOptions->addWidget(checkBoxFindWholeWords, 0, 1, 1, 1);
    
    checkBoxFindBackwards = new QCheckBox(tr("Find backwards"), groupBoxFindOptions);
    gridLayoutOptions->addWidget(checkBoxFindBackwards, 0, 0, 1, 1);
    
    vboxLayoutFindDialog->addWidget(groupBoxFindOptions);
    
    
    QHBoxLayout *hboxLayoutButtons = new QHBoxLayout;
    
    QSpacerItem *spacerItemButtons = new QSpacerItem(90, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    hboxLayoutButtons->addItem(spacerItemButtons);
    
    pushButtonFind = new QPushButton(tr("&Find"), this);
    hboxLayoutButtons->addWidget(pushButtonFind);
    
    pushButtonClose = new QPushButton(tr("&Close"), this);
    hboxLayoutButtons->addWidget(pushButtonClose);
    
    vboxLayoutFindDialog->addLayout(hboxLayoutButtons);
    
    setLayout(vboxLayoutFindDialog);
}
