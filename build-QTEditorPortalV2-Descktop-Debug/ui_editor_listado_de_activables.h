/********************************************************************************
** Form generated from reading UI file 'editor_listado_de_activables.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_LISTADO_DE_ACTIVABLES_H
#define UI_EDITOR_LISTADO_DE_ACTIVABLES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ListadoDeActivables
{
public:
    QGridLayout *gridLayout;
    QTableWidget *listado;
    QDialogButtonBox *cajaBotones;

    void setupUi(QDialog *ListadoDeActivables)
    {
        if (ListadoDeActivables->objectName().isEmpty())
            ListadoDeActivables->setObjectName(QStringLiteral("ListadoDeActivables"));
        ListadoDeActivables->resize(400, 300);
        gridLayout = new QGridLayout(ListadoDeActivables);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listado = new QTableWidget(ListadoDeActivables);
        listado->setObjectName(QStringLiteral("listado"));

        gridLayout->addWidget(listado, 0, 0, 1, 1);

        cajaBotones = new QDialogButtonBox(ListadoDeActivables);
        cajaBotones->setObjectName(QStringLiteral("cajaBotones"));
        cajaBotones->setOrientation(Qt::Horizontal);
        cajaBotones->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(cajaBotones, 1, 0, 1, 1);


        retranslateUi(ListadoDeActivables);
        QObject::connect(cajaBotones, SIGNAL(accepted()), ListadoDeActivables, SLOT(accept()));
        QObject::connect(cajaBotones, SIGNAL(rejected()), ListadoDeActivables, SLOT(reject()));

        QMetaObject::connectSlotsByName(ListadoDeActivables);
    } // setupUi

    void retranslateUi(QDialog *ListadoDeActivables)
    {
        ListadoDeActivables->setWindowTitle(QApplication::translate("ListadoDeActivables", "Logica de Apertura de la Compuerta", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ListadoDeActivables: public Ui_ListadoDeActivables {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_LISTADO_DE_ACTIVABLES_H
