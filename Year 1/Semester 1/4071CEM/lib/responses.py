"""
/lib/responses.py

Responses file for WangBot

This has the classes and the asynchronous functions which give random responses for things.

It uses the builtin modules:
 - random

"""

import random

class Response:
    def __init__(self):
        self.greetings = ["Hey!", "Hey there!", "Hello there!", "Hello!", "Hey :wave:"]
        self.goodbyes = ["Bye!", "Cya!", "Chat later on!", "Bye :)"]
        self.how_are_yous = ["I'm good thanks!", "I'm doing okay.", "I'm a bit hot - the CPU I'm being run on is overheating, but I'm good!"]

    async def greeting(self):
        return random.choice(self.greetings)

    async def goodbye(self):
        return random.choice(self.goodbyes)

    async def how_are_you(self):
        return random.choice(self.how_are_yous)