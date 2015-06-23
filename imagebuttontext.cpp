#include "imagebuttontext.h"

ImageButtonText::ImageButtonText(const QString &normalName, const QString& horverName, const QString& pressName,QWidget *parent)
{
    imageBtn = new ImageButton(normalName,horverName,pressName,parent);
}

ImageButtonText::ImageButtonText(QWidget *parent)
{
    imageBtn = new ImageButton(parent);
}
