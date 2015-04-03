#include "widget.h"
#include "ui_widget.h"
#include "ImageButton.h"
#include <QGridLayout>
#include <QLabel>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ImageButton *NumButton_0=new ImageButton(":/icon/00.png",":/icon/00.png",":/icon/000.png",10,10,this);
    ImageButton *NumButton_1=new ImageButton(":/icon/11.png",":/icon/11.png",":/icon/111.png",70,10,this);
    ImageButton *NumButton_2=new ImageButton(":/icon/22.png",":/icon/22.png",":/icon/222.png",130,10,this);
    ImageButton *NumButton_3=new ImageButton(":/icon/33.png",":/icon/33.png",":/icon/333.png",10,70,this);
    ImageButton *NumButton_4=new ImageButton(":/icon/44.png",":/icon/44.png",":/icon/444.png",70,70,this);
    ImageButton *NumButton_5=new ImageButton(":/icon/55.png",":/icon/55.png",":/icon/555.png",130,70,this);
    ImageButton *NumButton_6=new ImageButton(":/icon/66.png",":/icon/66.png",":/icon/666.png",10,130,this);
    ImageButton *NumButton_7=new ImageButton(":/icon/77.png",":/icon/77.png",":/icon/777.png",70,130,this);
    ImageButton *NumButton_8=new ImageButton(":/icon/88.png",":/icon/88.png",":/icon/888.png",130,130,this);
    ImageButton *NumButton_9=new ImageButton(":/icon/99.png",":/icon/99.png",":/icon/999.png",10,190,this);
    ImageButton *WeatherButton=new ImageButton(":/icon/weather_n.gif",":/icon/weather_n.gif",":/icon/weather_p.gif",70,190,this);
}

Widget::~Widget()
{
    delete ui;
}
