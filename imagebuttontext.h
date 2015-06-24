/*************************************************
Copyright:江贤
Author:江贤
Version：0.5.0
Init Date:2015-06-23
Description:在ImageButton类的基础上，支持在按钮上添加文字
**************************************************/
#ifndef IMAGEBUTTONTEXT_H
#define IMAGEBUTTONTEXT_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFont>
#include <QDebug>

#include "ImageButton.h"

class ImageButtonText : public QWidget
{
    Q_OBJECT

public:
    //构造函数，调用参数：按钮三态图片
    ImageButtonText(const QString &normalName, const QString& horverName, const QString& pressName,QWidget *parent = 0);
    //构造函数，调用参数:直接调用，提供默认的三态图片
    ImageButtonText(QWidget *parent = 0);

public:
    //布局枚举类型,图片位于按钮的什么位置
    enum LayoutPos
    {
        BOTTOM,
        TOP,
        LEFT,
        RIGHT,
        CENTRE
    };

/**********可供调用的函数**********/
public:
    //设置按钮文本，默认提供了微软雅黑字体，字号12，加粗，默认垂直布局
    void setBtnText(const QString&);
    //设置按钮文本字体
    void setBtnTextFamily(const QString&);
    //设置按钮文本字体大小
    void setBtnTextSize(const int&);
    //设置按钮文本是否加粗
    void setBtnTextBold(const bool&);
    //设置按钮文本字体对齐方式
    void setBtnTextAlignment(Qt::Alignment);
    //设置按钮文本的布局方式
    void setBtnTextLayout(LayoutPos);

private:
    //供构造函数调用，做初始化操作
    void Initial();
    //设置默认的文本样式，默认提供了微软雅黑字体，字号12，加粗，默认垂直布局
    void BtnTextStyle();

    //调整按钮文本布局函数
    void LayoutBottomH();
    void LayoutBottomV();
    void LayoutTopH();
    void LayoutTopV();
    void LayoutLeftH();
    void LayoutLeftV();
    void LayoutRightH();
    void LayoutRightV();

private:
    //按钮
    ImageButton* imageBtn;
    //文本
    QLabel *textLabel;
    //实例化字体样式
    QFont font;
    //布局
    QVBoxLayout* vLayout;
    QHBoxLayout* hLayout;
    //存储当前的布局样式
    LayoutPos layoutPos;
};

#endif // IMAGEBUTTONTEXT_H
