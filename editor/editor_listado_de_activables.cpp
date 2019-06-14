#include "editor_listado_de_activables.h"
#include "ui_editor_listado_de_activables.h"
#include "editor_defines.h"

#define TIPO 0
#define NOMBRE 1
#define AGREGADO 2
#define NEGADO 3

ListadoDeActivables::ListadoDeActivables(QWidget *parent) : QDialog(parent),
                                                            ui(new Ui::ListadoDeActivables),
                                                            tipo("Tipo"),
                                                            nombre("Nombre"),
                                                            agregar("Agregar"),
                                                            negar("Aplicar NOT")
{
    ui->setupUi(this);

    //configuramos las columnas

    this->setMinimumSize(DIALOG_SIZE_W, DIALOG_SIZE_H);
    this->setMaximumSize(DIALOG_SIZE_W, DIALOG_SIZE_H);
    this->ui->listado->setColumnCount(4);
    this->ui->listado->setHorizontalHeaderItem(0, &this->tipo);
    this->ui->listado->setHorizontalHeaderItem(1, &this->nombre);
    this->ui->listado->setHorizontalHeaderItem(2, &this->agregar);
    this->ui->listado->setHorizontalHeaderItem(3, &this->negar);

    this->ui->listado->setColumnWidth(0, this->width() / 4);
    this->ui->listado->setColumnWidth(1, this->width() / 4);
    this->ui->listado->setColumnWidth(2, this->width() / 4);
    this->ui->listado->setColumnWidth(3, this->width() / 4);
}

ListadoDeActivables::~ListadoDeActivables()
{
    for (int i = 0; i < this->cajas.size(); i++)
    {
        delete this->cajas[i];
    }
    for (int i = 0; i < this->items.size(); i++)
    {
        delete this->items[i];
    }

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

void ListadoDeActivables::agregarElemento(QString nombre, QString tipo)
{
    QComboBox *agregar = new QComboBox(this->ui->listado);
    agregar->addItem("si");
    agregar->addItem("no");

    QComboBox *negar = new QComboBox(this->ui->listado);
    negar->addItem("si");
    negar->addItem("no");

    QTableWidgetItem *tipoItem = new QTableWidgetItem(tipo);
    QTableWidgetItem *nombreItem = new QTableWidgetItem(nombre);

    this->ui->listado->insertRow(this->ui->listado->rowCount());
    this->ui->listado->setItem(this->ui->listado->rowCount() - 1, TIPO, tipoItem);
    this->ui->listado->setItem(this->ui->listado->rowCount() - 1, NOMBRE, nombreItem);
    this->ui->listado->setCellWidget(this->ui->listado->rowCount() - 1, AGREGADO, agregar);
    this->ui->listado->setCellWidget(this->ui->listado->rowCount() - 1, NEGADO, negar);

    this->cajas.append(agregar);
    this->cajas.append(negar);
    this->items.append(tipoItem);
    this->items.append(nombreItem);
}
