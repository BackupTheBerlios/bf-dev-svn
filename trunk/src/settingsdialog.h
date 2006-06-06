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
#include <QFileInfo>
#include <QString>
#include <QTabWidget>

class EditorTab : public QWidget
{
	Q_OBJECT

	public:
		EditorTab(QWidget *parent = 0);
};

class CompilerTab : public QWidget
{
	Q_OBJECT

	public:
		CompilerTab(QWidget *parent = 0);
};

class ShortcutsTab : public QWidget
{
	Q_OBJECT

	public:
		ShortcutsTab(QWidget *parent = 0);
};

class SettingsDialog : public QDialog
{
	Q_OBJECT

	public:
		SettingsDialog(QWidget *parent = 0);
	
	private slots:
		void acceptSettings();
		void rejectSettings();
	
	private:
		QTabWidget *tabWidget;
};

#endif
