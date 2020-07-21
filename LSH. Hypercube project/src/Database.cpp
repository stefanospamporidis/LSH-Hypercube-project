//
//  Database.cpp
//  Project-Cluster
//
//  Created by <author> on 18/11/2019.
//
//

#include "Database.hpp"

Database::Database()  {}
void Database::addItem(Item *t) {
    int index = items.size() ; // We get the index of where  the item will be added
    items.push_back(t);
    map.insert(std::pair<string,int> (t->getId(),index));
}
Item * Database::getItem(std::string qid) {
    int index = map[qid];
    return items[index];
}
Item * Database::getItem(int qind) {
    return items[qind];
}
int Database::getSize(void) {
    return items.size();
}
int Database::getDimensions(void) {
    return items[0]->getDimension();
}
Database::~Database() {
    for (size_t i = 0; i < items.size(); i++) {
        delete items[i] ;
    }
}
