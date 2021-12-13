#include "slidewindow.h"
#include "ui_slidewindow.h"
#include "mainwindow.h"


SlideWindow::SlideWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SlideWindow)
{
    ui->setupUi(this);
}


SlideWindow::~SlideWindow()
{
    delete ui;
}

void SlideWindow::on_Delete_Lable_clicked()
{
  connect(this,&SlideWindow::signal,MainWindow,&MainWindow::on_Delete_Lable_clicked_slot);
}

void SlideWindow::on_Canel_Button_clicked()
{
  MainWindow::on_Delete_Lable_clicked_slot();
}
