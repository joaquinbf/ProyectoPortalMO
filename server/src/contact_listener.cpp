#include "../include/contact_listener.h"
#include "../include/bodies/body.h"


void ContactListener::BeginContact(b2Contact *contact) {
    Body *body = (Body *)contact->GetFixtureA()->GetBody()->GetUserData();
    Body *other_body = (Body *)contact->GetFixtureB()->GetBody()->GetUserData();
    body++;
    other_body++;
}

void ContactListener::EndContact(b2Contact *contact) {
    Body *body = (Body *)contact->GetFixtureA()->GetBody()->GetUserData();
    Body *other_body = (Body *)contact->GetFixtureB()->GetBody()->GetUserData();
    body++;
    other_body++;
}
