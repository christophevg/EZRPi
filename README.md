# EZRPi
Raspberry Pi HAT with a Silicon Labs EZR32 Sub-GHz MCU  
Christophe VG (<contact@christophe.vg>)

## Introduction

Using the EZRPi HAT one can give access to sub-GHz network protocols to a Raspberry Pi. An example of such protocol is Dash-7. Dash7 is a specification for an ultra low power network stack, operating within the sub-GHz spectrum. The [Dash7 Open Source Stack (OSS-7)](https://github.com/MOSAIC-LoPoW/dash7-ap-open-source-stack) can be flashed onto the EZR to turn it into a modem, accessible from the Raspberry Pi. On the Pi, one then could talk to this modem using [pyd7a](https://github.com/MOSAIC-LoPoW/pyd7a) a collection of Python modules, supporting the DASH7 Alliance Protocol in general, and OSS-7 in particular..

This repository contains all information on the design and implementation of this generic sub-GHz Raspberry Pi HAT.
