/*************************************************
Copyright:江贤
Author:江贤
Version：0.5.0
Init Date:2015-04-04
Description:三态图片按钮
**************************************************/
#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QPushButton>
#include <QPoint>

class ImageButton : public QPushButton
{
    Q_OBJECT

public:
    //构造函数，调用参数：按钮三态图片
    explicit ImageButton(const QString &normalName, const QString& horverName, const QString& pressName,QWidget *parent = 0);
    //构造函数，调用参数:直接调用，提供默认的三态图片
    explicit ImageButton(QWidget *parent = 0);

/**********可供调用的函数**********/
public:
    //获得按钮的大小
    int getBtnWidth();
    int getBtnHeight();

//按钮的事件处理函数
protected:
    //鼠标进入事件
    virtual void enterEvent(QEvent *);
    //鼠标退出事件
    virtual void leaveEvent(QEvent *);
    //鼠标单击事件
    virtual void mousePressEvent(QMouseEvent *event);
    //鼠标释放事件
    virtual void mouseReleaseEvent(QMouseEvent *event);
    //鼠标样式绘制
    virtual void paintEvent(QPaintEvent *);

protected:
    //设置默认的按钮样式
    void setDefault();
    //设置按钮的大小
    void setBtnSize();

protected:
    //用于标识按钮的触发状态
    typedef enum
    {
        //初始状态
        ST_INIT,
        //正常状态
        ST_NORMAL,
        //鼠标悬停状态
        ST_HOVER,
        //鼠标按下状态
        ST_PRESS,
        //按钮所有状态的图片个数
        ST_COUNT
    } Status;
    Status curStatus_;

    //存储按钮在这几个状态下的背景图片路径
    QString imageName_[ST_COUNT];

    //存储按钮的大小
    int btn_width;
    int btn_height;
};

#endif // IMAGEBUTTON_H
