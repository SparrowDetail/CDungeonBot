#include <dpp/dpp.h>

// Insert you Discord bot token, I used environmental variables for access
const char* TOKEN = std::getenv("DungeonBotToken");

int main() {
    dpp::cluster bot(TOKEN);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "roll") {
            event.reply("ROLL");
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("roll", "Roll Dice", bot.me.id));
        }
    });

    bot.start(dpp::st_wait);

    return 0;
}