# Flight plan

<p align="center">Flight Simulator Code Interpreter</p>

![fligear Image](https://github.com/izpintel/flight_plan/blob/dev%23dudi/code_review/project_logo.jpeg)

![Static Badge](https://img.shields.io/badge/Solution-C++17-blue.svg?style=flat&logo=c%2B%2B&logoColor=b0c0c0&labelColor=363D44)  [![Static Badge](https://img.shields.io/badge/Cmake-passing-green??style=flat&logo=cmake&logoColor=0da636&labelColor=363D44)](https://github.com/aregtech/areg-sdk/actions/workflows/cmake.yml)   ![Static Badge](https://img.shields.io/badge/OS-linux-orange??style=flat&logo=Linux&logoColor=b0c0c8&labelColor=363D44)  [![Static Badge](https://img.shields.io/badge/Docker-include-0d82a6??style=flat&logo=docker&logoColor=0d82a6&labelColor=363D44)](https://www.docker.com/)

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

- git
- gcc compiler at least version 8
- Cmake
- Free ports for communication

# Description of the program flow process

1. **Tokenization**: The code is tokenized to prepare for analysis.
2. **Parsing**: An analysis is performed, and a Binary Expression Tree is generated.
3. **Environment Definition**: A definition file for simulator environment variables is created.
4. **Code Execution**: The program runs the code, performing operations on the simulator, accessing the OS, connecting to a TCP server, running the simulator in a separate process, and managing TELNET communication for data storage.
5. **Device Settings**: Adjustments for simulator plane devices are supported.
6. **Data Storage**: Data received from the simulator is stored in a database.

## Installation and Setup

1. Clone the repository.
   ```bash
    git clone git@github.com:dudi-w/flight-simulator-interpreter.git
    ```
2. Download and install [`FlightGear`](https://www.flightgear.org/) simulator.
   ```bash
   sudo apt-get update && apt-get install -y flightgear
   ```
3. Ensure the availability of the necessary ports (5400, 5402).
   ```sh
   lsof  -i :5402 -i :5400
   ```
4. setup the simulator
   ```sh
   sudo cp flight-simulator-interpreter/generic_json_format.xml /usr/share/games/flightgear/Protocol/generic_json_format.xml

   ```
5. Compile the files.
   ```sh
   cd flight-simulator-interpreter
   mkdir build
   cd build
   cmake ..
   make -j4
   ```
6. run the process
   ```sh
   # ./main <code_file> [<output_file>]
   ./main ../flight_instructions.txt /dev/null
   ```
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

- [itzchck pintel](https://github.com/izpintel)
- [nahum hilperin](https://github.com/nahumnahum)
- [ushi aerunube](https://github.com/ushi-ah)

## UML Diagram

![UML Diagram](https://github.com/izpintel/flight_plan/blob/dev%23dudi/code_review/UAV_Diagram.png)

## Downloads

To download the flight simulator [`FlightGear`](https://www.flightgear.org/) , Enter the following lines into the terminal

```sh
git clone https://github.com/izpintel/flight_plan
sudo add-apt-repository ppa:saiarcot895/flightgear
sudo apt update
sudo apt install flightgear
```

or

```sh
sudo apt-get update && apt-get install -y flightgear
```

or with doker

```sh
xhost +si:localuser:root
docker buildx build --rm --tag flightGearDocker --file ./flightGear .
docker run --rm -it --env DISPLAY=$DISPLAY --privileged --volume /tmp/.X11-unix:/tmp/.X11-unix flightGearDocker
```

run it with:

```sh
xhost +si:localuser:root
fgfs --generic=socket,out,10,127.0.0.1,5400,tcp,generic_json_format --telnet=socket,in,10,127.0.0.1,5402,tcp --httpd=8080
```
