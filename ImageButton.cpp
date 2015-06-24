#include "imagebutton.h"
#include <QtWidgets>
#include <QPixmap>

ImageButton::ImageButton(const QString& normalName, const QString& horverName, const QString& pressName,QWidget *parent)
    : QPushButton(parent)
    //设置按钮初始状态
    , curStatus_(ST_INIT)
{
    //设置按钮状态为正常
    curStatus_ = ST_NORMAL;

    //存储按钮三态图片
    //正常图片
    imageName_[ST_NORMAL] = normalName;
    //悬停图片
    imageName_[ST_HOVER] = horverName;
    //按下图片
    imageName_[ST_PRESS] = pressName;

   //设置按钮大小
    setBtnSize();
}

ImageButton::ImageButton(QWidget *parent)
    : QPushButton(parent)
    //设置按钮初始状态
    , curStatus_(ST_INIT)
{
    //设置按钮状态为正常
    curStatus_ = ST_NORMAL;

    //设置默认三态按钮及按钮大小
    setDefault();

}

void ImageButton::setDefault()
{
    //默认按钮
    imageName_[ST_NORMAL] = ":/defaultBtn/defaultIcon/BigBlue.png";
    //悬停按钮
    imageName_[ST_HOVER] = ":/defaultBtn/defaultIcon/BigYellowButton.png";
    //按下按钮
    imageName_[ST_PRESS] = ":/defaultBtn/defaultIcon/BigGreenButton.png" ;

    //设置按钮大小
    setBtnSize();
}

void ImageButton::setBtnSize()
{
    //获得图片的大小以便用来调整按钮的大小
    QPixmap icon;
    //读取正常状态按钮图片
    icon.load(imageName_[ST_NORMAL]);

    this->btn_width=icon.width();
    this->btn_height=icon.height();;

    //设置按钮控件的最小与最大大小
    setMaximumSize(btn_width,btn_height);
    setMinimumSize(btn_width,btn_height);

    //qDebug()<<btn_width<<btn_height;
}

void ImageButton::enterEvent(QEvent *)
{
    if (curStatus_ == ST_INIT)
    {
        return;
    }

    //鼠标进入按钮时，设置状态为悬停
    curStatus_ = ST_HOVER;
    update();
}

void ImageButton::leaveEvent(QEvent *)
{
    if (curStatus_ == ST_INIT)
    {
        return;
    }

    //鼠标离开按钮时，设置状态为正常
    curStatus_ = ST_NORMAL;
    update();
}

void ImageButton::mousePressEvent(QMouseEvent *event)
{
    if (curStatus_ == ST_INIT)
    {
        return;
    }

    //如果鼠标左键点击
    if (event->button() == Qt::LeftButton)
    {
        //将按钮状态设置为按下，并绘图
        curStatus_ = ST_PRESS;
        update();
    }
}

void ImageButton::mouseReleaseEvent(QMouseEvent *event)
{
    //如果鼠标左键释放
    if (event->button() == Qt::LeftButton)
    {
        if (curStatus_ != ST_INIT)
        {
            //将按钮状态设置为悬停，并绘图
            curStatus_ = ST_HOVER;
            update();
        }
    }
    // 鼠标在弹起的时候光标在按钮上才激发clicked信号
    if (rect().contains(event->pos()))
    {
        emit clicked();
    }
}

void ImageButton::paintEvent(QPaintEvent *event)
{
    if (curStatus_ == ST_INIT)
    {
        QPushButton::paintEvent(event);
        return;
    }
    QPainter painter(this);
    //绘制当前状态的按钮
    QPixmap pixmap(imageName_[curStatus_]);
    //绘图
    painter.drawPixmap(rect(), pixmap);
}

int ImageButton::getBtnHeight()
{
    return btn_height;
}

int ImageButton::getBtnWidth()
{
    return btn_width;
}
