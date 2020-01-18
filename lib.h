#include <fstream>

const int SIZE=7;

int read_file(std::ifstream &file, int a[SIZE][SIZE],std::string ver[SIZE]);
int minway(int a[SIZE][SIZE],std::string start,std::string final,std::string ver[SIZE]);