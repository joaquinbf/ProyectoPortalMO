#include "../include/contact_listener.h"
#include "../include/bodies/body.h"
#include <iostream>


void ContactListener::BeginContact(b2Contact *contact) {
    std::cout << "BEGIN CONTACT" << std::endl;
    Body *body = (Body *)contact->GetFixtureA()->GetBody()->GetUserData();
    Body *other_body = (Body *)contact->GetFixtureB()->GetBody()->GetUserData();
    body->handleBeginContactWith(other_body);
}

void ContactListener::EndContact(b2Contact *contact) {
    Body *body = (Body *)contact->GetFixtureA()->GetBody()->GetUserData();
    Body *other_body = (Body *)contact->GetFixtureB()->GetBody()->GetUserData();
    body++;
    other_body++;
}
