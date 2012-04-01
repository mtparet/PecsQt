#ifndef IMAGES_H
#define IMAGES_H
#include <dqmodel.h>


class Images : public DQModel
{
  DQ_MODEL
  public:
    DQField<QString> name;
    DQField<QString> image_file;
    DQField<QDateTime> creationDate;

};

/// Declare the model and the field clause
DQ_DECLARE_MODEL(Images,
                 "images", // the table name.
                 DQ_FIELD(creationDate , DQDefault("CURRENT_TIMESTAMP") ), // The default value for the field is the current timestamp
                 DQ_FIELD(name), // If no special requirement to the field , you don't need to pass the second argument
                 DQ_FIELD(image_file)
                 );

#endif // IMAGES_H
