#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "editor_escenario_grafico.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionBloque_de_Roca_triggered();

    void on_actionBloque_de_Metal_triggered();

    void on_actionAcido_triggered();

    void on_actionBloque_de_Metal_en_Diagonal_triggered();

    void on_actionBoton_triggered();

    void on_actionRoca_triggered();

    void on_actionEmisor_de_Energia_triggered();

    void on_actionReceptor_de_Energia_triggered();

    void on_actionPersonaje_triggered();

    void on_actionFondo_triggered();

    void on_actionGuardar_Escenario_triggered();

    void on_actionAbrir_Escenario_triggered();

private:
    Ui::MainWindow *ui;
    EscenarioGrafico escenario;
};

#endif // MAINWINDOW_H
