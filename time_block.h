#ifndef TIME_BLOCK_H
#define TIME_BLOCK_H

#include <QWidget>

namespace Ui {
class Time_block;
}

class Time_block : public QWidget
{
    Q_OBJECT
public slots:
    void main_algorithm();
    void Move_To();

public:
    explicit Time_block(QWidget *parent = nullptr);
    ~Time_block();

private:
    Ui::Time_block *ui;
};

#endif // TIME_BLOCK_H
