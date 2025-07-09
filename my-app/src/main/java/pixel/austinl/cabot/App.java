package pixel.austinl.cabot;
import net.dv8tion.jda.api.JDA;
import net.dv8tion.jda.api.JDABuilder;
import net.dv8tion.jda.api.requests.GatewayIntent;
import io.github.cdimascio.dotenv.Dotenv;
/**
 * Hello world!
 */
public class App {
    public static void main(String[] args) {
        Dotenv dotenv = Dotenv.load();
        String token = dotenv.get("DISCORD_BOT_TOKEN");
        JDA api = JDABuilder.createDefault(token).addEventListeners(new MyListener()).enableIntents(GatewayIntent.MESSAGE_CONTENT).build();
    }
}
