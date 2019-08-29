
#include "dminja.h"

int main( int argc, char* argv[] ) {

    Idminja* module = dminjaGetModule();
    if (module)
    {
        module->Test();
        module->Release();
    }
    return 0;
}
