#include <iostream>

class Distance {
private:
  long double m_Kilometers;
public:
  Distance(long double km) :m_Kilometers{km} {

  }
  long double GetKm()const {
    return m_Kilometers;
  }
  void SetKm(long double val){
    m_Kilometers = val;
  }
};

Distance operator"" _mi(long double val){
  return Distance{ val * 1.6 };
}

int main() {
  using namespace std;
  Distance dist{32.0_mi};
  std::cout << dist.GetKm() << std::endl;
  return 0;
}