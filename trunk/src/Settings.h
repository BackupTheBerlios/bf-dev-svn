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
    QVBoxLayout *vboxLayout;
    QTabWidget *settingsTabWidget;
    QWidget *tab_2;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout2;
    QCheckBox *lineNumCheckBox;
    QCheckBox *syntaxHighCheckBox;
    QSpacerItem *spacerItem;
    QGridLayout *gridLayout;
    QComboBox *encodingComboBox;
    QComboBox *endOfLineComboBox;
    QLabel *EncodingLabel;
    QLabel *endOfLineLabel;
    QGroupBox *fontsColorsGroupBox;
    QVBoxLayout *vboxLayout3;
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
    QWidget *tab_3;
    QVBoxLayout *vboxLayout4;
    QVBoxLayout *vboxLayout5;
    QHBoxLayout *hboxLayout4;
    QLabel *platformLabel;
    QComboBox *platformComboBox;
    QSpacerItem *spacerItem7;
    QHBoxLayout *hboxLayout5;
    QLabel *optimisationLabel;
    QComboBox *optimisationComboBox;
    QSpacerItem *spacerItem8;
    QHBoxLayout *hboxLayout6;
    QLabel *targetFileLabel;
    QLineEdit *targetFileLineEdit;
    QCheckBox *warningsCheckBox;
    QSpacerItem *spacerItem9;
    QWidget *tab_4;
    QWidget *widget;
    QVBoxLayout *vboxLayout6;
    QGroupBox *compileGroupBox;
    QGridLayout *gridLayout1;
    QLineEdit *interpretLineEdit;
    QLineEdit *compUndoLineEdit;
    QLabel *compUndoLabel;
    QLabel *interpretLabel;
    QGroupBox *debugGroupBox;
    QGridLayout *gridLayout2;
    QLineEdit *nextStepLineEdit;
    QLineEdit *startLineEdit;
    QLabel *startLabel;
    QLabel *nextStepLabel;
    QGroupBox *helpGroupBox;
    QGridLayout *gridLayout3;
    QLineEdit *handbookLineEdit;
    QLabel *handbookLabel;
    QGroupBox *fileGroupBox;
    QGridLayout *gridLayout4;
    QLineEdit *saveLineEdit;
    QLineEdit *newLineEdit;
    QLabel *printLabel;
    QLineEdit *openLineEdit;
    QLabel *newLabel;
    QLabel *closeLabel;
    QLabel *saveLabel;
    QLabel *openLabel;
    QLineEdit *closeLineEdit;
    QLineEdit *printLineEdit;
    QGroupBox *editGroupBox;
    QGridLayout *gridLayout5;
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
    vboxLayout = new QVBoxLayout(SettingsDialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    settingsTabWidget = new QTabWidget(SettingsDialog);
    settingsTabWidget->setObjectName(QString::fromUtf8("settingsTabWidget"));
    settingsTabWidget->setMaximumSize(QSize(16777215, 16777215));
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    vboxLayout1 = new QVBoxLayout(tab_2);
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(9);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    vboxLayout2 = new QVBoxLayout();
    vboxLayout2->setSpacing(6);
    vboxLayout2->setMargin(0);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    lineNumCheckBox = new QCheckBox(tab_2);
    lineNumCheckBox->setObjectName(QString::fromUtf8("lineNumCheckBox"));
    QFont font;
    font.setFamily(QString::fromUtf8("Sans Serif"));
    font.setPointSize(10);
    font.setBold(false);
    font.setItalic(false);
    font.setUnderline(false);
    font.setWeight(50);
    font.setStrikeOut(false);
    lineNumCheckBox->setFont(font);

    vboxLayout2->addWidget(lineNumCheckBox);

    syntaxHighCheckBox = new QCheckBox(tab_2);
    syntaxHighCheckBox->setObjectName(QString::fromUtf8("syntaxHighCheckBox"));
    QFont font1;
    font1.setFamily(QString::fromUtf8("Sans Serif"));
    font1.setPointSize(10);
    font1.setBold(false);
    font1.setItalic(false);
    font1.setUnderline(false);
    font1.setWeight(50);
    font1.setStrikeOut(false);
    syntaxHighCheckBox->setFont(font1);

    vboxLayout2->addWidget(syntaxHighCheckBox);


    hboxLayout->addLayout(vboxLayout2);

    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    gridLayout = new QGridLayout();
    gridLayout->setSpacing(6);
    gridLayout->setMargin(0);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    encodingComboBox = new QComboBox(tab_2);
    encodingComboBox->setObjectName(QString::fromUtf8("encodingComboBox"));

    gridLayout->addWidget(encodingComboBox, 1, 1, 1, 1);

    endOfLineComboBox = new QComboBox(tab_2);
    endOfLineComboBox->setObjectName(QString::fromUtf8("endOfLineComboBox"));

    gridLayout->addWidget(endOfLineComboBox, 0, 1, 1, 1);

    EncodingLabel = new QLabel(tab_2);
    EncodingLabel->setObjectName(QString::fromUtf8("EncodingLabel"));

    gridLayout->addWidget(EncodingLabel, 1, 0, 1, 1);

    endOfLineLabel = new QLabel(tab_2);
    endOfLineLabel->setObjectName(QString::fromUtf8("endOfLineLabel"));
    QFont font2;
    font2.setFamily(QString::fromUtf8("Sans Serif"));
    font2.setPointSize(10);
    font2.setBold(false);
    font2.setItalic(false);
    font2.setUnderline(false);
    font2.setWeight(50);
    font2.setStrikeOut(false);
    endOfLineLabel->setFont(font2);

    gridLayout->addWidget(endOfLineLabel, 0, 0, 1, 1);


    hboxLayout->addLayout(gridLayout);


    vboxLayout1->addLayout(hboxLayout);

    fontsColorsGroupBox = new QGroupBox(tab_2);
    fontsColorsGroupBox->setObjectName(QString::fromUtf8("fontsColorsGroupBox"));
    vboxLayout3 = new QVBoxLayout(fontsColorsGroupBox);
    vboxLayout3->setSpacing(6);
    vboxLayout3->setMargin(9);
    vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    characterLabel = new QLabel(fontsColorsGroupBox);
    characterLabel->setObjectName(QString::fromUtf8("characterLabel"));

    hboxLayout1->addWidget(characterLabel);

    characterComboBox = new QComboBox(fontsColorsGroupBox);
    characterComboBox->setObjectName(QString::fromUtf8("characterComboBox"));

    hboxLayout1->addWidget(characterComboBox);

    spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem1);


    vboxLayout3->addLayout(hboxLayout1);

    hboxLayout2 = new QHBoxLayout();
    hboxLayout2->setSpacing(6);
    hboxLayout2->setMargin(0);
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    fontLabel = new QLabel(fontsColorsGroupBox);
    fontLabel->setObjectName(QString::fromUtf8("fontLabel"));

    hboxLayout2->addWidget(fontLabel);

    fontComboBox = new QComboBox(fontsColorsGroupBox);
    fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
    fontComboBox->setMinimumSize(QSize(89, 0));

    hboxLayout2->addWidget(fontComboBox);

    spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem2);

    styleLabel = new QLabel(fontsColorsGroupBox);
    styleLabel->setObjectName(QString::fromUtf8("styleLabel"));

    hboxLayout2->addWidget(styleLabel);

    styleComboBox = new QComboBox(fontsColorsGroupBox);
    styleComboBox->setObjectName(QString::fromUtf8("styleComboBox"));
    styleComboBox->setMinimumSize(QSize(80, 0));

    hboxLayout2->addWidget(styleComboBox);

    spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem3);

    sizeLabel = new QLabel(fontsColorsGroupBox);
    sizeLabel->setObjectName(QString::fromUtf8("sizeLabel"));

    hboxLayout2->addWidget(sizeLabel);

    sizeComboBox = new QComboBox(fontsColorsGroupBox);
    sizeComboBox->setObjectName(QString::fromUtf8("sizeComboBox"));
    sizeComboBox->setMinimumSize(QSize(40, 0));

    hboxLayout2->addWidget(sizeComboBox);

    spacerItem4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem4);


    vboxLayout3->addLayout(hboxLayout2);

    hboxLayout3 = new QHBoxLayout();
    hboxLayout3->setSpacing(6);
    hboxLayout3->setMargin(0);
    hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
    colorLabel = new QLabel(fontsColorsGroupBox);
    colorLabel->setObjectName(QString::fromUtf8("colorLabel"));

    hboxLayout3->addWidget(colorLabel);

    colorComboBox = new QComboBox(fontsColorsGroupBox);
    colorComboBox->setObjectName(QString::fromUtf8("colorComboBox"));
    colorComboBox->setMinimumSize(QSize(60, 0));

    hboxLayout3->addWidget(colorComboBox);

    spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout3->addItem(spacerItem5);


    vboxLayout3->addLayout(hboxLayout3);


    vboxLayout1->addWidget(fontsColorsGroupBox);

    spacerItem6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout1->addItem(spacerItem6);

    settingsTabWidget->addTab(tab_2, QApplication::translate("SettingsDialog", "Editor", 0, QApplication::UnicodeUTF8));
    tab_3 = new QWidget();
    tab_3->setObjectName(QString::fromUtf8("tab_3"));
    vboxLayout4 = new QVBoxLayout(tab_3);
    vboxLayout4->setSpacing(6);
    vboxLayout4->setMargin(9);
    vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
    vboxLayout5 = new QVBoxLayout();
    vboxLayout5->setSpacing(6);
    vboxLayout5->setMargin(0);
    vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
    hboxLayout4 = new QHBoxLayout();
    hboxLayout4->setSpacing(6);
    hboxLayout4->setMargin(0);
    hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
    platformLabel = new QLabel(tab_3);
    platformLabel->setObjectName(QString::fromUtf8("platformLabel"));

    hboxLayout4->addWidget(platformLabel);

    platformComboBox = new QComboBox(tab_3);
    platformComboBox->setObjectName(QString::fromUtf8("platformComboBox"));

    hboxLayout4->addWidget(platformComboBox);

    spacerItem7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout4->addItem(spacerItem7);


    vboxLayout5->addLayout(hboxLayout4);

    hboxLayout5 = new QHBoxLayout();
    hboxLayout5->setSpacing(6);
    hboxLayout5->setMargin(0);
    hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
    optimisationLabel = new QLabel(tab_3);
    optimisationLabel->setObjectName(QString::fromUtf8("optimisationLabel"));

    hboxLayout5->addWidget(optimisationLabel);

    optimisationComboBox = new QComboBox(tab_3);
    optimisationComboBox->setObjectName(QString::fromUtf8("optimisationComboBox"));

    hboxLayout5->addWidget(optimisationComboBox);

    spacerItem8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout5->addItem(spacerItem8);


    vboxLayout5->addLayout(hboxLayout5);

    hboxLayout6 = new QHBoxLayout();
    hboxLayout6->setSpacing(6);
    hboxLayout6->setMargin(0);
    hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
    targetFileLabel = new QLabel(tab_3);
    targetFileLabel->setObjectName(QString::fromUtf8("targetFileLabel"));

    hboxLayout6->addWidget(targetFileLabel);

    targetFileLineEdit = new QLineEdit(tab_3);
    targetFileLineEdit->setObjectName(QString::fromUtf8("targetFileLineEdit"));

    hboxLayout6->addWidget(targetFileLineEdit);


    vboxLayout5->addLayout(hboxLayout6);

    warningsCheckBox = new QCheckBox(tab_3);
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

    vboxLayout5->addWidget(warningsCheckBox);


    vboxLayout4->addLayout(vboxLayout5);

    spacerItem9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout4->addItem(spacerItem9);

    settingsTabWidget->addTab(tab_3, QApplication::translate("SettingsDialog", "Compiler", 0, QApplication::UnicodeUTF8));
    tab_4 = new QWidget();
    tab_4->setObjectName(QString::fromUtf8("tab_4"));
    widget = new QWidget(tab_4);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(240, 0, 143, 234));
    vboxLayout6 = new QVBoxLayout(widget);
    vboxLayout6->setSpacing(6);
    vboxLayout6->setMargin(0);
    vboxLayout6->setObjectName(QString::fromUtf8("vboxLayout6"));
    compileGroupBox = new QGroupBox(widget);
    compileGroupBox->setObjectName(QString::fromUtf8("compileGroupBox"));
    compileGroupBox->setMinimumSize(QSize(141, 82));
    compileGroupBox->setMaximumSize(QSize(141, 82));
    gridLayout1 = new QGridLayout(compileGroupBox);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    interpretLineEdit = new QLineEdit(compileGroupBox);
    interpretLineEdit->setObjectName(QString::fromUtf8("interpretLineEdit"));
    interpretLineEdit->setMinimumSize(QSize(40, 20));
    interpretLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout1->addWidget(interpretLineEdit, 1, 1, 1, 1);

    compUndoLineEdit = new QLineEdit(compileGroupBox);
    compUndoLineEdit->setObjectName(QString::fromUtf8("compUndoLineEdit"));
    compUndoLineEdit->setMinimumSize(QSize(40, 20));
    compUndoLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout1->addWidget(compUndoLineEdit, 0, 1, 1, 1);

    compUndoLabel = new QLabel(compileGroupBox);
    compUndoLabel->setObjectName(QString::fromUtf8("compUndoLabel"));

    gridLayout1->addWidget(compUndoLabel, 0, 0, 1, 1);

    interpretLabel = new QLabel(compileGroupBox);
    interpretLabel->setObjectName(QString::fromUtf8("interpretLabel"));

    gridLayout1->addWidget(interpretLabel, 1, 0, 1, 1);


    vboxLayout6->addWidget(compileGroupBox);

    debugGroupBox = new QGroupBox(widget);
    debugGroupBox->setObjectName(QString::fromUtf8("debugGroupBox"));
    debugGroupBox->setMinimumSize(QSize(141, 82));
    debugGroupBox->setMaximumSize(QSize(141, 82));
    gridLayout2 = new QGridLayout(debugGroupBox);
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(9);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    nextStepLineEdit = new QLineEdit(debugGroupBox);
    nextStepLineEdit->setObjectName(QString::fromUtf8("nextStepLineEdit"));
    nextStepLineEdit->setMinimumSize(QSize(40, 20));
    nextStepLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout2->addWidget(nextStepLineEdit, 1, 1, 1, 1);

    startLineEdit = new QLineEdit(debugGroupBox);
    startLineEdit->setObjectName(QString::fromUtf8("startLineEdit"));
    startLineEdit->setMinimumSize(QSize(40, 20));
    startLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout2->addWidget(startLineEdit, 0, 1, 1, 1);

    startLabel = new QLabel(debugGroupBox);
    startLabel->setObjectName(QString::fromUtf8("startLabel"));

    gridLayout2->addWidget(startLabel, 0, 0, 1, 1);

    nextStepLabel = new QLabel(debugGroupBox);
    nextStepLabel->setObjectName(QString::fromUtf8("nextStepLabel"));

    gridLayout2->addWidget(nextStepLabel, 1, 0, 1, 1);


    vboxLayout6->addWidget(debugGroupBox);

    helpGroupBox = new QGroupBox(widget);
    helpGroupBox->setObjectName(QString::fromUtf8("helpGroupBox"));
    helpGroupBox->setMinimumSize(QSize(141, 56));
    helpGroupBox->setMaximumSize(QSize(141, 56));
    gridLayout3 = new QGridLayout(helpGroupBox);
    gridLayout3->setSpacing(6);
    gridLayout3->setMargin(9);
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    handbookLineEdit = new QLineEdit(helpGroupBox);
    handbookLineEdit->setObjectName(QString::fromUtf8("handbookLineEdit"));
    handbookLineEdit->setMinimumSize(QSize(40, 20));
    handbookLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout3->addWidget(handbookLineEdit, 0, 1, 1, 1);

    handbookLabel = new QLabel(helpGroupBox);
    handbookLabel->setObjectName(QString::fromUtf8("handbookLabel"));

    gridLayout3->addWidget(handbookLabel, 0, 0, 1, 1);


    vboxLayout6->addWidget(helpGroupBox);

    fileGroupBox = new QGroupBox(tab_4);
    fileGroupBox->setObjectName(QString::fromUtf8("fileGroupBox"));
    fileGroupBox->setGeometry(QRect(10, 0, 95, 160));
    fileGroupBox->setMinimumSize(QSize(95, 160));
    fileGroupBox->setMaximumSize(QSize(95, 160));
    gridLayout4 = new QGridLayout(fileGroupBox);
    gridLayout4->setSpacing(6);
    gridLayout4->setMargin(9);
    gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
    saveLineEdit = new QLineEdit(fileGroupBox);
    saveLineEdit->setObjectName(QString::fromUtf8("saveLineEdit"));
    saveLineEdit->setMinimumSize(QSize(40, 20));
    saveLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout4->addWidget(saveLineEdit, 2, 1, 1, 1);

    newLineEdit = new QLineEdit(fileGroupBox);
    newLineEdit->setObjectName(QString::fromUtf8("newLineEdit"));
    newLineEdit->setMinimumSize(QSize(40, 20));
    newLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout4->addWidget(newLineEdit, 0, 1, 1, 1);

    printLabel = new QLabel(fileGroupBox);
    printLabel->setObjectName(QString::fromUtf8("printLabel"));

    gridLayout4->addWidget(printLabel, 3, 0, 1, 1);

    openLineEdit = new QLineEdit(fileGroupBox);
    openLineEdit->setObjectName(QString::fromUtf8("openLineEdit"));
    openLineEdit->setMinimumSize(QSize(40, 20));
    openLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout4->addWidget(openLineEdit, 1, 1, 1, 1);

    newLabel = new QLabel(fileGroupBox);
    newLabel->setObjectName(QString::fromUtf8("newLabel"));

    gridLayout4->addWidget(newLabel, 0, 0, 1, 1);

    closeLabel = new QLabel(fileGroupBox);
    closeLabel->setObjectName(QString::fromUtf8("closeLabel"));

    gridLayout4->addWidget(closeLabel, 4, 0, 1, 1);

    saveLabel = new QLabel(fileGroupBox);
    saveLabel->setObjectName(QString::fromUtf8("saveLabel"));

    gridLayout4->addWidget(saveLabel, 2, 0, 1, 1);

    openLabel = new QLabel(fileGroupBox);
    openLabel->setObjectName(QString::fromUtf8("openLabel"));

    gridLayout4->addWidget(openLabel, 1, 0, 1, 1);

    closeLineEdit = new QLineEdit(fileGroupBox);
    closeLineEdit->setObjectName(QString::fromUtf8("closeLineEdit"));
    closeLineEdit->setMinimumSize(QSize(40, 20));
    closeLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout4->addWidget(closeLineEdit, 4, 1, 1, 1);

    printLineEdit = new QLineEdit(fileGroupBox);
    printLineEdit->setObjectName(QString::fromUtf8("printLineEdit"));
    printLineEdit->setMinimumSize(QSize(40, 20));
    printLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout4->addWidget(printLineEdit, 3, 1, 1, 1);

    editGroupBox = new QGroupBox(tab_4);
    editGroupBox->setObjectName(QString::fromUtf8("editGroupBox"));
    editGroupBox->setGeometry(QRect(120, 0, 101, 212));
    editGroupBox->setMinimumSize(QSize(101, 212));
    editGroupBox->setMaximumSize(QSize(101, 212));
    gridLayout5 = new QGridLayout(editGroupBox);
    gridLayout5->setSpacing(6);
    gridLayout5->setMargin(9);
    gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
    findLineEdit = new QLineEdit(editGroupBox);
    findLineEdit->setObjectName(QString::fromUtf8("findLineEdit"));
    findLineEdit->setMinimumSize(QSize(40, 20));
    findLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout5->addWidget(findLineEdit, 6, 1, 1, 1);

    selectLineEdit = new QLineEdit(editGroupBox);
    selectLineEdit->setObjectName(QString::fromUtf8("selectLineEdit"));
    selectLineEdit->setMinimumSize(QSize(40, 20));
    selectLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout5->addWidget(selectLineEdit, 5, 1, 1, 1);

    pasteLineEdit = new QLineEdit(editGroupBox);
    pasteLineEdit->setObjectName(QString::fromUtf8("pasteLineEdit"));
    pasteLineEdit->setMinimumSize(QSize(40, 20));
    pasteLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout5->addWidget(pasteLineEdit, 4, 1, 1, 1);

    copyLineEdit = new QLineEdit(editGroupBox);
    copyLineEdit->setObjectName(QString::fromUtf8("copyLineEdit"));
    copyLineEdit->setMinimumSize(QSize(40, 20));
    copyLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout5->addWidget(copyLineEdit, 3, 1, 1, 1);

    cutLineEdit = new QLineEdit(editGroupBox);
    cutLineEdit->setObjectName(QString::fromUtf8("cutLineEdit"));
    cutLineEdit->setMinimumSize(QSize(40, 20));
    cutLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout5->addWidget(cutLineEdit, 2, 1, 1, 1);

    redoLineEdit = new QLineEdit(editGroupBox);
    redoLineEdit->setObjectName(QString::fromUtf8("redoLineEdit"));
    redoLineEdit->setMinimumSize(QSize(40, 20));
    redoLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout5->addWidget(redoLineEdit, 1, 1, 1, 1);

    undoLineEdit = new QLineEdit(editGroupBox);
    undoLineEdit->setObjectName(QString::fromUtf8("undoLineEdit"));
    undoLineEdit->setMinimumSize(QSize(40, 20));
    undoLineEdit->setMaximumSize(QSize(40, 20));

    gridLayout5->addWidget(undoLineEdit, 0, 1, 1, 1);

    findLabel = new QLabel(editGroupBox);
    findLabel->setObjectName(QString::fromUtf8("findLabel"));

    gridLayout5->addWidget(findLabel, 6, 0, 1, 1);

    undoLabel = new QLabel(editGroupBox);
    undoLabel->setObjectName(QString::fromUtf8("undoLabel"));

    gridLayout5->addWidget(undoLabel, 0, 0, 1, 1);

    pasteLabel = new QLabel(editGroupBox);
    pasteLabel->setObjectName(QString::fromUtf8("pasteLabel"));

    gridLayout5->addWidget(pasteLabel, 4, 0, 1, 1);

    redoLabel = new QLabel(editGroupBox);
    redoLabel->setObjectName(QString::fromUtf8("redoLabel"));

    gridLayout5->addWidget(redoLabel, 1, 0, 1, 1);

    cutLabel = new QLabel(editGroupBox);
    cutLabel->setObjectName(QString::fromUtf8("cutLabel"));

    gridLayout5->addWidget(cutLabel, 2, 0, 1, 1);

    selectLabel = new QLabel(editGroupBox);
    selectLabel->setObjectName(QString::fromUtf8("selectLabel"));

    gridLayout5->addWidget(selectLabel, 5, 0, 1, 1);

    copyLabel = new QLabel(editGroupBox);
    copyLabel->setObjectName(QString::fromUtf8("copyLabel"));

    gridLayout5->addWidget(copyLabel, 3, 0, 1, 1);

    settingsTabWidget->addTab(tab_4, QApplication::translate("SettingsDialog", "Shortcuts", 0, QApplication::UnicodeUTF8));

    vboxLayout->addWidget(settingsTabWidget);

    hboxLayout7 = new QHBoxLayout();
    hboxLayout7->setSpacing(6);
    hboxLayout7->setMargin(0);
    hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
    spacerItem10 = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout7->addItem(spacerItem10);

    okButton = new QPushButton(SettingsDialog);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    hboxLayout7->addWidget(okButton);

    cancelButton = new QPushButton(SettingsDialog);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

    hboxLayout7->addWidget(cancelButton);


    vboxLayout->addLayout(hboxLayout7);

    retranslateUi(SettingsDialog);

    QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
    SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Brainfuck Studio - Settings", 0, QApplication::UnicodeUTF8));
    lineNumCheckBox->setText(QApplication::translate("SettingsDialog", "Show line numbers", 0, QApplication::UnicodeUTF8));
    syntaxHighCheckBox->setText(QApplication::translate("SettingsDialog", "Syntax-Highlighting", 0, QApplication::UnicodeUTF8));
    encodingComboBox->addItem(QApplication::translate("SettingsDialog", "UTF-8", 0, QApplication::UnicodeUTF8));
    encodingComboBox->addItem(QApplication::translate("SettingsDialog", "ISO 8859-15", 0, QApplication::UnicodeUTF8));
    endOfLineComboBox->addItem(QApplication::translate("SettingsDialog", "Windows", 0, QApplication::UnicodeUTF8));
    endOfLineComboBox->addItem(QApplication::translate("SettingsDialog", "Unix", 0, QApplication::UnicodeUTF8));
    endOfLineComboBox->addItem(QApplication::translate("SettingsDialog", "Mac", 0, QApplication::UnicodeUTF8));
    EncodingLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Encoding</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    endOfLineLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:10pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><span style=\" font-size:10pt;\">End of line</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    fontsColorsGroupBox->setTitle(QApplication::translate("SettingsDialog", "Fonts and Colors", 0, QApplication::UnicodeUTF8));
    characterLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Character</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    characterComboBox->addItem(QApplication::translate("SettingsDialog", "> (increment pointer)", 0, QApplication::UnicodeUTF8));
    characterComboBox->addItem(QApplication::translate("SettingsDialog", "< (decrement pointer)", 0, QApplication::UnicodeUTF8));
    characterComboBox->addItem(QApplication::translate("SettingsDialog", "+ (increment cell value)", 0, QApplication::UnicodeUTF8));
    characterComboBox->addItem(QApplication::translate("SettingsDialog", "- (decrement cell value)", 0, QApplication::UnicodeUTF8));
    characterComboBox->addItem(QApplication::translate("SettingsDialog", ". (output cell value)", 0, QApplication::UnicodeUTF8));
    characterComboBox->addItem(QApplication::translate("SettingsDialog", ", (read cell value)", 0, QApplication::UnicodeUTF8));
    characterComboBox->addItem(QApplication::translate("SettingsDialog", "[ (start loop)", 0, QApplication::UnicodeUTF8));
    characterComboBox->addItem(QApplication::translate("SettingsDialog", "] (end loop)", 0, QApplication::UnicodeUTF8));
    fontLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Font</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    fontComboBox->addItem(QApplication::translate("SettingsDialog", "Courier New", 0, QApplication::UnicodeUTF8));
    styleLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Style</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    styleComboBox->addItem(QApplication::translate("SettingsDialog", "Standard", 0, QApplication::UnicodeUTF8));
    styleComboBox->addItem(QApplication::translate("SettingsDialog", "fett", 0, QApplication::UnicodeUTF8));
    styleComboBox->addItem(QApplication::translate("SettingsDialog", "kursiv", 0, QApplication::UnicodeUTF8));
    styleComboBox->addItem(QApplication::translate("SettingsDialog", "fett kursiv", 0, QApplication::UnicodeUTF8));
    sizeLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Size</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    sizeComboBox->addItem(QApplication::translate("SettingsDialog", "10", 0, QApplication::UnicodeUTF8));
    sizeComboBox->addItem(QApplication::translate("SettingsDialog", "11", 0, QApplication::UnicodeUTF8));
    sizeComboBox->addItem(QApplication::translate("SettingsDialog", "12", 0, QApplication::UnicodeUTF8));
    colorLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Color</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    colorComboBox->addItem(QApplication::translate("SettingsDialog", "Black", 0, QApplication::UnicodeUTF8));
    colorComboBox->addItem(QApplication::translate("SettingsDialog", "Red", 0, QApplication::UnicodeUTF8));
    colorComboBox->addItem(QApplication::translate("SettingsDialog", "Yellow", 0, QApplication::UnicodeUTF8));
    colorComboBox->addItem(QApplication::translate("SettingsDialog", "Blue", 0, QApplication::UnicodeUTF8));
    colorComboBox->addItem(QApplication::translate("SettingsDialog", "Green", 0, QApplication::UnicodeUTF8));
    colorComboBox->addItem(QApplication::translate("SettingsDialog", "Grey", 0, QApplication::UnicodeUTF8));
    settingsTabWidget->setTabText(settingsTabWidget->indexOf(tab_2), QApplication::translate("SettingsDialog", "Editor", 0, QApplication::UnicodeUTF8));
    platformLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Target platform</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    platformComboBox->addItem(QApplication::translate("SettingsDialog", "Windows 32", 0, QApplication::UnicodeUTF8));
    platformComboBox->addItem(QApplication::translate("SettingsDialog", "Linux x86", 0, QApplication::UnicodeUTF8));
    optimisationLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Optimisation Level</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    optimisationComboBox->addItem(QApplication::translate("SettingsDialog", "Level 1", 0, QApplication::UnicodeUTF8));
    optimisationComboBox->addItem(QApplication::translate("SettingsDialog", "Level 2", 0, QApplication::UnicodeUTF8));
    optimisationComboBox->addItem(QApplication::translate("SettingsDialog", "Level 3", 0, QApplication::UnicodeUTF8));
    targetFileLabel->setText(QApplication::translate("SettingsDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Target file</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    warningsCheckBox->setText(QApplication::translate("SettingsDialog", "Show warnings", 0, QApplication::UnicodeUTF8));
    settingsTabWidget->setTabText(settingsTabWidget->indexOf(tab_3), QApplication::translate("SettingsDialog", "Compiler", 0, QApplication::UnicodeUTF8));
    compileGroupBox->setTitle(QApplication::translate("SettingsDialog", "Compile", 0, QApplication::UnicodeUTF8));
    compUndoLabel->setText(QApplication::translate("SettingsDialog", "Undo", 0, QApplication::UnicodeUTF8));
    interpretLabel->setText(QApplication::translate("SettingsDialog", "Interpret", 0, QApplication::UnicodeUTF8));
    debugGroupBox->setTitle(QApplication::translate("SettingsDialog", "Debug", 0, QApplication::UnicodeUTF8));
    startLabel->setText(QApplication::translate("SettingsDialog", "Start", 0, QApplication::UnicodeUTF8));
    nextStepLabel->setText(QApplication::translate("SettingsDialog", "Next Step", 0, QApplication::UnicodeUTF8));
    helpGroupBox->setTitle(QApplication::translate("SettingsDialog", "Help", 0, QApplication::UnicodeUTF8));
    handbookLabel->setText(QApplication::translate("SettingsDialog", "BFS Handbook", 0, QApplication::UnicodeUTF8));
    fileGroupBox->setTitle(QApplication::translate("SettingsDialog", "File", 0, QApplication::UnicodeUTF8));
    printLabel->setText(QApplication::translate("SettingsDialog", "Print", 0, QApplication::UnicodeUTF8));
    newLabel->setText(QApplication::translate("SettingsDialog", "New", 0, QApplication::UnicodeUTF8));
    closeLabel->setText(QApplication::translate("SettingsDialog", "Close", 0, QApplication::UnicodeUTF8));
    saveLabel->setText(QApplication::translate("SettingsDialog", "Save", 0, QApplication::UnicodeUTF8));
    openLabel->setText(QApplication::translate("SettingsDialog", "Open", 0, QApplication::UnicodeUTF8));
    editGroupBox->setTitle(QApplication::translate("SettingsDialog", "Edit", 0, QApplication::UnicodeUTF8));
    findLabel->setText(QApplication::translate("SettingsDialog", "Find", 0, QApplication::UnicodeUTF8));
    undoLabel->setText(QApplication::translate("SettingsDialog", "Undo", 0, QApplication::UnicodeUTF8));
    pasteLabel->setText(QApplication::translate("SettingsDialog", "Paste", 0, QApplication::UnicodeUTF8));
    redoLabel->setText(QApplication::translate("SettingsDialog", "Redo", 0, QApplication::UnicodeUTF8));
    cutLabel->setText(QApplication::translate("SettingsDialog", "Cut", 0, QApplication::UnicodeUTF8));
    selectLabel->setText(QApplication::translate("SettingsDialog", "Select", 0, QApplication::UnicodeUTF8));
    copyLabel->setText(QApplication::translate("SettingsDialog", "Copy", 0, QApplication::UnicodeUTF8));
    settingsTabWidget->setTabText(settingsTabWidget->indexOf(tab_4), QApplication::translate("SettingsDialog", "Shortcuts", 0, QApplication::UnicodeUTF8));
    okButton->setText(QApplication::translate("SettingsDialog", "OK", 0, QApplication::UnicodeUTF8));
    cancelButton->setText(QApplication::translate("SettingsDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(SettingsDialog);
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

#endif // SETTINGS_H
