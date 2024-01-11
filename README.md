# Flight plan
![fligear Image](https://www.techspot.com/images2/downloads/topdownload/2015/02/flightgear-p_256.webp)
Flight Simulator Code Interpreter

**Flight plan** project is to control a flight simulator using a code source file written in an custom language. The interpreter, written in C++, analyzes and executes the code, communicating with the FlightGear simulator via TCP and TELNET protocols.

The goal of this project is to control the [FlightGear](https://www.flightgear.org/) flight simulator using a custom code interpreter written in C++. The interpreter processes code written in an unfamiliar language, similar to Python, and communicates with the simulator to execute the specified operations.

## Technologies and Programming Languages

- C++.
- MultiThreads.
- TCP protocol.
- Telnet protocol.
- Design patterns: Command pattren, Singleton pattren.
- Object-Oriented Programming (OOP) principles.
- SOLID principles.

## Dependencies and Prerequisites

Ensure the following dependencies are installed:

- gtest libray
- Free ports for communication

<!-- ## Key Features -->
<!--  -->
<!-- 1. Tokenization of code -->
<!-- 2. Analysis and parser for creating a Binary Expression Tree -->
<!-- 3. Definition file generation for simulator environment variables -->
<!-- 4. Code execution, including OS access, server connection (TCP), simulator launch, data reception (Telnet), and database storage. -->
   <!--  -->
# Key Features

1. **Tokenization**: The code is tokenized to prepare for analysis.
2. **Parsing**: An analysis is performed, and a Binary Expression Tree is generated.
3. **Environment Definition**: A definition file for simulator environment variables is created.
4. **Code Execution**: The program runs the code, performing operations on the simulator, accessing the OS, connecting to a TCP server, running the simulator in a separate process, and managing TELNET communication for data storage.
5. **Device Settings**: Adjustments for simulator plane devices are supported.
6. **Data Storage**: Data received from the simulator is stored in a database.

<!-- 
## Installation and Setup

1. Clone the repository
2. Download and install third-party libraries
3. Ensure free ports for communication
4. Compile the files
5. Run GTEST unit tests -->

## Installation and Setup

1. Clone the repository.
2. Download and install required third-party libraries.
3. Ensure the availability of the necessary ports.
4. Compile the files.
   
## Contribution Guidelines

We welcome contributions! If you would like to contribute to the project, follow these steps:

1. Fork the repository
2. Create a new branch
3. Make your changes
4. Submit a pull request

## Examples and Usage

For examples and usage scenarios, refer to the [demo video](link_to_demo_video) and [screenshots](link_to_screenshots) provided in the project.

## Acknowledgments

Special thanks to:
- [Friend 1]
- [Friend 2]
- [Friend 3]

## UML Diagram

![UML Diagram](link_to_uml_diagram)

## Downloads
To download the flight simulator [`FlightGear`](https://www.flightgear.org/) , Enter the following lines into the terminal

```sh
git clone https://github.com/izpintel/flight_plan
sudo add-apt-repository ppa:saiarcot895/flightgear
sudo apt update
sudo apt install flightgear
```

run it with:
```sh
fgfs --generic=socket,out,10,127.0.0.1,5400,tcp,generic_json_format --telnet=socket,in,10,127.0.0.1,5402,tcp --httpd=8080
```
