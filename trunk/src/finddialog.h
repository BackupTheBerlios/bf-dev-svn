#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

class QLineEdit;
class QCheckBox;


class FindDialog : public QDialog
{
    Q_OBJECT
    
public:
    FindDialog(QWidget *parent);
    QString getSearchFor();
    int getFindCaseSens();
    int getFindWholeWords();
    int getFindBackwards();

private:
    void createDesign();
    
    QWidget *parent;
    
    QLineEdit *lineEditSearchFor;
    
    QCheckBox *checkBoxFindCaseSens;
    QCheckBox *checkBoxFindWholeWords;
    QCheckBox *checkBoxFindBackwards;
    
    QPushButton *pushButtonFind;
    QPushButton *pushButtonClose;
};

#endif // FINDDIALOG_H
