#include "widget.h"
#include <QPainter>
#include <QPixmap>
#include <QPointF>
#include <QRect>
#include <cmath>
#include <QDebug>
#include <QPen>
#include <QPushButton>
#include <QTime>
#include <QPainterPath>
#include <QMouseEvent>
#include <QMessageBox>
using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    init();
}

Widget::~Widget()
{
}

void Widget::init()
{
    // 设置最小尺寸
    this->setMinimumSize(QSize(200, 200));

    // 设置一个label 显示 当前是哪一方turn
    turnLabel = new QLabel(this);
    turnLabel->setText("黑方");
    QFont font("楷体", 25);
    turnLabel->setFont(font);

    // 添加一个按钮 产生随机的棋子。
//    QPushButton* randomBtn = new QPushButton(this);
//    randomBtn->setText("random");
//    connect(randomBtn, &QPushButton::clicked, [=](){
//        // 点击随机按钮 产生的事件
//        qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
//        auto random_x = qrand() % 15;
//        auto random_y = qrand() % 15;

//        if (chess_turn == 1)
//        {
//             this->chess_flag[random_x][random_y] = 1;
//            chess_turn = 2;
//        }
//        else
//        {
//             this->chess_flag[random_x][random_y] = 2;
//            chess_turn = 1;
//        }
//        this->update();

//        qDebug() << "x:" << random_x << " y:" << random_y;
//    });
}

/**
 * @brief Widget::drawChess
 * @param painter
 * 绘画棋子
 */
void Widget::drawChess(QPainter* painter, int offsetX, int offsetY, int unitLength)
{
    if (painter == nullptr)
    {
        return;
    }
    int ratio = 3;

    // 遍历 chess_flag 如果是0 表示没有棋子落下，1表示黑色棋子落下 2表示白色棋子落下
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {

            // i 表示行 j表示列
            if (chess_flag[i][j] == 0)
            {
                // 没有棋子落在这
                continue;
            }
            else if (chess_flag[i][j] == 1 || chess_flag[i][j] == 2)
            {
                QPen pen;
                QBrush brush(Qt::black);
                QRect rect;
                QPainterPath path;
                if (chess_flag[i][j] == 2)
                {
                    // 白色棋子落在这
                    brush.setColor(Qt::white);
                }

                int x = offsetX + unitLength * j - unitLength / ratio;
                int y = offsetY + unitLength * i - unitLength / ratio;
                rect.setX(x);
                rect.setY(y);
                rect.setWidth(unitLength * 2 / ratio);
                rect.setHeight(unitLength * 2 / ratio);
                path.addEllipse(rect);
                painter->fillPath(path, brush);
            }
        }
    }
}

/**
 * @brief Widget::getChessRect
 * @param pUnitLength
 * @return
 * 获取棋盘的尺寸
 */
QRect Widget::getChessRect(int* pUnitLength)
{
    // 确定棋盘的长宽
    auto winWidth = this->width();
    auto winHeight = this->height();

    // 确定棋盘的边长为窗口长宽的最小值 - 60
    auto minLength = min(winWidth, winHeight) - 60;

    auto unitLength = minLength / 14.0;
    *pUnitLength = unitLength;
//        qDebug() << minLength;

    // 计算出偏移量 以便绘制在窗口的中心位置
    auto offsetX = (this->width() - minLength) / 2;
    auto offsetY = (this->height() - minLength) / 2;

    // 先画出边框
    QRect rect;
    rect.setTopLeft(QPoint(offsetX, offsetY));
    rect.setBottomRight(QPoint(minLength + offsetX, minLength + offsetY));
    return rect;
}

void Widget::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    // set background image
    {
        QPixmap pixmap("landscape1.jpg");
        QRect rect;
        rect.setTopLeft(QPoint(0, 0));
        rect.setBottomRight(QPoint(this->width(), this->height()));
        painter.drawPixmap(rect, pixmap);
    }

    // 绘制五子棋盘 十五行十五列
    {
        // 先画出边框
        int unitLength = 0;
        QRect rect = getChessRect(&unitLength);
        int offsetX = rect.x();
        int offsetY = rect.y();
        int minLength = rect.width();

        painter.drawRect(rect);

        // 内部的棋盘线条比边框线条要
        pen.setWidth(2);

        painter.setPen(pen);

        for (int i = 1; i < 14; i++)
        {
            // 画竖线
            painter.drawLine(unitLength * i + offsetX, offsetY, unitLength * i + offsetX, minLength + offsetY);

            // 画横线
            painter.drawLine(offsetX, unitLength * i + offsetY, minLength + offsetX, unitLength * i + offsetY);
        }

        // 绘制棋子
        this->drawChess(&painter, offsetX, offsetY, unitLength);
    }
}

/**
 * @brief Widget::mousePressEvent
 * @param event
 * 鼠标按下事件
 */
void Widget::mousePressEvent(QMouseEvent *event)
{
    //
    int x = event->x();
    int y = event->y();
    // 通过鼠标点击的位置 来确定在哪个位置
    int unitLength;
    QRect chessRect = getChessRect(&unitLength);

    int virtual_chess_x = chessRect.x() - unitLength / 2;
    int virtual_chess_y = chessRect.y() - unitLength / 2;

    int virtual_chess_width = chessRect.width() + unitLength;

    chessRect = QRect(virtual_chess_x, virtual_chess_y, virtual_chess_width, virtual_chess_width);

    // 获取棋盘的位置
    bool contained = chessRect.contains(x, y);
    if (contained)
    {
        int offsetX = x - chessRect.x();
        int offsetY = y - chessRect.y();
        int j = offsetX / unitLength;
        int i = offsetY / unitLength;
        if (i >= 15 || j >= 15)
        {
            return;
        }
        if (chess_flag[i][j] == 0)
        {
            if (chess_turn == 1)
            {
                chess_flag[i][j] = 1;
                chess_turn = 2;
                turnLabel->setText("白方");
            }
            else
            {
                chess_flag[i][j] = 2;
                chess_turn = 1;
                turnLabel->setText("黑方");
            }
            int flag = checkSuccess();
            this->update();
            if (flag == 1)
            {
                QMessageBox::information(this, "胜负已分", "黑方胜利");
                clear();
                this->update();
            }
            else if (flag == 2)
            {
                QMessageBox::information(this, "胜负已分", "白方胜利");
                clear();
                this->update();
            }
        }
    }
}

/**
 * @brief Widget::checkSuccess
 * @return
 * 检验是否已经决出胜负 返回0表示没有 1表示黑胜利 2表示白胜利
 */
int Widget::checkSuccess()
{
    {
        // 遍历方法
        for (int i = 0; i <= 14; i++)
        {
            for (int j = 0; j <= 14; j++)
            {
                int current_flag = chess_flag[i][j];
                if (current_flag == 0)
                {
                    continue;
                }
                // 以此点为起点 三个方向 右 下 右下
                // 右方
                for (int k = 1; k < 5; k++)
                {
                    if (j + k >= 15)
                    {
                        break;
                    }
                    if (chess_flag[i][j+k] != current_flag)
                    {
                        break;
                    }
                    if (k == 4)
                    {
                        return current_flag;
                    }
                }

                // 下方
                for (int k = 1; k < 5; k++)
                {
                    if (i + k >= 15)
                    {
                        break;
                    }
                    if (chess_flag[i+k][j] != current_flag)
                    {
                        break;
                    }
                    if (k == 4)
                    {
                        return current_flag;
                    }
                }
                // 右下方
                for (int k = 1; k < 5; k++)
                {
                    if (i + k >= 15 || j + k >= 15)
                    {
                        break;
                    }
                    if (chess_flag[i+k][j+k] != current_flag)
                    {
                        break;
                    }

                    if (k == 4)
                    {
                        return current_flag;
                    }
                }
                // 右上方
                for (int k = 1; k < 5; k++)
                {
                    if (i + k >= 15 || j - k < 0)
                    {
                        break;
                    }
                    if (chess_flag[i+k][j-k] != current_flag)
                    {
                        break;
                    }

                    if (k == 4)
                    {
                        return current_flag;
                    }
                }
            }
        }
        return 0; // 没有决出胜负
    }
}

/**
 * @brief Widget
 * 清理
 */
void Widget::clear()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            chess_flag[i][j] = 0;
        }
    }
    chess_turn = 1;
    turnLabel->setText("黑方");
}

