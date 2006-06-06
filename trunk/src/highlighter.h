#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>

#include <QHash>
#include <QTextCharFormat>

class QTextDocument;
class QSettings;

class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text);

private:
    QHash<QString,QTextCharFormat> mappings;
	void setFont(QTextCharFormat &c, int &v);
	void setStyle(QTextCharFormat &c, int &v);
	void setSize(QTextCharFormat &c, int &v);
	void setColor(QTextCharFormat &c, int &v);
	
	QSettings *settings;
};

#endif
