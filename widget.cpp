#include "widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    ImageButton *NumButton_0=new ImageButton();
    ImageButton *NumButton_1=new ImageButton();
    ImageButton *NumButton_2=new ImageButton();
    ImageButton *NumButton_3=new ImageButton(":/icon/33.png",":/icon/33.png",":/icon/333.png");
    ImageButtonText *NumBtn_4 = new ImageButtonText(":/icon/33.png",":/icon/33.png",":/icon/333.png");
    //NumButton_3->setBtnText("123");

    QPushButton *testBtn = new QPushButton;
    testBtn->setText("Hello");

    h1Layout = new QHBoxLayout(this);
    h1Layout->addWidget(NumButton_0);
    h1Layout->addWidget(NumButton_1);
    h1Layout->addWidget(NumButton_2);
    h1Layout->addWidget(NumButton_3);
    h1Layout->addWidget(testBtn);
    h1Layout->addWidget(NumBtn_4);

}

Widget::~Widget()
{

}
