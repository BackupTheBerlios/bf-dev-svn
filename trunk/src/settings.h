#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_SettingsDialog
{
public:
    QTabWidget *navigationTabWidget;
    QWidget *editorTab;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QCheckBox *lineNumbersCheckBox;
    QCheckBox *syntaxHighlightingCheckBox;
    QSpacerItem *spacerItem;
    QGridLayout *gridLayout;
    QComboBox *encodingComboBox;
    QComboBox *eofComboBox;
    QLabel *encodingLabel;
    QLabel *eofLabel;
    QGroupBox *fontsGroupBox;
    QVBoxLayout *vboxLayout2;
    QHBoxLayout *hboxLayout1;
    QLabel *characterLabel;
    QComboBox *characterComboBox;
    QSpacerItem *spacerItem1;
    QHBoxLayout *hboxLayout2;
    QLabel *fontLabel;
    QComboBox *fontComboBox;
    QSpacerItem *spacerItem2;
    QLabel *styleLabel;
    QComboBox *styleComboBox;
    QSpacerItem *spacerItem3;
    QLabel *sizeLabel;
    QComboBox *sizeComboBox;
    QSpacerItem *spacerItem4;
    QHBoxLayout *hboxLayout3;
    QLabel *colorLabel;
    QComboBox *colorComboBox;
    QSpacerItem *spacerItem5;
    QSpacerItem *spacerItem6;
    QWidget *compilerTab;
    QVBoxLayout *vboxLayout3;
    QVBoxLayout *vboxLayout4;
    QHBoxLayout *hboxLayout4;
    QLabel *plattformLabel;
    QComboBox *plattformComboBox;
    QSpacerItem *spacerItem7;
    QHBoxLayout *hboxLayout5;
    QLabel *optLabel;
    QComboBox *optComboBox;
    QSpacerItem *spacerItem8;
    QHBoxLayout *hboxLayout6;
    QLabel *targetLabel;
    QLineEdit *targetLineEdit;
    QCheckBox *warningsCheckBox;
    QSpacerItem *spacerItem9;
    QWidget *shortcutsTab;
    QGroupBox *editGroupBox;
    QGridLayout *gridLayout1;
    QLineEdit *findLineEdit;
    QLineEdit *selectLineEdit;
    QLineEdit *pasteLineEdit;
    QLineEdit *copyLineEdit;
    QLineEdit *cutLineEdit;
    QLineEdit *redoLineEdit;
    QLineEdit *undoLineEdit;
    QLabel *findLabel;
    QLabel *undoLabel;
    QLabel *pasteLabel;
    QLabel *redoLabel;
    QLabel *cutLabel;
    QLabel *selectLabel;
    QLabel *copyLabel;
    QWidget *containerWidget;
    QGroupBox *compileGroupBox;
    QGridLayout *gridLayout2;
    QLineEdit *interpreterLineEdit;
    QLineEdit *undoLineEdit1;
    QLabel *undoLabel1;
    QLabel *interpreterLabel;
    QGroupBox *debugGroupBox;
    QGridLayout *gridLayout3;
    QLineEdit *nextStepLineEdit;
    QLineEdit *startLineEdit;
    QLabel *startLabel;
    QLabel *nextStepLabel;
    QGroupBox *helpGroupBox;
    QLineEdit *handbookLineEdit;
    QLabel *handbookLabel;
    QGroupBox *fileGroupBox;
    QLineEdit *saveLineEdit;
    QLineEdit *newLineEdit;
    QLabel *printLabel;
    QLabel *newLabel;
    QLabel *saveLabel;
    QLabel *openLabel;
    QLineEdit *closeLineEdit;
    QLineEdit *printLineEdit;
    QLineEdit *openLineEdit;
    QLabel *closeLabel;
    QWidget *widget;
    QHBoxLayout *hboxLayout7;
    QSpacerItem *spacerItem10;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *SettingsDialog)
    {
    SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
    SettingsDialog->resize(QSize(420, 320).expandedTo(SettingsDialog->minimumSizeHint()));
    SettingsDialog->setMinimumSize(QSize(420, 320));
    SettingsDialog->setMaximumSize(QSize(420, 320));
    SettingsDialog->setWindowIcon(QIcon());
    navigationTabWidget = new QTabWidget(SettingsDialog);
    navigationTabWidget->setObjectName(QString::fromUtf8("navigationTabWidget"));
    navigationTabWidget->setGeometry(QRect(9, 9, 402, 263));
    navigationTabWidget->setMaximumSize(QSize(16777215, 16777215));
    editorTab = new QWidget();
    editorTab->setObjectName(QString::fromUtf8("editorTab"));
    vboxLayout = new QVBoxLayout(editorTab);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    lineNumbersCheckBox = new QCheckBox(editorTab);
    lineNumbersCheckBox->setObjectName(QString::fromUtf8("lineNumbersCheckBox"));
    QFont font;
    font.setFamily(QString::fromUtf8("Sans Serif"));
    font.setPointSize(10);
    font.setBold(false);
    font.setItalic(false);
    font.setUnderline(false);
    font.setWeight(50);
    font.setStrikeOut(false);
    lineNumbersCheckBox->setFont(font);

    vboxLayout1->addWidget(lineNumbersCheckBox);

    syntaxHighlightingCheckBox = new QCheckBox(editorTab);
    syntaxHighlightingCheckBox->setObjectName(QString::fromUtf8("syntaxHighlightingCheckBox"));
    QFont font1;
    font1.setFamily(QString::fromUtf8("Sans Serif"));
    font1.setPointSize(10);
    font1.setBold(false);
    font1.setItalic(false);
    font1.setUnderline(false);
    font1.setWeight(50);
    font1.setStrikeOut(false);
    syntaxHighlightingCheckBox->setFont(font1);

    vboxLayout1->addWidget(syntaxHighlightingCheckBox);


    hboxLayout->addLayout(vboxLayout1);

    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    gridLayout = new QGridLayout();
    gridLayout->setSpacing(6);
    gridLayout->setMargin(0);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    encodingComboBox = new QComboBox(editorTab);
    encodingComboBox->setObjectName(QString::fromUtf8("encodingComboBox"));

    gridLayout->addWidget(encodingComboBox, 1, 1, 1, 1);

    eofComboBox = new QComboBox(editorTab);
    eofComboBox->setObjectName(QString::fromUtf8("eofComboBox"));

    gridLayout->addWidget(eofComboBox, 0, 1, 1, 1);

    encodingLabel = new QLabel(editorTab);
    encodingLabel->setObjectName(QString::fromUtf8("encodingLabel"));

    gridLayout->addWidget(encodingLabel, 1, 0, 1, 1);

    eofLabel = new QLabel(editorTab);
    eofLabel->setObjectName(QString::fromUtf8("eofLabel"));
    QFont font2;
    font2.setFamily(QString::fromUtf8("Sans Serif"));
    font2.setPointSize(10);
    font2.setBold(false);
    font2.setItalic(false);
    font2.setUnderline(false);
    font2.setWeight(50);
    font2.setStrikeOut(false);
    eofLabel->setFont(font2);

    gridLayout->addWidget(eofLabel, 0, 0, 1, 1);


    hboxLayout->addLayout(gridLayout);


    vboxLayout->addLayout(hboxLayout);

    fontsGroupBox = new QGroupBox(editorTab);
    fontsGroupBox->setObjectName(QString::fromUtf8("fontsGroupBox"));
    vboxLayout2 = new QVBoxLayout(fontsGroupBox);
    vboxLayout2->setSpacing(6);
    vboxLayout2->setMargin(9);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    characterLabel = new QLabel(fontsGroupBox);
    characterLabel->setObjectName(QString::fromUtf8("characterLabel"));

    hboxLayout1->addWidget(characterLabel);

    characterComboBox = new QComboBox(fontsGroupBox);
    characterComboBox->setObjectName(QString::fromUtf8("characterComboBox"));

    hboxLayout1->addWidget(characterComboBox);

    spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem1);


    vboxLayout2->addLayout(hboxLayout1);

    hboxLayout2 = new QHBoxLayout();
    hboxLayout2->setSpacing(6);
    hboxLayout2->setMargin(0);
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    fontLabel = new QLabel(fontsGroupBox);
    fontLabel->setObjectName(QString::fromUtf8("fontLabel"));

    hboxLayout2->addWidget(fontLabel);

    fontComboBox = new QComboBox(fontsGroupBox);
    fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
    fontComboBox->setMinimumSize(QSize(89, 0));

    hboxLayout2->addWidget(fontComboBox);

    spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem2);

    styleLabel = new QLabel(fontsGroupBox);
    styleLabel->setObjectName(QString::fromUtf8("styleLabel"));

    hboxLayout2->addWidget(styleLabel);

    styleComboBox = new QComboBox(fontsGroupBox);
    styleComboBox->setObjectName(QString::fromUtf8("styleComboBox"));
    styleComboBox->setMinimumSize(QSize(80, 0));

    hboxLayout2->addWidget(styleComboBox);

    spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem3);

    sizeLabel = new QLabel(fontsGroupBox);
    sizeLabel->setObjectName(QString::fromUtf8("sizeLabel"));

    hboxLayout2->addWidget(sizeLabel);

    sizeComboBox = new QComboBox(fontsGroupBox);
    sizeComboBox->setObjectName(QString::fromUtf8("sizeComboBox"));
    sizeComboBox->setMinimumSize(QSize(40, 0));

    hboxLayout2->addWidget(sizeComboBox);

    spacerItem4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem4);


    vboxLayout2->addLayout(hboxLayout2);

    hboxLayout3 = new QHBoxLayout();
    hboxLayout3->setSpacing(6);
    hboxLayout3->setMargin(0);
    hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
    colorLabel = new QLabel(fontsGroupBox);
    colorLabel->setObjectName(QString::fromUtf8("colorLabel"));

    hboxLayout3->addWidget(colorLabel);

    colorComboBox = new QComboBox(fontsGroupBox);
    colorComboBox->setObjectName(QString::fromUtf8("colorComboBox"));
    colorComboBox->setMinimumSize(QSize(60, 0));

    hboxLayout3->addWidget(colorComboBox);

    spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout3->addItem(spacerItem5);


    vboxLayout2->addLayout(hboxLayout3);


    vboxLayout->addWidget(fontsGroupBox);

    spacerItem6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout->addItem(spacerItem6);

    navigationTabWidget->addTab(editorTab, QApplication::translate("SettingsDialog", "Editor", 0, QApplication::UnicodeUTF8));
    compilerTab = new QWidget();
    compilerTab->setObjectName(QString::fromUtf8("compilerTab"));
    vboxLayout3 = new QVBoxLayout(compilerTab);
    vboxLayout3->setSpacing(6);
    vboxLayout3->setMargin(9);
    vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
    vboxLayout4 = new QVBoxLayout();
    vboxLayout4->setSpacing(6);
    vboxLayout4->setMargin(0);
    vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
    hboxLayout4 = new QHBoxLayout();
    hboxLayout4->setSpacing(6);
    hboxLayout4->setMargin(0);
    hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
    plattformLabel = new QLabel(compilerTab);
    plattformLabel->setObjectName(QString::fromUtf8("plattformLabel"));

    hboxLayout4->addWidget(plattformLabel);

    plattformComboBox = new QComboBox(compilerTab);
    plattformComboBox->setObjectName(QString::fromUtf8("plattformComboBox"));

    hboxLayout4->addWidget(plattformComboBox);

    spacerItem7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout4->addItem(spacerItem7);


    vboxLayout4->addLayout(hboxLayout4);

    hboxLayout5 = new QHBoxLayout();
    hboxLayout5->setSpacing(6);
    hboxLayout5->setMargin(0);
    hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
    optLabel = new QLabel(compilerTab);
    optLabel->setObjectName(QString::fromUtf8("optLabel"));

    hboxLayout5->addWidget(optLabel);

    optComboBox = new QComboBox(compilerTab);
    optComboBox->setObjectName(QString::fromUtf8("optComboBox"));

    hboxLayout5->addWidget(optComboBox);

    spacerItem8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout5->addItem(spacerItem8);


    vboxLayout4->addLayout(hboxLayout5);

    hboxLayout6 = new QHBoxLayout();
    hboxLayout6->setSpacing(6);
    hboxLayout6->setMargin(0);
    hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
    targetLabel = new QLabel(compilerTab);
    targetLabel->setObjectName(QString::fromUtf8("targetLabel"));

    hboxLayout6->addWidget(targetLabel);

    targetLineEdit = new QLineEdit(compilerTab);
    targetLineEdit->setObjectName(QString::fromUtf8("targetLineEdit"));

    hboxLayout6->addWidget(targetLineEdit);


    vboxLayout4->addLayout(hboxLayout6);

    warningsCheckBox = new QCheckBox(compilerTab);
    warningsCheckBox->setObjectName(QString::fromUtf8("warningsCheckBox"));
    QFont font3;
    font3.setFamily(QString::fromUtf8("Sans Serif"));
    font3.setPointSize(10);
    font3.setBold(false);
    font3.setItalic(false);
    font3.setUnderline(false);
    font3.setWeight(50);
    font3.setStrikeOut(false);
    warningsCheckBox->setFont(font3);

    vboxLayout4->addWidget(warningsCheckBox);


    vboxLayout3->addLayout(vboxLayout4);

    spacerItem9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout3->addItem(spacerItem9);

    navigationTabWidget->addTab(compilerTab, QApplication::translate("SettingsDialog", "Compiler", 0, QApplication::UnicodeUTF8));
    shortcutsTab = new QWidget();
    shortcutsTab->setObjectName(QString::fromUtf8("shortcutsTab"));
    editGroupBox = new QGroupBox(shortcutsTab);
    editGroupBox->setObjectName(QString::fromUtf8("editGroupBox"));
    editGroupBox->setGeometry(QRect(120, 0, 101, 212));
    editGroupBox->setMinimumSize(QSize(101, 212));
    editGroupBox->setMaximumSize(QSize(101, 212));
    gridLayout1 = new QGridLayout(editGroupBox);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    findLineEdit = new QLineEdit(editGroupBox);
    findLineEdit->setObjectName(QString::fromUtf8("findLineEdit"));
    findLineEdit->setMinimumSize(QSize(40, 20));
    findLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout1->addWidget(findLineEdit, 6, 1, 1, 1);

    selectLineEdit = new QLineEdit(editGroupBox);
    selectLineEdit->setObjectName(QString::fromUtf8("selectLineEdit"));
    selectLineEdit->setMinimumSize(QSize(40, 20));
    selectLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout1->addWidget(selectLineEdit, 5, 1, 1, 1);

    pasteLineEdit = new QLineEdit(editGroupBox);
    pasteLineEdit->setObjectName(QString::fromUtf8("pasteLineEdit"));
    pasteLineEdit->setMinimumSize(QSize(40, 20));
    pasteLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout1->addWidget(pasteLineEdit, 4, 1, 1, 1);

    copyLineEdit = new QLineEdit(editGroupBox);
    copyLineEdit->setObjectName(QString::fromUtf8("copyLineEdit"));
    copyLineEdit->setMinimumSize(QSize(40, 20));
    copyLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout1->addWidget(copyLineEdit, 3, 1, 1, 1);

    cutLineEdit = new QLineEdit(editGroupBox);
    cutLineEdit->setObjectName(QString::fromUtf8("cutLineEdit"));
    cutLineEdit->setMinimumSize(QSize(40, 20));
    cutLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout1->addWidget(cutLineEdit, 2, 1, 1, 1);

    redoLineEdit = new QLineEdit(editGroupBox);
    redoLineEdit->setObjectName(QString::fromUtf8("redoLineEdit"));
    redoLineEdit->setMinimumSize(QSize(40, 20));
    redoLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout1->addWidget(redoLineEdit, 1, 1, 1, 1);

    undoLineEdit = new QLineEdit(editGroupBox);
    undoLineEdit->setObjectName(QString::fromUtf8("undoLineEdit"));
    undoLineEdit->setMinimumSize(QSize(40, 20));
    undoLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout1->addWidget(undoLineEdit, 0, 1, 1, 1);

    findLabel = new QLabel(editGroupBox);
    findLabel->setObjectName(QString::fromUtf8("findLabel"));

    gridLayout1->addWidget(findLabel, 6, 0, 1, 1);

    undoLabel = new QLabel(editGroupBox);
    undoLabel->setObjectName(QString::fromUtf8("undoLabel"));

    gridLayout1->addWidget(undoLabel, 0, 0, 1, 1);

    pasteLabel = new QLabel(editGroupBox);
    pasteLabel->setObjectName(QString::fromUtf8("pasteLabel"));

    gridLayout1->addWidget(pasteLabel, 4, 0, 1, 1);

    redoLabel = new QLabel(editGroupBox);
    redoLabel->setObjectName(QString::fromUtf8("redoLabel"));

    gridLayout1->addWidget(redoLabel, 1, 0, 1, 1);

    cutLabel = new QLabel(editGroupBox);
    cutLabel->setObjectName(QString::fromUtf8("cutLabel"));

    gridLayout1->addWidget(cutLabel, 2, 0, 1, 1);

    selectLabel = new QLabel(editGroupBox);
    selectLabel->setObjectName(QString::fromUtf8("selectLabel"));

    gridLayout1->addWidget(selectLabel, 5, 0, 1, 1);

    copyLabel = new QLabel(editGroupBox);
    copyLabel->setObjectName(QString::fromUtf8("copyLabel"));

    gridLayout1->addWidget(copyLabel, 3, 0, 1, 1);

    containerWidget = new QWidget(shortcutsTab);
    containerWidget->setObjectName(QString::fromUtf8("containerWidget"));
    containerWidget->setGeometry(QRect(240, 0, 143, 234));
    compileGroupBox = new QGroupBox(containerWidget);
    compileGroupBox->setObjectName(QString::fromUtf8("compileGroupBox"));
    compileGroupBox->setMinimumSize(QSize(141, 82));
    compileGroupBox->setMaximumSize(QSize(141, 82));
    gridLayout2 = new QGridLayout(compileGroupBox);
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(9);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    interpreterLineEdit = new QLineEdit(compileGroupBox);
    interpreterLineEdit->setObjectName(QString::fromUtf8("interpreterLineEdit"));
    interpreterLineEdit->setMinimumSize(QSize(40, 20));
    interpreterLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout2->addWidget(interpreterLineEdit, 1, 1, 1, 1);

    undoLineEdit1 = new QLineEdit(compileGroupBox);
    undoLineEdit1->setObjectName(QString::fromUtf8("undoLineEdit1"));
    undoLineEdit1->setMinimumSize(QSize(40, 20));
    undoLineEdit1->setMaximumSize(QSize(40, 20));

    gridLayout2->addWidget(undoLineEdit1, 0, 1, 1, 1);

    undoLabel1 = new QLabel(compileGroupBox);
    undoLabel1->setObjectName(QString::fromUtf8("undoLabel1"));

    gridLayout2->addWidget(undoLabel1, 0, 0, 1, 1);

    interpreterLabel = new QLabel(compileGroupBox);
    interpreterLabel->setObjectName(QString::fromUtf8("interpreterLabel"));

    gridLayout2->addWidget(interpreterLabel, 1, 0, 1, 1);

    debugGroupBox = new QGroupBox(containerWidget);
    debugGroupBox->setObjectName(QString::fromUtf8("debugGroupBox"));
    debugGroupBox->setMinimumSize(QSize(141, 82));
    debugGroupBox->setMaximumSize(QSize(141, 82));
    gridLayout3 = new QGridLayout(debugGroupBox);
    gridLayout3->setSpacing(6);
    gridLayout3->setMargin(9);
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    nextStepLineEdit = new QLineEdit(debugGroupBox);
    nextStepLineEdit->setObjectName(QString::fromUtf8("nextStepLineEdit"));
    nextStepLineEdit->setMinimumSize(QSize(40, 20));
    nextStepLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout3->addWidget(nextStepLineEdit, 1, 1, 1, 1);

    startLineEdit = new QLineEdit(debugGroupBox);
    startLineEdit->setObjectName(QString::fromUtf8("startLineEdit"));
    startLineEdit->setMinimumSize(QSize(40, 20));
    startLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout3->addWidget(startLineEdit, 0, 1, 1, 1);

    startLabel = new QLabel(debugGroupBox);
    startLabel->setObjectName(QString::fromUtf8("startLabel"));

    gridLayout3->addWidget(startLabel, 0, 0, 1, 1);

    nextStepLabel = new QLabel(debugGroupBox);
    nextStepLabel->setObjectName(QString::fromUtf8("nextStepLabel"));

    gridLayout3->addWidget(nextStepLabel, 1, 0, 1, 1);

    helpGroupBox = new QGroupBox(containerWidget);
    helpGroupBox->setObjectName(QString::fromUtf8("helpGroupBox"));
    helpGroupBox->setMinimumSize(QSize(141, 56));
    helpGroupBox->setMaximumSize(QSize(141, 56));
    handbookLineEdit = new QLineEdit(helpGroupBox);
    handbookLineEdit->setObjectName(QString::fromUtf8("handbookLineEdit"));
    handbookLineEdit->setMinimumSize(QSize(40, 20));
    handbookLineEdit->setMaximumSize(QSize(40, 20));
    handbookLabel = new QLabel(helpGroupBox);
    handbookLabel->setObjectName(QString::fromUtf8("handbookLabel"));
    fileGroupBox = new QGroupBox(shortcutsTab);
    fileGroupBox->setObjectName(QString::fromUtf8("fileGroupBox"));
    fileGroupBox->setGeometry(QRect(10, 0, 95, 160));
    fileGroupBox->setMinimumSize(QSize(95, 160));
    fileGroupBox->setMaximumSize(QSize(95, 160));
    saveLineEdit = new QLineEdit(fileGroupBox);
    saveLineEdit->setObjectName(QString::fromUtf8("saveLineEdit"));
    saveLineEdit->setMinimumSize(QSize(40, 20));
    saveLineEdit->setMaximumSize(QSize(40, 20));
    newLineEdit = new QLineEdit(fileGroupBox);
    newLineEdit->setObjectName(QString::fromUtf8("newLineEdit"));
    newLineEdit->setMinimumSize(QSize(40, 20));
    newLineEdit->setMaximumSize(QSize(40, 20));
    printLabel = new QLabel(fileGroupBox);
    printLabel->setObjectName(QString::fromUtf8("printLabel"));
    newLabel = new QLabel(fileGroupBox);
    newLabel->setObjectName(QString::fromUtf8("newLabel"));
    saveLabel = new QLabel(fileGroupBox);
    saveLabel->setObjectName(QString::fromUtf8("saveLabel"));
    openLabel = new QLabel(fileGroupBox);
    openLabel->setObjectName(QString::fromUtf8("openLabel"));
    closeLineEdit = new QLineEdit(fileGroupBox);
    closeLineEdit->setObjectName(QString::fromUtf8("closeLineEdit"));
    closeLineEdit->setMinimumSize(QSize(40, 20));
    closeLineEdit->setMaximumSize(QSize(40, 20));
    printLineEdit = new QLineEdit(fileGroupBox);
    printLineEdit->setObjectName(QString::fromUtf8("printLineEdit"));
    printLineEdit->setMinimumSize(QSize(40, 20));
    printLineEdit->setMaximumSize(QSize(40, 20));
    openLineEdit = new QLineEdit(fileGroupBox);
    openLineEdit->setObjectName(QString::fromUtf8("openLineEdit"));
    openLineEdit->setMinimumSize(QSize(40, 20));
    openLineEdit->setMaximumSize(QSize(40, 20));
    closeLabel = new QLabel(fileGroupBox);
    closeLabel->setObjectName(QString::fromUtf8("closeLabel"));
    navigationTabWidget->addTab(shortcutsTab, QApplication::translate("SettingsDialog", "Shortcuts", 0, QApplication::UnicodeUTF8));
    widget = new QWidget(SettingsDialog);
    widget->setObjectName(QString::fromUtf8("widget"));
    hboxLayout7 = new QHBoxLayout(widget);
    hboxLayout7->setSpacing(6);
    hboxLayout7->setMargin(0);
    hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
    spacerItem10 = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout7->addItem(spacerItem10);

    okButton = new QPushButton(widget);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    hboxLayout7->addWidget(okButton);

    cancelButton = new QPushButton(widget);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

    hboxLayout7->addWidget(cancelButton);

    retranslateUi(SettingsDialog);

    QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
    SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Brainfuck Studio - Settings", 0, QApplication::UnicodeUTF8));
    lineNumbersCheckBox->setText(QApplication::translate("SettingsDialog", "Show line numbers", 0, QApplication::UnicodeUTF8));
    syntaxHighlightingCheckBox->setText(QApplication::translate("SettingsDialog", "Syntax-Highlighting", 0, QApplication::UnicodeUTF8));
    encodingComboBox->clear();
    encodingComboBox->addItem(QApplication::translate("SettingsDialog", "UTF-8", 0, QApplication::UnicodeUTF8));
    encodingComboBox->addItem(QApplication::translate("SettingsDialog", "ISO 8859-15", 0, QApplication::UnicodeUTF8));
    eofComboBox->clear();
    eofComboBox->addItem(QApplication::translate("SettingsDialog", "Windows", 0, QApplication::UnicodeUTF8));
    eofComboBox->addItem(QApplication::translate("SettingsDialog", "Unix", 0, QApplication::UnicodeUTF8));
    eofComboBox->addItem(QApplication::translate("SettingsDialog", "Mac", 0, QApplication::UnicodeUTF8));
    encodingLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Encoding</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    eofLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:10pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><span style=\" font-size:10pt;\">End of line</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    fontsGroupBox->setTitle(QApplication::translate("SettingsDialog", "Fonts and Colors", 0, QApplication::UnicodeUTF8));
    characterLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Character</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    characterComboBox->clear();
    characterComboBox->addItem(QApplication::translate("SettingsDialog", "> (increment pointer)", 0, QApplication::UnicodeUTF8));
    characterComboBox->addItem(QApplication::translate("SettingsDialog", "< (decrement pointer)", 0, QApplication::UnicodeUTF8));
    characterComboBox->addItem(QApplication::translate("SettingsDialog", "+ (increment cell value)", 0, QApplication::UnicodeUTF8));
    characterComboBox->addItem(QApplication::translate("SettingsDialog", "- (decrement cell value)", 0, QApplication::UnicodeUTF8));
    characterComboBox->addItem(QApplication::translate("SettingsDialog", ". (output cell value)", 0, QApplication::UnicodeUTF8));
    characterComboBox->addItem(QApplication::translate("SettingsDialog", ", (read cell value)", 0, QApplication::UnicodeUTF8));
    characterComboBox->addItem(QApplication::translate("SettingsDialog", "[ (start loop)", 0, QApplication::UnicodeUTF8));
    characterComboBox->addItem(QApplication::translate("SettingsDialog", "] (end loop)", 0, QApplication::UnicodeUTF8));
    fontLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Font</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    fontComboBox->clear();
    fontComboBox->addItem(QApplication::translate("SettingsDialog", "Courier New", 0, QApplication::UnicodeUTF8));
    styleLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Style</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    styleComboBox->clear();
    styleComboBox->addItem(QApplication::translate("SettingsDialog", "Standard", 0, QApplication::UnicodeUTF8));
    styleComboBox->addItem(QApplication::translate("SettingsDialog", "fett", 0, QApplication::UnicodeUTF8));
    styleComboBox->addItem(QApplication::translate("SettingsDialog", "kursiv", 0, QApplication::UnicodeUTF8));
    styleComboBox->addItem(QApplication::translate("SettingsDialog", "fett kursiv", 0, QApplication::UnicodeUTF8));
    sizeLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Size</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    sizeComboBox->clear();
    sizeComboBox->addItem(QApplication::translate("SettingsDialog", "10", 0, QApplication::UnicodeUTF8));
    sizeComboBox->addItem(QApplication::translate("SettingsDialog", "11", 0, QApplication::UnicodeUTF8));
    sizeComboBox->addItem(QApplication::translate("SettingsDialog", "12", 0, QApplication::UnicodeUTF8));
    colorLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Color</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    colorComboBox->clear();
    colorComboBox->addItem(QApplication::translate("SettingsDialog", "Black", 0, QApplication::UnicodeUTF8));
    colorComboBox->addItem(QApplication::translate("SettingsDialog", "Red", 0, QApplication::UnicodeUTF8));
    colorComboBox->addItem(QApplication::translate("SettingsDialog", "Yellow", 0, QApplication::UnicodeUTF8));
    colorComboBox->addItem(QApplication::translate("SettingsDialog", "Blue", 0, QApplication::UnicodeUTF8));
    colorComboBox->addItem(QApplication::translate("SettingsDialog", "Green", 0, QApplication::UnicodeUTF8));
    colorComboBox->addItem(QApplication::translate("SettingsDialog", "Grey", 0, QApplication::UnicodeUTF8));
    navigationTabWidget->setTabText(navigationTabWidget->indexOf(editorTab), QApplication::translate("SettingsDialog", "Editor", 0, QApplication::UnicodeUTF8));
    plattformLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Target platform</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    plattformComboBox->clear();
    plattformComboBox->addItem(QApplication::translate("SettingsDialog", "Windows 32", 0, QApplication::UnicodeUTF8));
    plattformComboBox->addItem(QApplication::translate("SettingsDialog", "Linux x86", 0, QApplication::UnicodeUTF8));
    optLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Optimisation Level</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    optComboBox->clear();
    optComboBox->addItem(QApplication::translate("SettingsDialog", "Level 1", 0, QApplication::UnicodeUTF8));
    optComboBox->addItem(QApplication::translate("SettingsDialog", "Level 2", 0, QApplication::UnicodeUTF8));
    optComboBox->addItem(QApplication::translate("SettingsDialog", "Level 3", 0, QApplication::UnicodeUTF8));
    targetLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Target file</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    warningsCheckBox->setText(QApplication::translate("SettingsDialog", "Show warnings", 0, QApplication::UnicodeUTF8));
    navigationTabWidget->setTabText(navigationTabWidget->indexOf(compilerTab), QApplication::translate("SettingsDialog", "Compiler", 0, QApplication::UnicodeUTF8));
    editGroupBox->setTitle(QApplication::translate("SettingsDialog", "Edit", 0, QApplication::UnicodeUTF8));
    findLabel->setText(QApplication::translate("SettingsDialog", "Find", 0, QApplication::UnicodeUTF8));
    undoLabel->setText(QApplication::translate("SettingsDialog", "Undo", 0, QApplication::UnicodeUTF8));
    pasteLabel->setText(QApplication::translate("SettingsDialog", "Paste", 0, QApplication::UnicodeUTF8));
    redoLabel->setText(QApplication::translate("SettingsDialog", "Redo", 0, QApplication::UnicodeUTF8));
    cutLabel->setText(QApplication::translate("SettingsDialog", "Cut", 0, QApplication::UnicodeUTF8));
    selectLabel->setText(QApplication::translate("SettingsDialog", "Select", 0, QApplication::UnicodeUTF8));
    copyLabel->setText(QApplication::translate("SettingsDialog", "Copy", 0, QApplication::UnicodeUTF8));
    compileGroupBox->setTitle(QApplication::translate("SettingsDialog", "Compile", 0, QApplication::UnicodeUTF8));
    undoLabel1->setText(QApplication::translate("SettingsDialog", "Undo", 0, QApplication::UnicodeUTF8));
    interpreterLabel->setText(QApplication::translate("SettingsDialog", "Interpret", 0, QApplication::UnicodeUTF8));
    debugGroupBox->setTitle(QApplication::translate("SettingsDialog", "Debug", 0, QApplication::UnicodeUTF8));
    startLabel->setText(QApplication::translate("SettingsDialog", "Start", 0, QApplication::UnicodeUTF8));
    nextStepLabel->setText(QApplication::translate("SettingsDialog", "Next Step", 0, QApplication::UnicodeUTF8));
    helpGroupBox->setTitle(QApplication::translate("SettingsDialog", "Help", 0, QApplication::UnicodeUTF8));
    handbookLabel->setText(QApplication::translate("SettingsDialog", "BFS Handbook", 0, QApplication::UnicodeUTF8));
    fileGroupBox->setTitle(QApplication::translate("SettingsDialog", "File", 0, QApplication::UnicodeUTF8));
    printLabel->setText(QApplication::translate("SettingsDialog", "Print", 0, QApplication::UnicodeUTF8));
    newLabel->setText(QApplication::translate("SettingsDialog", "New", 0, QApplication::UnicodeUTF8));
    saveLabel->setText(QApplication::translate("SettingsDialog", "Save", 0, QApplication::UnicodeUTF8));
    openLabel->setText(QApplication::translate("SettingsDialog", "Open", 0, QApplication::UnicodeUTF8));
    closeLabel->setText(QApplication::translate("SettingsDialog", "Close", 0, QApplication::UnicodeUTF8));
    navigationTabWidget->setTabText(navigationTabWidget->indexOf(shortcutsTab), QApplication::translate("SettingsDialog", "Shortcuts", 0, QApplication::UnicodeUTF8));
    okButton->setText(QApplication::translate("SettingsDialog", "OK", 0, QApplication::UnicodeUTF8));
    cancelButton->setText(QApplication::translate("SettingsDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(SettingsDialog);
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

#endif // SETTINGS_H
