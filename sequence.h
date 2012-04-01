#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <dqmodel.h>
#include <imageinsequence.h>
#include <QMap>

class Sequence : public DQModel
{
    DQ_MODEL
public:
      DQField<QString> name;
      DQField<QDateTime> creationDate;
      void addImageInSequence(ImageInSequence is);
      QList<DQForeignKey<ImageInSequence>*> getListImageInSequence();

private:
      QList<DQForeignKey<ImageInSequence>* > listIs;
      bool initIs();
      DQForeignKey<ImageInSequence> is1;
      DQForeignKey<ImageInSequence> is2;
      DQForeignKey<ImageInSequence> is3;
      DQForeignKey<ImageInSequence> is4;
      DQForeignKey<ImageInSequence> is5;
      DQForeignKey<ImageInSequence> is6;
      DQForeignKey<ImageInSequence> is7;
      DQForeignKey<ImageInSequence> is8;
      DQForeignKey<ImageInSequence> is9;
      DQForeignKey<ImageInSequence> is10;
      DQForeignKey<ImageInSequence> is11;
      DQForeignKey<ImageInSequence> is12;
      DQForeignKey<ImageInSequence> is13;

  };

  /// Declare the model and the field clause
  DQ_DECLARE_MODEL(Sequence,
                   "sequence", // the table name.
                   DQ_FIELD(creationDate , DQDefault("CURRENT_TIMESTAMP") ), // The default value for the field is the current timestamp
                   DQ_FIELD(name), // If no special requirement to the field , you don't need to pass the second argument
                   DQ_FIELD(is1 , DQNotNull ),
                   DQ_FIELD(is2 , DQNotNull ),
                   DQ_FIELD(is3 , DQNotNull ),
                   DQ_FIELD(is4 , DQNotNull ),
                   DQ_FIELD(is5 , DQNotNull ),
                   DQ_FIELD(is6 , DQNotNull ),
                   DQ_FIELD(is7 , DQNotNull ),
                   DQ_FIELD(is8 , DQNotNull ),
                   DQ_FIELD(is9 , DQNotNull ),
                   DQ_FIELD(is10 , DQNotNull ),
                   DQ_FIELD(is11 , DQNotNull ),
                   DQ_FIELD(is12 , DQNotNull ),
                   DQ_FIELD(is13 , DQNotNull )
                   );
#endif // SEQUENCE_H
