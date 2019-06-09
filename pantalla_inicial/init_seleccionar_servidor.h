#ifndef INIT_SELECCIONAR_SERVIDOR_H
#define INIT_SELECCIONAR_SERVIDOR_H

#include <QDialog>

namespace Ui {
class SeleccionarServidor;
}

class SeleccionarServidor : public QDialog
{
    Q_OBJECT

public:
    explicit SeleccionarServidor(QWidget *parent = 0);
    ~SeleccionarServidor();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SeleccionarServidor *ui;
};

#endif // INIT_SELECCIONAR_SERVIDOR_H
