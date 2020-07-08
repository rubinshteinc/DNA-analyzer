#include "app.h"
#include "I_O/input_data.h"
#include "I_O/output_data.h"
int main() {
    ConsuleWriter pw;
    ConsuleReader pr;
    App process(&pr, &pw);
    process.start();
        return 0;
}