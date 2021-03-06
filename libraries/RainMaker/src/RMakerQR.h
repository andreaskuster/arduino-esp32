#include "esp_system.h"
#if ESP_IDF_VERSION_MAJOR >= 4 && CONFIG_IDF_TARGET_ESP32

#include <qrcode.h>

#define PROV_QR_VERSION "v1"
#define QRCODE_BASE_URL     "https://rainmaker.espressif.com/qrcode.html"

static void printQR(const char *name, const char *pop, const char *transport)
{
    if (!name || !pop || !transport) {
        log_w("Cannot generate QR code payload. Data missing.");
        return;
    }
    char payload[150];
    snprintf(payload, sizeof(payload), "{\"ver\":\"%s\",\"name\":\"%s\"" \
                    ",\"pop\":\"%s\",\"transport\":\"%s\"}",
                    PROV_QR_VERSION, name, pop, transport);
    log_i("Scan this QR code from the phone app for Provisioning.");
    qrcode_display(payload);
    log_i("If QR code is not visible, copy paste the below URL in a browser.\n%s?data=%s", QRCODE_BASE_URL, payload);
}

#endif