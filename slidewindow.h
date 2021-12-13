#ifndef SLIDEWINDOW_H
#define SLIDEWINDOW_H

#include <QWidget>

namespace Ui {
class SlideWindow;
}

class SlideWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SlideWindow(QWidget *parent = nullptr);
    ~SlideWindow();

private slots:
    void on_Delete_Lable_clicked();

private:
    Ui::SlideWindow *ui;
};

#endif // SLIDEWINDOW_H
