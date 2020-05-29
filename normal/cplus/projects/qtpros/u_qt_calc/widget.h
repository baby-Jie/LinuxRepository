#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void normalBtnClicked();

    void on_cPb_clicked();

    void on_backPb_clicked();

    void on_equalPb_clicked();

private:
    Ui::Widget *ui;

private:
    double calcResultBySuffix(QStringList); // 通过后缀表达式计算结果
    bool checkMidExpressionLegal(QString,  QStringList*); // 检验表达式是否合法
    QStringList expressionConvertMiddle2Suffix(QStringList*); // 将中缀表达式转换成后缀表达式

    QStringList clearMarkStack(QStack<QString>&); // 清空运算符栈空间
    QStringList clearBracketMarkStack(QStack<QString>&); // 清空栈空间中括号内容

    int compareSymbol(QString leftItem, QString rightItem);
};
#endif // WIDGET_H
