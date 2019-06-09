#include "init_seleccionar_servidor.h"
#include "ui_init_seleccionar_servidor.h"

SeleccionarServidor::SeleccionarServidor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SeleccionarServidor)
{
    ui->setupUi(this);
}

SeleccionarServidor::~SeleccionarServidor()
{
    delete ui;
}
