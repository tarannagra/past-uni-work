"""
/lib/jokes.py

Jokes file for WangBot

This has the classes and the asynchronous functions which connect to the two joke APIs.

It uses the builtin modules:
 - aiohttp
 - asyncio

"""

import aiohttp
import asyncio

class Joker:
    def __init__(self):
        # Global variables in the class.. I guess.
        self.headers = {
            "User-Agent": "Mozilla/5.0 (X11; CrOS x86_64 15117.111.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36",
            "Accept": "application/json"
        }
        self.dad_joke_url = "https://icanhazdadjoke.com"
    
    """
    Every function does the same thing:
     - Makes a request;
     - Get's the JSON data;
     - Returns the key 'joke'
    """

    async def dad_joke(self):
        async with aiohttp.ClientSession(headers=self.headers) as session:
            async with session.get(self.dad_joke_url) as r:
                data = await r.json()

        return data['joke']

    async def programming_joke(self):
        async with aiohttp.ClientSession() as session:
            async with session.get("https://v2.jokeapi.dev/joke/Programming?type=single") as r:
                data = await r.json()

        return data['joke']

    async def misc_joke(self):
        async with aiohttp.ClientSession() as session:
            async with session.get("https://v2.jokeapi.dev/joke/Miscellaneous?type=single") as r:
                data = await r.json()

        return data['joke']

    async def dark_joke(self):
        async with aiohttp.ClientSession() as session:
            async with session.get("https://v2.jokeapi.dev/joke/Dark?type=single") as r:
                data = await r.json()

        return data['joke']

    async def pun_joke(self):
        async with aiohttp.ClientSession() as session:
            async with session.get("https://v2.jokeapi.dev/joke/Pun?type=single") as r:
                data = await r.json()

        return data['joke']