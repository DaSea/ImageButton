#include "imagebuttontext.h"

ImageButtonText::ImageButtonText(const QString &normalName, const QString& horverName, const QString& pressName,QWidget *parent)
{
    //实例化基类的图片按钮(自定义按钮三态)
    imageBtn = new ImageButton(normalName,horverName,pressName,parent);

    //初始化工作
    Initial();
}

ImageButtonText::ImageButtonText(QWidget *parent)
{
    //实例化基类的图片按钮(使用默认按钮)
    imageBtn = new ImageButton(parent);

    //初始化工作
    Initial();
}

void ImageButtonText::Initial()
{
    //实例化文本
    textLabel = new QLabel;
    //实例化布局
    vLayout = new QVBoxLayout(this);
    hLayout = new QHBoxLayout(this);
}

void ImageButtonText::setBtnText(const QString &text)
{
    //设置文本内容
    textLabel->setText(text);

    //设置字体默认样式
    BtnTextStyle();
}

void ImageButtonText::BtnTextStyle()
{
    //设置默认文本宽度
    textLabel->setMinimumWidth(imageBtn->getBtnWidth());
    //textLabel->setMaximumWidth();

    //默认让文本居中显示
    textLabel->setAlignment(Qt::AlignCenter);

    //设置默认文本字、大小及加粗
    font.setFamily("微软雅黑");
    font.setPointSize(12);
    font.setBold(true);
    textLabel->setFont(font);

    //默认布局
    vLayout->addWidget(imageBtn);
    vLayout->addWidget(textLabel);
    layoutPos = BOTTOM;
}

void ImageButtonText::setBtnTextLayout(LayoutPos pos)
{
    switch (pos)
    {
        case BOTTOM:
            if(layoutPos == TOP) LayoutBottomV();
            if(layoutPos == LEFT) LayoutBottomH();
            if(layoutPos == RIGHT) LayoutBottomH();
            break;

        case TOP:
            if(layoutPos == BOTTOM) LayoutTopV();
            if(layoutPos == LEFT) LayoutTopH();
            if(layoutPos == RIGHT) LayoutTopH();
            break;

        case LEFT:
            if(layoutPos == BOTTOM) LayoutLeftV();
            if(layoutPos == TOP) LayoutLeftV();
            if(layoutPos == RIGHT) LayoutTopH();
            break;

        case RIGHT:
            if(layoutPos == BOTTOM) LayoutRightV();
            if(layoutPos == TOP) LayoutRightV();
            if(layoutPos == LEFT) LayoutRightH();
            break;

        default:
            qDebug()<<"ERROR:Layout Change ERROR!!!";
    }
}

void ImageButtonText::setBtnTextFamily(const QString &family)
{
    //设置字体
    font.setFamily(family);
    textLabel->setFont(font);
}

void ImageButtonText::setBtnTextSize(const int & size)
{
    //设置字体大小
    font.setPointSize(size);
    textLabel->setFont(font);
}

void ImageButtonText::setBtnTextBold(const bool& enable)
{
    //设置字体加粗
    font.setBold(enable);
    textLabel->setFont(font);
}

void ImageButtonText::setBtnTextAlignment(Qt::Alignment alignment)
{
    //设置对齐方式
    textLabel->setAlignment(alignment);
}

void ImageButtonText::LayoutBottomH()
{
    hLayout->removeWidget(imageBtn);
    hLayout->removeWidget(textLabel);
    vLayout->addWidget(imageBtn);
    vLayout->addWidget(textLabel);
    layoutPos = BOTTOM;
}
void ImageButtonText::LayoutBottomV()
{
    vLayout->removeWidget(imageBtn);
    vLayout->removeWidget(textLabel);
    vLayout->addWidget(imageBtn);
    vLayout->addWidget(textLabel);
    layoutPos = BOTTOM;
}

void ImageButtonText::LayoutTopH()
{
    hLayout->removeWidget(imageBtn);
    hLayout->removeWidget(textLabel);
    vLayout->addWidget(textLabel);
    vLayout->addWidget(imageBtn);
    layoutPos = TOP;
}

void ImageButtonText::LayoutTopV()
{
    vLayout->removeWidget(imageBtn);
    vLayout->removeWidget(textLabel);
    vLayout->addWidget(textLabel);
    vLayout->addWidget(imageBtn);
    layoutPos = TOP;
}

void ImageButtonText::LayoutLeftH()
{
    hLayout->removeWidget(imageBtn);
    hLayout->removeWidget(textLabel);
    hLayout->addWidget(textLabel);
    hLayout->addWidget(imageBtn);
    layoutPos = LEFT;
}

void ImageButtonText::LayoutLeftV()
{
    vLayout->removeWidget(imageBtn);
    vLayout->removeWidget(textLabel);
    hLayout->addWidget(textLabel);
    hLayout->addWidget(imageBtn);
    layoutPos = LEFT;
}

void ImageButtonText::LayoutRightH()
{
    hLayout->removeWidget(imageBtn);
    hLayout->removeWidget(textLabel);
    hLayout->addWidget(imageBtn);
    hLayout->addWidget(textLabel);
    layoutPos = RIGHT;
}

void ImageButtonText::LayoutRightV()
{
    vLayout->removeWidget(imageBtn);
    vLayout->removeWidget(textLabel);
    hLayout->addWidget(imageBtn);
    hLayout->addWidget(textLabel);
    layoutPos = RIGHT;
}
