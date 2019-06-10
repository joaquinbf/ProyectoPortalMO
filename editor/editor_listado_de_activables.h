#ifndef EDITOR_LISTADO_DE_ACTIVABLES_H
#define EDITOR_LISTADO_DE_ACTIVABLES_H

#include <QDialog>

namespace Ui {
class ListadoDeActivables;
}

class ListadoDeActivables : public QDialog
{
    Q_OBJECT

public:
    explicit ListadoDeActivables(QWidget *parent = 0);
    ~ListadoDeActivables();

private:
    Ui::ListadoDeActivables *ui;
};

#endif // EDITOR_LISTADO_DE_ACTIVABLES_H
