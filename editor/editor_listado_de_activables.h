#ifndef EDITOR_LISTADO_DE_ACTIVABLES_H
#define EDITOR_LISTADO_DE_ACTIVABLES_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QString>
#include <QComboBox>


namespace Ui
{
class ListadoDeActivables;
}

class ListadoDeActivables : public QDialog
{
    Q_OBJECT
private:
    QTableWidgetItem tipo;
    QTableWidgetItem nombre;
    QTableWidgetItem agregar;
    QTableWidgetItem negar;
    QList<QComboBox *> cajas;
    QList<QTableWidgetItem* > items;
public:
    explicit ListadoDeActivables(QWidget *parent = 0);
    ~ListadoDeActivables();
    void agregarElemento(QString nombre, QString tipo);

private slots:
    void on_cajaBotones_accepted();

    void on_cajaBotones_rejected();

private:
    Ui::ListadoDeActivables *ui;
};

#endif // EDITOR_LISTADO_DE_ACTIVABLES_H
