#include <iostream>
#include "AddressBook.h"
#include "Friend.h"
#include "Colleague.h"
#include "Acquaintance.h"
int main()
{
    AddressBook s;
    s.add(new Friend("Ion", "9.11.2000", "0745666789", "Iasi?")).add(new Friend("jon", "31.2.2000", "0745888789", "Boston City"));
    s.add(new Acquaintance("Alex Vulcanizare", "1234567899")).add(new Colleague("Hatz jon", "Bucaresti", "3950275932", "Somer"));
    s.friends();
    s.search("jon");
    s.delet("Ion");
    printf("\n");
    s.friends();
    return 0;
}
