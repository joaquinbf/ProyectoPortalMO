#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QPalette>
#include <QDir>
#include <QDebug>

#include "init_seleccionar_escenario.h"
#include "init_seleccionar_servidor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap background(":/resources/background2.jpeg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette paleta;
    paleta.setBrush(QPalette::Background, background);
    this->setPalette(paleta);
    //cambiamos la apariencia de los botones.
    this->ui->botonNuevaPartida->setStyleSheet("background-color: black; color: white");
    this->ui->botonBuscarServidor->setStyleSheet("background-color: black; color: white");
    this->ui->botonOpciones->setStyleSheet("background-color: black; color: white");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_botonNuevaPartida_clicked()
{
    SeleccionarEscenario seleccion;
    seleccion.setModal(true);
    seleccion.exec();
}

void MainWindow::on_botonBuscarServidor_clicked()
{
    SeleccionarServidor seleccion;
    seleccion.setModal(true);
    seleccion.exec();
}
