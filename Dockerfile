FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive
ENV PATH="/usr/games:${PATH}"

RUN apt update -y
RUN apt upgrade -y
RUN apt install git -y
RUN apt install cmake -y
RUN apt install gcc -y
RUN apt install build-essential -y

RUN apt-get update
RUN apt-get install -y flightgear
RUN apt-get clean
RUN apt-get install -y x11-apps
RUN apt-get install -y dbus-x11

RUN git clone https://github.com/dudi-w/flight-simulator-interpreter.git /app

RUN cp /app/generic_json_format.xml /usr/share/games/flightgear/Protocol/generic_json_format.xml

WORKDIR /app

RUN mkdir build
RUN cd build
RUN cmake -DCMAKE_CXX_FLAGS="-pthread"
RUN make -j4

EXPOSE 5400 5402 8080

CMD ["./main", "flight_instructions.txt"]