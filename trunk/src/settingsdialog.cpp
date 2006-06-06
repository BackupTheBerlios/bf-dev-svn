/*
 *      settingsdialog.cpp
 *
 *      Copyright 2006 bernhard kragl <bernhard@vincent>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 
 #include <QtGui>
 
 #include "settingsdialog.h"
 
 #include <iostream>
 using namespace std;
 
SettingsDialog::SettingsDialog(QWidget *parent)
	: QDialog(parent)
{
	resize(QSize(420, 320).expandedTo(minimumSizeHint()));
	setMinimumSize(QSize(420, 320));
	setMaximumSize(QSize(420, 320));
	
	tabWidget = new QTabWidget;
	tabWidget->setMaximumSize(QSize(16777215, 16777215));
	tabWidget->addTab(new EditorTab(), tr("Editor"));
	tabWidget->addTab(new CompilerTab(), tr("Compiler"));
	tabWidget->addTab(new ShortcutsTab(), tr("Shortcuts"));
	
	QPushButton *okButton = new QPushButton(tr("OK"));
	QPushButton *cancelButton = new QPushButton(tr("Cancel"));
	
	connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
	connect(okButton, SIGNAL(clicked()), this, SLOT(acceptSettings()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(rejectSettings()));
	
	QHBoxLayout *hboxLayoutButtons = new QHBoxLayout;
	hboxLayoutButtons->addStretch(1);
	hboxLayoutButtons->addWidget(okButton);
	hboxLayoutButtons->addWidget(cancelButton);
	
	QVBoxLayout *vboxLayoutMain = new QVBoxLayout;
	vboxLayoutMain->setSpacing(6);
	vboxLayoutMain->setMargin(9);
	vboxLayoutMain->addWidget(tabWidget);
	vboxLayoutMain->addLayout(hboxLayoutButtons);
	setLayout(vboxLayoutMain);
	
	setWindowTitle(tr("Settings"));
}

void SettingsDialog::acceptSettings()
{
	cout << "accept\n";
}

void SettingsDialog::rejectSettings()
{
	cout << "reject\n";
}

EditorTab::EditorTab(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout *vboxLayoutMain = new QVBoxLayout;
	QHBoxLayout *hboxLayoutGeneral = new QHBoxLayout;
	QVBoxLayout *vboxLayoutGeneralLeft = new QVBoxLayout;
	QGridLayout *gridLayoutGeneralRight = new QGridLayout;
	
	//----------------------------------------------------
	
	QCheckBox *lineNumbersCheckBox = new QCheckBox(tr("Show line numbers"));
	QCheckBox *syntaxHighlightingCheckBox = new QCheckBox(tr("Syntax-Highlighting"));
	
	vboxLayoutGeneralLeft->setSpacing(6);
	vboxLayoutGeneralLeft->setMargin(0);
	vboxLayoutGeneralLeft->addWidget(lineNumbersCheckBox);
	vboxLayoutGeneralLeft->addWidget(syntaxHighlightingCheckBox);
	
	QComboBox *endOfLineComboBox = new QComboBox;
	QComboBox *encodingComboBox = new QComboBox;
	endOfLineComboBox->addItem(QApplication::translate("SettingsDialog", "Windows", 0, QApplication::UnicodeUTF8));
	endOfLineComboBox->addItem(QApplication::translate("SettingsDialog", "Unix", 0, QApplication::UnicodeUTF8));
	endOfLineComboBox->addItem(QApplication::translate("SettingsDialog", "Mac", 0, QApplication::UnicodeUTF8));
	encodingComboBox->addItem(QApplication::translate("SettingsDialog", "UTF-8", 0, QApplication::UnicodeUTF8));
	encodingComboBox->addItem(QApplication::translate("SettingsDialog", "ISO 8859-15", 0, QApplication::UnicodeUTF8));
	
	gridLayoutGeneralRight->setSpacing(6);
	gridLayoutGeneralRight->setMargin(0);
	gridLayoutGeneralRight->addWidget(new QLabel(tr("End of line")), 0, 0, 1, 1);
	gridLayoutGeneralRight->addWidget(new QLabel(tr("Encoding")), 1, 0, 1, 1);
	gridLayoutGeneralRight->addWidget(endOfLineComboBox, 0, 1, 1, 1);
	gridLayoutGeneralRight->addWidget(encodingComboBox, 1, 1, 1, 1);
	
	hboxLayoutGeneral->setSpacing(6);
	hboxLayoutGeneral->setMargin(0);
	hboxLayoutGeneral->addLayout(vboxLayoutGeneralLeft);
	hboxLayoutGeneral->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	hboxLayoutGeneral->addLayout(gridLayoutGeneralRight);
	
	//----------------------------------------------------
	
	QGroupBox *fontsColorsGroupBox = new QGroupBox(tr("Fonts and Colors"));
	QVBoxLayout *vboxLayoutFontsColorsGrouptBox = new QVBoxLayout;
	
	QHBoxLayout *hboxLayoutFontsColorsLine1 = new QHBoxLayout;
	hboxLayoutFontsColorsLine1->setSpacing(6);
	hboxLayoutFontsColorsLine1->setMargin(0);
	QHBoxLayout *hboxLayoutFontsColorsLine2 = new QHBoxLayout;
	hboxLayoutFontsColorsLine2->setSpacing(6);
	hboxLayoutFontsColorsLine2->setMargin(0);
	QHBoxLayout *hboxLayoutFontsColorsLine3 = new QHBoxLayout;
	hboxLayoutFontsColorsLine3->setSpacing(6);
	hboxLayoutFontsColorsLine3->setMargin(0);
	
	hboxLayoutFontsColorsLine1->addWidget(new QLabel(tr("Character")));
	QComboBox *characterComboBox = new QComboBox();
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "> (increment pointer)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "< (decrement pointer)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "+ (increment cell value)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "- (decrement cell value)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", ". (output cell value)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", ", (read cell value)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "[ (start loop)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "] (end loop)", 0, QApplication::UnicodeUTF8));
	hboxLayoutFontsColorsLine1->addWidget(characterComboBox);
	hboxLayoutFontsColorsLine1->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	
	hboxLayoutFontsColorsLine2->addWidget(new QLabel(tr("Font")));
	QComboBox *fontComboBox = new QComboBox;
	fontComboBox->addItem(QApplication::translate("SettingsDialog", "Courier New", 0, QApplication::UnicodeUTF8));
	fontComboBox->setMinimumSize(QSize(89, 0));
	hboxLayoutFontsColorsLine2->addWidget(fontComboBox);
	hboxLayoutFontsColorsLine2->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	hboxLayoutFontsColorsLine2->addWidget(new QLabel(tr("Style")));
	QComboBox *styleComboBox = new QComboBox;
	styleComboBox->addItem(QApplication::translate("SettingsDialog", "Standard", 0, QApplication::UnicodeUTF8));
	styleComboBox->addItem(QApplication::translate("SettingsDialog", "fett", 0, QApplication::UnicodeUTF8));
	styleComboBox->addItem(QApplication::translate("SettingsDialog", "kursiv", 0, QApplication::UnicodeUTF8));
	styleComboBox->addItem(QApplication::translate("SettingsDialog", "fett kursiv", 0, QApplication::UnicodeUTF8));
	styleComboBox->setMinimumSize(QSize(80, 0));
	hboxLayoutFontsColorsLine2->addWidget(styleComboBox);
	hboxLayoutFontsColorsLine2->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	hboxLayoutFontsColorsLine2->addWidget(new QLabel(tr("Size")));
	QComboBox *sizeComboBox = new QComboBox;
	sizeComboBox->addItem(QApplication::translate("SettingsDialog", "10", 0, QApplication::UnicodeUTF8));
	sizeComboBox->addItem(QApplication::translate("SettingsDialog", "11", 0, QApplication::UnicodeUTF8));
	sizeComboBox->addItem(QApplication::translate("SettingsDialog", "12", 0, QApplication::UnicodeUTF8));
	sizeComboBox->setMinimumSize(QSize(40, 0));
	hboxLayoutFontsColorsLine2->addWidget(sizeComboBox);
	hboxLayoutFontsColorsLine2->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	
	hboxLayoutFontsColorsLine3->addWidget(new QLabel(tr("Color")));
	QComboBox *colorComboBox = new QComboBox();
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Black", 0, QApplication::UnicodeUTF8));
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Red", 0, QApplication::UnicodeUTF8));
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Yellow", 0, QApplication::UnicodeUTF8));
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Blue", 0, QApplication::UnicodeUTF8));
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Green", 0, QApplication::UnicodeUTF8));
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Grey", 0, QApplication::UnicodeUTF8));
	colorComboBox->setMinimumSize(QSize(60, 0));
	hboxLayoutFontsColorsLine3->addWidget(colorComboBox);
	hboxLayoutFontsColorsLine3->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	
	vboxLayoutFontsColorsGrouptBox->setSpacing(6);
	vboxLayoutFontsColorsGrouptBox->setMargin(9);
	vboxLayoutFontsColorsGrouptBox->addLayout(hboxLayoutFontsColorsLine1);
	vboxLayoutFontsColorsGrouptBox->addLayout(hboxLayoutFontsColorsLine2);
	vboxLayoutFontsColorsGrouptBox->addLayout(hboxLayoutFontsColorsLine3);
	fontsColorsGroupBox->setLayout(vboxLayoutFontsColorsGrouptBox);
		
	//----------------------------------------------------
	
	vboxLayoutMain->setSpacing(6);
	vboxLayoutMain->setMargin(9);
	vboxLayoutMain->addLayout(hboxLayoutGeneral);
	vboxLayoutMain->addWidget(fontsColorsGroupBox);
	vboxLayoutMain->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
	setLayout(vboxLayoutMain);
}

CompilerTab::CompilerTab(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout *vboxLayoutMain = new QVBoxLayout;
	QVBoxLayout *vboxLayoutCompilerTab = new QVBoxLayout;
	vboxLayoutCompilerTab->setSpacing(6);
	vboxLayoutCompilerTab->setMargin(0);
	QHBoxLayout *hboxLayoutCompilerTabLine1 = new QHBoxLayout;
	hboxLayoutCompilerTabLine1->setSpacing(6);
	hboxLayoutCompilerTabLine1->setMargin(0);
	QHBoxLayout *hboxLayoutCompilerTabLine2 = new QHBoxLayout;
	hboxLayoutCompilerTabLine2->setSpacing(6);
	hboxLayoutCompilerTabLine2->setMargin(0);
	QHBoxLayout *hboxLayoutCompilerTabLine3 = new QHBoxLayout;
	hboxLayoutCompilerTabLine3->setSpacing(6);
	hboxLayoutCompilerTabLine3->setMargin(0);
	
	//----------------------------------------------------
	
	hboxLayoutCompilerTabLine1->addWidget(new QLabel(tr("Target Platform")));
	QComboBox *platformComboBox = new QComboBox();
	platformComboBox->addItem(QApplication::translate("SettingsDialog", "Windows 32", 0, QApplication::UnicodeUTF8));
	platformComboBox->addItem(QApplication::translate("SettingsDialog", "Linux x86", 0, QApplication::UnicodeUTF8));
	hboxLayoutCompilerTabLine1->addWidget(platformComboBox);
	hboxLayoutCompilerTabLine1->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	
	hboxLayoutCompilerTabLine2->addWidget(new QLabel(tr("Optimisation Level")));
	QComboBox *optimisationComboBox = new QComboBox();
	optimisationComboBox->addItem(QApplication::translate("SettingsDialog", "Level 1", 0, QApplication::UnicodeUTF8));
	optimisationComboBox->addItem(QApplication::translate("SettingsDialog", "Level 2", 0, QApplication::UnicodeUTF8));
	optimisationComboBox->addItem(QApplication::translate("SettingsDialog", "Level 3", 0, QApplication::UnicodeUTF8));
	hboxLayoutCompilerTabLine2->addWidget(optimisationComboBox);
	hboxLayoutCompilerTabLine2->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	
	hboxLayoutCompilerTabLine3->addWidget(new QLabel(tr("Target File")));
	QLineEdit *targetFileLineEdit = new QLineEdit();
	hboxLayoutCompilerTabLine3->addWidget(targetFileLineEdit);
	
	QCheckBox *warningsCheckBox = new QCheckBox(tr("Show warnings"));
	
	//----------------------------------------------------
	
	vboxLayoutCompilerTab->addLayout(hboxLayoutCompilerTabLine1);
	vboxLayoutCompilerTab->addLayout(hboxLayoutCompilerTabLine2);
	vboxLayoutCompilerTab->addLayout(hboxLayoutCompilerTabLine3);
	vboxLayoutCompilerTab->addWidget(warningsCheckBox);
	vboxLayoutMain->setSpacing(6);
	vboxLayoutMain->setMargin(9);
	vboxLayoutMain->addLayout(vboxLayoutCompilerTab);
	vboxLayoutMain->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
	setLayout(vboxLayoutMain);
}

ShortcutsTab::ShortcutsTab(QWidget *parent)
	: QWidget(parent)
{
	QGroupBox *fileGroupBox = new QGroupBox(tr("File"));
	QGridLayout *gridLayoutFileGroupBox = new QGridLayout;
	QGroupBox *editGroupBox = new QGroupBox(tr("Edit"));
	QGridLayout *gridLayoutEditGroupBox = new QGridLayout;
	QGroupBox *compileGroupBox = new QGroupBox(tr("Compile"));
	QGridLayout *gridLayoutCompileGroupBox = new QGridLayout;
	QGroupBox *debugGroupBox = new QGroupBox(tr("Debug"));
	QGridLayout *gridLayoutDebugGroupBox = new QGridLayout;
	QGroupBox *helpGroupBox = new QGroupBox(tr("Help"));
	QGridLayout *gridLayoutHelpGroupBox = new QGridLayout;
	QVBoxLayout *vboxLayoutShortcutsLeft = new QVBoxLayout;
	
	//----------------------------------------------------
	
	fileGroupBox->setGeometry(QRect(10, 0, 95, 160));
	fileGroupBox->setMinimumSize(QSize(95, 160));
	fileGroupBox->setMaximumSize(QSize(95, 160));
	gridLayoutFileGroupBox->setSpacing(6);
	gridLayoutFileGroupBox->setMargin(9);
	gridLayoutFileGroupBox->addWidget(new QLabel(tr("New")), 0, 0, 1, 1);
	QLineEdit *newLineEdit = new QLineEdit;
	newLineEdit->setMinimumSize(QSize(40, 20));
	newLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutFileGroupBox->addWidget(newLineEdit, 0, 1, 1, 1);
	gridLayoutFileGroupBox->addWidget(new QLabel(tr("Open")), 1, 0, 1, 1);
	QLineEdit *openLineEdit = new QLineEdit;
	openLineEdit->setMinimumSize(QSize(40, 20));
	openLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutFileGroupBox->addWidget(openLineEdit, 1, 1, 1, 1);
	gridLayoutFileGroupBox->addWidget(new QLabel(tr("Save")), 2, 0, 1, 1);
	QLineEdit *saveLineEdit = new QLineEdit;
	saveLineEdit->setMinimumSize(QSize(40, 20));
	saveLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutFileGroupBox->addWidget(saveLineEdit, 2, 1, 1, 1);
	gridLayoutFileGroupBox->addWidget(new QLabel(tr("Print")), 3, 0, 1, 1);
	QLineEdit *printLineEdit = new QLineEdit;
	printLineEdit->setMinimumSize(QSize(40, 20));
	printLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutFileGroupBox->addWidget(printLineEdit, 3, 1, 1, 1);
	gridLayoutFileGroupBox->addWidget(new QLabel(tr("Close")), 4, 0, 1, 1);
	QLineEdit *closeLineEdit = new QLineEdit;
	closeLineEdit->setMinimumSize(QSize(40, 20));
	closeLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutFileGroupBox->addWidget(closeLineEdit, 4, 1, 1, 1);
	
	fileGroupBox->setLayout(gridLayoutFileGroupBox);
	
	//----------------------------------------------------
	
	editGroupBox->setGeometry(QRect(120, 0, 101, 212));
 	editGroupBox->setMinimumSize(QSize(101, 212));
	editGroupBox->setMaximumSize(QSize(101, 212));
	gridLayoutEditGroupBox->setSpacing(6);
	gridLayoutEditGroupBox->setMargin(9);
	gridLayoutEditGroupBox->addWidget(new QLabel(tr("Undo")), 0, 0, 1, 1);
	QLineEdit *undoLineEdit = new QLineEdit;
	undoLineEdit->setMinimumSize(QSize(40, 20));
	undoLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutEditGroupBox->addWidget(undoLineEdit, 0, 1, 1, 1);
	gridLayoutEditGroupBox->addWidget(new QLabel(tr("Redo")), 1, 0, 1, 1);
	QLineEdit *redoLineEdit = new QLineEdit;
	redoLineEdit->setMinimumSize(QSize(40, 20));
	redoLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutEditGroupBox->addWidget(redoLineEdit, 1, 1, 1, 1);
	gridLayoutEditGroupBox->addWidget(new QLabel(tr("Cut")), 2, 0, 1, 1);
	QLineEdit *cutLineEdit = new QLineEdit;
	cutLineEdit->setMinimumSize(QSize(40, 20));
	cutLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutEditGroupBox->addWidget(cutLineEdit, 2, 1, 1, 1);
	gridLayoutEditGroupBox->addWidget(new QLabel(tr("Copy")), 3, 0, 1, 1);
	QLineEdit *copyLineEdit = new QLineEdit;
	copyLineEdit->setMinimumSize(QSize(40, 20));
	copyLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutEditGroupBox->addWidget(copyLineEdit, 3, 1, 1, 1);
	gridLayoutEditGroupBox->addWidget(new QLabel(tr("Paste")), 4, 0, 1, 1);
	QLineEdit *pasteLineEdit = new QLineEdit;
	pasteLineEdit->setMinimumSize(QSize(40, 20));
	pasteLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutEditGroupBox->addWidget(pasteLineEdit, 4, 1, 1, 1);
	gridLayoutEditGroupBox->addWidget(new QLabel(tr("Select")), 5, 0, 1, 1);
	QLineEdit *selectLineEdit = new QLineEdit;
	selectLineEdit->setMinimumSize(QSize(40, 20));
	selectLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutEditGroupBox->addWidget(selectLineEdit, 5, 1, 1, 1);
	gridLayoutEditGroupBox->addWidget(new QLabel(tr("Find")), 6, 0, 1, 1);
	QLineEdit *findLineEdit = new QLineEdit;
	findLineEdit->setMinimumSize(QSize(40, 20));
	findLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutEditGroupBox->addWidget(findLineEdit, 6, 1, 1, 1);
	
	editGroupBox->setLayout(gridLayoutEditGroupBox);
	
	//----------------------------------------------------
	
	compileGroupBox->setMinimumSize(QSize(141, 82));
	compileGroupBox->setMaximumSize(QSize(141, 82));
	gridLayoutCompileGroupBox->setSpacing(6);
	gridLayoutCompileGroupBox->setMargin(9);
	gridLayoutCompileGroupBox->addWidget(new QLabel(tr("Undo")), 0, 0, 1, 1);
	QLineEdit *compUndoLineEdit = new QLineEdit;
	compUndoLineEdit->setMinimumSize(QSize(40, 20));
	compUndoLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutCompileGroupBox->addWidget(compUndoLineEdit, 0, 1, 1, 1);
	gridLayoutCompileGroupBox->addWidget(new QLabel(tr("Interpret")), 1, 0, 1, 1);
	QLineEdit *interpretLineEdit = new QLineEdit;
	interpretLineEdit->setMinimumSize(QSize(40, 20));
	interpretLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutCompileGroupBox->addWidget(interpretLineEdit, 1, 1, 1, 1);
	
	compileGroupBox->setLayout(gridLayoutCompileGroupBox);
	
	debugGroupBox->setMinimumSize(QSize(141, 82));
	debugGroupBox->setMaximumSize(QSize(141, 82));
	gridLayoutDebugGroupBox->setSpacing(6);
	gridLayoutDebugGroupBox->setMargin(9);
	gridLayoutDebugGroupBox->addWidget(new QLabel(tr("Start")), 0, 0, 1, 1);
	QLineEdit *startLineEdit = new QLineEdit;
	startLineEdit->setMinimumSize(QSize(40, 20));
	startLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutDebugGroupBox->addWidget(startLineEdit, 0, 1, 1, 1);
	gridLayoutDebugGroupBox->addWidget(new QLabel(tr("Next Step")), 1, 0, 1, 1);
	QLineEdit *nextStepLineEdit = new QLineEdit;
	nextStepLineEdit->setMinimumSize(QSize(40, 20));
	nextStepLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutDebugGroupBox->addWidget(nextStepLineEdit, 1, 1, 1, 1);
	
	debugGroupBox->setLayout(gridLayoutDebugGroupBox);
	
	helpGroupBox->setMinimumSize(QSize(141, 56));
	helpGroupBox->setMaximumSize(QSize(141, 56));
	gridLayoutHelpGroupBox->setSpacing(6);
	gridLayoutHelpGroupBox->setMargin(9);
	gridLayoutHelpGroupBox->addWidget(new QLabel(tr("BFS Handbook")), 0, 0, 1, 1);
	QLineEdit *handbookLineEdit = new QLineEdit;
	handbookLineEdit->setMinimumSize(QSize(40, 20));
	handbookLineEdit->setMaximumSize(QSize(40, 20));
	gridLayoutHelpGroupBox->addWidget(handbookLineEdit, 0, 1, 1, 1);
	
	helpGroupBox->setLayout(gridLayoutHelpGroupBox);
	
	vboxLayoutShortcutsLeft->setGeometry(QRect(240, 0, 143, 234));
	vboxLayoutShortcutsLeft->setSpacing(6);
	vboxLayoutShortcutsLeft->setMargin(0);
	vboxLayoutShortcutsLeft->addWidget(compileGroupBox);
	vboxLayoutShortcutsLeft->addWidget(debugGroupBox);
	vboxLayoutShortcutsLeft->addWidget(helpGroupBox);
	
	//----------------------------------------------------
	
	QHBoxLayout *hboxLayoutMain = new QHBoxLayout;
	hboxLayoutMain->setSpacing(6);
	hboxLayoutMain->setMargin(9);
	hboxLayoutMain->addWidget(fileGroupBox);
	hboxLayoutMain->addWidget(editGroupBox);
	hboxLayoutMain->addLayout(vboxLayoutShortcutsLeft);
	setLayout(hboxLayoutMain);
}
