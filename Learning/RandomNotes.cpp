#include <iostream>
#include <ostream>

int main(int argc, char* argv[])
{
  // argumenti u endl specifiraju o kojem se streamu radi, po default-u je cout
  // std::endl(basic_ostream<CharT, Traits> &os);

  // takodjer, razlika izmedju dvije linije ispod je u tome sto endl flush-a stream
  // i detektuje o kakvom se uredjaju radi te dodaje korespondni end line karakter(e)
  // npr mozda umjesto \n treba \r\n, on detekruje koji treba i doda ga
  std::cout << '\n';
  std::cout << std::endl;

  return 0;
}
