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
	
	editorTab = new QWidget();
	compilerTab = new QWidget();
	shortcutsTab = new QWidget();
	
	//####################################################
	
	vboxLayoutEditorMain = new QVBoxLayout;
	hboxLayoutGeneral = new QHBoxLayout;
	vboxLayoutGeneralLeft = new QVBoxLayout;
	gridLayoutGeneralRight = new QGridLayout;
	
	//----------------------------------------------------
	
	lineNumbersCheckBox = new QCheckBox(tr("Show line numbers"));
	syntaxHighlightingCheckBox = new QCheckBox(tr("Syntax-Highlighting"));
	
	vboxLayoutGeneralLeft->setSpacing(6);
	vboxLayoutGeneralLeft->setMargin(0);
	vboxLayoutGeneralLeft->addWidget(lineNumbersCheckBox);
	vboxLayoutGeneralLeft->addWidget(syntaxHighlightingCheckBox);
	
	endOfLineComboBox = new QComboBox;
	encodingComboBox = new QComboBox;
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
	
	fontsColorsGroupBox = new QGroupBox(tr("Fonts and Colors"));
	vboxLayoutFontsColorsGrouptBox = new QVBoxLayout;
	
	hboxLayoutFontsColorsLine1 = new QHBoxLayout;
	hboxLayoutFontsColorsLine1->setSpacing(6);
	hboxLayoutFontsColorsLine1->setMargin(0);
	hboxLayoutFontsColorsLine2 = new QHBoxLayout;
	hboxLayoutFontsColorsLine2->setSpacing(6);
	hboxLayoutFontsColorsLine2->setMargin(0);
	hboxLayoutFontsColorsLine3 = new QHBoxLayout;
	hboxLayoutFontsColorsLine3->setSpacing(6);
	hboxLayoutFontsColorsLine3->setMargin(0);
	
	hboxLayoutFontsColorsLine1->addWidget(new QLabel(tr("Character")));
	characterComboBox = new QComboBox();
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "> (increment pointer)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "< (decrement pointer)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "+ (increment cell value)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "- (decrement cell value)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", ". (output cell value)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", ", (read cell value)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "[ (start loop)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "] (end loop)", 0, QApplication::UnicodeUTF8));
	connect(characterComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(readCharacterSettings(int)));
	hboxLayoutFontsColorsLine1->addWidget(characterComboBox);
	hboxLayoutFontsColorsLine1->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	
	hboxLayoutFontsColorsLine2->addWidget(new QLabel(tr("Font")));
	fontComboBox = new QComboBox;
	fontComboBox->addItem(QApplication::translate("SettingsDialog", "Courier New", 0, QApplication::UnicodeUTF8));
	fontComboBox->setMinimumSize(QSize(89, 0));
	connect(fontComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeFontSettings(int)));
	hboxLayoutFontsColorsLine2->addWidget(fontComboBox);
	hboxLayoutFontsColorsLine2->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	hboxLayoutFontsColorsLine2->addWidget(new QLabel(tr("Style")));
	styleComboBox = new QComboBox;
	styleComboBox->addItem(QApplication::translate("SettingsDialog", "Standard", 0, QApplication::UnicodeUTF8));
	styleComboBox->addItem(QApplication::translate("SettingsDialog", "fett", 0, QApplication::UnicodeUTF8));
	styleComboBox->addItem(QApplication::translate("SettingsDialog", "kursiv", 0, QApplication::UnicodeUTF8));
	styleComboBox->addItem(QApplication::translate("SettingsDialog", "fett kursiv", 0, QApplication::UnicodeUTF8));
	styleComboBox->setMinimumSize(QSize(80, 0));
	connect(styleComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeStyleSettings(int)));
	hboxLayoutFontsColorsLine2->addWidget(styleComboBox);
	hboxLayoutFontsColorsLine2->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	hboxLayoutFontsColorsLine2->addWidget(new QLabel(tr("Size")));
	sizeComboBox = new QComboBox;
	sizeComboBox->addItem(QApplication::translate("SettingsDialog", "10", 0, QApplication::UnicodeUTF8));
	sizeComboBox->addItem(QApplication::translate("SettingsDialog", "11", 0, QApplication::UnicodeUTF8));
	sizeComboBox->addItem(QApplication::translate("SettingsDialog", "12", 0, QApplication::UnicodeUTF8));
	sizeComboBox->setMinimumSize(QSize(40, 0));
	connect(sizeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeSizeSettings(int)));
	hboxLayoutFontsColorsLine2->addWidget(sizeComboBox);
	hboxLayoutFontsColorsLine2->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	
	hboxLayoutFontsColorsLine3->addWidget(new QLabel(tr("Color")));
	colorComboBox = new QComboBox();
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Black", 0, QApplication::UnicodeUTF8));
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Red", 0, QApplication::UnicodeUTF8));
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Yellow", 0, QApplication::UnicodeUTF8));
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Blue", 0, QApplication::UnicodeUTF8));
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Green", 0, QApplication::UnicodeUTF8));
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Grey", 0, QApplication::UnicodeUTF8));
	colorComboBox->setMinimumSize(QSize(60, 0));
	connect(colorComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeColorSettings(int)));
	hboxLayoutFontsColorsLine3->addWidget(colorComboBox);
	hboxLayoutFontsColorsLine3->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	
	vboxLayoutFontsColorsGrouptBox->setSpacing(6);
	vboxLayoutFontsColorsGrouptBox->setMargin(9);
	vboxLayoutFontsColorsGrouptBox->addLayout(hboxLayoutFontsColorsLine1);
	vboxLayoutFontsColorsGrouptBox->addLayout(hboxLayoutFontsColorsLine2);
	vboxLayoutFontsColorsGrouptBox->addLayout(hboxLayoutFontsColorsLine3);
	fontsColorsGroupBox->setLayout(vboxLayoutFontsColorsGrouptBox);
	
	//----------------------------------------------------
	
	vboxLayoutEditorMain->setSpacing(6);
	vboxLayoutEditorMain->setMargin(9);
	vboxLayoutEditorMain->addLayout(hboxLayoutGeneral);
	vboxLayoutEditorMain->addWidget(fontsColorsGroupBox);
	vboxLayoutEditorMain->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
	editorTab->setLayout(vboxLayoutEditorMain);
	
	//####################################################
	
	vboxLayoutCompilerMain = new QVBoxLayout;
	vboxLayoutCompilerTab = new QVBoxLayout;
	vboxLayoutCompilerTab->setSpacing(6);
	vboxLayoutCompilerTab->setMargin(0);
	hboxLayoutCompilerTabLine1 = new QHBoxLayout;
	hboxLayoutCompilerTabLine1->setSpacing(6);
	hboxLayoutCompilerTabLine1->setMargin(0);
	hboxLayoutCompilerTabLine2 = new QHBoxLayout;
	hboxLayoutCompilerTabLine2->setSpacing(6);
	hboxLayoutCompilerTabLine2->setMargin(0);
	hboxLayoutCompilerTabLine3 = new QHBoxLayout;
	hboxLayoutCompilerTabLine3->setSpacing(6);
	hboxLayoutCompilerTabLine3->setMargin(0);
	
	//----------------------------------------------------
	
	hboxLayoutCompilerTabLine1->addWidget(new QLabel(tr("Target Platform")));
	platformComboBox = new QComboBox();
	platformComboBox->addItem(QApplication::translate("SettingsDialog", "Windows 32", 0, QApplication::UnicodeUTF8));
	platformComboBox->addItem(QApplication::translate("SettingsDialog", "Linux x86", 0, QApplication::UnicodeUTF8));
	hboxLayoutCompilerTabLine1->addWidget(platformComboBox);
	hboxLayoutCompilerTabLine1->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	
	hboxLayoutCompilerTabLine2->addWidget(new QLabel(tr("Optimisation Level")));
	optimisationComboBox = new QComboBox();
	optimisationComboBox->addItem(QApplication::translate("SettingsDialog", "Level 1", 0, QApplication::UnicodeUTF8));
	optimisationComboBox->addItem(QApplication::translate("SettingsDialog", "Level 2", 0, QApplication::UnicodeUTF8));
	optimisationComboBox->addItem(QApplication::translate("SettingsDialog", "Level 3", 0, QApplication::UnicodeUTF8));
	hboxLayoutCompilerTabLine2->addWidget(optimisationComboBox);
	hboxLayoutCompilerTabLine2->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	
	hboxLayoutCompilerTabLine3->addWidget(new QLabel(tr("Workspace")));
	workspaceLineEdit = new QLineEdit();
	hboxLayoutCompilerTabLine3->addWidget(workspaceLineEdit);
	
	warningsCheckBox = new QCheckBox(tr("Show warnings"));
	
	//----------------------------------------------------
	
	vboxLayoutCompilerTab->addLayout(hboxLayoutCompilerTabLine1);
	vboxLayoutCompilerTab->addLayout(hboxLayoutCompilerTabLine2);
	vboxLayoutCompilerTab->addLayout(hboxLayoutCompilerTabLine3);
	vboxLayoutCompilerTab->addWidget(warningsCheckBox);
	vboxLayoutCompilerMain->setSpacing(6);
	vboxLayoutCompilerMain->setMargin(9);
	vboxLayoutCompilerMain->addLayout(vboxLayoutCompilerTab);
	vboxLayoutCompilerMain->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
	compilerTab->setLayout(vboxLayoutCompilerMain);
	
	//####################################################
	
	fileGroupBox = new QGroupBox(tr("File"));
	gridLayoutFileGroupBox = new QGridLayout;
	editGroupBox = new QGroupBox(tr("Edit"));
	gridLayoutEditGroupBox = new QGridLayout;
	compileGroupBox = new QGroupBox(tr("Compile"));
	gridLayoutCompileGroupBox = new QGridLayout;
	debugGroupBox = new QGroupBox(tr("Debug"));
	gridLayoutDebugGroupBox = new QGridLayout;
	helpGroupBox = new QGroupBox(tr("Help"));
	gridLayoutHelpGroupBox = new QGridLayout;
	vboxLayoutShortcutsLeft = new QVBoxLayout;
	
	//----------------------------------------------------
	
	fileGroupBox->setGeometry(QRect(10, 0, 95, 160));
	fileGroupBox->setMinimumSize(QSize(95, 160));
	fileGroupBox->setMaximumSize(QSize(95, 160));
	gridLayoutFileGroupBox->setSpacing(6);
	gridLayoutFileGroupBox->setMargin(9);
	gridLayoutFileGroupBox->addWidget(new QLabel(tr("New")), 0, 0, 1, 1);
	newLineEdit = new QLineEdit;
	newLineEdit->setMinimumSize(QSize(40, 20));
	newLineEdit->setMaximumSize(QSize(40, 20));
	connect(newLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutFileGroupBox->addWidget(newLineEdit, 0, 1, 1, 1);
	gridLayoutFileGroupBox->addWidget(new QLabel(tr("Open")), 1, 0, 1, 1);
	openLineEdit = new QLineEdit;
	openLineEdit->setMinimumSize(QSize(40, 20));
	openLineEdit->setMaximumSize(QSize(40, 20));
	connect(openLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutFileGroupBox->addWidget(openLineEdit, 1, 1, 1, 1);
	gridLayoutFileGroupBox->addWidget(new QLabel(tr("Save")), 2, 0, 1, 1);
	saveLineEdit = new QLineEdit;
	saveLineEdit->setMinimumSize(QSize(40, 20));
	saveLineEdit->setMaximumSize(QSize(40, 20));
	connect(saveLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutFileGroupBox->addWidget(saveLineEdit, 2, 1, 1, 1);
	gridLayoutFileGroupBox->addWidget(new QLabel(tr("Print")), 3, 0, 1, 1);
	printLineEdit = new QLineEdit;
	printLineEdit->setMinimumSize(QSize(40, 20));
	printLineEdit->setMaximumSize(QSize(40, 20));
	connect(printLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutFileGroupBox->addWidget(printLineEdit, 3, 1, 1, 1);
	gridLayoutFileGroupBox->addWidget(new QLabel(tr("Close")), 4, 0, 1, 1);
	closeLineEdit = new QLineEdit;
	closeLineEdit->setMinimumSize(QSize(40, 20));
	closeLineEdit->setMaximumSize(QSize(40, 20));
	connect(closeLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutFileGroupBox->addWidget(closeLineEdit, 4, 1, 1, 1);
	
	fileGroupBox->setLayout(gridLayoutFileGroupBox);
	
	//----------------------------------------------------
	
	editGroupBox->setGeometry(QRect(120, 0, 101, 212));
 	editGroupBox->setMinimumSize(QSize(101, 212));
	editGroupBox->setMaximumSize(QSize(101, 212));
	gridLayoutEditGroupBox->setSpacing(6);
	gridLayoutEditGroupBox->setMargin(9);
	gridLayoutEditGroupBox->addWidget(new QLabel(tr("Undo")), 0, 0, 1, 1);
	undoLineEdit = new QLineEdit;
	undoLineEdit->setMinimumSize(QSize(40, 20));
	undoLineEdit->setMaximumSize(QSize(40, 20));
	connect(undoLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutEditGroupBox->addWidget(undoLineEdit, 0, 1, 1, 1);
	gridLayoutEditGroupBox->addWidget(new QLabel(tr("Redo")), 1, 0, 1, 1);
	redoLineEdit = new QLineEdit;
	redoLineEdit->setMinimumSize(QSize(40, 20));
	redoLineEdit->setMaximumSize(QSize(40, 20));
	connect(redoLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutEditGroupBox->addWidget(redoLineEdit, 1, 1, 1, 1);
	gridLayoutEditGroupBox->addWidget(new QLabel(tr("Cut")), 2, 0, 1, 1);
	cutLineEdit = new QLineEdit;
	cutLineEdit->setMinimumSize(QSize(40, 20));
	cutLineEdit->setMaximumSize(QSize(40, 20));
	connect(cutLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutEditGroupBox->addWidget(cutLineEdit, 2, 1, 1, 1);
	gridLayoutEditGroupBox->addWidget(new QLabel(tr("Copy")), 3, 0, 1, 1);
	copyLineEdit = new QLineEdit;
	copyLineEdit->setMinimumSize(QSize(40, 20));
	copyLineEdit->setMaximumSize(QSize(40, 20));
	connect(copyLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutEditGroupBox->addWidget(copyLineEdit, 3, 1, 1, 1);
	gridLayoutEditGroupBox->addWidget(new QLabel(tr("Paste")), 4, 0, 1, 1);
	pasteLineEdit = new QLineEdit;
	pasteLineEdit->setMinimumSize(QSize(40, 20));
	pasteLineEdit->setMaximumSize(QSize(40, 20));
	connect(pasteLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutEditGroupBox->addWidget(pasteLineEdit, 4, 1, 1, 1);
	gridLayoutEditGroupBox->addWidget(new QLabel(tr("Select")), 5, 0, 1, 1);
	selectLineEdit = new QLineEdit;
	selectLineEdit->setMinimumSize(QSize(40, 20));
	selectLineEdit->setMaximumSize(QSize(40, 20));
	connect(selectLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutEditGroupBox->addWidget(selectLineEdit, 5, 1, 1, 1);
	gridLayoutEditGroupBox->addWidget(new QLabel(tr("Find")), 6, 0, 1, 1);
	findLineEdit = new QLineEdit;
	findLineEdit->setMinimumSize(QSize(40, 20));
	findLineEdit->setMaximumSize(QSize(40, 20));
	connect(findLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutEditGroupBox->addWidget(findLineEdit, 6, 1, 1, 1);
	
	editGroupBox->setLayout(gridLayoutEditGroupBox);
	
	//----------------------------------------------------
	
	compileGroupBox->setMinimumSize(QSize(141, 82));
	compileGroupBox->setMaximumSize(QSize(141, 82));
	gridLayoutCompileGroupBox->setSpacing(6);
	gridLayoutCompileGroupBox->setMargin(9);
	gridLayoutCompileGroupBox->addWidget(new QLabel(tr("Undo")), 0, 0, 1, 1);
	compUndoLineEdit = new QLineEdit;
	compUndoLineEdit->setMinimumSize(QSize(40, 20));
	compUndoLineEdit->setMaximumSize(QSize(40, 20));
	connect(compUndoLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutCompileGroupBox->addWidget(compUndoLineEdit, 0, 1, 1, 1);
	gridLayoutCompileGroupBox->addWidget(new QLabel(tr("Interpret")), 1, 0, 1, 1);
	interpretLineEdit = new QLineEdit;
	interpretLineEdit->setMinimumSize(QSize(40, 20));
	interpretLineEdit->setMaximumSize(QSize(40, 20));
	connect(interpretLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutCompileGroupBox->addWidget(interpretLineEdit, 1, 1, 1, 1);
	
	compileGroupBox->setLayout(gridLayoutCompileGroupBox);
	
	debugGroupBox->setMinimumSize(QSize(141, 82));
	debugGroupBox->setMaximumSize(QSize(141, 82));
	gridLayoutDebugGroupBox->setSpacing(6);
	gridLayoutDebugGroupBox->setMargin(9);
	gridLayoutDebugGroupBox->addWidget(new QLabel(tr("Start")), 0, 0, 1, 1);
	startLineEdit = new QLineEdit;
	startLineEdit->setMinimumSize(QSize(40, 20));
	startLineEdit->setMaximumSize(QSize(40, 20));
	connect(startLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutDebugGroupBox->addWidget(startLineEdit, 0, 1, 1, 1);
	gridLayoutDebugGroupBox->addWidget(new QLabel(tr("Next Step")), 1, 0, 1, 1);
	nextStepLineEdit = new QLineEdit;
	nextStepLineEdit->setMinimumSize(QSize(40, 20));
	nextStepLineEdit->setMaximumSize(QSize(40, 20));
	connect(nextStepLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutDebugGroupBox->addWidget(nextStepLineEdit, 1, 1, 1, 1);
	
	debugGroupBox->setLayout(gridLayoutDebugGroupBox);
	
	helpGroupBox->setMinimumSize(QSize(141, 56));
	helpGroupBox->setMaximumSize(QSize(141, 56));
	gridLayoutHelpGroupBox->setSpacing(6);
	gridLayoutHelpGroupBox->setMargin(9);
	gridLayoutHelpGroupBox->addWidget(new QLabel(tr("BFS Handbook")), 0, 0, 1, 1);
	handbookLineEdit = new QLineEdit;
	handbookLineEdit->setMinimumSize(QSize(40, 20));
	handbookLineEdit->setMaximumSize(QSize(40, 20));
	connect(handbookLineEdit, SIGNAL(editingFinished()), this, SLOT(checkShortcut()));
	gridLayoutHelpGroupBox->addWidget(handbookLineEdit, 0, 1, 1, 1);
	
	helpGroupBox->setLayout(gridLayoutHelpGroupBox);
	
	vboxLayoutShortcutsLeft->setGeometry(QRect(240, 0, 143, 234));
	vboxLayoutShortcutsLeft->setSpacing(6);
	vboxLayoutShortcutsLeft->setMargin(0);
	vboxLayoutShortcutsLeft->addWidget(compileGroupBox);
	vboxLayoutShortcutsLeft->addWidget(debugGroupBox);
	vboxLayoutShortcutsLeft->addWidget(helpGroupBox);
	
	//----------------------------------------------------
	
	hboxLayoutShortcutsMain = new QHBoxLayout;
	hboxLayoutShortcutsMain->setSpacing(6);
	hboxLayoutShortcutsMain->setMargin(9);
	vboxLayoutFileHelp = new QVBoxLayout;
	vboxLayoutEditHelp = new QVBoxLayout;
	vboxLayoutLeftHelp = new QVBoxLayout;
	vboxLayoutFileHelp->addWidget(fileGroupBox);
	vboxLayoutFileHelp->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
	vboxLayoutEditHelp->addWidget(editGroupBox);
	vboxLayoutEditHelp->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
	vboxLayoutLeftHelp->addLayout(vboxLayoutShortcutsLeft);
	vboxLayoutLeftHelp->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
	hboxLayoutShortcutsMain->addLayout(vboxLayoutFileHelp);
	hboxLayoutShortcutsMain->addLayout(vboxLayoutEditHelp);
	hboxLayoutShortcutsMain->addLayout(vboxLayoutLeftHelp);
	shortcutsTab->setLayout(hboxLayoutShortcutsMain);
	
	//####################################################
	
	tabWidget->addTab(editorTab, tr("Editor"));
	tabWidget->addTab(compilerTab, tr("Compiler"));
	tabWidget->addTab(shortcutsTab, tr("Shortcuts"));
	
	okButton = new QPushButton(tr("OK"));
	cancelButton = new QPushButton(tr("Cancel"));
	
	connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
	connect(okButton, SIGNAL(clicked()), this, SLOT(writeSettings()));
	
	hboxLayoutButtons = new QHBoxLayout;
	hboxLayoutButtons->addStretch(1);
	hboxLayoutButtons->addWidget(okButton);
	hboxLayoutButtons->addWidget(cancelButton);
	
	vboxLayoutMain = new QVBoxLayout;
	vboxLayoutMain->setSpacing(6);
	vboxLayoutMain->setMargin(9);
	vboxLayoutMain->addWidget(tabWidget);
	vboxLayoutMain->addLayout(hboxLayoutButtons);
	setLayout(vboxLayoutMain);
	
	settings = new QSettings("BFS Team", "Brainfuck Studio");
	readSettings();
	
	setWindowTitle(tr("Settings"));
}

void SettingsDialog::readSettings()
{
	if(settings->value("showLineNumbers").toInt() == 2)
		lineNumbersCheckBox->setCheckState(Qt::Checked);
	if(settings->value("syntaxHighlighting").toInt() == 2)
		syntaxHighlightingCheckBox->setCheckState(Qt::Checked);
	endOfLineComboBox->setCurrentIndex(settings->value("endOfLine").toInt());
	encodingComboBox->setCurrentIndex(settings->value("encoding").toInt());
	
	tempSettings[0][0] = settings->value(">/font").toInt();
	tempSettings[0][1] = settings->value(">/style").toInt();
	tempSettings[0][2] = settings->value(">/size").toInt();
	tempSettings[0][3] = settings->value(">/color").toInt();

	tempSettings[1][0] = settings->value("</font").toInt();
	tempSettings[1][1] = settings->value("</style").toInt();
	tempSettings[1][2] = settings->value("</size").toInt();
	tempSettings[1][3] = settings->value("</color").toInt();

	tempSettings[2][0] = settings->value("+/font").toInt();
	tempSettings[2][1] = settings->value("+/style").toInt();
	tempSettings[2][2] = settings->value("+/size").toInt();
	tempSettings[2][3] = settings->value("+/color").toInt();

	tempSettings[3][0] = settings->value("-/font").toInt();
	tempSettings[3][1] = settings->value("-/style").toInt();
	tempSettings[3][2] = settings->value("-/size").toInt();
	tempSettings[3][3] = settings->value("-/color").toInt();

	tempSettings[4][0] = settings->value("./font").toInt();
	tempSettings[4][1] = settings->value("./style").toInt();
	tempSettings[4][2] = settings->value("./size").toInt();
	tempSettings[4][3] = settings->value("./color").toInt();

	tempSettings[5][0] = settings->value(",/font").toInt();
	tempSettings[5][1] = settings->value(",/style").toInt();
	tempSettings[5][2] = settings->value(",/size").toInt();
	tempSettings[5][3] = settings->value(",/color").toInt();

	tempSettings[6][0] = settings->value("[/font").toInt();
	tempSettings[6][1] = settings->value("[/style").toInt();
	tempSettings[6][2] = settings->value("[/size").toInt();
	tempSettings[6][3] = settings->value("[/color").toInt();

	tempSettings[7][0] = settings->value("]/font").toInt();
	tempSettings[7][1] = settings->value("]/style").toInt();
	tempSettings[7][2] = settings->value("]/size").toInt();
	tempSettings[7][3] = settings->value("]/color").toInt();
	
	readCharacterSettings(0);
	
	platformComboBox->setCurrentIndex(settings->value("platform").toInt());
	optimisationComboBox->setCurrentIndex(settings->value("optimisation").toInt());
	workspaceLineEdit->setText(settings->value("workspace").toString());
	if(settings->value("showWarnings").toInt() == 2)
		warningsCheckBox->setCheckState(Qt::Checked);
}

void SettingsDialog::writeSettings()
{
	settings->setValue("showLineNumbers", lineNumbersCheckBox->checkState());
	settings->setValue("syntaxHighlighting", syntaxHighlightingCheckBox->checkState());
	settings->setValue("endOfLine", endOfLineComboBox->currentIndex());
	settings->setValue("encoding", encodingComboBox->currentIndex());
	
	settings->setValue(">/font", tempSettings[0][0]);
	settings->setValue(">/style", tempSettings[0][1]);
	settings->setValue(">/size", tempSettings[0][2]);
	settings->setValue(">/color", tempSettings[0][3]);
	
	settings->setValue("</font", tempSettings[1][0]);
	settings->setValue("</style", tempSettings[1][1]);
	settings->setValue("</size", tempSettings[1][2]);
	settings->setValue("</color", tempSettings[1][3]);

	settings->setValue("+/font", tempSettings[2][0]);
	settings->setValue("+/style", tempSettings[2][1]);
	settings->setValue("+/size", tempSettings[2][2]);
	settings->setValue("+/color", tempSettings[2][3]);

	settings->setValue("-/font", tempSettings[3][0]);
	settings->setValue("-/style", tempSettings[3][1]);
	settings->setValue("-/size", tempSettings[3][2]);
	settings->setValue("-/color", tempSettings[3][3]);

	settings->setValue("./font", tempSettings[4][0]);
	settings->setValue("./style", tempSettings[4][1]);
	settings->setValue("./size", tempSettings[4][2]);
	settings->setValue("./color", tempSettings[4][3]);

	settings->setValue(",/font", tempSettings[5][0]);
	settings->setValue(",/style", tempSettings[5][1]);
	settings->setValue(",/size", tempSettings[5][2]);
	settings->setValue(",/color", tempSettings[5][3]);

	settings->setValue("[/font", tempSettings[6][0]);
	settings->setValue("[/style", tempSettings[6][1]);
	settings->setValue("[/size", tempSettings[6][2]);
	settings->setValue("[/color", tempSettings[6][3]);

	settings->setValue("]/font", tempSettings[7][0]);
	settings->setValue("]/style", tempSettings[7][1]);
	settings->setValue("]/size", tempSettings[7][2]);
	settings->setValue("]/color", tempSettings[7][3]);

	settings->setValue("platform", platformComboBox->currentIndex());
	settings->setValue("optimisation", optimisationComboBox->currentIndex());
	
	QDir *d = new QDir();
	d->setPath(workspaceLineEdit->text());
	if(!d->exists())
	{
		if(!d->mkdir(workspaceLineEdit->text()))
		{
			QMessageBox::warning(this, "Brainfuck Studio",
				"\""+workspaceLineEdit->text()+"\" is not writeable.\n"
				"Workspace remains \""+settings->value("workspace").toString()+"\".\n\n",
				"OK"
			);
		}
		else
		{
			settings->setValue("workspace", workspaceLineEdit->text());
		}
	}
	else
	{
		settings->setValue("workspace", workspaceLineEdit->text());
	}
	
	settings->setValue("showWarnings", warningsCheckBox->checkState());
	settings->sync();
}

void SettingsDialog::readCharacterSettings(int index)
{
	fontComboBox->setCurrentIndex(tempSettings[index][0]);
	styleComboBox->setCurrentIndex(tempSettings[index][1]);
	sizeComboBox->setCurrentIndex(tempSettings[index][2]);
	colorComboBox->setCurrentIndex(tempSettings[index][3]);
}

void SettingsDialog::changeFontSettings(int index)
{
	tempSettings[characterComboBox->currentIndex()][0] = index;
}

void SettingsDialog::changeStyleSettings(int index)
{
	tempSettings[characterComboBox->currentIndex()][1] = index;
}

void SettingsDialog::changeSizeSettings(int index)
{
	tempSettings[characterComboBox->currentIndex()][2] = index;
}

void SettingsDialog::changeColorSettings(int index)
{
	tempSettings[characterComboBox->currentIndex()][3] = index;
}

void SettingsDialog::checkShortcut()
{
	QObject* sender = const_cast<QObject*>(QObject::sender());
	actLineEdit = (QLineEdit*)sender;
	actLineEdit->clear();
}
