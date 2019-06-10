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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ListadoDeActivables
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;
    QRadioButton *radioButton;

    void setupUi(QDialog *ListadoDeActivables)
    {
        if (ListadoDeActivables->objectName().isEmpty())
            ListadoDeActivables->setObjectName(QStringLiteral("ListadoDeActivables"));
        ListadoDeActivables->resize(400, 300);
        buttonBox = new QDialogButtonBox(ListadoDeActivables);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableWidget = new QTableWidget(ListadoDeActivables);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(60, 10, 256, 192));
        radioButton = new QRadioButton(ListadoDeActivables);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(50, 220, 112, 23));

        retranslateUi(ListadoDeActivables);
        QObject::connect(buttonBox, SIGNAL(accepted()), ListadoDeActivables, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ListadoDeActivables, SLOT(reject()));

        QMetaObject::connectSlotsByName(ListadoDeActivables);
    } // setupUi

    void retranslateUi(QDialog *ListadoDeActivables)
    {
        ListadoDeActivables->setWindowTitle(QApplication::translate("ListadoDeActivables", "Dialog", Q_NULLPTR));
        radioButton->setText(QApplication::translate("ListadoDeActivables", "RadioButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ListadoDeActivables: public Ui_ListadoDeActivables {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_LISTADO_DE_ACTIVABLES_H
