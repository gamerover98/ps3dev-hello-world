#include <cstdio>
#include <cstdlib>

#include <io/pad.h>
#include <sysutil/sysutil.h>

#define GAME_MAX_PADS 1

bool running = true;

// Callback function for system utilities
extern "C" void sysutil_callback(const uint64_t status,
                                 const uint64_t param,
                                 void *userdata) {
    (void) param;
    (void) userdata;

    if (status == SYSUTIL_EXIT_GAME) {
        running = 0;
    }
}

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;

    // Register callback
    sysUtilRegisterCallback(SYSUTIL_EVENT_SLOT0, sysutil_callback, nullptr);

    // Initialize pad library
    ioPadInit(GAME_MAX_PADS);

    // [RPCS3 TTY console]
    std::printf("Hello World from PS3!\n");
    std::printf("Press START to exit.\n");

    padInfo2 padInfo;
    padData padData;

    while (running) {
        sysUtilCheckCallback();
        ioPadGetInfo2(&padInfo);

        for (unsigned int i = 0; i < padInfo.max; i++) {
            if (padInfo.port_status[i]) {
                ioPadGetData(i, &padData);

                if (padData.BTN_START) {
                    running = false;
                }
            }
        }
    }

    ioPadEnd();
    return 0;
}
