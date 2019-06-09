#include "init_seleccionar_servidor.h"
#include "ui_init_seleccionar_servidor.h"
#include <QMessageBox>

SeleccionarServidor::SeleccionarServidor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SeleccionarServidor)
{
    ui->setupUi(this);
    this->ui->listaServidores->addItem("servidor1");
    this->ui->listaServidores->addItem("servidor2");
    this->ui->listaServidores->addItem("servidor3");
}

SeleccionarServidor::~SeleccionarServidor()
{
    delete ui;
}

void SeleccionarServidor::on_buttonBox_accepted()
{
    //TODO
    //revisar
    //https://doc.qt.io/archives/qt-4.8/qlistwidget.html
    //https://doc.qt.io/archives/qt-4.8/qlistwidgetitem.html
    QListWidgetItem *escenario = this->ui->listaServidores->selectedItems().front();
    QMessageBox::information(this, "titulo", escenario->text());
}
