#include "freertos/FreeRTOS.h"//required libs 
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "protocol_examples_common.h"

#include "discord.h"
#include "discord/session.h"

static discord_handle_t bot;

//takes event type and event data
static void bot_event_handler(void* handler_arg, esp_event_base_t base, int32_t event_id, void* event_data) {
    discord_event_data_t* data = (discord_event_data_t*) event_data;
    //event data type

    //main funcs responding to events
    switch (event_id)
    {
        case DISCORD_EVENT_CONNECTED: {
            discord_session_t* session = (discord_session_t*) data->ptr;

            ESP_LOGI("BOT", "Bot %s#%s connected",
                session->user->username,
                session->user->discriminator
            );
        }
            break;
        case DISCORD_EVENT_MESSAGE_RECEIVED: 
            break;

    }
}

void app_main(void) {
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    ESP_ERROR_CHECK(example_connect());
    
    
    discord_config_t cfg = {
        .intents = DISCORD_INTENT_GUILD_MESSAGES
    };

    bot = discord_create(&cfg);
    discord_register_events(bot, DISCORD_EVENT_ANY, bot_event_handler, NULL);
    discord_login(bot);
}