#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void init();
    void drawChess(QPainter* painter, int, int, int);
    QRect getChessRect(int* pUnitLength);
    int checkSuccess();
    void clear();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    int chess_flag[15][15] = {0}; // 0表示没有棋子落下 1 表示黑色棋子落下 2 表示白色棋子落下
    int chess_turn = 1; // 1表示黑色 2表示白色
    QLabel* turnLabel;
};
#endif // WIDGET_H
