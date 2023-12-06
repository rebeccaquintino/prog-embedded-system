<h1 align="center">
	EEL7323 – Programação C++ para Sistemas Embarcados
	<br>
</h1>

<h4 align="center">Electronic Locks with RFID reader.</h4>

<p align="center">
  	<a href="#overview">Overview</a> •
	<a href="#embbeded-system">Embbeded System</a> •
	<a href="#computer-software">Computer Software</a> •
  	<a href="#repository-organization">Repository Organizarion</a> •
	<a href="#notes">Notes</a>
</p>

## Overview
The project aims to develop an electronic lock using a radio frequency identification (RFID) reader module of the MFRC522 model. Additionally, a Membrane Matrix Keyboard with 16 keys will be incorporated, allowing users to register new tags through a password, and a reset button has been included to unlock the lock at any time within the environment. All these sensors will be interconnected to an ESP32S ESP-WROOM-32 microcontroller, which will also be connected to signaling LEDs, our actuator. It is worth noting that the records of tag readings will be sent to the computer, which will also be connected to the microcontroller.

<p align="center">
	<img width="70%" src="https://github.com/rebeccaquintino/prog-embedded-system/projetoFinal/doc/figures/fluxograma.png">
</p>

## Embbeded System
<p align="center">
	<img width="70%" src="https://github.com/rebeccaquintino/prog-embedded-system/projetoFinal/doc/figures/diagrama_de_blocos.png">
</p>

## Computer Software
	- execute main.exe
	- choose an option: 1) Read the serial UART or 2) Display specific data via a date filter.
 
## Repository Organization
	- doc: Complete documentation about the project.
	- firmware: Firmware project (pc and embbeded system).
## Notes
More info about the project: [Documentation](https://github.com//rebeccaquintino/prog-embedded-system/projetoFinal/doc/Projeto_Final_Documentação.pdf)

