#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vector>
#include <QPushButton>
#include <QMainWindow>
#include <QLabel>
#include <QSlider>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void on_pushButton_clicked();
    void Create_Label(int x,int y, int width,int height);
    void choiseCost(int n);
    void Make_defualt_settings();
    void GetXLables();
    void on_Canel_Button_clicked();
    void Show_Names();
    void on_Delete_Lable_clicked();
    void Moved_Signals();
    void Make_invisible_elements();
    void ReplaseLables(int value,int width);
    void on_Slider_for_lables_valueChanged(int value);
    void on_Slider_for_lables_valueChanged_comb(int value,bool key);
    void Time_lines();
    void Time_Scratch(int value);
    void Time_Line_absolut();
    bool size_check();
    void Sinhrone_time_2();
    void main_algorithm();
       void on_switch_2_clicked();
       void timerEvent(QTimerEvent *event);
private slots:



    void on_horizontalSlider_valueChanged(int value);



    void on_horizontalSlider_2_valueChanged(int value);

    void on_Rename_clicked();

    void on_pushButton_3_clicked();



private:
    Ui::MainWindow *ui;
      int m_timerId;
};


#endif // MAINWINDOW_H


