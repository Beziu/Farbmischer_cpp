#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSurfaceFormat>
#include <QWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sliderRed_valueChanged(int myRed);
    void on_sliderGreen_valueChanged(int myGreen);
    void on_sliderBlue_valueChanged(int myBlue);

    void on_vbRed_valueChanged(int myRed);
    void on_vbGreen_valueChanged(int myGreen);
    void on_vbBlue_valueChanged(int myBlue);

    void on_lbledRed_editingFinished();
    void on_lbledGreen_editingFinished();
    void on_lbledBlue_editingFinished();

    void on_btnClose_clicked();

    void on_sliderTransparent_valueChanged(int myTransparent);

    void on_vbTransparent_valueChanged(int myTransparent);

    void on_lineEditBlue_returnPressed();
    void on_lineEditGreen_returnPressed();
    void on_lineEditRed_returnPressed();

    void on_lineEditBlue_editingFinished();
    void on_lineEditGreen_editingFinished();
    void on_lineEditRed_editingFinished();

private:
    Ui::MainWindow *ui;

    void init();

    int myRed = 255;
    int myGreen = 255;
    int myBlue = 255;
    int myTransparent = 0;

    void setDynamicColor(int myRed, int myGreen, int myBlue);
    void setDynamicDarkerColor();
    void setTransparency(int myTransparent);

};
#endif // MAINWINDOW_H
