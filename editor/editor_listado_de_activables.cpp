#include "editor_listado_de_activables.h"
#include "ui_editor_listado_de_activables.h"

ListadoDeActivables::ListadoDeActivables(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListadoDeActivables)
{
    ui->setupUi(this);
}

ListadoDeActivables::~ListadoDeActivables()
{
    delete ui;
}
