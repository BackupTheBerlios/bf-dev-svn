#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_MainWindow
{
public:
    QAction *actionBrainfuck_Studio_Handbook;
    QAction *actionAbout_Brainfuck_Studio;
    QAction *actionStart;
    QAction *actionStop;
    QAction *actionInterrupt;
    QAction *actionRun_to_Cursor;
    QAction *actionSet_Execution_Position_to_Cursor;
    QAction *actionStep_over;
    QAction *actionStep_into;
    QAction *actionStep_out;
    QAction *actionToggle_Breakpoint;
    QAction *actionSelect_all;
    QAction *actionDeselect;
    QAction *actionOverwrite_Mode;
    QAction *actionFind;
    QAction *actionFind_Next;
    QAction *actionFind_Previous;
    QAction *actionOpen_Recent;
    QAction *actionSave_All;
    QAction *actionClose_All;
    QAction *actionClose_All_Others;
    QAction *actionExit;
    QAction *actionInterpret_Only;
    QAction *actionNo_Optimization;
    QAction *actionOptLevel_1;
    QAction *actionOptLevel_2;
    QAction *actionOptLevel_3;
    QAction *actionPreferences;
    QAction *actionNext_Step;
    QAction *actionPrevious_Step;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionPrint;
    QAction *actionClose;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCompile;
    QAction *actionDebug;
    QWidget *centralwidget;
    QVBoxLayout *vboxLayout;
    QTextEdit *code;
    QTabWidget *develTabWidget;
    QWidget *compilerTab;
    QVBoxLayout *vboxLayout1;
    QTextEdit *compiler;
    QWidget *debuggerTab;
    QVBoxLayout *vboxLayout2;
    QTableView *debugger;
    QWidget *interpreterTab;
    QVBoxLayout *vboxLayout3;
    QTextEdit *interpreter;
    QMenuBar *menubar;
    QMenu *menuHelp;
    QMenu *menuWindow;
    QMenu *menuEdit;
    QMenu *menuFile;
    QMenu *menuDebug;
    QMenu *menuRun;
    QMenu *menuOptimization;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
    MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(QSize(721, 573).expandedTo(MainWindow->minimumSizeHint()));
    actionBrainfuck_Studio_Handbook = new QAction(MainWindow);
    actionBrainfuck_Studio_Handbook->setObjectName(QString::fromUtf8("actionBrainfuck_Studio_Handbook"));
    actionBrainfuck_Studio_Handbook->setIcon(QIcon(QString::fromUtf8("icons/handbook.png")));
    actionAbout_Brainfuck_Studio = new QAction(MainWindow);
    actionAbout_Brainfuck_Studio->setObjectName(QString::fromUtf8("actionAbout_Brainfuck_Studio"));
    actionStart = new QAction(MainWindow);
    actionStart->setObjectName(QString::fromUtf8("actionStart"));
    actionStart->setIcon(QIcon(QString::fromUtf8("icons/debug.png")));
    actionStop = new QAction(MainWindow);
    actionStop->setObjectName(QString::fromUtf8("actionStop"));
    actionInterrupt = new QAction(MainWindow);
    actionInterrupt->setObjectName(QString::fromUtf8("actionInterrupt"));
    actionRun_to_Cursor = new QAction(MainWindow);
    actionRun_to_Cursor->setObjectName(QString::fromUtf8("actionRun_to_Cursor"));
    actionSet_Execution_Position_to_Cursor = new QAction(MainWindow);
    actionSet_Execution_Position_to_Cursor->setObjectName(QString::fromUtf8("actionSet_Execution_Position_to_Cursor"));
    actionStep_over = new QAction(MainWindow);
    actionStep_over->setObjectName(QString::fromUtf8("actionStep_over"));
    actionStep_into = new QAction(MainWindow);
    actionStep_into->setObjectName(QString::fromUtf8("actionStep_into"));
    actionStep_out = new QAction(MainWindow);
    actionStep_out->setObjectName(QString::fromUtf8("actionStep_out"));
    actionToggle_Breakpoint = new QAction(MainWindow);
    actionToggle_Breakpoint->setObjectName(QString::fromUtf8("actionToggle_Breakpoint"));
    actionSelect_all = new QAction(MainWindow);
    actionSelect_all->setObjectName(QString::fromUtf8("actionSelect_all"));
    actionSelect_all->setIcon(QIcon(QString::fromUtf8("icons/select-all.png")));
    actionDeselect = new QAction(MainWindow);
    actionDeselect->setObjectName(QString::fromUtf8("actionDeselect"));
    actionOverwrite_Mode = new QAction(MainWindow);
    actionOverwrite_Mode->setObjectName(QString::fromUtf8("actionOverwrite_Mode"));
    actionFind = new QAction(MainWindow);
    actionFind->setObjectName(QString::fromUtf8("actionFind"));
    actionFind->setIcon(QIcon(QString::fromUtf8("icons/find.png")));
    actionFind_Next = new QAction(MainWindow);
    actionFind_Next->setObjectName(QString::fromUtf8("actionFind_Next"));
    actionFind_Previous = new QAction(MainWindow);
    actionFind_Previous->setObjectName(QString::fromUtf8("actionFind_Previous"));
    actionOpen_Recent = new QAction(MainWindow);
    actionOpen_Recent->setObjectName(QString::fromUtf8("actionOpen_Recent"));
    actionSave_All = new QAction(MainWindow);
    actionSave_All->setObjectName(QString::fromUtf8("actionSave_All"));
    actionClose_All = new QAction(MainWindow);
    actionClose_All->setObjectName(QString::fromUtf8("actionClose_All"));
    actionClose_All_Others = new QAction(MainWindow);
    actionClose_All_Others->setObjectName(QString::fromUtf8("actionClose_All_Others"));
    actionExit = new QAction(MainWindow);
    actionExit->setObjectName(QString::fromUtf8("actionExit"));
    actionExit->setIcon(QIcon(QString::fromUtf8("icons/exit.png")));
    actionInterpret_Only = new QAction(MainWindow);
    actionInterpret_Only->setObjectName(QString::fromUtf8("actionInterpret_Only"));
    actionNo_Optimization = new QAction(MainWindow);
    actionNo_Optimization->setObjectName(QString::fromUtf8("actionNo_Optimization"));
    actionOptLevel_1 = new QAction(MainWindow);
    actionOptLevel_1->setObjectName(QString::fromUtf8("actionOptLevel_1"));
    actionOptLevel_2 = new QAction(MainWindow);
    actionOptLevel_2->setObjectName(QString::fromUtf8("actionOptLevel_2"));
    actionOptLevel_3 = new QAction(MainWindow);
    actionOptLevel_3->setObjectName(QString::fromUtf8("actionOptLevel_3"));
    actionPreferences = new QAction(MainWindow);
    actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
    actionPreferences->setIcon(QIcon(QString::fromUtf8("icons/settings.png")));
    actionNext_Step = new QAction(MainWindow);
    actionNext_Step->setObjectName(QString::fromUtf8("actionNext_Step"));
    actionPrevious_Step = new QAction(MainWindow);
    actionPrevious_Step->setObjectName(QString::fromUtf8("actionPrevious_Step"));
    actionNew = new QAction(MainWindow);
    actionNew->setObjectName(QString::fromUtf8("actionNew"));
    actionNew->setIcon(QIcon(QString::fromUtf8("icons/new.png")));
    actionOpen = new QAction(MainWindow);
    actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
    actionOpen->setIcon(QIcon(QString::fromUtf8("icons/open.png")));
    actionSave = new QAction(MainWindow);
    actionSave->setObjectName(QString::fromUtf8("actionSave"));
    actionSave->setIcon(QIcon(QString::fromUtf8("icons/save.png")));
    actionSave_As = new QAction(MainWindow);
    actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
    actionSave_As->setIcon(QIcon(QString::fromUtf8("icons/save-as.png")));
    actionPrint = new QAction(MainWindow);
    actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
    actionPrint->setIcon(QIcon(QString::fromUtf8("icons/print.png")));
    actionClose = new QAction(MainWindow);
    actionClose->setObjectName(QString::fromUtf8("actionClose"));
    actionClose->setIcon(QIcon(QString::fromUtf8("icons/close.png")));
    actionUndo = new QAction(MainWindow);
    actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
    actionUndo->setIcon(QIcon(QString::fromUtf8("icons/undo.png")));
    actionRedo = new QAction(MainWindow);
    actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
    actionRedo->setIcon(QIcon(QString::fromUtf8("icons/redo.png")));
    actionCut = new QAction(MainWindow);
    actionCut->setObjectName(QString::fromUtf8("actionCut"));
    actionCut->setIcon(QIcon(QString::fromUtf8("icons/cut.png")));
    actionCopy = new QAction(MainWindow);
    actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
    actionCopy->setIcon(QIcon(QString::fromUtf8("icons/copy.png")));
    actionPaste = new QAction(MainWindow);
    actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
    actionPaste->setIcon(QIcon(QString::fromUtf8("icons/paste.png")));
    actionCompile = new QAction(MainWindow);
    actionCompile->setObjectName(QString::fromUtf8("actionCompile"));
    actionCompile->setIcon(QIcon(QString::fromUtf8("icons/compile.png")));
    actionDebug = new QAction(MainWindow);
    actionDebug->setObjectName(QString::fromUtf8("actionDebug"));
    actionDebug->setIcon(QIcon(QString::fromUtf8("icons/debug.png")));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    vboxLayout = new QVBoxLayout(centralwidget);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(9);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    code = new QTextEdit(centralwidget);
    code->setObjectName(QString::fromUtf8("code"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(code->sizePolicy().hasHeightForWidth());
    code->setSizePolicy(sizePolicy);

    vboxLayout->addWidget(code);

    develTabWidget = new QTabWidget(centralwidget);
    develTabWidget->setObjectName(QString::fromUtf8("develTabWidget"));
    develTabWidget->setMinimumSize(QSize(0, 125));
    develTabWidget->setMaximumSize(QSize(16777215, 125));
    compilerTab = new QWidget();
    compilerTab->setObjectName(QString::fromUtf8("compilerTab"));
    vboxLayout1 = new QVBoxLayout(compilerTab);
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(9);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    compiler = new QTextEdit(compilerTab);
    compiler->setObjectName(QString::fromUtf8("compiler"));
    compiler->setReadOnly(true);

    vboxLayout1->addWidget(compiler);

    develTabWidget->addTab(compilerTab, QApplication::translate("MainWindow", "Compiler", 0, QApplication::UnicodeUTF8));
    debuggerTab = new QWidget();
    debuggerTab->setObjectName(QString::fromUtf8("debuggerTab"));
    vboxLayout2 = new QVBoxLayout(debuggerTab);
    vboxLayout2->setSpacing(6);
    vboxLayout2->setMargin(9);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    debugger = new QTableView(debuggerTab);
    debugger->setObjectName(QString::fromUtf8("debugger"));

    vboxLayout2->addWidget(debugger);

    develTabWidget->addTab(debuggerTab, QApplication::translate("MainWindow", "Debugger", 0, QApplication::UnicodeUTF8));
    interpreterTab = new QWidget();
    interpreterTab->setObjectName(QString::fromUtf8("interpreterTab"));
    vboxLayout3 = new QVBoxLayout(interpreterTab);
    vboxLayout3->setSpacing(6);
    vboxLayout3->setMargin(9);
    vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
    interpreter = new QTextEdit(interpreterTab);
    interpreter->setObjectName(QString::fromUtf8("interpreter"));
    interpreter->setReadOnly(true);

    vboxLayout3->addWidget(interpreter);

    develTabWidget->addTab(interpreterTab, QApplication::translate("MainWindow", "Interpreter", 0, QApplication::UnicodeUTF8));

    vboxLayout->addWidget(develTabWidget);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 721, 26));
    menuHelp = new QMenu(menubar);
    menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
    menuWindow = new QMenu(menubar);
    menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
    menuEdit = new QMenu(menubar);
    menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    menuDebug = new QMenu(menubar);
    menuDebug->setObjectName(QString::fromUtf8("menuDebug"));
    menuRun = new QMenu(menubar);
    menuRun->setObjectName(QString::fromUtf8("menuRun"));
    menuOptimization = new QMenu(menuRun);
    menuOptimization->setObjectName(QString::fromUtf8("menuOptimization"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    statusbar->setGeometry(QRect(0, 554, 721, 19));
    MainWindow->setStatusBar(statusbar);
    toolBar = new QToolBar(MainWindow);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    toolBar->setOrientation(Qt::Horizontal);
    MainWindow->addToolBar(static_cast<Qt::ToolBarArea>(4), toolBar);

    menubar->addAction(menuFile->menuAction());
    menubar->addAction(menuEdit->menuAction());
    menubar->addAction(menuRun->menuAction());
    menubar->addAction(menuDebug->menuAction());
    menubar->addAction(menuWindow->menuAction());
    menubar->addAction(menuHelp->menuAction());
    menuHelp->addAction(actionBrainfuck_Studio_Handbook);
    menuHelp->addAction(actionAbout_Brainfuck_Studio);
    menuEdit->addAction(actionUndo);
    menuEdit->addAction(actionRedo);
    menuEdit->addSeparator();
    menuEdit->addAction(actionCut);
    menuEdit->addAction(actionCopy);
    menuEdit->addAction(actionPaste);
    menuEdit->addSeparator();
    menuEdit->addAction(actionSelect_all);
    menuEdit->addAction(actionDeselect);
    menuEdit->addSeparator();
    menuEdit->addAction(actionOverwrite_Mode);
    menuEdit->addSeparator();
    menuEdit->addAction(actionFind);
    menuEdit->addAction(actionFind_Next);
    menuEdit->addAction(actionFind_Previous);
    menuEdit->addSeparator();
    menuEdit->addAction(actionPreferences);
    menuFile->addAction(actionOpen_Recent);
    menuFile->addSeparator();
    menuFile->addAction(actionSave);
    menuFile->addAction(actionSave_As);
    menuFile->addAction(actionSave_All);
    menuFile->addSeparator();
    menuFile->addAction(actionPrint);
    menuFile->addSeparator();
    menuFile->addAction(actionClose);
    menuFile->addAction(actionClose_All);
    menuFile->addAction(actionClose_All_Others);
    menuFile->addSeparator();
    menuFile->addAction(actionExit);
    menuDebug->addAction(actionStart);
    menuDebug->addAction(actionStop);
    menuDebug->addSeparator();
    menuDebug->addSeparator();
    menuDebug->addAction(actionNext_Step);
    menuDebug->addAction(actionPrevious_Step);
    menuRun->addAction(actionCompile);
    menuRun->addAction(menuOptimization->menuAction());
    menuRun->addSeparator();
    menuRun->addAction(actionInterpret_Only);
    menuOptimization->addAction(actionNo_Optimization);
    menuOptimization->addAction(actionOptLevel_1);
    menuOptimization->addAction(actionOptLevel_2);
    menuOptimization->addAction(actionOptLevel_3);
    toolBar->addAction(actionNew);
    toolBar->addAction(actionOpen);
    toolBar->addSeparator();
    toolBar->addAction(actionSave);
    toolBar->addAction(actionSave_As);
    toolBar->addSeparator();
    toolBar->addAction(actionPrint);
    toolBar->addSeparator();
    toolBar->addAction(actionClose);
    toolBar->addSeparator();
    toolBar->addAction(actionUndo);
    toolBar->addAction(actionRedo);
    toolBar->addAction(actionCut);
    toolBar->addAction(actionCopy);
    toolBar->addAction(actionPaste);
    toolBar->addSeparator();
    toolBar->addAction(actionCompile);
    toolBar->addAction(actionDebug);
    retranslateUi(MainWindow);

    develTabWidget->setCurrentIndex(1);


    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Brainfuck Studio", 0, QApplication::UnicodeUTF8));
    actionBrainfuck_Studio_Handbook->setText(QApplication::translate("MainWindow", "Brainfuck Studio Handbook", 0, QApplication::UnicodeUTF8));
    actionAbout_Brainfuck_Studio->setText(QApplication::translate("MainWindow", "About Brainfuck Studio", 0, QApplication::UnicodeUTF8));
    actionStart->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
    actionStop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
    actionInterrupt->setText(QApplication::translate("MainWindow", "Interrupt", 0, QApplication::UnicodeUTF8));
    actionRun_to_Cursor->setText(QApplication::translate("MainWindow", "Run to Cursor", 0, QApplication::UnicodeUTF8));
    actionSet_Execution_Position_to_Cursor->setText(QApplication::translate("MainWindow", "Set Execution Position to Cursor", 0, QApplication::UnicodeUTF8));
    actionStep_over->setText(QApplication::translate("MainWindow", "Step Over", 0, QApplication::UnicodeUTF8));
    actionStep_into->setText(QApplication::translate("MainWindow", "Step Into", 0, QApplication::UnicodeUTF8));
    actionStep_out->setText(QApplication::translate("MainWindow", "Step Out", 0, QApplication::UnicodeUTF8));
    actionToggle_Breakpoint->setText(QApplication::translate("MainWindow", "Toggle Breakpoint", 0, QApplication::UnicodeUTF8));
    actionSelect_all->setText(QApplication::translate("MainWindow", "Select all", 0, QApplication::UnicodeUTF8));
    actionDeselect->setText(QApplication::translate("MainWindow", "Deselect", 0, QApplication::UnicodeUTF8));
    actionOverwrite_Mode->setText(QApplication::translate("MainWindow", "Overwrite Mode", 0, QApplication::UnicodeUTF8));
    actionFind->setText(QApplication::translate("MainWindow", "Find", 0, QApplication::UnicodeUTF8));
    actionFind_Next->setText(QApplication::translate("MainWindow", "Find Next", 0, QApplication::UnicodeUTF8));
    actionFind_Previous->setText(QApplication::translate("MainWindow", "Find Previous", 0, QApplication::UnicodeUTF8));
    actionOpen_Recent->setText(QApplication::translate("MainWindow", "Open Recent", 0, QApplication::UnicodeUTF8));
    actionSave_All->setText(QApplication::translate("MainWindow", "Save All", 0, QApplication::UnicodeUTF8));
    actionClose_All->setText(QApplication::translate("MainWindow", "Close All", 0, QApplication::UnicodeUTF8));
    actionClose_All_Others->setText(QApplication::translate("MainWindow", "Close All Others", 0, QApplication::UnicodeUTF8));
    actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
    actionInterpret_Only->setText(QApplication::translate("MainWindow", "Interpret Only", 0, QApplication::UnicodeUTF8));
    actionInterpret_Only->setIconText(QApplication::translate("MainWindow", "Interpret Only", 0, QApplication::UnicodeUTF8));
    actionInterpret_Only->setToolTip(QApplication::translate("MainWindow", "Interpret Only", 0, QApplication::UnicodeUTF8));
    actionNo_Optimization->setText(QApplication::translate("MainWindow", "No Optimization", 0, QApplication::UnicodeUTF8));
    actionNo_Optimization->setIconText(QApplication::translate("MainWindow", "No Optimization", 0, QApplication::UnicodeUTF8));
    actionNo_Optimization->setToolTip(QApplication::translate("MainWindow", "No Optimization", 0, QApplication::UnicodeUTF8));
    actionOptLevel_1->setText(QApplication::translate("MainWindow", "Level 1", 0, QApplication::UnicodeUTF8));
    actionOptLevel_2->setText(QApplication::translate("MainWindow", "Level 2", 0, QApplication::UnicodeUTF8));
    actionOptLevel_3->setText(QApplication::translate("MainWindow", "Level 3", 0, QApplication::UnicodeUTF8));
    actionPreferences->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
    actionNext_Step->setText(QApplication::translate("MainWindow", "Next Step", 0, QApplication::UnicodeUTF8));
    actionPrevious_Step->setText(QApplication::translate("MainWindow", "Previous Step", 0, QApplication::UnicodeUTF8));
    actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
    actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
    actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
    actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", 0, QApplication::UnicodeUTF8));
    actionPrint->setText(QApplication::translate("MainWindow", "Print", 0, QApplication::UnicodeUTF8));
    actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
    actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0, QApplication::UnicodeUTF8));
    actionRedo->setText(QApplication::translate("MainWindow", "Redo", 0, QApplication::UnicodeUTF8));
    actionCut->setText(QApplication::translate("MainWindow", "Cut", 0, QApplication::UnicodeUTF8));
    actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0, QApplication::UnicodeUTF8));
    actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0, QApplication::UnicodeUTF8));
    actionCompile->setText(QApplication::translate("MainWindow", "Compile", 0, QApplication::UnicodeUTF8));
    actionDebug->setText(QApplication::translate("MainWindow", "Debug", 0, QApplication::UnicodeUTF8));
    develTabWidget->setTabText(develTabWidget->indexOf(compilerTab), QApplication::translate("MainWindow", "Compiler", 0, QApplication::UnicodeUTF8));
    develTabWidget->setTabText(develTabWidget->indexOf(debuggerTab), QApplication::translate("MainWindow", "Debugger", 0, QApplication::UnicodeUTF8));
    develTabWidget->setTabText(develTabWidget->indexOf(interpreterTab), QApplication::translate("MainWindow", "Interpreter", 0, QApplication::UnicodeUTF8));
    menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    menuWindow->setTitle(QApplication::translate("MainWindow", "Window", 0, QApplication::UnicodeUTF8));
    menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
    menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    menuDebug->setTitle(QApplication::translate("MainWindow", "Debug", 0, QApplication::UnicodeUTF8));
    menuRun->setTitle(QApplication::translate("MainWindow", "Compile", 0, QApplication::UnicodeUTF8));
    menuOptimization->setTitle(QApplication::translate("MainWindow", "Optimization", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

#endif // MAINWINDOW_H
