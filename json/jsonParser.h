#ifndef HADB_JSONPARSER_H
#define HADB_JSONPARSER_H

#include "json.hpp"

using json = nlohmann::json;

class jsonParser {
public:
    jsonParser();
    void deserializeRequest(std::string jsonString);
private:
    std::string deserializeQuery(std::string jsonString);
    std::string deserializeTableName(std::string jsonString);
    std::vector<std::string> deserializeColumns(std::string jsonString);
    std::string deserializeWhere(std::string jsonString);
    std::string deserializeEquals(std::string jsonString);
    std::string deserializePrimaryKey(std::string jsonString);
};

#endif //HADB_JSONPARSER_H