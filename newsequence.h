#ifndef NEWSEQUENCE_H
#define NEWSEQUENCE_H

#include <QDialog>
#include <QMap>

namespace Ui {
class NewSequence;
}

class NewSequence : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewSequence(QWidget *parent = 0);
    ~NewSequence();
    
private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::NewSequence *ui;
    QStringList fileList;
    QString name;
    QMap<QString, int> mapOrder;
};

#endif // NEWSEQUENCE_H
