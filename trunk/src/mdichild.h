#ifndef MDICHILD_H
#define MDICHILD_H

#include <QTextEdit>

class QSettings;

class MdiChild : public QTextEdit
{
    Q_OBJECT

public:
    MdiChild();

    void newFile();
    bool loadFile(const QString &fileName);
    bool save();
    bool saveAs();
    bool saveFile(const QString &fileName);
    QString userFriendlyCurrentFile();
	QString userFriendlyFileDir();
	QString userFriendlyFileBaseName();
    QString currentFile() { return curFile; }
    void setCurrentFile(const QString &fileName);
	bool isCompiled();
	
public slots:
	void setCompiled(const bool compiled);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void documentWasModified();

private:
    bool maybeSave();
    QString strippedName(const QString &fullFileName);
	QString absoluteDirectory(const QString &fileName);
	QString fileBaseName(const QString &fileName);

    QString curFile;
    bool isUntitled;
	QSettings *settings;
	bool compiled;
};

#endif
