#ifndef __PORTAL_GUN_H__
#define __PORTAL_GUN_H__

class Portal;
class Chell;

class PortalGun {
private:
    Chell *chell;
    Portal *portal_one;
    Portal *portal_two;

public:
    /* Instancia una portal gun para chell */
    PortalGun(Chell *chell);

    /* Libera los recursos utilizados */
    ~PortalGun();

    /* Devuelve un puntero al primer portal */
    Portal *getPortalOne() const;

    /* Devuelve un puntero al segundo portal */
    Portal *getPortalTwo() const;

    /* Dispara el primer portal a (x, y) */
    void firePortalOne(float x, float y);

    /* Dispara el segundo portal a (x, y) */
    void firePortalTwo(float x, float y);

private:
    /* Destruye un portal */
    void destroyPortal(Portal *&portal);
};

#endif
