#include "model.h"
#include "database.h"

Model::Model()
{
}

bool Model::save(){
    Database *db = new Database();
    db->insert(this->listValues,this->table);
}

bool Model::remove(){

}
