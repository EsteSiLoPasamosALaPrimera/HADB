#include "jsonParser.h"
#include "../object/RequestForm.h"

void jsonParser::deserializeRequest(std::string jsonString) {
    RequestForm* requestForm = new RequestForm();
    std::string query = deserializeQuery(jsonString);
    requestForm->setQuery(query);
    requestForm->setTableName(deserializeTableName(jsonString));
    if(query == "create table") {
        requestForm->setColumns(deserializeColumns(jsonString));
        requestForm->setPrimaryKey(deserializePrimaryKey(jsonString));
    }
    else if(query == "select" || query == "update") {
        requestForm->setColumns(deserializeColumns(jsonString));
        requestForm->setWhere(deserializeWhere(jsonString));
        requestForm->setEquals(deserializeEquals(jsonString));
    }
    else if(query == "select join") {

    }
    else if(query == "insert") {
        requestForm->setColumns(deserializeColumns(jsonString));
    }

    else if(query == "delete") {
        requestForm->setWhere(deserializeWhere(jsonString));
        requestForm->setEquals(deserializeEquals(jsonString));
    }
}

std::string jsonParser::deserializeQuery(std::string jsonString) {
    json jsonQuery = json::parse(jsonString);
    std::string query = jsonQuery["query"].get<std::string>();
    return query;
}

std::string jsonParser::deserializeTableName(std::string jsonString) {
    json jsonTableName = json::parse(jsonString);
    std::string tableName = jsonTableName["table name"].get<std::string>();
    return tableName;
}

std::vector<std::string> jsonParser::deserializeColumns(std::string jsonString) {
    std::vector<std::string> columns;
    json jsonObject = json::parse(jsonString);
    for (json::iterator iterator = jsonObject.begin(); iterator != jsonObject.end(); ++iterator) {
        std::cout << *iterator << '\n';//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<eliminar
        columns.emplace_back(iterator.value().dump());
    }
    return columns;
}

std::string jsonParser::deserializeWhere(std::string jsonString) {
    json jsonWhere = json::parse(jsonString);
    std::string query = jsonWhere["where"].get<std::string>();
    return query;
}

std::string jsonParser::deserializeEquals(std::string jsonString) {
    json jsonEquals = json::parse(jsonString);
    std::string equals = jsonEquals["equals"].get<std::string>();
    return equals;
}

std::string jsonParser::deserializePrimaryKey(std::string jsonString) {
    json jsonPrimaryKey = json::parse(jsonString);
    std::string primaryKey = jsonPrimaryKey["primary key"].get<std::string>();
    return primaryKey;
}