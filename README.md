# Flight plan

## Downloads
To download the flight simulator [`FlightGear`](https://www.flightgear.org/) , Enter the following lines into the terminal

```bash
sudo add-apt-repository ppa:saiarcot895/flightgear
sudo apt update
sudo apt install flightgear
```

run it with:
```bash
fgfs --generic=socket,out,10,127.0.0.1,5400,tcp,generic_json_format --telnet=socket,in,10,1270.0.1,5402,tcp --httpd=8080
```
