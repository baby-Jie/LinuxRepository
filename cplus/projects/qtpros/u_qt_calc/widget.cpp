#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QStack>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QObject::connect(this->ui->zeroPb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));
    QObject::connect(this->ui->onePb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));
    QObject::connect(this->ui->twoPb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));
    QObject::connect(this->ui->threePb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));
    QObject::connect(this->ui->fourPb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));
    QObject::connect(this->ui->fivePb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));
    QObject::connect(this->ui->sixPb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));
    QObject::connect(this->ui->sevenPb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));
    QObject::connect(this->ui->eightPb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));
    QObject::connect(this->ui->ninePb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));


    QObject::connect(this->ui->plusPb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));
    QObject::connect(this->ui->subtractPb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));
    QObject::connect(this->ui->multiplyPb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));
    QObject::connect(this->ui->divPb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));
    QObject::connect(this->ui->pointPb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));

    QObject::connect(this->ui->leftBracketPb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));
    QObject::connect(this->ui->rightBracketPb, SIGNAL(clicked()), this, SLOT(normalBtnClicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::normalBtnClicked()
{
    QObject* sender = QObject::sender();
    if (sender->metaObject()->className() == QStringLiteral("QPushButton"))
    {
        QPushButton* p = qobject_cast<QPushButton*>(sender);
        if (p != nullptr)
        {
            QString str = p->text();

            qDebug() << str;
            QString showText = ui->showLe->text();
            showText.append(str);
            ui->showLe->setText(showText);
        }
    }
}


void Widget::on_cPb_clicked()
{
    ui->showLe->clear();
}

void Widget::on_backPb_clicked()
{
    // ui->showLe->backspace(); // not match
    QString text = ui->showLe->text();
    int len = text.length();
    if (len > 0)
    {
        text.remove(len - 1, 1);
        ui->showLe->setText(text);
    }
}

void Widget::on_equalPb_clicked()
{
    try {
        QString midExpression = ui->showLe->text();
//        midExpression =  "6+(4+8)/2-9";

        QStringList midExpList;

        // 检查中缀表达式是否合法
        if (!checkMidExpressionLegal(midExpression, &midExpList))
        {
            QMessageBox::information(this, "title", "表达式不正确", QMessageBox::Yes);
        }
        qDebug() << midExpList;

        // 由中缀表达式转换成后缀表达式
        QStringList suffixList = expressionConvertMiddle2Suffix(&midExpList);

        qDebug() << suffixList;

        // 由后缀表达式计算结果
        double res = calcResultBySuffix(suffixList);

        // 显示计算得出的结果
        ui->showLe->setText( QString::number(res));
    }
    catch (...) {
        QMessageBox::information(this, "title", "表达式不正确", QMessageBox::Yes);
    }
}

// 通过后缀表达式计算结果
double Widget::calcResultBySuffix(QStringList suffixExpList)
{

    QStack<double> stack;
    QString str = "+-*/";

    int len = suffixExpList.length();
    for (int i = 0; i < len; i++)
    {
        QString item = suffixExpList.at(i);
        if (str.contains(item))
        {
            // 从栈中拿出两个数据来计算
            double num2 = stack.pop();
            double num1 = stack.pop();
            double ret = 0;
            if (item == "+")
            {
                ret = num1 + num2;
            }
            else if (item == "-")
            {
                ret = num1 - num2;
            }
            else if (item == "*")
            {
                ret = num1 * num2;
            }
            else if (item == "/")
            {
                ret = num1 / num2;
            }
            stack.push(ret);
        }
        else
        {
            bool isOk;
            double num = item.toDouble(&isOk);
            if (!isOk)
            {
                // throw Exception();
                qDebug() << "输入格式不正确";
                return 0;
            }
            stack.push(num);
        }
    }
    double result = stack.pop();
    return result;
}

// 检验中缀表达式是否合法 并且将它转换成中缀列表
bool Widget::checkMidExpressionLegal(QString midExpression, QStringList* midExpList)
{
    bool isLegal = true;
    int len = midExpression.length();
    if (len == 0)
    {
        return false;
    }

    if (midExpList == nullptr)
    {
        return false;
    }

    // 将表达式分割成列表
    QString temp = "0";
    for (int i = 0; i < len; i++)
    {
        QString str = "+-*/()";
        QChar ch = midExpression.at(i);
        if (str.contains(ch))
        {
            if (temp.length() > 0)
            {
                midExpList->append(temp);
            }

            midExpList->append(ch);
            temp.clear();
        }
        else
        {
            temp.append(ch);
        }
    }
    if (temp.length() > 0)
    {
        midExpList->append(temp);
        temp.clear();
    }

    // todo: 暂时先略过这一步
    return isLegal;
}

// 将中缀表达式转换成后缀表达式
QStringList Widget::expressionConvertMiddle2Suffix(QStringList* midExpList)
{

    // 用于存储运算符号 + - * / ()
    QStack<QString> symbolStack;

    QStringList suffixList;

    int len = midExpList->length();

    for (int i = 0; i < len; i++)
    {
        QString item = midExpList->at(i);
        bool isNum;
        item.toDouble(&isNum);
        if (isNum)
        {
            // 是数字 直接加到结果集中
            suffixList.append(item);
        }
        else
        {
            // 是运算符号
            // 第一个运算符，直接加进入
            if (symbolStack.isEmpty())
            {
                symbolStack.push(item);
            }
            else
            {
                // 非第一个运算符，要和前一个运算符相比较
                QString preItem = symbolStack.last();
                // 遇到右括号，优先级最高
                if (item == ")")
                {
                    QStringList l = clearBracketMarkStack(symbolStack);
                    suffixList.append(l);
                } else if (item == "(")
                {
                    // 遇到左括号，直接压栈
                    symbolStack.push(item);
                }
                else
                {
                    // 比较 item 和 preItem,
                    while (compareSymbol(preItem, item) >= 0)
                    {
                        suffixList.append(preItem);
                        symbolStack.pop();
                        if (symbolStack.isEmpty())
                        {
                            break;
                        }
                        preItem = symbolStack.last();
                    }

                    symbolStack.push(item);
                }
            }
        }
    }

    QStringList l = clearMarkStack(symbolStack);
    suffixList.append(l);

    return suffixList;
}

int Widget::compareSymbol(QString leftItem, QString rightItem)
{
    QString str = "+-*/()";
    QString str1 = "+-";
    QString str2 = "*/";
    if (!str.contains(leftItem) || !str.contains(rightItem)){
        throw "运算符不可用";
    }

    // 左括号在压栈前，优先级最大
    if (rightItem == "(")
    {
        return -1;
    } else if (leftItem == "(")
    {
        // 压栈后，左括号优先级最小
        return -1;
    }
    if (str1.contains(leftItem) && str1.contains(rightItem))
    {
        return 0;
    }
    if (str2.contains(leftItem) && str2.contains(rightItem))
    {
        return 0;
    }
    if (str1.contains(leftItem) && str2.contains(rightItem))
    {
        return -1;
    }
    if (str2.contains(leftItem) && str1.contains(rightItem))
    {
        return 1;
    }
    return 0;
}

// 清空运算符栈空间
QStringList Widget::clearMarkStack(QStack<QString>& stack)
{
    QStringList list;
    while (!stack.isEmpty())
    {
        QString item = stack.pop();
        if (item != "(" && item != ")")
        {
            list.append(item);
        }
    }
    return list;
}

// 清空栈空间中括号内容
QStringList Widget::clearBracketMarkStack(QStack<QString>& stack)
{
    QStringList list;
    bool findFlag = false;
    while (!stack.isEmpty())
    {
        QString item = stack.pop();
        if (item == ")")
        {
            throw "expression error";
        }
        if (item == "(")
        {
            findFlag = true;
            break;
        }
        else
        {
            list.append(item);
        }
    }

    if (!findFlag)
    {
        throw "括号不匹配";
    }

    return list;
}
