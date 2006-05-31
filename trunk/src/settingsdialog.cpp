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
	
	QHBoxLayout *buttonLayout = new QHBoxLayout;
	buttonLayout->addStretch(1);
	buttonLayout->addWidget(okButton);
	buttonLayout->addWidget(cancelButton);
	
	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->setSpacing(6);
	mainLayout->setMargin(9);
	mainLayout->addWidget(tabWidget);
	mainLayout->addLayout(buttonLayout);
	setLayout(mainLayout);
	
	setWindowTitle(tr("Settings"));
}

EditorTab::EditorTab(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout *mainLayout = new QVBoxLayout;
	QHBoxLayout *generalLayout = new QHBoxLayout;
	QVBoxLayout *generalLeftLayout = new QVBoxLayout;
	QGridLayout *generalRightLayout = new QGridLayout();
	
	//----------------------------------------------------
	
	
	
	QCheckBox *lineNumbersCheckBox = new QCheckBox(tr("Show line numbers"));
	QCheckBox *syntaxHighlightingCheckBox = new QCheckBox(tr("Syntax-Highlighting"));
	
	generalLeftLayout->setSpacing(6);
	generalLeftLayout->setMargin(0);
	generalLeftLayout->addWidget(lineNumbersCheckBox);
	generalLeftLayout->addWidget(syntaxHighlightingCheckBox);
	
	QComboBox *endOfLineComboBox = new QComboBox;
	QComboBox *encodingComboBox = new QComboBox;
	endOfLineComboBox->addItem(QApplication::translate("SettingsDialog", "Windows", 0, QApplication::UnicodeUTF8));
	endOfLineComboBox->addItem(QApplication::translate("SettingsDialog", "Unix", 0, QApplication::UnicodeUTF8));
	endOfLineComboBox->addItem(QApplication::translate("SettingsDialog", "Mac", 0, QApplication::UnicodeUTF8));
	encodingComboBox->addItem(QApplication::translate("SettingsDialog", "UTF-8", 0, QApplication::UnicodeUTF8));
	encodingComboBox->addItem(QApplication::translate("SettingsDialog", "ISO 8859-15", 0, QApplication::UnicodeUTF8));
	
	generalRightLayout->setSpacing(6);
	generalRightLayout->setMargin(0);
	generalRightLayout->addWidget(new QLabel(tr("End of line")), 0, 0, 1, 1);
	generalRightLayout->addWidget(new QLabel(tr("Encoding")), 1, 0, 1, 1);
	generalRightLayout->addWidget(endOfLineComboBox, 0, 1, 1, 1);
	generalRightLayout->addWidget(encodingComboBox, 1, 1, 1, 1);
	
	generalLayout->setSpacing(6);
	generalLayout->setMargin(0);
	generalLayout->addLayout(generalLeftLayout);
	generalLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	generalLayout->addLayout(generalRightLayout);
	
	//----------------------------------------------------
	
	QGroupBox *fontsColorsGroupBox = new QGroupBox(tr("Fonts and Colors"));
	QVBoxLayout *fontsColorsGroupBoxLayout = new QVBoxLayout;
	
	QHBoxLayout *fontsColorsLine1 = new QHBoxLayout;
	fontsColorsLine1->setSpacing(6);
	fontsColorsLine1->setMargin(0);
	QHBoxLayout *fontsColorsLine2 = new QHBoxLayout;
	fontsColorsLine2->setSpacing(6);
	fontsColorsLine2->setMargin(0);
	QHBoxLayout *fontsColorsLine3 = new QHBoxLayout;
	fontsColorsLine3->setSpacing(6);
	fontsColorsLine3->setMargin(0);
	
	fontsColorsLine1->addWidget(new QLabel(tr("Character")));
	QComboBox *characterComboBox = new QComboBox();
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "> (increment pointer)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "< (decrement pointer)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "+ (increment cell value)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "- (decrement cell value)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", ". (output cell value)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", ", (read cell value)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "[ (start loop)", 0, QApplication::UnicodeUTF8));
	characterComboBox->addItem(QApplication::translate("SettingsDialog", "] (end loop)", 0, QApplication::UnicodeUTF8));
	fontsColorsLine1->addWidget(characterComboBox);
	fontsColorsLine1->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	
	fontsColorsLine2->addWidget(new QLabel(tr("Font")));
	QComboBox *fontComboBox = new QComboBox;
	fontComboBox->addItem(QApplication::translate("SettingsDialog", "Courier New", 0, QApplication::UnicodeUTF8));
	fontComboBox->setMinimumSize(QSize(89, 0));
	fontsColorsLine2->addWidget(fontComboBox);
	fontsColorsLine2->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	fontsColorsLine2->addWidget(new QLabel(tr("Style")));
	QComboBox *styleComboBox = new QComboBox;
	styleComboBox->addItem(QApplication::translate("SettingsDialog", "Standard", 0, QApplication::UnicodeUTF8));
	styleComboBox->addItem(QApplication::translate("SettingsDialog", "fett", 0, QApplication::UnicodeUTF8));
	styleComboBox->addItem(QApplication::translate("SettingsDialog", "kursiv", 0, QApplication::UnicodeUTF8));
	styleComboBox->addItem(QApplication::translate("SettingsDialog", "fett kursiv", 0, QApplication::UnicodeUTF8));
	styleComboBox->setMinimumSize(QSize(80, 0));
	fontsColorsLine2->addWidget(styleComboBox);
	fontsColorsLine2->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	fontsColorsLine2->addWidget(new QLabel(tr("Size")));
	QComboBox *sizeComboBox = new QComboBox;
	sizeComboBox->addItem(QApplication::translate("SettingsDialog", "10", 0, QApplication::UnicodeUTF8));
	sizeComboBox->addItem(QApplication::translate("SettingsDialog", "11", 0, QApplication::UnicodeUTF8));
	sizeComboBox->addItem(QApplication::translate("SettingsDialog", "12", 0, QApplication::UnicodeUTF8));
	sizeComboBox->setMinimumSize(QSize(40, 0));
	fontsColorsLine2->addWidget(sizeComboBox);
	fontsColorsLine2->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	
	fontsColorsLine3->addWidget(new QLabel(tr("Color")));
	QComboBox *colorComboBox = new QComboBox();
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Black", 0, QApplication::UnicodeUTF8));
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Red", 0, QApplication::UnicodeUTF8));
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Yellow", 0, QApplication::UnicodeUTF8));
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Blue", 0, QApplication::UnicodeUTF8));
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Green", 0, QApplication::UnicodeUTF8));
	colorComboBox->addItem(QApplication::translate("SettingsDialog", "Grey", 0, QApplication::UnicodeUTF8));
	colorComboBox->setMinimumSize(QSize(60, 0));
	fontsColorsLine3->addWidget(colorComboBox);
	fontsColorsLine3->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	
	fontsColorsGroupBoxLayout->setSpacing(6);
	fontsColorsGroupBoxLayout->setMargin(9);
	fontsColorsGroupBoxLayout->addLayout(fontsColorsLine1);
	fontsColorsGroupBoxLayout->addLayout(fontsColorsLine2);
	fontsColorsGroupBoxLayout->addLayout(fontsColorsLine3);
	fontsColorsGroupBox->setLayout(fontsColorsGroupBoxLayout);
		
	//----------------------------------------------------
	
	mainLayout->setSpacing(6);
	mainLayout->setMargin(9);
	mainLayout->addLayout(generalLayout);
	mainLayout->addWidget(fontsColorsGroupBox);
	mainLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
	setLayout(mainLayout);
}

CompilerTab::CompilerTab(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout *mainLayout = new QVBoxLayout;
	QVBoxLayout *compilerTabLayout = new QVBoxLayout;
	compilerTabLayout->setSpacing(6);
	compilerTabLayout->setMargin(0);
	QHBoxLayout *compilerTabLine1 = new QHBoxLayout;
	compilerTabLine1->setSpacing(6);
	compilerTabLine1->setMargin(0);
	QHBoxLayout *compilerTabLine2 = new QHBoxLayout;
	compilerTabLine2->setSpacing(6);
	compilerTabLine2->setMargin(0);
	QHBoxLayout *compilerTabLine3 = new QHBoxLayout;
	compilerTabLine3->setSpacing(6);
	compilerTabLine3->setMargin(0);
	
	//----------------------------------------------------
	
	compilerTabLine1->addWidget(new QLabel(tr("Target Platform")));
	QComboBox *platformComboBox = new QComboBox();
	platformComboBox->addItem(QApplication::translate("SettingsDialog", "Windows 32", 0, QApplication::UnicodeUTF8));
	platformComboBox->addItem(QApplication::translate("SettingsDialog", "Linux x86", 0, QApplication::UnicodeUTF8));
	compilerTabLine1->addWidget(platformComboBox);
	compilerTabLine1->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	
	compilerTabLine2->addWidget(new QLabel(tr("Optimisation Level")));
	QComboBox *optimisationComboBox = new QComboBox();
	optimisationComboBox->addItem(QApplication::translate("SettingsDialog", "Level 1", 0, QApplication::UnicodeUTF8));
	optimisationComboBox->addItem(QApplication::translate("SettingsDialog", "Level 2", 0, QApplication::UnicodeUTF8));
	optimisationComboBox->addItem(QApplication::translate("SettingsDialog", "Level 3", 0, QApplication::UnicodeUTF8));
	compilerTabLine2->addWidget(optimisationComboBox);
	compilerTabLine2->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	
	compilerTabLine3->addWidget(new QLabel(tr("Target File")));
	QLineEdit *targetFileLineEdit = new QLineEdit();
	compilerTabLine3->addWidget(targetFileLineEdit);
	
	QCheckBox *warningsCheckBox = new QCheckBox(tr("Show warnings"));
	
	//----------------------------------------------------
	
	compilerTabLayout->addLayout(compilerTabLine1);
	compilerTabLayout->addLayout(compilerTabLine2);
	compilerTabLayout->addLayout(compilerTabLine3);
	compilerTabLayout->addWidget(warningsCheckBox);
	mainLayout->setSpacing(6);
	mainLayout->setMargin(9);
	mainLayout->addLayout(compilerTabLayout);
	mainLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
	setLayout(mainLayout);
}

ShortcutsTab::ShortcutsTab(QWidget *parent)
	: QWidget(parent)
{
	QGroupBox *fileGroupBox = new QGroupBox(tr("File"));
	QGridLayout *fileGroupBoxLayout = new QGridLayout;
	QGroupBox *editGroupBox = new QGroupBox(tr("Edit"));
	QGridLayout *editGroupBoxLayout = new QGridLayout;
	QGroupBox *compileGroupBox = new QGroupBox(tr("Compile"));
	QGridLayout *compileGroupBoxLayout = new QGridLayout;
	QGroupBox *debugGroupBox = new QGroupBox(tr("Debug"));
	QGridLayout *debugGroupBoxLayout = new QGridLayout;
	QGroupBox *helpGroupBox = new QGroupBox(tr("Help"));
	QGridLayout *helpGroupBoxLayout = new QGridLayout;
	QVBoxLayout *shortcutsLeftLayout = new QVBoxLayout;
	
	//----------------------------------------------------
	
	fileGroupBox->setGeometry(QRect(10, 0, 95, 160));
	fileGroupBox->setMinimumSize(QSize(95, 160));
	fileGroupBox->setMaximumSize(QSize(95, 160));
	fileGroupBoxLayout->setSpacing(6);
	fileGroupBoxLayout->setMargin(9);
	fileGroupBoxLayout->addWidget(new QLabel(tr("New")), 0, 0, 1, 1);
	QLineEdit *newLineEdit = new QLineEdit;
	newLineEdit->setMinimumSize(QSize(40, 20));
	newLineEdit->setMaximumSize(QSize(40, 20));
	fileGroupBoxLayout->addWidget(newLineEdit, 0, 1, 1, 1);
	fileGroupBoxLayout->addWidget(new QLabel(tr("Open")), 1, 0, 1, 1);
	QLineEdit *openLineEdit = new QLineEdit;
	openLineEdit->setMinimumSize(QSize(40, 20));
	openLineEdit->setMaximumSize(QSize(40, 20));
	fileGroupBoxLayout->addWidget(openLineEdit, 1, 1, 1, 1);
	fileGroupBoxLayout->addWidget(new QLabel(tr("Save")), 2, 0, 1, 1);
	QLineEdit *saveLineEdit = new QLineEdit;
	saveLineEdit->setMinimumSize(QSize(40, 20));
	saveLineEdit->setMaximumSize(QSize(40, 20));
	fileGroupBoxLayout->addWidget(saveLineEdit, 2, 1, 1, 1);
	fileGroupBoxLayout->addWidget(new QLabel(tr("Print")), 3, 0, 1, 1);
	QLineEdit *printLineEdit = new QLineEdit;
	printLineEdit->setMinimumSize(QSize(40, 20));
	printLineEdit->setMaximumSize(QSize(40, 20));
	fileGroupBoxLayout->addWidget(printLineEdit, 3, 1, 1, 1);
	fileGroupBoxLayout->addWidget(new QLabel(tr("Close")), 4, 0, 1, 1);
	QLineEdit *closeLineEdit = new QLineEdit;
	closeLineEdit->setMinimumSize(QSize(40, 20));
	closeLineEdit->setMaximumSize(QSize(40, 20));
	fileGroupBoxLayout->addWidget(closeLineEdit, 4, 1, 1, 1);
	
	fileGroupBox->setLayout(fileGroupBoxLayout);
	
	//----------------------------------------------------
	
	editGroupBox->setGeometry(QRect(120, 0, 101, 212));
	editGroupBox->setMinimumSize(QSize(101, 212));
	editGroupBox->setMaximumSize(QSize(101, 212));
	editGroupBoxLayout->setSpacing(6);
	editGroupBoxLayout->setMargin(9);
	editGroupBoxLayout->addWidget(new QLabel(tr("Undo")), 0, 0, 1, 1);
	QLineEdit *undoLineEdit = new QLineEdit;
	undoLineEdit->setMinimumSize(QSize(40, 20));
	undoLineEdit->setMaximumSize(QSize(40, 20));
	editGroupBoxLayout->addWidget(undoLineEdit, 0, 1, 1, 1);
	editGroupBoxLayout->addWidget(new QLabel(tr("Redo")), 1, 0, 1, 1);
	QLineEdit *redoLineEdit = new QLineEdit;
	redoLineEdit->setMinimumSize(QSize(40, 20));
	redoLineEdit->setMaximumSize(QSize(40, 20));
	editGroupBoxLayout->addWidget(redoLineEdit, 1, 1, 1, 1);
	editGroupBoxLayout->addWidget(new QLabel(tr("Cut")), 2, 0, 1, 1);
	QLineEdit *cutLineEdit = new QLineEdit;
	cutLineEdit->setMinimumSize(QSize(40, 20));
	cutLineEdit->setMaximumSize(QSize(40, 20));
	editGroupBoxLayout->addWidget(cutLineEdit, 2, 1, 1, 1);
	editGroupBoxLayout->addWidget(new QLabel(tr("Copy")), 3, 0, 1, 1);
	QLineEdit *copyLineEdit = new QLineEdit;
	copyLineEdit->setMinimumSize(QSize(40, 20));
	copyLineEdit->setMaximumSize(QSize(40, 20));
	editGroupBoxLayout->addWidget(copyLineEdit, 3, 1, 1, 1);
	editGroupBoxLayout->addWidget(new QLabel(tr("Paste")), 4, 0, 1, 1);
	QLineEdit *pasteLineEdit = new QLineEdit;
	pasteLineEdit->setMinimumSize(QSize(40, 20));
	pasteLineEdit->setMaximumSize(QSize(40, 20));
	editGroupBoxLayout->addWidget(pasteLineEdit, 4, 1, 1, 1);
	editGroupBoxLayout->addWidget(new QLabel(tr("Select")), 5, 0, 1, 1);
	QLineEdit *selectLineEdit = new QLineEdit;
	selectLineEdit->setMinimumSize(QSize(40, 20));
	selectLineEdit->setMaximumSize(QSize(40, 20));
	editGroupBoxLayout->addWidget(selectLineEdit, 5, 1, 1, 1);
	editGroupBoxLayout->addWidget(new QLabel(tr("Find")), 6, 0, 1, 1);
	QLineEdit *findLineEdit = new QLineEdit;
	findLineEdit->setMinimumSize(QSize(40, 20));
	findLineEdit->setMaximumSize(QSize(40, 20));
	editGroupBoxLayout->addWidget(findLineEdit, 6, 1, 1, 1);
	
	editGroupBox->setLayout(editGroupBoxLayout);
	
	//----------------------------------------------------
	
	compileGroupBox->setMinimumSize(QSize(141, 82));
	compileGroupBox->setMaximumSize(QSize(141, 82));
	compileGroupBoxLayout->setSpacing(6);
	compileGroupBoxLayout->setMargin(9);
	compileGroupBoxLayout->addWidget(new QLabel(tr("Undo")), 0, 0, 1, 1);
	QLineEdit *compUndoLineEdit = new QLineEdit;
	compUndoLineEdit->setMinimumSize(QSize(40, 20));
	compUndoLineEdit->setMaximumSize(QSize(40, 20));
	compileGroupBoxLayout->addWidget(compUndoLineEdit, 0, 1, 1, 1);
	compileGroupBoxLayout->addWidget(new QLabel(tr("Interpret")), 1, 0, 1, 1);
	QLineEdit *interpretLineEdit = new QLineEdit;
	interpretLineEdit->setMinimumSize(QSize(40, 20));
	interpretLineEdit->setMaximumSize(QSize(40, 20));
	compileGroupBoxLayout->addWidget(interpretLineEdit, 1, 1, 1, 1);
	
	compileGroupBox->setLayout(compileGroupBoxLayout);
	
	debugGroupBox->setMinimumSize(QSize(141, 82));
	debugGroupBox->setMaximumSize(QSize(141, 82));
	debugGroupBoxLayout->setSpacing(6);
	debugGroupBoxLayout->setMargin(9);
	debugGroupBoxLayout->addWidget(new QLabel(tr("Start")), 0, 0, 1, 1);
	QLineEdit *startLineEdit = new QLineEdit;
	startLineEdit->setMinimumSize(QSize(40, 20));
	startLineEdit->setMaximumSize(QSize(40, 20));
	debugGroupBoxLayout->addWidget(startLineEdit, 0, 1, 1, 1);
	debugGroupBoxLayout->addWidget(new QLabel(tr("Next Step")), 1, 0, 1, 1);
	QLineEdit *nextStepLineEdit = new QLineEdit;
	nextStepLineEdit->setMinimumSize(QSize(40, 20));
	nextStepLineEdit->setMaximumSize(QSize(40, 20));
	debugGroupBoxLayout->addWidget(nextStepLineEdit, 1, 1, 1, 1);
	
	debugGroupBox->setLayout(debugGroupBoxLayout);
	
	helpGroupBox->setMinimumSize(QSize(141, 56));
	helpGroupBox->setMaximumSize(QSize(141, 56));
	helpGroupBoxLayout->setSpacing(6);
	helpGroupBoxLayout->setMargin(9);
	helpGroupBoxLayout->addWidget(new QLabel(tr("BFS Handbook")), 0, 0, 1, 1);
	QLineEdit *handbookLineEdit = new QLineEdit;
	handbookLineEdit->setMinimumSize(QSize(40, 20));
	handbookLineEdit->setMaximumSize(QSize(40, 20));
	helpGroupBoxLayout->addWidget(handbookLineEdit, 0, 1, 1, 1);
	
	helpGroupBox->setLayout(helpGroupBoxLayout);
	
	shortcutsLeftLayout->setGeometry(QRect(240, 0, 143, 234));
	shortcutsLeftLayout->setSpacing(6);
	shortcutsLeftLayout->setMargin(0);
	shortcutsLeftLayout->addWidget(compileGroupBox);
	shortcutsLeftLayout->addWidget(debugGroupBox);
	shortcutsLeftLayout->addWidget(helpGroupBox);
	
	//----------------------------------------------------
	
	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->setSpacing(6);
	mainLayout->setMargin(9);
	mainLayout->addWidget(fileGroupBox);
	mainLayout->addWidget(editGroupBox);
	mainLayout->addLayout(shortcutsLeftLayout);
	setLayout(mainLayout);
}
