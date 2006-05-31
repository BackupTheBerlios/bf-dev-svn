#ifndef MDICHILD_H
#define MDICHILD_H

#include <QTextEdit>

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
    QString currentFile() { return curFile; }
    void setCurrentFile(const QString &fileName);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void documentWasModified();

private:
    bool maybeSave();
    QString strippedName(const QString &fullFileName);

    QString curFile;
    bool isUntitled;
};

#endif
