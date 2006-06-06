#include <QtGui>

#include "highlighter.h"

Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    QTextCharFormat gt;
    gt.setForeground(Qt::red);
    gt.setFontWeight(QFont::Bold);
    mappings[">"] = gt;

    QTextCharFormat lt;
    lt.setForeground(Qt::green);
    lt.setFontWeight(QFont::Bold);
    mappings["<"] = lt;
    
    QTextCharFormat plus;
    plus.setForeground(Qt::blue);
    plus.setFontWeight(QFont::Bold);
    mappings["\\+"] = plus;
    
    QTextCharFormat minus;
    minus.setForeground(Qt::cyan);
    minus.setFontWeight(QFont::Bold);
    mappings["\\-"] = minus;
    
    QTextCharFormat point;
    point.setForeground(Qt::magenta);
    point.setFontWeight(QFont::Bold);
    mappings["\\."] = point;
    
    QTextCharFormat comma;
    comma.setForeground(Qt::yellow);
    comma.setFontWeight(QFont::Bold);
    mappings["\\,"] = comma;
    
    QTextCharFormat openBracket;
    openBracket.setForeground(Qt::black);
    openBracket.setFontWeight(QFont::Bold);
    mappings["\\["] = openBracket;
    
    QTextCharFormat closedBracket;
    closedBracket.setForeground(Qt::black);
    closedBracket.setFontWeight(QFont::Bold);
    mappings["\\]"] = closedBracket;
    
    QTextCharFormat comment;
    comment.setForeground(Qt::gray);
    comment.setFontWeight(QFont::Bold);
    mappings["[^><\\+\\-\\.\\,\\[\\]]"] = comment;
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
