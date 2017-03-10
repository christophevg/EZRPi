# EZRPi
Raspberry Pi HAT with a Silicon Labs EZR32 Sub-GHz MCU  
Christophe VG (<contact@christophe.vg>)

## Introduction

Using the EZRPi HAT one can give access to sub-GHz network protocols to a Raspberry Pi. An example of such protocol is Dash-7. Dash7 is a specification for an ultra low power network stack, operating within the sub-GHz spectrum. The [Dash7 Open Source Stack (OSS-7)](https://github.com/MOSAIC-LoPoW/dash7-ap-open-source-stack) can be flashed onto the EZR to turn it into a modem, accessible from the Raspberry Pi. On the Pi, one then could talk to this modem using [pyd7a](https://github.com/MOSAIC-LoPoW/pyd7a) a collection of Python modules, supporting the DASH7 Alliance Protocol in general, and OSS-7 in particular..

This repository contains all information on the design and implementation of this generic sub-GHz Raspberry Pi HAT.

## Version 1

The production of the first version of the board is currently ongoing. The design includes a standard 868MHz setup of the EZR32 and two LEDs for minimal debugging/feedback.

![Schematic v1](assets/schematic-v1.png)

![Board v1](assets/board-v1.png)

Within a few weeks both the components and prototype PCBs will be available and ready for (manual) soldering and testing.

![EuroCircuits Board v1](assets/ec-v1.png)
