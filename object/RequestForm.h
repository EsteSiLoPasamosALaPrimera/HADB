#ifndef HADB_QUERYFORM_H
#define HADB_QUERYFORM_H

#include <string>
#include <vector>

class RequestForm {
private:
    std::string query;
    std::string tableName;
    std::string where;
    std::string equals;
    std::vector<std::string> columns;
    std::string primaryKey;
public:
    RequestForm();
    void setQuery(std::string query);
    void setTableName(std::string tableName);
    void setWhere(std::string where);
    void setColumns(std::vector<std::string> columns);
    void setPrimaryKey(std::string primaryKey);
    void setEquals(std::string  equals);
};

#endif //HADB_QUERYFORM_H