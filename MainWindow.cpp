#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init();

}

void MainWindow::init()
{
    ui->sliderRed->setValue(myRed);
    ui->sliderGreen->setValue(myGreen);
    ui->sliderBlue->setValue(myBlue);
    ui->sliderTransparent->setValue(myTransparent);

    ui->lbledRed->setText(QString("0X%1").arg(ui->sliderRed->value(), 2, 16, QChar('0')).toUpper());
    ui->lbledGreen->setText(QString("0X%1").arg(ui->sliderGreen->value(), 2, 16, QChar('0')).toUpper());
    ui->lbledBlue->setText(QString("0X%1").arg(ui->sliderBlue->value(), 2, 16, QChar('0')).toUpper());

    setDynamicColor(myRed, myGreen, myBlue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lbledRed_editingFinished()
{
    //ui->lbledRed->setText(QString("0X%1").arg(ui->sliderRed->value(), 2, 16, QChar('0')).toUpper());
}

void MainWindow::on_lbledGreen_editingFinished()
{
    //ui->lbledGreen->setText(QString("0X%1").arg(ui->sliderGreen->value(), 2, 16, QChar('0')).toUpper());
}

void MainWindow::on_lbledBlue_editingFinished()
{
    //ui->lbledBlue->setText(QString("0X%1").arg(ui->sliderBlue->value(), 2, 16, QChar('0')).toUpper());
}

void MainWindow::on_vbGreen_valueChanged(int myGreen)
{
    ui->sliderGreen->setValue(myGreen);
}


void MainWindow::on_vbBlue_valueChanged(int myBlue)
{
    ui->sliderBlue->setValue(myBlue);
}


void MainWindow::on_vbRed_valueChanged(int myRed)
{
    ui->sliderRed->setValue(myRed);
}



void MainWindow::on_lineEditRed_returnPressed()
{
    this->focusNextChild();
}

void MainWindow::on_lineEditRed_editingFinished()
{
    bool bOK;
    this->myRed = ui->lineEditRed->text().toInt(&bOK, 10);
    if (bOK == true)
       ui->sliderRed->setValue(myRed);
}

void MainWindow::on_lineEditGreen_returnPressed()
{
    this->focusNextChild();
}

void MainWindow::on_lineEditGreen_editingFinished()
{
    bool bOK;
    this->myGreen = ui->lineEditGreen->text().toInt(&bOK, 10);
    if (bOK == true)
       ui->sliderGreen->setValue(myGreen);
}

void MainWindow::on_lineEditBlue_returnPressed()
{
    this->focusNextChild();
}

void MainWindow::on_lineEditBlue_editingFinished()
{
    bool bOK;
    this->myBlue = ui->lineEditBlue->text().toInt(&bOK, 10);
    if (bOK == true)
       ui->sliderBlue->setValue(myBlue);
}

void MainWindow::on_btnClose_clicked()
{
    close();
}

void MainWindow::on_sliderRed_valueChanged(int myRed)
{
    this->myRed = myRed;
    ui->vbRed->setValue(myRed);
    ui->lineEditRed->setText(QString::number(myRed));
    ui->lbledRed->setText(QString("0X%1").arg(ui->sliderRed->value(), 2, 16, QChar('0')).toUpper());
    setDynamicColor(myRed, myGreen, myBlue);
    setDynamicDarkerColor();
}

void MainWindow::on_sliderGreen_valueChanged(int myGreen)
{
    this->myGreen = myGreen;
    ui->vbGreen->setValue(myGreen);
    ui->lineEditGreen->setText(QString::number(myGreen));
    ui->lbledGreen->setText(QString("0X%1").arg(ui->sliderGreen->value(), 2, 16, QChar('0')).toUpper());
    setDynamicColor(myRed, myGreen, myBlue);
    setDynamicDarkerColor();
}

void MainWindow::on_sliderBlue_valueChanged(int myBlue)
{
    this->myBlue = myBlue;
    ui->vbBlue->setValue(myBlue);
    ui->lineEditBlue->setText(QString::number(myBlue));
    ui->lbledBlue->setText(QString("0X%1").arg(ui->sliderBlue->value(), 2, 16, QChar('0')).toUpper());
    setDynamicColor(myRed, myGreen, myBlue);
    setDynamicDarkerColor();
}


void MainWindow::setDynamicColor(int myRed, int myGreen, int myBlue)
{
    QPalette pal = this->palette();
    QColor myColor;

    myColor.setRgb(myRed, myGreen, myBlue);
    pal.setColor(QPalette::Window, myColor);

    this->setPalette(pal);
}


void MainWindow::setDynamicDarkerColor()
{
    QPalette pal = this->palette();
    QColor myColor = Qt::white;

    int val = myRed + myGreen + myBlue;

    if (val <= 100)
        pal.setColor(QPalette::WindowText, myColor);
    else if (val > 100)
        pal.setColor(QPalette::WindowText, myColor.darker(val-50));;

    this->setPalette(pal);
}

void MainWindow::setTransparency(int myTransparent)
{
    this->myTransparent = myTransparent;
    ui->vbTransparent->setValue(myTransparent);

    this->setWindowOpacity(1 - (myTransparent / 100.0));
    ui->lbledTransparent->setText(QString::number(myTransparent) + " %");
}

void MainWindow::on_sliderTransparent_valueChanged(int myTransparent)
{
    setTransparency(myTransparent);
}

void MainWindow::on_vbTransparent_valueChanged(int myTransparent)
{
    ui->sliderTransparent->setValue(myTransparent);
}


