idf_component_register(SRCS "cabot_host.c"
                       INCLUDE_DIRS "."
                       PRIV_REQUIRES protocol_examples_common nvs_flash esp_netif)