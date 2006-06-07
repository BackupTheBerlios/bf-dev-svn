#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MdiChild;
class FindDialog;
class QWorkspace;
class QSignalMapper;
class QSettings;
class QSpacerItem;
class QTextEdit;
class QTabWidget;
class SettingsDialog;
class Highlighter;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void newFile();
    void closeAllOthers();
    void open(QString fileName = tr(""));
    void openRecentFile();
    void save();
    void saveAs();
    void saveAll();
    void find();
    void findText();
    void cut();
    void copy();
    void paste();
    void undo();
    void redo();
    void print();
    void selectAll();
    void deselect();
    void overwriteMode();
    void aboutBfs();
    void showSettings();
    void updateMenus();
    void updateWindowMenu();
	void compile();
	void run();
    MdiChild *createMdiChild();

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void createDesign();
	void setShortcuts();
    void readSettings();
    void writeSettings();
    void updateRecentFileActions();
    void setCurrentFile(const QString &fileName);
	QString actualFilePath();
    QString strippedName(const QString &fullFileName);
    MdiChild *activeMdiChild();
    MdiChild *findMdiChild(const QString &fileName);

    enum { maxRecentFiles = 5 };
    
    FindDialog *findDialog;
    SettingsDialog *settingsDialog;
    Highlighter *highlighter;

    QWorkspace *workspace;
    
    QSignalMapper *windowMapper;
    
    QMenu *menuHelp;
    QMenu *menuWindow;
    QMenu *menuEdit;
    QMenu *menuFile;
    QMenu *menuDebug;
    QMenu *menuCompile;
    QMenu *menuRecentFiles;
    
    QStatusBar *statusbar;
    
    QToolBar *toolBarFile;
    QToolBar *toolBarEdit;
    QToolBar *toolBarExecute;
    
    QSettings *settings;
    
    QAction *actionBfsHandbook;
    QAction *actionAboutBfs;
    QAction *actionStartDebug;
    QAction *actionStopDebug;
    QAction *actionSelectAll;
    QAction *actionDeselect;
    QAction *actionOverwriteMode;
    QAction *actionFind;
    QAction *actionFindNext;
    QAction *actionFindPrevious;
    QAction *actionSaveAll;
    QAction *actionCloseAll;
    QAction *actionCloseAllOthers;
    QAction *actionExit;
    QAction *actionInterpretOnly;
    QAction *actionOptimization;
    QAction *actionSettings;
    QAction *actionNextStep;
    QAction *actionPreviousStep;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionPrint;
    QAction *actionClose;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCompile;
	QAction *actionRun;
    QAction *actionTile;
    QAction *actionCascade;
    QAction *actionArrange;
    QAction *actionNextWindow;
    QAction *actionPreviousWindow;
    QAction *actionSeparator;
    QAction *actionRecentFiles[maxRecentFiles];
    
    QWidget *centralWidget;
    QWidget *widgetDevel;
    
    QTextEdit *textEditCompiler;
    QTextEdit *textEditDebugger;
    QTextEdit *textEditInterpreter;
    
    QSpacerItem *spacerItem;
    
    QTabWidget *tabWidgetDevel;
};

#endif
