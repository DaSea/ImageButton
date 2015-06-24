#include "widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    ImageButton *NumButton_0=new ImageButton();
    ImageButton *NumButton_3=new ImageButton(":/icon/33.png",":/icon/33.png",":/icon/333.png",this);

    ImageButtonText *NumButton_4 = new ImageButtonText();
    NumButton_4->setBtnText("按钮文本");
    //NumButton_4->setBtnTextAlignment(Qt::AlignRight);
    NumButton_4->setBtnTextLayout(ImageButtonText::TOP);


    h1Layout = new QHBoxLayout(this);
    h1Layout->addWidget(NumButton_0);
    h1Layout->addWidget(NumButton_3);
    h1Layout->addWidget(NumButton_4);

}

Widget::~Widget()
{

}
