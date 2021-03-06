#include <QtGui>

#include "mdichild.h"

MdiChild::MdiChild()
{
    setAttribute(Qt::WA_DeleteOnClose);
    setUndoRedoEnabled(true);
    isUntitled = true;
	compiled = false;

    connect(document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));
}

void MdiChild::newFile()
{
    static int sequenceNumber = 1;

    isUntitled = true;
    curFile = tr("untitled%1.b").arg(sequenceNumber++);
    setWindowTitle(curFile + "[*]");
    showMaximized();
}

bool MdiChild::loadFile(const QString &fileName)
{
	settings = new QSettings("BFS Team", "Brainfuck Studio");
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Error"),
                                tr("Cannot read file %1:\n%2.")
                                .arg(fileName)
                                .arg(file.errorString()));
        return false;
    }

    QTextStream in(&file);
	if (settings->value("encoding") == 1)
		in.setCodec("ISO 8859-15");
	else
		in.setCodec("UTF-8");
    QApplication::setOverrideCursor(Qt::WaitCursor);
    setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    showMaximized();
    return true;
}

bool MdiChild::save()
{
    if (isUntitled) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool MdiChild::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                    curFile, "Brainfuck Files (*.b);;All Files (*)");
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

bool MdiChild::saveFile(const QString &fileName)
{
	settings = new QSettings("BFS Team", "Brainfuck Studio");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Error"),
                                tr("Cannot write file %1:\n%2.")
                                .arg(fileName)
                                .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
	if (settings->value("encoding") == 1)
		out.setCodec("ISO 8859-15");
	else
		out.setCodec("UTF-8");
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << toPlainText();
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    return true;
}

QString MdiChild::userFriendlyCurrentFile()
{
    return strippedName(curFile);
}

QString MdiChild::userFriendlyFileDir()
{
	return absoluteDirectory(curFile);
}

QString MdiChild::userFriendlyFileBaseName()
{
	return fileBaseName(curFile);
}

void MdiChild::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void MdiChild::documentWasModified()
{
    setWindowModified(document()->isModified());
}

bool MdiChild::maybeSave()
{
    if (document()->isModified()) {
        int ret = QMessageBox::warning(this, tr("Save Changes"),
                        tr("'%1' has been modified.\n"
                        "Do you want to save your changes?")
                        .arg(userFriendlyCurrentFile()),
                        QMessageBox::Yes | QMessageBox::Default,
                        QMessageBox::No,
                        QMessageBox::Cancel | QMessageBox::Escape);
        if (ret == QMessageBox::Yes)
            return save();
        else if (ret == QMessageBox::Cancel)
            return false;
    }
    return true;
}

void MdiChild::setCurrentFile(const QString &fileName)
{
    curFile = QFileInfo(fileName).canonicalFilePath();
    isUntitled = false;
    document()->setModified(false);
    setWindowModified(false);
    setWindowTitle(userFriendlyCurrentFile() + "[*]");
}

void MdiChild::setCompiled(const bool compiled)
{
	this->compiled = compiled;
}

bool MdiChild::isCompiled()
{
	return compiled;
}

QString MdiChild::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

QString MdiChild::absoluteDirectory(const QString &fullFileName)
{
	return QFileInfo(fullFileName).absoluteDir().absolutePath();
}

QString MdiChild::fileBaseName(const QString &fullFileName)
{
	return QFileInfo(fullFileName).baseName();
}
