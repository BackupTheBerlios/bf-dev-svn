#include <QtGui>

#include "highlighter.h"

Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
	int temp;
	settings = new QSettings("BFS Team", "Brainfuck Studio");
	
	if(settings->value("syntaxHighlighting") == Qt::Checked)
	{
		QTextCharFormat gt;
		
		temp = settings->value(">/font").toInt();
		setFont(gt, temp);
	
		temp = settings->value(">/style").toInt();
		setStyle(gt, temp);
	
		temp = settings->value(">/size").toInt();
		setSize(gt, temp);
	
		temp = settings->value(">/color").toInt();
		setColor(gt, temp);
	
		mappings[">"] = gt;
		
	
		QTextCharFormat lt;
		
		temp = settings->value("</font").toInt();
		setFont(lt, temp);
	
		temp = settings->value("</style").toInt();
		setStyle(lt, temp);
	
		temp = settings->value("</size").toInt();
		setSize(lt, temp);
	
		temp = settings->value("</color").toInt();
		setColor(lt, temp);
		
		mappings["<"] = lt;
		
		
		QTextCharFormat plus;
		
		temp = settings->value("+/font").toInt();
		setFont(plus, temp);
	
		temp = settings->value("+/style").toInt();
		setStyle(plus, temp);
	
		temp = settings->value("+/size").toInt();
		setSize(plus, temp);
	
		temp = settings->value("+/color").toInt();
		setColor(plus, temp);
		
		mappings["\\+"] = plus;
		
		
		QTextCharFormat minus;
		
		temp = settings->value("-/font").toInt();
		setFont(minus, temp);
	
		temp = settings->value("-/style").toInt();
		setStyle(minus, temp);
	
		temp = settings->value("-/size").toInt();
		setSize(minus, temp);
	
		temp = settings->value("-/color").toInt();
		setColor(minus, temp);
		
		mappings["\\-"] = minus;
		
		
		QTextCharFormat point;
		
		temp = settings->value("./font").toInt();
		setFont(point, temp);
	
		temp = settings->value("./style").toInt();
		setStyle(point, temp);
	
		temp = settings->value("./size").toInt();
		setSize(point, temp);
	
		temp = settings->value("./color").toInt();
		setColor(point, temp);
		
		mappings["\\."] = point;
		
		
		QTextCharFormat comma;
		
		temp = settings->value(",/font").toInt();
		setFont(comma, temp);
	
		temp = settings->value(",/style").toInt();
		setStyle(comma, temp);
	
		temp = settings->value(",/size").toInt();
		setSize(comma, temp);
	
		temp = settings->value(",/color").toInt();
		setColor(comma, temp);
		
		mappings["\\,"] = comma;
		
		
		QTextCharFormat openBracket;
		
		temp = settings->value("[/font").toInt();
		setFont(openBracket, temp);
	
		temp = settings->value("[/style").toInt();
		setStyle(openBracket, temp);
	
		temp = settings->value("[/size").toInt();
		setSize(openBracket, temp);
	
		temp = settings->value("[/color").toInt();
		setColor(openBracket, temp);
		
		mappings["\\["] = openBracket;
		
		
		QTextCharFormat closedBracket;
		
		temp = settings->value("]/font").toInt();
		setFont(closedBracket, temp);
	
		temp = settings->value("]/style").toInt();
		setStyle(closedBracket, temp);
	
		temp = settings->value("]/size").toInt();
		setSize(closedBracket, temp);
	
		temp = settings->value("]/color").toInt();
		setColor(closedBracket, temp);
		
		mappings["\\]"] = closedBracket;
    	
		
		QTextCharFormat comment;
		
		temp = settings->value("comment/font").toInt();
		setFont(comment, temp);
	
		temp = settings->value("comment/style").toInt();
		setStyle(comment, temp);
	
		temp = settings->value("comment/size").toInt();
		setSize(comment, temp);
	
		temp = settings->value("comment/color").toInt();
		setColor(comment, temp);
		
		mappings["[^><\\+\\-\\.\\,\\[\\]]"] = comment;
	}
}

void Highlighter::highlightBlock(const QString &text)
{
    foreach (QString pattern, mappings.keys()) {
        QRegExp expression(pattern);
        int index = text.indexOf(expression);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, mappings[pattern]);
            index = text.indexOf(expression, index + length);
        }
    }
}

void Highlighter::setFont(QTextCharFormat &c, int &v)
{
	if(v == 0)
		c.setFontFamily("Courier");
}

void Highlighter::setStyle(QTextCharFormat &c, int &v)
{
	if(v == 0)
	{
		c.setFontWeight(QFont::StyleNormal);
		c.setFontItalic(false);
	}
	else if(v == 1)
	{
		c.setFontWeight(QFont::Bold);
		c.setFontItalic(false);
	}
	else if(v == 2)
	{
		c.setFontWeight(QFont::StyleNormal);
		c.setFontItalic(true);
	}
	else
	{
		c.setFontWeight(QFont::Bold);
		c.setFontItalic(true);
	}
}

void Highlighter::setSize(QTextCharFormat &c, int &v)
{
	if(v == 0)
		c.setFontPointSize(10);
	else if(v == 1)
		c.setFontPointSize(11);
	else
		c.setFontPointSize(12);
}

void Highlighter::setColor(QTextCharFormat &c, int &v)
{
	if(v == 0)
		c.setForeground(Qt::black);
	else if(v == 1)
		c.setForeground(Qt::red);
	else if(v == 2)
		c.setForeground(Qt::yellow);
	else if(v == 3)
		c.setForeground(Qt::blue);
	else if(v == 4)
		c.setForeground(Qt::green);
	else
		c.setForeground(Qt::gray);
}
