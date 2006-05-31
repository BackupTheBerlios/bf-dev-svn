#include <QtGui>

#include "mainwindow.h"
#include "mdichild.h"
#include "finddialog.h"

MainWindow::MainWindow()
{
    centralWidget = new QWidget(this);
    QVBoxLayout *vboxLayoutMain = new QVBoxLayout(centralWidget);
    
    workspace = new QWorkspace;
    createDesign();
    
    vboxLayoutMain->addWidget(workspace);
    vboxLayoutMain->addWidget(widgetDevel);

    setCentralWidget(centralWidget);
    
    connect(workspace, SIGNAL(windowActivated(QWidget *)),
            this, SLOT(updateMenus()));
    windowMapper = new QSignalMapper(this);
    connect(windowMapper, SIGNAL(mapped(QWidget *)),
            workspace, SLOT(setActiveWindow(QWidget *)));
    
    settings = new QSettings("BFS Team", "Brainfuck Studio");
    readSettings();
    
    if(settings->value("recentFileList").isNull())
	settings->setValue("recentFileList", QStringList());
    
    createActions();
    createMenus();
    createToolBars();
    createStatusBar();
    updateMenus();

    setWindowTitle(tr("Brainfuck Studio"));
    setWindowIcon(QIcon(QString::fromUtf8("icons/bfs.png")));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    workspace->closeAllWindows();
    if (activeMdiChild()) {
        event->ignore();
    } else {
        writeSettings();
        event->accept();
    }
}

void MainWindow::newFile()
{
    MdiChild *child = createMdiChild();
    child->newFile();
    child->show();
}

void MainWindow::openRecentFile()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
	open(action->data().toString());
}

void MainWindow::closeAllOthers()
{
    MdiChild *activeChild = activeMdiChild();
    
    foreach (QWidget *window, workspace->windowList()) {
        if(window != activeChild)
        {
            workspace->setActiveWindow(window);
            workspace->closeActiveWindow();
        }
    }

    workspace->setActiveWindow(activeChild);
}

void MainWindow::open(QString fileName)
{
    if (fileName.isEmpty())
    fileName = QFileDialog::getOpenFileName(this, "Open",
					    ".", "Brainfuck Files (*.b);;All Files (*)");
    if (!fileName.isEmpty()) {
        MdiChild *existing = findMdiChild(fileName);
        if (existing) {
            workspace->setActiveWindow(existing);
            return;
        }

        MdiChild *child = createMdiChild();
        if (child->loadFile(fileName)) {
	    setCurrentFile(fileName);
            statusBar()->showMessage(tr("File loaded"), 2000);
            child->show();
        } else {
            child->close();
        }
    }
}

void MainWindow::save()
{
    if (activeMdiChild()->save())
        statusBar()->showMessage(tr("File saved"), 2000);
}

void MainWindow::saveAs()
{
    if (activeMdiChild()->saveAs())
        statusBar()->showMessage(tr("File saved"), 2000);
}

void MainWindow::saveAll()
{
    MdiChild *activeChild = activeMdiChild();
    
    foreach (QWidget *window, workspace->windowList())
    {
	workspace->setActiveWindow(window);
	save();
    }
    
    workspace->setActiveWindow(activeChild);
}

void MainWindow::find()
{
    findDialog = new FindDialog(this);
    findDialog->exec();
}

void MainWindow::findText()
{
    activeMdiChild()->document()->find(findDialog->getSearchFor(), activeMdiChild()->textCursor(),
				       findDialog->getFindCaseSens() == 2 ? 								      
				       QTextDocument::FindCaseSensitively :
				       (QFlags<QTextDocument::FindFlag>) 0 |
				       findDialog->getFindWholeWords() == 2 ? 
				       QTextDocument::FindWholeWords : 
				       (QFlags<QTextDocument::FindFlag>) 0 |
				       findDialog->getFindBackwards() == 2 ?
				       QTextDocument::FindBackward : 
				       (QFlags<QTextDocument::FindFlag>) 0);
}

void MainWindow::cut()
{
    activeMdiChild()->cut();
}

void MainWindow::copy()
{
    activeMdiChild()->copy();
}

void MainWindow::paste()
{
    activeMdiChild()->paste();
}

void MainWindow::undo()
{
    activeMdiChild()->document()->undo();
}

void MainWindow::redo()
{
    activeMdiChild()->document()->redo();
}

void MainWindow::print()
{
    QTextDocument *document = activeMdiChild()->document();
    QPrinter printer;

    QPrintDialog *dlg = new QPrintDialog(&printer, this);
    if (dlg->exec() != QDialog::Accepted)
	return;

    document->print(&printer);

    statusBar()->showMessage(tr("Ready"), 2000);
}


void MainWindow::selectAll()
{
    activeMdiChild()->selectAll();
}

void MainWindow::deselect()
{
    QTextCursor *textCursor = new QTextCursor(activeMdiChild()->document());
    activeMdiChild()->setTextCursor(*textCursor);
}

void MainWindow::overwriteMode()
{
    static bool overwrite = false;
    
    overwrite = !overwrite;
    activeMdiChild()->setOverwriteMode(overwrite);
    if(overwrite)
	statusBar()->showMessage(tr("Overwrite Mode ON"), 2000);
    else
	statusBar()->showMessage(tr("Overwrite Mode OFF"), 2000);
}

void MainWindow::aboutBfs()
{
    QMessageBox *aboutBfs = new QMessageBox();

    aboutBfs->QMessageBox::about(this, "About Brainfuck Studio",
                                "Brainfuck Studio is a graphical development environment for coding brainfuck.\n\n"
                                "Copyright 2006 BF-dev\n\n"
                                "The whole application is under GPL\n\n"
                                "For technical support, see http://bf-dev.berlios.de/\n");
}

void MainWindow::updateRecentFileActions()
{
    QStringList files = settings->value("recentFileList").toStringList();

    int numRecentFiles = qMin(files.size(), (int)maxRecentFiles);

    for (int i = 0; i < numRecentFiles; ++i) {
	QString text = tr("&%1 %2").arg(i + 1).arg(strippedName(files[i]));
	actionRecentFiles[i]->setText(text);
	actionRecentFiles[i]->setData(files[i]);
	actionRecentFiles[i]->setVisible(true);
    }
    for (int j = numRecentFiles; j < maxRecentFiles; ++j)
	actionRecentFiles[j]->setVisible(false);
}

QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

void MainWindow::updateMenus()
{
    bool hasMdiChild = (activeMdiChild() != 0);
    actionStartDebug->setEnabled(hasMdiChild);
    actionStopDebug->setEnabled(hasMdiChild);
    actionSelectAll->setEnabled(hasMdiChild);
    actionDeselect->setEnabled(hasMdiChild);
    actionOverwriteMode->setEnabled(hasMdiChild);
    actionFind->setEnabled(hasMdiChild);
    actionFindNext->setEnabled(hasMdiChild);
    actionFindPrevious->setEnabled(hasMdiChild);
    actionClose->setEnabled(hasMdiChild);
    actionNextStep->setEnabled(hasMdiChild);
    actionPreviousStep->setEnabled(hasMdiChild);
    actionSave->setEnabled(hasMdiChild);
    actionSaveAs->setEnabled(hasMdiChild);
    actionPrint->setEnabled(hasMdiChild);
    actionUndo->setEnabled(hasMdiChild);
    actionRedo->setEnabled(hasMdiChild);
    actionPaste->setEnabled(hasMdiChild);
    actionCompile->setEnabled(hasMdiChild);
    actionTile->setEnabled(hasMdiChild);
    actionCascade->setEnabled(hasMdiChild);
    actionArrange->setEnabled(hasMdiChild);
    actionNextWindow->setEnabled(hasMdiChild);
    actionPreviousWindow->setEnabled(hasMdiChild);
    actionSaveAll->setEnabled(hasMdiChild);
    actionCloseAll->setEnabled(hasMdiChild);
    actionCloseAllOthers->setEnabled(hasMdiChild);
    actionSeparator->setVisible(hasMdiChild);


    bool hasSelection = (activeMdiChild() &&
                            activeMdiChild()->textCursor().hasSelection());
    
    actionCut->setEnabled(hasSelection);
    actionCopy->setEnabled(hasSelection);
}

void MainWindow::updateWindowMenu()
{
    menuWindow->clear();
    menuWindow->addAction(actionClose);
    menuWindow->addAction(actionCloseAll);
    menuWindow->addAction(actionCloseAllOthers);
    menuWindow->addSeparator();
    menuWindow->addAction(actionTile);
    menuWindow->addAction(actionCascade);
    menuWindow->addAction(actionArrange);
    menuWindow->addSeparator();
    menuWindow->addAction(actionNextWindow);
    menuWindow->addAction(actionPreviousWindow);
    menuWindow->addAction(actionSeparator);

    QList<QWidget *> windows = workspace->windowList();
    actionSeparator->setVisible(!windows.isEmpty());

    for (int i = 0; i < windows.size(); ++i)
    {
        MdiChild *child = qobject_cast<MdiChild *>(windows.at(i));

        QString text;
        if (i < 9)
        {
            text = tr("&%1 %2").arg(i + 1)
                                .arg(child->userFriendlyCurrentFile());
        } else
        {
            text = tr("%1 %2").arg(i + 1)
                                .arg(child->userFriendlyCurrentFile());
        }
        QAction *action  = menuWindow->addAction(text);
        action->setCheckable(true);
        action->setChecked(child == activeMdiChild());
        connect(action, SIGNAL(triggered()), windowMapper, SLOT(map()));
        windowMapper->setMapping(action, child);
    }
}

MdiChild *MainWindow::createMdiChild()
{
    MdiChild *child = new MdiChild;
    workspace->addWindow(child);

    connect(child, SIGNAL(copyAvailable(bool)),
            actionCut, SLOT(setEnabled(bool)));
    connect(child, SIGNAL(copyAvailable(bool)),
            actionCopy, SLOT(setEnabled(bool)));

    return child;
}

void MainWindow::createActions()
{
    actionBfsHandbook = new QAction(QIcon(QString::fromUtf8("icons/handbook.png")), tr("BFS &Handbook"), this);
    connect(actionBfsHandbook, SIGNAL(triggered()), this, SLOT(bfsHandbook()));

    actionAboutBfs = new QAction(tr("About &Brainfuck Studio"), this);
    connect(actionAboutBfs, SIGNAL(triggered()), this, SLOT(aboutBfs()));

    actionStartDebug = new QAction(QIcon(QString::fromUtf8("icons/debug.png")), tr("&Debug"), this);
    connect(actionStartDebug, SIGNAL(triggered()), this, SLOT(startDebug()));

    actionStopDebug = new QAction(tr("&Stop Debugging"), this);
    connect(actionStopDebug, SIGNAL(triggered()), this, SLOT(stopDebug()));

    actionSelectAll = new QAction(QIcon(QString::fromUtf8("icons/select-all.png")), tr("Select &All"), this);
    connect(actionSelectAll, SIGNAL(triggered()), this, SLOT(selectAll()));

    actionDeselect = new QAction(tr("&Deselect"), this);
    connect(actionDeselect, SIGNAL(triggered()), this, SLOT(deselect()));

    actionOverwriteMode = new QAction(tr("&Overwrite Mode"), this);
    actionOverwriteMode->setCheckable(true);
    connect(actionOverwriteMode, SIGNAL(triggered()), this, SLOT(overwriteMode()));

    actionFind = new QAction(tr("&Find"), this);
    connect(actionFind, SIGNAL(triggered()), this, SLOT(find()));
    //connect(actionFind, SIGNAL(triggered()), this, SLOT(findText(tr("Moser"), 0, 0, 0)));

    actionFindNext = new QAction(tr("&Find Next"), this);
    connect(actionFindNext, SIGNAL(triggered()), this, SLOT(findNext()));

    actionFindPrevious = new QAction(tr("&Find Previous"), this);
    connect(actionFindPrevious, SIGNAL(triggered()), this, SLOT(findPrevious()));
    
    for (int i = 0; i < maxRecentFiles; ++i)
    {
	actionRecentFiles[i] = new QAction(this);
	actionRecentFiles[i]->setVisible(false);
	connect(actionRecentFiles[i], SIGNAL(triggered()),
		this, SLOT(openRecentFile()));
    }
    updateRecentFileActions();

    actionSaveAll = new QAction(tr("Save A&ll"), this);
    connect(actionSaveAll, SIGNAL(triggered()), this, SLOT(saveAll()));

    actionCloseAll = new QAction(tr("Close A&ll"), this);
    connect(actionCloseAll, SIGNAL(triggered()), workspace, SLOT(closeAllWindows()));

    actionCloseAllOthers = new QAction(tr("Close All &Others"), this);
    connect(actionCloseAllOthers, SIGNAL(triggered()), this, SLOT(closeAllOthers()));

    actionExit = new QAction(QIcon(QString::fromUtf8("icons/exit.png")), tr("E&xit"), this);
    connect(actionExit, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    actionInterpretOnly = new QAction(tr("Interpret Onl&y"), this);
    actionInterpretOnly->setCheckable(true);
    connect(actionInterpretOnly, SIGNAL(triggered()), this, SLOT(interpretOnly()));

    actionOptimization = new QAction(tr("Optimi&zation"), this);
    actionOptimization->setCheckable(true);
    connect(actionOptimization, SIGNAL(triggered()), this, SLOT(optimization()));

    actionSettings = new QAction(tr("&Settings"), this);
    connect(actionSettings, SIGNAL(triggered()), this, SLOT(settings()));

    actionNextStep = new QAction(tr("&Next Step"), this);
    connect(actionNextStep, SIGNAL(triggered()), this, SLOT(nextStep()));

    actionPreviousStep = new QAction(tr("&Previous Step"), this);
    connect(actionPreviousStep, SIGNAL(triggered()), this, SLOT(previousStep()));

    actionNew = new QAction(QIcon(QString::fromUtf8("icons/new.png")), tr("&New"), this);
    connect(actionNew, SIGNAL(triggered()), this, SLOT(newFile()));

    actionOpen = new QAction(QIcon(QString::fromUtf8("icons/open.png")), tr("&Open"), this);
    connect(actionOpen, SIGNAL(triggered()), this, SLOT(open()));

    actionSave = new QAction(QIcon(QString::fromUtf8("icons/save.png")), tr("&Save"), this);
    connect(actionSave, SIGNAL(triggered()), this, SLOT(save()));

    actionSaveAs = new QAction(QIcon(QString::fromUtf8("icons/save-as.png")), tr("Save &As"), this);
    connect(actionSaveAs, SIGNAL(triggered()), this, SLOT(saveAs()));

    actionPrint = new QAction(QIcon(QString::fromUtf8("icons/print.png")), tr("&Print"), this);
    connect(actionPrint, SIGNAL(triggered()), this, SLOT(print()));

    actionClose = new QAction(QIcon(QString::fromUtf8("icons/close.png")), tr("&Close"), this);
    connect(actionClose, SIGNAL(triggered()), workspace, SLOT(closeActiveWindow()));

    actionUndo = new QAction(QIcon(QString::fromUtf8("icons/undo.png")), tr("&Undo"), this);
    connect(actionUndo, SIGNAL(triggered()), this, SLOT(undo()));

    actionRedo = new QAction(QIcon(QString::fromUtf8("icons/redo.png")), tr("&Redo"), this);
    connect(actionRedo, SIGNAL(triggered()), this, SLOT(redo()));

    actionCut = new QAction(QIcon(QString::fromUtf8("icons/cut.png")), tr("Cu&t"), this);
    connect(actionCut, SIGNAL(triggered()), this, SLOT(cut()));

    actionCopy = new QAction(QIcon(QString::fromUtf8("icons/copy.png")), tr("&Copy"), this);
    connect(actionCopy, SIGNAL(triggered()), this, SLOT(copy()));

    actionPaste = new QAction(QIcon(QString::fromUtf8("icons/paste.png")), tr("&Paste"), this);
    connect(actionPaste, SIGNAL(triggered()), this, SLOT(paste()));

    actionCompile = new QAction(QIcon(QString::fromUtf8("icons/compile.png")), tr("&Compile"), this);
    connect(actionCompile, SIGNAL(triggered()), this, SLOT(compile()));

    actionTile = new QAction(tr("&Tile"), this);
    connect(actionTile, SIGNAL(triggered()), workspace, SLOT(tile()));

    actionCascade = new QAction(tr("&Cascade"), this);
    connect(actionCascade, SIGNAL(triggered()), workspace, SLOT(cascade()));

    actionArrange = new QAction(tr("&Arrange"), this);
    connect(actionArrange, SIGNAL(triggered()), workspace, SLOT(arrangeIcons()));

    actionNextWindow = new QAction(tr("&Next Window"), this);
    connect(actionNextWindow, SIGNAL(triggered()), workspace, SLOT(activateNextWindow()));
    
    actionPreviousWindow = new QAction(tr("&Previous Window"), this);
    connect(actionPreviousWindow, SIGNAL(triggered()), workspace, SLOT(activatePreviousWindow()));

    actionSeparator = new QAction(this);
    actionSeparator->setSeparator(true);
}

void MainWindow::createMenus()
{
    menuFile = menuBar()->addMenu(tr("&File"));
    
    menuRecentFiles = menuFile->addMenu(tr("&Recent Files"));
    for (int i = 0; i < maxRecentFiles; ++i)
            menuRecentFiles->addAction(actionRecentFiles[i]);
    
    menuFile->addAction(actionOpen);
    menuFile->addSeparator();
    menuFile->addAction(actionSave);
    menuFile->addAction(actionSaveAs);
    menuFile->addAction(actionSaveAll);
    menuFile->addSeparator();
    menuFile->addAction(actionPrint);
    menuFile->addSeparator();
    menuFile->addAction(actionClose);
    menuFile->addAction(actionCloseAll);
    menuFile->addAction(actionCloseAllOthers);
    menuFile->addSeparator();
    menuFile->addAction(actionExit);

    menuEdit = menuBar()->addMenu(tr("&Edit"));
    menuEdit->addAction(actionUndo);
    menuEdit->addAction(actionRedo);
    menuEdit->addSeparator();
    menuEdit->addAction(actionCut);
    menuEdit->addAction(actionCopy);
    menuEdit->addAction(actionPaste);
    menuEdit->addSeparator();
    menuEdit->addAction(actionSelectAll);
    menuEdit->addAction(actionDeselect);
    menuEdit->addSeparator();
    menuEdit->addAction(actionOverwriteMode);
    menuEdit->addSeparator();
    menuEdit->addAction(actionFind);
    menuEdit->addAction(actionFindNext);
    menuEdit->addAction(actionFindPrevious);
    menuEdit->addSeparator();
    menuEdit->addAction(actionSettings);

    menuCompile = menuBar()->addMenu(tr("&Compile"));
    menuCompile->addAction(actionCompile);
    menuCompile->addAction(actionOptimization);
    
    menuCompile->addSeparator();
    menuCompile->addAction(actionInterpretOnly);    

    menuDebug = menuBar()->addMenu(tr("&Debug"));
    menuDebug->addAction(actionStartDebug);
    menuDebug->addAction(actionStopDebug);
    menuDebug->addSeparator();
    menuDebug->addSeparator();
    menuDebug->addAction(actionNextStep);
    menuDebug->addAction(actionPreviousStep);

    menuWindow = menuBar()->addMenu(tr("&Window"));
    connect(menuWindow, SIGNAL(aboutToShow()), this, SLOT(updateWindowMenu()));

    menuBar()->addSeparator();

    menuHelp = menuBar()->addMenu(tr("&Help"));
    menuHelp->addAction(actionBfsHandbook);
    menuHelp->addAction(actionAboutBfs);
}

void MainWindow::createToolBars()
{
    toolBarFile = addToolBar(tr("File"));
    toolBarFile->addAction(actionNew);
    toolBarFile->addAction(actionOpen);
    toolBarFile->addSeparator();
    toolBarFile->addAction(actionSave);
    toolBarFile->addAction(actionSaveAs);
    toolBarFile->addSeparator();
    toolBarFile->addAction(actionPrint);
    toolBarFile->addSeparator();
    toolBarFile->addAction(actionClose);
    toolBarFile->addSeparator();

    toolBarEdit = addToolBar(tr("Edit"));
    toolBarEdit->addAction(actionUndo);
    toolBarEdit->addAction(actionRedo);
    toolBarEdit->addAction(actionCut);
    toolBarEdit->addAction(actionCopy);
    toolBarEdit->addAction(actionPaste);
    toolBarEdit->addSeparator();

    toolBarExecute = addToolBar(tr("Execute"));
    toolBarExecute->addAction(actionCompile);
    toolBarExecute->addAction(actionStartDebug);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::createDesign()
{
    widgetDevel = new QWidget(centralWidget);
    QVBoxLayout *vboxLayoutDevel = new QVBoxLayout(widgetDevel);
    spacerItem = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    
    vboxLayoutDevel->addItem(spacerItem);

    tabWidgetDevel = new QTabWidget(widgetDevel);
    tabWidgetDevel->setMinimumSize(QSize(0,150));
    
    QWidget *tabCompiler = new QWidget();
    QVBoxLayout *vboxLayoutCompiler = new QVBoxLayout(tabCompiler);
    textEditCompiler = new QTextEdit(tabCompiler);
    textEditCompiler->setReadOnly(true);
    vboxLayoutCompiler->addWidget(textEditCompiler);
    
    tabWidgetDevel->addTab(tabCompiler, "&Compiler");
    
    QWidget *tabDebugger = new QWidget();
    QVBoxLayout *vboxLayoutDebugger = new QVBoxLayout(tabDebugger);
    textEditDebugger = new QTextEdit(tabDebugger);
    textEditDebugger->setReadOnly(true);
    vboxLayoutDebugger->addWidget(textEditDebugger);
    
    tabWidgetDevel->addTab(tabDebugger, "&Debugger");
    
    QWidget *tabInterpreter = new QWidget();
    QVBoxLayout *vboxLayoutInterpreter = new QVBoxLayout(tabInterpreter);
    textEditInterpreter = new QTextEdit(tabInterpreter);
    textEditInterpreter->setReadOnly(true);
    vboxLayoutInterpreter->addWidget(textEditInterpreter);
    
    tabWidgetDevel->addTab(tabInterpreter, "&Interpreter");

    tabWidgetDevel->setTabIcon(0, QIcon(QString::fromUtf8("icons/compile.png")));
    tabWidgetDevel->setTabIcon(1, QIcon(QString::fromUtf8("icons/debug.png")));
    tabWidgetDevel->setTabIcon(2, QIcon(QString::fromUtf8("icons/debug.png")));
    
    vboxLayoutDevel->addWidget(tabWidgetDevel);
}

void MainWindow::readSettings()
{
    QPoint pos = settings->value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings->value("size", QSize(400, 400)).toSize();
    move(pos);
    resize(size);
}

void MainWindow::writeSettings()
{
    settings->setValue("pos", pos());
    settings->setValue("size", size());
}

void MainWindow::setCurrentFile(const QString &fileName)
{
    QStringList files = settings->value("recentFileList").toStringList();
    files.removeAll(fileName);
    files.prepend(fileName);
    while (files.size() > maxRecentFiles)
	files.removeLast();
    
    settings->setValue("recentFileList", files);
    
    updateRecentFileActions();
}


MdiChild *MainWindow::activeMdiChild()
{
    return qobject_cast<MdiChild *>(workspace->activeWindow());
}

MdiChild *MainWindow::findMdiChild(const QString &fileName)
{
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

    foreach (QWidget *window, workspace->windowList()) {
        MdiChild *mdiChild = qobject_cast<MdiChild *>(window);
        if (mdiChild->currentFile() == canonicalFilePath)
            return mdiChild;
    }
    return 0;
}
