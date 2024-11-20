#include "frontend.h"
#include "backend.h"

int main(void)
{
    while (1)
    {
        set_up_console();
        run_game();
    }
    
    return 0;
}