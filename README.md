# CNC Controller

CNC MACHINE (DRAWBOT)
- **ALI HAMZA MALIK**  
- **ALI ASHRAF**  

## Abstract

To create a device capable of reading g-code corresponding to various 2D shapes and recreating them on paper with a pencil, paper, marker, etc. Even in the 21st century, there are many instances where handwritten documents, letters, etc. are needed. But this requires a lot of time and labor, especially for lengthy articles. To automate this process, we have used an Arduino-based microcontroller, specifically the Arduino UNO R3, along with A4988 stepper motor drivers to drive two bipolar stepper motors. We have two separate pieces of code: one on the Arduino UNO to control the stepper motors and take commands from serial communication, and the second reads a G-code file and translates it into commands for the Arduino to run the motors in a specific manner through serial communication [1].

## Introduction

CNC is an acronym for Computer Numeric Control. CNC Machines are basically Computer Controlled Machinery. This "Machinery" is usually some kind of Motor or a whole system of Motors coupled with a Rotary Drill, Laser Engraver, Hot-End filament extruder, etc. The main aim of CNC Machines is to reduce human error involved in machinery control by handing over control to a computer that has been programmed to carry out specific repeated movements with the help of a motor along with feedback control, which makes certain tasks easier, automated, and more precise and accurate. CNC machines are widely used in the industry because they reduce human labor and increase production and efficiency [2]. But due to their functionality, they are also used in other fields such as workshops, wood engraving, 3D printing for hobbyists, etc.

Our project is a simple 2D CNC Machine capable of reading a G-code file and sending commands over serial communication to an Arduino, which converts transmitted signals to electrical signals suitable for driving two stepper motors that trace out the shape encoded in the G-code file. Basically, we are converting digital models into signals for a 2-axis arrangement of motors that can trace out lines or dots on a piece of paper.

The goal of the project is to create a cheap and functional CNC machine along with operating code capable of sketching out 2D images and texts on paper with basic writing tools such as a pen.

## Existing Similar Work

Such a simple 2D plotter is a common project for hobbyists, students, engineers, etc. There are many different implementations of this idea that can be found on the internet. Some examples are:

1. Plotter machines in educational institutions for blind students, handicapped, and temporarily fractured people that convert voice to text [3].
2. Small 3D printers made with a 3-axis CNC machine attached with a 3D printer pen or Hot-End Filament Extruder [1].

## Features

Our CNC machine will have the following features:

1. Standard CNC machines made by hobbyists and students use already available CNC and G-Code Controller software. Our aim is to create a custom program to run our CNC machine.
2. Two modes of operation: one for converting G-code into an image on paper and another for controlling motor movements with arrow keys to use the CNC machine like a mechanical pen.

## File Structure

<pre>
code/
│├── Arduino code.ino
│└── CNCCONTROLINTERFACE.c
├── CNC Machine (Drawbot).pptx
└── Project_Proposal.docx
</pre>



## References

1. Patil, Sheetal N., and Prashant G. Patil. "Implementation of Arduino UNO based Two Directional [2D] Plotter."
2. Shivakumar, M., et al. "Robotic 2D plotter." International Journal of Engineering and Innovative Technology (IJEIT) 3.10 (2014): 300-303.
3. Pandey, Udit, and Swapnil Raj Sharma. "Model and Fabrication of CNC Plotter Machine." International Journal of Advanced Research in Computer and Communication Engineering ISO 3297: 2007 Certified 6.6 (2017): 336-337.
