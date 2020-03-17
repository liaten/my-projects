#ifndef NUMBERSORT_H
#define NUMBERSORT_H

#include <QMainWindow>
#include <QFile>
#include <QTime>
#include <QString>
QT_BEGIN_NAMESPACE
namespace Ui { class NumberSort; }
QT_END_NAMESPACE

class NumberSort : public QMainWindow
{
    Q_OBJECT

public:
    NumberSort(QWidget *parent = nullptr);
    ~NumberSort();

private slots:
    void on_SortArray_clicked();

    void on_CreatArray_clicked();

    void on_ShowCreatedArray_clicked();

    void on_ShowSortArray_clicked();

private:
    Ui::NumberSort *ui;
    int N;
    bool flag = false;
    void quickSort(QVector <int>& array, int left, int right);
    void NaturalSort(QVector <int>& array,int size);
    bool sheck_fucntion(QVector <int>& mess);
    void SortShortArray(QVector <int>& ar);
};
#endif // NUMBERSORT_H
