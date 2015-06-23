#ifndef IMAGEBUTTONTEXT_H
#define IMAGEBUTTONTEXT_H
#include "ImageButton.h"

class ImageButtonText : public ImageButton
{
    Q_OBJECT

public:
    //构造函数，调用参数：按钮三态图片
    ImageButtonText(const QString &normalName, const QString& horverName, const QString& pressName,QWidget *parent = 0);
    //构造函数，调用参数:直接调用，提供默认的三态图片
    ImageButtonText(QWidget *parent = 0);
private:
    ImageButton* imageBtn;
};

#endif // IMAGEBUTTONTEXT_H
