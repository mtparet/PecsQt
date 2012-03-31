#include "images.h"

Images::Images()
{
    table = "images";
    this->listRow.insert("name","VARCHAR(255)");
    this->listRow.insert("location","VARCHAR(255)");
}


QString Images::getName() const
{
    return this->name;
}

void Images::setName(const QString &name)
{
    this->listValues.insert("name",name);
    this->name = name;
}

QString Images::getLocation() const
{
    return this->location;
}

void Images::setLocation(const QString &location)
{
    this->listValues.insert("location",location);
    this->location = location;
}

