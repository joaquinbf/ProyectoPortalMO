/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNuevo_Escenario;
    QAction *actionAbrir_Escenario;
    QAction *actionGuardar_Escenario;
    QAction *actionBloque_de_Roca;
    QAction *actionBloque_de_Metal;
    QAction *actionBloque_de_Metal_en_Diagonal;
    QAction *actionAcido;
    QAction *actionBoton;
    QAction *actionRoca;
    QAction *actionEmisor_de_Energia;
    QAction *actionReceptor_de_Energia;
    QAction *actionPersonaje;
    QAction *actionFondo;
    QAction *actionBloqueOriginal;
    QAction *actionBloqueRotado_90;
    QAction *actionBloqueRotado_180;
    QAction *actionBloqueRotado_270;
    QAction *actionEmisorOriginal;
    QAction *actionEmisor_Rotado_90;
    QAction *actionEmisor_Rotado_180;
    QAction *actionEmisor_Rotado_270;
    QAction *actionReceptor_Original;
    QAction *actionReceptor_Rotado_180;
    QAction *actionReceptor_Rotado_270;
    QAction *actionCompuerta_Regular;
    QAction *actionCompuerta_AND;
    QAction *actionCompuerta_OR;
    QAction *actionBarrera_Horizontal;
    QAction *actionBarrera_Vertical;
    QAction *actionReceptor_Rotado_90;
    QAction *actionPastel;
    QAction *actionConfiguracion_de_Compuertas;
    QAction *actionConfiguracion_de_Personajes;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBoxX;
    QLabel *label_2;
    QSpinBox *spinBoxY;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QMenu *menuEscenario;
    QMenu *menuInsertar;
    QMenu *menuBloque;
    QMenu *menuBloque_de_Metal_Diagonal;
    QMenu *menuEmisor_de_Energia;
    QMenu *menuReceptor_de_Energia;
    QMenu *menuCompuerta;
    QMenu *menuBarrera_de_Energia;
    QMenu *menuHerramientas;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(978, 590);
        actionNuevo_Escenario = new QAction(MainWindow);
        actionNuevo_Escenario->setObjectName(QStringLiteral("actionNuevo_Escenario"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/nuevo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNuevo_Escenario->setIcon(icon);
        actionAbrir_Escenario = new QAction(MainWindow);
        actionAbrir_Escenario->setObjectName(QStringLiteral("actionAbrir_Escenario"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/resources/abrir.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbrir_Escenario->setIcon(icon1);
        actionGuardar_Escenario = new QAction(MainWindow);
        actionGuardar_Escenario->setObjectName(QStringLiteral("actionGuardar_Escenario"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/resources/guardar.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGuardar_Escenario->setIcon(icon2);
        actionBloque_de_Roca = new QAction(MainWindow);
        actionBloque_de_Roca->setObjectName(QStringLiteral("actionBloque_de_Roca"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/resources/bloqueRoca.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBloque_de_Roca->setIcon(icon3);
        actionBloque_de_Metal = new QAction(MainWindow);
        actionBloque_de_Metal->setObjectName(QStringLiteral("actionBloque_de_Metal"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/resources/bloqueMetal.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBloque_de_Metal->setIcon(icon4);
        actionBloque_de_Metal_en_Diagonal = new QAction(MainWindow);
        actionBloque_de_Metal_en_Diagonal->setObjectName(QStringLiteral("actionBloque_de_Metal_en_Diagonal"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/resources/bloquesMetalDiagonal.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBloque_de_Metal_en_Diagonal->setIcon(icon5);
        actionAcido = new QAction(MainWindow);
        actionAcido->setObjectName(QStringLiteral("actionAcido"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/resources/acido2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAcido->setIcon(icon6);
        actionBoton = new QAction(MainWindow);
        actionBoton->setObjectName(QStringLiteral("actionBoton"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/resources/boton.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBoton->setIcon(icon7);
        actionRoca = new QAction(MainWindow);
        actionRoca->setObjectName(QStringLiteral("actionRoca"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/resources/roca1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRoca->setIcon(icon8);
        actionEmisor_de_Energia = new QAction(MainWindow);
        actionEmisor_de_Energia->setObjectName(QStringLiteral("actionEmisor_de_Energia"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/resources/emisorEnergia.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEmisor_de_Energia->setIcon(icon9);
        actionReceptor_de_Energia = new QAction(MainWindow);
        actionReceptor_de_Energia->setObjectName(QStringLiteral("actionReceptor_de_Energia"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/resources/receptorEnergia.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReceptor_de_Energia->setIcon(icon10);
        actionPersonaje = new QAction(MainWindow);
        actionPersonaje->setObjectName(QStringLiteral("actionPersonaje"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/resources/shell.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPersonaje->setIcon(icon11);
        actionFondo = new QAction(MainWindow);
        actionFondo->setObjectName(QStringLiteral("actionFondo"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/resources/fond.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFondo->setIcon(icon12);
        actionBloqueOriginal = new QAction(MainWindow);
        actionBloqueOriginal->setObjectName(QStringLiteral("actionBloqueOriginal"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/resources/bloquesMetalDiagonal0.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBloqueOriginal->setIcon(icon13);
        actionBloqueRotado_90 = new QAction(MainWindow);
        actionBloqueRotado_90->setObjectName(QStringLiteral("actionBloqueRotado_90"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/resources/bloquesMetalDiagonal90.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBloqueRotado_90->setIcon(icon14);
        actionBloqueRotado_180 = new QAction(MainWindow);
        actionBloqueRotado_180->setObjectName(QStringLiteral("actionBloqueRotado_180"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/resources/bloquesMetalDiagonal180.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBloqueRotado_180->setIcon(icon15);
        actionBloqueRotado_270 = new QAction(MainWindow);
        actionBloqueRotado_270->setObjectName(QStringLiteral("actionBloqueRotado_270"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/resources/bloquesMetalDiagonal270.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBloqueRotado_270->setIcon(icon16);
        actionEmisorOriginal = new QAction(MainWindow);
        actionEmisorOriginal->setObjectName(QStringLiteral("actionEmisorOriginal"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/resources/emisorEnergia0.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEmisorOriginal->setIcon(icon17);
        actionEmisor_Rotado_90 = new QAction(MainWindow);
        actionEmisor_Rotado_90->setObjectName(QStringLiteral("actionEmisor_Rotado_90"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/resources/emisorEnergia90.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEmisor_Rotado_90->setIcon(icon18);
        actionEmisor_Rotado_180 = new QAction(MainWindow);
        actionEmisor_Rotado_180->setObjectName(QStringLiteral("actionEmisor_Rotado_180"));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/resources/emisorEnergia180.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEmisor_Rotado_180->setIcon(icon19);
        actionEmisor_Rotado_270 = new QAction(MainWindow);
        actionEmisor_Rotado_270->setObjectName(QStringLiteral("actionEmisor_Rotado_270"));
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/resources/emisorEnergia270.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEmisor_Rotado_270->setIcon(icon20);
        actionReceptor_Original = new QAction(MainWindow);
        actionReceptor_Original->setObjectName(QStringLiteral("actionReceptor_Original"));
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/resources/receptorEnergia0.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReceptor_Original->setIcon(icon21);
        actionReceptor_Rotado_180 = new QAction(MainWindow);
        actionReceptor_Rotado_180->setObjectName(QStringLiteral("actionReceptor_Rotado_180"));
        QIcon icon22;
        icon22.addFile(QStringLiteral(":/resources/receptorEnergia180.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReceptor_Rotado_180->setIcon(icon22);
        actionReceptor_Rotado_270 = new QAction(MainWindow);
        actionReceptor_Rotado_270->setObjectName(QStringLiteral("actionReceptor_Rotado_270"));
        QIcon icon23;
        icon23.addFile(QStringLiteral(":/resources/receptorEnergia270.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReceptor_Rotado_270->setIcon(icon23);
        actionCompuerta_Regular = new QAction(MainWindow);
        actionCompuerta_Regular->setObjectName(QStringLiteral("actionCompuerta_Regular"));
        QIcon icon24;
        icon24.addFile(QStringLiteral(":/resources/compuerta1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCompuerta_Regular->setIcon(icon24);
        actionCompuerta_AND = new QAction(MainWindow);
        actionCompuerta_AND->setObjectName(QStringLiteral("actionCompuerta_AND"));
        QIcon icon25;
        icon25.addFile(QStringLiteral(":/resources/compuerta2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCompuerta_AND->setIcon(icon25);
        actionCompuerta_OR = new QAction(MainWindow);
        actionCompuerta_OR->setObjectName(QStringLiteral("actionCompuerta_OR"));
        QIcon icon26;
        icon26.addFile(QStringLiteral(":/resources/compuerta3.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCompuerta_OR->setIcon(icon26);
        actionBarrera_Horizontal = new QAction(MainWindow);
        actionBarrera_Horizontal->setObjectName(QStringLiteral("actionBarrera_Horizontal"));
        QIcon icon27;
        icon27.addFile(QStringLiteral(":/resources/barreraDeEnergiaHorizontal.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBarrera_Horizontal->setIcon(icon27);
        actionBarrera_Vertical = new QAction(MainWindow);
        actionBarrera_Vertical->setObjectName(QStringLiteral("actionBarrera_Vertical"));
        QIcon icon28;
        icon28.addFile(QStringLiteral(":/resources/barreraDeEnergiaVertical.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBarrera_Vertical->setIcon(icon28);
        actionReceptor_Rotado_90 = new QAction(MainWindow);
        actionReceptor_Rotado_90->setObjectName(QStringLiteral("actionReceptor_Rotado_90"));
        QIcon icon29;
        icon29.addFile(QStringLiteral(":/resources/receptorEnergia90.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReceptor_Rotado_90->setIcon(icon29);
        actionPastel = new QAction(MainWindow);
        actionPastel->setObjectName(QStringLiteral("actionPastel"));
        QIcon icon30;
        icon30.addFile(QStringLiteral(":/resources/cake.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPastel->setIcon(icon30);
        actionConfiguracion_de_Compuertas = new QAction(MainWindow);
        actionConfiguracion_de_Compuertas->setObjectName(QStringLiteral("actionConfiguracion_de_Compuertas"));
        QIcon icon31;
        icon31.addFile(QStringLiteral(":/resources/configuracionCompuertas.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfiguracion_de_Compuertas->setIcon(icon31);
        actionConfiguracion_de_Personajes = new QAction(MainWindow);
        actionConfiguracion_de_Personajes->setObjectName(QStringLiteral("actionConfiguracion_de_Personajes"));
        actionConfiguracion_de_Personajes->setIcon(icon31);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMouseTracking(false);
        graphicsView->setTabletTracking(false);
        graphicsView->setFocusPolicy(Qt::StrongFocus);
        graphicsView->setAcceptDrops(false);
        graphicsView->setAutoFillBackground(true);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        graphicsView->setInteractive(true);
        graphicsView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        graphicsView->setDragMode(QGraphicsView::NoDrag);

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBoxX = new QSpinBox(centralWidget);
        spinBoxX->setObjectName(QStringLiteral("spinBoxX"));

        horizontalLayout->addWidget(spinBoxX);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBoxY = new QSpinBox(centralWidget);
        spinBoxY->setObjectName(QStringLiteral("spinBoxY"));

        horizontalLayout->addWidget(spinBoxY);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 978, 22));
        menuEscenario = new QMenu(menuBar);
        menuEscenario->setObjectName(QStringLiteral("menuEscenario"));
        menuInsertar = new QMenu(menuBar);
        menuInsertar->setObjectName(QStringLiteral("menuInsertar"));
        menuBloque = new QMenu(menuInsertar);
        menuBloque->setObjectName(QStringLiteral("menuBloque"));
        menuBloque_de_Metal_Diagonal = new QMenu(menuBloque);
        menuBloque_de_Metal_Diagonal->setObjectName(QStringLiteral("menuBloque_de_Metal_Diagonal"));
        menuEmisor_de_Energia = new QMenu(menuInsertar);
        menuEmisor_de_Energia->setObjectName(QStringLiteral("menuEmisor_de_Energia"));
        menuReceptor_de_Energia = new QMenu(menuInsertar);
        menuReceptor_de_Energia->setObjectName(QStringLiteral("menuReceptor_de_Energia"));
        menuCompuerta = new QMenu(menuInsertar);
        menuCompuerta->setObjectName(QStringLiteral("menuCompuerta"));
        menuBarrera_de_Energia = new QMenu(menuInsertar);
        menuBarrera_de_Energia->setObjectName(QStringLiteral("menuBarrera_de_Energia"));
        menuHerramientas = new QMenu(menuBar);
        menuHerramientas->setObjectName(QStringLiteral("menuHerramientas"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuEscenario->menuAction());
        menuBar->addAction(menuInsertar->menuAction());
        menuBar->addAction(menuHerramientas->menuAction());
        menuEscenario->addAction(actionNuevo_Escenario);
        menuEscenario->addAction(actionAbrir_Escenario);
        menuEscenario->addAction(actionGuardar_Escenario);
        menuInsertar->addAction(menuBloque->menuAction());
        menuInsertar->addAction(menuEmisor_de_Energia->menuAction());
        menuInsertar->addAction(menuReceptor_de_Energia->menuAction());
        menuInsertar->addAction(menuCompuerta->menuAction());
        menuInsertar->addAction(menuBarrera_de_Energia->menuAction());
        menuInsertar->addAction(actionBoton);
        menuInsertar->addAction(actionRoca);
        menuInsertar->addAction(actionPersonaje);
        menuInsertar->addAction(actionFondo);
        menuBloque->addAction(actionBloque_de_Roca);
        menuBloque->addAction(actionBloque_de_Metal);
        menuBloque->addAction(menuBloque_de_Metal_Diagonal->menuAction());
        menuBloque_de_Metal_Diagonal->addAction(actionBloqueOriginal);
        menuBloque_de_Metal_Diagonal->addAction(actionBloqueRotado_90);
        menuBloque_de_Metal_Diagonal->addAction(actionBloqueRotado_180);
        menuBloque_de_Metal_Diagonal->addAction(actionBloqueRotado_270);
        menuEmisor_de_Energia->addAction(actionEmisorOriginal);
        menuEmisor_de_Energia->addAction(actionEmisor_Rotado_90);
        menuEmisor_de_Energia->addAction(actionEmisor_Rotado_180);
        menuEmisor_de_Energia->addAction(actionEmisor_Rotado_270);
        menuReceptor_de_Energia->addAction(actionReceptor_Original);
        menuReceptor_de_Energia->addAction(actionReceptor_Rotado_90);
        menuReceptor_de_Energia->addAction(actionReceptor_Rotado_180);
        menuReceptor_de_Energia->addAction(actionReceptor_Rotado_270);
        menuCompuerta->addAction(actionCompuerta_Regular);
        menuCompuerta->addAction(actionCompuerta_AND);
        menuCompuerta->addAction(actionCompuerta_OR);
        menuBarrera_de_Energia->addAction(actionBarrera_Horizontal);
        menuBarrera_de_Energia->addAction(actionBarrera_Vertical);
        menuHerramientas->addAction(actionConfiguracion_de_Compuertas);
        menuHerramientas->addAction(actionConfiguracion_de_Personajes);
        mainToolBar->addAction(actionPersonaje);
        mainToolBar->addAction(actionFondo);
        mainToolBar->addAction(actionPastel);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionBloque_de_Roca);
        mainToolBar->addAction(actionBloque_de_Metal);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionBloqueOriginal);
        mainToolBar->addAction(actionBloqueRotado_90);
        mainToolBar->addAction(actionBloqueRotado_180);
        mainToolBar->addAction(actionBloqueRotado_270);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionEmisorOriginal);
        mainToolBar->addAction(actionEmisor_Rotado_90);
        mainToolBar->addAction(actionEmisor_Rotado_180);
        mainToolBar->addAction(actionEmisor_Rotado_270);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionReceptor_Original);
        mainToolBar->addAction(actionReceptor_Rotado_90);
        mainToolBar->addAction(actionReceptor_Rotado_180);
        mainToolBar->addAction(actionReceptor_Rotado_270);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCompuerta_Regular);
        mainToolBar->addAction(actionCompuerta_AND);
        mainToolBar->addAction(actionCompuerta_OR);
        mainToolBar->addSeparator();
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionBarrera_Horizontal);
        mainToolBar->addAction(actionBarrera_Vertical);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionBoton);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRoca);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Editor de Escenarios", Q_NULLPTR));
        actionNuevo_Escenario->setText(QApplication::translate("MainWindow", "Nuevo Escenario", Q_NULLPTR));
        actionAbrir_Escenario->setText(QApplication::translate("MainWindow", "Abrir Escenario", Q_NULLPTR));
        actionGuardar_Escenario->setText(QApplication::translate("MainWindow", "Guardar Escenario", Q_NULLPTR));
        actionBloque_de_Roca->setText(QApplication::translate("MainWindow", "Bloque de Roca", Q_NULLPTR));
        actionBloque_de_Metal->setText(QApplication::translate("MainWindow", "Bloque de Metal", Q_NULLPTR));
        actionBloque_de_Metal_en_Diagonal->setText(QApplication::translate("MainWindow", "Bloque de Metal en Diagonal", Q_NULLPTR));
        actionAcido->setText(QApplication::translate("MainWindow", "Acido", Q_NULLPTR));
        actionBoton->setText(QApplication::translate("MainWindow", "Boton", Q_NULLPTR));
        actionRoca->setText(QApplication::translate("MainWindow", "Roca", Q_NULLPTR));
        actionEmisor_de_Energia->setText(QApplication::translate("MainWindow", "Emisor de Energia", Q_NULLPTR));
        actionReceptor_de_Energia->setText(QApplication::translate("MainWindow", "Receptor de Energia", Q_NULLPTR));
        actionPersonaje->setText(QApplication::translate("MainWindow", "Personaje", Q_NULLPTR));
        actionFondo->setText(QApplication::translate("MainWindow", "Fondo Nuevo", Q_NULLPTR));
        actionBloqueOriginal->setText(QApplication::translate("MainWindow", "Bloque Original", Q_NULLPTR));
        actionBloqueRotado_90->setText(QApplication::translate("MainWindow", "Bloque Rotado 90\302\260", Q_NULLPTR));
        actionBloqueRotado_180->setText(QApplication::translate("MainWindow", "Bloque Rotado 180\302\260", Q_NULLPTR));
        actionBloqueRotado_270->setText(QApplication::translate("MainWindow", "Bloque Rotado 270\302\260", Q_NULLPTR));
        actionEmisorOriginal->setText(QApplication::translate("MainWindow", "Emisor Original", Q_NULLPTR));
        actionEmisor_Rotado_90->setText(QApplication::translate("MainWindow", "Emisor Rotado 90\302\260", Q_NULLPTR));
        actionEmisor_Rotado_180->setText(QApplication::translate("MainWindow", "Emisor Rotado 180\302\260", Q_NULLPTR));
        actionEmisor_Rotado_270->setText(QApplication::translate("MainWindow", "Emisor Rotado 270\302\260", Q_NULLPTR));
        actionReceptor_Original->setText(QApplication::translate("MainWindow", "Receptor Original", Q_NULLPTR));
        actionReceptor_Rotado_180->setText(QApplication::translate("MainWindow", "Receptor Rotado 180\302\260", Q_NULLPTR));
        actionReceptor_Rotado_270->setText(QApplication::translate("MainWindow", "Receptor Rotado 270\302\260", Q_NULLPTR));
        actionCompuerta_Regular->setText(QApplication::translate("MainWindow", "Compuerta Regular", Q_NULLPTR));
        actionCompuerta_AND->setText(QApplication::translate("MainWindow", "Compuerta AND", Q_NULLPTR));
        actionCompuerta_OR->setText(QApplication::translate("MainWindow", "Compuerta OR", Q_NULLPTR));
        actionBarrera_Horizontal->setText(QApplication::translate("MainWindow", "Barrera Horizontal", Q_NULLPTR));
        actionBarrera_Vertical->setText(QApplication::translate("MainWindow", "Barrera Vertical", Q_NULLPTR));
        actionReceptor_Rotado_90->setText(QApplication::translate("MainWindow", "Receptor Rotado 90\302\260", Q_NULLPTR));
        actionPastel->setText(QApplication::translate("MainWindow", "Pastel", Q_NULLPTR));
        actionConfiguracion_de_Compuertas->setText(QApplication::translate("MainWindow", "Configuracion de Compuertas", Q_NULLPTR));
        actionConfiguracion_de_Personajes->setText(QApplication::translate("MainWindow", "Configuracion de Personajes", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        graphicsView->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        graphicsView->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        graphicsView->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("MainWindow", "x:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "y:", Q_NULLPTR));
        menuEscenario->setTitle(QApplication::translate("MainWindow", "Escenario", Q_NULLPTR));
        menuInsertar->setTitle(QApplication::translate("MainWindow", "Insertar", Q_NULLPTR));
        menuBloque->setTitle(QApplication::translate("MainWindow", "Bloque", Q_NULLPTR));
        menuBloque_de_Metal_Diagonal->setTitle(QApplication::translate("MainWindow", "Bloque de Metal Diagonal", Q_NULLPTR));
        menuEmisor_de_Energia->setTitle(QApplication::translate("MainWindow", "Emisor de Energia", Q_NULLPTR));
        menuReceptor_de_Energia->setTitle(QApplication::translate("MainWindow", "Receptor de Energia ", Q_NULLPTR));
        menuCompuerta->setTitle(QApplication::translate("MainWindow", "Compuerta", Q_NULLPTR));
        menuBarrera_de_Energia->setTitle(QApplication::translate("MainWindow", "Barrera de Energia", Q_NULLPTR));
        menuHerramientas->setTitle(QApplication::translate("MainWindow", "Herramientas", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
