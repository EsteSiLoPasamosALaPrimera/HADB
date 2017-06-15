#include "RequestForm.h"

RequestForm::RequestForm() {}

void RequestForm::setQuery(std::string query) {
    this->query = query;
}

void RequestForm::setTableName(std::string tableName) {
    this->tableName = tableName;
}

void RequestForm::setWhere(std::string where) {
    this->where = where;
}

void RequestForm::setColumns(std::vector<std::string> columns) {
    this->columns = columns;
}

void RequestForm::setPrimaryKey(std::string primaryKey) {
    this->primaryKey = primaryKey;
}

void RequestForm::setEquals(std::string equals) {
    this->equals = equals;
}