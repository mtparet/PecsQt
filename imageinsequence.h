#ifndef IMAGEINSEQUENCE_H
#define IMAGEINSEQUENCE_H
#include <dqmodel.h>
#include <images.h>

class ImageInSequence: public DQModel
{
  DQ_MODEL
  public:
  DQField<int> orderIn;
  DQField<QDateTime> creationDate;

  DQForeignKey<Images> a;
};

/// Declare the model and the field clause
DQ_DECLARE_MODEL(ImageInSequence,
                 "imageinsequence", // the table name.
                 DQ_FIELD(a , DQNotNull ),
                 DQ_FIELD(creationDate , DQDefault("CURRENT_TIMESTAMP") ), // The default value for the field is the current timestamp
                 DQ_FIELD(orderIn)
                 );

#endif // IMAGEINSEQUENCE_H
