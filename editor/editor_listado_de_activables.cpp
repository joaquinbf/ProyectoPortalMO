#include "editor_listado_de_activables.h"
#include "ui_editor_listado_de_activables.h"

#include <QComboBox>

#define TIPO 0
#define NOMBRE 1
#define AGREGADO 2
#define NEGADO 3

ListadoDeActivables::ListadoDeActivables(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListadoDeActivables),
    tipo("Tipo"),
    nombre("Nombre"),
    agregar("Agregar"),
    negar("Aplicar NOT")
{
    ui->setupUi(this);

    //configuramos las columnas
    this->ui->listado->setColumnCount(4);
    this->ui->listado->setHorizontalHeaderItem(0, &this->tipo);
    this->ui->listado->setHorizontalHeaderItem(1, &this->nombre);
    this->ui->listado->setHorizontalHeaderItem(2, &this->agregar);
    this->ui->listado->setHorizontalHeaderItem(3, &this->negar);

}

ListadoDeActivables::~ListadoDeActivables()
{
    delete ui;
}
void ListadoDeActivables::on_cajaBotones_accepted()
{
    //TODO
}

void ListadoDeActivables::on_cajaBotones_rejected()
{
    //TODO
}

void ListadoDeActivables::agregarElemento(QString tipo, QString nombre) {
    QComboBox *agregar = new QComboBox(this->ui->listado);
    agregar->addItem("si");
    agregar->addItem("no");

    QComboBox *negar = new QComboBox(this->ui->listado);
    negar->addItem("si");
    negar->addItem("no");

    this->ui->listado->insertRow(this->ui->listado->rowCount());
    this->ui->listado->setItem(this->ui->listado->rowCount()-1, TIPO, new QTableWidgetItem(tipo));
    this->ui->listado->setItem(this->ui->listado->rowCount()-1, NOMBRE, new QTableWidgetItem(nombre));
    this->ui->listado->setCellWidget(this->ui->listado->rowCount()-1, AGREGADO, agregar);
    this->ui->listado->setCellWidget(this->ui->listado->rowCount()-1, NEGADO, negar);

}
