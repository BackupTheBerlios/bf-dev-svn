/*
 *      SettingsDialog.h
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

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

class QTabWidget;
class QWidget;
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QCheckBox;
class QComboBox;
class QGroupBox;
class QLineEdit;
class QPushButton;
class QSettings;

class SettingsDialog : public QDialog
{
	Q_OBJECT

	public:
		SettingsDialog(QWidget *parent = 0);
	
	private slots:
		void writeSettings();
		void readCharacterSettings(int);
		void changeFontSettings(int);
		void changeStyleSettings(int);
		void changeSizeSettings(int);
		void changeColorSettings(int);
		void checkShortcut();
	
	private:
		void readSettings();
		QTabWidget *tabWidget;
		QWidget *editorTab;
		QWidget *compilerTab;
		QWidget *shortcutsTab;
		QVBoxLayout *vboxLayoutEditorMain;
		QHBoxLayout *hboxLayoutGeneral;
		QVBoxLayout *vboxLayoutGeneralLeft;
		QGridLayout *gridLayoutGeneralRight;
		QCheckBox *lineNumbersCheckBox;
		QCheckBox *syntaxHighlightingCheckBox;
		QComboBox *endOfLineComboBox;
		QComboBox *encodingComboBox;
		QGroupBox *fontsColorsGroupBox;
		QVBoxLayout *vboxLayoutFontsColorsGrouptBox;
		QHBoxLayout *hboxLayoutFontsColorsLine1;
		QHBoxLayout *hboxLayoutFontsColorsLine2;
		QHBoxLayout *hboxLayoutFontsColorsLine3;
		QComboBox *characterComboBox;
		QComboBox *fontComboBox;
		QComboBox *styleComboBox;
		QComboBox *sizeComboBox;
		QComboBox *colorComboBox;
		QVBoxLayout *vboxLayoutCompilerMain;
		QVBoxLayout *vboxLayoutCompilerTab;
		QHBoxLayout *hboxLayoutCompilerTabLine1;
		QHBoxLayout *hboxLayoutCompilerTabLine2;
		QHBoxLayout *hboxLayoutCompilerTabLine3;
		QComboBox *platformComboBox;
		QComboBox *optimisationComboBox;
		QLineEdit *workspaceLineEdit;
		QCheckBox *warningsCheckBox;
		QGroupBox *fileGroupBox;
		QGridLayout *gridLayoutFileGroupBox;
		QGroupBox *editGroupBox;
		QGridLayout *gridLayoutEditGroupBox;
		QGroupBox *compileGroupBox;
		QGridLayout *gridLayoutCompileGroupBox;
		QGroupBox *debugGroupBox;
		QGridLayout *gridLayoutDebugGroupBox;
		QGroupBox *helpGroupBox;
		QGridLayout *gridLayoutHelpGroupBox;
		QVBoxLayout *vboxLayoutShortcutsLeft;
		QLineEdit *newLineEdit;
		QLineEdit *openLineEdit;
		QLineEdit *saveLineEdit;
		QLineEdit *printLineEdit;
		QLineEdit *closeLineEdit;
		QLineEdit *undoLineEdit;
		QLineEdit *redoLineEdit;
		QLineEdit *cutLineEdit;
		QLineEdit *copyLineEdit;
		QLineEdit *pasteLineEdit;
		QLineEdit *selectLineEdit;
		QLineEdit *findLineEdit;
		QLineEdit *compUndoLineEdit;
		QLineEdit *interpretLineEdit;
		QLineEdit *startLineEdit;
		QLineEdit *nextStepLineEdit;
		QLineEdit *handbookLineEdit;
		QVBoxLayout *vboxLayoutFileHelp;
		QVBoxLayout *vboxLayoutEditHelp;
		QVBoxLayout *vboxLayoutLeftHelp;
		QHBoxLayout *hboxLayoutShortcutsMain;
		QPushButton *okButton;
		QPushButton *cancelButton;
		QHBoxLayout *hboxLayoutButtons;
		QVBoxLayout *vboxLayoutMain;
		QSettings *settings;
		int tempSettings[8][4];
		QLineEdit *actLineEdit;
};

#endif
