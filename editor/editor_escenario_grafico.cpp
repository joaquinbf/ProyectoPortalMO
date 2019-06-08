#include "editor_escenario_grafico.h"
#include "editor_item_grafico.h"
#include "editor_excepcion.h"
#include "editor_defines.h"
#include "editor_bloque_de_roca.h"
#include "editor_personaje_chell.h"


#include <QGraphicsScene>
#include <QPixmap>
#include <QBrush>
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
        QGraphicsScene::mouseMoveEvent(event);
        this->moverItem(event->scenePos());
    } else {
        this->crearItem(event->scenePos());
    }
    this->spinBoxX->setValue(event->scenePos().x());
    this->spinBoxY->setValue(event->scenePos().y());

}

void EscenarioGrafico::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->crearItem(event->scenePos());
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

void EscenarioGrafico::crearItem(const QPointF posicion)
{
    if(this->idClassACrear == IDCLASS_NULL) {
        return;
    } else if(this->idClassACrear == IDCLASS_CHELL) {
        this->crearPersonaje(posicion);
    } else if(this->idClassACrear == IDCLASS_BLOQUEROCA) {
        this->crearBloqueDeRoca(posicion);
    }
}

void EscenarioGrafico::moverItem(const QPointF posicion)
{
    for(int i = 0; i < this->celdas.size(); ++i) {
        if(this->celdas[i].abandonado()) {
            if((this->getCelda(posicion)).libre()) {
                (this->getCelda(posicion)).ocupar(this->celdas[i].liberar());
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

void EscenarioGrafico::setFondoEscenario(std::string direccion,  QSize tamanio)
{
    this->fondoEscenario = direccion;
    this->tamanio = tamanio;
    QPixmap nuevoFondo(direccion.c_str());
    nuevoFondo = nuevoFondo.scaled(tamanio);
    QBrush fondo(nuevoFondo);
    this->setBackgroundBrush(fondo);
    
}

void EscenarioGrafico::setIdClassACrear(unsigned idClass)
{
    this->idClassACrear = idClass;
}

void EscenarioGrafico::crearPersonaje(QPointF posicion)
{
    PersonajeChell *personaje = new PersonajeChell(IDCOLOR_CHELL_A, "CHELL");
    this->agregarACeldas(personaje, posicion);

}

void EscenarioGrafico::crearBloqueDeRoca(QPointF posicion)
{
    BloqueDeRoca *bloque = new BloqueDeRoca();
    this->agregarACeldas(bloque, posicion);
}

CeldaGrafica &EscenarioGrafico::getCelda(QPointF posicion)
{
    int i = qFloor(posicion.x()/CELL_SIZE_W);
    int j = qFloor(posicion.y()/CELL_SIZE_H);
    int columnas = qFloor(WINDOWS_SIZE_W/CELL_SIZE_W);
    int k = columnas * j + i;
    return this->celdas[k];
}

void EscenarioGrafico::guardar(YAML::Node &nodo)
{   
    nodo["escenario"]["pathFondoEscenario"] = this->fondoEscenario;
    nodo["escenario"]["tamanioAncho"] = this->tamanio.width();
    nodo["escenario"]["tamanioAlto"] = this->tamanio.height();
}

void EscenarioGrafico::abrir(YAML::Node &nodo) {
    this->fondoEscenario = nodo["escenario"]["pathFondoEscenario"].as<std::string>();
    this->tamanio.setWidth(nodo["escenario"]["tamanioAncho"].as<int>());
    this->tamanio.setHeight(nodo["escenario"]["tamanioAlto"].as<int>());
    QPixmap nuevoFondo(this->fondoEscenario.c_str());
    nuevoFondo = nuevoFondo.scaled(this->tamanio);
    QBrush fondo(nuevoFondo);
    this->setBackgroundBrush(fondo);
}

void EscenarioGrafico::agregarACeldas(ItemGrafico *item, QPointF posicion)
{
    if(!(this->getCelda(posicion).ocupada())) {
       this->addItem(item);
       item->setPos((this->getCelda(posicion)).getPosicionRelativaEscenario());
       item->setFlag(QGraphicsItem::ItemIsMovable);
       item->setFlag(QGraphicsItem::ItemIsSelectable);
       (this->getCelda(posicion)).ocupar(item);
    } else {
       delete item;
    }
}




