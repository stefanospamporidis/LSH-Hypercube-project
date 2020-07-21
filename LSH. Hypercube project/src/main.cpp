#include "CMDParser.hpp"
#include <string>
#include <iostream>


int main(int argc, char **argv) {
    CMDParser cmd_p ;
    std::string input ;
    std::string config ;
    std::string output ;
    cmd_p.getArgs(argc,argv,input,config,output);
    std::cout << input << " " << config << " " << output << "\n" ;
    return 0;
}
