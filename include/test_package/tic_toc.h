#include <ctime>
#include <cstdlib>
#include <chrono>

class TicToc
{
  public:
    
    void tic();
    double toc();

  private:
    std::chrono::time_point<std::chrono::system_clock> start, end;
};