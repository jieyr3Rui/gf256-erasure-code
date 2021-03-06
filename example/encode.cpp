#include <iostream>
#include <table.hpp>
#include <gf.hpp>
#include <ec.hpp>
#include <string>
using namespace std;


int main(int argc, char** argv){
    if(argc != 4){
        cout << "Usage: ./encode ./data/file/abcd 3 2" << endl;
        return 0;
    }
    // 把K转化为数字
    int n=stoi(argv[2]); assert(n>0);
    int k=stoi(argv[3]); assert(k>0);
    // 生成GF256的指数表和对数表
    get_table_256();

    EC ec;
    // 读取初始文件
    ec.read_file(argv[1], n);
    // 编码
    ec.encode(k);
    // 写入shards
    ec.write_shards("./data/shards");

    // 删除GF256的指数表和对数表
    destory_table_256();
    return 0;
}