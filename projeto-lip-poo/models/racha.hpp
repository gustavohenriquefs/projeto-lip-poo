#include <string>
#include <vector>
#include "time.hpp"

// A principal funcionalidade é montar um racha, que é composto por uma data, local,
// alocação dos times e um placar do racha (quantas vitórias cada time obteve).
class Racha
{
  private:
    
    std::string data;

    std::string local;
    
    std::vector<Time> times;

  public:
    
    Racha(std::string data, std::string local, std::vector<Time> times);
    
    ~Racha();

    void setData(std::string data);

    std::string getData();

    void setLocal(std::string local);

    std::string getLocal();

    std::vector<Time> getTimes();

    void setTimes(std::vector<Time> time);
};