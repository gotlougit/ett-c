# Eye Time Tracker: C version

## Overview

This is a small C program that will try to regulate your computer screen time by auto locking your computer after a certain set time. It will then auto unlock your computer after another set time (called the cooldown period).

It is actually a slightly more advanced rewrite of [the first program I ever released publicly](https://github.com/gotlougit/ett). That version was written in Python.

Notifications will be given when the computer is being locked so that you won't be blindsided by the auto lock.

Note: on some laptops, the laptop may suspend itself after being locked for some time. The program currently doesn't have a way to wake
the computer up from sleep like this, so make sure the cooldown period isn't too long.

**PLEASE NOTE: macOS and Windows are NOT SUPPORTED! This is a Linux only program due to the dependencies outlined below**

## Dependencies

In order to send notifications, ```notify-send``` has to be installed. It's available in almost all Linux distributions.

For the auto locking and unlocking, ```loginctl``` is used, which is a way to interact with systemd's login service. So, systemd is also required.

## Installation

You can simply compile the program as such (note: only gcc has been tested to work)

```gcc -lm main.c -o ett```

Then, run ```ett```

It will prompt you to set the time for the working and cooldown periods, then it will keep running and will accordingly take action.

## Roadmap

- Make a config file so that the working and cooldown periods don't need to be entered every time

- Make ett a systemd service that can be started on boot for a particular user

- Add macOS and Windows support; this one is trickier since I don't really have a Mac to test my program with

- Use C libraries for sending notifications and locking system instead of executing shell commands with system()
