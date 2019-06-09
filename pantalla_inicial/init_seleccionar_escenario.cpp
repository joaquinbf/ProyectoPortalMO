#include "init_seleccionar_escenario.h"
#include "ui_init_seleccionar_escenario.h".h"
#include <QMessageBox>

SeleccionarEscenario::SeleccionarEscenario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SeleccionarEscenario)
{
    ui->setupUi(this);
    this->ui->listaEscenarios->addItem("Escenario1");
    this->ui->listaEscenarios->addItem("Escenario2");
    this->ui->listaEscenarios->addItem("Escenario3");
}

SeleccionarEscenario::~SeleccionarEscenario()
{
    delete ui;
}

void SeleccionarEscenario::on_buttonBox_accepted()
{
    //TODO
    //revisar
    //https://doc.qt.io/archives/qt-4.8/qlistwidget.html
    //https://doc.qt.io/archives/qt-4.8/qlistwidgetitem.html
    QListWidgetItem *escenario = this->ui->listaEscenarios->selectedItems().front();
    QMessageBox::information(this, "titulo", escenario->text());

}
