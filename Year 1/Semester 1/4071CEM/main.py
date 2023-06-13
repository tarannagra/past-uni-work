"""
4071CEM Activity Project Led 1
Chatbot name: WangBot

External modules used:
 - discord.py (https://github.com/Rapptz/discord.py)

Authors:
 - Taran Nagra
 - Nanxi Wang
 - Vince Dayrit
 - Jack Perkins

Running the bot:
python3 main.py # in terminal
"""

# Builtin modules.

import os
import json
import asyncio

# External modules.

import discord
from discord.ext import commands

# Where the bot token is stored.

with open('credentials.json', 'r') as f:
    data = json.load(f)

# Adds the intents that are required for the bot to send messages.

intents = discord.Intents.all()

# Makes the bot a bot; and... adds the intents to it.

bot = commands.Bot(
    command_prefix=data['prefix'],
    intents=intents,
    case_insensitive=True
)
bot.remove_command("help")

# Local imports.

from lib.jokes import Joker
from lib.responses import Response

# Initialising the classes for the modules I had just imported.

jokes = Joker()
response = Response()

# Clears the screen > in a small lambda function.
clear = lambda: os.system('clear' if not os.name == 'nt' else 'cls')

# Manages when the bot is online and messages in the console when it is ready for user input.

@bot.event
async def on_ready():
    clear()
    print(f"{bot.user.name} is online!")
    await bot.change_presence(activity=discord.Activity(type=discord.ActivityType.watching, name="Persuasion"))

# Manages when a message is detected in the same guild as the bot.

@bot.event
async def on_message(message):
    if message.author == bot.user: # Makes sure the message did not come from the bot.
        return

    """
    The majority of this code checks to see if a string is in the message content...
    Then I just convert the message content to lowercase.

    Joke and normal chatting interactions are from the imported local modules;
    asynchronous too as discord.py prefers it.

    """

    if "dad joke" in message.content.lower():
        joke = await jokes.dad_joke()
        await message.channel.send(joke)

    elif "pun" in message.content.lower():
        joke = await jokes.pun_joke()
        await message.channel.send(joke)

    elif "programming joke" in message.content.lower():
        joke = await jokes.programming_joke()
        await message.channel.send(joke)

    elif "misc joke" in message.content.lower():
        joke = await jokes.misc_joke()
        await message.channel.send(joke)

    elif "dark" in message.content.lower():
        joke = await jokes.dark_joke()
        await message.channel.send(joke)


    elif message.content.lower() == "wang way":
        await message.channel.send(f"{message.author.mention}, you're looking at this the **wang way**!")
    
    elif message.content.lower() == "hello" or message.content.lower() == "hey there" or message.content.lower() == "hello there":
        resp = await response.greeting()
        await message.channel.send(resp)
    elif message.content.lower() == "bye" or message.content.lower() == "cya" or message.content.lower() == "bye for now":
        resp = await response.goodbye()
        await message.channel.send(resp)
    elif message.content.lower() == "how are you?" or message.content.lower() == "how are you doing" or message.content.lower() == "hru" or message.content.lower() == "hyd":
        resp = await response.how_are_you()
        await message.channel.send(resp)
    
    # Xi's code input
    elif message.content.lower() == "tell a normal wang joke":
        await message.channel.send("My friend takes the Wang way trip twice per week")
    
    elif message.content.lower() == "tell a covuni wang joke":
        await message.channel.send("If you know how to use Python than you just have to Wang it")
    
    elif message.content.lower() == "tell a wang style insult":
        await message.channel.send("You Wanged up")
    
    elif message.content.lower() == "mathmatical wang jokes":
        await message.channel.send("Looking down on a shape from above, this is called the Wang's Eye View")
    
    elif message.content.lower() == "tell a standard chinese wang pun":
        await message.channel.send("The guy who ate an ince cream has Bing Chilling with his friends,") 
    
    elif message.content.lower() == "tell a special chinese wang pun":
        await message.channel.send("Everyone is Wanged when it comes to Phase Tests")
    
    elif message.content.lower() == "tell a vip chinese wang image.pngpun":
        await message.channel.send("The Wang Mafia is 'INF3XT' elite protection service")

    # End of Xi's input

    # Jack's code input

    # this section is a range of jokes around fitness
    elif message.content.lower() == "tell a wang fitness joke":
        await message.channel.send("My wife said i should do lunges to stay healthy. Thats a big step forward.")
    
    elif message.content.lower() == "tell a wang protein joke":
        await message.channel.send("What did the protein shake say to his crush? I'm Whey into you")
    
    elif message.content.lower() == "tell a lazy wang joke":
        await message.channel.send("Chest Day? I thought you said rest Day")
    
    elif message.content.lower() == "tell a wang gym bro joke":
        await message.channel.send("Let's go to the bar... Hopefully the weight won't be too long")	
    
    elif message.content.lower() == "tell a wang mum joke":
        await message.channel.send("Exercise? I thought you said extra fries")
    
    elif message.content.lower() == "tell a wang legday joke":
        await message.channel.send("Why was the farmer kicked out of the gym? He was destroying his calves")
    
    elif message.content.lower() == "tell a wang olympic joke":
        await message.channel.send("Why can althletes lift more than prisoners? Because the pros outweigh the cons")
    
    elif message.content.lower() == "tell a spooky wang joke":
        await message.channel.send("Why did the skeleton go to the party alone? He had no body to go with him")
    
    elif message.content.lower() == "wang tell a starwars gym joke" or message.content.lower() == "tell a wang starwars joke":
        await message.channel.send("May the fitness be with you")
    
    elif message.content.lower() == "tell a weight lifting wang joke":
        await message.channel.send("What do you get for winning a muscle loss competition? Atrophy")
    
    elif message.content.lower() == "tell a bodybuilding wang joke":
        await message.channel.send("Bodybuilders agree on most methods to build muscle... but not best the whey to do it")
    
    elif message.content.lower() == "tell a spooky fitness wang joke":
        await message.channel.send("A ghost's favorite workout is easy to guess... it's definitely dead lifts")

    # End of Jack's input

    # When having these sorts of checks above, you would need this line to make all other commands to work.
    await bot.process_commands(message)

# This event manages the command errors either informs the developer in the console;
# or mentions the user in the same channel where the command was run.

@bot.event
async def on_command_error(ctx, error):
    if isinstance(error, commands.CommandNotFound):
        pass
    elif isinstance(error, discord.ext.commands.errors.NotOwner):
        print(f"{ctx.author} just tried to access admin commands")
    elif isinstance(error, commands.CommandOnCooldown):
        await ctx.send(f"{ctx.author.mention}, that command is on cooldown for: {error.retry_after:.2f}s")

# This is a command, it can only be run by the owner of the bot token (Taran).
# This shutdowns the bot instance running on the developer's system.

@bot.command()
@commands.is_owner()
async def shutdown(ctx):
    print(f"{bot.user.name} is offline!")
    await bot.close()

# This is new and required if the discord.py library is >= 2.0.0.
# bot.start() creates a server with discord and makes it work. 
# It takes a token as a parameter.. the token is in the JSON file in the current working directory.

async def main():
    async with bot:
        #await load_extensions()
        await bot.start(data['token'])

if __name__ == '__main__':
    # This runs the bot using asyncio as discord.py requires it;
    # and all the functions are asynchronous.
    asyncio.run(main())