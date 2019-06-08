#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editor_defines.h"
#include "editor_escenario_grafico.h"

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QFileDialog>
#include <QMouseEvent>
#include <string>
#include <QSize>
#include <yaml-cpp/yaml.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setMinimumSize(WINDOWS_SIZE_W, WINDOWS_SIZE_H);
    this->setMaximumSize(WINDOWS_SIZE_W, WINDOWS_SIZE_H);
    this->ui->setupUi(this);
    this->ui->graphicsView->setScene(&(this->escenario));

    //dibujamos grilla
    for(int i = 0; i < WINDOWS_SIZE_W; i += CELL_SIZE_W) {
        this->escenario.addLine(i, 0, i, WINDOWS_SIZE_H, QPen(Qt::gray));
    }
    for(int i = 0; i < WINDOWS_SIZE_H; i += CELL_SIZE_H) {
        this->escenario.addLine(0, i, WINDOWS_SIZE_W, i, QPen(Qt::gray));
    }

    //seteamos spinbox
    QSize size = this->ui->graphicsView->size();
    this->escenario.setSceneRect(0, 0, size.width(), size.height());

    this->ui->spinBoxX->setMinimum(INT_MIN);
    this->ui->spinBoxX->setMaximum(INT_MAX);
    this->ui->spinBoxY->setMinimum(INT_MIN);
    this->ui->spinBoxY->setMaximum(INT_MAX);
    this->escenario.setSpinBox(this->ui->spinBoxX, this->ui->spinBoxY);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionBloque_de_Metal_triggered()
{

}

void MainWindow::on_actionAcido_triggered()
{

}

void MainWindow::on_actionBloque_de_Metal_en_Diagonal_triggered()
{

}

void MainWindow::on_actionBoton_triggered()
{

}

void MainWindow::on_actionRoca_triggered()
{

}

void MainWindow::on_actionEmisor_de_Energia_triggered()
{

}

void MainWindow::on_actionReceptor_de_Energia_triggered()
{

}

void MainWindow::on_actionPersonaje_triggered()
{
    this->escenario.setIdClassACrear(IDCLASS_CHELL);
}

void MainWindow::on_actionBloque_de_Roca_triggered()
{
    this->escenario.setIdClassACrear(IDCLASS_BLOQUEROCA);
}

void MainWindow::on_actionFondo_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "Abrir");

    this->escenario.setFondoEscenario(path.toStdString());

    QPixmap nuevoFondo(path);
    nuevoFondo = nuevoFondo.scaled(this->ui->graphicsView->size());
    QBrush fondo(nuevoFondo);
    this->escenario.setBackgroundBrush(fondo);
}

void MainWindow::on_actionGuardar_Escenario_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, "Guardar");

    YAML::Node nodo = YAML::LoadFile(path.toStdString());
    //this->escenario.guardar(nodo);

}
