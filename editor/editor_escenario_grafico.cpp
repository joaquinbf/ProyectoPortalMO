#include "editor_escenario_grafico.h"
#include "editor_item_grafico.h"
#include "editor_excepcion.h"
#include "editor_defines.h"
#include "editor_bloque_de_roca.h"
#include "editor_personaje_chell.h"


#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QtMath>
#include <QKeyEvent>

EscenarioGrafico::EscenarioGrafico() :
    spinBoxX(nullptr),
    spinBoxY(nullptr),
    celdas(QUANTITY_CELLS),
    idClassACrear(IDCLASS_NULL)
{
    for(int i = 0; i < this->celdas.size(); ++i) {
        this->celdas[i].setPosicion(i);
    }
}

EscenarioGrafico::~EscenarioGrafico()
{
}

void EscenarioGrafico::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton) {
        this->moverItem(event);
    } else {
        this->crearItem(event);
    }
    this->spinBoxX->setValue(event->scenePos().x());
    this->spinBoxY->setValue(event->scenePos().y());

}

void EscenarioGrafico::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->crearItem(event);
    QGraphicsScene::mousePressEvent(event);
    this->spinBoxX->setValue(event->scenePos().x());
    this->spinBoxY->setValue(event->scenePos().y());
}

void EscenarioGrafico::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Backspace) {
        while(!this->selectedItems().isEmpty()) {
            QGraphicsItem *item = this->selectedItems().front();
            ItemGrafico* itemGrafico = (this->getCelda(item->scenePos())).liberar();
            this->removeItem(this->selectedItems().front());
            delete itemGrafico;
        }
    } else {
        QGraphicsScene::keyPressEvent(event);
    }
}

void EscenarioGrafico::crearItem(QGraphicsSceneMouseEvent *event)
{
    if(this->idClassACrear == IDCLASS_NULL) {
        return;
    } else if(this->idClassACrear == IDCLASS_CHELL) {
        this->crearPersonaje(event);
    } else if(this->idClassACrear == IDCLASS_BLOQUEROCA) {
        this->crearBloqueDeRoca(event);
    }
}

void EscenarioGrafico::moverItem(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
    for(int i = 0; i < this->celdas.size(); ++i) {
        if(this->celdas[i].abandonado()) {
            if((this->getCelda(event->scenePos())).libre()) {
                (this->getCelda(event->scenePos())).ocupar(this->celdas[i].liberar());
            } else {
                this->celdas[i].recapturar();
            }
        }
    }

}

void EscenarioGrafico::setSpinBox(QSpinBox *spinBoxX_, QSpinBox *spinBoxY_)
{
    this->spinBoxX = spinBoxX_;
    this->spinBoxY = spinBoxY_;
}

void EscenarioGrafico::setFondoEscenario(std::string direccion)
{
    this->fondoEscenario = direccion;
}

void EscenarioGrafico::setIdClassACrear(unsigned idClass)
{
    this->idClassACrear = idClass;
}

void EscenarioGrafico::crearPersonaje(QGraphicsSceneMouseEvent *event)
{
    PersonajeChell *personaje = new PersonajeChell(IDCOLOR_CHELL_A, "CHELL");
    this->agregarACeldas(personaje, event);

}

void EscenarioGrafico::crearBloqueDeRoca(QGraphicsSceneMouseEvent *event)
{
    BloqueDeRoca *bloque = new BloqueDeRoca();
    this->agregarACeldas(bloque, event);
}

CeldaGrafica &EscenarioGrafico::getCelda(QPointF posicion)
{
    int i = qFloor(posicion.x()/CELL_SIZE_W);
    int j = qFloor(posicion.y()/CELL_SIZE_H);
    int columnas = qFloor(WINDOWS_SIZE_W/CELL_SIZE_W);
    int k = columnas * j + i;
    return this->celdas[k];
}

void EscenarioGrafico::guardar(/*YAML::Node &nodo*/)
{
//    nodo["pathFondoEscenario"] = this->fondoEscenario;
}

void EscenarioGrafico::agregarACeldas(ItemGrafico *item, QGraphicsSceneMouseEvent *event)
{
    if(!(this->getCelda(event->scenePos()).ocupada())) {
       this->addItem(item);
       item->setPos((this->getCelda(event->scenePos())).getPosicionRelativaEscenario());
       item->setFlag(QGraphicsItem::ItemIsMovable);
       item->setFlag(QGraphicsItem::ItemIsSelectable);
       (this->getCelda(event->scenePos())).ocupar(item);
    } else {
       delete item;
    }
}




