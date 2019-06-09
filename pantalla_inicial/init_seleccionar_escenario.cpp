#include "init_seleccionar_escenario.h"
#include "ui_seleccionarescenario.h"

SeleccionarEscenario::SeleccionarEscenario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SeleccionarEscenario)
{
    ui->setupUi(this);
}

SeleccionarEscenario::~SeleccionarEscenario()
{
    delete ui;
}
