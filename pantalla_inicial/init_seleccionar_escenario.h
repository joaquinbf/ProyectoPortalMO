#ifndef INIT_SELECCIONAR_ESCENARIO_H
#define INIT_SELECCIONAR_ESCENARIO_H

#include <QDialog>

namespace Ui {
class SeleccionarEscenario;
}

class SeleccionarEscenario : public QDialog
{
    Q_OBJECT

public:
    explicit SeleccionarEscenario(QWidget *parent = 0);
    ~SeleccionarEscenario();

private:
    Ui::SeleccionarEscenario *ui;
};

#endif // INIT_SELECCIONAR_ESCENARIO_H
