#ifndef EDITOR_ESCENARIO_GRAFICO_H
#define EDITOR_ESCENARIO_GRAFICO_H

#include <QGraphicsScene>
#include <QSpinBox>
#include <string>
#include <QVector>
#include <QSize>
#include "yaml-cpp/yaml.h"
#include "editor_item_grafico.h"
#include "editor_celda_grafica.h"

class EscenarioGrafico : public QGraphicsScene
{
private:
    QSpinBox *spinBoxX;
    QSpinBox *spinBoxY;

    std::string fondoEscenario;

    QVector<CeldaGrafica> celdas;
    QSize tamanio;

    unsigned idClassACrear;

public:
    EscenarioGrafico();
    virtual ~EscenarioGrafico();
    //void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

    void setSpinBox(QSpinBox *spinBoxX_, QSpinBox *spinBoxY_);
    void setFondoEscenario(std::string direccion, QSize tamanio);
    void setIdClassACrear(unsigned idClass);

    void agregarACeldas(ItemGrafico *item, QPointF posicion);
    void moverItem(QPointF posicion);
    void crearItem(QPointF posicion);
    void crearPersonaje(QPointF posicion);
    void crearBloqueDeRoca(QPointF posicion);



    CeldaGrafica &getCelda(QPointF posicion);

    void guardar(YAML::Node &nodo);
    void abrir(YAML::Node &nodo);


};

#endif // EDITOR_ESCENARIO_GRAFICO_H
