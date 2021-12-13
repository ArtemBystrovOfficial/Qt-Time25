#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <string>
#include <QSignalMapper>
#include <QLabel>
#include <cmath>
#include <QPixmap>
#include <QInputDialog>
#include <QErrorMessage>
#include <QPropertyAnimation>
#include <Windows.h>
#include <QTime>
#include <QDebug>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Make_defualt_settings();
    Make_invisible_elements();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void  MainWindow::Make_defualt_settings()
{

    QPixmap backnd("123456789.jpg");
    backnd = backnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,backnd);
    this->setPalette(palette);
    Time_lines();
    m_timerId = startTimer(200);


}



void MainWindow::Make_invisible_elements()
{

    ui->horizontalSlider->setHidden(true);
    ui->label1->setHidden(true);
    ui->Slider_for_lables->setHidden(true);
    ui->Canel_Button->setHidden(true);
    ui->Delete_Lable->setHidden(true);
    ui->Rename->setHidden(true);

}


// Глобальные------------------------------------

vector < QLabel* > Time_Lines;
vector < QLabel* > Time_Lines_2;
vector < int > Time_Lines_Absolut;
vector < QSignalMapper* > Signal_List;
//vector < QPushButton* > Label_list;
vector < int > Label_list_cor_x;
vector < QString > Colors;
vector < QLabel* > Lines;
vector < pair <QLabel* , QLabel* > > Names;
vector < QPushButton* > Label_list;

int value_purpose=0;
int data1=0;
int width_all=0;
bool Ckecked=true;
int max_x = 0;
int max_x_value=0;
int Selected_id=-1;
int Absolut_width=120;
int value1=0,value2=0;

//----------------------------------------------

void MainWindow::main_algorithm()
{
    QTime time = QTime::currentTime();
    int Curret_time=time.minute()+time.hour()*60;
    int width=0;
    for(int i=0;i<Label_list.size(); i++)
    {
        if(Curret_time*2>=width&&Curret_time*2<=Label_list[i]->width()+width)
        {
             if(Names.size()>i){
             ui->label11->setStyleSheet(Label_list[i]->styleSheet());
             ui->label44->setText(Names[i].second->text());
             ui->label55->setText(Names[i].first->text());
            }
             if(Names.size()>i+1){
             if(i<Label_list.size()-1)
             {
                 ui->label22->setStyleSheet(Label_list[i+1]->styleSheet());
                 ui->label77->setText(Names[i+1].second->text());

             }
             }
             if(Names.size()>i-1){
             if(i>0)
             {
                 ui->label33->setStyleSheet(Label_list[i-1]->styleSheet());
                 ui->label66->setText(Names[i-1].second->text());
             }
             }
             if(Label_list.size()>i){
           ui->label88->setGeometry(ui->label11->x()+int(float((((Curret_time-width/2)*60+time.second())*1000+time.msec())/float(((Label_list[i]->width()/2)*60)*1000+time.msec()))*(ui->label11->width())),280,1,250);
           if((width/2)%60==0)
           ui->label_right->setText(QString::number((width/2)/60)+":"+QString::number((width/2)%60)+"0");
           else
           ui->label_right->setText(QString::number((width/2)/60)+":"+QString::number((width/2)%60));

           if(((width+Label_list[i]->width()+1)/2)%60==0)
             ui->label_left->setText(QString::number(((width+Label_list[i]->width())/2+1)/60)+":"+QString::number((width+Label_list[i]->width()+1)%60)+"0");
           else
             ui->label_left->setText(QString::number(((width+Label_list[i]->width())/2)/60)+":"+QString::number((width+Label_list[i]->width())%60));
             }
         }



            width+=Label_list[i]->width();

    }
}
void MainWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_timerId)
     main_algorithm();
}


void MainWindow::on_pushButton_clicked()
{
    Ckecked=true;
    if(Label_list.size()>0)
    max_x=Label_list[Label_list.size()-1]->width()+Label_list[Label_list.size()-1]->x();
    else max_x=40;

        // Создаём графический элемент
    if(!size_check()){
        Create_Label(max_x,100,120,25);
 ui->pushButton->setGeometry(max_x+110,30,20,40);
    Show_Names();
    }
}

void MainWindow::Time_lines()
{
    int height=0;;
    for(int i=0;i!=96;i++)
    {
    if(i%4==0)height=3;
    if(i%4==1)height=1;
    if(i%4==2)height=2;
    if(i%4==3)height=1;
    QLabel *ql = new QLabel(this);
    ql->setGeometry(39+30*i,150-height*6,1,height*17);
    ql->setStyleSheet("background:rgba(255,255,255,0.7);");
    ql->show();
    Time_Lines.push_back(ql);
    }
    for(int i=0;i!=48;i++)
    {
        QLabel *ql = new QLabel(this);
        if(i%2==0)
        ql->setText(QString::number(i/2)+":"+QString::number(i%2*30)+"0");
        else
        ql->setText(QString::number(i/2)+":"+QString::number(i%2*30));
        ql->setStyleSheet("color:rgba(255,255,255,0.9);");
        ql->setGeometry(Time_Lines[i*2]->x()-10,184,40,20);
        ql->show();
    Time_Lines_2.push_back(ql);
    }
}
// Меню кнопок

void MainWindow::Create_Label(int x,int y, int width,int height)
{


    Ckecked=true;
    int r,g,b;
    r=rand()%64+150;
    g=rand()%64+150;
    b=rand()%64+150;
    QString rnd="background-color:rgb("+QString::number(r)+","+ QString::number(g)+"," + QString::number(rand()%64+150)+");";
    QPushButton  *ql = new QPushButton(this);
    ql->setStyleSheet(rnd+"border-radius: 3px;");

    QLabel *ql1 = new QLabel(this);
    QLabel *ql2 = new QLabel(this);

    ql2->setText(QInputDialog::getText(0,"","Name of list",QLineEdit::Normal,""));
    ql1->setStyleSheet("background-color:white;""color:black;""border-radius:4px;"
                       "background-color:rgba("+QString::number(r+40)+","+ QString::number(g+40)+"," + QString::number(b+40)+",0.8);");
    ql2->setStyleSheet("color:white");
    ql2->show();


    Colors.push_back(rnd);
    Label_list.push_back(ql);
    int data = QInputDialog::getText(0,"","Time(MIN)",QLineEdit::Normal,"").toInt();

    ql->setGeometry(x,y, data*2,height);
    ql1->setText(QString::number(ql->width()/120)+"h "+QString::number((ql->width()%120)/2)+"min");

    ql->show();

        ql1->show();
            Names.push_back({ql1,ql2});
    QSignalMapper *SigMapper = new QSignalMapper(this);
    connect(SigMapper, SIGNAL(mapped(int)),this,SLOT(choiseCost(int)));
    connect(ql,SIGNAL(clicked(bool)),SigMapper,SLOT(map()));
    SigMapper->setMapping(ql,Label_list.size()-1);
    Signal_List.push_back(SigMapper);
    if(data==0){Selected_id=Label_list.size()-1;on_Delete_Lable_clicked();}

}




// Полиморфизм кнопок
void MainWindow::choiseCost(int n)
{
    for(int i=0;i<Label_list.size();i++)
    {
        if(Label_list[i]->width()==0){
            Selected_id=i;
            on_Delete_Lable_clicked();
        }
     }
            Ckecked=true;
            int i=n;
            ui->Canel_Button->setHidden(false);
            ui->pushButton->setEnabled(false);
            ui->Delete_Lable->setHidden(false);
            ui->horizontalSlider->setHidden(false);
            ui->Rename->setHidden(false);
            for(int i=0;i<Names.size();i++)
            {
                Names[i].first->setHidden(true);
                Names[i].second->setHidden(true);
                Lines[i]->setHidden(true);
            }


            if(Selected_id!=-1)
            {
                  Show_Names();
                  Label_list[Selected_id]->setStyleSheet(Colors[Selected_id]+"border-radius:3px");
                  Names[Selected_id].first->setText(QString::number((Absolut_width-max_x_value)/120)+"h "+QString::number(((Absolut_width-max_x_value)%120)/2)+ "min");
            }
            max_x=max_x-max_x_value;
            max_x_value=0;
            Label_list[i]->setStyleSheet(Colors[i]+"border: 2px solid yellow;");
            Selected_id=i;
            ui->label_2->setText(Names[i].second->text());
            GetXLables();
            QRect pos(Label_list[i]->geometry());
            Absolut_width=pos.width();
            value1=pos.width()/120;
            value2=pos.width()%120;
            ui->label1->setHidden(false);
            ui->Slider_for_lables->setHidden(false);
            ui->Slider_for_lables->setGeometry(pos.x()-30,pos.y()+40,160,22);
            ui->horizontalSlider->setGeometry(pos.x()-30,pos.y()+65,160,22);
            ui->horizontalSlider->setSliderPosition(pos.width()/120);
            ui->Slider_for_lables->setSliderPosition(pos.width()%120);
            ui->label1->setGeometry(pos.x(),pos.y()-80,171,71);
            ui->horizontalSlider_2->setHidden(true);

}



void MainWindow::on_Delete_Lable_clicked()
{
    if(Label_list.size()>0)
    max_x=Label_list[Label_list.size()-1]->width()+Label_list[Label_list.size()-1]->x();
    else max_x=40;
    ui->pushButton->setGeometry(max_x,30,20,40);
    Ckecked=true;
    value1=0;
    value2=0;
    QRect pos(Label_list[Selected_id]->geometry());
    GetXLables();
    ReplaseLables(0,pos.width());
    delete Label_list[Selected_id];
    Label_list[Selected_id]=nullptr;
    Label_list.erase(Label_list.begin()+Selected_id);
    Colors.erase(Colors.begin()+Selected_id);
    ui->label1->setHidden(true);
    ui->Slider_for_lables->setHidden(true);
    ui->Canel_Button->setHidden(true);
    ui->pushButton->setEnabled(true);
    ui->Delete_Lable->setHidden(true);
    ui->label_2->setText("");
    ui->horizontalSlider->setHidden(true);
    ui->horizontalSlider_2->setHidden(false);
    ui->Rename->setHidden(true);

    delete Names[Selected_id].first;
    Names[Selected_id].first=nullptr;
    delete Names[Selected_id].second;
    Names[Selected_id].second=nullptr;
    Names.erase(Names.begin()+Selected_id);

    for(int i=0;i<Names.size();i++)
    {
        Names[i].first->setHidden(false);
        Names[i].second->setHidden(false);
        Lines[i]->setHidden(false);
    }

    Moved_Signals();
    Selected_id=-1;
    QRect pos_button_plus(ui->pushButton->geometry());
    ui->pushButton->setGeometry(pos_button_plus.x()-(Absolut_width-max_x_value),30,20,40);
    max_x-=Absolut_width;
    max_x_value=0;
    Show_Names();

}

void MainWindow::Moved_Signals()
{
    Ckecked=true;
    for(int i=Selected_id; i<int(Label_list.size());i++)
    {
         Signal_List[i+1]->setMapping(Label_list[i],i);
    }
    delete Signal_List[Selected_id];
    Signal_List[Selected_id]=nullptr;
    Signal_List.erase(Signal_List.begin()+Selected_id);

}


void MainWindow::GetXLables()
{
    Ckecked=true;
    Label_list_cor_x.clear();
    for(int i=0;i<int(Label_list.size());i++)
    {
        QRect pos(Label_list[i]->geometry());
        Label_list_cor_x.push_back(pos.x());
    }
}

void MainWindow::ReplaseLables(int value,int width)
{
    Ckecked=true;
    QRect pos(ui->label1->geometry());
    for(int i=Selected_id+1;i<int(Label_list.size());i++)
    {
        pos=Label_list[i]->geometry();
        Label_list[i]->setGeometry(Label_list_cor_x[i]-(width-value),pos.y(),pos.width(),pos.height());
    }

    ui->pushButton->setGeometry(pos.x()+130,20,20,40);

}


void MainWindow::on_Slider_for_lables_valueChanged(int value)
{
     on_Slider_for_lables_valueChanged_comb(value,true);
}

void MainWindow::on_Slider_for_lables_valueChanged_comb(int value, bool key)
{


       if(!size_check()){
    if(value+value1+value2!=0){
    if(key==true) value1=value; else value2=value;

    if(key==true){

    if(value%2!=0) value+=1;
    QRect pos(Label_list[Selected_id]->geometry());
    Label_list[Selected_id]->setGeometry(pos.x(),pos.y(),value+value2,25);
    if(value2/120==0){
    ui->label1->setText(QString::number(value/2)+QString(" Min"));
    }else
    ui->label1->setText(QString(QString::number((value2+value)/120)+" hr "+QString::number(((value2+value)%120)/2)+QString(" Min")));
    ReplaseLables(value+value2,Absolut_width);
    max_x_value=Absolut_width-value-value2;

    }
    else
    {
    QRect pos(Label_list[Selected_id]->geometry());
    Label_list[Selected_id]->setGeometry(pos.x(),pos.y(),value+value1,25);
    if(value==0){
    ui->label1->setText(QString::number(value1/2)+QString(" Min"));
    }else
    ui->label1->setText(QString(QString::number((value1+value)/120)+" hr "+QString::number(((value1+value)%120)/2)+QString(" Min")));
    ReplaseLables(value+value1,Absolut_width);
    max_x_value=Absolut_width-value-value1;

    }
    }
}
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    on_Slider_for_lables_valueChanged_comb(value*120,false);
}

void MainWindow::on_Canel_Button_clicked()
{
    if(Label_list.size()>0)
    max_x=Label_list[Label_list.size()-1]->width()+Label_list[Label_list.size()-1]->x();
    else max_x=40;
    ui->pushButton->setGeometry(max_x,30,20,40);
    Ckecked=true;
    Names[Selected_id].first->setText(QString::number((Absolut_width-max_x_value)/120)+"h "+QString::number(((Absolut_width-max_x_value)%120)/2)+ "min");
    ui->label_2->setText("");
    ui->label1->setHidden(true);
    ui->Slider_for_lables->setHidden(true);
    ui->Canel_Button->setHidden(true);
    ui->pushButton->setEnabled(true);
    ui->Delete_Lable->setHidden(true);
    ui->horizontalSlider->setHidden(true);
    ui->horizontalSlider_2->setHidden(false);
    ui->Rename->setHidden(true);
    value1=0;
    value2=0;
    Label_list[Selected_id]->setStyleSheet(Colors[Selected_id]+"border-radius:3px");
    Selected_id=-1;
    max_x=max_x-max_x_value;
    max_x_value=0;
    Show_Names();
    for(int i=0;i<Names.size();i++)
    {
        Names[i].first->setHidden(false);
        Names[i].second->setHidden(false);
        Lines[i]->setHidden(false);
    }

}

int distanse(int width)
{
    Ckecked=true;
    if(width>100)return 30;
    else if(width<20) return 80;
    else return 90-width/2;
}

void MainWindow::Show_Names()
{
    Ckecked=true;
    for(int i=0;i<Lines.size();i++)
    {
       delete Lines[i];
        Lines[i]=nullptr;
    }
    Lines.clear();
    for(int i=0;i<Label_list.size();i++)
    {
         QRect pos(Label_list[i]->geometry());

         QRect pos2(Names[i].second->geometry());


         Names[i].first->setGeometry(pos.x()+2,pos.y()+2,55,20);
         Names[i].second->setGeometry(pos.x()+10,pos.y()-distanse(pos.width()),pos2.width(),pos2.height());

         QLabel *line = new QLabel(this);
         line->setGeometry(pos.x()+20,pos.y()-distanse(pos.width())+24,2,pos.y()-(pos.y()-distanse(pos.width())+27));
         line->setStyleSheet(Colors[i]);
         line->show();

         Lines.push_back(line);

    }
}

void MainWindow::Time_Scratch(int value)
{
    for(int i=0;i<96;i++)
    {
        Time_Lines[i]->setGeometry(Time_Lines_Absolut[i]-value,Time_Lines[i]->y(),Time_Lines[i]->width(),Time_Lines[i]->height());

    }
}

void MainWindow::Time_Line_absolut()
{
    Time_Lines_Absolut.clear();
    for(int i=0;i<96;i++)
    {
    Time_Lines_Absolut.push_back(Time_Lines[i]->x());
    }
}
bool key=false;
int absolut_value=0;
void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{

    if(key==true)key=false; else{
    if(value==0||value>990){
        if(value==0){
        if(Label_list.size()>0)
        {
        if(Label_list[0]->x()<0)
        {
             key=true;
            ui->horizontalSlider_2->setSliderPosition(300);
            absolut_value+=20;

        }
        }
        }
        else{
            if(Label_list.size()>0)
            {
            if(Label_list[Label_list.size()-1]->x()+Label_list[Label_list.size()-1]->width()>1200)
            {

                 key=true;
                ui->horizontalSlider_2->setSliderPosition(700);
                absolut_value-=20;

            }
            }
        }

    }else{
        value=value-absolut_value;
    if(Ckecked){GetXLables();Time_Line_absolut();}
    ReplaseLables(-value*2,0);
    Sinhrone_time_2();
    Time_Scratch(value*2);
    Show_Names();
    Ckecked=false;
    }
    }

}

void  MainWindow::Sinhrone_time_2()
{
    for(int i=0;i<Time_Lines_2.size();i++)
    {
         Time_Lines_2[i]->setGeometry(Time_Lines[i*2]->x()-10,184,40,20);
    }
}

bool MainWindow::size_check()
{
    int sum=0;
    for(int i=0;i<Label_list.size();i++)
    {
        sum+=Label_list[i]->width();
    }
    if(sum>24*120)
    { (new QErrorMessage(this))->showMessage("Time > 24h"); return true;}
    else return false;
}

void MainWindow::on_Rename_clicked()
{
     Names[Selected_id].second->setText(QInputDialog::getText(0,"","Название",QLineEdit::Normal,""));
}

void MainWindow::on_pushButton_3_clicked()
{
    for(int i=0;i<Colors.size();i++)
    {
    int r,g,b;
    r=rand()%64+150;
    g=rand()%64+150;
    b=rand()%64+150;

    QString rnd="background-color:rgb("+QString::number(r)+","+ QString::number(g)+"," + QString::number(rand()%64+150)+");";
        Label_list[i]->setStyleSheet(rnd+"border-radius: 3px;");
          Colors[i]=rnd;
    }
}



