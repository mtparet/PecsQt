#ifndef IMAGES_H
#define IMAGES_H
#include <QObject>
#include <QList>
#include <model.h>


class Images : public Model
{

  public:
      Images();
      QString getName() const;
      void setName(const QString &name);

      QString getLocation() const;
      void setLocation(const QString &location);

  private:
      QString name;
      QString location;
};

#endif // IMAGES_H
