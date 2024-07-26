#include "fclaculator.h"
#include "./ui_fclaculator.h"
#include<QRegularExpression>

double  track_value = 0.0;

bool dividetrigger = false;
bool addtrigger = false;
bool multiplytrigger = false;
bool substracttrigger = false;
bool modtrigger = false;

// initializing the calculator operation
FClaculator::FClaculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FClaculator)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(track_value));

    // Creating and connecting number with number buttons;
    QPushButton *buttonnumber[10];
    for(int i = 0; i < 10; i++){
        QString Buttonname = "Button_" + QString::number(i);
        buttonnumber[i] =FClaculator::findChild<QPushButton *>(Buttonname);
        connect(buttonnumber[i], SIGNAL(released()), this, SLOT(numpressed()));
    }

    // Connecting operation with math button pressed
    connect(ui->Add,SIGNAL(released()),this, SLOT(buttonmathpressed()));
    connect(ui->Substract,SIGNAL(released()),this, SLOT(buttonmathpressed()));
    connect(ui->Multiply,SIGNAL(released()),this, SLOT(buttonmathpressed()));
    connect(ui->Divide,SIGNAL(released()),this, SLOT(buttonmathpressed()));
    connect(ui->Modular,SIGNAL(released()),this,SLOT(buttonmathpressed()));

    // Connecting operation with Equal, Sign_Change , AC button pressed
    connect(ui->Equal,SIGNAL(released()),this, SLOT(equalbutton()));
    connect(ui->SignChange,SIGNAL(released()),this, SLOT(changesign()));
    connect(ui->Clear,SIGNAL(released()),this,SLOT(refresh()));


}

FClaculator::~FClaculator()
{
    delete ui;
}

// function for number buttons
void FClaculator::numpressed(){
    QPushButton *button = (QPushButton *)sender();

    QString theval = button->text();
    QString dispval = ui->Display->text();

    if( (dispval.toDouble()==0) || (dispval.toDouble()==0.0) ){
        ui->Display->setText(theval);
    }
    else{
        QString newval = dispval + theval;

        double secnewval = newval.toDouble();

        ui->Display->setText(QString::number(secnewval,'g', 20));

    }

}

// function for math buttons;
void FClaculator::buttonmathpressed(){
    dividetrigger = false;
    multiplytrigger = false;
    substracttrigger = false;
    addtrigger = false;
    modtrigger = false;

    QString dispval = ui->Display->text();
    track_value = dispval.toDouble();

    QPushButton * button= (QPushButton *)sender();
    QString secnewval = button -> text();

    if(QString::compare(secnewval,"+",Qt::CaseInsensitive)==0){
        addtrigger = true;
    }
    else if(QString::compare(secnewval,"-",Qt::CaseInsensitive)==0){
        substracttrigger = true;
    }
    else if(QString::compare(secnewval,"x",Qt::CaseInsensitive)==0){
        multiplytrigger = true;
    }
    else if(QString::compare(secnewval,"÷",Qt::CaseInsensitive)==0){
        dividetrigger = true;
    }
    else{
        modtrigger = true;
    }

    ui->Display->setText(secnewval);
}

// function for equal button
void FClaculator::equalbutton(){
    double solution=0.0;
    QString dispVal = ui->Display->text();
    double secnewnum = dispVal.toDouble();

    if(addtrigger || substracttrigger || multiplytrigger || dividetrigger|| modtrigger)
    {
        if(addtrigger){
            solution = track_value + secnewnum;
        }
        else if(substracttrigger){
            solution = track_value - secnewnum;
        }
        else if(multiplytrigger){
            solution = track_value * secnewnum;
        }
        else if(dividetrigger){
            solution = track_value / secnewnum;
        }
        else{
            solution = static_cast<int>(track_value) % static_cast<int>(secnewnum);
        }

    }

    ui->Display->setText(QString::number(solution));

}

// funciton for changing Sign
void FClaculator::changesign(){
    QString disptext = ui->Display->text();
    QRegularExpression reg("[-]?[0-9.]*");
    QRegularExpressionMatch match = reg.match(disptext);

    if(match.hasMatch()){
        double secnewnum = disptext.toDouble();
        double secnewnumsign = -1 *(secnewnum);
        ui->Display->setText(QString::number(secnewnumsign));
    }
}

// function for clearing screen
void FClaculator::refresh(){
    ui->Display->setText("0");
    track_value = 0.0;
    dividetrigger =false;
    multiplytrigger = false;
    substracttrigger = false;
    addtrigger = false;
    modtrigger = false;
}





