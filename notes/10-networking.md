# Networking

## Networking Stack Basics
- Software uses a **network stack** to organize responsibilities into layers
- The **physical layer** does the hardware control
    - In charge of physically sending and receiving data
    - Analogy: package delivery needs a car and a driver
- The **link/MAC layer** does local network addressing and routing
    - e.g. wired or wireless local network
    - MAC addresses for devices = Medium Address Control
- The **IP/network layer** does inter-network addressing and routing
    - IP = Internet Protocol
    - Uses IP address for addressing
- The **transport layer** can do packet tracking and retransmission
    - Takes care of issues like: lost packets, out of order packets, duplicate packets
    - TCP: Transmission Control Protocol - provides protection against these issues
    - UDP : User Datagram Protocol - does not provide any protection, raw datagrams/packets
    - TCP builds upon a UDP packet
    - Port numbers are used to identify where on a computer the packet should be sent to
        - Which application
