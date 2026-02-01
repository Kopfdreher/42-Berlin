#include <string>

class Zombie {

public:
  Zombie(std::string _name);
  ~Zombie();

  void announce(void);

private:
  std::string _name;

  Zombie();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);
