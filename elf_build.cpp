#include <elf.h>
#include <fstream>
#include <iostream>

using namespace std;

class ELF_Write {
 public:
  ELF_Write() = default;
  ~ELF_Write() = default;

  void Init(std::string &name);
  void Finish();
 private:
  ofstream *output = nullptr;
};

void ELF_Write::Init(std::string &name) 
{
  output = new ofstream(name, ios::out | ios::binary);
  if (output != nullptr) {
    std::cout << "create binary.out success !\n";
  } else {
    std::cout << "create binary.out failed !\n";
  }
}

void ELF_Write::Finish() 
{
  if (output != nullptr) {
    delete output;
	output = nullptr;
  }
}

int main()
{
  ELF_Write elf_write;
  std::string fileName = "binary.out";
  elf_write.Init(fileName);

  std::cout << "the end!!\n";
  elf_write.Finish();
  return 0;
}
