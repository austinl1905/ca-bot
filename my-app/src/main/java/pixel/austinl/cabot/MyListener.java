package pixel.austinl.cabot;
import net.dv8tion.jda.api.hooks.ListenerAdapter;
import net.dv8tion.jda.api.events.message.MessageReceivedEvent;
import net.dv8tion.jda.api.entities.Message;
import net.dv8tion.jda.api.entities.channel.middleman.MessageChannel;

public class MyListener extends ListenerAdapter
{   @Override
    public void onMessageReceived(MessageReceivedEvent e)
    {   if(e.getAuthor().isBot())
        {   return;   }
        Message message = e.getMessage();
        String content = message.getContentRaw();
        if (content.toLowerCase().equals("prophet"))
        {   MessageChannel channel = e.getChannel();
            channel.sendMessage("60091").queue();
        }
    }
}