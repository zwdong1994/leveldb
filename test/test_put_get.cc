//
// Created by victor on 11/29/17.
//

#include "leveldb/db.h"
#include <iostream>
#include <string>
#include <assert.h>

using namespace leveldb;

int main(){
    DB *db;
    Options options;
    options.create_if_missing = true;

    Status status = DB::Open(options, "./test", &db);
    assert(status.ok());

    std::string key = "name1";
    std::string value = "zwd1";
    std::string find_key = "name1";
    std::string get_value;

    status = db -> Put(WriteOptions(), key, value);
    assert(status.ok());

    status = db -> Get(ReadOptions(), find_key, &get_value);
    if(!status.ok()) {
        std::cerr<<key<<"    "<<status.ToString()<<std::endl;
    } else {
        std::cout<<key<<"==="<<get_value<<std::endl;
    }
    getchar();
    delete db;
    return 0;
}